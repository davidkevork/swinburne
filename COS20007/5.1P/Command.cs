using System;
namespace SwinAdventure.src
{
    public abstract class Command : Identify
    {
        public Command (string [] ids) : base (ids) { }

        public abstract string Execute (Player p, string [] text);
    }
}
