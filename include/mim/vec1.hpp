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
	 * \addtogroup VectorCore
	 */
	template <typename T = float>
	using vec1 = vec<1, T>;

	/**
	 * \brief Helper alias for 1D vectors of type float.
	 * \addtogroup VectorCore
	 */
	using vec1f = vec<1, float>;

	/**
	 * \brief Helper alias for 1D vectors of type double.
	 * \addtogroup VectorCore
	 */
	using vec1d = vec<1, double>;

	/**
	 * \brief Helper alias for 1D vectors of type int.
	 * \addtogroup VectorCore
	 */
	using vec1i = vec<1, int>;

	/**
	 * \brief Helper alias for 1D vectors of type unsigned int.
	 * \addtogroup VectorCore
	 */
	using vec1u = vec<1, unsigned int>;

	/**
	 * \brief Helper alias for 1D vectors of type half.
	 * \addtogroup VectorCore
	 */
	using vec1h = vec<1, half>;

} // namespace mim
