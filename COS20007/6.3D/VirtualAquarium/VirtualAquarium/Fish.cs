using System;
using System.IO;
using System.Collections.Generic;

namespace VirtualAquarium
{
    /// <summary>
    /// Abstract fish class
    /// </summary>
    public abstract class Fish
    {
        private int _bagLimit;
        private int _sizeLimit;
        private double _eatingScore;
        private double _sportingScore;

        public static Dictionary<string, Type> _FishClassRegistry = new Dictionary<string, Type>();

        /// <summary>
        /// Register fish into a dictionary
        /// </summary>
        public static void RegisterFish(string name, Type t)
        {
            _FishClassRegistry[name] = t;
        }

        /// <summary>
        /// Creates a new instance of the fish class based on fish class registery
        /// </summary>
        public static Fish CreateFish(string name)
        {
            return (Fish) Activator.CreateInstance(_FishClassRegistry[name]);
        }

        /// <summary>
        /// This class does something.
        /// </summary>
        public static string GetKey(Type t)
        {
            foreach (var val in _FishClassRegistry.Keys)
            {
                if (t == _FishClassRegistry[val])
                    return val;
            }
            return null;
        }

        /// <summary>
        /// Fish constructor
        /// Each fish will have different or sometimes no value and default value is set
        /// </summary>
        public Fish(int bagLimit, int sizeLimit, double eatingScore, double sportingScore)
        {
            _bagLimit = bagLimit;
            _sizeLimit = sizeLimit;
            _eatingScore = eatingScore;
            _sportingScore = sportingScore;
        }

        public Fish(int bagLimit, int sizeLimit, double eatingScore) : this(bagLimit, sizeLimit, eatingScore, -1.0) { }

        public Fish(int bagLimit, int sizeLimit) : this (bagLimit, sizeLimit, -1.0, -1.0) { }

        public Fish(int bagLimit) : this(bagLimit, -1, -1.0, -1.0) { }

        public Fish() : this (-1, -1, -1.0, -1.0) { }

        /// <summary>
        /// Fish name
        /// </summary>
        public string Name
        {
            get
            {
                return GetKey(GetType());
            }
        }

        /// <summary>
        /// Fish limit in aquarium
        /// </summary>
        public int BagLimit
        {
            get
            {
                return _bagLimit;
            }
            set
            {
                _bagLimit = value;
            }
        }

        /// <summary>
        /// fish size limit in aquarium
        /// </summary>
        public int SizeLimit
        {
            get
            {
                return _sizeLimit;
            }
            set
            {
                _sizeLimit = value;
            }
        }

        /// <summary>
        /// fish eating score
        /// </summary>
        public double EatingScore
        {
            get
            {
                return _eatingScore;
            }
            set
            {
                _eatingScore = value;
            }
        }

        /// <summary>
        /// fish catch sporting score
        /// </summary>
        public double SportingScore
        {
            get
            {
                return _sportingScore;
            }
            set
            {
                _sportingScore = value;
            }
        }

        /// <summary>
        /// Draw fish in ascii
        /// </summary>
        public abstract string Draw();

        /// <summary>
        /// Full description of the fish
        /// </summary>
        public virtual string FullDescription
        {
            get
            {
                string fullDesc = "";
                fullDesc += "Fish Name: " + Name + "\r\n";
                fullDesc += BagLimit.Equals(-1) ? "No bag limit\r\n" : "Bag Limit: " + BagLimit + "\r\n";
                fullDesc += SizeLimit.Equals(-1) ? "No size limit\r\n" : "Size Limit: " + SizeLimit + "\r\n";
                fullDesc += EatingScore.Equals(-1f) ? "No eating score\r\n" : "Eating Score: " + EatingScore + "\r\n";
                fullDesc += SportingScore.Equals(-1f) ? "No sporting score\r\n" : "Sporting Score: " + SportingScore + "\r\n";
                return fullDesc;
            }
        }

        /// <summary>
        /// Save fish data into file
        /// </summary>
        public virtual void SaveTo(StreamWriter writer)
        {
            writer.WriteLine(Name);
            writer.WriteLine(BagLimit);
            writer.WriteLine(SizeLimit);
            writer.WriteLine(EatingScore);
            writer.WriteLine(SportingScore);
        }

        /// <summary>
        /// load fish data from file
        /// </summary>
        public virtual void LoadFrom(StreamReader reader)
        {
            BagLimit = reader.ReadInteger();
            SizeLimit = reader.ReadInteger();
            EatingScore = reader.ReadDouble();
            SportingScore = reader.ReadDouble();
        }
    }
}
