// Copyright WizWorks, Inc. All Rights Reserved.

#pragma once

#include "system/core.hpp"
#include "math/detail/qualifier.hpp"

#include "math/vec1.hpp"
#include "math/vec2.hpp"
#include "math/vec3.hpp"
#include "math/vec4.hpp"

namespace mim
{
    template <typename T, std::size_t Dim, qualifier Q = qualifier::defaultp>
    using vec = typename std::enable_if<(Dim <= 4), VectorT<Dim, T, Q>>::type;
}
