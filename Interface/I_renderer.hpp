#pragma once

#include <iostream>

class I_renderer {
public:
virtual void render_board() const = 0;
virtual ~I_renderer() = default; //{ std::cout<<"\nDestructing I_Renderer only destructed after return\n"; }
};