using System;
using System.Collections.Generic;

namespace SwinAdventure.src
{
    public class Identify
    {
        private List<string> _identifiers = new List<string> ();

        public Identify (string [] idents)
        {
            foreach (string ident in idents)
            {
                _identifiers.Add (ident.ToLower ());
            }
        }

        public Boolean AreYou (string id)
        {
            foreach (string ident in _identifiers) {
                if (ident.Equals(id.ToLower ())) {
                    return true;
                }
            }
            return false;
        }

        public string FirstId
        {
            get
            {
                return _identifiers.Count >= 1 ? _identifiers [0] : "";
            }
        }

        public int Count()
        {
            return _identifiers.Count;
        }

        public void AddIdentifier (string id)
        {
            _identifiers.Add (id.ToLower());
        }
    }
}
