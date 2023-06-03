// Copyright WizWorks, Inc. All Rights Reserved.

#pragma once

#include "system/core.hpp"
#include "math/detail/qualifier.hpp"
#include "math/half.hpp"

#include "math/detail/type_vector3.hpp"

namespace mim
{
    template <typename T = float, qualifier Q = qualifier::defaultp>
    using vec3 = VectorT<3, T, Q>;

    using vec3f = VectorT<3, float, qualifier::defaultp>;
    using vec3d = VectorT<3, double, qualifier::defaultp>;
    using vec3i = VectorT<3, i32, qualifier::defaultp>;
    using vec3u = VectorT<3, u32, qualifier::defaultp>;
    using vec3b = VectorT<3, bool, qualifier::defaultp>;
    using vec3h = VectorT<3, half, qualifier::defaultp>;

    using highp_vec3 = VectorT<3, float, qualifier::highp>;
    using highp_vec3f = VectorT<3, float, qualifier::highp>;
    using highp_vec3d = VectorT<3, double, qualifier::highp>;
    using highp_vec3i = VectorT<3, i32, qualifier::highp>;
    using highp_vec3u = VectorT<3, u32, qualifier::highp>;
    using highp_vec3b = VectorT<3, bool, qualifier::highp>;

    using mediump_vec3 = VectorT<3, float, qualifier::mediump>;
    using mediump_vec3f = VectorT<3, float, qualifier::mediump>;
    using mediump_vec3d = VectorT<3, double, qualifier::mediump>;
    using mediump_vec3i = VectorT<3, i32, qualifier::mediump>;
    using mediump_vec3u = VectorT<3, u32, qualifier::mediump>;
    using mediump_vec3b = VectorT<3, bool, qualifier::mediump>;

    using lowp_vec3 = VectorT<3, float, qualifier::lowp>;
    using lowp_vec3f = VectorT<3, float, qualifier::lowp>;
    using lowp_vec3d = VectorT<3, double, qualifier::lowp>;
    using lowp_vec3i = VectorT<3, i32, qualifier::lowp>;
    using lowp_vec3u = VectorT<3, u32, qualifier::lowp>;
    using lowp_vec3b = VectorT<3, bool, qualifier::lowp>;

}
