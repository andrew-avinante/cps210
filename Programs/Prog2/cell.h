#include <iostream>
#include <string>

using namespace std;

struct Location
{
    int row;
    int col;
    string cord;
};

class Cell
{
    public:
        Location loc;
        char isSolid;
        int visitNum;
        bool isPath;
        inline void SetCord(int r, int c)
        {
            loc.row = r; 
            loc.col = c; 
            loc.cord = to_string(loc.row) + ", " + to_string(loc.col);
        }   
        inline string GetCord() {return loc.cord;}
        inline int GetRow() {return loc.row;}
        inline int GetCol() {return loc.col;}
        inline void SetSolid() { isSolid = '1'; }   
        inline void SetVoid() { isSolid = '0'; }   
        inline void SetEntrance() { isSolid = 'E'; }  
        inline void SetVisitNum(int num) { visitNum = num;}
        inline int GetVisitNum() { return visitNum;}
        inline char GetCell(){return isSolid;}
        inline void SetPath(){isPath = true;}
        inline bool checkSides(int rowCheck, int colCheck, int height, int width) { return loc.col + colCheck >= 0 && loc.row + rowCheck >= 0 && loc.col + colCheck < width && loc.row + rowCheck < height;}
};