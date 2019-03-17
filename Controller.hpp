#pragma once

#include "Interface/I_player.hpp"
#include "Interface/I_renderer.hpp"
#include "Board.hpp"


class Controller {
public:
    Controller(I_player &, I_player &, I_renderer &, Board );

    bool Game_win_check(const char &);
    void Play_game();

private:
    I_player &player_1;
    I_player &player_2;
    I_renderer &r;
    Board b;
};