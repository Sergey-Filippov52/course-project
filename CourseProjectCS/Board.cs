namespace Chess;

public class Board
{
    public const int Rows = 8;
    public const int Cols = 10;

    private readonly Piece?[,] _grid;

    public Board()
    {
        _grid = new Piece?[Rows, Cols];
        Console.WriteLine($"[board] Создана доска {Rows}x{Cols}");
    }

    public bool IsCellFree(int row, int col)
    {
        if (!InBounds(row, col)) return false;
        return _grid[row, col] is null;
    }

    public Piece? GetPieceAt(int row, int col)
        => InBounds(row, col) ? _grid[row, col] : null;

    public bool PlacePiece(Piece? piece, int row, int col)
    {
        if (piece is null)
        {
            Console.WriteLine("[board] Нарушение правила: пустая фигура");
            return false;
        }
        if (!InBounds(row, col))
        {
            Console.WriteLine("[board] Нарушение правила: клетка за пределами доски");
            return false;
        }
        if (_grid[row, col] is not null)
        {
            Console.WriteLine($"[board] Нарушение правила: клетка ({row}, {col}) уже занята");
            return false;
        }
        _grid[row, col] = piece;
        piece.MoveTo(row, col);
        Console.WriteLine($"[board] Фигура поставлена на ({row}, {col})");
        return true;
    }

    public Piece? RemovePiece(int row, int col)
    {
        if (!InBounds(row, col)) return null;
        Piece? piece = _grid[row, col];
        _grid[row, col] = null;
        return piece;
    }

    public override string ToString()
    {
        var sb = new System.Text.StringBuilder();
        sb.Append("   ");
        for (int c = 0; c < Cols; c++)
            sb.Append((char)('a' + c)).Append(' ');
        sb.AppendLine();

        for (int r = Rows - 1; r >= 0; r--)
        {
            sb.Append(r + 1).Append(r < 9 ? "  " : " ");
            for (int c = 0; c < Cols; c++)
                sb.Append(_grid[r, c] is not null ? "Ф " : ". ");
            sb.AppendLine();
        }
        return sb.ToString();
    }

    private static bool InBounds(int row, int col)
        => row >= 0 && row < Rows && col >= 0 && col < Cols;
}