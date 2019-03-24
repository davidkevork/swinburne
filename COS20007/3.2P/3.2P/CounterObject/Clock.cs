using System;
using System.Timers;

namespace CounterObject
{
    public class Clock
    {
        private int _hour;
        private int _minute;
        private int _second;
        private Timer _tick;

        public Clock()
        {
            _hour = 0;
            _minute = 0;
            _second = 0;

            _tick = new Timer();
            _tick.Interval = 100;
            _tick.Enabled = true;
            _tick.Elapsed += _tick_Elapsed;
            _tick.Start();
        }

        private void _tick_Elapsed(object sender, ElapsedEventArgs e)
        {
            if (_second < 60)
            {
                _second++;
            }
            else
            {
                _second = 0;
                if (_minute < 60)
                {
                    _minute++;
                }
                else
                {
                    _minute = 0;
                    if (_hour < 24)
                    {
                        _hour++;
                    }
                    else
                    {
                        _hour = 0;
                    }
                }

            }
        }

        public string Time
        {
            get
            {
                return (_hour).ToString("00") + ":" + (_minute).ToString("00") + ":" + (_second).ToString("00");
            }
        }

        public void Reset()
        {
            _hour = 0;
            _minute = 0;
            _second = 0;
        }
    }
}
