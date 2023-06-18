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
	 * \tparam Q Qualifier of the vector.
	 * \addtogroup VectorCore
	 */
	template <typename T = float, qualifier Q = qualifier::defaultp>
	using vec3 = VectorT<3, T, Q>;

	/**
	 * \brief Helper alias for 3D vectors of type float.
	 * \addtogroup VectorCore
	 */
	using vec3f = VectorT<3, float, qualifier::defaultp>;

	/**
	 * \brief Helper alias for 3D vectors of type double.
	 * \addtogroup VectorCore
	 */
	using vec3d = VectorT<3, double, qualifier::defaultp>;

	/**
	 * \brief Helper alias for 3D vectors of type int.
	 * \addtogroup VectorCore
	 */
	using vec3i = VectorT<3, int, qualifier::defaultp>;

	/**
	 * \brief Helper alias for 3D vectors of type unsigned int.
	 * \addtogroup VectorCore
	 */
	using vec3u = VectorT<3, unsigned int, qualifier::defaultp>;

	/**
	 * \brief Helper alias for 3D vectors of type bool.
	 * \addtogroup VectorCore
	 */
	using vec3b = VectorT<3, bool, qualifier::defaultp>;

	/**
	 * \brief Helper alias for 3D vectors of type half.
	 * \addtogroup VectorCore
	 */
	using vec3h = VectorT<3, half, qualifier::defaultp>;

	using highp_vec3 = VectorT<3, float, qualifier::highp>;
	using highp_vec3f = VectorT<3, float, qualifier::highp>;
	using highp_vec3d = VectorT<3, double, qualifier::highp>;
	using highp_vec3i = VectorT<3, int, qualifier::highp>;
	using highp_vec3u = VectorT<3, unsigned int, qualifier::highp>;
	using highp_vec3b = VectorT<3, bool, qualifier::highp>;

	using mediump_vec3 = VectorT<3, float, qualifier::mediump>;
	using mediump_vec3f = VectorT<3, float, qualifier::mediump>;
	using mediump_vec3d = VectorT<3, double, qualifier::mediump>;
	using mediump_vec3i = VectorT<3, int, qualifier::mediump>;
	using mediump_vec3u = VectorT<3, unsigned int, qualifier::mediump>;
	using mediump_vec3b = VectorT<3, bool, qualifier::mediump>;

	using lowp_vec3 = VectorT<3, float, qualifier::lowp>;
	using lowp_vec3f = VectorT<3, float, qualifier::lowp>;
	using lowp_vec3d = VectorT<3, double, qualifier::lowp>;
	using lowp_vec3i = VectorT<3, int, qualifier::lowp>;
	using lowp_vec3u = VectorT<3, unsigned int, qualifier::lowp>;
	using lowp_vec3b = VectorT<3, bool, qualifier::lowp>;

} // namespace mim
