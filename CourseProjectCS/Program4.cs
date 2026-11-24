using System;
using System.Collections.Generic;

namespace Chess
{
    using PieceList = System.Collections.Generic.List<BasePiece>;

    internal class Program
    {
        static void Main(string[] args)
        {
            Console.OutputEncoding = System.Text.Encoding.UTF8;

            Console.WriteLine("========== 1. Создание фигур ==========");
            PieceList pieces = new PieceList
            {
                new Pawn("White", 1, 0),
                new Knight("Black", 7, 1)
            };

            Console.WriteLine("\n========== 2. Наследование и виртуальные методы ==========");
            foreach (var piece in pieces)
            {
                Console.WriteLine(piece.Describe());
            }

            Console.WriteLine("\n========== 3. Поверхностная и глубокая копия ==========");
            var original = new Pawn("White", 2, 2);

            var shallow = (Pawn)original.ShallowCopy();
            var deep = (Pawn)original.Clone();

            shallow.Position.Row = 99;
            Console.WriteLine($"Оригинал после изменения поверхностной копии: {original.Position.Row}");

            deep.Position.Row = 55;
            Console.WriteLine($"Оригинал после изменения глубокой копии: {original.Position.Row}");

            Console.WriteLine("\n========== 4. Equals и HashSet ==========");
            var p1 = new Pawn("White", 1, 0);
            var p2 = new Pawn("White", 5, 5);
            var k1 = new Knight("White", 1, 0);

            Console.WriteLine($"p1 равен p2? {p1.Equals(p2)}");
            Console.WriteLine($"p1 равен k1? {p1.Equals(k1)}");

            var unique = new HashSet<BasePiece> { p1, p2, k1 };
            Console.WriteLine($"Уникальных фигур в HashSet: {unique.Count}");

            Console.WriteLine("\n========== 5. using static и using var ==========");
            using static System.Math;
            Console.WriteLine($"Максимум из 10 и 20: {Max(10, 20)}");

            using var stream = new System.IO.MemoryStream();
            Console.WriteLine("Поток создан и будет закрыт автоматически");

            Console.WriteLine($"\nВсего создано фигур: {BasePiece.CreatedCount}");
        }
    }
}