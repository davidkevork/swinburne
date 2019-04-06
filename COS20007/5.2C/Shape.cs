using System;
using SwinGameSDK;
using System.IO;

namespace MyGame
{
    public abstract class Shape
    {
        private Color _color;
        private float _x, _y;
        private bool _selected;

        public Shape (Color c)
        {
            _color = c;
            _x = 0;
            _y = 0;
        }

        public Shape () : this (Color.Green) { }

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

        public abstract void Draw ();

        public abstract void DrawOutline ();

        public abstract Boolean IsAt (Point2D pt);

        public virtual void SaveTo (StreamWriter writer)
        {
            writer.WriteLine (Color.ToArgb ());
            writer.WriteLine (X);
            writer.WriteLine (Y);
        }

        public virtual void LoadFrom (StreamReader reader)
        {
            Color = Color.FromArgb (reader.ReadInteger ());
            X = reader.ReadInteger ();
            Y = reader.ReadInteger ();
        }
    }
}
