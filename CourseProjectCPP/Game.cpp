#include "game.hpp"

#include <iostream>

namespace chess
{

    Game::Game()
    {
        std::cout << "[" << TAG << "] Создана. Ход игрока=" << m_currentPlayer
            << ", волшебников=" << m_wizardCount << "\n";
    }

    Game::~Game()
    {
        std::cout << "[" << TAG << "] Уничтожена (доска уходит вместе с ней — композиция)\n";
    }

    Board& Game::GetBoard() { return m_board; }
    const Board& Game::GetBoard() const { return m_board; }
    int          Game::GetWizardCount() const { return m_wizardCount; }

    void Game::Start()
    {
        std::cout << "[" << TAG << "] Старт. Волшебники занимают 5-ю и 6-ю горизонтали\n";
    }

    bool Game::MakeMove(Piece* piece, int row, int col)
    {
        if (piece == nullptr)
        {
            std::cout << "[" << TAG << "] Нарушение правила: фигура не выбрана\n";
            return false;
        }
        if (!m_board.PlacePiece(piece, row, col))
        {
            return false;
        }
        std::cout << "[" << TAG << "] Ход сделан игроком " << m_currentPlayer << "\n";
        m_currentPlayer = (m_currentPlayer == 1) ? 2 : 1;
        return true;
    }

    void Game::SpawnWizards()
    {
        m_wizardCount += 2;
        std::cout << "[" << TAG << "] Волшебники усилены. Всего волшебников: "
            << m_wizardCount << "\n";
    }

    bool Game::CheckVictory() const
    {
        if (m_wizardCount > 0)
        {
            std::cout << "[" << TAG << "] Волшебники ещё живы — победу объявить нельзя\n";
            return false;
        }
        std::cout << "[" << TAG << "] Волшебники побеждены\n";
        return true;
    }

} // namespace chess