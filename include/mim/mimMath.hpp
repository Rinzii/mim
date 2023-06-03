// Copyright WizWorks, Inc. All Rights Reserved.

#pragma once

#include "system/core.hpp"

#include "math/riotMathDefs.hpp"
#include "math/half.hpp"

#include "system/crt.hpp"

#include <cmath>
#include <concepts> // TODO: Try to replace the use of concepts later.



namespace mim
{


    template <typename T>
    RIOT_CONSTEXPR T degToRad(const T& deg)
    {
        return (deg * (RIOT_PI<T>) / T{ 180 });
    }

    template <typename T>
    RIOT_CONSTEXPR T radToDeg(T rad)
    {
        return (rad * T{ 180 }) / RIOT_PI<T>;
    }

    i32 floatBitsToInt32(float const& f)
    {
        union
        {
            float in;
            i32 out;
        } u;
        u.in = f;
        return u.out;
    }

    float int32BitsToFloat(i32 const& i)
    {
        union
        {
            i32 in;
            float out;
        } u;
        u.in = i;
        return u.out;
    }

    u32 floatBitsUInt32(float const& f)
    {
        union
        {
            float in;
            u32 out;
        } u;
        u.in = f;
        return u.out;
    }

    float uint32BitsToFloat(u32 const& i)
    {
        union
        {
            u32 in;
            float out;
        } u;
        u.in = i;
        return u.out;
    }



    static RIOT_CONSTEXPR int ftoiFast(float const& f)
    {
#if defined(_MSC_VER) || defined(__clang__)
        return lrintf(f);
#elif defined(__GNUC__)
        return __builtin_lrintf(f);
#elif defined(__INTEL_COMPILER)
        return _lrintf(f);
#else
        return static_cast<int>(f);
#endif

    }


    template <typename T>
    RIOT_CONSTEXPR T min(const T& a, const T& b)
    {
        RIOT_STATIC_ASSERT(std::is_arithmetic<T>::value, "T must be an arithmetic type.");
        return (b < a) ? b : a;
    }

    template <typename T, typename ... Args>
    RIOT_CONSTEXPR T min(const T& a, const T& b, const Args& ... args)
    {
        return min(min(a, b), std::forward<Args>(args)...);
    }

    template <typename T>
    RIOT_CONSTEXPR T max(const T& a, const T& b)
    {
        RIOT_STATIC_ASSERT(std::is_arithmetic<T>::value, "T must be an arithmetic type.");
        return (a < b) ? b : a;
    }

    template <typename T, typename ... Args>
    RIOT_CONSTEXPR T max(const T& a, const T& b, const Args& ... args)
    {
        return max(max(a, b), std::forward<Args>(args)...);
    }

    template <typename T>
    RIOT_CONSTEXPR T clamp(const T& val, const T& min, const T& max)
    {
        return min(max(val, min), max);
    }

    template <typename T>
    void swap(const T& a, const T& b)
    {
        ::std::swap(a, b);
    }

    template <typename T>
    RIOT_CONSTEXPR T abs(const T& val)
    {
        return ::std::abs(val);
    }

    // I've noticed slight improvements in performance with this method when handling integers.
    template <>
    RIOT_CONSTEXPR int abs<int>(const int& val)
    {
        int const mask = val >> (sizeof(int) * CHAR_BIT - 1);
        return (val ^ mask) - mask;
    }

    template <typename T>
    RIOT_CONSTEXPR T floor(const T& val)
    {
        return ::std::floor(val);
    }

    template <>
    RIOT_CONSTEXPR float floor<float>(const float& val)
    {
        return ::std::floorf(val);
    }

    template <typename T>
    RIOT_CONSTEXPR T ceil(const T& val)
    {
        return ::std::ceil(val);
    }

    template <>
    RIOT_CONSTEXPR float ceil<float>(const float& val)
    {
        return ::std::ceilf(val);
    }

    template <typename T>
    RIOT_CONSTEXPR T round(const T& val)
    {
        return ::std::round(val);
    }

    template <>
    RIOT_CONSTEXPR float round<float>(const float& val)
    {
        return ::std::roundf(val);
    }

    template <typename T>
    RIOT_CONSTEXPR T trunc(const T& val)
    {
        return ::std::trunc(val);
    }

    template <>
    RIOT_CONSTEXPR float trunc<float>(const float& val)
    {
        return ::std::truncf(val);
    }

    template <typename T>
    RIOT_CONSTEXPR T frac(const T& val)
    {
        return val - trunc(val);
    }

    template <typename T>
    RIOT_CONSTEXPR bool isnan(const T& val)
    {
        #if RIOT_COMPILER_CPP11_ENABLED
            return ::std::isnan(val);
        #elif RIOT_COMPILER_MSVC
            return _isnan(val) != 0;
        #elif (RIOT_COMPILER_GCC || RIOT_COMPILER_CLANG) && (RIOT_PLATFORM_ANDROID) && __cplusplus < 201103L
            return _isnan(val) != 0;
        #else
            return ::std::isnan(val);
        #endif
    }

