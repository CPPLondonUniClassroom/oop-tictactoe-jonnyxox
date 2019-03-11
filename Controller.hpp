#pragma once

#include <algorithm>    // std::find

#include "Interface/I_player.hpp"
#include "Interface/I_renderer.hpp"
#include "Board.hpp"
#include "Renderer.hpp"

class Controller {
public:
    Controller(I_player &_player_1, I_player &_player_2, I_renderer &_r, Board _b) :
            player_1{_player_1},
            player_2{_player_2},
            r{_r},
            b{_b} {}

    bool Game_win_check(const char &player_symbol) {
        int chk {0};
        if (player_symbol == 'X') chk = 1;
        else if (player_symbol == 'O') chk =2;
        std::vector<std::vector<int>> magic_square = {
                {8, 1, 6},
                {3, 5, 7},
                {4, 9, 2}
        };
        std::vector<int> counter {0,0,0,0};

        for (int x = 0; x < 3; ++x) {
            for (int y = 0; y < 3; ++y) {
                if (b.board[(x + y * 3)] == chk ) counter[0] += magic_square[x][y];
                if (b.board[(y + x * 3)] == chk ) counter[1] += magic_square[x][y];
          }

            if (counter[0] == 15 || counter[1] == 15) return true;
            counter[0] = 0;
            counter[1] = 0;
       //     std::cout << " X1 " << x << ", " << x + x * 3 << ", " << counter[2] << " " << counter[3] << ", "<< 2 + x * 2 <<"\n";
            if (b.board[x + x * 3] == chk ) counter[2] += magic_square[x][x];
            if (b.board[2 + x * 2] == chk ) counter[3] += magic_square[x][-x+2];
         //   std::cout << " X2 " << x << ", " << x + x * 3 << ", " << counter[2] << " " <<magic_square[x][x] << "." << counter[3] << ", "<< 2 + x * 2 <<"\n";
        }
        if (counter[2] == 15 || counter[3] == 15) return true;
        counter.clear();
        return false;
    }

    void Play_game() {
        int next_turn{false};
        bool win_or_not{};
        std::vector<int>::iterator it;
        std::cout << " hi lets Play the game\n";
        while (true) {

            std::cout << "Player " << player_1.Symbol() << " Please select an empty cell:";
            next_turn = player_1.Take_turn(b.Free_positions());
            b.Occupy_position(next_turn, player_1);
            Renderer r_p1{b};
            r_p1.render_board();
            win_or_not = Game_win_check(player_1.Symbol());
            if (win_or_not == true) {
                std::cout << player_1.Symbol() << " wins. Well Done\n";
                break;
            }

            it = find(b.board.begin()+1, b.board.end(), 0);
            if (it == b.board.end()) {std::cout << "\n That's a draw then\n"; break;}

            std::cout << "Player " << player_2.Symbol() << " Please select an empty cell:";
            next_turn = player_2.Take_turn(b.Free_positions());
            b.Occupy_position(next_turn, player_2);
            Renderer r_p2{b};
            r_p2.render_board();
            win_or_not = Game_win_check(player_2.Symbol());
            if (win_or_not == true) {
                std::cout << player_2.Symbol() << " wins. Well Done\n";
                break;
            }

        }
    }

    I_player &player_1;
    I_player &player_2;
    I_renderer &r;
    Board b;
};