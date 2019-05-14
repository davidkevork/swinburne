using NUnit.Framework;
using System;
namespace SwinAdventure.src.test
{
    [TestFixture()]
    public class NUnitTestCommandProcessor
    {
        public void LookTest()
        {
            Player John = new Player ("John", "Random Player");

            LookCommand TestLook = new LookCommand();

            CommandProcessor TestProcessor = new CommandProcessor();

            TestProcessor.AddCommand(TestLook);

            Console.WriteLine(TestProcessor.Execute(John, new string[] { "look", "at", "me" }));

            Assert.AreEqual(John.FullDescription, TestProcessor.Execute(John, new string[] { "look", "at", "me" }));
        }

        [Test()]
        public void MoveTest()
        {
            Player John = new Player ("John", "Random Player");
            Location TestLocation1 = new Location("Hallway", "This is a long well lit hallway");
            Location TestLocation2 = new Location("Small Closet", "A small dark closet, with an odd smell");
            Location TestLocation3 = new Location("Small Garden", "There are many small shrubs and flowers growing from well tended garden beds.");

            Path TestPath = new Path();
            Path TestPath2 = new Path();
            Path TestPath3 = new Path();


            TestLocation1.Path = TestPath;
            TestPath.SetLocation("west", TestLocation2);
            TestPath.SetLocation("north", TestLocation3);

            TestLocation2.Path = TestPath2;
            TestPath2.SetLocation("east", TestLocation1);
            TestPath2.SetLocation("northeast", TestLocation3);

            TestLocation3.Path = TestPath3;
            TestPath3.SetLocation("south", TestLocation1);
            TestPath3.SetLocation("southwest", TestLocation2);

            John.Location = TestLocation1;


            MoveCommand TestMove = new MoveCommand();
            CommandProcessor TestProcessor = new CommandProcessor();

            TestProcessor.AddCommand(TestMove);

            Assert.AreEqual(TestLocation2.FullDescription, TestProcessor.Execute(John, new string[] { "move", "west" }));
            Assert.AreEqual(TestLocation3.FullDescription, TestProcessor.Execute(John, new string[] { "move", "northeast" }));
        }

        [Test()]
        public void MultipleCommandTest()
        {
            Player John = new Player ("John", "Random Player");
            Location TestLocation1 = new Location("Hallway", "This is a long well lit hallway");
            Location TestLocation2 = new Location("Small Closet", "A small dark closet, with an odd smell");
            Location TestLocation3 = new Location("Small Garden", "There are many small shrubs and flowers growing from well tended garden beds.");

            Path TestPath = new Path();
            Path TestPath2 = new Path();
            Path TestPath3 = new Path();


            TestLocation1.Path = TestPath;
            TestPath.SetLocation("west", TestLocation2);
            TestPath.SetLocation("north", TestLocation3);

            TestLocation2.Path = TestPath2;
            TestPath2.SetLocation("east", TestLocation1);
            TestPath2.SetLocation("northeast", TestLocation3);

            TestLocation3.Path = TestPath3;
            TestPath3.SetLocation("south", TestLocation1);
            TestPath3.SetLocation("southwest", TestLocation2);

            John.Location = TestLocation1;


            MoveCommand TestMove = new MoveCommand();
            LookCommand TestLook = new LookCommand();
            CommandProcessor TestProcessor = new CommandProcessor();

            TestProcessor.AddCommand(TestMove);

            TestProcessor.AddCommand(TestLook);

            Assert.AreEqual(John.FullDescription, TestProcessor.Execute(John, new string[] { "look", "at", "me" }));
            Assert.AreEqual(TestLocation2.FullDescription, TestProcessor.Execute(John, new string[] { "move", "west" }));
            Assert.AreEqual(TestLocation3.FullDescription, TestProcessor.Execute(John, new string[] { "move", "northeast" }));
        }
    }
}
