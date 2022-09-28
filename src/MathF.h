#pragma once

#include <numbers>
#include <cmath>
#include <algorithm>

namespace mathF
{
    template<typename T> inline constexpr T PI = std::numbers::pi_v<T>;
    template<typename T> inline constexpr T TwoPI = std::numbers::pi_v<T> * T{2};
    template<typename T> inline constexpr T Tau = std::numbers::pi_v<T> * T{2};
    template<typename T> inline constexpr T HalfPI = std::numbers::pi_v<T> / T{2};
    template<typename T> inline constexpr T QuarterPI = std::numbers::pi_v<T> / T{4};
    template<typename T> inline constexpr T E = std::numbers::e_v<T>;
    template<typename T> inline constexpr T Log10E = std::log(E<T>);
    template<typename T> inline constexpr T Log2E = std::log(E<T>, T{2});
    template<typename T> inline constexpr T Deg2Rad = PI<T> * T{2} / T{360};
    template<typename T> inline constexpr T Rad2Deg = T{1} / Deg2Rad<T>;
    template<typename T> inline constexpr T MinValue = std::numeric_limits<T>::min();
    template<typename T> inline constexpr T MaxValue = std::numeric_limits<T>::max();
    template<typename T> inline constexpr T Infinity = std::numeric_limits<T>::infinity();
    /** IEEE 754 is required for this to work. It should be fine though since we are using c++20 */
    template<typename T> inline constexpr T NegativeInfinity = T{-1} * std::numeric_limits<T>::infinity();
    template<typename T> inline constexpr T qNaN = std::numeric_limits<T>::quiet_NaN();
    template<typename T> inline constexpr T sNaN = std::numeric_limits<T>::signaling_NaN();
    template<typename T> inline constexpr T Epsilon = std::numeric_limits<T>::epsilon();
    template<typename T> [[maybe_unused]] inline constexpr T ϵ = std::numeric_limits<T>::epsilon();

    /**
     * Free Functions for general generic math
     */

    // This is so we can constrain the usable values
    template <typename T>
    concept VecTypes = std::floating_point<T> || (std::integral<T> && !std::same_as<T, bool>);

    // constexpr Vector3 Normalize() const noexcept requires std::floating_point<T>

    template <VecTypes T>
    constexpr inline T Clamp(T const& value, T const& min, T const& max) {
        return std::clamp<T>(value, min, max);
    }

    template <VecTypes T>
    constexpr inline T Clamp01(T const& value) {
        if (value < T{}) {
            return T{}; // Should return zero
        } else {
            return (value > T{1})
                   ? T{1}
                   : value;
        }
    }

    template <VecTypes T>
    constexpr inline T Lerp(T a, T b, T t) {
        return std::lerp(a, b, t);
    }

    template <VecTypes T>
    constexpr inline T LerpClamped(T a, T b, T t) {
        return a + (b - a) * Clamp01<T>(t);
    }
	
	template <VecTypes T>
	constexpr inline T LerpAngle(T a, T b, T t) {
		auto num = Repeat(b - a, T{360});
		if (num > T{-180})
			num -= T{360};
		return a + num * Clamp01(t);
	}
		

    // Repeats the value t, so t is never larger than length and never smaller than 0.
    template <VecTypes T>
    constexpr inline T Repeat(T t, T length) {
        return t - std::floor(t / length) * length;
    }

    template <VecTypes T>
    constexpr inline T PingPong(T t, T length) {
        t = Repeat(t, length * T{2});
        return length - std::abs(t - length);
    }

    template <VecTypes T>
    constexpr inline T DeltaAngle(T current, T target) {
        auto num = Repeat(target - current, T{360});
        if (num > T{180})
            num -= T{360};

        return num;
    }

    template <VecTypes T>
    constexpr inline T SmoothStep(T from, T to, T t) {
        t = Clamp01(t);
        t = -T{2} * t * t * t + T{3} * t * t;
        return to * t + from * (T{1} - t);
    }



}
