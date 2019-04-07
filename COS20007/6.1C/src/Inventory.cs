using System;
using System.Collections.Generic;

namespace SwinAdventure.src
{
    public class Inventory
    {
        private List<Item> _items = new List<Item> ();

        public Inventory ()
        {
        }

        public Boolean HasItem (string id)
        {
            foreach (Item item in _items) {
                if (item.AreYou (id)) {
                    return true;
                }
            }
            return false;
        }

        public void Put (Item item)
        {
            _items.Add (item);
        }

        public Item Take (string id) {
            foreach (Item item in _items) {
                if (item.AreYou (id)) {
                    _items.Remove (item);
                    return item;
                }
            }
            return null;
        }

        public Item Fetch (string id) {
            foreach (Item item in _items) {
                if (item.AreYou (id)) {
                    return item;
                }
            }
            return null;
        }

        public string ItemList
        {
            get
            {
                if (_items.Count == 0)
                {
                    return null;
                }

                string list = "";
                foreach (Item item in _items)
                {
                    list += "\t" + item.ShortDescription + "\r\n";
                }
                return list;
            }
        }
    }
}
