// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#pragma once

#include "mim/detail/qualifier.hpp"
#include "mim/half.hpp"
#include "mim/internal/setup.hpp"

#include "mim/detail/type/type_vector4.hpp"

namespace mim {
template <typename T = float, qualifier Q = qualifier::defaultp>
using vec4 = VectorT<4, T, Q>;

using vec4f = VectorT<4, float, qualifier::defaultp>;
using vec4d = VectorT<4, double, qualifier::defaultp>;
using vec4i = VectorT<4, int, qualifier::defaultp>;
using vec4u = VectorT<4, unsigned int, qualifier::defaultp>;
using vec4b = VectorT<4, bool, qualifier::defaultp>;
using vec4h = VectorT<4, half, qualifier::defaultp>;

using highp_vec4 = VectorT<4, float, qualifier::highp>;
using highp_vec4f = VectorT<4, float, qualifier::highp>;
using highp_vec4d = VectorT<4, double, qualifier::highp>;
using highp_vec4i = VectorT<4, int, qualifier::highp>;
using highp_vec4u = VectorT<4, unsigned int, qualifier::highp>;
using highp_vec4b = VectorT<4, bool, qualifier::highp>;
using highp_vec4h = VectorT<4, half, qualifier::highp>;

using mediump_vec4 = VectorT<4, float, qualifier::mediump>;
using mediump_vec4f = VectorT<4, float, qualifier::mediump>;
using mediump_vec4d = VectorT<4, double, qualifier::mediump>;
using mediump_vec4i = VectorT<4, int, qualifier::mediump>;
using mediump_vec4u = VectorT<4, unsigned int, qualifier::mediump>;
using mediump_vec4b = VectorT<4, bool, qualifier::mediump>;
using mediump_vec4h = VectorT<4, half, qualifier::mediump>;

using lowp_vec4 = VectorT<4, float, qualifier::lowp>;
using lowp_vec4f = VectorT<4, float, qualifier::lowp>;
using lowp_vec4d = VectorT<4, double, qualifier::lowp>;
using lowp_vec4i = VectorT<4, int, qualifier::lowp>;
using lowp_vec4u = VectorT<4, unsigned int, qualifier::lowp>;
using lowp_vec4b = VectorT<4, bool, qualifier::lowp>;
using lowp_vec4h = VectorT<4, half, qualifier::lowp>;

} // namespace mim
