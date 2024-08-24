load('scripts/npc/lib/Crafting.js');
load('scripts/npc/interactions/shared/MakerCrafting.js');

class CraftingEquipmentInteraction {
    constructor(cm) {
        this.cm = cm;
        this.handlerRegistry = new InteractionHandlerRegistry();

        this.craftingMenuInteraction = new MakerCraftingMenuSubInteraction(cm);

        this.setGearData = getJson("gearSets.json");
        this.otherAccessoryData = getJson("otherAccessories.json");

        // level 1 options
        this.craftingMenuOptions = [ CraftingMenuOption.SetGear, CraftingMenuOption.OtherAccessories ];

        // Level 2a options
        this.classOptions = [ ClassOption.Common, ClassOption.Warrior, ClassOption.Magician, ClassOption.Bowman,
            ClassOption.Thief, ClassOption.Pirate ];

        // Level 2b options
        this.accessoryOptions = [ AccessoryOption.EarAccessories, AccessoryOption.EyeAccessories,
            AccessoryOption.FaceAccessories, AccessoryOption.Pendants, AccessoryOption.Rings ];

        this.startingStatusMap = {
            1: 6, // CraftingMenuOption.SetGear
            2: 5  // CraftingMenuOption.OtherAccessories
        }

        // Shared selection memory
        this.selectedCraftingMenuOption = null;

        // SetGear Selection Memory :3
        this.selectedClassOption = null;
        this.selectedSetGearOption = null;
        this.selectedSetGearItemOption = null;
        this.selectedGearSetItemAmount = null;
        this.activeSetGearList = null;
        this.activeSetGearItemList = null;
        this.activeSetGearRecipe = null;

        // Other Accessories Selection Memory
        this.selectedAccessoryOption = null;
        this.selectedAccessoryItemOption = null;
        this.selectedAccessoryItemAmount = null;
        this.activeAccessoryItemList = null;
        this.activeAccessoryRecipe = null;

        this.initializeHandlers();
    }

    initializeHandlers() {
        // Entrypoint
        this.handlerRegistry.register(1, null, this.showCraftingMenu.bind(this));

        // SetGear handlers
        this.handlerRegistry.register(2, CraftingMenuOption.SetGear, this.showClassSelectionMenu.bind(this));
        this.handlerRegistry.register(3, CraftingMenuOption.SetGear, this.showSetGearSelectionMenu.bind(this));
        this.handlerRegistry.register(4, CraftingMenuOption.SetGear, this.showSetGearItemSelectionMenu.bind(this));
        this.handlerRegistry.register(5, CraftingMenuOption.SetGear, this.getSetGearCraftingAmount.bind(this));
        this.handlerRegistry.register(6, CraftingMenuOption.SetGear, this.confirmSetGearItemSelection.bind(this));

        // OtherAccessories handlers
        this.handlerRegistry.register(2, CraftingMenuOption.OtherAccessories, this.showOtherAccessoriesSelectionMenu.bind(this));
        this.handlerRegistry.register(3, CraftingMenuOption.OtherAccessories, this.showOtherAccessoriesItemSelectionMenu.bind(this));
        this.handlerRegistry.register(4, CraftingMenuOption.OtherAccessories, this.getOtherAccessoryCraftingAmount.bind(this));
        this.handlerRegistry.register(5, CraftingMenuOption.OtherAccessories, this.confirmOtherAccessoryItemSelection.bind(this));
    }

    action(mode, type, selection, status) {
        try {
            if (status === 2) {
                this.selectedCraftingMenuOption = this.selectedCraftingMenuOption || selection;
            }

            if (status > 2 && status > this.startingStatusMap[this.selectedCraftingMenuOption])
            {
                return this.craftingMenuInteraction.action(mode, type, selection, status);
            }

            const handler = this.handlerRegistry.getHandler(status, this.selectedCraftingMenuOption);
            return handler.call(this, mode, type, selection, status);
        } catch (error) {
            this.cm.logToConsole(`[CraftingEquipmentInteraction] HandlerError: ${error}`);
            return ScriptInteractionResult.HandlerError;
        }
    }

    // ======================= The Beginning ===========================
    showCraftingMenu(mode, type, selection, status) {
        let selStr = "My selection of armour, weaponry and other accessories are fit for all types of combat!#b#e";

        for (let option of this.craftingMenuOptions) {
            selStr += `\r\n#L${option}# ${CraftingMenuOption.StringMap[option]}#l`;
        }

        this.cm.sendSimple(selStr);
        return status;
    }

    // ===================== SetGear Handlers =========================
    showClassSelectionMenu(mode, type, selection, status) {
        let selStr = "I have unique equipment per class!#b#e";

        for (let option of this.classOptions) {
            selStr += `\r\n#L${option}# ${ClassOption.StringMap[option]}#l`;
        }

        this.cm.sendSimple(selStr);
        return status;
    }

