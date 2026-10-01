#include "chess_board.hpp"

#include <iostream>

namespace chess
{

    Board::Board()
    {
        for (int r = 0; r < BOARD_ROWS; ++r)
        {
            for (int c = 0; c < BOARD_COLS; ++c)
            {
                m_grid[r][c] = nullptr;
            }
        }
        std::cout << "[" << TAG << "] Создана доска "
            << BOARD_ROWS << "x" << BOARD_COLS << "\n";
    }

    Board::~Board()
    {
        std::cout << "[" << TAG << "] Уничтожена (фигуры живы — агрегация)\n";
    }

    bool Board::IsCellFree(int row, int col) const
    {
        if (row < 0 || row >= BOARD_ROWS || col < 0 || col >= BOARD_COLS)
        {
            return false;
        }
        return m_grid[row][col] == nullptr;
    }

    Piece* Board::GetPieceAt(int row, int col) const
    {
        if (row < 0 || row >= BOARD_ROWS || col < 0 || col >= BOARD_COLS)
        {
            return nullptr;
        }
        return m_grid[row][col];
    }

    bool Board::PlacePiece(Piece* piece, int row, int col)
    {
        if (piece == nullptr)
        {
            std::cout << "[" << TAG << "] Нарушение правила: пустая фигура\n";
            return false;
        }
        if (row < 0 || row >= BOARD_ROWS || col < 0 || col >= BOARD_COLS)
        {
            std::cout << "[" << TAG << "] Нарушение правила: клетка за пределами доски\n";
            return false;
        }
        if (m_grid[row][col] != nullptr)
        {
            std::cout << "[" << TAG << "] Нарушение правила: клетка (" << row << ", " << col
                << ") уже занята\n";
            return false;
        }
        m_grid[row][col] = piece;
        piece->MoveTo(row, col);
        std::cout << "[" << TAG << "] Фигура поставлена на (" << row << ", " << col << ")\n";
        return true;
    }

    Piece* Board::RemovePiece(int row, int col)
    {
        if (row < 0 || row >= BOARD_ROWS || col < 0 || col >= BOARD_COLS)
        {
            return nullptr;
        }
        Piece* piece = m_grid[row][col];
        m_grid[row][col] = nullptr;
        return piece;
    }

    void Board::Print() const
    {
        std::cout << "   ";
        for (int c = 0; c < BOARD_COLS; ++c)
        {
            std::cout << static_cast<char>('a' + c) << " ";
        }
        std::cout << "\n";

        for (int r = BOARD_ROWS - 1; r >= 0; --r)
        {
            int label = r + 1;
            std::cout << label << (label < 10 ? "  " : " ");
            for (int c = 0; c < BOARD_COLS; ++c)
            {
                std::cout << (m_grid[r][c] != nullptr ? "Ф " : ". ");
            }
            std::cout << "\n";
        }
    }

} // namespace chess