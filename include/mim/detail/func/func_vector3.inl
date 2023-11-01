// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#include "mim/detail/compute/compute_functors.hpp"
#include "mim/detail/defines.hpp"

#include "mim/mimConstants.hpp"
#include "mim/cmath.hpp"

namespace mim
{

	/// Member functions

	template <typename T>
	constexpr vec<3, T> vec<3, T>::inverse() const
	{
		static_assert(std::is_floating_point<T>::value, "Cannot use inverse() on a non-floating-point vector.");
		return vec<3, T>(T{ 1 } / x, T{ 1 } / y, T{ 1 } / z);
	}

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
		static_assert(std::is_arithmetic<T>::value, "Cannot use the dot product on a non-arithmetic vector.");
		return x * v.x + y * v.y + z * v.z;
	}

	template <typename T>
	constexpr vec<3, T> vec<3, T>::cross(const vec<3, T>& v) const
	{
		static_assert(std::is_floating_point<T>::value, "Cannot use the cross product on a non-floating-point vector.");
		return vec<3, T>(
			x.y * y.z - y.y * x.z,
			x.z * y.x - y.z * x.x,
			x.x * y.y - y.x * x.y
		);
	}

	template <typename T>
	constexpr vec<3, T> vec<3, T>::hadamard(const vec<3, T>& v) const
	{
		static_assert(std::is_arithmetic<T>::value, "Cannot use hadamard() on a non-arithmetic vector.");
		return vec<3, T>(x * v.x, y * v.y, z * v.z);
	}

	template <typename T>
	constexpr void vec<3, T>::rotate(const vec<3, T>& axis, T angle)
	{
		static_assert(std::is_floating_point<T>::value, "Cannot rotate a non-floating-point vector.");

		// Rotation matrix from https://en.wikipedia.org/wiki/Rotation_matrix#Rotation_matrix_from_axis_and_angle

		// The provided axis must be normalized.
		// TODO: Maybe add in a means to tell the function the axis is already normalized?
		axis.normalize();

		// the unit matrix will become the rotational matrix
		vec<3, T> unitMatrix[3] = {
			vec<3, T>(1, 0, 0),
			vec<3, T>(0, 1, 0),
			vec<3, T>(0, 0, 1)
		};

		vec<3, T> axisSqr(axis.x * axis.x, axis.y * axis.y, axis.z * axis.z);
		T cosAngle = std::cos(angle);

		unitMatrix[0][0] = axisSqr.x + (1 - axisSqr.x) * cosAngle;
		unitMatrix[1][1] = axisSqr.y + (1 - axisSqr.y) * cosAngle;
		unitMatrix[2][2] = axisSqr.z + (1 - axisSqr.z) * cosAngle;

		T sinAngle = std::sin(angle);
		T t = 1 - cosAngle;

		T xyzt = axis.x * axis.y * t;
		T zyxs = axis.z * sinAngle;
		unitMatrix[0][1] = xyzt - zyxs;
		unitMatrix[1][0] = xyzt + zyxs;

		xyzt = axis.x * axis.z * t;
		zyxs = axis.y * sinAngle;
		unitMatrix[0][2] = xyzt + zyxs;
		unitMatrix[2][0] = xyzt - zyxs;

		xyzt = axis.y * axis.z * t;
		zyxs = axis.x * sinAngle;
		unitMatrix[1][2] = xyzt - zyxs;
		unitMatrix[2][1] = xyzt + zyxs;

		*this = vec<3, T>(
			unitMatrix[0].dot(*this),
			unitMatrix[1].dot(*this),
			unitMatrix[2].dot(*this)
		);
	}

	template <typename T>
	constexpr vec<3, T> vec<3, T>::rotated(T angle) const
	{
		static_assert(std::is_floating_point<T>::value, "Cannot rotate a non-floating-point vector.");
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
	constexpr vec<3, T> vec<3, T>::project(const vec<3, T>& normal) const
	{
		static_assert(std::is_arithmetic<T>::value, "Cannot use project() on a non-arithmetic vector.");
		// TODO: Validate this function.
		return normal * (this->dot(normal) / normal.length_squared());
	}



	/// Free functions

	template <typename T>
	constexpr vec<3, T> inverse(const vec<3, T>& v)
	{
		static_assert(std::is_floating_point<T>::value, "Cannot use inverse() on a non-floating-point vector.");
		return vec<3, T>(T{ 1 } / v.x, T{ 1 } / v.y, T{ 1 } / v.z);
	}

	template <typename T>
	constexpr T length(const vec<3, T>& v)
	{
		static_assert(std::is_arithmetic<T>::value, "Cannot use length() on a non-arithmetic vector.");
		return v.length();
	}

	template <typename T>
	constexpr T length_squared(const vec<3, T>& v)
	{
		static_assert(std::is_arithmetic<T>::value, "Cannot use length_squared() on a non-arithmetic vector.");
		return v.length_squared();
	}

	template <typename T>
	constexpr vec<3, T> normalized(const vec<3, T>& v)
	{
		static_assert(std::is_floating_point<T>::value, "Cannot normalize a non-floating-point vector.");
		return v.normalized();
	}

	template <typename T>
	constexpr bool is_normalized(const vec<3, T>& v)
	{
		static_assert(std::is_floating_point<T>::value, "Cannot normalize a non-floating-point vector.");
		return v.is_normalized();
	}

	template <typename T>
	constexpr vec<3, T> distance(const vec<3, T>& v1, const vec<3, T>& v2)
	{
		static_assert(std::is_arithmetic<T>::value, "Cannot use distance() on a non-arithmetic vector.");
		return v1.distance(v2);
	}

	template <typename T>
	constexpr vec<3, T> distance_squared(const vec<3, T>& v1, const vec<3, T>& v2)
	{
		static_assert(std::is_arithmetic<T>::value, "Cannot use distance_squared() on a non-arithmetic vector.");
		return v1.distance_squared(v2);
	}

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
			v1.y * v2.z - v2.y * v1.z,
			v1.z * v2.x - v2.z * v1.x,
			v1.x * v2.y - v2.x * v1.y
		);

    }

	template <typename T>
	constexpr vec<3, T> hadamard(const vec<3, T>& v1, const vec<3, T>& v2)
	{
		static_assert(std::is_arithmetic<T>::value, "Cannot use hadamard() on a non-arithmetic vector.");
		return vec<3, T>(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);
	}

	template <typename T>
	constexpr vec<3, T> rotated(const vec<3, T>& v, T angle)
	{
		static_assert(std::is_floating_point<T>::value, "Cannot rotate a non-floating-point vector.");
		return v.rotated(angle);
	}

	template <typename T>
	constexpr vec<3, T> clamp(const vec<3, T>& v, const vec<3, T>& min, const vec<3, T>& max)
	{
		static_assert(std::is_arithmetic<T>::value, "Cannot use clamp() on a non-arithmetic vector.");
		return vec<3, T>(
			::mim::math::clamp(v.x, min.x, max.x),
			::mim::math::clamp(v.y, min.y, max.y),
			::mim::math::clamp(v.z, min.z, max.z)
		);
	}

	template <typename T>
	constexpr vec<3, T> reflect(const vec<3, T>& v, const vec<3, T>& normal)
	{
		static_assert(std::is_arithmetic<T>::value, "Cannot use reflect() on a non-arithmetic vector.");
		return v.reflect(normal);
	}

	template <typename T>
	constexpr vec<3, T> refract(const vec<3, T>& v, const vec<3, T>& normal, T eta)
	{
		static_assert(std::is_arithmetic<T>::value, "Cannot use refract() on a non-arithmetic vector.");
		return v.refract(normal, eta);
	}

	template <typename T>
	constexpr vec<3, T> project(const vec<3, T>& v, const vec<3, T>& normal)
	{
		static_assert(std::is_arithmetic<T>::value, "Cannot use project() on a non-arithmetic vector.");
		return v.project(normal);
	}

}
