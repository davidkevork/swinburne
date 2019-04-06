using System;
using SwinGameSDK;
using System.Collections.Generic;
using System.IO;

namespace MyGame
{
    public class Drawing
    {
        private readonly List<Shape> _shapes;
        private Color _background;

        public Drawing (Color background)
        {
            _shapes = new List<Shape> ();
            _background = background;
        }

        public Drawing () : this (Color.White) { }

        public List<Shape> SelectedShapes
        {
            get
            {
                List<Shape> result = new List<Shape> ();
                foreach (Shape shape in _shapes)
                {
                    if (shape.Selected) {
                        result.Add (shape);
                    }
                }
                return result;
            }
        }

        public int ShapeCount
        {
            get
            {
                return _shapes.Count;
            }
        }

        public Color Background
        {
            get
            {
                return _background;
            }
            set
            {
                _background = value;
            }
        }

        public void Draw ()
        {
            SwinGame.ClearScreen (_background);
            foreach (Shape shape in _shapes)
            {
                shape.Draw ();
            }
        }

        public void SelectShapesAt (Point2D pt)
        {
            foreach (Shape shape in _shapes) {
                shape.Selected = shape.IsAt (pt) ? true : false;
            }
        }

        public void AddShape (Shape s)
        {
            _shapes.Add (s);
        }

        public void RemoveShape (Shape s)
        {
            _shapes.Remove (s);
        }

        public void Save (string filename)
        {
            StreamWriter writer = new StreamWriter (filename);

            writer.WriteLine (Background.ToArgb ());
            writer.WriteLine (ShapeCount);

            try {
                foreach (Shape shape in _shapes) {
                    shape.SaveTo (writer);
                }
            } finally {
                writer.Close ();
            }
        }

        public void Load (string filename)
        {
            StreamReader reader = new StreamReader (filename;
            int count;
            Shape shape;
            string kind = null;

            Background = Color.FromArgb (reader.ReadInteger ());
            count = reader.ReadInteger ();

            try {
                for (int i = 0; i < count; i++)
                {
                    kind = reader.ReadLine ();
                    switch (kind)
                    {
                        case "Rectangle":
                            shape = new Rectangle();
                            break;
                        case "Circle":
                            shape = new Circle();
                            break;
                        default:
                            throw new InvalidDataException ("Unkown shape kind: " + kind);
                     }

                    shape.LoadFrom (reader);
                    AddShape (shape);
                }
            } finally {
                reader.Close ();
            }
        }
    }
}
