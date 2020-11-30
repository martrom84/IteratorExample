#include "matrix.h"
#include "matrix_iterator.h"

MatrixIterator::MatrixIterator(Matrix& matrix) : 
    m_matrix(matrix), 
    m_rowIdx{0}, 
    m_colIdx{0}, 
    m_rows{matrix.m_data.size()}, 
    m_cols{matrix.m_data.at(0).size()}
{
}

MatrixIterator::MatrixIterator(Matrix& matrix, U32 rowIdx, U32 colIdx) : 
    m_matrix(matrix), 
    m_rowIdx{rowIdx}, 
    m_colIdx{colIdx}, 
    m_rows{0}, 
    m_cols{0}
{
}

void MatrixIterator::operator++()
{
    if(m_colIdx+1 < m_cols) {
        m_colIdx++;
        return;
    }

    if(m_rowIdx+1 < m_rows) {
        m_rowIdx++;
        m_colIdx = 0;
        return;
    }

    m_rowIdx = m_colIdx = UINT32_MAX;
}

void MatrixIterator::operator++(int)
{
    this->operator++();
}

MatrixIterator::valueType& MatrixIterator::at(U32 row, U32 col)
{
    return m_matrix.m_data.at(row).at(col);
}

MatrixIterator::valueType& MatrixIterator::at(U32 row, U32 col) const
{
    return m_matrix.m_data.at(row).at(col);
}

MatrixIterator::valueType& MatrixIterator::operator*()
{
    return at(m_rowIdx, m_colIdx);
}

bool MatrixIterator::operator==(MatrixIterator const& rhs)
{
    return m_rowIdx == rhs.m_rowIdx && m_colIdx == rhs.m_colIdx;
}

bool MatrixIterator::operator!=(MatrixIterator const& rhs)
{
    return !(*this == rhs);
}

