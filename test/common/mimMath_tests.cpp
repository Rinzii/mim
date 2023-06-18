// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#include <gtest/gtest.h>
#include <mim/mimMath.hpp>

/*
TEST(CommonMimMath, degToRadTest)
{
	EXPECT_FLOAT_EQ(mim::math::radians(0.0f), 0.0f);
    EXPECT_FLOAT_EQ(mim::math::radians(90.0f), 1.5707963267948966f);
    EXPECT_FLOAT_EQ(mim::math::radians(180.0f), 3.141592653589793f);
    EXPECT_FLOAT_EQ(mim::math::radians(270.0f), 4.71238898038469f);
    EXPECT_FLOAT_EQ(mim::math::radians(360.0f), 6.283185307179586f);
}

TEST(CommonMimMath, radToDegTest)
{
	EXPECT_FLOAT_EQ(mim::math::radToDeg(0.0f), 0.0f);
    EXPECT_FLOAT_EQ(mim::math::radToDeg(1.5707963267948966f), 90.0f);
    EXPECT_FLOAT_EQ(mim::math::radToDeg(3.141592653589793f), 180.0f);
    EXPECT_FLOAT_EQ(mim::math::radToDeg(4.71238898038469f), 270.0f);
    EXPECT_FLOAT_EQ(mim::math::radToDeg(6.283185307179586f), 360.0f);
}
*/

TEST(CommonMimMath, sinTest)
{
	auto tPi = mim::MIM_PI<double>;
	EXPECT_FLOAT_EQ(mim::math::sin(0.0f), 0.0f);
    EXPECT_FLOAT_EQ(mim::math::sin(tPi / 6.0f), 0.5f);
	EXPECT_FLOAT_EQ(mim::math::sin(tPi / 2.0f), 1.0f);
	EXPECT_FLOAT_EQ(mim::math::sin(-3.0f * tPi / 4.0f), -0.7071067812f);
}

TEST(CommonMimMath, cosTest)
{
	auto tPi = mim::MIM_PI<double>;
    EXPECT_FLOAT_EQ(mim::math::cos(0.0f), 1.0f);
	EXPECT_FLOAT_EQ(mim::math::cos(tPi / 3.0f), 0.5f);
	EXPECT_FLOAT_EQ(mim::math::cos(tPi / 2.0f), 6.123233996e-17f);
	EXPECT_FLOAT_EQ(mim::math::cos(-3.0f * tPi / 4.0f), -0.7071067812f);

}

TEST(CommonMimMath, tanTest)
{
	auto tPi = mim::MIM_PI<double>;
    EXPECT_FLOAT_EQ(mim::math::tan(0.0f), 0.0f);
	EXPECT_FLOAT_EQ(mim::math::tan(1.0f * tPi / 4.0f), 1.0f);
	EXPECT_FLOAT_EQ(mim::math::tan(3.0f * tPi / 4.0f), -1.0f);

}

TEST(CommonMimMath, asinTest)
{
    EXPECT_FLOAT_EQ(mim::math::asin(0.0f), 0.0f);
    EXPECT_FLOAT_EQ(mim::math::asin(1.0f), 1.5707963267948966f);
    EXPECT_FLOAT_EQ(mim::math::asin(-1.0f), -1.5707963267948966f);
}

TEST(CommonMimMath, acosTest)
{
    EXPECT_FLOAT_EQ(mim::math::acos(1.0f), 0.0f);
    EXPECT_FLOAT_EQ(mim::math::acos(0.0f), 1.5707963267948966f);
    EXPECT_FLOAT_EQ(mim::math::acos(-1.0f), 3.141592653589793f);
}

TEST(CommonMimMath, acos_sTest)
{
	EXPECT_FLOAT_EQ(mim::math::acos_s(1.0f), 0.0f);
	EXPECT_FLOAT_EQ(mim::math::acos_s(0.0f), 1.5707963267948966f);
	EXPECT_FLOAT_EQ(mim::math::acos_s(-1.0f), 3.141592653589793f);

	// Test out-of-range input values
	EXPECT_FALSE(std::isnan(mim::math::acos_s(1.1f)));  // Value greater than 1
	EXPECT_FALSE(std::isnan(mim::math::acos_s(-1.1f))); // Value less than -1
}

