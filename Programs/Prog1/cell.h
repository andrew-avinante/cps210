#include <iostream>

struct Location
{
    int row;
    int col;
};

class Cell
{
    public:
        bool isAlive;
        Location loc;
        int neighbors;
        inline void SetRow(int r) { loc.row = r; }
        inline void SetCol(int c) { loc.row = c; }     
        inline void BirthCell() { isAlive = true; }
        inline void KillCell() { isAlive = false; }
        inline int GetNeighbor() { return neighbors; }
        inline void AddNeighbor() { neighbors += 1; }
        inline void ResetNeighbor() { neighbors = 0; }
};