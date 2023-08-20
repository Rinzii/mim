// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#include <gtest/gtest.h>
#include <mim/cmath.hpp>
#include <limits>
#include <cmath>
#include <cfloat>


TEST(cmathDefaultTests, isnan)
{
	EXPECT_TRUE(mim::math::isnan(std::numeric_limits<float>::quiet_NaN()));
    EXPECT_TRUE(mim::math::isnan(std::numeric_limits<double>::quiet_NaN()));
    EXPECT_TRUE(mim::math::isnan(std::numeric_limits<long double>::quiet_NaN()));
    EXPECT_FALSE(mim::math::isnan(0.0f));
    EXPECT_FALSE(mim::math::isnan(0.0));
    EXPECT_FALSE(mim::math::isnan(0.0l));
}

TEST(cmathDefaultTests, abs)
{
    EXPECT_EQ(mim::math::abs(0), 0);
    EXPECT_EQ(mim::math::abs(0.0f), 0.0f);
    EXPECT_EQ(mim::math::abs(0.0), 0.0);
    EXPECT_EQ(mim::math::abs(0.0l), 0.0l);
    EXPECT_EQ(mim::math::abs(-1), 1);
    EXPECT_EQ(mim::math::abs(-1.0f), 1.0f);
    EXPECT_EQ(mim::math::abs(-1.0), 1.0);
    EXPECT_EQ(mim::math::abs(-1.0l), 1.0l);
}

TEST(cmathDefaultTests, min)
{
    EXPECT_EQ(mim::math::min(0, 1), 0);
    EXPECT_EQ(mim::math::min(1, 0), 0);
    EXPECT_EQ(mim::math::min(0.0f, 1.0f), 0.0f);
    EXPECT_EQ(mim::math::min(1.0f, 0.0f), 0.0f);
    EXPECT_EQ(mim::math::min(0.0, 1.0), 0.0);
    EXPECT_EQ(mim::math::min(1.0, 0.0), 0.0);
    EXPECT_EQ(mim::math::min(0.0l, 1.0l), 0.0l);
    EXPECT_EQ(mim::math::min(1.0l, 0.0l), 0.0l);

	EXPECT_EQ(mim::math::min(0, 1, 2), 0);
	EXPECT_EQ(mim::math::min(1, 0, 2), 0);
	EXPECT_EQ(mim::math::min(2, 1, 0, 5, 8, 19), 0);

}

TEST(cmathDefaultTests, max)
{
    EXPECT_EQ(mim::math::max(0, 1), 1);
    EXPECT_EQ(mim::math::max(1, 0), 1);
    EXPECT_EQ(mim::math::max(0.0f, 1.0f), 1.0f);
    EXPECT_EQ(mim::math::max(1.0f, 0.0f), 1.0f);
    EXPECT_EQ(mim::math::max(0.0, 1.0), 1.0);
    EXPECT_EQ(mim::math::max(1.0, 0.0), 1.0);
    EXPECT_EQ(mim::math::max(0.0l, 1.0l), 1.0l);
    EXPECT_EQ(mim::math::max(1.0l, 0.0l), 1.0l);

	EXPECT_EQ(mim::math::max(0, 1, 2), 2);
	EXPECT_EQ(mim::math::max(1, 0, 2), 2);
	EXPECT_EQ(mim::math::max(2, 1, 0, 5, 8, 19), 19);
}

TEST(cmathDefaultTests, clamp)
{
	EXPECT_EQ(mim::math::clamp(0, 1, 2), 1);
    EXPECT_EQ(mim::math::clamp(1, 0, 2), 1);
    EXPECT_EQ(mim::math::clamp(2, 0, 1), 1);
    EXPECT_EQ(mim::math::clamp(0.0f, 1.0f, 2.0f), 1.0f);
    EXPECT_EQ(mim::math::clamp(1.0f, 0.0f, 2.0f), 1.0f);
    EXPECT_EQ(mim::math::clamp(2.0f, 0.0f, 1.0f), 1.0f);
    EXPECT_EQ(mim::math::clamp(0.0, 1.0, 2.0), 1.0);
    EXPECT_EQ(mim::math::clamp(1.0, 0.0, 2.0), 1.0);
    EXPECT_EQ(mim::math::clamp(2.0, 0.0, 1.0), 1.0);
    EXPECT_EQ(mim::math::clamp(0.0l, 1.0l, 2.0l), 1.0l);
    EXPECT_EQ(mim::math::clamp(1.0l, 0.0l, 2.0l), 1.0l);
    EXPECT_EQ(mim::math::clamp(2.0l, 0.0l, 1.0l), 1.0l);
}

