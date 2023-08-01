// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#pragma once

namespace mim
{
	/*
	 * NAN Values
	 */

	// These values will be useful later for specializations of vector functions when implementing stuff like sine.

    #define NAN_LOG 0x101  // logarithm for x<0
    #define NAN_POW 0x102  // negative number raised to non-integer power
    #define NAN_HYP 0x104  // acosh for x<1 and atanh for abs(x)>1


	/*
	 * Mathematical constants
	 */

	template <typename T = float> inline constexpr T MIM_PI = static_cast<T>(3.1415926535897932384626433832795028841972L);      //!< pi
	template <typename T = float> inline constexpr T MIM_2PI = static_cast<T>(6.2831853071795864769252867665590057683943L);     //!< 2 * pi
	template <typename T = float> inline constexpr T MIM_4PI = static_cast<T>(12.566370614359172953850573533118011536789L);     //!< 4 * pi
	template <typename T = float> inline constexpr T MIM_HALF_PI = static_cast<T>(1.5707963267948966192313216916397514420986L);    //!< pi / 2
	template <typename T = float> inline constexpr T MIM_QUARTER_PI = static_cast<T>(0.78539816339744830961566084581987572104929L);   //!< pi / 4
	template <typename T = float> inline constexpr T MIM_TAU = static_cast<T>(6.2831853071795864769252867665590057683943L);     //!< tau
	template <typename T = float> inline constexpr T MIM_E = static_cast<T>(2.7182818284590452353602874713526624977572L);       //!< e
    template <typename T = float> inline constexpr T MIM_SQRT2 = static_cast<T>(1.41421356237309504880);   //!< sqrt(2)
    template <typename T = float> inline constexpr T MIM_LOG2E = static_cast<T>(1.44269504088896340736);   //!< 1 / log(2)
    template <typename T = float> inline constexpr T MIM_LOG10E = static_cast<T>(0.434294481903251827651); //!< 1 / log(10)
	template <typename T = float> inline constexpr T MIM_LOG2_10 = static_cast<T>(3.321928094887362347808); //!< log2(10)
	template <typename T = float> inline constexpr T MIM_LOG2 = static_cast<T>(0.693147180559945309417);    //!< log(2)
	template <typename T = float> inline constexpr T MIM_NLOG10 = static_cast<T>(2.3025850929940456840179914546843642076011L);    //!< ln(10)


	template <typename T = float> inline constexpr T MIM_SMALLEST_NORMAL = static_cast<T>(2.2250738585072014E-308);    //!< smallest normal number
	template <> inline constexpr double MIM_SMALLEST_NORMAL<double> = 2.2250738585072014E-308;                  //!< smallest normal number, double
	template <> inline constexpr float MIM_SMALLEST_NORMAL<float> = 1.17549435E-38f;                            //!< smallest normal number, float


    // Copied from: https://en.cppreference.com/w/cpp/types/numeric_limits/epsilon
	// Did not want to include all of <limits> since all I need is epsilon

	template <typename T = float> inline constexpr T MIM_EPSILON = static_cast<T>(0);   //!< machine epsilon
	template <> inline constexpr long double MIM_EPSILON<long double> = 1.0842e-19L;    //!< machine epsilon, long double
	template <> inline constexpr double MIM_EPSILON<double> = 2.22045e-16;              //!< machine epsilon, double
	template <> inline constexpr float MIM_EPSILON<float> = 1.19209e-07f;               //!< machine epsilon, float


	template <typename T> inline constexpr T MIM_UNIT_EPSILON = static_cast<T>(0.00001);   //!< unit epsilon

} // namespace mim
