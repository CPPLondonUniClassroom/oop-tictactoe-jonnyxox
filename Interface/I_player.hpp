#pragma once

#include <iostream>
#include <vector>


const char* Board_position_names[] = {"ZERO", "ONE","TWO","THREE","FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
enum class Board_position { ZERO=0, ONE=1, TWO=2, THREE=3, FOUR=4, FIVE=4, SIX=6, SEVEN=7, EIGHT=8, NINE=9 };

class I_player {
public:
    virtual char Symbol() const = 0;
    virtual int Take_turn(const std::vector<Board_position> &bp) const = 0;

    virtual ~I_player() = default; //{ std::cout<<"\nDestructing I_player \n"; }
    // virtual destructor unwinds everything from derived classes, avoids memory leaks
};