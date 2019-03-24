﻿using System;

namespace CounterObject
{
    class MainClass
    {
        private static void PrintCounters(Counter[] counters
        )
        {
            foreach(Counter c in counters)
            {
                Console.WriteLine("{0} is {1}", c.Name, c.Value);
            }
            Console.WriteLine("");
        }

        public static void Main(string[] args)
        {
            Clock c = new Clock();
            Console.WriteLine(c.Time);
            Counter[] myCounters = new Counter[3];

            myCounters[0] = new Counter("Counter 1");
            myCounters[1] = new Counter("Counter 2");
            myCounters[2] = new Counter("Counter 3");

            for (int i = 0; i < 4; i++)
            {
                myCounters[0].Increment();
            }

            for (int i = 0; i < 9; i++)
            {
                myCounters[1].Increment();
            }

            PrintCounters(myCounters);
            myCounters[2].Reset();
            PrintCounters(myCounters);

            double d = 0;
            for (int i = 0; i < 200 * 1000 * 1000; i++)
            {
                d += 1;
            }
            Console.WriteLine(c.Time);
        }
    }
}
