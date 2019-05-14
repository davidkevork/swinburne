using NUnit.Framework;
using System;
namespace SwinAdventure.src.test
{
    [TestFixture()]
    public class NUnitQuitCommand
    {
        [Test()]
        public void TestCase()
        {
            QuitCommand quit = new QuitCommand();
            Player testPlayer = new Player("James", "Deer hunter");
            Assert.AreEqual("Quitting", quit.Execute(testPlayer, new String[] { "quit" }));
            Assert.AreEqual("Quitting", quit.Execute(testPlayer, new String[] { "exit" }));

            Assert.AreEqual("I don't understand that", quit.Execute(testPlayer, new String[] { "wrongCommand" }));
        }
    }
}
