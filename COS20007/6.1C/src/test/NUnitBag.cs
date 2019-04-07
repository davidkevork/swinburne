using NUnit.Framework;
using System;

namespace SwinAdventure.src.test
{
    [TestFixture ()]
    public class NUnitBag
    {
        [Test ()]
        public void TestBagLocatesItems ()
        {
            Bag bag = new Bag (new String [] { "shovel", "spade" }, "a shovel", "This is a might fine ...");
            Item gunItem = new Item(new String[] { "gun", "rifle" }, "a gun", "This is a killing tool ...");
            bag.Inventory.Put(gunItem);
            Assert.AreEqual (gunItem, bag.Locate ("gun"), "Test bag locates items");
        }

        [Test ()]
        public void TestBagLocatesItslef ()
        {
            Bag bag = new Bag (new String [] { "shovel", "spade" }, "a shovel", "This is a might fine ...");
            Assert.AreEqual (bag, bag.Locate ("shovel"), "Test bag locates itself");
        }

        [Test ()]
        public void TestBagLocatesNothing ()
        {
            Bag bag = new Bag (new String [] { "shovel", "spade" }, "a shovel", "This is a might fine ...");
            Assert.AreEqual (null, bag.Locate ("sword"), "Test bag locates nothing");
        }

        [Test ()]
        public void TestBagFullDescription ()
        {
            Bag bag = new Bag (new String [] { "shovel", "spade" }, "a shovel", "This is a might fine ...");
            string bagDesc = "In the a shovel you can see:\r\n\ta shovel (shovel)\r\n";
            Assert.AreEqual (bagDesc, bag.FullDescription, "Test bag full description");
        }

        [Test ()]
        public void TestBagInBag ()
        {
            Bag b1 = new Bag (new String [] { "shovel", "spade" }, "a shovel", "This is a might fine ...");
            Bag b2 = new Bag (new String [] { "sword" }, "a sword", "This can kill anything ...");
            b1.Inventory.Put (b2);
            Assert.AreEqual (b2, b1.Locate("sword"), "Test bag in bag");
        }
    }
}