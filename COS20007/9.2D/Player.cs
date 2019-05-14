﻿using System;

namespace SwinAdventure.src
{
    public class Player : GameObject, IHaveInventory
    {
        private Inventory _inventory = new Inventory();
        private Location _location;
        private Location _lastLocation;

        public Player (string name, string desc) : base (new string [] { "me", "inventory" }, name, desc)
        {
            _location = null;
        }

        public GameObject Locate (string id)
        {
            if (AreYou(id))
            {
                return this;
            }
            else if (_inventory.HasItem (id))
            {
                return _inventory.Fetch (id);
            }
            else if (_location != null && _location.Locate(id) != null)
            {
                return _location.Locate(id);
            }
            else
            {
                return null;
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
            else if (_location != null && _location.Locate(id) != null)
            {
                return _location.Drop(id);
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
                if (_inventory.ItemList == null)
                {
                    return "You are not carrying anything";
                }
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

        public Location Location
        {
            get
            {
                return _location;
            }
            set
            {
                _lastLocation = _location == null ? value : _location;
                _location = value;
            }
        }

        public void LeaveLocation()
        {
            _location = _lastLocation;
        }
    }
}