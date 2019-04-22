import Counter from './Counter';
import Clock from './Clock';

function PrintCounters(counters: Counter[]): void
{
  counters.forEach((c: Counter) => {
    console.log(`${c.Name} is ${c.Value}`);
  });
}

const myCounters: Array<Counter> = [];

myCounters[0] = new Counter("Counter 1");
myCounters[1] = new Counter("Counter 2");
myCounters[2] = new Counter("Counter 3");

for (let i = 0; i < 4; i++)
{
  myCounters[0].Increment();
}

for (let i = 0; i < 9; i++)
{
  myCounters[1].Increment();
}

PrintCounters(myCounters);
myCounters[2].Reset();
PrintCounters(myCounters);

const c: Clock = new Clock();
c.Tick();
c.Tick();
c.Tick();
console.log(c.Time);