// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#pragma once

#include "mim/internal/setup.hpp"
#include "mim/detail/qualifier.hpp"
#include "mim/half.hpp"

#include "mim/detail/type/type_vector1.hpp"

namespace mim
{
    template <typename T = float, qualifier Q = qualifier::defaultp>
    using vec1 = VectorT<1, T, Q>;

    using vec1f = VectorT<1, float, qualifier::defaultp>;
    using vec1d = VectorT<1, double, qualifier::defaultp>;
    using vec1i = VectorT<1, int, qualifier::defaultp>;
    using vec1u = VectorT<1, unsigned int, qualifier::defaultp>;
    using vec1b = VectorT<1, bool, qualifier::defaultp>;
    using vec1h = VectorT<1, half, qualifier::defaultp>;

    using highp_vec1 = VectorT<1, float, qualifier::highp>;
    using highp_vec1f = VectorT<1, float, qualifier::highp>;
    using highp_vec1d = VectorT<1, double, qualifier::highp>;
    using highp_vec1i = VectorT<1, int, qualifier::highp>;
    using highp_vec1u = VectorT<1, unsigned int, qualifier::highp>;
    using highp_vec1b = VectorT<1, bool, qualifier::highp>;
    using highp_vec1h = VectorT<1, half, qualifier::highp>;

    using mediump_vec1 = VectorT<1, float, qualifier::mediump>;
    using mediump_vec1f = VectorT<1, float, qualifier::mediump>;
    using mediump_vec1d = VectorT<1, double, qualifier::mediump>;
    using mediump_vec1i = VectorT<1, int, qualifier::mediump>;
    using mediump_vec1u = VectorT<1, unsigned int, qualifier::mediump>;
    using mediump_vec1b = VectorT<1, bool, qualifier::mediump>;
    using mediump_vec1h = VectorT<1, half, qualifier::mediump>;

    using lowp_vec1 = VectorT<1, float, qualifier::lowp>;
    using lowp_vec1f = VectorT<1, float, qualifier::lowp>;
    using lowp_vec1d = VectorT<1, double, qualifier::lowp>;
    using lowp_vec1i = VectorT<1, int, qualifier::lowp>;
    using lowp_vec1u = VectorT<1, unsigned int, qualifier::lowp>;
    using lowp_vec1b = VectorT<1, bool, qualifier::lowp>;
    using lowp_vec1h = VectorT<1, half, qualifier::lowp>;

}
