using System;
namespace SwinAdventure.src
{
    public class MoveCommand : Command
    {
        public MoveCommand() : base(new String[] { "move", "go", "head", "leave" }) { }

        public override string Execute(Player p, string [] text)
        {
            int textLength = text.Length;
            if ((textLength == 1 && text[0] != "leave") || textLength > 2)
            {
                return "I don't know how to move like that";
            }
            if (text[0] != "move" && text[0] != "go" && text[0] != "head" && text[0] != "leave")
            {
                return "Error in move input";
            }
            if (text[0] == "leave")
            {
                return MoveTo(p, "leave");
            }
            if (textLength == 1)
            {
                return "Where do you want to go?";
            }
            else
            {
                return MoveTo(p, text[1]);
            }
        }

        public string MoveTo(Player p, string pahtId)
        {
            Location _location;
            if (pahtId == "leave")
            {
                p.LeaveLocation();
                return p.Location.FullDescription;
            }
            _location = p.Location;
            Path _path = _location.Path;
            if (_path == null)
            {
                return "Location has no path";
            }
            _location = _path.GetLocation(pahtId);
            if (_location == null)
            {
                return "Path not found";
            }
            p.Location = _location;
            return p.Location.FullDescription;
        }
    }
}
