namespace Chess;

public sealed class GameLog : IDisposable
{
    private readonly string _matchName;

    public GameLog(string matchName)
    {
        _matchName = matchName;
        Console.WriteLine($"[game-log] Запись партии «{_matchName}» открыта");
    }

    public void Write(string line)
        => Console.WriteLine($"    Ход: {line}");

    public void Dispose()
        => Console.WriteLine($"[-] Запись партии «{_matchName}» закрыта");
}