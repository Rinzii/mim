// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#include "mim/detail/qualifier.hpp"
#include "mim/cmath.hpp"
#include "mim/mimConstants.hpp"
#include "mim/detail/compute/compute_vector.hpp"
#include "mim/detail/compute/compute_functors.hpp"

namespace mim
{

	template <typename T, qualifier Q>
	constexpr T VectorT<1, T, Q>::length() const
    {
        return sqrt(x * x);
    }

	template <typename T, qualifier Q>
	constexpr T VectorT<1, T, Q>::length_squared() const
    {
        return x * x;
    }

	template <typename T, qualifier Q>
	constexpr void VectorT<1, T, Q>::normalize()
	{
		static_assert(std::is_floating_point<T>::value, "Cannot normalize a non-floating-point vector.");

		T len = length_squared();
		if (len != 0)
		{
			len = mim::math::sqrt(len);
			x /= len;
		}
	}

	template <typename T, qualifier Q>
	constexpr VectorT<1, T, Q> VectorT<1, T, Q>::normalized() const
	{
		static_assert(std::is_floating_point<T>::value, "Cannot normalize a non-floating-point vector.");

		VectorT<1, T, Q> v = *this;
		v.normalize();
		return v;
	}

	template <typename T, qualifier Q>
	constexpr bool VectorT<1, T, Q>::is_normalized() const
    {
        static_assert(std::is_floating_point<T>::value, "Cannot normalize a non-floating-point vector.");

        return nearlyEquals(length_squared(), T{ 1 }, MIM_UNIT_EPSILON<T>);
    }

	template <typename T, qualifier Q>
	constexpr T VectorT<1, T, Q>::distance(const VectorT<1, T, Q>& v) const
    {
        return mim::math::sqrt((x - v.x) * (x - v.x));
    }

	template <typename T, qualifier Q>
	constexpr T VectorT<1, T, Q>::distance_squared(const VectorT<1, T, Q>& v) const
    {
        return (x - v.x) * (x - v.x);
    }






}
