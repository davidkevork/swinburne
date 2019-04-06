using NUnit.Framework;
using System;

namespace MyGame
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

        [Test ()]
        public void TestPlayerLocatesNothing ()
        {
            Player John = new Player ("John", "Random Player");
            Assert.AreEqual (null, John.Locate ("nothing"), "Test Player Locates itself");
        }

        [Test ()]
        public void TestPlayerFullDescription ()
        {
            Player John = new Player ("John", "Random Player");
            Item shovel = new Item (new String [] { "shovel", "spade" }, "a shovel", "This is a might fine ...");
            John.Inventory.Put (shovel);
            Assert.AreEqual ("You are carrying:\r\na shovel (shovel)\r\n", John.FullDescription, "Test Player Locates itself");
        }
    }
}
