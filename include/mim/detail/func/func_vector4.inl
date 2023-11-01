// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#include "mim/cmath.hpp"
#include "mim/mimConstants.hpp"

namespace mim
{
	/// Member Functions

    template <typename T>
    constexpr T vec<4, T>::length() const
    {
		static_assert(std::is_arithmetic<T>::value, "Cannot use length() on a non-arithmetic vector.");
        return mim::math::sqrt(x * x + y * y + z * z + w * w);
    }

    template <typename T>
    constexpr T vec<4, T>::length_squared() const
    {
		static_assert(std::is_arithmetic<T>::value, "Cannot use length_squared() on a non-arithmetic vector.");
        return x * x + y * y + z * z + w * w;
    }

    template <typename T>
    constexpr void vec<4, T>::normalize()
    {
        static_assert(std::is_floating_point<T>::value, "Cannot normalize a non-floating-point vector.");

        T len = length_squared();
        if (len != 0)
        {
            len = mim::math::sqrt(len);
            x /= len;
            y /= len;
            z /= len;
            w /= len;
        }
    }

    template <typename T>
    constexpr vec<4, T> vec<4, T>::normalized() const
    {
        static_assert(std::is_floating_point<T>::value, "Cannot normalize a non-floating-point vector.");

        vec<4, T> v = *this;
        v.normalize();
        return v;
    }

    template <typename T>
    constexpr bool vec<4, T>::is_normalized() const
    {
        static_assert(std::is_floating_point<T>::value, "Cannot normalize a non-floating-point vector.");

        // We want to use length_squared() over length() to avoid the use of sqrt.
        return ::mim::math::isclose(length_squared(), T{ 1 }, MIM_UNIT_EPSILON<T>);
    }

    template <typename T>
    constexpr T vec<4, T>::distance(const vec<4, T>& v) const
    {
		static_assert(std::is_arithmetic<T>::value, "Cannot use distance() on a non-arithmetic vector.");
        return ::mim::math::sqrt((x - v.x) * (x - v.x) + (y - v.y) * (y - v.y) + (z - v.z) * (z - v.z) + (w - v.w) * (w - v.w));
    }

    template <typename T>
    constexpr T vec<4, T>::distance_squared(const vec<4, T>& v) const
    {
		static_assert(std::is_arithmetic<T>::value, "Cannot use distance_squared() on a non-arithmetic vector.");
        return (x - v.x) * (x - v.x) + (y - v.y) * (y - v.y) + (z - v.z) * (z - v.z) + (w - v.w) * (w - v.w);
    }

	template <typename T>
	constexpr T vec<4, T>::dot(const vec<4, T>& v) const
	{
		static_assert(std::is_arithmetic<T>::value, "Cannot use dot() on a non-arithmetic vector.");
		return x * v.x + y * v.y + z * v.z + w * v.w;
	}

	template <typename T>
	constexpr vec<4, T> vec<4, T>::hadamard(const vec<4, T>& v) const
	{
		static_assert(std::is_arithmetic<T>::value, "Cannot use hadamard() on a non-arithmetic vector.");
		return vec<4, T>(x * v.x, y * v.y, z * v.z, w * v.w);
	}

	template <typename T>
	constexpr vec<4, T> vec<4, T>::clamp(const vec<4, T> & min, const vec<4, T> & max) const
	{
		static_assert(std::is_arithmetic<T>::value, "Cannot use clamp() on a non-arithmetic vector.");
		return vec<4, T>(
			::mim::math::clamp(x, min.x, max.x),
			::mim::math::clamp(y, min.y, max.y),
			::mim::math::clamp(z, min.z, max.z),
			::mim::math::clamp(w, min.w, max.w)
		);
	}


	/// Free functions

	template <typename T>
	constexpr T length(const vec<4, T>& v)
	{
		static_assert(std::is_arithmetic<T>::value, "Cannot use length() on a non-arithmetic vector.");
		return v.length();
	}

	template <typename T>
	constexpr T length_squared(const vec<4, T>& v)
	{
		static_assert(std::is_arithmetic<T>::value, "Cannot use length_squared() on a non-arithmetic vector.");
		return v.length_squared();
	}

	template <typename T>
	constexpr vec<4, T> normalized(const vec<4, T>& v)
	{
		static_assert(std::is_arithmetic<T>::value, "Cannot use normalized() on a non-arithmetic vector.");
		return v.normalized();
	}

	template <typename T>
	MIM_NODISCARD constexpr bool is_normalized(const vec<4, T>& v)
	{
		static_assert(std::is_arithmetic<T>::value, "Cannot use is_normalized() on a non-arithmetic vector.");
		return v.is_normalized();
	}

	template <typename T>
	constexpr T distance(const vec<4, T>& v1, const vec<4, T>& v2)
	{
		static_assert(std::is_arithmetic<T>::value, "Cannot use distance() on a non-arithmetic vector.");
		return v1.distance(v2);
	}

	template <typename T>
	constexpr T distance_squared(const vec<4, T>& v1, const vec<4, T>& v2)
	{
		static_assert(std::is_arithmetic<T>::value, "Cannot use distance_squared() on a non-arithmetic vector.");
		return v1.distance_squared(v2);
	}

	template <typename T>
	constexpr T dot(const vec<4, T>& v1, const vec<4, T>& v2)
	{
		static_assert(std::is_arithmetic<T>::value, "Cannot use dot() on a non-arithmetic vector.");
		return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
	}

	template <typename T>
	constexpr vec<4, T> hadamard(const vec<4, T>& v1, const vec<4, T>& v2)
	{
		static_assert(std::is_arithmetic<T>::value, "Cannot use hadamard() on a non-arithmetic vector.");
		return vec<4, T>(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z, v1.w * v2.w);
	}


}
