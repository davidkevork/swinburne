using System;

namespace SwinAdventure.src
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            Console.Write("Enter Player Name: ");
            string PlayerName = Console.ReadLine();
            Console.Write("Enter Player Description: ");
            string PlayerDescription = Console.ReadLine();

            Player GamePlayer = new Player(PlayerName, PlayerDescription);
            Item Gun = new Item(new String[] { "gun", "rifle" }, "a gun", "This is a killing tool ...");
            Item Shovel = new Item(new String[] { "shovel", "spade" }, "a shovel", "This is a might fine ...");

            GamePlayer.Inventory.Put(Gun);
            GamePlayer.Inventory.Put(Shovel);

            Bag PlayerBag = new Bag(new string[] { "Bag" }, "A Bag", "Game Player's Bag ...");

            GamePlayer.Inventory.Put(PlayerBag);

            Item Gem = new Item(new string[] { "gem", "shiny" }, "Gem", "A Shiny Gem ...");
            PlayerBag.Inventory.Put(Gem);

            do
            {
                Console.Write("Enter Command: ");
                string UserInput = Console.ReadLine();
                String[] Command = UserInput.Split(' ');
                Console.WriteLine((new LookCommand()).Execute(GamePlayer, Command));
            }
            while (true);
        }
    }
}
