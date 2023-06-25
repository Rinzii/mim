// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#pragma once

#include <limits>
#include <cmath>

namespace mim::math
{
	template <typename T>
	constexpr T abs(const T& val)
	{
		return (val >= 0) ? val : -val;
	}

	template <typename T>
	constexpr T min(const T& a, const T& b)
	{
		static_assert(std::is_arithmetic<T>::value, "T must be an arithmetic type.");
		return (b < a) ? b : a;
	}

	template <typename T, typename... Args>
	constexpr T min(const T& a, const T& b, const Args&... args)
	{
		return min(min(a, b), std::forward<Args>(args)...);
	}

	template <typename T>
	constexpr T max(const T& a, const T& b)
	{
		static_assert(std::is_arithmetic<T>::value, "T must be an arithmetic type.");
		return (a < b) ? b : a;
	}

	template <typename T, typename... Args>
	constexpr T max(const T& a, const T& b, const Args&... args)
	{
		return max(max(a, b), std::forward<Args>(args)...);
	}

	namespace detail
	{
		template <typename T>
		constexpr bool is_close(T a, T b, T epsilon = std::numeric_limits<T>::epsilon()) noexcept
		{
			return mim::math::abs(a - b) <= epsilon * mim::math::max(mim::math::abs(a), mim::math::abs(b));
		}

        template <typename T>
        constexpr T sqrt_helper(T x, T y) noexcept
        {
            return is_close(x, y*y) ? y : sqrt_helper(x, (y + x/y) / 2);
        }
	}


	template <typename T>
	constexpr T clamp(const T& val, const T& min, const T& max)
	{
		return min(max(val, min), max);
	}

	template <typename T>
	constexpr T sqrt(T x) noexcept
    {
        return detail::sqrt_helper(x, x);
    }

	template <typename T>
	constexpr bool is_close(T a, T b, T epsilon = std::numeric_limits<T>::epsilon()) noexcept
    {
        return detail::is_close(a, b, epsilon);
    }

	// TODO: Implement sine and cosine functions as constexpr.

} // namespace mim
