// Copyright (c) 2023-Present Mim contributors (see LICENSE)

/// \ref core
/// \file mim/vec4.hpp

#pragma once

#include "mim/detail/qualifier.hpp"
#include "mim/half.hpp"
#include "mim/internal/setup.hpp"

#include "mim/detail/type/type_vector4.hpp"

namespace mim
{
	/**
	 * \brief Alias for the default 4D vector types.
	 * \tparam T Type of the vector.
	 * \tparam Q Qualifier of the vector.
	 * \addtogroup VectorCore
	 */
	template <typename T = float, qualifier Q = qualifier::defaultp>
	using vec4 = VectorT<4, T, Q>;

	/**
	 * \brief Helper alias for 4D vectors of type float.
	 * \addtogroup VectorCore
	 */
	using vec4f = VectorT<4, float, qualifier::defaultp>;

	/**
	 * \brief Helper alias for 4D vectors of type double.
	 * \addtogroup VectorCore
	 */
	using vec4d = VectorT<4, double, qualifier::defaultp>;

	/**
	 * \brief Helper alias for 4D vectors of type int.
	 * \addtogroup VectorCore
	 */
	using vec4i = VectorT<4, int, qualifier::defaultp>;

	/**
	 * \brief Helper alias for 4D vectors of type unsigned int.
	 * \addtogroup VectorCore
	 */
	using vec4u = VectorT<4, unsigned int, qualifier::defaultp>;

	/**
	 * \brief Helper alias for 4D vectors of type bool.
	 * \addtogroup VectorCore
	 */
	using vec4b = VectorT<4, bool, qualifier::defaultp>;

	/**
	 * \brief Helper alias for 4D vectors of type half.
	 * \addtogroup VectorCore
	 */
	using vec4h = VectorT<4, half, qualifier::defaultp>;

	template <typename T = float>
	using highp_vec4 = VectorT<4, T, qualifier::highp>;
	using highp_vec4f = VectorT<4, float, qualifier::highp>;
	using highp_vec4d = VectorT<4, double, qualifier::highp>;
	using highp_vec4i = VectorT<4, int, qualifier::highp>;
	using highp_vec4u = VectorT<4, unsigned int, qualifier::highp>;
	using highp_vec4b = VectorT<4, bool, qualifier::highp>;
	using highp_vec4h = VectorT<4, half, qualifier::highp>;

	template <typename T = float>
	using mediump_vec4 = VectorT<4, float, qualifier::mediump>;
	using mediump_vec4f = VectorT<4, float, qualifier::mediump>;
	using mediump_vec4d = VectorT<4, double, qualifier::mediump>;
	using mediump_vec4i = VectorT<4, int, qualifier::mediump>;
	using mediump_vec4u = VectorT<4, unsigned int, qualifier::mediump>;
	using mediump_vec4b = VectorT<4, bool, qualifier::mediump>;
	using mediump_vec4h = VectorT<4, half, qualifier::mediump>;

	template <typename T = float>
	using lowp_vec4 = VectorT<4, float, qualifier::lowp>;
	using lowp_vec4f = VectorT<4, float, qualifier::lowp>;
	using lowp_vec4d = VectorT<4, double, qualifier::lowp>;
	using lowp_vec4i = VectorT<4, int, qualifier::lowp>;
	using lowp_vec4u = VectorT<4, unsigned int, qualifier::lowp>;
	using lowp_vec4b = VectorT<4, bool, qualifier::lowp>;
	using lowp_vec4h = VectorT<4, half, qualifier::lowp>;

} // namespace mim
