//
// Τΰιλ Piece.hpp
//
#pragma once

namespace chess
{

    class Piece
    {
    public:
        enum class Type
        {
            ePawn,
            eKnight,
            eBishop,
            eRook,
            eQueen,
            eKing
        };

        enum class Color
        {
            eWhite,
            eBlack
        };

    private:
        static constexpr auto TAG = "piece";

        Type  m_type{ Type::ePawn };
        Color m_color{ Color::eWhite };
        int   m_row{ 0 };
        int   m_col{ 0 };
        bool  m_hasShield{ false };

    public:
        Piece();
        Piece(Type type, Color color, int row, int col);
        ~Piece();

        [[nodiscard]] Type  GetType()   const;
        [[nodiscard]] Color GetColor()  const;
        [[nodiscard]] int   GetRow()    const;
        [[nodiscard]] int   GetCol()    const;
        [[nodiscard]] bool  HasShield() const;
    };

} // namespace chess