// Copyright WizWorks, Inc. All Rights Reserved.

#pragma once

#include "system/core.hpp"
#include "math/detail/qualifier.hpp"
#include "math/half.hpp"

#include "math/detail/type_vector1.hpp"

namespace mim
{
    template <typename T = float, qualifier Q = qualifier::defaultp>
    using vec1 = VectorT<1, T, Q>;

    using vec1f = VectorT<1, float, qualifier::defaultp>;
    using vec1d = VectorT<1, double, qualifier::defaultp>;
    using vec1i = VectorT<1, i32, qualifier::defaultp>;
    using vec1u = VectorT<1, u32, qualifier::defaultp>;
    using vec1b = VectorT<1, bool, qualifier::defaultp>;
    using vec1h = VectorT<1, half, qualifier::defaultp>;

    using highp_vec1 = VectorT<1, float, qualifier::highp>;
    using highp_vec1f = VectorT<1, float, qualifier::highp>;
    using highp_vec1d = VectorT<1, double, qualifier::highp>;
    using highp_vec1i = VectorT<1, i32, qualifier::highp>;
    using highp_vec1u = VectorT<1, u32, qualifier::highp>;
    using highp_vec1b = VectorT<1, bool, qualifier::highp>;
    using highp_vec1h = VectorT<1, half, qualifier::highp>;

    using mediump_vec1 = VectorT<1, float, qualifier::mediump>;
    using mediump_vec1f = VectorT<1, float, qualifier::mediump>;
    using mediump_vec1d = VectorT<1, double, qualifier::mediump>;
    using mediump_vec1i = VectorT<1, i32, qualifier::mediump>;
    using mediump_vec1u = VectorT<1, u32, qualifier::mediump>;
    using mediump_vec1b = VectorT<1, bool, qualifier::mediump>;
    using mediump_vec1h = VectorT<1, half, qualifier::mediump>;

    using lowp_vec1 = VectorT<1, float, qualifier::lowp>;
    using lowp_vec1f = VectorT<1, float, qualifier::lowp>;
    using lowp_vec1d = VectorT<1, double, qualifier::lowp>;
    using lowp_vec1i = VectorT<1, i32, qualifier::lowp>;
    using lowp_vec1u = VectorT<1, u32, qualifier::lowp>;
    using lowp_vec1b = VectorT<1, bool, qualifier::lowp>;
    using lowp_vec1h = VectorT<1, half, qualifier::lowp>;

}
