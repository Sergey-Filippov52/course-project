//
// Файл main.cpp
//
#include "chess_game.hpp"

#include <iostream>
#include <windows.h>

int main()
{
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    using namespace chess;

    std::cout << "=== 1. Статический объект во вложенном блоке ===\n";
    {
        Piece staticPawn(Piece::Type::ePawn, Piece::Color::eWhite, 7, 0);
        staticPawn.ApplyShield();
        staticPawn.ApplyShield();
        staticPawn.Print();
    }

    std::cout << "\n=== 2. Композиция и агрегация ===\n";
    Piece* dynamicKnight = new Piece(Piece::Type::eKnight, Piece::Color::eWhite, 0, 1);

    {
        Game game;
        game.Start();

        game.GetBoard().PlacePiece(dynamicKnight, 7, 1);

        Piece king(Piece::Type::eKing, Piece::Color::eWhite, 0, 5);
        king.ApplyShield();
        game.GetBoard().PlacePiece(&king, 7, 1);

        std::cout << "\n--- Состояние доски ---\n";
        game.GetBoard().Print();

        std::cout << "\n--- Проверка победы ---\n";
        game.CheckVictory();

        std::cout << "\n--- Выходим из внутреннего блока ---\n";
    }

    std::cout << "\n--- Партия уничтожена, а фигура - нет ---\n";
    std::cout << "dynamicKnight существует: ";
    dynamicKnight->Print();
    delete dynamicKnight;

    std::cout << "\n=== 3. Динамический массив объектов ===\n";
    Piece* arrayOfPieces = new Piece[3]{
        Piece(Piece::Type::ePawn, Piece::Color::eWhite, 6, 0),
        Piece(Piece::Type::ePawn, Piece::Color::eWhite, 6, 1),
        Piece(Piece::Type::ePawn, Piece::Color::eWhite, 6, 2)
    };
    for (int i = 0; i < 3; ++i)
    {
        arrayOfPieces[i].Print();
    }
    delete[] arrayOfPieces;

    std::cout << "\n=== 4. Массив динамических объектов ===\n";
    Piece** arrayOfPtrs = new Piece * [3];
    arrayOfPtrs[0] = new Piece(Piece::Type::eRook, Piece::Color::eBlack, 0, 0);
    arrayOfPtrs[1] = new Piece(Piece::Type::eRook, Piece::Color::eBlack, 0, 9);
    arrayOfPtrs[2] = new Piece(Piece::Type::eQueen, Piece::Color::eBlack, 0, 3);

    Piece& refToRook = *arrayOfPtrs[0];
    refToRook.Print();
    arrayOfPtrs[1]->Print();

    for (int i = 0; i < 3; ++i)
    {
        delete arrayOfPtrs[i];
    }
    delete[] arrayOfPtrs;

    return 0;
}