TEST(CommonMimMath, asin_sTest)
{
	EXPECT_FLOAT_EQ(mim::math::asin_s(0.0f), 0.0f);
	EXPECT_FLOAT_EQ(mim::math::asin_s(1.0f), 1.5707963267948966f);
	EXPECT_FLOAT_EQ(mim::math::asin_s(-1.0f), -1.5707963267948966f);

	// Test out-of-range input values
	EXPECT_FALSE(std::isnan(mim::math::asin_s(1.1f)));  // Value greater than 1
	EXPECT_FALSE(std::isnan(mim::math::asin_s(-1.1f))); // Value less than -1
}

TEST(CommonMimMath, atanTest)
{
    EXPECT_FLOAT_EQ(mim::math::atan(0.0f), 0.0f);
    EXPECT_FLOAT_EQ(mim::math::atan(1.0f), 0.7853981633974483f);
    EXPECT_FLOAT_EQ(mim::math::atan(-1.0f), -0.7853981633974483f);
}

TEST(CommonMimMath, atan2Test)
{
    //EXPECT_FLOAT_EQ(mim::math::atan2(0.0f, 0.0f), 0.0f);
    EXPECT_FLOAT_EQ(mim::math::atan2(1.0f, 1.0f), 0.7853981633974483f);
    EXPECT_FLOAT_EQ(mim::math::atan2(-1.0f, -1.0f), -2.356194490192345f);
}

TEST(CommonMimMath, coshTest)
{
    EXPECT_FLOAT_EQ(mim::math::cosh(0.0f), 1.0f);
    EXPECT_FLOAT_EQ(mim::math::cosh(1.0f), 1.5430806348152437f);
    EXPECT_FLOAT_EQ(mim::math::cosh(-1.0f), 1.5430806348152437f);
}

TEST(CommonMimMath, sinhTest)
{
    EXPECT_FLOAT_EQ(mim::math::sinh(0.0f), 0.0f);
    EXPECT_FLOAT_EQ(mim::math::sinh(1.0f), 1.1752011936438014f);
    EXPECT_FLOAT_EQ(mim::math::sinh(-1.0f), -1.1752011936438014f);
}

TEST(CommonMimMath, tanhTest)
{
    EXPECT_FLOAT_EQ(mim::math::tanh(0.0f), 0.0f);
    EXPECT_FLOAT_EQ(mim::math::tanh(1.0f), 0.7615941559557649f);
    EXPECT_FLOAT_EQ(mim::math::tanh(-1.0f), -0.7615941559557649f);
}

TEST(CommonMimMath, acoshTest)
{
    EXPECT_FLOAT_EQ(mim::math::acosh(1.0f), 0.0f);
    EXPECT_FLOAT_EQ(mim::math::acosh(2.0f), 1.3169578969248166f);
    EXPECT_FLOAT_EQ(mim::math::acosh(3.0f), 1.762747174039086f);
}

TEST(CommonMimMath, asinhTest)
{
    EXPECT_FLOAT_EQ(mim::math::asinh(0.0f), 0.0f);
    EXPECT_FLOAT_EQ(mim::math::asinh(1.0f), 0.881373587019543f);
    EXPECT_FLOAT_EQ(mim::math::asinh(-1.0f), -0.881373587019543f);
}

TEST(CommonMimMath, atanhTest)
{
    EXPECT_FLOAT_EQ(mim::math::atanh(0.0f), 0.0f);
    EXPECT_FLOAT_EQ(mim::math::atanh(0.5f), 0.5493061443340549f);
    EXPECT_FLOAT_EQ(mim::math::atanh(-0.5f), -0.5493061443340549f);
}

TEST(CommonMimMath, absTest)
{
	EXPECT_FLOAT_EQ(mim::math::abs(0.0f), 0.0f);
    EXPECT_FLOAT_EQ(mim::math::abs(1.0f), 1.0f);
    EXPECT_FLOAT_EQ(mim::math::abs(-1.0f), 1.0f);

	EXPECT_EQ(mim::math::abs(0), 0);
	EXPECT_EQ(mim::math::abs(1), 1);
	EXPECT_EQ(mim::math::abs(-1), 1);
}

