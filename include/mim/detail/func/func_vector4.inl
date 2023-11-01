// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#include "mim/cmath.hpp"
#include "mim/mimConstants.hpp"

namespace mim
{
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

}
