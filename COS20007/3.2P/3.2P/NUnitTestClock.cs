﻿using NUnit.Framework;
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
            for (int i = 0; i < 500 * 1000 * 1000; i++)
            {
                d += 1;
            }
            Assert.AreNotEqual("00:00:00", c.Time, "Should get time at 5 second");
        }

        [Test()]
        public void TestTick()
        {
            Clock c = new Clock();
            for (int i = 0; i <= 102; i++)
            {
                c.Tick();
            }
            Assert.AreEqual("00:01:42", c.Time, "Should tick 102 times and be 1 minute and 42 second");
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
