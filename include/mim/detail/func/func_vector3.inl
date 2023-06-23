// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#include "mim/detail/qualifier.hpp"
#include "mim/mimMath.hpp"
#include "mim/detail/compute/compute_vector.hpp"
#include "mim/detail/compute/compute_functors.hpp"

namespace mim
{
	template <typename T, qualifier Q>
	constexpr bool VectorT<3, T, Q>::isfinite() const
    {
		using mim::math::isfinite;
		return isfinite(x) && isfinite(y) && isfinite(z);
    }

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> VectorT<3, T, Q>::sign() const
    {
        return VectorT<3, T, Q>(mim::math::sign(x), mim::math::sign(y), mim::math::sign(z));
    }

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> VectorT<3, T, Q>::floor() const
    {
        return VectorT<3, T, Q>(mim::math::floor(x), mim::math::floor(y), mim::math::floor(z));
    }

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> VectorT<3, T, Q>::ceil() const
    {
        return VectorT<3, T, Q>(mim::math::ceil(x), mim::math::ceil(y), mim::math::ceil(z));
    }

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> VectorT<3, T, Q>::round() const
    {
        return VectorT<3, T, Q>(mim::math::round(x), mim::math::round(y), mim::math::round(z));
    }

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> VectorT<3, T, Q>::min(const VectorT<3, T, Q>& v) const
    {
        return VectorT<3, T, Q>(mim::math::min(x, v.x), mim::math::min(y, v.y), mim::math::min(z, v.z));
    }

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> VectorT<3, T, Q>::max(const VectorT<3, T, Q>& v) const
    {
        return VectorT<3, T, Q>(mim::math::max(x, v.x), mim::math::max(y, v.y), mim::math::max(z, v.z));
    }

	template <typename T, qualifier Q>
	constexpr T VectorT<3, T, Q>::length() const
    {
        return mim::math::sqrt(x * x + y * y + z * z);
    }

	template <typename T, qualifier Q>
	constexpr T VectorT<3, T, Q>::length_squared() const
    {
        return x * x + y * y + z * z;
    }

	template <typename T, qualifier Q>
	constexpr void VectorT<3, T, Q>::normalize()
	{
		static_assert(std::is_floating_point<T>::value, "Cannot normalize a non-floating-point vector.");

		T len = length_squared();
		if (len != 0)
		{
			len = mim::math::sqrt(len);
			x /= len;
			y /= len;
			z /= len;
		}
	}

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> VectorT<3, T, Q>::normalized() const
	{
		static_assert(std::is_floating_point<T>::value, "Cannot normalize a non-floating-point vector.");

		VectorT<3, T, Q> v = *this;
		v.normalize();
		return v;
	}

	template <typename T, qualifier Q>
	constexpr bool VectorT<3, T, Q>::is_normalized() const
	{
		static_assert(std::is_floating_point<T>::value, "Cannot normalize a non-floating-point vector.");

		// We want to use length_squared() over length() to avoid the use of sqrt.
		return nearlyEquals(length_squared(), T{ 1 }, MIM_UNIT_EPSILON<T>);
	}

	template <typename T, qualifier Q>
	constexpr T VectorT<3, T, Q>::distance(const VectorT<3, T, Q>& v) const
    {
        return mim::math::sqrt((x - v.x) * (x - v.x) + (y - v.y) * (y - v.y) + (z - v.z) * (z - v.z));
    }

	template <typename T, qualifier Q>
	constexpr T VectorT<3, T, Q>::distance_squared(const VectorT<3, T, Q>& v) const
    {
        return (x - v.x) * (x - v.x) + (y - v.y) * (y - v.y) + (z - v.z) * (z - v.z);
    }


	/// Functions

	template <typename T, qualifier Q>
	constexpr T VectorT<3, T, Q>::dot(const VectorT<3, T, Q>& v) const
	{
		return x * v.x + y * v.y + z * v.z;
	}

	template <typename T, qualifier Q>
	constexpr T VectorT<3, T, Q>::cross(const VectorT<3, T, Q>& v) const
	{
		return x * v.y - y * v.x - z * v.z;
	}

	template <typename T, qualifier Q>
	constexpr void VectorT<3, T, Q>::rotate(T angle)
	{
		// TODO: Implement rotation of a vec3 using Euler angles.

	}

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> VectorT<3, T, Q>::rotated(T angle) const
	{
        VectorT<3, T, Q> v = *this;
		v.rotate(angle);
		return v;

	}

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> VectorT<3, T, Q>::clamp(const VectorT<3, T, Q>& min, const VectorT<3, T, Q>& max) const
	{
		return VectorT<3, T, Q>(
			mim::math::clamp(x, min.x, max.x),
			mim::math::clamp(y, min.y, max.y),
			mim::math::clamp(z, min.z, max.z)
		);
	}

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> VectorT<3, T, Q>::reflect(const VectorT<3, T, Q>& normal) const
	{
		T factor = T{ -2 } * normal.dot(*this);

		return VectorT<3, T, Q>(
            factor * normal.x + x,
            factor * normal.y + y,
            factor * normal.z + z
        );
	}

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> VectorT<3, T, Q>::refract(const VectorT<3, T, Q>& normal, T eta) const
	{
		// TODO: Validate this function.

		T dot = normal.dot(*this);
        T k = T{ 1 } - eta * eta * (T{ 1 } - dot * dot);

        if (k < T{ 0 })
        {
            return VectorT<3, T, Q>{};
        }
        else
        {
            return eta * *this - (eta * dot + mim::math::sqrt(k)) * normal;
        }
	}

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> VectorT<3, T, Q>::project(const VectorT<3, T, Q>& to) const
	{
		// TODO: Validate this function.
		return to * (this->dot(to) / to.length_squared());
	}
}
