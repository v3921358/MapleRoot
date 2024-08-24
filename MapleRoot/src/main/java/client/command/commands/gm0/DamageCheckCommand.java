package client.command.commands.gm0;

import client.Character;
import client.Client;
import client.command.Command;


public class DamageCheckCommand extends Command {
    {
        setDescription("Begin a damage check over X amount of seconds time eg @damage 15 sets damage check for 15 seconds.");
    }

    @Override
    public void execute(Client c, String[] params) {
        Character player = c.getPlayer();
        int duration = Integer.parseInt(params[0]);
        if (params.length < 1) {
            player.dropMessage(5, "Please include the duration in seconds of the Damage Check.");
            return;
        }
        player.damageChecks = true;
        player.damageTestLength = duration;
        player.dropMessage(6, "Damage check will last for " + duration + " seconds on next attack.");
    }
}

