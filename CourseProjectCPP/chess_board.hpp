#pragma once

#include "BasePiece.hpp"
#include <memory>

namespace chess
{

    class Board
    {
    private:
        static constexpr auto TAG = "board";
        static constexpr int BOARD_ROWS = 8;
        static constexpr int BOARD_COLS = 10;

        std::unique_ptr<BasePiece> m_grid[BOARD_ROWS][BOARD_COLS];

    public:
        Board();
        ~Board();

        Board(const Board&) = delete;
        Board(Board&&) = delete;
        Board& operator=(const Board&) = delete;
        Board& operator=(Board&&) = delete;

        [[nodiscard]] bool IsCellFree(int row, int col) const;
        [[nodiscard]] BasePiece* GetPieceAt(int row, int col) const;

        bool PlacePiece(std::unique_ptr<BasePiece> piece, int row, int col);
        std::unique_ptr<BasePiece> RemovePiece(int row, int col);
        void Print() const;
    };

}