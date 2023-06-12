// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#pragma once

#include <limits>

namespace mim
{
	template <typename T = float>
	const T MIM_PI = static_cast<T>(3.141592653589793238462643);
	template <typename T = float>
	const T MIM_2PI = static_cast<T>(6.283185307179586476925287);
	template <typename T = float>
	const T MIM_TAU = static_cast<T>(6.283185307179586476925287);
	template <typename T = float>
	const T MIM_E = static_cast<T>(2.7182818284590452353602874714);

	template <typename T = float>
	const T MIM_EPSILON = std::numeric_limits<T>::epsilon();

	template <typename T>
	const T MIM_UNIT_EPSILON = T{0.00001};

} // namespace mim
