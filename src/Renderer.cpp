#include "../Renderer.hpp"

#include <algorithm>    // std::for_each

#include "../Interface/I_renderer.hpp"
#include "../Board.hpp"

    Renderer::Renderer(Board &_board) :
            board{_board} {}

    Renderer::Renderer() {
        Board board;
    }

    void Renderer::render_board() const {
        int index{1};
        std::vector<char> bp_state = board.Current_state();
        std::cout << "\n";
        for_each(bp_state.begin(), bp_state.end(), [&index](char const &bp_state) {
            if ((index + 1) % 3 == 0) std::cout << " | " << "  " << bp_state << "  " << " | ";
            else
                std::cout << "  " << bp_state << "  ";
            if (index % 3 == 0 && index < 7) std::cout << "\n------|-------|-------\n";
            if (index % 3 == 0 && index > 7) std::cout << "\n";
            ++index;
        });
        std::cout << "\n";
    }

