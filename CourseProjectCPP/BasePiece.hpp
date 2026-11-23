//
// Τΰιλ BasePiece.hpp
//
#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <string_view>

namespace chess {

    struct Position {
        int row;
        int col;
    };

    class BasePiece {
    private:
        inline static int s_createdCount = 0;
        int m_id;
        std::shared_ptr<Position> m_position;

    protected:
        std::string m_name;
        std::string m_color;
        bool m_hasShield;
        int m_cost;

        std::string Header() const;

        BasePiece(const BasePiece& other);
        BasePiece(BasePiece&& other) noexcept;
        BasePiece& operator=(const BasePiece& other);
        BasePiece& operator=(BasePiece&& other) noexcept;

    public:
        BasePiece(std::string_view name, std::string_view color, int row, int col, int cost);

        BasePiece();

        virtual ~BasePiece();

        virtual std::string GetMovePattern() const = 0;
        virtual std::string Describe() const;
        virtual std::unique_ptr<BasePiece> Clone() const = 0;

        void MoveTo(int row, int col);
        void Print() const;

        static int GetCreatedCount() { return s_createdCount; }
        std::string GetName() const { return m_name; }
        int GetCost() const { return m_cost; }
    };

} // namespace chess