// Copyright (c) 2023-Present Mim contributors (see LICENSE)

/**
 * @file cmath.hpp
 * @brief mim cmath provides a set of math functions from the standard cmath library implemented in constexpr.
 *
 * This is not a comprehensive implementation of the cmath library, but rather a set of functions that are
 * useful for mim that are needed to be constexpr.
 */

#pragma once

#include <limits>
#include <type_traits>
#include <cmath>

namespace mim::math
{
	template <typename T>
	[[nodiscard]] constexpr bool isnan(const T& val) noexcept
	{
        return val != val;
	}

	template <typename T>
	[[nodiscard]] constexpr T abs(const T& val) noexcept
	{
		return (val >= 0) ? val : -val;
	}

	template <typename T, typename... Args>
	[[nodiscard]] constexpr auto min(const T&& a, const T&& b, const Args&&... args) noexcept
		-> std::enable_if_t<std::is_arithmetic_v<T>, T>
    {
        if constexpr (sizeof...(args) == 0) {
            return (a < b) ? std::forward<T>(a) : std::forward<T>(b);
        } else {
            return ::mim::math::min(::mim::math::min(std::forward<T>(a), std::forward<T>(b)), std::forward<Args>(args)...);
        }
    }

	template <typename T, typename... Args>
	[[nodiscard]] constexpr auto min(T&& a, T&& b, Args&&... args) noexcept
		-> std::enable_if_t<std::is_arithmetic_v<T>, T>
    {
        if constexpr (sizeof...(args) == 0) {
            return (a < b) ? std::forward<T>(a) : std::forward<T>(b);
        } else {
            return ::mim::math::min(::mim::math::min(std::forward<T>(a), std::forward<T>(b)), std::forward<Args>(args)...);
        }
    }

	template <typename T, typename... Args>
	[[nodiscard]] constexpr auto max(const T&& a, const T&& b, const Args&&... args) noexcept
		-> std::enable_if_t<std::is_arithmetic_v<T>, T>
	{
		if constexpr (sizeof...(args) == 0) {
			return (a < b) ? std::forward<T>(b) : std::forward<T>(a);
		} else {
			return ::mim::math::max(::mim::math::max(std::forward<T>(a), std::forward<T>(b)), std::forward<Args>(args)...);
		}

	}

	template <typename T, typename... Args>
	[[nodiscard]] constexpr auto max(T&& a, T&& b, Args&&... args) noexcept
		-> std::enable_if_t<std::is_arithmetic_v<T>, T>
    {
		if constexpr (sizeof...(args) == 0) {
			return (a < b) ? std::forward<T>(b) : std::forward<T>(a);
		} else {
			return ::mim::math::max(::mim::math::max(std::forward<T>(a), std::forward<T>(b)), std::forward<Args>(args)...);
		}
    }

	namespace detail
	{
		template <typename T>
		[[nodiscard]] constexpr bool isclose(T a, T b, T epsilon = std::numeric_limits<T>::epsilon()) noexcept
		{
			return ::mim::math::abs(a - b) <= epsilon * ::mim::math::max(::mim::math::abs(a), ::mim::math::abs(b));
		}

        template <typename T>
		[[nodiscard]] constexpr T sqrt_helper(T x, T y) noexcept
        {
            return ::mim::math::detail::isclose(x, y*y) ? y : sqrt_helper(x, (y + x/y) / 2);
        }
	}

	template <typename T>
	[[nodiscard]] constexpr auto clamp(const T& val, const T& lo, const T& hi) noexcept
		-> std::enable_if_t<std::is_arithmetic_v<T>, T>
	{
		return ::mim::math::min(::mim::math::max(val, lo), hi);
	}

	template <typename T>
	[[nodiscard]] constexpr T sqrt(T x) noexcept
    {
        return ::mim::math::detail::sqrt_helper(x, x);
    }

	template <typename T>
	[[nodiscard]] constexpr bool isclose(T a, T b, T epsilon = std::numeric_limits<T>::epsilon()) noexcept
    {
        return ::mim::math::detail::isclose(a, b, epsilon);
    }

	// TODO: Implement sine and cosine functions as constexpr.

} // namespace mim
