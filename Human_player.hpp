#pragma once

#include "Board.hpp"
#include "Interface/I_player.hpp"

class Human_player : public I_player {
public:
    explicit Human_player(const char &);

    char Symbol() const override;

    int Take_turn(const std::vector<Board_position> &bp) const override ;
private:
    char player{};
};
