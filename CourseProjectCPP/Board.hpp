//
//  Τΰιλ Board.hpp
//
#pragma once

#include "piece.hpp"

namespace chess
{

    class Board
    {
    private:
        static constexpr auto TAG = "board";
        static constexpr int BOARD_ROWS = 8;
        static constexpr int BOARD_COLS = 10;

        Piece* m_grid[BOARD_ROWS][BOARD_COLS];

    public:
        Board();
        ~Board();

        Board(const Board&) = delete;
        Board(Board&&) = delete;
        Board& operator=(const Board&) = delete;
        Board& operator=(Board&&) = delete;

        [[nodiscard]] bool   IsCellFree(int row, int col) const;
        [[nodiscard]] Piece* GetPieceAt(int row, int col) const;

        bool   PlacePiece(Piece* piece, int row, int col);
        Piece* RemovePiece(int row, int col);
        void   Print() const;
    };

} // namespace chess