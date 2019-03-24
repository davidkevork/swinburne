﻿using System;
using SwinGameSDK;

namespace MyGame
{
    public class Shape
    {
        private Color _color;
        private float _x, _y;
        private int _width, _height;
        private bool _selected;

        public Shape ()
        {
            _color = Color.Green;
            _x = 0;
            _y = 0;
            _width = 100;
            _height = 100;
        }

        public Color Color
        {
            get
            {
                return _color;
            }
            set
            {
                _color = value;
            }
        }

        public float X
        {
            get
            {
                return _x;
            }
            set
            {
                _x = value;
            }
        }

        public float Y
        {
            get
            {
                return _y;
            }
            set
            {
                _y = value;
            }
        }

        public int Width
        {
            get
            {
                return _width;
            }
            set
            {
                _width = value;
            }
        }

        public int Height
        {
            get
            {
                return _height;
            }
            set
            {
                _height = value;
            }
        }

        public bool Selected
        {
            get
            {
                return _selected;
            }
            set
            {
                _selected = value;
            }
        }

        public void Draw ()
        {
            SwinGame.FillRectangle (_color, _x, _y, _width, _height);
            if (_selected)
            {
                DrawOutline ();
            }
        }

        public Boolean isAt (Point2D pt)
        {
            return SwinGame.PointInRect (pt, _x, _y, _width, _height);
        }

        public void DrawOutline ()
        {
            SwinGame.DrawRectangle (Color.Black, _x - 2, _y - 2, _width + 4, _height + 4);
        }
    }
}
