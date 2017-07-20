#pragma once

#include <array>

#include "Wall.hpp"

using std::array;

class Cell {
    public:
        Cell() { }
        Cell(array<array<Wall, 3>, 3> walls) { mWalls = walls; }
        void setWall(unsigned int x, unsigned int y, Wall wall) { mWalls.at(y).at(x) = wall; }
        void setTopWall(Wall wall) { mWalls.at(0).at(1) = wall; }
        void setRightWall(Wall wall) { mWalls.at(1).at(2) = wall; }
        void setBottomWall(Wall wall) { mWalls.at(2).at(1) = wall; }
        void setLeftWall(Wall wall) { mWalls.at(1).at(0) = wall; }
        string getWallString(unsigned int x, unsigned int y) { return mWalls.at(y).at(x).getWallString(); }
        // Utility method to make drawing easier
        string getRow(unsigned int index) { return getWallString(0, index)
                                                    + getWallString(1, index)
                                                    + getWallString(2, index); }
        unsigned int getWidth() { return mWidth; }
        unsigned int getHeight() { return mHeight; }

    private:
        array<array<Wall, 3>, 3> mWalls;
        unsigned int mWidth = 3;
        unsigned int mHeight = 3;
};
