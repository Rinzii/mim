// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#pragma once

#include "mim/internal/setup.hpp"

#include "mim/mimMathDefs.hpp"

#include "mim/detail/compute/compute_functors.hpp"

#include "mim/detail/qualifier.hpp"

#include "mim/half.hpp"
#include "mim/vec.hpp"
#include "mim/mat.hpp"
#include "mim/quat.hpp"


#include <cmath>



namespace mim
{

    template <typename T>
    static T degToRad(const T& deg)
    {
        return (deg * (MIM_PI<T>) / T{ 180 });
    }

    template <typename T>
    static T radToDeg(T rad)
    {
        return (rad * T{ 180 }) / MIM_PI<T>;
    }

	static int ftoifast(float const& f)
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
    static T min(const T& a, const T& b)
    {
        MIM_STATIC_ASSERT(std::is_arithmetic<T>::value, "T must be an arithmetic type.");
        return (b < a) ? b : a;
    }

    template <typename T, typename ... Args>
    static T min(const T& a, const T& b, const Args& ... args)
    {
        return min(min(a, b), std::forward<Args>(args)...);
    }

    template <typename T>
    static T max(const T& a, const T& b)
    {
        MIM_STATIC_ASSERT(std::is_arithmetic<T>::value, "T must be an arithmetic type.");
        return (a < b) ? b : a;
    }

    template <typename T, typename ... Args>
    static T max(const T& a, const T& b, const Args& ... args)
    {
        return max(max(a, b), std::forward<Args>(args)...);
    }

    template <typename T>
    static T clamp(const T& val, const T& min, const T& max)
    {
        return min(max(val, min), max);
    }

    template <typename T>
    void swap(const T& a, const T& b)
    {
        ::std::swap(a, b);
    }

    template <typename T>
    static T abs(const T& val)
    {
        return ::std::abs(val);
    }

    // I've noticed slight improvements in performance with this method when handling integers.
    template <>
    int abs<int>(const int& val)
    {
        int const mask = val >> (sizeof(int) * CHAR_BIT - 1);
        return (val ^ mask) - mask;
    }

    template <typename T>
    static T floor(const T& val)
    {
        return ::std::floor(val);
    }

    template <>
    float floor<float>(const float& val)
    {
        return floorf(val);
    }

    template <typename T>
    static T ceil(const T& val)
    {
        return ::std::ceil(val);
    }

    template <>
    float ceil<float>(const float& val)
    {
        return ceilf(val);
    }

    template <typename T>
    static T round(const T& val)
    {
        return ::std::round(val);
    }

    template <>
    float round<float>(const float& val)
    {
        return ::std::roundf(val);
    }

    template <typename T>
    static T trunc(const T& val)
    {
        return ::std::trunc(val);
    }

    template <>
	float trunc<float>(const float& val)
    {
        return ::std::truncf(val);
    }

    template <typename T>
    static T frac(const T& val)
    {
        return val - trunc(val);
    }

    template <typename T>
    static bool isnan(const T& val)
    {
        #if MIM_COMPILER_CPP11_ENABLED
            return ::std::isnan(val);
        #elif MIM_COMPILER_MSVC
            return _isnan(val) != 0;
        #elif (MIM_COMPILER_GCC || MIM_COMPILER_CLANG) && (MIM_PLATFORM_ANDROID) && __cplusplus < 201103L
            return _isnan(val) != 0;
        #else
            return ::std::isnan(val);
        #endif
    }

    template <typename T>
    static bool isinf(const T& val)
    {
        return ::std::isinf(val);
    }

    template <typename T>
	static T sqrt(const T& val)
    {
        return ::std::sqrt(val);
    }

    template <>
	float sqrt<float>(const float& val)
    {
        return sqrtf(val);
    }

    template <typename T>
	static T inv_sqrt(const T& val)
    {
        return T{ 1 } / sqrt(val);
    }

    // std::pow is relatively slow when working with floats instead of doubles. This is due to pow having to convert from double to float.
    // So we will use a custom implementation of pow for floats.
    // https://baptiste-wicht.com/posts/2017/09/cpp11-performance-tip-when-to-use-std-pow.html
    template <typename T, typename Q>
	static T pow(T& base, Q& power)
    {
        return ::std::pow<T>(base, power);
    }

    // This custom implementation is significantly faster than std::pow for integers.
    template <>
	detail::i32 pow<detail::i32, detail::i32>(detail::i32& base, detail::i32& power)
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
	detail::u32 pow<detail::u32, detail::u32>(detail::u32& base, detail::u32& power)
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

        detail::u32 result = base;
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
	float pow<float, float>(float& base, float& power)
    {
        return powf(base, power);
    }

	template <std::size_t S, typename T, qualifier Q>
	static VectorT<S, T, Q> pow(const VectorT<S, T, Q>& base, const VectorT<S, T, Q>& power)
	{
		return detail::functor2<VectorT, S, T, T, Q>::compute(pow, base, power);
    }

