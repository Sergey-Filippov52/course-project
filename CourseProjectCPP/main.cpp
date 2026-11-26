#include "pawn.hpp"
#include "knight.hpp"
#include <iostream>
#include <vector>
#include <memory>

int main() {
    setlocale(LC_ALL, "Russian");

    std::cout << "========== 1. Создание фигур ==========\n";
    {
        std::vector<std::unique_ptr<chess::BasePiece>> pieces;
        pieces.push_back(std::make_unique<chess::Pawn>("White", 1, 0));
        pieces.push_back(std::make_unique<chess::Knight>("Black", 7, 1));

        std::cout << "\n========== 2. Наследование и виртуальные методы ==========\n";
        for (const auto& p : pieces) {
            std::cout << p->Describe() << "\n\n";
        }
    }

    std::cout << "========== 3. Работа со строками ==========\n";
    {
        chess::Pawn p("White", 2, 2);
        std::string text = "Выбранная фигура: " + p.GetName();
        std::cout << text << "\n";

        std::string pattern = p.GetMovePattern();
        size_t pos = pattern.find("2");
        if (pos != std::string::npos) {
            std::cout << "Найдена подстрока: " << pattern.substr(pos, 1) << "\n";
        }
        if (p.GetName() == "Пешка") {
            std::cout << "Это пешка!\n";
        }
    }

    std::cout << "\n========== 4. Поверхностная и глубокая копия ==========\n";
    {
        chess::Pawn original("White", 2, 2);
        auto deepCopy = original.Clone();
        std::cout << "Глубокая копия создана\n";
    }

    std::cout << "\n========== 5. Статические члены ==========\n";
    std::cout << "Всего создано фигур: " << chess::BasePiece::GetCreatedCount() << "\n";

    return 0;
}