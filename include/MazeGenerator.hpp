#pragma once

class Maze;

class MazeGenerator {
    public:
        virtual Maze generate(unsigned int width, unsigned int height) = 0;
        virtual Maze generateBlank(unsigned int width, unsigned int height);
};