    template <typename T>
	static T exp(const T& val)
    {
        return ::std::exp(val);
    }

    template <>
	float exp<float>(const float& val)
    {
        return expf(val);
    }

    template <typename T>
	static T sin(const T& val)
    {
        return ::std::sin(val);
    }

    template <>
	float sin<float>(const float& val)
    {
        return sinf(val);
    }

	template <std::size_t S, typename T, qualifier Q>
	static VectorT<S, T, Q> sin(const VectorT<S, T, Q>& val)
	{
		return detail::functor1<VectorT, S, T, T, Q>::compute(sin, val);
	}

    template <typename T>
	static T cos(const T& val)
    {
        return ::std::cos(val);
    }

    template <>
	float cos(const float& val)
    {
        return cosf(val);
    }


	template <std::size_t S, typename T, qualifier Q>
	static VectorT<S, T, Q> cos(const VectorT<S, T, Q>& val)
    {
        return detail::functor1<VectorT, S, T, T, Q>::compute(cos, val);
    }


    template <typename T>
	static T tan(const T& val)
    {
        return ::std::tan(val);
    }

    template <>
	float tan<float>(const float& val)
    {
        return tanf(val);
    }

    template <typename T>
	static T asin(const T& val)
    {
        return ::std::asin(val);
    }

	template <std::size_t S, typename T, qualifier Q>
	static VectorT<S, T, Q> tan(const VectorT<S, T, Q>& val)
	{
		return detail::functor1<VectorT, S, T, T, Q>::compute(tan, val);
	}

    template <>
    float asin<float>(const float& val)
    {
        return asinf(val);
    }

	template <std::size_t S, typename T, qualifier Q>
	static VectorT<S, T, Q> asin(const VectorT<S, T, Q>& val)
	{
		return detail::functor1<VectorT, S, T, T, Q>::compute(asin, val);
	}

    template <typename T>
    static T acos(const T& val)
    {
        return ::std::acos(val);
    }

    template <>
    float acos<float>(const float& val)
    {
        return acosf(val);
    }

	template <std::size_t S, typename T, qualifier Q>
	static VectorT<S, T, Q> acos(const VectorT<S, T, Q>& val)
	{
		return detail::functor1<VectorT, S, T, T, Q>::compute(acos, val);
	}

    // Safe version of acos won't return NaN if the input is out of range.
    template <typename T>
    static T acos_s(T& val)
    {
        if( abs(val) >= T{ 1 } )
        {
            val = (val > T{ 0 }) ? T{ 0 } : MIM_PI<T>;
            return val;
        }

        return acos(val);
    }

    // Safe version of asin won't return NaN if the input is out of range.
    template <typename T>
    static T asin_s(T& val)
    {
        if( abs(val) >= T{ 1 } )
        {
            val = (val > T{ 0 }) ? MIM_PI<T> / T{ 2 } : -MIM_PI<T> / T{ 2 };
            return val;
        }

        return asin(val);
    }

    // Specialization for float that takes advantage of using multiplication vs division.
    template <>
	float asin_s(float& val)
    {
        if( abs(val) >= 1.0f )
        {
            val = (val > 0.0f) ? 0.5f * MIM_PI<float> : -0.5f * MIM_PI<float>;
            return val;
        }

        return asin(val);
    }

    template <typename T>
    static T atan(const T& val)
    {
        return ::std::atan(val);
    }

    template <>
	float atan<float>(const float& val)
    {
        return atanf(val);
    }

	template <std::size_t S, typename T, qualifier Q>
	static VectorT<S, T, Q> atan(const VectorT<S, T, Q>& val)
	{
		return detail::functor1<VectorT, S, T, T, Q>::compute(atan, val);
	}

    template <typename T>
    static T atan2(const T& y, const T& x)
    {
        return ::std::atan2(y, x);
    }

    template <>
	float atan2<float>(const float& y, const float& x)
    {
        return atan2f(y, x);
    }

	template <typename T>
	static T cosh(const T& val)
    {
		return ::std::cosh(val);
	}

	template <std::size_t S, typename T, qualifier Q>
	static VectorT<S, T, Q> cosh(const VectorT<S, T, Q>& val)
	{
		return detail::functor1<VectorT, S, T, T, Q>::compute(cosh, val);
	}

	template <typename T>
	static T sinh(const T& val)
	{
		return ::std::cosh(val);
	}

	template <std::size_t S, typename T, qualifier Q>
	static VectorT<S, T, Q> sinh(const VectorT<S, T, Q>& val)
	{
		return detail::functor1<VectorT, S, T, T, Q>::compute(sinh, val);
	}

	template <typename T>
	static T tanh(const T& val)
	{
		return ::std::tanh(val);
	}

	template <std::size_t S, typename T, qualifier Q>
	static VectorT<S, T, Q> tanh(const VectorT<S, T, Q>& val)
	{
		return detail::functor1<VectorT, S, T, T, Q>::compute(tanh, val);
	}

	template <typename T>
	static T acosh(const T& val)
    {
		return ::std::acosh(val);
	}

