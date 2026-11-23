#pragma once
#include "BasePiece.hpp"

namespace chess {

    class Pawn final : public BasePiece {
    public:
        Pawn(std::string_view color, int row, int col);
        ~Pawn() override;

        std::string GetMovePattern() const override;
        std::string Describe() const override;
        std::unique_ptr<BasePiece> Clone() const override;
    };

}