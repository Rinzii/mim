// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#include "mim/cmath.hpp"
#include "mim/detail/compute/compute_functors.hpp"
#include "mim/detail/defines.hpp"
#include "mim/mimConstants.hpp"

namespace mim
{
	/// Member Functions

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

	template <typename T>
	constexpr vec<1, T> vec<1, T>::hadamard(const vec<1, T> & v) const
	{
		static_assert(std::is_arithmetic<T>::value, "Cannot use hadamard() on a non-arithmetic vector.");
		return this->x * v.x;
	}

	/// Free functions

	template <typename T>
	constexpr T length(vec<1, T> const& v)
	{
		static_assert(std::is_arithmetic<T>::value, "Cannot use length() on a non-arithmetic vector.");
		return v.length();
	}

	template <typename T>
	constexpr T length_squared(vec<1, T> const& v)
	{
		static_assert(std::is_arithmetic<T>::value, "Cannot use length_squared() on a non-arithmetic vector.");
		return v.length_squared();
	}

	template <typename T>
	constexpr vec<1, T> normalized(vec<1, T> const& v)
	{
		static_assert(std::is_floating_point<T>::value, "Cannot normalize a non-floating-point vector.");
		return v.normalized();
	}

	template <typename T>
	constexpr bool is_normalized(vec<1, T> const& v)
	{
		static_assert(std::is_floating_point<T>::value, "Cannot normalize a non-floating-point vector.");
		return v.is_normalized();
	}

	template <typename T>
	constexpr T distance(vec<1, T> const& v1, vec<1, T> const& v2)
	{
		static_assert(std::is_arithmetic<T>::value, "Cannot use distance() on a non-arithmetic vector.");
		return v1.distance(v2);
	}

	template <typename T>
	constexpr T distance_squared(vec<1, T> const& v1, vec<1, T> const& v2)
	{
		static_assert(std::is_arithmetic<T>::value, "Cannot use distance_squared() on a non-arithmetic vector.");
		return v1.distance_squared(v2);
	}

	template <typename T>
	constexpr vec<1, T> hadamard(vec<1, T> const& v1, vec<1, T> const& v2)
	{
		static_assert(std::is_arithmetic<T>::value, "Cannot use hadamard() on a non-arithmetic vector.");
		return v1.hadamard(v2);
	}

}
