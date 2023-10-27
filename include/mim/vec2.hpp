// Copyright (c) 2023-Present Mim contributors (see LICENSE)

/// \ref core
/// \file mim/vec2.hpp

#pragma once

#include "mim/half.hpp"

#include "mim/detail/type/type_vector2.hpp"

namespace mim
{

	/**
	 * \brief Alias for the default 2D vector types.
	 * \tparam T Type of the vector.
	 * \addtogroup VectorCore
	 */
	template <typename T = float>
	using vec2 = vec<2, T>;

	/**
	 * \brief Helper alias for 2D vectors of type float.
	 * \addtogroup VectorCore
	 */
	using vec2f = vec<2, float>;

	/**
	 * \brief Helper alias for 2D vectors of type int.
	 * \addtogroup VectorCore
	 */
	using vec2i = vec<2, int>;

	/**
	 * \brief Helper alias for 2D vectors of type unsigned int.
	 * \addtogroup VectorCore
	 */
	using vec2u = vec<2, unsigned int>;

	/**
	 * \brief Helper alias for 2D vectors of type double.
	 * \addtogroup VectorCore
	 */
	using vec2d = vec<2, double>;

	/**
	 * \brief Helper alias for 2D vectors of type half.
	 * \addtogroup VectorCore
	 */
	using vec2h = vec<2, half>;

} // namespace mim
