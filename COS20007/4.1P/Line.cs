﻿using System;
using SwinGameSDK;

namespace MyGame
{
    public class Line : Shape
    {
        private float _endX, _endY;

        public Line (Color c, float startX, float startY, float endX, float endY)
        {
            //
        }

        public Line ()
        {
            //
        }

        public float EndX
        {
            get
            {
                return _endX;
            }
            set
            {
                _endX = value;
            }
        }

        public float EndY
        {
            get
            {
                return _endY;
            }
            set
            {
                _endY = value;
            }
        }

        public override void Draw ()
        {
            SwinGame.DrawLine (Color, X, Y, _endX, _endY);
            if (base.Selected) {
                DrawOutline ();
            }
        }

        public override void DrawOutline () 
        {
            SwinGame.DrawCircle (Color.Black, X, Y, 2);
        }

        public override Boolean IsAt (Point2D pt)
        {
            return SwinGame.PointOnLine (pt, X, Y, _endX, _endY);
        }
    }
}
