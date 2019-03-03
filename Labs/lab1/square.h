#include <iostream>

class Square {
public:
    const int N;
private:
    int * const square;
    int rowCol2Index(int row, int col) const { return N*row + col; }
public:
    Square(int _n) : N(_n), square(new int[N*N]) { SetToZero(); }
    ~Square();
    
    void SetToZero()
    {
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j) 
            {
                set(i, j, 0);
            }
        }
    }

    int &get(int row, int col) { return square[rowCol2Index(row,col)]; }
    const int &get(int row, int col) const { return square[rowCol2Index(row,col)]; }
    void set(int row, int col, int value) { square[rowCol2Index(row,col)] = value; }
    int *operator[](int row) { return (square+N*row); }
    int size() const { return N; }
    
    std::ostream &print(std::ostream &os, char sep=' ', int width=3) const;
}; // end of class Square