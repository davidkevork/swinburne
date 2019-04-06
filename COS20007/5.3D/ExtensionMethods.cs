using System;
using System.IO;

namespace MyGame
{
    public static class ExtensionMethods
    {
        public static int ReadInteger (this StreamReader reader)
        {
            return Convert.ToInt32 (reader.ReadLine ());
        }
    }
}
