using System;

namespace Chess
{
    public sealed class Pawn : BasePiece
    {
        public Pawn(string color, int row, int col) : base("ѕешка", color, row, col, 1)
        {
            Console.WriteLine("[Pawn] Constructed");
        }

        public Pawn(Pawn other) : base(other)
        {
            Console.WriteLine("[Pawn] Copy-constructed");
        }

        public override string GetMovePattern()
        {
            return "на 1 клетку вперед (или на 2 с начальной позиции)";
        }

        public override string Describe()
        {
            return base.Describe() + " | ќсобенность: превращаетс€ на последней линии";
        }

        public override BasePiece Clone()
        {
            return new Pawn(this);
        }
    }
}