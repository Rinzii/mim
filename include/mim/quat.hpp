// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#pragma once

#include "mim/half.hpp"

#include "mim/detail/type/type_quaternion.hpp"

namespace mim
{
	template <typename T = float, qualifier Q = defaultp>
	using quat = Quaternion<T, Q>;

	using quatf = Quaternion<float, defaultp>;
	using quatd = Quaternion<double, defaultp>;
}
