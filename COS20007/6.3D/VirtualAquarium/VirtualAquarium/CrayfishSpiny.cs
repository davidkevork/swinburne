using System;
using System.IO;

namespace VirtualAquarium
{
    public class CrayfishSpiny : Fish
    {
        private string _danger = "The claws are strong and can inflict injury when handled";

        public CrayfishSpiny(int bagLimit, int sizeLimit, double eatingScore) : base(bagLimit, sizeLimit, eatingScore) { }

        public CrayfishSpiny() : base() { }

        public string Danger
        {
            get
            {
                return _danger;
            }
            set
            {
                _danger = value;
            }
        }

        public override string FullDescription
        {
            get
            {
                return base.FullDescription + "Danger: " + Danger + "\r\n";
            }
        }

        public override string Draw()
        {
            return "     /\\\r\n" +
                   "    ( /   @ @    ()\r\n" +
                   "     \\\\ __| |__  /\r\n" +
                   "      \\/   \"   \\/\r\n" +
                   "     /-|       |-\\\r\n" +
                   "    / /-\\     /-\\ \\\r\n" +
                   "     / /-`---'-\\ \\\r\n" +
                   "      /         \\ \r\n";
        }

        public override void SaveTo(StreamWriter writer)
        {
            base.SaveTo(writer);
            writer.WriteLine(Danger);
        }

        public override void LoadFrom(StreamReader reader)
        {
            base.LoadFrom(reader);
            Danger = reader.ReadLine();
        }
    }
}
