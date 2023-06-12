// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#include "mim/detail/qualifier.hpp"
#include "mim/mimMath.hpp"
#include "mim/detail/compute/compute_vector.hpp"
#include "mim/detail/compute/compute_functors.hpp"

namespace mim
{
	/// Generic Functions

    template <typename T, qualifier Q>
    bool VectorT<2, T, Q>::isfinite() const
    {
        return std::isfinite(x) && std::isfinite(y);
    }

	template <typename T, qualifier Q>
	VectorT<2, T, Q> VectorT<2, T, Q>::sign() const
	{
		return VectorT<2, T, Q>(mim::math::sign(x), mim::math::sign(y));
	}

	template <typename T, qualifier Q>
	VectorT<2, T, Q> VectorT<2, T, Q>::floor() const
    {
        return VectorT<2, T, Q>(mim::math::floor(x), mim::math::floor(y));
    }

	template <typename T, qualifier Q>
	VectorT<2, T, Q> VectorT<2, T, Q>::ceil() const
    {
        return VectorT<2, T, Q>(mim::math::ceil(x), mim::math::ceil(y));
    }

	template <typename T, qualifier Q>
	VectorT<2, T, Q> VectorT<2, T, Q>::round() const
    {
        return VectorT<2, T, Q>(mim::math::round(x), mim::math::round(y));
    }

	template <typename T, qualifier Q>
	VectorT<2, T, Q> VectorT<2, T, Q>::min(const VectorT<2, T, Q>& v) const
    {
        return VectorT<2, T, Q>(mim::math::min(x, v.x), mim::math::min(y, v.y));
    }

	template <typename T, qualifier Q>
	VectorT<2, T, Q> VectorT<2, T, Q>::max(const VectorT<2, T, Q>& v) const
	{
		return VectorT<2, T, Q>(mim::math::max(x, v.x), mim::math::max(y, v.y));
	}

	template <typename T, qualifier Q>
	T VectorT<2, T, Q>::length() const
    {
        return sqrt(x * x + y * y);
    }

	template <typename T, qualifier Q>
	T VectorT<2, T, Q>::length_squared() const
    {
        return x * x + y * y;
    }

	template <typename T, qualifier Q>
	void VectorT<2, T, Q>::normalize()
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

	template <typename T, qualifier Q>
	VectorT<2, T, Q> VectorT<2, T, Q>::normalized() const
    {
        static_assert(std::is_floating_point<T>::value, "Cannot normalize a non-floating-point vector.");

        VectorT<2, T, Q> v = *this;
		v.normalize();
		return v;
    }

	template <typename T, qualifier Q>
	bool VectorT<2, T, Q>::is_normalized() const
	{
		static_assert(std::is_floating_point<T>::value, "Cannot normalize a non-floating-point vector.");

		// We want to use length_squared() over length() to avoid the use of sqrt.
		return nearlyEquals(length_squared(), T{ 1 }, MIM_UNIT_EPSILON<T>);
	}

	template <typename T, qualifier Q>
	T VectorT<2, T, Q>::distance(const VectorT<2, T, Q>& v) const
    {
        return mim::math::sqrt((x - v.x) * (x - v.x) + (y - v.y) * (y - v.y));
    }

	template <typename T, qualifier Q>
	T VectorT<2, T, Q>::distance_squared(const VectorT<2, T, Q>& v) const
    {
        return (x - v.x) * (x - v.x) + (y - v.y) * (y - v.y);
    }


	/// Functions

	template <typename T, qualifier Q>
	T VectorT<2, T, Q>::dot(const VectorT<2, T, Q>& v) const
    {
        return x * v.x + y * v.y;
    }

	template <typename T, qualifier Q>
	T VectorT<2, T, Q>::cross(const VectorT<2, T, Q>& v) const
    {
        return x * v.y - y * v.x;
    }

	template <typename T, qualifier Q>
	VectorT<2, T, Q> VectorT<2, T, Q>::rotated(T angle) const
	{
        T sine = mim::math::sin(angle);
		T cosi = mim::math::cos(angle);

		return VectorT<2, T, Q>(
			x * cosi - y * sine,
			x * sine + y * cosi
		);

	}

	template <typename T, qualifier Q>
	VectorT<2, T, Q> VectorT<2, T, Q>::clamp(const VectorT<2, T, Q>& min, const VectorT<2, T, Q>& max) const
	{
		return VectorT<2, T, Q>(
            mim::math::clamp(x, min.x, max.x),
            mim::math::clamp(y, min.y, max.y)
        );
	}

	template <typename T, qualifier Q>
	VectorT<2, T, Q> VectorT<2, T, Q>::reflect(const VectorT<2, T, Q>& normal) const
	{
		return T{ 2 } * normal * this->dot(normal) - *this;
	}

	template <typename T, qualifier Q>
	VectorT<2, T, Q> VectorT<2, T, Q>::refract(const VectorT<2, T, Q>& normal, T eta) const
    {
		auto K = T{ 1 } - eta * eta * (T{ 1 } - normal.dot(*this) * normal.dot(*this));
		if (K < T{ 0 })
			return VectorT<2, T, Q>{ 0 };
		else
			return eta * *this - (eta * normal.dot(*this) + mim::math::sqrt(K)) * normal;
    }

	template <typename T, qualifier Q>
	VectorT<2, T, Q> VectorT<2, T, Q>::project(const VectorT<2, T, Q>& to) const
    {
        return to * (this->dot(to) / to.length_squared());
    }


}
