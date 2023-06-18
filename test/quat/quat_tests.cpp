// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#include <mim/quat.hpp>
#include <gtest/gtest.h>

TEST(QuatTests, DefaultConstructor)
{
	mim::quatf q;
    EXPECT_EQ(q.w, 1.0f);
    EXPECT_EQ(q.x, 0.0f);
    EXPECT_EQ(q.y, 0.0f);
    EXPECT_EQ(q.z, 0.0f);
}

TEST(QuatTests, ScalarVectorConstructor)
{
    mim::quatf q(1.0f, 2.0f, 3.0f, 4.0f);
    EXPECT_EQ(q.w, 1.0f);
    EXPECT_EQ(q.x, 2.0f);
    EXPECT_EQ(q.y, 3.0f);
    EXPECT_EQ(q.z, 4.0f);
}



