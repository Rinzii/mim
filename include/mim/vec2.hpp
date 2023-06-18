// Copyright (c) 2023-Present Mim contributors (see LICENSE)

/// \ref core
/// \file mim/vec2.hpp

#pragma once

#include "mim/detail/qualifier.hpp"
#include "mim/half.hpp"

#include "mim/detail/type/type_vector2.hpp"

namespace mim
{

	/**
	 * \brief Alias for the default 2D vector types.
	 * \tparam T Type of the vector.
	 * \tparam Q Qualifier of the vector.
	 * \addtogroup VectorCore
	 */
	template <typename T = float, qualifier Q = qualifier::defaultp>
	using vec2 = VectorT<2, T, Q>;

	/**
	 * \brief Helper alias for 2D vectors of type float.
	 * \addtogroup VectorCore
	 */
	using vec2f = VectorT<2, float, defaultp>;

	/**
	 * \brief Helper alias for 2D vectors of type int.
	 * \addtogroup VectorCore
	 */
	using vec2i = VectorT<2, int, defaultp>;

	/**
	 * \brief Helper alias for 2D vectors of type unsigned int.
	 * \addtogroup VectorCore
	 */
	using vec2u = VectorT<2, unsigned int, defaultp>;

	/**
	 * \brief Helper alias for 2D vectors of type double.
	 * \addtogroup VectorCore
	 */
	using vec2d = VectorT<2, double, defaultp>;

	/**
	 * \brief Helper alias for 2D vectors of type bool.
	 * \addtogroup VectorCore
	 */
	using vec2b = VectorT<2, bool, defaultp>;

	/**
	 * \brief Helper alias for 2D vectors of type half.
	 * \addtogroup VectorCore
	 */
	using vec2h = VectorT<2, half, defaultp>;

	using highp_vec2 = VectorT<2, float, highp>;
	using highp_vec2f = VectorT<2, float, highp>;
	using highp_vec2i = VectorT<2, int, highp>;
	using highp_vec2u = VectorT<2, unsigned int, highp>;
	using highp_vec2d = VectorT<2, double, highp>;
	using highp_vec2b = VectorT<2, bool, highp>;
	using highp_vec2h = VectorT<2, half, highp>;

	using mediump_vec2 = VectorT<2, float, mediump>;
	using mediump_vec2f = VectorT<2, float, mediump>;
	using mediump_vec2i = VectorT<2, int, mediump>;
	using mediump_vec2u = VectorT<2, unsigned int, mediump>;
	using mediump_vec2d = VectorT<2, double, mediump>;
	using mediump_vec2b = VectorT<2, bool, mediump>;
	using mediump_vec2h = VectorT<2, half, mediump>;

	using lowp_vec2 = VectorT<2, float, lowp>;
	using lowp_vec2f = VectorT<2, float, lowp>;
	using lowp_vec2i = VectorT<2, int, lowp>;
	using lowp_vec2u = VectorT<2, unsigned int, lowp>;
	using lowp_vec2d = VectorT<2, double, lowp>;
	using lowp_vec2b = VectorT<2, bool, lowp>;
	using lowp_vec2h = VectorT<2, half, lowp>;

} // namespace mim
