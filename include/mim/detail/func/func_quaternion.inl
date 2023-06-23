// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#include <cmath>
#include "mim/mimMath.hpp"


namespace mim
{

	template <typename T, qualifier Q>
	constexpr bool Quaternion<T, Q>::isfinite() const
    {
		using mim::math::isfinite;
        return isfinite(w) && isfinite(x) && isfinite(y) && isfinite(z);
    }

	template <typename T, qualifier Q>
	constexpr T Quaternion<T, Q>::length() const
    {
        return math::sqrt(w * w + x * x + y * y + z * z);
    }

	template <typename T, qualifier Q>
	constexpr void Quaternion<T, Q>::normalize()
    {
        T len = length();
        if (len > 0)
        {
            T invLen = 1 / len;
            w *= invLen;
            x *= invLen;
            y *= invLen;
            z *= invLen;
        }
    }

	template <typename T, qualifier Q>
	constexpr Quaternion<T, Q> Quaternion<T, Q>::normalized() const
    {
        T len = length();
        if (len > 0)
        {
            T invLen = 1 / len;
            return Quaternion<T, Q>(w * invLen, x * invLen, y * invLen, z * invLen);
        }
        return Quaternion<T, Q>(0, 0, 0, 0);
    }

	template <typename T, qualifier Q>
	constexpr bool Quaternion<T, Q>::is_normalized() const
    {
        return mim::math::abs(length() - 1) < MIM_UNIT_EPSILON<T>;
    }

	template <typename T, qualifier Q>
	constexpr Quaternion<T, Q> Quaternion<T, Q>::inverse() const
	{
		T len = length();
        if (len > 0)
        {
            T invLen = 1 / len;
            return Quaternion<T, Q>(w * invLen, -x * invLen, -y * invLen, -z * invLen);
        }
        return Quaternion<T, Q>(0, 0, 0, 0);
	}
}