    showSetGearSelectionMenu(mode, type, selection, status) {
        this.selectedClassOption = this.selectedClassOption || selection;

        this.activeSetGearList = this.activeSetGearList
            || this.setGearData[ClassOption.StringMap[this.selectedClassOption]].map(SetGear.fromJson);

        let selStr = "I have unique set gear available!#b#e";
        let index = 1;
        for (let setGear of this.activeSetGearList) {
            selStr += `\r\n#L${index}##i${setGear.recipes[0].itemId}# ${setGear.name}#l`;
            index++;
        }

        this.cm.sendSimple(selStr);
        return status;
    }

    showSetGearItemSelectionMenu(mode, type, selection, status) {
        this.selectedSetGearOption = this.selectedSetGearOption || selection;

        this.activeSetGearItemList = this.activeSetGearItemList || this.activeSetGearList[selection - 1].recipes;

        let selStr = "I have unique items available!#b#e";
        for (let index = 0; index < this.activeSetGearItemList.length; index++) {
            let setGearItem = this.activeSetGearItemList[index];

            selStr += `\r\n#L${index + 1}##i${setGearItem.itemId}# ${setGearItem.name}#l`;
        }

        this.cm.sendSimple(selStr);
        return status;
    }

    // TODO: Show item and quantity
    getSetGearCraftingAmount(mode, type, selection, status) {
        this.selectedSetGearItemOption = this.selectedSetGearItemOption || selection;

        this.activeSetGearRecipe = this.activeSetGearItemList[this.selectedSetGearItemOption - 1];

        // if any material in the recipe will process StarForce, max is 1.
        const maxQuantity = this.activeSetGearRecipe.materials.some((material) => material.processStarforce)
            ? 1
            : 1000;

        this.cm.sendGetNumber("How many would you like to make?", 1, 1, maxQuantity);
        return status;
    }

    confirmSetGearItemSelection(mode, type, selection, status) {
        this.selectedGearSetItemAmount = selection;

        this.craftingMenuInteraction.setupInteraction(status);
        this.craftingMenuInteraction.setSelectedRecipe(this.activeSetGearRecipe, this.selectedGearSetItemAmount);

        return this.craftingMenuInteraction.action(mode, type, selection, status);
    }

    // ================= OtherAccessory Handlers =========================
    showOtherAccessoriesSelectionMenu(mode, type, selection, status) {
        let selStr = "Browse through my fine collection of accessories!#b#e";

        for (let option of this.accessoryOptions) {
            selStr += `\r\n#L${option}# ${AccessoryOption.StringMap[option]}#l`;
        }

        this.cm.sendSimple(selStr);
        return status;
    }

    showOtherAccessoriesItemSelectionMenu(mode, type, selection, status) {
        this.selectedAccessoryOption = this.selectedAccessoryOption || selection;

        this.activeAccessoryItemList = this.activeAccessoryItemList
            || this.otherAccessoryData[AccessoryOption.StringMap[this.selectedAccessoryOption]]
                .map(CraftingRecipe.fromJson);

        let selStr = "Select the item you would like to craft.\r\n\r\n"
        for (let index = 0; index < this.activeAccessoryItemList.length; index++) {
            let recipe = this.activeAccessoryItemList[index];

            selStr += `\r\n#L${index + 1}##i${recipe.itemId}# ${recipe.name} #ex${recipe.quantity}#n#l`;
        }

        this.cm.sendSimple(selStr);
        return status;
    }

    getOtherAccessoryCraftingAmount(mode, type, selection, status) {
        this.selectedAccessoryItemOption = this.selectedAccessoryItemOption || selection;

        this.activeAccessoryRecipe = this.activeAccessoryItemList[this.selectedAccessoryItemOption - 1];

        this.cm.sendGetNumber("How many would you like to make?", 1, 1, 1000);
        return status;
    }

    confirmOtherAccessoryItemSelection(mode, type, selection, status) {
        this.selectedAccessoryItemAmount = selection;

        this.craftingMenuInteraction.setupInteraction(status);
        this.craftingMenuInteraction.setSelectedRecipe(this.activeAccessoryRecipe, this.selectedAccessoryItemAmount);

        return this.craftingMenuInteraction.action(mode, type, selection, status);
    }
}

class SetGear {
    constructor(name, recipes) {
        this.name = name;
        this.recipes = recipes.map(CraftingRecipe.fromJson);
    }

    static fromJson(json) {
        return new SetGear(json.name, json.recipes);
    }
}

const CraftingMenuOption = {
    StringMap: {
        1 : "Set Gear",
        2 : "Other Accessories",
    },
    SetGear: 1,
    OtherAccessories: 2
}

const ClassOption = {
    StringMap: {
        1 : "Common",
        2 : "Warrior",
        3 : "Magician",
        4 : "Bowman",
        5 : "Thief",
        6 : "Pirate"
    },
    Common: 1,
    Warrior: 2,
    Magician: 3,
    Bowman: 4,
    Thief: 5,
    Pirate: 6
}

const AccessoryOption = {
    StringMap: {
        1 : "Pendants",
        2 : "Medals",
        3 : "Face Accessories",
        4 : "Eye Accessories",
        5 : "Ear Accessories",
        6 : "Rings"
    },
    Pendants: 1,
    Medals: 2,
    FaceAccessories: 3,
    EyeAccessories: 4,
    EarAccessories: 5,
    Rings: 6
}