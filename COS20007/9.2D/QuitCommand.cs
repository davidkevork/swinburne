using System;
namespace SwinAdventure.src
{
    public class QuitCommand : Command
    {
        public QuitCommand() : base(new String[] { "quit", "exit" }) { }

        public override string Execute(Player p, string[] text)
        {
            if (this.AreYou(text[0]))
            {
                return "Quitting";
            }
            else
            {
                return "I don't understand that";
            }
        }

        public string Description()
        {
            return "[quit][exit] Usage: quits the program\n";
        }
    }
}