    template <typename T>
    RIOT_CONSTEXPR bool isinf(const T& val)
    {
        return ::std::isinf(val);
    }

    template <typename T>
    RIOT_CONSTEXPR T sqrt(const T& val)
    {
        return ::std::sqrt(val);
    }

    template <>
    RIOT_CONSTEXPR float sqrt<float>(const float& val)
    {
        return ::std::sqrtf(val);
    }

    template <typename T>
    RIOT_CONSTEXPR T invSqrt(const T& val)
    {
        return T{ 1 } / sqrt(val);
    }

    // std::pow is relatively slow when working with floats instead of doubles. This is due to pow having to convert from double to float.
    // So we will use a custom implementation of pow for floats.
    // https://baptiste-wicht.com/posts/2017/09/cpp11-performance-tip-when-to-use-std-pow.html
    template <typename T, typename Q>
    RIOT_CONSTEXPR T pow(T& base, Q& power)
    {
        return ::std::pow<T>(base, power);
    }

    // This custom implementation is significantly faster than std::pow for integers.
    template <>
    RIOT_CONSTEXPR i32 pow<i32, i32>(i32& base, i32& power)
    {
        // TODO: Validate this implementation for correctness.
        // Iterative implementation of pow using exponentiation by squaring with bounded auxiliary space.
        // https://en.wikipedia.org/wiki/Exponentiation_by_squaring
        if (power < 0)
        {
            base /= 1;
            power = -power;
        }

        if (power == 0)
        {
            return 1;
        }

        int result = base;
        while (power > 1)
        {
            if (power & 1)
            {
                result *= base;
            }
            base *= base;
            power >>= 1;
        }

        return result;
    }

    // This custom implementation is significantly faster than std::pow for integers.
    template <>
    RIOT_CONSTEXPR u32 pow<u32, u32>(u32& base, u32& power)
    {
        // TODO: Validate this implementation for correctness.
        // Iterative implementation of pow using exponentiation by squaring with bounded auxiliary space.
        // https://en.wikipedia.org/wiki/Exponentiation_by_squaring
        if (power < 0)
        {
            base /= 1;
            power = -power;
        }

        if (power == 0)
        {
            return 1;
        }

        int result = base;
        while (power > 1)
        {
            if (power & 1)
            {
                result *= base;
            }
            base *= base;
            power >>= 1;
        }

        return result;
    }

    // TODO: Find a faster implementation of pow for floats.
    template <>
    RIOT_CONSTEXPR float pow<float, float>(float& base, float& power)
    {
        return ::std::powf(base, power);
    }


    template <typename T>
    RIOT_CONSTEXPR T sin(const T& val)
    {
        return ::std::sin(val);
    }

    template <>
    RIOT_CONSTEXPR float sin<float>(const float& val)
    {
        return ::std::sinf(val);
    }

    template <typename T>
    RIOT_CONSTEXPR T cos(const T& val)
    {
        return ::std::cos(val);
    }

    template <>
    RIOT_CONSTEXPR float cos<float>(const float& val)
    {
        return ::std::cosf(val);
    }

    template <typename T>
    RIOT_CONSTEXPR T tan(const T& val)
    {
        return ::std::tan(val);
    }

    template <>
    RIOT_CONSTEXPR float tan<float>(const float& val)
    {
        return ::std::tanf(val);
    }

    template <typename T>
    RIOT_CONSTEXPR T asin(const T& val)
    {
        return ::std::asin(val);
    }

    template <>
    RIOT_CONSTEXPR float asin<float>(const float& val)
    {
        return ::std::asinf(val);
    }

    template <typename T>
    RIOT_CONSTEXPR T acos(const T& val)
    {
        return ::std::acos(val);
    }

    template <>
    RIOT_CONSTEXPR float acos<float>(const float& val)
    {
        return ::std::acosf(val);
    }

    // Safe version of acos won't return NaN if the input is out of range.
    template <typename T>
    RIOT_CONSTEXPR T acosSafe(T& val)
    {
        if( abs(val) >= T{ 1 } )
        {
            val = (val > T{ 0 }) ? T{ 0 } : RIOT_PI<T>;
            return val;
        }

        return acos(val);
    }

    // Safe version of asin won't return NaN if the input is out of range.
    template <typename T>
    RIOT_CONSTEXPR T asinSafe(T& val)
    {
        if( abs(val) >= T{ 1 } )
        {
            val = (val > T{ 0 }) ? RIOT_PI<T> / T{ 2 } : -RIOT_PI<T> / T{ 2 };
            return val;
        }

        return asin(val);
    }

    // Specialization for float that takes advantage of using multiplication vs division.
    template <>
    RIOT_CONSTEXPR float asinSafe(float& val)
    {
        if( abs(val) >= 1.0f )
        {
            val = (val > 0.0f) ? 0.5f * RIOT_PI<float> : -0.5f * RIOT_PI<float>;
            return val;
        }

        return asin(val);
    }

