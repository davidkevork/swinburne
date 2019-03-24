using NUnit.Framework;
using System;
namespace CounterObject
{
    [TestFixture()]
    public class NUnitTestClock
    {
        [Test()]
        public void TestClock()
        {
            Clock c = new Clock();

            Assert.AreEqual("00:00:00", c.Time, "Should initialize and get time at start");
        }

        [Test()]
        public void Test_tick_Elapsed()
        {
            Clock c = new Clock();
            double d = 0;
            for (int i = 0; i < 200 * 1000 * 1000; i++)
            {
                d += 1;
            }
            Assert.AreEqual("00:00:05", c.Time, "Should get time at 5 second");
        }

        [Test()]
        public void TestReset()
        {
            Clock c = new Clock();
            double d = 0;
            for (int i = 0; i < 200 * 1000 * 1000; i++)
            {
                d += 1;
            }
            c.Reset();

            Assert.AreEqual("00:00:00", c.Time, "Should reset time");
        }
    }
}
