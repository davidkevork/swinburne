using NUnit.Framework;
using System;
namespace CounterObject
{
    [TestFixture()]
    public class NUnitTestCounter
    {
        [Test()]
        public void TestCounter()
        {
            Counter VCounter = new Counter("Counter");

            Assert.AreEqual(0, VCounter.Value, "Initialising the counter starts at 0");
        }

        [Test()]
        public void TestIncrement()
        {
            Counter VCounter = new Counter("Counter");
            VCounter.Increment();

            Assert.AreEqual(1, VCounter.Value, "Incrementing the counter adds one to the count");
        }

        [Test()]
        public void TestIncrementMultiple()
        {
            Counter VCounter = new Counter("Counter");
            VCounter.Increment();
            VCounter.Increment();
            VCounter.Increment();

            Assert.AreEqual(3, VCounter.Value, "Increments get multiple times increases the counter to match");
        }

        [Test()]
        public void TestReset()
        {
            Counter VCounter = new Counter("Counter");
            VCounter.Increment();
            VCounter.Increment();
            VCounter.Reset();

            Assert.AreEqual(0, VCounter.Value, "Resetting the timer sets the count to 0");
        }
    }
}
