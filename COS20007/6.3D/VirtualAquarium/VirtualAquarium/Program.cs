using System;
using System.Collections.Generic;

namespace VirtualAquarium
{
    class MainClass
    {
        /// <summary>
        /// List of fish species
        /// </summary>
        private static List<string> FishSpecies = new List<string> {
            "AustralianBass",
            "Blackfish",
            "CrayfishSpiny",
            "Snapper",
            "Redfin"
        };

        private enum FishSpeciesEnum {
            AustralianBass,
            Blackfish,
            CrayfishSpiny,
            Snapper,
            Redfin
        };

        /// <summary>
        /// Register fish
        /// Write out commands
        /// listen to command
        /// </summary>
        public static void Main(string[] args)
        {
            Fish.RegisterFish("AustralianBass", typeof(AustralianBass));
            Fish.RegisterFish("Blackfish", typeof(Blackfish));
            Fish.RegisterFish("CrayfishSpiny", typeof(CrayfishSpiny));
            Fish.RegisterFish("Snapper", typeof(Snapper));
            Fish.RegisterFish("Redfin", typeof(Redfin));

            Aquarium myAquarium = new Aquarium();

            Console.WriteLine("List of commands");
            Console.WriteLine("view         – View your aquarium");
            Console.WriteLine("save         – Save your aquarium into a file");
            Console.WriteLine("load         – Load your aquarium from a file");
            Console.WriteLine("list         – Display the list of fish");
            Console.WriteLine("add fishname – Add a fish to your aquarium");
            Console.WriteLine("exit");

            string command;
            string[] commandArr;

            do {
                Console.Write("Enter a command: ");
                command = Console.ReadLine().ToLower();
                commandArr = ToStringArray(command);
                switch (commandArr[0])
                {
                    case "view":
                        Console.WriteLine(myAquarium.FullDescription);
                        break;
                    case "save":
                        myAquarium.Save("./myAquarium");
                        Console.WriteLine("Aquarium saved to ./myAquarium file");
                        break;
                    case "load":
                        myAquarium.Load("./myAquarium");
                        Console.WriteLine("Aquarium loaded from ./myAquarium file");
                        break;
                    case "list":
                        foreach (string fish in FishSpecies)
                        {
                            Console.WriteLine(fish);
                        }
                        break;
                    case "add":
                        if (commandArr.Length == 1)
                        {
                            Console.WriteLine("add  fishname – Add a fish to your aquarium");
                            return;

                        }
                        Fish newFish = null;
                        switch (commandArr[1])
                        {
                            case "australianbass":
                                newFish = new AustralianBass(5, 27, 4.0, 4.0);
                                break;
                            case "blackfish":
                                newFish = new Blackfish(5, 23);
                                break;
                            case "crayfishspiny":
                                newFish = new CrayfishSpiny(5, 9, 4.5);
                                break;
                            case "snapper":
                                newFish = new Snapper(10, 28, 4.8, 4.0);
                                break;
                            case "redfin":
                                newFish = new Redfin();
                                break;
                            default:
                                Console.WriteLine("Fish species was not found");
                                break;
                        }
                        if (newFish != null)
                        {
                            myAquarium.AddFish(newFish);
                        }
                        break;
                    default:
                        Console.WriteLine("Command not found");
                        break;
                }
            } while (command != "exit");
        }

        private static string[] ToStringArray(string s)
        {
            string[] strArr = null;
            char[] splitchar = { ' ' };
            strArr = s.Split(splitchar);
            return strArr;
        }
    }
}
