using System;
using SwinGameSDK;

namespace MyGame
{
    public class GameMain
    {
        private enum ShapeKind
        {
            Rectangle,
            Circle,
            Line
        }

        public static void Main ()
        {
            Shape.RegisterShape ("Rectangle", typeof (Rectangle));
            Shape.RegisterShape ("Circle", typeof (Circle));
            Shape.RegisterShape ("Line", typeof (Line));


            Drawing myDrawing = new Drawing ();
            ShapeKind KindToAdd = ShapeKind.Circle;

            //Open the game window
            SwinGame.OpenGraphicsWindow ("GameMain", 800, 600);
            SwinGame.ShowSwinGameSplashScreen ();
            
            //Run the game loop
            while(SwinGame.WindowCloseRequested () == false)
            {
                //Fetch the next batch of UI interaction
                SwinGame.ProcessEvents ();
                
                //Clear the screen and myDrawing the framerate
                SwinGame.ClearScreen (Color.White);

                if (SwinGame.KeyTyped (KeyCode.vk_r))
                {
                    KindToAdd = ShapeKind.Rectangle;
                }
                else if (SwinGame.KeyTyped (KeyCode.vk_c))
                {
                    KindToAdd = ShapeKind.Circle;
                }
                else if (SwinGame.KeyTyped (KeyCode.vk_l))
                {
                    KindToAdd = ShapeKind.Line;
                }

                if (SwinGame.MouseClicked (MouseButton.LeftButton))
                {
                    Shape newShape;

                    switch (KindToAdd)
                    {
                        case ShapeKind.Circle:
                            newShape = new Circle ();
                            break;
                        case ShapeKind.Rectangle:
                            newShape = new Rectangle ();
                            break;
                        case ShapeKind.Line:
                            newShape = new Line ();
                            break;
                        default:
                            newShape = new Rectangle ();
                            break;
                    }

                    newShape.X = SwinGame.MouseX ();
                    newShape.Y = SwinGame.MouseY ();
                    myDrawing.AddShape (newShape);
                }
                if (SwinGame.MouseClicked (MouseButton.RightButton)) {
                    myDrawing.SelectShapesAt (SwinGame.MousePosition ());
                }
                if (SwinGame.KeyTyped (KeyCode.vk_DELETE) || SwinGame.KeyTyped (KeyCode.vk_BACKSPACE)) {
                    foreach (Shape shape in myDrawing.SelectedShapes) {
                        myDrawing.RemoveShape (shape);
                    }
                }
                if (SwinGame.KeyTyped (KeyCode.vk_SPACE)) {
                    myDrawing.Background = SwinGame.RandomRGBColor (255);
                }
                if (SwinGame.KeyTyped (KeyCode.vk_s)) {
                    myDrawing.Save ("./drawing.txt");
                }
                if (SwinGame.KeyTyped (KeyCode.vk_o)) {
                    try {
                        myDrawing.Load ("./drawing.txt");
                    } catch (Exception e) {
                        Console.Error.WriteLine ("Error loading file: {0}", e.Message);
                    }

                }
                myDrawing.Draw ();
                SwinGame.DrawFramerate (0,0);

                //myDrawing onto the screen
                SwinGame.RefreshScreen (60);
            }
    }
}
}