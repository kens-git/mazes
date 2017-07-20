#include <memory>
#include <iostream>

#include "MazeGenerator.hpp"
#include "BinaryTree.hpp"
#include "Sidewinder.hpp"
#include "Maze.hpp"

using std::shared_ptr;
using std::make_shared;
using std::cout;
using std::endl;

void showType(const shared_ptr<MazeGenerator> mg);

int main() {
    shared_ptr<MazeGenerator> mazeGenerator = make_shared<BinaryTree>();
    Maze myMaze = mazeGenerator->generate(10, 10);

    showType(mazeGenerator);
    myMaze.draw();
    cout << endl << endl;

    mazeGenerator = make_shared<Sidewinder>();
    myMaze = mazeGenerator->generate(10, 10);

    showType(mazeGenerator);
    myMaze.draw();

    return 0;
}

void showType(const shared_ptr<MazeGenerator> mg) {
    MazeGenerator *theMG = mg.get();

    cout << "Drawing maze using algorithm " << typeid(*theMG).name() << endl;
}
