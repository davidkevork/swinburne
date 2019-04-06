using NUnit.Framework;
using System;

namespace SwinAdventure.src.test
{
    [TestFixture ()]
    public class NUnitTestItem
    {
        [Test ()]
        public void TestItem ()
        {
            Item shovel = new Item (new String [] { "shovel", "spade" }, "a shovel", "This is a might fine ...");
            Assert.AreEqual (true, shovel.AreYou ("shovel"), "Test Item is Identifiable");
        }

        [Test()]
        public void ShortDescription ()
        {
            Item shovel = new Item (new String [] { "shovel", "spade" }, "a shovel", "This is a might fine ...");
            Assert.AreEqual ("a shovel (shovel)", shovel.ShortDescription, "Test Short Description");
        }

        [Test ()]
        public void FullDescription ()
        {
            Item shovel = new Item (new String [] { "shovel", "spade" }, "a shovel", "This is a might fine ...");
            Assert.AreEqual ("This is a might fine ...", shovel.FullDescription, "Test Full Description");
        }
    }
}
