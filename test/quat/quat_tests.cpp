// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#include <mim/quat.hpp>
#include <mim/vec.hpp>
#include <mim/mimConstants.hpp>
#include <gtest/gtest.h>

TEST(QuaternionDefaultTests, DefaultConstructor)
{
    mim::quat<float> q;
	EXPECT_EQ(q.w, 1.0f);
    EXPECT_EQ(q.x, 0.0f);
    EXPECT_EQ(q.y, 0.0f);
    EXPECT_EQ(q.z, 0.0f);
}

TEST(QuaternionDefaultTests, CheckSizeOfDataStructure)
{
    mim::quat<float> q;
    EXPECT_EQ(sizeof(q), 16);
}

TEST(QuaternionDefaultTests, Size)
{
    mim::quat<float> q;
    EXPECT_EQ(q.size(), 4);
}

TEST(QuaternionDefaultTests, ArrayAccessor)
{
	mim::quat<float> q;
    EXPECT_EQ(q[0], 1.0f);
    EXPECT_EQ(q[1], 0.0f);
    EXPECT_EQ(q[2], 0.0f);
    EXPECT_EQ(q[3], 0.0f);
}

TEST(QuaternionDefaultTests, At)
{
    mim::quat<float> q;
    EXPECT_EQ(q.at(0), 1.0f);
    EXPECT_EQ(q.at(1), 0.0f);
    EXPECT_EQ(q.at(2), 0.0f);
    EXPECT_EQ(q.at(3), 0.0f);
}

TEST(QuaternionDefaultTests, QuatConstructor)
{
    mim::quat<float> q1(1.0f, 2.0f, 3.0f, 4.0f);
	mim::quat<float> q2(q1);

	EXPECT_EQ(q2.w, 1.0f);
    EXPECT_EQ(q2.x, 2.0f);
    EXPECT_EQ(q2.y, 3.0f);
    EXPECT_EQ(q2.z, 4.0f);
}



TEST(QuaternionDefaultTests, QuatConstructorWithVecAndW)
{
    mim::vec<3, float> v(1.0f, 2.0f, 3.0f);
    mim::quat<float> q(4.0f, v);

    EXPECT_EQ(q.w, 4.0f);
    EXPECT_EQ(q.x, 1.0f);
    EXPECT_EQ(q.y, 2.0f);
    EXPECT_EQ(q.z, 3.0f);
}

// TODO: Add tests for mat type conversion

/* Broken at moment
TEST(QuaternionDefaultTests, QuatConstructorWithVec3s)
{
	const mim::vec<3, float> v1(1.0f, 2.0f, 3.0f);
    const mim::vec<3, float> v2(4.0f, 5.0f, 6.0f);
    mim::quat<float> q(v1, v2);

    EXPECT_EQ(q.w, -28.0f);
    EXPECT_EQ(q.x, 4.0f);
    EXPECT_EQ(q.y, 5.0f);
    EXPECT_EQ(q.z, 6.0f);
}
*/
