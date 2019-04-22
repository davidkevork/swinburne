using System;
using System.Collections.Generic;
using System.IO;

namespace VirtualAquarium
{
    /// <summary>
    /// An Aquarium class
    /// </summary>
    public class Aquarium
    {
        private readonly List<Fish> _fish;

        /// <summary>
        /// Initialize Aquarium by creating an empty list of fish
        /// </summary>
        public Aquarium()
        {
            _fish = new List<Fish>();
        }

        public int FishCount
        {
            get
            {
                return _fish.Count;
            }
        }

        /// <summary>
        /// Add a fish to Aquarium
        /// </summary>
        public void AddFish(Fish s)
        {
            _fish.Add(s);
        }

        /// <summary>
        /// Remove a fish from Aquarium
        /// </summary>
        public void RemoveFish(Fish s)
        {
            _fish.Remove(s);
        }

        /// <summary>
        /// List of fish in the Aquarium
        /// </summary>
        public List<Fish> FishList
        {
            get
            {
                return _fish;
            }
        }

        /// <summary>
        /// Full Description of the aquarium
        /// including full description of every fish in the aquarium
        /// </summary>
        public string FullDescription
        {
            get
            {
                if (FishCount == 0)
                {
                    return "There are no fish in your aquarium\r\n";
                }
                else
                {
                    string fullDesc = "In your aquarium there are " + FishCount + " fish\r\n";
                    foreach (Fish fish in _fish)
                    {
                        fullDesc += fish.FullDescription;
                        fullDesc += fish.Draw();
                    }
                    return fullDesc;
                }
            }
        }

        /// <summary>
        /// Save the list of fish in the aquarium to a file
        /// </summary>
        public void Save(string filename)
        {
            StreamWriter writer = new StreamWriter(filename);

            writer.WriteLine(FishCount);

            try
            {
                foreach (Fish shape in _fish)
                {
                    shape.SaveTo(writer);
                }
            }
            finally
            {
                writer.Close();
            }
        }

        /// <summary>
        /// Load list of fish from file to aquarium
        /// </summary>
        public void Load(string filename)
        {
            StreamReader reader = new StreamReader(filename);
            int count;
            Fish fish;
            string kind = null;

            count = reader.ReadInteger();

            try
            {
                for (int i = 0; i < count; i++)
                {
                    kind = reader.ReadLine();
                    fish = Fish.CreateFish(kind);
                    fish.LoadFrom(reader);
                    AddFish(fish);
                }
            }
            finally
            {
                reader.Close();
            }
        }
    }
}
