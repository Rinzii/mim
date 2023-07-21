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

