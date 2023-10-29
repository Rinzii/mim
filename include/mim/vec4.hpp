// Copyright (c) 2023-Present Mim contributors (see LICENSE)

/// \ref core
/// \file mim/vec4.hpp

#pragma once

#include "mim/half.hpp"

#include "mim/detail/type/type_vector4.hpp"

namespace mim
{
	/**
	 * \brief Alias for the default 4D vector types.
	 * \tparam T Type of the vector.
	 * \addtogroup VectorCore
	 */
	template <typename T = float>
	using vec4 = vec<4, T>;

	/**
	 * \brief Helper alias for 4D vectors of type float.
	 * \addtogroup VectorCore
	 */
	using vec4f = vec<4, float>;

	/**
	 * \brief Helper alias for 4D vectors of type double.
	 * \addtogroup VectorCore
	 */
	using vec4d = vec<4, double>;

	/**
	 * \brief Helper alias for 4D vectors of type int.
	 * \addtogroup VectorCore
	 */
	using vec4i = vec<4, int>;

	/**
	 * \brief Helper alias for 4D vectors of type unsigned int.
	 * \addtogroup VectorCore
	 */
	using vec4u = vec<4, unsigned int>;

	/**
	 * \brief Helper alias for 4D vectors of type half.
	 * \addtogroup VectorCore
	 */
	using vec4h = vec<4, half>;

} // namespace mim
