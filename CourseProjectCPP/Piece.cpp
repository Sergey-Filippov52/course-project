//
// Файл piece.cpp
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

    int Piece::GetCost() const
    {
        switch (m_type)
        {
        case Type::ePawn:   return 1;
        case Type::eKnight: return 3;
        case Type::eBishop: return 3;
        case Type::eRook:   return 5;
        case Type::eQueen:  return 9;
        case Type::eKing:   return 0;
        }
        return 0;
    }

    const char* Piece::GetTypeName() const
    {
        switch (m_type)
        {
        case Type::ePawn:   return "пешка";
        case Type::eKnight: return "конь";
        case Type::eBishop: return "слон";
        case Type::eRook:   return "ладья";
        case Type::eQueen:  return "ферзь";
        case Type::eKing:   return "король";
        }
        return "неизвестно";
    }

    bool Piece::IsAt(int row, int col) const
    {
        return m_row == row && m_col == col;
    }

    bool Piece::ApplyShield()
    {
        if (m_type == Type::eKing)
        {
            std::cout << "[" << TAG << "] Нарушение правила: на короля нельзя наложить щит\n";
            return false;
        }
        if (m_hasShield)
        {
            std::cout << "[" << TAG << "] Нарушение правила: щит уже наложен\n";
            return false;
        }
        m_hasShield = true;
        std::cout << "[" << TAG << "] Щит наложен\n";
        return true;
    }

    bool Piece::BreakShield()
    {
        if (!m_hasShield)
        {
            return false;
        }
        m_hasShield = false;
        std::cout << "[" << TAG << "] Щит сломан\n";
        return true;
    }

    void Piece::MoveTo(int row, int col)
    {
        m_row = row;
        m_col = col;
    }

    void Piece::Print() const
    {
        std::cout << "Фигура(тип=" << GetTypeName()
            << ", цвет=" << (m_color == Color::eWhite ? "белый" : "чёрный")
            << ", строка=" << m_row << ", столбец=" << m_col
            << ", стоимость=" << GetCost()
            << ", щит=" << (m_hasShield ? "есть" : "нет") << ")\n";
    }

} // namespace chess