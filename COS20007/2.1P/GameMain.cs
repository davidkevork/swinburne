using System;
using SwinGameSDK;

namespace MyGame
{
    public class GameMain
    {
        public static void Main()
        {
            Shape myShape = new Shape();
 
            //Open the game window
            SwinGame.OpenGraphicsWindow("GameMain", 800, 600);
            SwinGame.ShowSwinGameSplashScreen();
            
            //Run the game loop
            while(SwinGame.WindowCloseRequested() == false)
            {
                //Fetch the next batch of UI interaction
                SwinGame.ProcessEvents();
                
                //Clear the screen and draw the framerate
                SwinGame.ClearScreen(Color.White);
                myShape.Draw();
                if (SwinGame.MouseClicked(MouseButton.LeftButton)) {
                    myShape.X = SwinGame.MouseX();
                    myShape.Y = SwinGame.MouseY();
                }
                if (myShape.isAt(SwinGame.MousePosition()) && SwinGame.KeyTyped(KeyCode.vk_SPACE)) {
                    myShape.Color = SwinGame.RandomRGBColor(255);
                }
                SwinGame.DrawFramerate(0,0);
               

                //Draw onto the screen
                SwinGame.RefreshScreen(60);
            }
        }
    }
}