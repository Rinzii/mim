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
#include <algorithm>

#include "mim/mimConstants.hpp"

namespace mim::math
{

	template <typename T>
	[[nodiscard]] constexpr bool isnan(const T& val) noexcept
	{
        return val != val;
	}

	template <typename T>
	[[nodiscard]] constexpr bool isnan(T& val) noexcept
	{
		return val != val;
	}

	template <typename T>
	[[nodiscard]] constexpr T abs(const T& val) noexcept
	{
		static_assert(std::is_arithmetic<T>::value, "abs() requires an arithmetic type.");
		return val == 0 ? 0 : (val < 0 ? -val : val);
	}

	template <typename T>
	[[nodiscard]] constexpr T abs(T& val) noexcept
	{
		static_assert(std::is_arithmetic<T>::value, "abs() requires an arithmetic type.");
		return val == 0 ? 0 : (val < 0 ? -val : val);
	}

	namespace detail
	{
		template <typename T>
		[[nodiscard]] constexpr bool isclose(T a, T b, T epsilon = std::numeric_limits<T>::epsilon()) noexcept
		{
			static_assert(std::is_arithmetic<T>::value, "isclose() requires an arithmetic type.");
			return ::mim::math::abs(a - b) <= epsilon * std::max(::mim::math::abs(a), ::mim::math::abs(b));
		}

        template <typename T>
		[[nodiscard]] constexpr T sqrt_helper(T x, T y) noexcept
        {
            return ::mim::math::detail::isclose(x, y*y) ? y : sqrt_helper(x, (y + x/y) / 2);
        }
	}

	template <typename T>
	[[nodiscard]] constexpr auto clamp(const T& val, const T& lo, const T& hi) noexcept
	{
		static_assert(std::is_arithmetic<T>::value, "clamp() requires an arithmetic type.");
		return std::min(std::max(val, lo), hi);
	}

	template <typename T>
	[[nodiscard]] constexpr T sqrt(T x) noexcept
    {
		static_assert(std::is_arithmetic<T>::value, "sqrt() requires an arithmetic type.");
        return ::mim::math::detail::sqrt_helper(x, x);
    }

	template <typename T>
	[[nodiscard]] constexpr bool isclose(T a, T b, T epsilon = std::numeric_limits<T>::epsilon()) noexcept
    {
        return ::mim::math::detail::isclose(a, b, epsilon);
    }

	namespace detail
	{
		template <typename T>
		[[nodiscard]] constexpr T compute_sine(const T x) noexcept
		{
			static_assert(std::is_floating_point<T>::value, "Cannot compute sine of a non-floating-point value.");
			T{2} * x / (T{1} + x * x);
		}

		template <typename T>
		[[nodiscard]] constexpr T sin_impl(const T x) noexcept
		{
			static_assert(std::is_floating_point<T>::value, "Cannot compute sine of a non-floating-point value.");
			return
				::mim::math::isnan(x) ? std::numeric_limits<T>::quiet_NaN() : std::numeric_limits<T>::min();
		}
	}

	// TODO: Implement sine and cosine functions as constexpr.

} // namespace mim
