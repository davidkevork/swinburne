using System;
using System.Collections.Generic;
using NUnit.Framework;

namespace MyGame
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

    [TestFixture]
    public class TestIdentify
    {

        [Test]
        public void TestIdentifyConstructor ()
        {
            Identify ident = new Identify (new string [] { "id1", "id2" });

            Assert.AreEqual ("id1", ident.FirstId, "Identify constructor should add idents");
            Assert.AreEqual (2, ident.Count (), "Should have 2 ids inserted");
        }

        [Test]
        public void TestFirstId ()
        {
            Identify ident = new Identify (new string [] {});

            Assert.AreEqual ("", ident.FirstId, "Should have empty list");
        }

        [Test]
        public void TestAreYou ()
        {
            Identify ident = new Identify (new string [] { "id1", "id2" });

            Assert.AreEqual (true, ident.AreYou("id1"), "Should find id is in list");
        }

        [Test]
        public void TestNotAreYou ()
        {
            Identify ident = new Identify (new string [] { "id1", "id2" });

            Assert.AreEqual (false, ident.AreYou ("id5"), "Should find id is not in list");
        }

        [Test]
        public void TestCaseSensitive ()
        {
            Identify ident = new Identify (new string [] { "id1", "id2" });

            Assert.AreEqual (true, ident.AreYou ("ID1"), "Should find id is in list");
        }

        [Test]
        public void TestCount ()
        {
            Identify ident = new Identify (new string [] { "id1", "id2" });

            Assert.AreEqual (2, ident.Count (), "Should have 2 ids inserted");
        }

        [Test]
        public void TestAddIdentifier ()
        {
            Identify ident = new Identify (new string [] {});
            ident.AddIdentifier ("ID1");

            Assert.AreEqual ("id1", ident.FirstId, "Should turn id to LowerCase before inserting");
        }
    }
}
