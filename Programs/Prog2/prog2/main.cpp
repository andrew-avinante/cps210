#include <iostream>
#include "board.h"

using namespace std;

int main(int argc, char **argv)
{
    Board maze = Board();
    maze.CreateBoard(argv[1]);
    bool path = maze.SearchBoard();
    maze.IsConnected();
    maze.WriteBoard(maze.maze, argv[2], path);
    return 0;
}