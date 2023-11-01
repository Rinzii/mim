// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#include "mim/cmath.hpp"
#include "mim/detail/compute/compute_functors.hpp"
#include "mim/detail/defines.hpp"
#include "mim/mimConstants.hpp"

namespace mim
{

	template <typename T>
	constexpr T vec<2, T>::length() const
    {
		static_assert(std::is_arithmetic<T>::value, "Cannot use length() on a non-arithmetic vector.");
        return ::mim::math::sqrt(x * x + y * y);
    }

	template <typename T>
	constexpr T vec<2, T>::length_squared() const
    {
		static_assert(std::is_arithmetic<T>::value, "Cannot use length_squared() on a non-arithmetic vector.");
        return x * x + y * y;
    }

	template <typename T>
	constexpr void vec<2, T>::normalize()
    {
		static_assert(std::is_floating_point<T>::value, "Cannot normalize a non-floating-point vector.");

		T len = length_squared();
		if (len != 0)
		{
			len = mim::math::sqrt(len);
			x /= len;
			y /= len;
		}
    }

	template <typename T>
	constexpr vec<2, T> vec<2, T>::normalized() const
    {
        static_assert(std::is_floating_point<T>::value, "Cannot normalize a non-floating-point vector.");

        vec<2, T> v = *this;
		v.normalize();
		return v;
    }

	template <typename T>
	constexpr bool vec<2, T>::is_normalized() const
	{
		static_assert(std::is_floating_point<T>::value, "Cannot normalize a non-floating-point vector.");

		// We want to use length_squared() over length() to avoid the use of sqrt.
		return nearlyEquals(length_squared(), T{ 1 }, MIM_UNIT_EPSILON<T>);
	}

	template <typename T>
	constexpr T vec<2, T>::distance(const vec<2, T>& v) const
    {
		static_assert(std::is_arithmetic<T>::value, "Cannot use distance() on a non-arithmetic vector.");
        return ::mim::math::sqrt((x - v.x) * (x - v.x) + (y - v.y) * (y - v.y));
    }

	template <typename T>
	constexpr T vec<2, T>::distance_squared(const vec<2, T>& v) const
    {
		static_assert(std::is_arithmetic<T>::value, "Cannot use distance_squared() on a non-arithmetic vector.");
        return (x - v.x) * (x - v.x) + (y - v.y) * (y - v.y);
    }


	/// Functions

	template <typename T>
	constexpr T vec<2, T>::dot(const vec<2, T>& v) const
    {
		static_assert(std::is_arithmetic<T>::value, "Cannot use the dot product on a non-arithmetic vector.");
        return x * v.x + y * v.y;
    }

	// TODO: Implement rotate()?

	// TODO: Make this constexpr once sine and cosine are constexpr.
	template <typename T>
	vec<2, T> vec<2, T>::rotated(T angle) const
	{
		static_assert(std::is_arithmetic<T>::value, "Cannot rotate a non-arithmetic vector.");
        T sine = std::sin(angle);
		T cosi = std::cos(angle);

		return vec<2, T>(
			x * cosi - y * sine,
			x * sine + y * cosi
		);

	}

	template <typename T>
	constexpr vec<2, T> vec<2, T>::clamp(const vec<2, T>& min, const vec<2, T>& max) const
	{
		static_assert(std::is_arithmetic<T>::value, "Cannot use clamp() on a non-arithmetic vector.");
		return vec<2, T>(
            mim::math::clamp(x, min.x, max.x),
            mim::math::clamp(y, min.y, max.y)
        );
	}

	template <typename T>
	constexpr vec<2, T> vec<2, T>::reflect(const vec<2, T>& normal) const
	{
		static_assert(std::is_arithmetic<T>::value, "Cannot use reflect() on a non-arithmetic vector.");
		return T{ 2 } * normal * this->dot(normal) - *this;
	}

	template <typename T>
	constexpr vec<2, T> vec<2, T>::refract(const vec<2, T>& normal, T eta) const
    {
		static_assert(std::is_arithmetic<T>::value, "Cannot use refract() on a non-arithmetic vector.");
		auto K = T{ 1 } - eta * eta * (T{ 1 } - normal.dot(*this) * normal.dot(*this));
		if (K < T{ 0 })
			return vec<2, T>{ 0 };
		else
			return eta * *this - (eta * normal.dot(*this) + mim::math::sqrt(K)) * normal;
    }

	template <typename T>
	constexpr vec<2, T> vec<2, T>::project(const vec<2, T>& to) const
    {
		static_assert(std::is_arithmetic<T>::value, "Cannot use project() on a non-arithmetic vector.");
        return to * (this->dot(to) / to.length_squared());
    }


}
