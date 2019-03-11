#include "catch.hpp"

#include "Interface/I_player.hpp"
#include "Interface/I_renderer.hpp"
#include "Board.hpp"
#include "Human_player.hpp"
#include "Renderer.hpp"
#include "Controller.hpp"

void print_vec_board_pos(std::vector<Board_position> &fp1) {
    if (fp1.size() < 1) {
        std::cout << "\nfull\n";
        return;
    }
    std::cout << "\n";
    for (auto it = fp1.begin(); it != fp1.end(); ++it) {
        std::cout << Board_position_names[static_cast<int>(*it) - 1] << ", ";
    }
    std::cout << "\n";
}

void print_vec_board(Board &b) {
    std::cout << "**";
    for (auto it = b.board.begin(); it != b.board.end(); ++it) {
        std::cout << static_cast<int>(*it) << ", ";
    }
    std::cout << "**\n";
}

void print_board_state(std::vector<char> &fp1) {
    std::cout << "\n";
    for (auto it = fp1.begin(); it != fp1.end(); ++it) {
        std::cout << *it << ", ";
    }
    std::cout << "\n";
}

SCENARIO("construct players") {

    GIVEN("construct two players for the game and check they have the correct symbol") {
        Human_player p1{'X'};
        Human_player p2{'O'};
        REQUIRE(p1.Symbol() == 'X');
        REQUIRE(p2.Symbol() == 'O');
        WHEN("we have a board of some empty, and full cells and check we can select the next turn") {
            std::vector<Board_position> test_board_1 = {
                    Board_position::ONE,
                    Board_position::THREE,
                    Board_position::FOUR,
                    Board_position::EIGHT,
                    Board_position::NINE};
            WHEN("take-turn i set to 1") {

                //  CHECK(p1.Take_turn(test_board_1) == 1); // input a one when asked
            }
        }
    }
    GIVEN("construct a renderer") {
        Renderer r1{};
        r1.render_board();
    }

    GIVEN("a board identify the empty cells") {
        Board b1 = {{0, 0, 0, 1, 1, 1, 2, 2, 2}};
        CHECK(b1.board[8] == 2);
        CHECK(b1.board[0] == 0);
        CHECK(b1.board[3] == 1);
        Board b2 = {{0, 0, 0}};

        std::vector<Board_position> fp1 = b1.Free_positions();
        print_vec_board_pos(fp1);

        b1 = {{0, 0, 0, 0, 0, 0, 0, 0, 0}};
        fp1 = b1.Free_positions();
        print_vec_board_pos(fp1);

        b1 = {{1, 1, 1, 1, 1, 1, 1, 1, 1}};
        fp1 = b1.Free_positions();
        print_vec_board_pos(fp1);
    }

    GIVEN("a board identify empty cells and occupy a position / cell so long as its free") {
        // try an already occupied cell
        Human_player p1{'X'};
        Board b1 = {{0, 0, 0, 1, 1, 1, 2, 2, 2}};
        print_vec_board(b1);
        Board_position bp{Board_position::FOUR};
        b1.Occupy_position(bp, p1);

        GIVEN("a new cell to place move, check validity and update board if ok") {
            bp = Board_position::ONE;
            std::cout << "before move\n";
            print_vec_board(b1);
            b1.Occupy_position(bp, p1);
            std::cout << "after move\n";
            print_vec_board(b1);
        }
    }
    GIVEN("a board retrn the current state f the board") {
        Board b2 = {{0, 0, 0, 1, 1, 1, 2, 2, 2}};
        std::vector<char> tst = b2.Current_state();
        print_board_state(tst);
        CHECK(tst[0] == 'E');
        CHECK(tst[3] == 'X');
        CHECK(tst[8] == 'O');
    }

    GIVEN("a controller check the player take turn, set up inputs") {
        Human_player p1{'X'};
        Human_player p2{'O'};
        Renderer rc_1{};
        Board bc_1 = {{0, 0, 0, 0, 0, 0, 0, 0, 0}};
        Controller c_1{p1, p2, rc_1, bc_1};
        CHECK(p1.Symbol() == 'X');
        CHECK(p2.Symbol() == 'O');

        GIVEN("a few different boards check win logic") {
            CHECK(c_1.Game_win_check(p2.Symbol()) == false);

            Board bc_2 = {{1, 1, 1, 0, 0, 0, 0, 0, 0}};
           Controller c_2{p1, p2, rc_1, bc_2};
            CHECK(c_2.Game_win_check(p1.Symbol()) == true);

            bc_2 = {{0, 0, 1, 0, 0, 1, 0, 0, 1}};
            Controller c_3{p1, p2, rc_1, bc_2};
            CHECK(c_3.Game_win_check(p1.Symbol()) == true);

            bc_2 = {{1, 0, 0, 0, 1, 0, 0, 0, 1}};
            Controller c_4{p1, p2, rc_1, bc_2};
            CHECK(c_4.Game_win_check(p1.Symbol()) == true);

            bc_2 = {{0, 0, 1, 0, 0, 1, 0, 0, 1}};
            Controller c_5 = {p1, p2, rc_1, bc_2};
            CHECK(c_5.Game_win_check(p1.Symbol()) == true);

            bc_2 = {{1, 0, 2, 0, 1, 0, 2, 0, 2}};
            Controller c_6 = {p1, p2, rc_1, bc_2};
            CHECK(c_6.Game_win_check(p1.Symbol()) == false);

            bc_2 = {{2, 0, 1, 0, 2, 0, 1, 0, 2}};
            Controller c_7 = {p1, p2, rc_1, bc_2};
            CHECK(c_7.Game_win_check(p2.Symbol()) == true);

            bc_2 = {{2, 2, 2, 0, 0, 0, 1, 0, 2}};
            Controller c_8 = {p1, p2, rc_1, bc_2};
            CHECK(c_8.Game_win_check(p2.Symbol()) == true);

            bc_2 = {{1, 2, 1, 2, 1, 2, 2, 1, 2}};
            Controller c_9 = {p1, p2, rc_1, bc_2};
            CHECK(c_9.Game_win_check(p2.Symbol()) == false);

        }
        c_1.Play_game();
    }


};

