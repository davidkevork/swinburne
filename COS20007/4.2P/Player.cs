using System;
namespace MyGame
{
    public class Player : GameObject
    {
        private Inventory _inventory = new Inventory();

        public Player (string name, string desc) : base (new string [] { "me", "inventory" }, name, desc)
        {
        }

        public GameObject Locate (string id)
        {
            if (AreYou (id))
            {
                return this;
            } else {
                return _inventory.Fetch (id);
            }
        }

        public override string FullDescription
        {
            get
            {
                return "You are carrying:\r\n" + _inventory.ItemList;
            }
        }

        public Inventory Inventory
        {
            get
            {
                return _inventory;
            }
        }
    }
}
