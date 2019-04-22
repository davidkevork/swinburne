using System;
using System.IO;

namespace VirtualAquarium
{
    public class Snapper : Fish
    {
        private string _restrictions = "Must be landed whole or as a carcass";

        public Snapper(int bagLimit, int sizeLimit, double eatingScore, double sportingScore) : base(bagLimit, sizeLimit, eatingScore, sportingScore) { }

        public Snapper() : base() { }

        public string Restrictions
        {
            get
            {
                return _restrictions;
            }
            set
            {
                _restrictions = value;
            }
        }

        public override string FullDescription
        {
            get
            {
                return base.FullDescription + "Restriction: " + Restrictions + "\r\n";
            }
        }

        public override string Draw()
        {
            return "        /\"*._         _\r\n" +
                   "   .-*'`    `*-.._.-'/\r\n" +
                   " < * ))     ,       ( \r\n" +
                   "   `*-._`._(__.--*\"`.\\\r\n";
        }

        public override void SaveTo(StreamWriter writer)
        {
            base.SaveTo(writer);
            writer.WriteLine(Restrictions);
        }

        public override void LoadFrom(StreamReader reader)
        {
            base.LoadFrom(reader);
            Restrictions = reader.ReadLine();
        }
    }
}
