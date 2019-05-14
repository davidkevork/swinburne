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
                case "north":
                case "up":
                    _north = location;
                    break;
                case "south":
                case "down":
                    _south = location;
                    break;
                case "east":
                case "right":
                    _east = location;
                    break;
                case "west":
                case "left":
                    _west = location;
                    break;
                case "northeast":
                    _north_east = location;
                    break;
                case "northwest":
                    _north_west = location;
                    break;
                case "southeast":
                    _south_east = location;
                    break;
                case "southweast":
                    _south_west = location;
                    break;
            }
        }

        public Location GetLocation(string direction)
        {
            if (direction == "up" || direction == "north")
            {
                return _north;
            }
            else if (direction == "down" || direction == "south")
            {
                return _south;
            }
            else if (direction == "right" || direction == "east")
            {
                return _east;
            }
            else if (direction == "left" || direction == "west")
            {
                return _west;
            }
            else if (direction == "northeast")
            {
                return _north_east;
            }
            else if (direction == "northwest")
            {
                return _north_west;
            }
            else if (direction == "southeast")
            {
                return _south_east;
            }
            else if (direction == "southwest")
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
