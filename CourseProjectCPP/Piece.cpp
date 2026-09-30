//
// Файл Piece.cpp
//

#include "piece.hpp"

#include <iostream>

namespace chess
{

    Piece::Piece()
        : Piece(Type::ePawn, Color::eWhite, 0, 0)
    {
    }

    Piece::Piece(Type type, Color color, int row, int col)
        : m_type{ type }
        , m_color{ color }
        , m_row{ row }
        , m_col{ col }
        , m_hasShield{ false }
    {
        std::cout << "[" << TAG << "] Создана на клетке (" << row << ", " << col << ")\n";
    }

    Piece::~Piece()
    {
        std::cout << "[" << TAG << "] Уничтожена на клетке (" << m_row << ", " << m_col << ")\n";
    }

    Piece::Type  Piece::GetType()   const { return m_type; }
    Piece::Color Piece::GetColor()  const { return m_color; }
    int          Piece::GetRow()    const { return m_row; }
    int          Piece::GetCol()    const { return m_col; }
    bool         Piece::HasShield() const { return m_hasShield; }

} // namespace chess