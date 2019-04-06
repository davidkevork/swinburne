using System;
using SwinGameSDK;
using System.IO;

namespace MyGame
{
    public class Rectangle : Shape
    {
        private int _width, _height;

        public Rectangle (Color c, float x, float y, int width, int height) : base(c)
        {
            X = x;
            Y = y;
            _width = width;
            _height = height;
        }

        public Rectangle () : this (Color.Green, 0, 0, 100, 100) { }

        public int Width
        {
            get
            {
                return _width;
            }
            set {
                _width = value;
            }
        }

        public int Height
        {
            get
            {
                return _height;
            }
            set {
                _height = value;
            }
        }

        public override void Draw ()
        {
            SwinGame.FillRectangle (Color, X, Y, _width, _height);
            if (base.Selected)
            {
                DrawOutline ();
            }
        }

        public override void DrawOutline ()
        {
            SwinGame.DrawRectangle (Color.Black, X - 2, Y - 2, _width + 4, _height + 4);
        }

        public override Boolean IsAt (Point2D pt)
        {
            return SwinGame.PointInRect (pt, X, Y, _width, _height);
        }

        public override void SaveTo (StreamWriter writer)
        {
            writer.WriteLine ("Rectangle");
            base.SaveTo (writer);
            writer.WriteLine (Width);
            writer.WriteLine (Height);
        }

        public override void LoadFrom (StreamReader reader)
        {
            base.LoadFrom (reader);
            Width = reader.ReadInteger ();
            Height = reader.ReadInteger ();
        }
    }
}
    