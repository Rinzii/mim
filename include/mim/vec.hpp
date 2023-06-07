// Copyright (c) 2023-Present Mim contributors (see LICENSE)

/// \ref core
/// \file mim/vec.hpp
/// \brief Global vector file to include all vector types.

#pragma once



#include "mim/vec1.hpp"
#include "mim/vec2.hpp"
#include "mim/vec3.hpp"
#include "mim/vec4.hpp"

namespace mim
{
/**
 * \brief Templated helper alias for all vector types.
 * \tparam T Type of the vector.
 * \tparam Dim Dimension of the vector.
 * \tparam Q Qualifier of the vector.
 * \addtogroup VectorCore
 */
template <std::size_t Dim, typename T, qualifier Q = qualifier::defaultp>
using vec = typename std::enable_if<(Dim <= 4), VectorT<Dim, T, Q>>::type;
}
