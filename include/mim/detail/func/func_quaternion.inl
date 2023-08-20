// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#include <cmath>
#include "mim/cmath.hpp"
#include "mim/mimConstants.hpp"


namespace mim
{

	/// Member functions

	template <typename T, qualifier Q>
	constexpr T quat<T, Q>::length() const
    {
        return ::mim::math::sqrt(w * w + x * x + y * y + z * z);
    }

	template <typename T, qualifier Q>
	constexpr void quat<T, Q>::normalize()
    {
        T len = this->length();
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
	constexpr quat<T, Q> quat<T, Q>::normalized() const
    {
        T len = this->length();
        if (len > 0)
        {
            T invLen = 1 / len;
            return quat<T, Q>(w * invLen, x * invLen, y * invLen, z * invLen);
        }
        return quat<T, Q>(0, 0, 0, 0);
    }

	template <typename T, qualifier Q>
	constexpr bool quat<T, Q>::is_normalized() const
    {
        return ::mim::math::abs(this->length() - 1) < MIM_UNIT_EPSILON<T>;
    }

	template <typename T, qualifier Q>
	constexpr quat<T, Q> quat<T, Q>::inverse() const
	{
		T len = this->length();
        if (len > 0)
        {
            T invLen = 1 / len;
            return quat<T, Q>(w * invLen, -x * invLen, -y * invLen, -z * invLen);
        }
        return quat<T, Q>(0, 0, 0, 0);
	}


	/// Free functions

    template <typename T, qualifier Q>
    constexpr quat<T, Q> normalize(const quat<T, Q>& q)
    {
        return q.normalized();
    }
}
