using System;
namespace SwinAdventure.src
{
    public class Bag : Item, IHaveInventory
    {
        private Inventory _inventory = new Inventory ();

        public Bag (string [] ids, string name, string desc) : base (ids, name, desc)
        {
            _inventory.Put (new Item (ids, name, desc));
        }

        public GameObject Locate (string id)
        {
            if (AreYou (id))
            {
                return this;
            }
            else
            {
                return _inventory.Fetch(id);
            }
        }

        public bool Drop (string id)
        {
            if (AreYou (id))
            {
                return false;
            }
            else if (_inventory.HasItem (id))
            {
                _inventory.Take (id);
                return true;
            }
            else
            {
                return false;
            }
        }

        public override string FullDescription
        {
            get
            {
                string FullDesc = "In the " + Name + " you can see:\r\n";
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
    }
}
