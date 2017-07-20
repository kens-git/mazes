#pragma once

#include <vector>

#include "Cell.hpp"

using std::vector;

class Maze {
    public:
        Maze(unsigned int width, unsigned int height);
        void setCell(unsigned int x, unsigned int y, Cell cell) { mMaze.at(y).at(x) = cell; }
        void setCellTopWall(unsigned int x, unsigned int y, Wall wall) { mMaze.at(y).at(x).setTopWall(wall); }
        void setCellRightWall(unsigned int x, unsigned int y, Wall wall) { mMaze.at(y).at(x).setRightWall(wall); }
        void setCellBottomWall(unsigned int x, unsigned int y, Wall wall) { mMaze.at(y).at(x).setBottomWall(wall); }
        void setCellLeftWall(unsigned int x, unsigned int y, Wall wall) { mMaze.at(y).at(x).setLeftWall(wall); }

        unsigned int getWidth() { return mWidth; }
        unsigned int getHeight() { return mHeight; }
        void draw();

   private:
        vector<vector<Cell>> mMaze;
        unsigned int mWidth;
        unsigned int mHeight;
};
