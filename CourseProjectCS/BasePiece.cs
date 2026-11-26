using System;

namespace Chess
{
    public class PieceMetadata
    {
        public string FlavorText { get; set; } = "Базовое описание фигуры";
    }

    public abstract class BasePiece
    {
        private static int _createdCount = 0;
        public static int CreatedCount => _createdCount;

        protected string Name { get; private set; }
        protected string Color { get; private set; }
        protected int Cost { get; private set; }

        public Position Position { get; private set; }
        public PieceMetadata Metadata { get; private set; }

        protected BasePiece(string name, string color, int row, int col, int cost)
        {
            Name = name;
            Color = color;
            Cost = cost;
            Position = new Position { Row = row, Col = col };
            Metadata = new PieceMetadata();
            _createdCount++;
            Console.WriteLine($"[BasePiece] Constructed: {Name}");
        }

        protected BasePiece(BasePiece other)
        {
            Name = other.Name;
            Color = other.Color;
            Cost = other.Cost;
            Position = new Position { Row = other.Position.Row, Col = other.Position.Col };
            Metadata = new PieceMetadata { FlavorText = other.Metadata.FlavorText };

            _createdCount++;
            Console.WriteLine($"[BasePiece] Copy-constructed: {Name}");
        }

        protected string Header() => $"{Name} ({Color}) на [{Position.Row}, {Position.Col}]";

        public abstract string GetMovePattern();

        public virtual string Describe() => $"{Header()} | Ходит: {GetMovePattern()}";

        public abstract BasePiece Clone();

        public void MoveTo(int row, int col)
        {
            Position = new Position { Row = row, Col = col };
        }

        public BasePiece ShallowCopy() => (BasePiece)MemberwiseClone();

        public override bool Equals(object? obj) =>
            obj is BasePiece other && GetType() == other.GetType() && Name == other.Name;

        public override int GetHashCode() => HashCode.Combine(GetType(), Name);
    }
}