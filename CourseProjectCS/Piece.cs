namespace Chess;

public class Piece
{
    public enum PieceType { Pawn, Knight, Bishop, Rook, Queen, King }
    public enum PieceColor { White, Black }

    private PieceType _type;
    private PieceColor _color;
    private int _row;
    private int _col;
    private bool _hasShield;

    public PieceType Type => _type;
    public PieceColor Color => _color;
    public int Row => _row;
    public int Col => _col;
    public bool HasShield => _hasShield;

    public int Cost => _type switch
    {
        PieceType.Pawn => 1,
        PieceType.Knight or PieceType.Bishop => 3,
        PieceType.Rook => 5,
        PieceType.Queen => 9,
        _ => 0,
    };

    public string TypeName => _type switch
    {
        PieceType.Pawn => "пешка",
        PieceType.Knight => "конь",
        PieceType.Bishop => "слон",
        PieceType.Rook => "ладья",
        PieceType.Queen => "ферзь",
        PieceType.King => "король",
        _ => "неизвестно",
    };

    public Piece(PieceType type, PieceColor color, int row, int col)
    {
        _type = type;
        _color = color;
        _row = row;
        _col = col;
        Console.WriteLine($"[piece] Создана на клетке ({row}, {col})");
    }

    public Piece() : this(PieceType.Pawn, PieceColor.White, 0, 0) { }

    public bool ApplyShield()
    {
        if (_type == PieceType.King)
        {
            Console.WriteLine("[piece] Нарушение правила: на короля нельзя наложить щит");
            return false;
        }
        if (_hasShield)
        {
            Console.WriteLine("[piece] Нарушение правила: щит уже наложен");
            return false;
        }
        _hasShield = true;
        Console.WriteLine("[piece] Щит наложен");
        return true;
    }

    public bool BreakShield()
    {
        if (!_hasShield) return false;
        _hasShield = false;
        Console.WriteLine("[piece] Щит сломан");
        return true;
    }

    public void MoveTo(int row, int col)
    {
        _row = row;
        _col = col;
    }

    public bool IsAt(int row, int col) => _row == row && _col == col;

    public override string ToString()
        => $"Фигура(тип={TypeName}, цвет={(_color == PieceColor.White ? "белый" : "чёрный")}, " +
           $"строка={_row}, столбец={_col}, стоимость={Cost}, " +
           $"щит={(_hasShield ? "есть" : "нет")})";
}