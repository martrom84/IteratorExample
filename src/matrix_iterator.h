#pragma once
#include <cstdint>

class Matrix;

class MatrixIterator
{
    using U32 = std::uint32_t;
public:
    using valueType = std::int32_t;

    explicit MatrixIterator(Matrix& matrix);
    MatrixIterator(Matrix& matrix, U32 rowIdx, U32 colIdx);

    void operator++();
    void operator++(int);
    std::int32_t& operator*();
    bool operator==(MatrixIterator const& rhs);
    bool operator!=(MatrixIterator const& rhs);
protected:
    valueType& at(U32 row, U32 col);
    valueType& at(U32 row, U32 col) const;
private:
    Matrix& m_matrix;
    U32 m_rowIdx;
    U32 m_colIdx;
    std::size_t m_rows;
    std::size_t m_cols;
};
