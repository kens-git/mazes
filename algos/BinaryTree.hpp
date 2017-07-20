#pragma once

#include "MazeGenerator.hpp"

class Maze;

class BinaryTree : public MazeGenerator {
    public:
        Maze generate(unsigned int width, unsigned int height);
};
