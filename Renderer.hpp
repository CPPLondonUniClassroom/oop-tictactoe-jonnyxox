#pragma once

#include "Interface/I_renderer.hpp"
#include "Board.hpp"

class Renderer : public I_renderer {
public:
    explicit Renderer(Board &);

    Renderer();

    void render_board() const;
private:
    Board board;
};