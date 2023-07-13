// Copyright (c) 2023-Present Mim contributors (see LICENSE)

/// \ref core
/// \file mim/vec1.hpp

#pragma once

#include "mim/half.hpp"

#include "mim/detail/type/type_vector1.hpp"

namespace mim
{

	/**
	 * \brief Alias for the default 1D vector types.
	 * \tparam T Type of the vector.
	 * \tparam Q Qualifier of the vector.
	 * \addtogroup VectorCore
	 */
	template <typename T = float, qualifier Q = qualifier::defaultp>
	using vec1 = vec<1, T, Q>;

	/**
	 * \brief Helper alias for 1D vectors of type float.
	 * \addtogroup VectorCore
	 */
	using vec1f = vec<1, float, qualifier::defaultp>;

	/**
	 * \brief Helper alias for 1D vectors of type double.
	 * \addtogroup VectorCore
	 */
	using vec1d = vec<1, double, qualifier::defaultp>;

	/**
	 * \brief Helper alias for 1D vectors of type int.
	 * \addtogroup VectorCore
	 */
	using vec1i = vec<1, int, qualifier::defaultp>;

	/**
	 * \brief Helper alias for 1D vectors of type unsigned int.
	 * \addtogroup VectorCore
	 */
	using vec1u = vec<1, unsigned int, qualifier::defaultp>;

	/**
	 * \brief Helper alias for 1D vectors of type bool.
	 * \addtogroup VectorCore
	 */
	using vec1b = vec<1, bool, qualifier::defaultp>;

	/**
	 * \brief Helper alias for 1D vectors of type half.
	 * \addtogroup VectorCore
	 */
	using vec1h = vec<1, half, qualifier::defaultp>;

	using highp_vec1 = vec<1, float, qualifier::highp>;
	using highp_vec1f = vec<1, float, qualifier::highp>;
	using highp_vec1d = vec<1, double, qualifier::highp>;
	using highp_vec1i = vec<1, int, qualifier::highp>;
	using highp_vec1u = vec<1, unsigned int, qualifier::highp>;
	using highp_vec1b = vec<1, bool, qualifier::highp>;
	using highp_vec1h = vec<1, half, qualifier::highp>;

	using mediump_vec1 = vec<1, float, qualifier::mediump>;
	using mediump_vec1f = vec<1, float, qualifier::mediump>;
	using mediump_vec1d = vec<1, double, qualifier::mediump>;
	using mediump_vec1i = vec<1, int, qualifier::mediump>;
	using mediump_vec1u = vec<1, unsigned int, qualifier::mediump>;
	using mediump_vec1b = vec<1, bool, qualifier::mediump>;
	using mediump_vec1h = vec<1, half, qualifier::mediump>;

	using lowp_vec1 = vec<1, float, qualifier::lowp>;
	using lowp_vec1f = vec<1, float, qualifier::lowp>;
	using lowp_vec1d = vec<1, double, qualifier::lowp>;
	using lowp_vec1i = vec<1, int, qualifier::lowp>;
	using lowp_vec1u = vec<1, unsigned int, qualifier::lowp>;
	using lowp_vec1b = vec<1, bool, qualifier::lowp>;
	using lowp_vec1h = vec<1, half, qualifier::lowp>;

} // namespace mim
