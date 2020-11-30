#include "matrix.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <cassert>

const int ROWS = 4;
const int COLS = 4;

// matrix cant be const here because no const_iterator is available
void printMatrix(Matrix& m)
{
    int cellCnt = 0;
    for(auto const& cell : m) {
        if((cellCnt++ % COLS) == 0) {
            std::cout << std::endl;
        }
        std::cout << std::setw(2) << cell << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char** argv)
{
    Matrix m1{ROWS, COLS};
    
    for(Matrix::iterator it = m1.begin(); it != m1.end(); it++) {
        *it = 5;
    }

    printMatrix(m1);

    std::cout << std::accumulate(m1.begin(), m1.end(), 0) << std::endl;

    int adder = 0;
    std::for_each(m1.begin(), m1.end(), [&adder] (auto& cell) {
        cell += adder++;
    });

    printMatrix(m1);

    return 0;
}
