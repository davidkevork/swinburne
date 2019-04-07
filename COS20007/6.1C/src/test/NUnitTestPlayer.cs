using NUnit.Framework;
using System;

namespace SwinAdventure.src.test
{
    [TestFixture ()]
    public class NUnitTestPlayer
    {
        [Test ()]
        public void TestPlayerIsIdentifiable ()
        {
            Player John = new Player ("John", "Random Player");
            Assert.AreEqual (true, John.AreYou ("me"), "Test Player is Identifiable");
            Assert.AreEqual (true, John.AreYou ("inventory"), "Test Player is Identifiable");
        }

        [Test ()]
        public void TestPlayerLocatesItem ()
        {
            Player John = new Player ("John", "Random Player");
            Item shovel = new Item (new String [] { "shovel", "spade" }, "a shovel", "This is a might fine ...");
            John.Inventory.Put (shovel);
            Assert.AreEqual (shovel, John.Locate ("shovel"), "Test Player Locates Item");
        }

        [Test ()]
        public void TestPlayerLocatesItself ()
        {
            Player John = new Player ("John", "Random Player");
            Assert.AreEqual (John, John.Locate ("me"), "Test Player Locates itself");
            Assert.AreEqual (John, John.Locate ("inventory"), "Test Player Locates itself");
        }

        [Test()]
        public void TestPlayerLocatesItemsInLocation()
        {
            Player John = new Player("John", "Random Player");
            Location hallway = new Location("Hallway", "This is a long well lit hallway");
            Item shovel = new Item(new String[] { "shovel", "spade" }, "a shovel", "This is a might fine ...");
            hallway.Inventory.Put(shovel);
            John.Location = hallway;
            Assert.AreEqual(shovel, John.Locate("shovel"), "Test Player Locates items in location");
        }

        [Test ()]
        public void TestPlayerLocatesNothing ()
        {
            Player John = new Player ("John", "Random Player");
            Assert.AreEqual (null, John.Locate ("nothing"), "Test Player Locates nothing");
        }

        [Test ()]
        public void TestPlayerFullDescription ()
        {
            Player John = new Player ("John", "Random Player");
            Item shovel = new Item (new String [] { "shovel", "spade" }, "a shovel", "This is a might fine ...");
            John.Inventory.Put (shovel);
            Assert.AreEqual ("You are carrying:\r\n\ta shovel (shovel)\r\n", John.FullDescription, "Test Player full description");
        }
    }
}