TEST(CommonMimMath, signTest)
{
    EXPECT_FLOAT_EQ(mim::math::sign(0.0f), 0.0f);
    EXPECT_FLOAT_EQ(mim::math::sign(1.0f), 1.0f);
    EXPECT_FLOAT_EQ(mim::math::sign(-1.0f), -1.0f);
}

TEST(CommonMimMath, floorTest)
{
    EXPECT_FLOAT_EQ(mim::math::floor(0.0f), 0.0f);
    EXPECT_FLOAT_EQ(mim::math::floor(1.0f), 1.0f);
    EXPECT_FLOAT_EQ(mim::math::floor(-1.0f), -1.0f);
}

TEST(CommonMimMath, truncTest)
{
    EXPECT_FLOAT_EQ(mim::math::trunc(0.0f), 0.0f);
    EXPECT_FLOAT_EQ(mim::math::trunc(1.0f), 1.0f);
    EXPECT_FLOAT_EQ(mim::math::trunc(-1.0f), -1.0f);
}

TEST(CommonMimMath, roundTest)
{
    EXPECT_FLOAT_EQ(mim::math::round(0.0f), 0.0f);
    EXPECT_FLOAT_EQ(mim::math::round(1.0f), 1.0f);
    EXPECT_FLOAT_EQ(mim::math::round(-1.0f), -1.0f);
}

TEST(CommonMimMath, roundEven)
{
	EXPECT_FLOAT_EQ(mim::math::roundEven(0.0f), 0.0f);
    EXPECT_FLOAT_EQ(mim::math::roundEven(1.0f), 1.0f);
    EXPECT_FLOAT_EQ(mim::math::roundEven(-1.0f), -1.0f);
}

TEST(CommonMimMath, roundEvenFast)
{
	EXPECT_FLOAT_EQ(mim::math::roundEvenFast(0.0f), 0.0f);
    EXPECT_FLOAT_EQ(mim::math::roundEvenFast(1.0f), 1.0f);
    EXPECT_FLOAT_EQ(mim::math::roundEvenFast(-1.0f), -1.0f);
}

TEST(CommonMimMath, ceilTest)
{
    EXPECT_FLOAT_EQ(mim::math::ceil(0.0f), 0.0f);
    EXPECT_FLOAT_EQ(mim::math::ceil(1.0f), 1.0f);
    EXPECT_FLOAT_EQ(mim::math::ceil(-1.0f), -1.0f);
}

TEST(CommonMimMath, fractTest)
{
    EXPECT_FLOAT_EQ(mim::math::fract(0.0f), 0.0f);
    EXPECT_FLOAT_EQ(mim::math::fract(1.0f), 0.0f);
    EXPECT_FLOAT_EQ(mim::math::fract(-1.0f), 0.0f);
}

TEST(CommonMimMath, modTest)
{
    EXPECT_FLOAT_EQ(mim::math::mod(0.0f, 1.0f), 0.0f);
    EXPECT_FLOAT_EQ(mim::math::mod(1.0f, 1.0f), 0.0f);
    EXPECT_FLOAT_EQ(mim::math::mod(-1.0f, 1.0f), 0.0f);
}

TEST(CommonMimMath, modfTest)
{
    float intPart;
    EXPECT_FLOAT_EQ(mim::math::modf(0.0f, &intPart), 0.0f);
    EXPECT_FLOAT_EQ(intPart, 0.0f);

    EXPECT_FLOAT_EQ(mim::math::modf(1.0f, &intPart), 0.0f);
    EXPECT_FLOAT_EQ(intPart, 1.0f);

    EXPECT_FLOAT_EQ(mim::math::modf(-1.0f, &intPart), 0.0f);
    EXPECT_FLOAT_EQ(intPart, -1.0f);
}

TEST(CommonMimMath, minTest)
{
    EXPECT_FLOAT_EQ(mim::math::min(0.0f, 1.0f), 0.0f);
    EXPECT_FLOAT_EQ(mim::math::min(1.0f, 0.0f), 0.0f);
    EXPECT_FLOAT_EQ(mim::math::min(-1.0f, 0.0f), -1.0f);
}

