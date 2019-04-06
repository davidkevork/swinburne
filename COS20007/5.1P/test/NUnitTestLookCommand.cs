using NUnit.Framework;
using System;
namespace SwinAdventure.src.test
{
    [TestFixture()]
    public class NUnitTestLookCommand
    {
        [Test()]
        public void TestLookAtMe()
        {
            LookCommand look = new LookCommand();
            Player testPlayer = new Player("James", "Deer hunter");
            Assert.AreEqual("You are not carrying anything", look.Execute(testPlayer, new String[] { "look", "at", "inventory" }), "Test look at me");
        }

        [Test()]
        public void TestLookAtGem()
        {
            LookCommand look = new LookCommand();
            Player testPlayer = new Player("James", "Deer hunter");
            testPlayer.Inventory.Put(new Item(new String[] { "gun", "rifle" }, "a gun", "This is a killing tool ..."));
            Assert.AreEqual("This is a killing tool ...", look.Execute(testPlayer, new String[] { "look", "at", "gun" }), "test look at item in inventory");
        }

        [Test()]
        public void TestLookAtUnk()
        {
            LookCommand look = new LookCommand();
            Player testPlayer = new Player("James", "Deer hunter");
            Assert.AreEqual("I cannot find the gun", look.Execute(testPlayer, new String[] { "look", "at", "gun" }), "test  look at item");
        }

        [Test()]
        public void TestLookAtGemInMe()
        {
            LookCommand look = new LookCommand();
            Player testPlayer = new Player("James", "Deer hunter");
            Assert.AreEqual("I cannot find the gun", look.Execute(testPlayer, new String[] { "look", "at", "gun", "in", "inventory" }), "test look at item in inventory");
        }

        [Test()]
        public void TestLookAtGemInBag()
        {
            LookCommand look = new LookCommand();
            Player testPlayer = new Player("James", "Deer hunter");
            Bag testBag = new Bag(new string[] { "Bag", "Backpack" }, "a bag", "This is a bag for....");
            testBag.Inventory.Put(new Item(new String[] { "shovel", "spade" }, "a shovel", "This is a might fine ..."));
            testPlayer.Inventory.Put(testBag);
            Assert.AreEqual("This is a might fine ...", look.Execute(testPlayer, new String[] { "look", "at", "shovel", "in", "bag" }), "test look returns items description");
        }

        [Test()]
        public void TestLookAtGemInNoBag()
        {
            LookCommand look = new LookCommand();
            Player testPlayer = new Player("James", "Deer hunter");
            Assert.AreEqual("I cannot find the bag", look.Execute(testPlayer, new String[] { "look", "at", "shovel", "in", "bag" }), "test look cannot find the container");
        }

        [Test()]
        public void TestLookAtNoGemInBag()
        {
            LookCommand look = new LookCommand();
            Player testPlayer = new Player("James", "Deer hunter");
            Bag testBag = new Bag(new string[] { "Bag", "Backpack" }, "a bag", "This is a bag for....");
            testPlayer.Inventory.Put(testBag);
            Assert.AreEqual("I cannot find the shovel in the bag", look.Execute(testPlayer, new String[] { "look", "at", "shovel", "in", "bag" }), "test look cannot find item in the container");
        }

        [Test()]
        public void TestInvalidLook()
        {
            LookCommand look = new LookCommand();
            Player testPlayer = new Player("James", "Deer hunter");
            Assert.AreEqual("I don't know how to look like that", look.Execute(testPlayer, new String[] { "look", "down" }), "test invalid look command");
            Assert.AreEqual("Error in look input", look.Execute(testPlayer, new String[] { "hello", "deer", "hunter" }), "test invalid look command");
            Assert.AreEqual("What do you want to look in?", look.Execute(testPlayer, new String[] { "look", "at", "drink", "about", "me" }), "test invalid look command");
            Assert.AreEqual("What do you want to look at?", look.Execute(testPlayer, new String[] { "look", "over", "that" }), "test invalid look command");
        }
    }
}
