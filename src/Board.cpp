
#include <algorithm>    // std::fill std::for_each
//#include <vector>
#include <iostream>

#include "../Board.hpp"

    Board::Board(std::vector<int> _board) : board{_board} {
        if (board.size() != 9) std::cout << "Board wrong size";
    }

    Board::Board() : board(9) {
        std::fill(board.begin(), board.end(), 0);
    }

    std::vector<Board_position> Board::Free_positions() const {
        std::vector<Board_position> free_cells{};
        for (auto it = board.begin(); it != board.end(); ++it) {
            if (*it == 0) free_cells.push_back(static_cast<Board_position >(it - board.begin() + 1));
        }

        return free_cells;
    }

    void Board::Occupy_position(const Board_position &bp, const I_player &Ip) {
        // std::cout << Ip.Symbol() << "\n";
        //  std::cout << Board_position_names[static_cast<int>(bp) - 1] << "\n";
        if (board[static_cast<int>(bp) - 1] == 0) {
            //   std::cout << "\ncell free\n";
            if (Ip.Symbol() == 'X') board[static_cast<int>(bp) - 1] = 1;
            else if (Ip.Symbol() == 'O') board[static_cast<int>(bp) - 1] = 2;
        } else { std::cout << "\ncell occupied\n"; }
    };

    void Board::Occupy_position(const int &bp, const I_player &Ip) {
        //  std::cout << Ip.Symbol() << "\n";
        //   std::cout << Board_position_names[bp] << "\n";
        if (board[bp-1] == 0) {
            //   std::cout << "\ncell free\n";
            if (Ip.Symbol() == 'X') board[bp-1] = 1;
            else if (Ip.Symbol() == 'O') board[bp-1] = 2;

        }
    }

    std::vector<char> Board::Current_state() const {
        std::vector<char> bp_state(9);
        std::fill(bp_state.begin(), bp_state.end(), 'E'); // Empty indicator 'E' for checking remove for final game
        int index{0};
        for_each(board.begin(), board.end(), [&index, &bp_state](int const &bp) {
                     if (bp == 1) bp_state[index] = 'X';
                     else if (bp == 2) bp_state[index] = 'O';
                     ++index;
                 }
        );
        return {bp_state};
    }
