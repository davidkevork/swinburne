using System;
using System.Collections.Generic;

namespace SwinAdventure.src
{
    public class CommandProcessor : Command
    {
        private List<Command> _commands = new List<Command>();

        public CommandProcessor() : base(new String[] { }) { }

        public override string Execute(Player p, string[] text)
        {
            foreach (Command command in _commands)
            {
                if (command.AreYou(text[0]))
                {
                    return command.Execute(p, text);
                }
            }

            return "Invalid command";
        }

        public void AddCommand(Command newCommand)
        {
            _commands.Add (newCommand);
        }
    }
}
