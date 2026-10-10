#include "chess_game.hpp"

#include <iostream>
#include <memory>
#include <windows.h>

int main()
{
    SetConsoleOutputCP(65001);

    using namespace chess;

    std::cout << "=== 1. unique_ptr: один владелец ===\n";
    {
        auto pawn = std::make_unique<Piece>(Piece::Type::ePawn, Piece::Color::eWhite, 1, 4);
        pawn->ApplyShield();
        pawn->ApplyShield();
        pawn->Print();
    }
    std::cout << "После блока pawn уничтожен без delete\n";

    std::cout << "\n=== 2. unique_ptr: передача владения ===\n";
    {
        auto knight = std::make_unique<Piece>(Piece::Type::eKnight, Piece::Color::eWhite, 0, 1);
        std::cout << "До move: knight " << (knight ? "владеет" : "пуст") << "\n";

        auto moved = std::move(knight);
        std::cout << "После move: knight " << (knight ? "владеет" : "пуст")
            << ", moved " << (moved ? "владеет" : "пуст") << "\n";
        moved->Print();
    }

    std::cout << "\n=== 3. shared_ptr: несколько владельцев ===\n";
    {
        auto shared = std::make_shared<Piece>(Piece::Type::eQueen, Piece::Color::eBlack, 0, 3);
        std::cout << "use_count = " << shared.use_count() << "\n";

        {
            auto copy = shared;
            std::cout << "use_count = " << shared.use_count() << "\n";
        }

        std::cout << "use_count = " << shared.use_count() << "\n";
    }

    std::cout << "\n=== 4. weak_ptr: наблюдатель ===\n";
    std::weak_ptr<Piece> weak;
    {
        auto owner = std::make_shared<Piece>(Piece::Type::eRook, Piece::Color::eBlack, 0, 0);
        weak = owner;

        if (auto locked = weak.lock())
        {
            std::cout << "Фигура доступна: ";
            locked->Print();
        }
    }

    if (auto locked = weak.lock())
    {
        std::cout << "Фигура доступна: ";
        locked->Print();
    }
    else
    {
        std::cout << "Фигура уничтожена — weak_ptr пуст\n";
    }

    std::cout << "\n=== 5. Доска владеет фигурами через unique_ptr ===\n";
    {
        Game game;
        game.Start();

        auto knight = std::make_unique<Piece>(Piece::Type::eKnight, Piece::Color::eWhite, 0, 1);
        game.GetBoard().PlacePiece(std::move(knight), 2, 2);
        std::cout << "После PlacePiece: knight " << (knight ? "владеет" : "пуст") << "\n";

        auto knight2 = std::make_unique<Piece>(Piece::Type::eKnight, Piece::Color::eWhite, 0, 1);
        game.GetBoard().PlacePiece(std::move(knight2), 2, 2);

        auto king = std::make_unique<Piece>(Piece::Type::eKing, Piece::Color::eWhite, 0, 4);
        king->ApplyShield();
        game.GetBoard().PlacePiece(std::move(king), 3, 3);

        std::cout << "\n--- Состояние доски ---\n";
        game.GetBoard().Print();

        std::cout << "\n--- Проверка победы ---\n";
        game.CheckVictory();
    }

    std::cout << "\n=== 6. Массивы с уникальными владельцами ===\n";
    {
        auto arrayOfPieces = std::make_unique<Piece[]>(3);
        arrayOfPieces[0] = Piece(Piece::Type::ePawn, Piece::Color::eWhite, 6, 0);
        arrayOfPieces[1] = Piece(Piece::Type::ePawn, Piece::Color::eWhite, 6, 1);
        arrayOfPieces[2] = Piece(Piece::Type::ePawn, Piece::Color::eWhite, 6, 2);
        for (int i = 0; i < 3; ++i) arrayOfPieces[i].Print();

        std::unique_ptr<Piece> arrayOfPtrs[3];
        arrayOfPtrs[0] = std::make_unique<Piece>(Piece::Type::eRook, Piece::Color::eBlack, 0, 0);
        arrayOfPtrs[1] = std::make_unique<Piece>(Piece::Type::eRook, Piece::Color::eBlack, 0, 9);
        arrayOfPtrs[2] = std::make_unique<Piece>(Piece::Type::eQueen, Piece::Color::eBlack, 0, 3);

        Piece& refToRook = *arrayOfPtrs[0];
        refToRook.Print();
        arrayOfPtrs[1]->Print();
    }

    return 0;
}