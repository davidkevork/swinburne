using System;
using Xwt;

namespace SwinAdventure.src
{
    class MainClass
    {
        [STAThread]
        public static void Main(string[] args)
        {
            Application.Initialize(ToolkitType.Gtk);
            var mainWindow = new Window()
            {
                Title = "SwinAdventure",
                Width = 700,
                Height = 500
            };
            mainWindow.CloseRequested += delegate {
                Application.Exit();
            };

            VBox ContentData = new VBox()
            {
                ExpandHorizontal = true,
                ExpandVertical = true
            };

            string inputText = null;
            var input = new TextEntry();
            input.Changed += delegate {
                inputText = input.Text;
            };

            var button = new Button("Send Command");
            button.Type = ButtonType.Normal;
            button.Margin = 10;

            var label = new Label();
            label.BackgroundColor = Xwt.Drawing.Color.FromName("black");
            label.TextColor = Xwt.Drawing.Color.FromName("white");
            label.MinHeight = 450;

            var scrollview = new ScrollView();
            scrollview.VerticalScrollPolicy = ScrollPolicy.Automatic;
            scrollview.ExpandHorizontal = true;
            scrollview.HeightRequest = 460;
            scrollview.Content = label;

            int buttonClicks = 0;
            label.Text = "Enter Player Name: ";
            string PlayerName = null;
            Player GamePlayer = null;

            CommandProcessor MainCommandProcessor = new CommandProcessor();
            LookCommand Look = new LookCommand();
            MoveCommand Move = new MoveCommand();
            PutCommand Put = new PutCommand();
            QuitCommand Quit = new QuitCommand();

            MainCommandProcessor.AddCommand(Look);
            MainCommandProcessor.AddCommand(Move);
            MainCommandProcessor.AddCommand(Put);
            MainCommandProcessor.AddCommand(Quit);

            button.Clicked += (object sender, EventArgs e) =>
            {
                if (buttonClicks == 0)
                {
                    label.Text += inputText + "\nEnter Player Description: ";
                    PlayerName = inputText;
                }
                else if (buttonClicks == 1)
                {
                    label.Text += inputText + "\n";
                    label.Text += Look.Description();
                    label.Text += Move.Description();
                    label.Text += Put.Description();
                    label.Text += Quit.Description();
                    label.Text += "Enter Command: ";

                    GamePlayer = new Player(PlayerName, inputText);
                    Item Gun = new Item(new String[] { "gun", "rifle" }, "a gun", "This is a killing tool ...");
                    Item Shovel = new Item(new String[] { "shovel", "spade" }, "a shovel", "This is a might fine ...");

                    GamePlayer.Inventory.Put(Gun);
                    GamePlayer.Inventory.Put(Shovel);

                    Bag PlayerBag = new Bag(new string[] { "Bag" }, "A Bag", "Game Player's Bag ...");

                    GamePlayer.Inventory.Put(PlayerBag);

                    Item Gem = new Item(new string[] { "gem", "shiny" }, "Gem", "A Shiny Gem ...");
                    PlayerBag.Inventory.Put(Gem);

                    Location NorthLocation = new Location("Hallway", "This is a long well lit hallway");
                    Location SouthLocation = new Location("Small Closet", "A small dark closet, with an odd smell");
                    Location EastLocation = new Location("Small Garden", "There are many small shrubs and flowers growing from well tended garden beds.");
                    Location WestLocation = new Location("University", "This is a place were you spend your money and time for nothing in return.");
                    
                    Path path = new Path();
                    NorthLocation.Path = path;
                    path.SetLocation("north", NorthLocation);
                    path.SetLocation("south", SouthLocation);
                    path.SetLocation("east", EastLocation);
                    path.SetLocation("west", WestLocation);

                    GamePlayer.Location = NorthLocation;
                }

                if (buttonClicks > 1)
                {
                    label.Text += inputText + "\n";
                    String[] Command = inputText.Split(' ');
                    label.Text += MainCommandProcessor.Execute(GamePlayer, Command) + "\nEnter Command: ";
                }
                inputText = "";
                input.Text = "";
                buttonClicks += 1;
            };

            ContentData.PackStart(scrollview);
            ContentData.PackStart(input);
            ContentData.PackStart(button);

            mainWindow.Content = ContentData;

            mainWindow.Show();
            Application.Run();
            mainWindow.Dispose();
        }
    }
}
