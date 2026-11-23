#pragma once

#include "chess_board.hpp"
#include <memory>

namespace chess
{

    class Game
    {
    private:
        static constexpr auto TAG = "game";

        Board m_board;
        int   m_currentPlayer{ 1 };
        int   m_wizardCount{ 2 };

    public:
        Game();
        ~Game();

        Game(const Game&) = delete;
        Game(Game&&) = delete;
        Game& operator=(const Game&) = delete;
        Game& operator=(Game&&) = delete;

        [[nodiscard]] Board& GetBoard();
        [[nodiscard]] const Board& GetBoard() const;
        [[nodiscard]] int          GetWizardCount() const;

        void Start();
        bool MakeMove(std::unique_ptr<Piece> piece, int row, int col);
        void SpawnWizards();
        bool CheckVictory() const;
    };

} // namespace chess