	template <std::size_t S, typename T, qualifier Q>
	static VectorT<S, T, Q> acosh(const VectorT<S, T, Q>& val)
    {
		return detail::functor1<VectorT, S, T, T, Q>::compute(acosh, val);
	}

	template <typename T>
	static T asinh(const T& val)
    {
		return ::std::asinh(val);
	}

	template <std::size_t S, typename T, qualifier Q>
	static VectorT<S, T, Q> asinh(const VectorT<S, T, Q>& val)
    {
		return detail::functor1<VectorT, S, T, T, Q>::compute(asinh, val);
	}

	template <typename T>
	static T atanh(const T& val)
    {
		return ::std::atanh(val);
	}

	template <std::size_t S, typename T, qualifier Q>
	static VectorT<S, T, Q> atanh(const VectorT<S, T, Q>& val)
    {
		return detail::functor1<VectorT, S, T, T, Q>::compute(atanh, val);
	}

    template <typename T>
    static bool nearlyEquals (const T& a, const T& b, const T& epsilon = MIM_EPSILON<T>)
    {
        // Check if we have equality. This is needed to handle infinities.
        if (a == b)
        {
            return true;
        }

        return abs(a - b) <= epsilon;
    }

    template <typename T>
    static bool equalsZero(const T& val, const T& epsilon = MIM_EPSILON<T>)
    {
        return abs(val) <= epsilon;
    }

    template <typename T>
    static T sign(const T& val)
    {
        // Specifically not using copysign as it tends to be slow when handling integer types.
        return (T{ 0 } < val) - (val < T{ 0 });
    }

	template <typename T>
	static T inverse(const T& val)
    {
		return T{ 1 } / val;
	}
	
	template <std::size_t S, typename T, qualifier Q>
	static VectorT<S, T, Q> inverse(const VectorT<S, T, Q>& val)
    {
		return detail::functor1<VectorT, S, T, T, Q>::compute(inverse, val);
	}

    template<std::floating_point T>
    static float distance(const T& a, const T& b)
    {
        return abs(b - a);
    }

    template <typename T = float>
    static T lerp(const T& start, const T& end, const T& t)
    {
        return start + (end - start) * t;
    }

    template <typename T = float >
    static T lerp_unclamped(const T& start, const T& end, const T& t)
    {
        return start + (end - start) * t;
    }

    template <typename T = float>
    static T lerp_clamped(const T& start, const T& end, const T& t)
    {
        return lerp(start, end, clamp(t, T{ 0 }, T{ 1 }));
    }

    template <typename T>
    static T lerp_angle(const T& start, const T& end, const T& t)
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
    static constexpr T inverse_lerp(const T& start, const T& end, const T& val)
    {
        return (val - start) / (end - start);
    }

    template <typename T = float>
    static constexpr T inverse_lerp_clamped(const T& start, const T& end, const T& val)
    {
        return clamp(inverseLerp(start, end, val), T{ 0 }, T{ 1 });
    }

    template <typename T = float>
    static constexpr T smooth_step(const T& start, const T& end, const T& t)
    {
        T x = clamp((t - start) / (end - start), T{ 0 }, T{ 1 });
        return x * x * (T{ 3 } - T{ 2 } * x);
    }

    template <typename T = float>
    static typename std::enable_if<std::is_floating_point<T>::value, T>::type cubic_interp(T start, T end, T pre, T post, T t)
    {
        return
            T{ 0.5 } *
                ((T{ 2 } * start) +
                    ((-pre + end) * t) +
                    ((T{ 2 } * pre - T{ 5 } * start + T{ 4 } * end - post) * t * t) +
                    ((-pre + T{ 3 } * start - T{ 3 } * end + post) * t * t * t));
    }

    template <typename T = float>
    static typename std::enable_if<std::is_floating_point<T>::value, T>::type cubic_interp_angle(T start, T end, T pre, T post, T t)
    {
        double startRot = fmod(start, MIM_TAU<T>);

        double preDiff = fmod(pre - startRot, MIM_TAU<T>);
        double preRot = startRot + fmod(2.0 * preDiff, MIM_TAU<T>) - preDiff;

        double endDiff = fmod(end - startRot, MIM_TAU<T>);
        double endRot = startRot + fmod(2.0 * endDiff, MIM_TAU<T>) - endDiff;

        double postDiff = fmod(post - endRot, MIM_TAU<T>);
        double postRot = endRot + fmod(2.0 * postDiff, MIM_TAU<T>) - postDiff;

        return cubic_interpolate(startRot, endRot, preRot, postRot, t);
    }


    // TODO: Implement bezier interpolation
    //template <typename T = float>
    //static typename std::enable_if<std::is_floating_point<T>::value, T>::type bezierInterp



    template <typename T = float>
    static constexpr T pingpong(const T& val, const T& length)
    {
        (length != T{ 0 }) ? abs(fract((val - length) / (length * T{ 2 })) * length * T{ 2 } - length) : T{ 0 };
    }

}
