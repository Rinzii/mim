#pragma once

#include "matrixT.hpp"

#include "matrix2f.hpp"
#include "matrix3f.hpp"
#include "matrix4f.hpp"

namespace mim
{
    template <std::size_t R, std::size_t C, typename T>
    using mat = MatrixT<R, C, T>;

    using mat2 = matrix2f;
    using mat3 = matrix3f;
    using mat4 = matrix4f;

    using mat2f = matrix2f;
    using mat3f = matrix3f;
    using mat4f = matrix4f;

    using mat2i = mat<2, 2, int>;
    using mat3i = mat<3, 3, int>;
    using mat4i = mat<4, 4, int>;

}