    template <typename T>
    RIOT_CONSTEXPR T atan(const T& val)
    {
        return ::std::atan(val);
    }

    template <>
    RIOT_CONSTEXPR float atan<float>(const float& val)
    {
        return ::std::atanf(val);
    }

    template <typename T>
    RIOT_CONSTEXPR T atan2(const T& y, const T& x)
    {
        return ::std::atan2(y, x);
    }

    template <>
    RIOT_CONSTEXPR float atan2<float>(const float& y, const float& x)
    {
        return ::std::atan2f(y, x);
    }

    template <typename T>
    RIOT_CONSTEXPR bool nearlyEquals (const T& a, const T& b, const T& epsilon = RIOT_EPSILON<T>)
    {
        // Check if we have equality. This is needed to handle infinities.
        if (a == b)
        {
            return true;
        }

        return abs(a - b) <= epsilon;
    }

    template <typename T>
    RIOT_CONSTEXPR bool equalsZero(const T& val, const T& epsilon = RIOT_EPSILON<T>)
    {
        return abs(val) <= epsilon;
    }

    template <typename T>
    RIOT_CONSTEXPR T sign(const T& val)
    {
        // Specifically not using copysign as it tends to be slow when handling integer types.
        return (T{ 0 } < val) - (val < T{ 0 });
    }

    template<std::floating_point T>
    RIOT_CONSTEXPR float distance(const T& a, const T& b)
    {
        return abs(b - a);
    }

    template <typename T = float>
    RIOT_CONSTEXPR T lerp(const T& start, const T& end, const T& t)
    {
        return start + (end - start) * t;
    }

    template <typename T = float >
    RIOT_CONSTEXPR T lerpUnclamped(const T& start, const T& end, const T& t)
    {
        return start + (end - start) * t;
    }

    template <typename T = float>
    RIOT_CONSTEXPR T lerpClamped(const T& start, const T& end, const T& t)
    {
        return lerp(start, end, clamp(t, T{ 0 }, T{ 1 }));
    }

    template <typename T>
    RIOT_CONSTEXPR T lerpAngle(const T& start, const T& end, const T& t)
    {
        T delta = end - start;
        if (delta > T{ 180 })
        {
            delta -= T{ 360 };
        }
        else if (delta < T{ -180 })
        {
            delta += T{ 360 };
        }

        return start + delta * t;
    }

    template <typename T = float>
    static RIOT_CONSTEXPR T inverseLerp(const T& start, const T& end, const T& val)
    {
        return (val - start) / (end - start);
    }

    template <typename T = float>
    static RIOT_CONSTEXPR T inverseLerpClamped(const T& start, const T& end, const T& val)
    {
        return clamp(inverseLerp(start, end, val), T{ 0 }, T{ 1 });
    }

    template <typename T = float>
    static RIOT_CONSTEXPR T smoothStep(const T& start, const T& end, const T& t)
    {
        T x = clamp((t - start) / (end - start), T{ 0 }, T{ 1 });
        return x * x * (T{ 3 } - T{ 2 } * x);
    }

    template <typename T = float>
    constexpr typename std::enable_if<std::is_floating_point<T>::value, T>::type cubicInterp(T start, T end, T pre, T post, T t)
    {
        return
            T{ 0.5 } *
                ((T{ 2 } * start) +
                    ((-pre + end) * t) +
                    ((T{ 2 } * pre - T{ 5 } * start + T{ 4 } * end - post) * t * t) +
                    ((-pre + T{ 3 } * start - T{ 3 } * end + post) * t * t * t));
    }

    template <typename T = float>
    constexpr typename std::enable_if<std::is_floating_point<T>::value, T>::type cubicInterpAngle(T start, T end, T pre, T post, T t)
    {
        double startRot = fmod(start, RIOT_TAU<T>);

        double preDiff = fmod(pre - startRot, RIOT_TAU<T>);
        double preRot = startRot + fmod(2.0 * preDiff, RIOT_TAU<T>) - preDiff;

        double endDiff = fmod(end - startRot, RIOT_TAU<T>);
        double endRot = startRot + fmod(2.0 * endDiff, RIOT_TAU<T>) - endDiff;

        double postDiff = fmod(post - endRot, RIOT_TAU<T>);
        double postRot = endRot + fmod(2.0 * postDiff, RIOT_TAU<T>) - postDiff;

        return cubic_interpolate(startRot, endRot, preRot, postRot, t);
    }


    // TODO: Implement bezier interpolation
    //template <typename T = float>
    //constexpr typename std::enable_if<std::is_floating_point<T>::value, T>::type bezierInterp



    template <typename T = float>
    static RIOT_CONSTEXPR T pingpong(const T& val, const T& length)
    {
        (length != T{ 0 }) ? abs(fract((val - length) / (length * T{ 2 })) * length * T{ 2 } - length) : T{ 0 };
    }



}
