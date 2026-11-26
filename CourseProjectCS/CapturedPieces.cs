using System.Runtime.CompilerServices;

namespace Chess;

public static class CapturedPieces
{
    [MethodImpl(MethodImplOptions.NoInlining)]
    public static WeakReference<BasePiece> CaptureTemporary()
    {
        BasePiece captured = new Knight("Black", 0, 3);
        return new WeakReference<BasePiece>(captured);
    }
}