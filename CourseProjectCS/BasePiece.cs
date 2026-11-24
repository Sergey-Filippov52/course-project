using System;

namespace Chess
{
    public abstract class BasePiece
    {
        private static int _createdCount = 0;
        public static int CreatedCount => _createdCount;

        protected string Name { get; private set; }
        protected string Color { get; private set; }
        protected int Cost { get; private set; }

        public Position Position { get; private set; }

        protected BasePiece(string name, string color, int row, int col, int cost)
        {
            Name = name;
            Color = color;
            Cost = cost;
            Position = new Position { Row = row, Col = col };
            _createdCount++;
            Console.WriteLine($"[BasePiece] Constructed: {Name}");
        }

        protected BasePiece(BasePiece other)
        {
            Name = other.Name;
            Color = other.Color;
            Cost = other.Cost;
            Position = new Position { Row = other.Position.Row, Col = other.Position.Col };
            _createdCount++;
            Console.WriteLine($"[BasePiece] Copy-constructed: {Name}");
        }

        protected string Header() => $"{Name} ({Color}) на [{Position.Row}, {Position.Col}]";

        public abstract string GetMovePattern();

        public virtual string Describe() => $"{Header()} | ’одит: {GetMovePattern()}";

        public abstract BasePiece Clone();

        public void MoveTo(int row, int col)
        {
            Position.Row = row;
            Position.Col = col;
        }

        public BasePiece ShallowCopy() => (BasePiece)MemberwiseClone();

        public override bool Equals(object? obj) =>
            obj is BasePiece other && GetType() == other.GetType() && Name == other.Name;

        public override int GetHashCode() => HashCode.Combine(GetType(), Name);
    }
}