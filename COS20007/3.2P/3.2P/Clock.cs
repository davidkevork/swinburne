using System;
using System.Timers;

namespace CounterObject
{
    public class Clock
    {
        private Counter _hour;
        private Counter _minute;
        private Counter _second;
        private Timer _tick;

        public Clock()
        {
            _hour = new Counter("Hour");
            _minute = new Counter("Minute");
            _second = new Counter("Second");

            _tick = new Timer();
            _tick.Interval = 100;
            _tick.Enabled = true;
            _tick.Elapsed += _tick_Elapsed;
            _tick.Start();
        }

        private void _tick_Elapsed(object sender, ElapsedEventArgs e)
        {
            Tick();
        }

        public void Tick()
        {
            if (_second.Value < 60)
            {
                _second.Increment();
            }
            else
            {
                _second.Reset();
                if (_minute.Value < 60)
                {
                    _minute.Increment();
                }
                else
                {
                    _minute.Reset();
                    if (_hour.Value < 24)
                    {
                        _hour.Increment();
                    }
                    else
                    {
                        _hour.Reset();
                    }
                }

            }
        }

        public string Time
        {
            get
            {
                return (_hour.Value).ToString("00") + ":" + (_minute.Value).ToString("00") + ":" + (_second.Value).ToString("00");
            }
        }

        public void Reset()
        {
            _hour.Reset();
            _minute.Reset();
            _second.Reset();
        }
    }
}
