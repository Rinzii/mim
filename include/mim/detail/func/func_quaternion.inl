// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#include <cmath>
#include "mim/cmath.hpp"
#include "mim/mimConstants.hpp"


namespace mim
{

	/// Member functions

	template <typename T>
	constexpr T quat<T>::length() const
    {
        return ::mim::math::sqrt(w * w + x * x + y * y + z * z);
    }

	template <typename T>
	constexpr void quat<T>::normalize()
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

	template <typename T>
	constexpr quat<T> quat<T>::normalized() const
    {
        T len = this->length();
        if (len > 0)
        {
            T invLen = 1 / len;
            return quat<T>(w * invLen, x * invLen, y * invLen, z * invLen);
        }
        return quat<T>(0, 0, 0, 0);
    }

	template <typename T>
	constexpr bool quat<T>::is_normalized() const
    {
        return ::mim::math::abs(this->length() - 1) < MIM_UNIT_EPSILON<T>;
    }

	template <typename T>
	constexpr quat<T> quat<T>::inverse() const
	{
		T len = this->length();
        if (len > 0)
        {
            T invLen = 1 / len;
            return quat<T>(w * invLen, -x * invLen, -y * invLen, -z * invLen);
        }
        return quat<T>(0, 0, 0, 0);
	}


	/// Free functions

    template <typename T>
    constexpr quat<T> normalize(const quat<T>& q)
    {
        return q.normalized();
    }
}
