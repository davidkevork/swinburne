using NUnit.Framework;
using System;

namespace SwinAdventure.src.test
{
    [TestFixture()]
    public class NUnitTestIdentifiy
    {
        [Test()]
        public void TestIdentifyConstructor()
        {
            Identify ident = new Identify(new string[] { "id1", "id2" });

            Assert.AreEqual("id1", ident.FirstId, "Identify constructor should add idents");
            Assert.AreEqual(2, ident.Count(), "Should have 2 ids inserted");
        }

        [Test()]
        public void TestFirstId()
        {
            Identify ident = new Identify(new string[] { });

            Assert.AreEqual("", ident.FirstId, "Should have empty list");
        }

        [Test()]
        public void TestAreYou()
        {
            Identify ident = new Identify(new string[] { "id1", "id2" });

            Assert.AreEqual(true, ident.AreYou("id1"), "Should find id is in list");
        }

        [Test()]
        public void TestNotAreYou()
        {
            Identify ident = new Identify(new string[] { "id1", "id2" });

            Assert.AreEqual(false, ident.AreYou("id5"), "Should find id is not in list");
        }

        [Test()]
        public void TestCaseSensitive()
        {
            Identify ident = new Identify(new string[] { "id1", "id2" });

            Assert.AreEqual(true, ident.AreYou("ID1"), "Should find id is in list");
        }

        [Test()]
        public void TestCount()
        {
            Identify ident = new Identify(new string[] { "id1", "id2" });

            Assert.AreEqual(2, ident.Count(), "Should have 2 ids inserted");
        }

        [Test()]
        public void TestAddIdentifier()
        {
            Identify ident = new Identify(new string[] { });
            ident.AddIdentifier("ID1");

            Assert.AreEqual("id1", ident.FirstId, "Should turn id to LowerCase before inserting");
        }
    }
}
