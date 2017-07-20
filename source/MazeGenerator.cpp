#include "MazeGenerator.hpp"

#include "Maze.hpp"

Maze MazeGenerator::generateBlank(unsigned int width, unsigned int height) {
    Maze tempMaze(width, height);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            Cell tempCell;
            if (i == 0) {
                tempCell.setWall(0, 0, Wall("+"));
                tempCell.setWall(1, 0, Wall("---"));
                if (j == width - 1) {
                    tempCell.setWall(2, 0, Wall("+"));
                }
            }

            if (j == 0) {
                tempCell.setWall(0, 1, Wall("|"));
                tempCell.setWall(0, 2, Wall("+"));
            }

            // Generally, every wall will have a bottom and right wall
            tempCell.setWall(1, 1, Wall("   "));
            tempCell.setWall(2, 1, Wall("|"));
            tempCell.setWall(1, 2, Wall("---"));
            tempCell.setWall(2, 2, Wall("+"));

            tempMaze.setCell(j, i, tempCell);
        }
    }

    return tempMaze;
}
