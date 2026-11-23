#include "Knight.hpp"

namespace chess {

    Knight::Knight(std::string_view color, int row, int col)
        : BasePiece("Конь", color, row, col, 3) {
        std::cout << "[Knight] Constructed\n";
    }

    Knight::~Knight() {
        std::cout << "[Knight] Destroyed\n";
    }

    std::string Knight::GetMovePattern() const {
        return "буквой Г (2 + 1)";
    }

    std::string Knight::Describe() const {
        return "Могучий " + m_name + " цвета " + m_color;
    }

    std::unique_ptr<BasePiece> Knight::Clone() const {
        return std::make_unique<Knight>(*this);
    }

}