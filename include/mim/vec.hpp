// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#pragma once

#include "mim/detail/qualifier.hpp"
#include "mim/internal/setup.hpp"

#include "mim/vec1.hpp"
#include "mim/vec2.hpp"
#include "mim/vec3.hpp"
#include "mim/vec4.hpp"

namespace mim {
template <typename T, std::size_t Dim, qualifier Q = qualifier::defaultp>
using vec = typename std::enable_if<(Dim <= 4), VectorT<Dim, T, Q>>::type;
}
