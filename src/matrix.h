#pragma once

#include "matrix_iterator.h"
#include <vector>
#include <cstdint>

class Matrix
{
    using U32 = std::uint32_t; // just syntactic sugar for less typing

    friend class MatrixIterator;
public:
    using iterator = MatrixIterator;
    using value_type = MatrixIterator::valueType;

    Matrix(U32 rows, U32 cols);

    void set(U32 row, U32 col, value_type value);
    value_type get(U32 row, U32 col) const;

    iterator begin();
    iterator end();

    // \TODO implement these
    //const_iterator cbegin();
    //const_iterator cend();
private:
    std::vector<std::vector<value_type>> m_data; 
};
