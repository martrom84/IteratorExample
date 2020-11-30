#include "matrix.h"


Matrix::Matrix(U32 rows, U32 cols)
{
    m_data = std::vector<std::vector<value_type>> (rows, std::vector<value_type>(cols, 0));
}

void Matrix::set(U32 row, U32 col, value_type value)
{
    m_data.at(row).at(col) = value;
}

Matrix::value_type Matrix::get(U32 row, U32 col) const
{
    return m_data.at(row).at(col);
}

Matrix::iterator Matrix::begin()
{
    return MatrixIterator(*this);
}

Matrix::iterator Matrix::end()
{
    return MatrixIterator(*this, UINT32_MAX, UINT32_MAX);   
}
