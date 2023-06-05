// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#pragma once

#include "mim/internal/setup.hpp"
#include "mim/detail/qualifier.hpp"
#include "mim/half.hpp"

#include "mim/detail/type/type_vector2.hpp"

namespace mim
{
    template <typename T = float, qualifier Q = qualifier::defaultp>
    using vec2 = VectorT<2, T, Q>;

    using vec2f = VectorT<2, float, defaultp>;
    using vec2i = VectorT<2, i32, defaultp>;
    using vec2u = VectorT<2, u32 , defaultp>;
    using vec2d = VectorT<2, double, defaultp>;
    using vec2b = VectorT<2, bool, defaultp>;
    using vec2h = VectorT<2, half, defaultp>;

    using highp_vec2 = VectorT<2, float, highp>;
    using highp_vec2f = VectorT<2, float, highp>;
    using highp_vec2i = VectorT<2, i32, highp>;
    using highp_vec2u = VectorT<2, u32, highp>;
    using highp_vec2d = VectorT<2, double, highp>;
    using highp_vec2b = VectorT<2, bool, highp>;
    using highp_vec2h = VectorT<2, half, highp>;

    using mediump_vec2 = VectorT<2, float, mediump>;
    using mediump_vec2f = VectorT<2, float, mediump>;
    using mediump_vec2i = VectorT<2, i32, mediump>;
    using mediump_vec2u = VectorT<2, u32, mediump>;
    using mediump_vec2d = VectorT<2, double, mediump>;
    using mediump_vec2b = VectorT<2, bool, mediump>;
    using mediump_vec2h = VectorT<2, half, mediump>;

    using lowp_vec2 = VectorT<2, float, lowp>;
    using lowp_vec2f = VectorT<2, float, lowp>;
    using lowp_vec2i = VectorT<2, i32, lowp>;
    using lowp_vec2u = VectorT<2, u32, lowp>;
    using lowp_vec2d = VectorT<2, double, lowp>;
    using lowp_vec2b = VectorT<2, bool, lowp>;
    using lowp_vec2h = VectorT<2, half, lowp>;

}
