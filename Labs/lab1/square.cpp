#include <iomanip>
#include "square.h"

Square::~Square() {
    if (nullptr != square) {
        delete [] square;
    }
}
    
std::ostream &Square::print(std::ostream &os, char sep, int width) const {
    int row, col;
    
    for (row=0; row < N; ++row) {
        for (col=0; col < N; ++col) {
            if (col > 0 && sep > 0) { os << sep; }
            os << std::setw(width) << get(row, col);
        }
        os << std::endl;
    }
    return os;
}