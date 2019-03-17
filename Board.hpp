#pragma once

//#include <algorithm>    // std::fill std::for_each
#include <vector>
//#include <iostream>

#include "Interface/I_player.hpp"

class Board {
public:
    Board(std::vector<int> );

    Board();

    std::vector<Board_position> Free_positions() const;

    void Occupy_position(const Board_position &, const I_player &);

// overload Occupy Position with int for simplicity
    void Occupy_position(const int &, const I_player &);

    std::vector<char> Current_state() const;

    std::vector<int> board;
};


