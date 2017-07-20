#include "Sidewinder.hpp"

#include <random>

#include "Maze.hpp"

using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;

unsigned int Sidewinder::endRun(vector<unsigned int> run) {
    random_device rndDev;
    mt19937 eng(rndDev());
    uniform_int_distribution<unsigned int> dist(0, run.size() - 1);

    return run.at(dist(eng));

}

Maze Sidewinder::generate(unsigned int width, unsigned int height) {
    Maze tempMaze = generateBlank(width, height);

    random_device rndDev;
    mt19937 eng(rndDev());
    uniform_int_distribution<unsigned int> dist(0, 1);

    unsigned int coinFlip;

    for (int i = tempMaze.getHeight() - 1; i >= 0; i--) {
        vector<unsigned int> currentRun; // we'll keep the x values of the current run

        for (int j = 0; j < tempMaze.getWidth(); j++) {
            currentRun.push_back(j);

            coinFlip = dist(eng);

            if (i == 0) {
                if (j != tempMaze.getWidth() - 1) {
                    tempMaze.setCellRightWall(j, 0, Wall(" "));
                } else {
                    // Top right corner, do nothing
                }
            }
            else if (j == tempMaze.getWidth() - 1) {
                // we're at the right border
                if (currentRun.size() > 1) {
                    tempMaze.setCellBottomWall(endRun(currentRun), i - 1, Wall("   "));
                } else {
                    tempMaze.setCellBottomWall(j, i - 1, Wall("   "));
                }
            }

            else if (coinFlip == 0) {
                tempMaze.setCellRightWall(j, i, Wall(" "));
            }

            else if (coinFlip == 1) {
                if (currentRun.size() > 1) {
                    tempMaze.setCellBottomWall(endRun(currentRun), i - 1, Wall("   "));
                } else {
                    tempMaze.setCellBottomWall(j, i - 1, Wall("   "));
                }
                currentRun.clear();
            }
        }

        currentRun.clear();
    }

    return tempMaze;
}
