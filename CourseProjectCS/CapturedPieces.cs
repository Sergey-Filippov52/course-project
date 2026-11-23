using System.Runtime.CompilerServices;

namespace Chess;

public static class CapturedPieces
{
    [MethodImpl(MethodImplOptions.NoInlining)]
    public static WeakReference<Piece> CaptureTemporary()
    {
        var captured = new Piece(Piece.PieceType.Queen, Piece.PieceColor.Black, 0, 3);
        return new WeakReference<Piece>(captured);
    }
}