#pragma once

#include <vector>

#include "MazeGenerator.hpp"

using std::vector;

class Maze;

class Sidewinder : public MazeGenerator {
    public:
        Maze generate(unsigned int width, unsigned int height);
        // returns a random number from the vector
        unsigned int endRun(vector<unsigned int> run);
};
