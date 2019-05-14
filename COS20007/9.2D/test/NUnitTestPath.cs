using NUnit.Framework;
using System;
namespace SwinAdventure.src.test
{
    [TestFixture()]
    public class NUnitTestPath
    {
        [Test()]
        public void PathMoveTest()
        {
            Player John = new Player ("John", "Random Player");
            Location TestLocation1 = new Location("Hallway", "This is a long well lit hallway");
            Location TestLocation2 = new Location("Small Closet", "A small dark closet, with an odd smell");
            Location TestLocation3 = new Location("Small Garden", "There are many small shrubs and flowers growing from well tended garden beds.");

            Path TestPath1 = new Path();
            Path TestPath2 = new Path();

            TestLocation1.Path = TestPath1;
            TestPath1.SetLocation("west", TestLocation2);
            TestPath1.SetLocation("north", TestLocation3);

            TestLocation2.Path = TestPath2;
            TestPath2.SetLocation("northwest", TestLocation1);
            TestPath2.SetLocation("southeast", TestLocation3);

            John.Location = TestLocation1;

            MoveCommand TestMove = new MoveCommand();

            Assert.AreEqual(TestLocation2.FullDescription, TestMove.Execute(John, new string[] { "move", "west" }));

            John.Location = TestLocation2;
            Assert.AreEqual(TestLocation3.FullDescription, TestMove.Execute(John, new string[] { "move", "southeast" }));

        }

        [Test()]
        public void GetPathTest()
        {
            Player John = new Player ("John", "Random Player");
            Location TestLocation1 = new Location("Hallway", "This is a long well lit hallway");
            Location TestLocation2 = new Location("Small Closet", "A small dark closet, with an odd smell");
            Location TestLocation3 = new Location("Small Garden", "There are many small shrubs and flowers growing from well tended garden beds.");

            Path TestPath1 = new Path();
            Path TestPath2 = new Path();
            Path TestPath3 = new Path();

            TestLocation1.Path = TestPath1;
            TestPath1.SetLocation("west", TestLocation2);
            TestPath1.SetLocation("north", TestLocation3);

            TestLocation2.Path = TestPath2;
            TestPath2.SetLocation("east", TestLocation1);
            TestPath2.SetLocation("northest", TestLocation3);

            TestLocation3.Path = TestPath3;
            TestPath3.SetLocation("south", TestLocation1);
            TestPath3.SetLocation("sothwest", TestLocation2);

            John.Location = TestLocation1;
            Assert.AreEqual(TestLocation1.Path, TestPath1);

        }

        [Test()]
        public void LeaveTest()
        {
            Player John = new Player ("John", "Random Player");
            Location TestLocation1 = new Location("Hallway", "This is a long well lit hallway");
            Location TestLocation2 = new Location("Small Closet", "A small dark closet, with an odd smell");
            Location TestLocation3 = new Location("Small Garden", "There are many small shrubs and flowers growing from well tended garden beds.");

            Path TestPath1 = new Path();
            Path TestPath2 = new Path();
            Path TestPath3 = new Path();

            TestLocation1.Path = TestPath1;
            TestPath1.SetLocation("west", TestLocation2);
            TestPath1.SetLocation("north", TestLocation3);

            TestLocation2.Path = TestPath2;
            TestPath2.SetLocation("east", TestLocation1);
            TestPath2.SetLocation("northeast", TestLocation3);

            TestLocation3.Path = TestPath3;
            TestPath3.SetLocation("south", TestLocation1);
            TestPath3.SetLocation("southwest", TestLocation2);

            John.Location = TestLocation1;

            MoveCommand TestMove = new MoveCommand();

            Assert.AreEqual(TestLocation2.FullDescription, TestMove.Execute(John, new string[] { "move", "west" }));
            Assert.AreEqual(TestLocation1.FullDescription, TestMove.Execute(John, new string[] { "leave" }));

        }

        [Test()]
        public void LeaveFailTest()
        {
            Player John = new Player ("John", "Random Player");
            Location TestLocation1 = new Location("Hallway", "This is a long well lit hallway");
            Location TestLocation2 = new Location("Small Closet", "A small dark closet, with an odd smell");
            Location TestLocation3 = new Location("Small Garden", "There are many small shrubs and flowers growing from well tended garden beds.");

            Path TestPath1 = new Path();
            Path TestPath2 = new Path();
            Path TestPath3 = new Path();

            TestLocation1.Path = TestPath1;
            TestPath1.SetLocation("west", TestLocation2);
            TestPath1.SetLocation("north", TestLocation3);

            TestLocation2.Path = TestPath2;
            TestPath2.SetLocation("east", TestLocation1);
            TestPath2.SetLocation("northeast", TestLocation3);

            TestLocation3.Path = TestPath3;
            TestPath3.SetLocation("south", TestLocation1);
            TestPath3.SetLocation("southwest", TestLocation2);

            John.Location = TestLocation1;

            MoveCommand TestMove = new MoveCommand();

            Assert.AreEqual(TestMove.Execute(John, new string[] { "move", "nowhere" }), "Path not found");
            Assert.AreEqual(TestMove.Execute(John, new string[] { "should fail" }), "I don't know how to move like that");

        }
    }
}
