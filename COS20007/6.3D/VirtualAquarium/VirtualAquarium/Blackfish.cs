using System;
using System.IO;

namespace VirtualAquarium
{
    public class Blackfish : Fish
    {

        public Blackfish(int bagLimit, int sizeLimit) : base(bagLimit, sizeLimit) { }

        public Blackfish() : base() { }

        public string ClosedSeasonStart { get; set; } = "1 September";
        public string ClosedSeasonEnd { get; set; } = "31 December";

        public override string FullDescription
        {
            get
            {
                return base.FullDescription + "Closed Season Start: " + ClosedSeasonEnd + "\r\n"
                                            + "Closed Season End: " + ClosedSeasonEnd + "\r\n";
            }
        }

        public override string Draw()
        {
            return "      /`·.¸\r\n" +
                   "     /¸...¸`:·\r\n" +
                   " ¸.·´  ¸   `·.¸.·´)\r\n" +
                   ": © ):´;      ¸  {\r\n" +
                   " `·.¸ `·  ¸.·´\\`·¸)\r\n" +
                   "     `\\\\´´\\¸.·´\r\n";
        }

        public override void SaveTo(StreamWriter writer)
        {
            base.SaveTo(writer);
            writer.WriteLine(ClosedSeasonStart);
            writer.WriteLine(ClosedSeasonEnd);
        }

        public override void LoadFrom(StreamReader reader)
        {
            base.LoadFrom(reader);
            ClosedSeasonStart = reader.ReadLine();
            ClosedSeasonEnd = reader.ReadLine();
        }
    }
}
