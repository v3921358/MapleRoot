package client.command.commands.gm0;

import client.Character;
import client.Client;
import client.command.Command;
import java.text.NumberFormat;

public class BankCommand extends Command {
    {
        setDescription("Retrieve or store Mesos");
    }

    @Override
    public void execute(Client c, String[] params) {
        Character player = c.getPlayer();
        long bank = player.getBankMesos();
        NumberFormat numberFormat = NumberFormat.getInstance();

        if (params.length == 0) {
            String formattedBank = numberFormat.format(bank);
            player.dropMessage("You currently have " + formattedBank + " mesos stored.");
            player.dropMessage("To retrieve or store mesos use the command @bank take/store <amount>");
        } else if (params.length == 1) {
            player.dropMessage("Please specify an amount after 'take' or 'store'");
        } else if (params.length == 2) {
            try {
                int amount = Integer.parseInt(params[1]);
                if (amount <= 0) {
                    player.dropMessage("Please specify a valid amount of mesos.");
                    return;
                }

                switch (params[0].toLowerCase()) {
                    case "store":
                        handleStore(player, amount);
                        break;
                    case "take":
                        handleTake(player, amount);
                        break;
                    default:
                        player.dropMessage("Invalid command. Use '@bank take <amount>' or '@bank store <amount>'");
                        break;
                }
            } catch (NumberFormatException e) {
                player.dropMessage("Please specify a valid numeric amount.");
            }
        }
    }

    private void handleStore(Character player, int amount) {
        if (amount > player.getMeso()) {
            player.dropMessage("You don't have enough mesos to deposit.");
        } else {
            player.dropMessage("Deposited " + NumberFormat.getInstance().format(amount) + " mesos to your bank.");
            player.gainMeso(-amount);
            player.setBankMesos(player.getBankMesos() + amount);
        }
    }

    private void handleTake(Character player, int amount) {
        long bank = player.getBankMesos();
        int meso = player.getMeso();
        long maxAmount = (long) meso + amount;

        if (maxAmount > Integer.MAX_VALUE) {
            String formattedMax = NumberFormat.getInstance().format(Integer.MAX_VALUE - meso);
            player.dropMessage("Your meso amount must not exceed " + formattedMax + ".");
        } else if (bank < amount) {
            player.dropMessage("You don't have enough mesos to withdraw.");
        } else {
            player.dropMessage("Withdrew " + NumberFormat.getInstance().format(amount) + " mesos from your bank.");
            player.setBankMesos(bank - amount);
            player.gainMeso(amount);
        }
    }
}