TEST(CommonMimMath, maxTest)
{
    EXPECT_FLOAT_EQ(mim::math::max(0.0f, 1.0f), 1.0f);
    EXPECT_FLOAT_EQ(mim::math::max(1.0f, 0.0f), 1.0f);
    EXPECT_FLOAT_EQ(mim::math::max(-1.0f, 0.0f), 0.0f);
}

/* TODO: Fix clamp.
TEST(CommonMimMath, clampTest)
{
    EXPECT_FLOAT_EQ(mim::math::clamp(0.0f, 0.0f, 1.0f), 0.0f);
    EXPECT_FLOAT_EQ(mim::math::clamp(1.0f, 0.0f, 1.0f), 1.0f);
    EXPECT_FLOAT_EQ(mim::math::clamp(-1.0f, 0.0f, 1.0f), 0.0f);
}
*/

TEST(CommonMimMath, mixTest)
{
    EXPECT_FLOAT_EQ(mim::math::mix(0.0f, 1.0f, 0.0f), 0.0f);
    EXPECT_FLOAT_EQ(mim::math::mix(0.0f, 1.0f, 1.0f), 1.0f);
    EXPECT_FLOAT_EQ(mim::math::mix(0.0f, 1.0f, 0.5f), 0.5f);
}

TEST(CommonMimMath, stepTest)
{
    EXPECT_FLOAT_EQ(mim::math::step(0.0f, 1.0f), 1.0f);
    EXPECT_FLOAT_EQ(mim::math::step(1.0f, 0.0f), 0.0f);
    EXPECT_FLOAT_EQ(mim::math::step(0.0f, 0.0f), 1.0f);
}

/* TODO: Fix smoothstep.
TEST(CommonMimMath, smoothstepTest)
{
    EXPECT_FLOAT_EQ(mim::math::smoothstep(0.0f, 1.0f, 0.0f), 0.0f);
    EXPECT_FLOAT_EQ(mim::math::smoothstep(0.0f, 1.0f, 1.0f), 1.0f);
    EXPECT_FLOAT_EQ(mim::math::smoothstep(0.0f, 1.0f, 0.5f), 0.5f);
}
*/

TEST(CommonMimMath, isnanTest)
{
    EXPECT_FALSE(mim::math::isnan(0.0f));
    EXPECT_FALSE(mim::math::isnan(1.0f));
    EXPECT_FALSE(mim::math::isnan(-1.0f));
}

TEST(CommonMimMath, isinfTest)
{
    EXPECT_FALSE(mim::math::isinf(0.0f));
    EXPECT_FALSE(mim::math::isinf(1.0f));
    EXPECT_FALSE(mim::math::isinf(-1.0f));
}

TEST(CommonMimMath, floatBitsToIntTest)
{
	EXPECT_EQ(mim::math::floatBitsToInt(0.0f), 0);
    EXPECT_EQ(mim::math::floatBitsToInt(1.0f), 1065353216);
    EXPECT_EQ(mim::math::floatBitsToInt(-1.0f), -1082130432);
}

TEST(CommonMimMath, floatBitsToUintTest)
{
    EXPECT_EQ(mim::math::floatBitsToUint(0.0f), 0u);
    EXPECT_EQ(mim::math::floatBitsToUint(1.0f), 1065353216u);
    EXPECT_EQ(mim::math::floatBitsToUint(-1.0f), 3212836864u);
}

TEST(CommonMimMath, intBitsToFloatTest)
{
    EXPECT_FLOAT_EQ(mim::math::intBitsToFloat(0), 0.0f);
    EXPECT_FLOAT_EQ(mim::math::intBitsToFloat(1065353216), 1.0f);
    EXPECT_FLOAT_EQ(mim::math::intBitsToFloat(-1082130432), -1.0f);
}

TEST(CommonMimMath, uintBitsToFloatTest)
{
    EXPECT_FLOAT_EQ(mim::math::uintBitsToFloat(0u), 0.0f);
    EXPECT_FLOAT_EQ(mim::math::uintBitsToFloat(1065353216u), 1.0f);
    EXPECT_FLOAT_EQ(mim::math::uintBitsToFloat(3212836864u), -1.0f);
}

