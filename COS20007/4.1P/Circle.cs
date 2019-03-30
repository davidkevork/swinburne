﻿using System;
using SwinGameSDK;

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
            SwinGame.DrawCircle (Color.Black, X - 2, Y - 2, _radius + 2);
        }

        public override Boolean IsAt (Point2D pt)
        {
            return SwinGame.PointInCircle (pt, X, Y, _radius);
        }
    }
}
