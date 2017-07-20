#include "BinaryTree.hpp"

#include <random>

#include "Maze.hpp"

using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;

Maze BinaryTree::generate(unsigned int width, unsigned int height) {
    Maze tempMaze = generateBlank(width, height);

    random_device rndDev;
    mt19937 eng(rndDev());
    uniform_int_distribution<unsigned int> dist(0, 1);

    unsigned int coinFlip;

    for (int i = 0; i < tempMaze.getHeight(); i++) {
        for (int j = 0; j < tempMaze.getWidth(); j++) {
            int coinFlip = dist(eng);
            if (j == tempMaze.getWidth() - 1 && i != 0) {
                // we're at the right border, remove top wall
                tempMaze.setCellBottomWall(j, i - 1, Wall("   "));
            }
            else if (j == tempMaze.getWidth() - 1 && i == 0) {
                // Top right corner, do nothing
            }
            else if (i == 0 && j != tempMaze.getWidth() - 1) {
                // we're at the top border, remove right wall
                tempMaze.setCellRightWall(j, i, Wall(" "));

            }
            else if (coinFlip == 0) {
                // remove top Wall, which is the cell above's bottom wall
                tempMaze.setCellBottomWall(j, i - 1, Wall("   "));

            } else {
                // remove right Wall
                tempMaze.setCellRightWall(j, i, Wall(" "));
            }
        }
    }

    return tempMaze;
}
