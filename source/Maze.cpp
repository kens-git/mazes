#include "Maze.hpp"

#include <iostream>

using std::cout;
using std::endl;

Maze::Maze(unsigned int width, unsigned int height) {
    mWidth = width;
    mHeight = height;
    for (int i = 0; i < mHeight; i++) {
        mMaze.push_back(vector<Cell>(mWidth));
    }
}

void Maze::draw() {
    for (int i = 0; i < mHeight; i++) { // loop through each row of the maze
        string firstRow, secondRow, thirdRow; // 'row' in this context refers to a row in a cell, not the maze

        for (int j = 0; j < mWidth; j++) { // loop through each cell
            firstRow += mMaze.at(i).at(j).getRow(0);
            secondRow += mMaze.at(i).at(j).getRow(1);
            thirdRow += mMaze.at(i).at(j).getRow(2);
        }
        cout << firstRow << endl;
        cout << secondRow << endl;
        cout << thirdRow;
    }
    cout << endl;
}
