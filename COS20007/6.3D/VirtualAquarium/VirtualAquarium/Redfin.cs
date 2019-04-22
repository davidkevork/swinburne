using System;
namespace VirtualAquarium
{
    // nothing special about this fish
    public class Redfin : Fish
    {
        public Redfin() : base() { }

        public override string Draw()
        {
            return "  ;,//;,    ,;/\r\n" +
                   " o:::::::;;///\r\n" +
                   ">::::::::;;\\\\\\\r\n" +
                   "  ''\\\\\\\\\\'\" ';\\\r\n";
        }
    }
}
