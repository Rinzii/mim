// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#include "mim/detail/compute/compute_functors.hpp"
#include "mim/detail/compute/compute_vector.hpp"
#include "mim/detail/defines.hpp"

#include "mim/mimConstants.hpp"
#include "mim/cmath.hpp"

namespace mim
{

	/// Member functions

	template <typename T>
	constexpr T vec<3, T>::length() const
    {
		static_assert(std::is_arithmetic<T>::value, "Cannot use length() on a non-arithmetic vector.");
        return ::mim::math::sqrt(x * x + y * y + z * z);
    }

	template <typename T>
	constexpr T vec<3, T>::length_squared() const
    {
		static_assert(std::is_arithmetic<T>::value, "Cannot use length_squared() on a non-arithmetic vector.");
        return x * x + y * y + z * z;
    }

	template <typename T>
	constexpr void vec<3, T>::normalize()
	{
		static_assert(std::is_floating_point<T>::value, "Cannot normalize a non-floating-point vector.");

		T len = length_squared();
		if (len != 0)
		{
			len = ::mim::math::sqrt(len);
			x /= len;
			y /= len;
			z /= len;
		}
	}

	template <typename T>
	constexpr vec<3, T> vec<3, T>::normalized() const
	{
		static_assert(std::is_floating_point<T>::value, "Cannot normalize a non-floating-point vector.");

		vec<3, T> v = *this;
		v.normalize();
		return v;
	}

	template <typename T>
	constexpr bool vec<3, T>::is_normalized() const
	{
		static_assert(std::is_floating_point<T>::value, "Cannot normalize a non-floating-point vector.");

		// We want to use length_squared() over length() to avoid the use of sqrt.
		return ::mim::math::isclose(length_squared(), T{ 1 }, MIM_UNIT_EPSILON<T>);
	}

	template <typename T>
	constexpr T vec<3, T>::distance(const vec<3, T>& v) const
    {
		static_assert(std::is_arithmetic<T>::value, "Cannot use distance() on a non-arithmetic vector.");
        return ::mim::math::sqrt((x - v.x) * (x - v.x) + (y - v.y) * (y - v.y) + (z - v.z) * (z - v.z));
    }

	template <typename T>
	constexpr T vec<3, T>::distance_squared(const vec<3, T>& v) const
    {
		static_assert(std::is_arithmetic<T>::value, "Cannot use distance_squared() on a non-arithmetic vector.");
        return (x - v.x) * (x - v.x) + (y - v.y) * (y - v.y) + (z - v.z) * (z - v.z);
    }

	template <typename T>
	constexpr T vec<3, T>::dot(const vec<3, T>& v) const
	{
		return x * v.x + y * v.y + z * v.z;
	}

	template <typename T>
	constexpr T vec<3, T>::cross(const vec<3, T>& v) const
	{
		static_assert(std::is_arithmetic<T>::value, "Cannot use the dot product on a non-arithmetic vector.");
		return x * v.y - y * v.x - z * v.z;
	}

	template <typename T>
	constexpr void vec<3, T>::rotate(T angle)
	{
		// This may require floats only instead of all arithmetic types.
		static_assert(std::is_arithmetic<T>::value, "Cannot rotate a non-arithmetic vector.");
		// TODO: Implement rotation of a vec3 using Euler angles.

	}

	template <typename T>
	constexpr vec<3, T> vec<3, T>::rotated(T angle) const
	{
		static_assert(std::is_arithmetic<T>::value, "Cannot rotate a non-arithmetic vector.");
        vec<3, T> v = *this;
		v.rotate(angle);
		return v;

	}

	template <typename T>
	constexpr vec<3, T> vec<3, T>::clamp(const vec<3, T>& min, const vec<3, T>& max) const
	{
		static_assert(std::is_arithmetic<T>::value, "Cannot use clamp() on a non-arithmetic vector.");
		return vec<3, T>(
			::mim::math::clamp(x, min.x, max.x),
			::mim::math::clamp(y, min.y, max.y),
			::mim::math::clamp(z, min.z, max.z)
		);
	}

	template <typename T>
	constexpr vec<3, T> vec<3, T>::reflect(const vec<3, T>& normal) const
	{
		static_assert(std::is_arithmetic<T>::value, "Cannot use reflect() on a non-arithmetic vector.");
		T factor = T{ -2 } * normal.dot(*this);

		return vec<3, T>(
            factor * normal.x + x,
            factor * normal.y + y,
            factor * normal.z + z
        );
	}

	template <typename T>
	constexpr vec<3, T> vec<3, T>::refract(const vec<3, T>& normal, T eta) const
	{
		static_assert(std::is_arithmetic<T>::value, "Cannot use refract() on a non-arithmetic vector.");
		// TODO: Validate this function.

		T dot = normal.dot(*this);
        T k = T{ 1 } - eta * eta * (T{ 1 } - dot * dot);

        if (k < T{ 0 })
        {
            return vec<3, T>{};
        }
        else
        {
            return eta * (*this) - (eta * dot + ::mim::math::sqrt(k)) * normal;
        }
	}

	template <typename T>
	constexpr vec<3, T> vec<3, T>::project(const vec<3, T>& to) const
	{
		static_assert(std::is_arithmetic<T>::value, "Cannot use project() on a non-arithmetic vector.");
		// TODO: Validate this function.
		return to * (this->dot(to) / to.length_squared());
	}



	/// Free functions

	template <typename T>
	constexpr vec<3, T> dot(const vec<3, T>& v1, const vec<3, T>& v2)
    {
		static_assert(std::is_arithmetic<T>::value, "Cannot use the dot product on a non-arithmetic vector.");
        return v1.dot(v2);
    }

	template <typename T>
	constexpr vec<3, T> cross(const vec<3, T>& v1, const vec<3, T>& v2)
    {
		static_assert(std::is_arithmetic<T>::value, "Cannot use the cross product on a non-arithmetic vector.");
        return vec<3, T>(
			(v1.y * v2.z) - (v1.z * v2.y),
			-((v1.x * v2.z) - (v1.z * v2.x)),
			(v1.x * v2.y) - (v1.y * v2.x)
		);
    }

	template <typename T>
	constexpr vec<3, T> inverse(const vec<3, T>& v)
    {
		static_assert(std::is_floating_point<T>::value, "Cannot use inverse() on a non-floating-point vector.");
        return vec<3, T>(T{ 1 } / v.x, T{ 1 } / v.y, T{ 1 } / v.z);
    }
}
