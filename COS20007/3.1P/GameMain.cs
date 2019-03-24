using System;
using SwinGameSDK;

namespace MyGame
{
    public class GameMain
    {
        public static void Main ()
        {
            Drawing draw = new Drawing ();

            //Open the game window
            SwinGame.OpenGraphicsWindow ("GameMain", 800, 600);
            SwinGame.ShowSwinGameSplashScreen ();
            
            //Run the game loop
            while(SwinGame.WindowCloseRequested () == false)
            {
                //Fetch the next batch of UI interaction
                SwinGame.ProcessEvents ();
                
                //Clear the screen and draw the framerate
                SwinGame.ClearScreen (Color.White);
                if (SwinGame.MouseClicked (MouseButton.LeftButton)) {
                    Shape shape = new Shape ();
                    shape.X = SwinGame.MouseX ();
                    shape.Y = SwinGame.MouseY ();
                    draw.AddShape (shape);
                }
                if (SwinGame.MouseClicked (MouseButton.RightButton)) {
                    draw.SelectShapesAt (SwinGame.MousePosition ());
                }
                if (SwinGame.KeyTyped (KeyCode.vk_DELETE) || SwinGame.KeyTyped (KeyCode.vk_BACKSPACE)) {
                    foreach (Shape shape in draw.SelectedShapes) {
                        draw.RemoveShape (shape);
                    }
                }
                if (SwinGame.KeyTyped (KeyCode.vk_SPACE)) {
                    draw.Background = SwinGame.RandomRGBColor (255);
                }
                SwinGame.DrawFramerate (0,0);

                //Draw onto the screen
                SwinGame.RefreshScreen (60);
            }
    }
}
}