#include "pawn.hpp"

namespace chess {

    Pawn::Pawn(std::string_view color, int row, int col)
        : BasePiece("Пешка", color, row, col, 1) {
        std::cout << "[Pawn] Constructed\n";
    }

    Pawn::~Pawn() {
        std::cout << "[Pawn] Destroyed\n";
    }

    std::string Pawn::GetMovePattern() const {
        return "на 1 клетку вперед (или на 2 с начальной позиции)";
    }

    std::string Pawn::Describe() const {
        return BasePiece::Describe() + " | Особенность: превращается на последней линии";
    }

    std::unique_ptr<BasePiece> Pawn::Clone() const {
        return std::make_unique<Pawn>(*this);
    }

}