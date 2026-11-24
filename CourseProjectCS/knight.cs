using System;

namespace Chess
{
    public class Knight : BasePiece
    {
        public Knight(string color, int row, int col) : base("Конь", color, row, col, 3)
        {
            Console.WriteLine("[Knight] Constructed");
        }

        public Knight(Knight other) : base(other)
        {
            Console.WriteLine("[Knight] Copy-constructed");
        }

        public override string GetMovePattern()
        {
            return "буквой Г (2 + 1)";
        }

        public override string Describe()
        {
            return $"Могучий {this.Name} цвета {this.Color}";
        }

        public override BasePiece Clone()
        {
            return new Knight(this);
        }
    }
}