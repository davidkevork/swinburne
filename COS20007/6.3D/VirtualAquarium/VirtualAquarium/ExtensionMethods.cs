using System;
using System.IO;

namespace VirtualAquarium
{
    /// <summary>
    /// Extension class for StreamReader
    /// ReadIteger will read a line and convert to integer
    /// ReadDouble will read a line and convert to double
    /// </summary>
    public static class ExtensionMethods
    {
        public static int ReadInteger(this StreamReader reader)
        {
            return Convert.ToInt32(reader.ReadLine());
        }

        public static double ReadDouble(this StreamReader reader)
        {
            return Convert.ToDouble(reader.ReadLine());
        }
    }
}
