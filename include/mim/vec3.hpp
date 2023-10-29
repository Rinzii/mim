// Copyright (c) 2023-Present Mim contributors (see LICENSE)

/// \ref core
/// \file mim/vec3.hpp

#pragma once

#include "mim/half.hpp"

#include "mim/detail/type/type_vector3.hpp"

namespace mim
{

	/**
	 * \brief Alias for the default 3D vector types.
	 * \tparam T Type of the vector.
	 * \addtogroup VectorCore
	 */
	template <typename T = float>
	using vec3 = vec<3, T>;

	/**
	 * \brief Helper alias for 3D vectors of type float.
	 * \addtogroup VectorCore
	 */
	using vec3f = vec<3, float>;

	/**
	 * \brief Helper alias for 3D vectors of type double.
	 * \addtogroup VectorCore
	 */
	using vec3d = vec<3, double>;

	/**
	 * \brief Helper alias for 3D vectors of type int.
	 * \addtogroup VectorCore
	 */
	using vec3i = vec<3, int>;

	/**
	 * \brief Helper alias for 3D vectors of type unsigned int.
	 * \addtogroup VectorCore
	 */
	using vec3u = vec<3, unsigned int>;

	/**
	 * \brief Helper alias for 3D vectors of type half.
	 * \addtogroup VectorCore
	 */
	using vec3h = vec<3, half>;

} // namespace mim
