//
// Файл BasePiece.cpp
//

#include "BasePiece.hpp"

namespace chess {

    BasePiece::BasePiece(std::string_view name, std::string_view color, int row, int col, int cost)
        : m_id(++s_createdCount),
        m_position(std::make_shared<Position>(Position{ row, col })),
        m_name(name),
        m_color(color),
        m_hasShield(false),
        m_cost(cost)
    {
        std::cout << "[BasePiece] Constructed: " << m_name << "\n";
    }

    BasePiece::BasePiece() : BasePiece("Empty", "None", 0, 0, 0) {}

    BasePiece::~BasePiece() {
        std::cout << "[BasePiece] Destroyed: " << m_name << "\n";
    }

    BasePiece::BasePiece(const BasePiece& other)
        : m_id(++s_createdCount),
        m_name(other.m_name),
        m_color(other.m_color),
        m_hasShield(other.m_hasShield),
        m_cost(other.m_cost)
    {
        m_position = std::make_shared<Position>(*other.m_position);
        std::cout << "[BasePiece] Copy-constructed: " << m_name << "\n";
    }

    BasePiece::BasePiece(BasePiece&& other) noexcept
        : m_id(++s_createdCount),
        m_position(std::move(other.m_position)),
        m_name(std::move(other.m_name)),
        m_color(std::move(other.m_color)),
        m_hasShield(other.m_hasShield),
        m_cost(other.m_cost)
    {
        std::cout << "[BasePiece] Move-constructed\n";
    }

    BasePiece& BasePiece::operator=(const BasePiece& other) {
        if (this == &other) {
            return *this;
        }
        m_name = other.m_name;
        m_color = other.m_color;
        m_hasShield = other.m_hasShield;
        m_cost = other.m_cost;
        m_position = std::make_shared<Position>(*other.m_position);
        return *this;
    }

    BasePiece& BasePiece::operator=(BasePiece&& other) noexcept {
        if (this == &other) return *this;
        m_name = std::move(other.m_name);
        m_color = std::move(other.m_color);
        m_hasShield = other.m_hasShield;
        m_cost = other.m_cost;
        m_position = std::move(other.m_position);
        return *this;
    }

    std::string BasePiece::Header() const {
        return m_name + " (" + m_color + ") на [" + std::to_string(m_position->row) + ", " + std::to_string(m_position->col) + "]";
    }

    std::string BasePiece::Describe() const {
        return Header() + " | Ходит: " + GetMovePattern();
    }

    void BasePiece::MoveTo(int row, int col) {
        m_position->row = row;
        m_position->col = col;
    }

    void BasePiece::Print() const {
        std::cout << "Фигура(тип=" << m_name
            << ", цвет=" << (m_color == "White" ? "белый" : "чёрный")
            << ", строка=" << m_position->row << ", столбец=" << m_position->col
            << ", стоимость=" << m_cost
            << ", щит=" << (m_hasShield ? "есть" : "нет") << ")\n";
    }

} // namespace chess