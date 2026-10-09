using Chess;

Console.OutputEncoding = System.Text.Encoding.UTF8;

// === 1. Ссылки и копии: класс ===
Console.WriteLine("=== 1. Ссылки и копии (класс Piece) ===");
Piece first = new Piece(Piece.PieceType.Pawn, Piece.PieceColor.White, 1, 4);
Piece second = first;                     // копируется ссылка, а не объект
second.MoveTo(3, 4);
Console.WriteLine($"first  = {first}");
Console.WriteLine($"second = {second}");
Console.WriteLine($"Это один и тот же объект: {ReferenceEquals(first, second)}");

// === 2. Структура копируется по значению ===
Console.WriteLine("\n=== 2. Структура копируется по значению (struct Position) ===");
Position from = new Position(1, 4);
Position to = from;
to.Row = 3;
Console.WriteLine($"from = {from}");
Console.WriteLine($"to   = {to}");
Console.WriteLine("Изменение to не повлияло на from");

// === 3. Композиция и агрегация ===
Console.WriteLine("\n=== 3. Композиция и агрегация ===");
Piece knight = new Piece(Piece.PieceType.Knight, Piece.PieceColor.White, 0, 1);

{
    Game game = new Game();               // композиция: Board создан внутри Game
    game.Start();

    game.PlacePiece(knight, 2, 2);        // агрегация: knight создан снаружи
    game.PlacePiece(knight, 2, 2);        // правило: клетка занята

    Piece king = new Piece(Piece.PieceType.King, Piece.PieceColor.White, 0, 4);
    king.ApplyShield();                   // правило: на короля щит нельзя
    game.PlacePiece(king, 2, 2);          // правило: клетка занята

    Console.WriteLine("\n--- Состояние доски ---");
    game.PrintBoard();

    Console.WriteLine("\n--- Состояние партии ---");
    Console.WriteLine(game);

    Console.WriteLine("\n--- Проверка победы ---");
    game.CheckVictory();
}

Console.WriteLine($"\nknight жив после выхода из блока: {knight}");

// === 4. IDisposable + using ===
Console.WriteLine("\n=== 4. Освобождение ресурса через using ===");
using (GameLog log = new GameLog("Партия №1"))
{
    log.Write("e2-e4");
    log.Write("e7-e5");
    log.Write("g1-f3");
}

// === 5. Сборщик мусора ===
Console.WriteLine("\n=== 5. Сборщик мусора ===");
WeakReference<Piece> captured = CapturedPieces.CaptureTemporary();
Console.WriteLine($"Взятая фигура жива до сборки мусора: {captured.TryGetTarget(out _)}");

GC.Collect();
GC.WaitForPendingFinalizers();

Console.WriteLine($"Взятая фигура жива после сборки: {captured.TryGetTarget(out _)}");