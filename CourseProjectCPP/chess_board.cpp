#include "chess_board.hpp"

#include <iostream>
#include <utility>
namespace chess
{

    Board::Board()
    {
        std::cout << "[" << TAG << "] Создана доска "
            << BOARD_ROWS << "x" << BOARD_COLS << "\n";
    }

    Board::~Board()
    {
        std::cout << "[" << TAG << "] Уничтожена вместе с фигурами\n";
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
        return m_grid[row][col].get();
    }

    bool Board::PlacePiece(std::unique_ptr<Piece> piece, int row, int col)
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
        piece->MoveTo(row, col);
        m_grid[row][col] = std::move(piece);
        std::cout << "[" << TAG << "] Фигура поставлена на (" << row << ", " << col << ")\n";
        return true;
    }

    std::unique_ptr<Piece> Board::RemovePiece(int row, int col)
    {
        if (row < 0 || row >= BOARD_ROWS || col < 0 || col >= BOARD_COLS)
        {
            return nullptr;
        }
        return std::move(m_grid[row][col]);  
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