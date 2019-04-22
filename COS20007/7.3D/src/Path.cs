using System;

namespace SwinAdventure.src
{
    public class Path : Identify
    {
        private Location _north = null;
        private Location _south = null;
        private Location _east = null;
        private Location _west = null;
        private Location _north_east = null;
        private Location _north_west = null;
        private Location _south_east = null;
        private Location _south_west = null;

        public Path() : base(new string[] { "move", "go", "head", "leave" }) { }

        public void SetLocation(string direction, Location location)
        {
            if (location == null)
            {
                return;
            }
            switch (direction)
            {
                case "n":
                    _north = location;
                    break;
                case "s":
                    _south = location;
                    break;
                case "e":
                    _east = location;
                    break;
                case "w":
                    _west = location;
                    break;
                case "ne":
                    _north_east = location;
                    break;
                case "nw":
                    _north_west = location;
                    break;
                case "se":
                    _south_east = location;
                    break;
                case "sw":
                    _south_west = location;
                    break;
            }
        }

        public Location GetLocation(string direction)
        {
            if (direction == "n" || direction == "up" || direction == "north")
            {
                return _north;
            }
            else if (direction == "s" || direction == "down" || direction == "south")
            {
                return _south;
            }
            else if (direction == "e" || direction == "east")
            {
                return _east;
            }
            else if (direction == "w" || direction == "west")
            {
                return _west;
            }
            else if (direction == "ne" || direction == "north_east")
            {
                return _north_east;
            }
            else if (direction == "nw" || direction == "north_west")
            {
                return _north_west;
            }
            else if (direction == "se" || direction == "south_east")
            {
                return _south_east;
            }
            else if (direction == "sw" || direction == "south_west")
            {
                return _south_west;
            }
            else
            {
                if (_north != null)
                {
                    if (_north.AreYou(direction))
                    {
                        return _north;
                    }
                }
                if (_south != null)
                {
                    if (_south.AreYou(direction))
                    {
                        return _south;
                    }
                }
                if (_east != null)
                {
                    if (_east.AreYou(direction))
                    {
                        return _east;
                    }
                }
                if (_west != null)
                {
                    if (_west.AreYou(direction))
                    {
                        return _west;
                    }
                }
                if (_north_east != null)
                {
                    if (_north_east.AreYou(direction))
                    {
                        return _north_east;
                    }
                }
                if (_north_west != null)
                {
                    if (_north_west.AreYou(direction))
                    {
                        return _north_west;
                    }
                }
                if (_south_east != null)
                {
                    if (_south_east.AreYou(direction))
                    {
                        return _south_east;
                    }
                }
                if (_south_west != null)
                {
                    if (_south_west.AreYou(direction))
                    {
                        return _south_west;
                    }
                }
                return null;
            }
        }
    }
}
