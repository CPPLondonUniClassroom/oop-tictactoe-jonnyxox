#include <algorithm> // std::find
#include <iostream>
#include <string>

#include "../Human_player.hpp"



Human_player::Human_player(const char &_player) :
            player{_player} {}

    char Human_player::Symbol() const {
        return player;
    }

    int Human_player::Take_turn(const std::vector<Board_position> &bp) const {
        std::vector<int> empty_cells{};
        std::cout << "\nAvailable cells: ";
        for (auto it = bp.begin(); it != bp.end(); ++it) {
            empty_cells.push_back(static_cast<int>(*it));
            std::cout << Board_position_names[static_cast<int>(*it)] << ", ";
        }
        //for (auto i: empty_cells) std::cout << i << ", ";
        int take_turn{};
        std::vector<int>::iterator it;
        while (true) {
            //  std::cout << "\nPlease select an empty cell b inputting a number (1 to 9): ";
            std::cin.clear();
            std::cin >> take_turn;
            if (std::cin.fail()) {std::cin.clear(); std::cin.ignore(32767,'\n');}
            it = find(empty_cells.begin(), empty_cells.end(), take_turn);
            if (it != empty_cells.end()) { break; }
            std::cout << "\nNot valid turn, please have another go\n";
        }
        // std::cout << "\nDeref *it" << *it << "\n";
        return *it;
    }


