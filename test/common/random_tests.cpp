// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#include <mim/random.hpp>
#include <gtest/gtest.h>
#include <cstdint>

#ifdef MIM_TESTS_EXCESSIVE
    static const int LOOPS = 100000;
#else
    static const int LOOPS = 2;
#endif

TEST(Random, DefaultConstructor)
{
	mim::random r;
    EXPECT_EQ(r.get_seed(), mim::random::DEFAULT_SEED);
}

TEST(Random, ValueConstructor)
{
    mim::random r(123456789);
    EXPECT_EQ(r.get_seed(), 123456789);
}

TEST(Random, ValueConstructorNoNegative)
{
	    mim::random r(-123456789);
    EXPECT_EQ(r.get_seed(), 123456789);
}

TEST(Random, SetSeed)
{
	mim::random r;
    r.set_seed(123456789);
    EXPECT_EQ(r.get_seed(), 123456789);
}

TEST(Random, Seed)
{
	mim::random r;
	r.seed(123456789);
	EXPECT_EQ(r.get_seed(), 123456789);
}


TEST(Random, NextDefault)
{
    mim::random r;
	const int min = 0;
	const int max = INT_MAX;
	for (int i = 0; i < LOOPS; ++i)
	{
		int rand = r.next();
		EXPECT_GE(rand, min);
        EXPECT_LE(rand, max);
	}
}

TEST(Random, NextUpperBound)
{
    mim::random r;
    const int min = 0;
    const int max = 20;
    for (int i = 0; i < LOOPS; ++i)
    {
        int rand = r.next(max);
        EXPECT_GE(rand, min);
        EXPECT_LE(rand, max);
    }
}

TEST(Random, NextLowerUpperBound)
{
    mim::random r;
    const int min = -10;
    const int max = 20;
    for (int i = 0; i < LOOPS; ++i)
    {
        int rand = r.next(min, max);
        EXPECT_GE(rand, min);
        EXPECT_LE(rand, max);
    }
}

TEST(Random, NextLowerUpperBoundNegative)
{
	mim::random r;
	const int min = -100;
	const int max = -1;
	for (int i = 0; i < LOOPS; ++i)
	{
		int rand = r.next(min, max);
		EXPECT_GE(rand, min);
		EXPECT_LE(rand, max);
	}
}

TEST(Random, NextInt64Default)
{
	mim::random r;
	const std::int64_t min = 0;
	const std::int64_t max = INT64_MAX;
	for (int i = 0; i < LOOPS; ++i)
	{
		std::int64_t rand = r.next_int64();
		EXPECT_GE(rand, min);
		EXPECT_LE(rand, max);
	}
}

TEST(Random, NextInt64UpperBound)
{
    mim::random r;
    const std::int64_t min = 0;
    const std::int64_t max = 20;
    for (int i = 0; i < LOOPS; ++i)
    {
        std::int64_t rand = r.next_int64(max);
        EXPECT_GE(rand, min);
        EXPECT_LE(rand, max);
    }
}

TEST(Random, NextInt64LowerUpperBound)
{
    mim::random r;
    const std::int64_t min = -10;
    const std::int64_t max = 20;
    for (int i = 0; i < LOOPS; ++i)
    {
        std::int64_t rand = r.next_int64(min, max);
        EXPECT_GE(rand, min);
        EXPECT_LE(rand, max);
    }
}

TEST(Random, NextInt64LowerUpperBoundNegative)
{
    mim::random r;
    const std::int64_t min = -100;
    const std::int64_t max = -1;
    for (int i = 0; i < LOOPS; ++i)
    {
        std::int64_t rand = r.next_int64(min, max);
        EXPECT_GE(rand, min);
        EXPECT_LE(rand, max);
    }
}

TEST(Random, NextSingleDefault)
{
    mim::random r;
    const float min = 0.0f;
    const float max = 1.0f;
    for (int i = 0; i < LOOPS; ++i)
    {
		float rand = r.next_single();
        EXPECT_GE(rand, min);
        EXPECT_LE(rand, max);
    }
}

TEST(Random, NextSingleUpperBound)
{
    mim::random r;
    const float min = 0.0f;
    const float max = 20.0f;
    for (int i = 0; i < LOOPS; ++i)
    {
        float rand = r.next_single(max);
        EXPECT_GE(rand, min);
        EXPECT_LE(rand, max);
    }
}

TEST(Random, NextSingleLowerUpperBound)
{
    mim::random r;
    const float min = -10.0f;
    const float max = 20.0f;
    for (int i = 0; i < LOOPS; ++i)
    {
        float rand = r.next_single(min, max);
        EXPECT_GE(rand, min);
        EXPECT_LE(rand, max);
    }
}

TEST(Random, NextSingleLowerUpperBoundNegative)
{
	    mim::random r;
    const float min = -100.0f;
    const float max = -1.0f;
    for (int i = 0; i < LOOPS; ++i)
    {
        float rand = r.next_single(min, max);
        EXPECT_GE(rand, min);
        EXPECT_LE(rand, max);
    }
}

TEST(Random, NextDoubleDefault)
{
    mim::random r;
    const double min = 0.0;
    const double max = 1.0;
    for (int i = 0; i < LOOPS; ++i)
    {
        double rand = r.next_double();
        EXPECT_GE(rand, min);
        EXPECT_LE(rand, max);
    }
}

TEST(Random, NextDoubleUpperBound)
{
    mim::random r;
    const double min = 0.0;
    const double max = 20.0;
    for (int i = 0; i < LOOPS; ++i)
    {
        double rand = r.next_double(max);
        EXPECT_GE(rand, min);
        EXPECT_LE(rand, max);
    }
}

TEST(Random, NextDoubleLowerUpperBound)
{
    mim::random r;
    const double min = -10.0;
    const double max = 20.0;
    for (int i = 0; i < LOOPS; ++i)
    {
        double rand = r.next_double(min, max);
        EXPECT_GE(rand, min);
        EXPECT_LE(rand, max);
    }
}

TEST(Random, NextDoubleLowerUpperBoundNegative)
{
    mim::random r;
    const double min = -100.0;
    const double max = -1.0;
    for (int i = 0; i < LOOPS; ++i)
    {
        double rand = r.next_double(min, max);
        EXPECT_GE(rand, min);
        EXPECT_LE(rand, max);
    }
}

