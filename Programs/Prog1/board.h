#include <iostream>
#include "cell.h"

class Board
{
    public:
        int width;
        int height;
        Cell** ecosystem;
        Cell** prevEco;
        Cell** prevPrevEco;
        int generations;
        int genCount;
        Board(int h, int w, int g);
        void PopulateCells();
        void PrintBoard(Cell** board);
        void PrintPrevBoard();
        void FindNeighbors();
        void CountGen();
        void Spawn();
        void Kill();
        void DebugPrint();
        inline void AddCurrentGen() { ++genCount; }
        inline int GetCurrentGen() { return genCount; }
        inline void ResetCurrentGen() { genCount = 0; }
        void SetPrevGen(Cell** previous, Cell** current);
        bool AreEqual();
    private:
        void CreateBoard(int w, int h, Cell** board);
};