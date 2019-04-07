using NUnit.Framework;
using System;

namespace SwinAdventure.src.test
{
    [TestFixture ()]
    public class NUnitTestInventory
    {
        [Test ()]
        public void TestFindItem ()
        {
            Item shovel = new Item (new String [] { "shovel", "spade" }, "a shovel", "This is a might fine ...");
            Inventory inv = new Inventory ();
            inv.Put (shovel);
            Assert.AreEqual (true, inv.HasItem ("shovel"), "Test find item");
        }

        [Test ()]
        public void TestNoFindItem ()
        {
            Item shovel = new Item (new String [] { "shovel", "spade" }, "a shovel", "This is a might fine ...");
            Inventory inv = new Inventory ();
            inv.Put (shovel);
            Assert.AreEqual (false, inv.HasItem ("hammer"), "Test no find item");
        }

        [Test ()]
        public void TestFetchItem ()
        {
            Item shovel = new Item (new String [] { "shovel", "spade" }, "a shovel", "This is a might fine ...");
            Inventory inv = new Inventory ();
            inv.Put (shovel);
            Assert.AreEqual (shovel, inv.Fetch ("shovel"), "Test fetch item");
        }

        [Test ()]
        public void TestTakeItem ()
        {
            Item shovel = new Item (new String [] { "shovel", "spade" }, "a shovel", "This is a might fine ...");
            Inventory inv = new Inventory ();
            inv.Put (shovel);
            Assert.AreEqual (shovel, inv.Take ("shovel"), "Test Take item");
            Assert.AreEqual (null, inv.Take ("shovel"), "Test Take item");
        }

        [Test ()]
        public void TestItemList ()
        {
            Item shovel = new Item (new String [] { "shovel", "spade" }, "a shovel", "This is a might fine ...");
            Inventory inv = new Inventory ();
            inv.Put (shovel);
            Assert.AreEqual (shovel, inv.Fetch ("shovel"), "Test Item List");
        }
    }
}
