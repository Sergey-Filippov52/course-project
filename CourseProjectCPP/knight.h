#pragma once
#include "BasePiece.hpp"

namespace chess {

    class Knight : public BasePiece {
    public:
        Knight(std::string_view color, int row, int col);
        ~Knight() override;

        std::string GetMovePattern() const override;
        std::string Describe() const override;
        std::unique_ptr<BasePiece> Clone() const override;
    };

}