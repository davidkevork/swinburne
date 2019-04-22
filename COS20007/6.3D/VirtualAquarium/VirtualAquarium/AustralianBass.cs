using System;
using System.IO;

namespace VirtualAquarium
{
    public class AustralianBass : Fish
    {
        public AustralianBass(int bagLimit, int sizeLimit, double eatingScore, double sportingScore): base(bagLimit, sizeLimit, eatingScore, sportingScore) { }

        public AustralianBass() : base() { }

        public string Diet { get; set; } = "earthworms";

        public override string FullDescription
        {
            get
            {
                return base.FullDescription + "Diet: " + Diet + "\r\n";
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
            writer.WriteLine(Diet);
        }

        public override void LoadFrom(StreamReader reader)
        {
            base.LoadFrom(reader);
            Diet = reader.ReadLine();
        }
    }
}