TEST(CommonMimMath, fmaTest)
{
	// TODO: Define test case for fma
	//EXPECT_FLOAT_EQ(mim::math::fma(0.0f, 0.0f, 0.0f), 0.0f);
    //EXPECT_FLOAT_EQ(mim::math::fma(1.0f, 1.0f, 1.0f), 2.0f);
    //EXPECT_FLOAT_EQ(mim::math::fma(-1.0f, -1.0f, -1.0f), -2.0f);
}

TEST(CommonMimMath, frexpTest)
{
    int exp;
    EXPECT_FLOAT_EQ(mim::math::frexp(0.0f, &exp), 0.0f);
    EXPECT_EQ(exp, 0);

    EXPECT_FLOAT_EQ(mim::math::frexp(1.0f, &exp), 0.5f);
    EXPECT_EQ(exp, 1);

    EXPECT_FLOAT_EQ(mim::math::frexp(-1.0f, &exp), -0.5f);
    EXPECT_EQ(exp, 1);
}

TEST(CommonMimMath, ldexpTest)
{
    EXPECT_FLOAT_EQ(mim::math::ldexp(0.0f, 0), 0.0f);
    EXPECT_FLOAT_EQ(mim::math::ldexp(1.0f, 1), 2.0f);
    EXPECT_FLOAT_EQ(mim::math::ldexp(-1.0f, 1), -2.0f);
}

TEST(CommonMimMath, powTest)
{
	EXPECT_FLOAT_EQ(mim::math::pow(0.0f, 0.0f), 1.0f);
    EXPECT_FLOAT_EQ(mim::math::pow(1.0f, 1.0f), 1.0f);
    EXPECT_FLOAT_EQ(mim::math::pow(-1.0f, 1.0f), -1.0f);

	// TODO: Add tests for int types
}

TEST(CommonMimMath, expTest)
{
    EXPECT_FLOAT_EQ(mim::math::exp(0.0f), 1.0f);
    EXPECT_FLOAT_EQ(mim::math::exp(1.0f), 2.71828182845904523536f);
    EXPECT_FLOAT_EQ(mim::math::exp(-1.0f), 0.3678794411714423215955f);
}

TEST(CommonMimMath, logTest)
{
    EXPECT_FLOAT_EQ(mim::math::log(1.0f), 0.0f);
    EXPECT_FLOAT_EQ(mim::math::log(2.71828182845904523536f), 1.0f);
    EXPECT_FLOAT_EQ(mim::math::log(0.3678794411714423215955f), -1.0f);
}

TEST(CommonMimMath, exp2Test)
{
    EXPECT_FLOAT_EQ(mim::math::exp2(0.0f), 1.0f);
    EXPECT_FLOAT_EQ(mim::math::exp2(1.0f), 2.0f);
    EXPECT_FLOAT_EQ(mim::math::exp2(-1.0f), 0.5f);
}

TEST(CommonMimMath, log2Test)
{
    EXPECT_FLOAT_EQ(mim::math::log2(1.0f), 0.0f);
    EXPECT_FLOAT_EQ(mim::math::log2(2.0f), 1.0f);
    EXPECT_FLOAT_EQ(mim::math::log2(0.5f), -1.0f);
}

TEST(CommonMimMath, sqrtTest)
{
    EXPECT_FLOAT_EQ(mim::math::sqrt(0.0f), 0.0f);
    EXPECT_FLOAT_EQ(mim::math::sqrt(1.0f), 1.0f);
    EXPECT_FLOAT_EQ(mim::math::sqrt(4.0f), 2.0f);
}

TEST(CommonMimMath, inversesqrtTest)
{
	// Consider this as a possible return.
    //EXPECT_FLOAT_EQ(mim::math::inversesqrt(0.0f), std::numeric_limits<float>::infinity());
    EXPECT_FLOAT_EQ(mim::math::inversesqrt(1.0f), 1.0f);
    EXPECT_FLOAT_EQ(mim::math::inversesqrt(4.0f), 0.5f);
}

// TODO: Implement the remaining functions test cases.






