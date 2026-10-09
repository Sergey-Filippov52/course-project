namespace Chess;

public class Game
{
    private readonly Board _board;
    private int _currentPlayer;
    private int _wizardCount;

    public int CurrentPlayer => _currentPlayer;
    public int WizardCount => _wizardCount;

    public Game()
    {
        _board = new Board();
        _currentPlayer = 1;
        _wizardCount = 2;
        Console.WriteLine($"[game] Создана. Ход игрока={_currentPlayer}, волшебников={_wizardCount}");
    }

    public void Start()
        => Console.WriteLine("[game] Старт. Волшебники занимают 5-ю и 6-ю горизонтали");

    public bool PlacePiece(Piece? piece, int row, int col)
        => _board.PlacePiece(piece, row, col);

    public Piece? RemovePiece(int row, int col)
        => _board.RemovePiece(row, col);

    public void PrintBoard()
        => Console.Write(_board.ToString());

    public bool MakeMove(Piece? piece, int row, int col)
    {
        if (piece is null)
        {
            Console.WriteLine("[game] Нарушение правила: фигура не выбрана");
            return false;
        }
        if (!_board.PlacePiece(piece, row, col)) return false;

        Console.WriteLine($"[game] Ход сделан игроком {_currentPlayer}");
        _currentPlayer = _currentPlayer == 1 ? 2 : 1;
        return true;
    }

    public void SpawnWizards()
    {
        _wizardCount += 2;
        Console.WriteLine($"[game] Волшебники усилены. Всего волшебников: {_wizardCount}");
    }

    public bool CheckVictory()
    {
        if (_wizardCount > 0)
        {
            Console.WriteLine("[game] Волшебники ещё живы — победу объявить нельзя");
            return false;
        }
        Console.WriteLine("[game] Волшебники побеждены — мат разрешён");
        return true;
    }

    public override string ToString()
        => $"Партия: ход игрока {_currentPlayer}, волшебников {_wizardCount}";
}