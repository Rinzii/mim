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

	template <typename T = float> inline constexpr T MIM_PI = static_cast<T>(3.14159265358979323846);      //!< pi
	template <typename T = float> inline constexpr T MIM_2PI = static_cast<T>(6.28318530717958647693);     //!< 2 * pi
	template <typename T = float> inline constexpr T MIM_4PI = static_cast<T>(12.5663706143591729539);     //!< 4 * pi
	template <typename T = float> inline constexpr T MIM_PI_2 = static_cast<T>(1.57079632679489661923);    //!< pi / 2
	template <typename T = float> inline constexpr T MIM_PI_4 = static_cast<T>(0.785398163397448309616);   //!< pi / 4
	template <typename T = float> inline constexpr T MIM_TAU = static_cast<T>(6.28318530717958647693);     //!< tau
	template <typename T = float> inline constexpr T MIM_E = static_cast<T>(2.71828182845904523536);       //!< e
    template <typename T = float> inline constexpr T MIM_SQRT2 = static_cast<T>(1.41421356237309504880);   //!< sqrt(2)
    template <typename T = float> inline constexpr T MIM_LOG2E = static_cast<T>(1.44269504088896340736);   //!< 1 / log(2)
    template <typename T = float> inline constexpr T MIM_LOG10E = static_cast<T>(0.434294481903251827651); //!< 1 / log(10)
	template <typename T = float> inline constexpr T MIM_LOG210 = static_cast<T>(3.321928094887362347808); //!< log2(10)
	template <typename T = float> inline constexpr T MIM_LN2 = static_cast<T>(0.693147180559945309417);    //!< log(2)

	template <typename T = float> inline constexpr T MIM_SMALLEST_NORMAL = static_cast<T>(2.2250738585072014E-308);    //!< smallest normal number
	template <> inline constexpr double MIM_SMALLEST_NORMAL<double> = 2.2250738585072014E-308;                  //!< smallest normal number, double
	template <> inline constexpr float MIM_SMALLEST_NORMAL<float> = 1.17549435E-38f;                            //!< smallest normal number, float


    // Copied from: https://en.cppreference.com/w/cpp/types/numeric_limits/epsilon
	// Did not want to include all of <limits> since all I need is epsilon

	template <typename T = float> inline constexpr T MIM_EPSILON = static_cast<T>(0);          //!< machine epsilon
	template <> inline constexpr long double MIM_EPSILON<long double> = 1.0842e-19L;    //!< machine epsilon, long double
	template <> inline constexpr double MIM_EPSILON<double> = 2.22045e-16;              //!< machine epsilon, double
	template <> inline constexpr float MIM_EPSILON<float> = 1.19209e-07f;               //!< machine epsilon, float


	template <typename T> inline constexpr T MIM_UNIT_EPSILON = static_cast<T>(0.00001);   //!< unit epsilon

} // namespace mim
