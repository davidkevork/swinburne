using NUnit.Framework;
using System;

namespace SwinAdventure.src.test
{
    [TestFixture()]
    public class NUnitTestLocation
    {
        [Test()]
        public void TestLocatationLocatesItself ()
        {
            Location hallway = new Location("Hallway", "This is a long well lit hallway");
            Assert.AreEqual(true, hallway.AreYou("room"), "Test Location locates itself");
            Assert.AreEqual(true, hallway.AreYou("here"), "Test Location locates itself");
        }

        [Test()]
        public void TestLocatationLocatesItem ()
        {
            Location hallway = new Location("Hallway", "This is a long well lit hallway");
            Item shovel = new Item(new String[] { "shovel", "spade" }, "a shovel", "This is a might fine ...");
            hallway.Inventory.Put(shovel);
            Assert.AreEqual(shovel, hallway.Locate("shovel"), "Test Location Locates Item");
        }

        [Test()]
        public void TestLocatationLocatesNothing()
        {
            Location hallway = new Location("Hallway", "This is a long well lit hallway");
            Assert.AreEqual(null, hallway.Locate("nothing"), "Test Location Locates nothing");
        }

        [Test()]
        public void TestLocatationsFullDescription()
        {
            Location hallway = new Location("Hallway", "This is a long well lit hallway");
            Item shovel = new Item(new String[] { "shovel", "spade" }, "a shovel", "This is a might fine ...");
            hallway.Inventory.Put(shovel);
            Assert.AreEqual("You are in Hallway\r\nThis is a long well lit hallway\r\n\ta shovel (shovel)\r\n", hallway.FullDescription, "Test Location full description");
        }
    }
}
