#pragma once

#include <vector>

// TODO: Build this out to be a full matrix class
// TODO: Currently this is just a shell of a matrix class but I'm not yet ready to build this out

namespace mim
{
    template<size_t Row, size_t Col, typename T>
    class MatrixT
    {
    private:
        std::array<std::array<T, Col>, Row> data;  // 2D array to hold the matrix data
        
    public:
        // Accessor to get the element at (i, j)
        T& operator()(size_t i, size_t j)
        {
            return data[i][j];
        }
        
        // Const accessor to get the element at (i, j)
        const T& operator()(size_t i, size_t j) const
        {
            return data[i][j];
        }
        
        // Accessor to get the number of rows
        size_t numRows() const
        {
            return Row;
        }
        
        // Accessor to get the number of columns
        size_t numCols() const
        {
            return Col;
        }
    };
}
