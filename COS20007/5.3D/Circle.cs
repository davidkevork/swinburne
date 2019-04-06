using System;
using SwinGameSDK;
using System.IO;

namespace MyGame
{
    public class Circle : Shape
    {
        private int _radius;

        public Circle (Color c, int radius) : base(c)
        {
            _radius = radius;
        }

        public Circle () : this (Color.Blue, 50) { }

        public int Radius
        {
            get
            {
                return _radius;
            }
            set
            {
                _radius = value;
            }
        }

        public override void Draw ()
        {
            SwinGame.FillCircle (Color, X, Y, _radius);
            if (Selected)
            {
                DrawOutline ();
            }
        }

        public override void DrawOutline ()
        {
            SwinGame.DrawCircle (Color.Black, X, Y, _radius + 2);
        }

        public override Boolean IsAt (Point2D pt)
        {
            return SwinGame.PointInCircle (pt, X, Y, _radius);
        }

        public override void SaveTo (StreamWriter writer)
        {
            base.SaveTo (writer);
            writer.WriteLine (Radius);
        }

        public override void LoadFrom (StreamReader reader)
        {
            base.LoadFrom (reader);
            Radius = reader.ReadInteger ();
        }
    }
}
