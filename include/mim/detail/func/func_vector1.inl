// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#include "mim/cmath.hpp"
#include "mim/detail/compute/compute_functors.hpp"
#include "mim/detail/compute/compute_vector.hpp"
#include "mim/detail/defines.hpp"
#include "mim/mimConstants.hpp"

namespace mim
{

	template <typename T>
	constexpr T vec<1, T>::length() const
    {
		static_assert(std::is_arithmetic<T>::value, "Cannot use length() on a non-arithmetic vector.");
        return sqrt(x * x);
    }


	template <typename T>
	constexpr T vec<1, T>::length_squared() const
    {
		static_assert(std::is_arithmetic<T>::value, "Cannot use length_squared() on a non-arithmetic vector.");
        return x * x;
    }

	template <typename T>
	constexpr void vec<1, T>::normalize()
	{
		static_assert(std::is_floating_point<T>::value, "Cannot normalize a non-floating-point vector.");

		T len = length_squared();
		if (len != 0)
		{
			len = mim::math::sqrt(len);
			x /= len;
		}
	}

	template <typename T>
	constexpr vec<1, T> vec<1, T>::normalized() const
	{
		static_assert(std::is_floating_point<T>::value, "Cannot normalize a non-floating-point vector.");

		vec<1, T> v = *this;
		v.normalize();
		return v;
	}

	template <typename T>
	constexpr bool vec<1, T>::is_normalized() const
    {
        static_assert(std::is_floating_point<T>::value, "Cannot normalize a non-floating-point vector.");

        return nearlyEquals(length_squared(), T{ 1 }, MIM_UNIT_EPSILON<T>);
    }

	template <typename T>
	constexpr T vec<1, T>::distance(const vec<1, T>& v) const
    {
		static_assert(std::is_arithmetic<T>::value, "Cannot use distance() on a non-arithmetic vector.");
        return mim::math::abs(x - v.x);
    }

	template <typename T>
	constexpr T vec<1, T>::distance_squared(const vec<1, T>& v) const
    {
		static_assert(std::is_arithmetic<T>::value, "Cannot use distance_squared() on a non-arithmetic vector.");
        return (x - v.x) * (x - v.x);
    }






}
