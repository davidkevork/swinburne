using System;
namespace SwinAdventure.src
{
    public class Location : GameObject, IHaveInventory
    {
        private Inventory _inventory = new Inventory();
        private Path _path = null;

        public Location(string name, string desc) : base (new String[] { "room", "here" }, name, desc) { }

        public GameObject Locate (string id)
        {
            if (AreYou (id))
            {
                return this;
            }
            else if (_inventory.HasItem (id))
            {
                return _inventory.Fetch (id);
            }
            else
            {
                return null;
            }
        }

        public override string FullDescription
        {
            get
            {
                string FullDesc = "You are in " + Name + "\r\n";
                FullDesc += base.FullDescription + "\r\n";
                FullDesc += _inventory.ItemList;
                return FullDesc;
            }
        }

        public Inventory Inventory
        {
            get
            {
                return _inventory;
            }
        }

        public Path Path
        {
            get
            {
                return _path;
            }
            set
            {
                _path = value;
            }
        }
    }
}
