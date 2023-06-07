// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#include <mim/vec4.hpp>
#include <gtest/gtest.h>

TEST(Vector4Default, DefaultConstructor)
{
    mim::vec4f v;
	EXPECT_EQ(v.x, 0.0f);
	EXPECT_EQ(v.y, 0.0f);
	EXPECT_EQ(v.z, 0.0f);
	EXPECT_EQ(v.w, 0.0f);
}

TEST(Vector4Default, ValueConstructor)
{
    mim::vec4f v(1.0f, 2.0f, 3.0f, 4.0f);
    EXPECT_EQ(v.x, 1.0f);
    EXPECT_EQ(v.y, 2.0f);
    EXPECT_EQ(v.z, 3.0f);
    EXPECT_EQ(v.w, 4.0f);
}

TEST(Vector4Default, CopyConstructor)
{
    mim::vec4f v1(1.0f, 2.0f, 3.0f, 4.0f);
    mim::vec4f v2(v1);
    EXPECT_EQ(v2.x, 1.0f);
    EXPECT_EQ(v2.y, 2.0f);
    EXPECT_EQ(v2.z, 3.0f);
    EXPECT_EQ(v2.w, 4.0f);
}

TEST(Vector4Default, MoveConstructor)
{
    mim::vec4f v1(1.0f, 2.0f, 3.0f, 4.0f);
    mim::vec4f v2(std::move(v1));
    EXPECT_EQ(v2.x, 1.0f);
    EXPECT_EQ(v2.y, 2.0f);
    EXPECT_EQ(v2.z, 3.0f);
    EXPECT_EQ(v2.w, 4.0f);
}

TEST(Vector4Default, CopyAssignment)
{
    mim::vec4f v1(1.0f, 2.0f, 3.0f, 4.0f);
    mim::vec4f v2;
    v2 = v1;
    EXPECT_EQ(v2.x, 1.0f);
    EXPECT_EQ(v2.y, 2.0f);
    EXPECT_EQ(v2.z, 3.0f);
    EXPECT_EQ(v2.w, 4.0f);
}

TEST(Vector4Default, MoveAssignment)
{
    mim::vec4f v1(1.0f, 2.0f, 3.0f, 4.0f);
    mim::vec4f v2;
    v2 = std::move(v1);
    EXPECT_EQ(v2.x, 1.0f);
    EXPECT_EQ(v2.y, 2.0f);
    EXPECT_EQ(v2.z, 3.0f);
    EXPECT_EQ(v2.w, 4.0f);
}

TEST(Vector4Default, Addition)
{
    mim::vec4f v1(1.0f, 2.0f, 3.0f, 4.0f);
    mim::vec4f v2(5.0f, 6.0f, 7.0f, 8.0f);
    mim::vec4f v3 = v1 + v2;
    EXPECT_EQ(v3.x, 6.0f);
    EXPECT_EQ(v3.y, 8.0f);
    EXPECT_EQ(v3.z, 10.0f);
    EXPECT_EQ(v3.w, 12.0f);
}

TEST(Vector4Default, AdditionAssignment)
{
    mim::vec4f v1(1.0f, 2.0f, 3.0f, 4.0f);
    mim::vec4f v2(5.0f, 6.0f, 7.0f, 8.0f);
    v1 += v2;
    EXPECT_EQ(v1.x, 6.0f);
    EXPECT_EQ(v1.y, 8.0f);
    EXPECT_EQ(v1.z, 10.0f);
    EXPECT_EQ(v1.w, 12.0f);
}

TEST(Vector4Default, Subtraction)
{
    mim::vec4f v1(5.0f, 6.0f, 7.0f, 8.0f);
    mim::vec4f v2(1.0f, 2.0f, 3.0f, 4.0f);
    mim::vec4f v3 = v1 - v2;
    EXPECT_EQ(v3.x, 4.0f);
    EXPECT_EQ(v3.y, 4.0f);
    EXPECT_EQ(v3.z, 4.0f);
    EXPECT_EQ(v3.w, 4.0f);
}

TEST(Vector4Default, SubtractionAssignment)
{
    mim::vec4f v1(5.0f, 6.0f, 7.0f, 8.0f);
    mim::vec4f v2(1.0f, 2.0f, 3.0f, 4.0f);
    v1 -= v2;
    EXPECT_EQ(v1.x, 4.0f);
    EXPECT_EQ(v1.y, 4.0f);
    EXPECT_EQ(v1.z, 4.0f);
    EXPECT_EQ(v1.w, 4.0f);
}

TEST(Vector4Default, Multiplication)
{
    mim::vec4f v1(1.0f, 2.0f, 3.0f, 4.0f);
    mim::vec4f v2(5.0f, 6.0f, 7.0f, 8.0f);
    mim::vec4f v3 = v1 * v2;
    EXPECT_EQ(v3.x, 5.0f);
    EXPECT_EQ(v3.y, 12.0f);
    EXPECT_EQ(v3.z, 21.0f);
    EXPECT_EQ(v3.w, 32.0f);
}

TEST(Vector4Default, MultiplicationAssignment)
{
    mim::vec4f v1(1.0f, 2.0f, 3.0f, 4.0f);
    mim::vec4f v2(5.0f, 6.0f, 7.0f, 8.0f);
    v1 *= v2;
    EXPECT_EQ(v1.x, 5.0f);
    EXPECT_EQ(v1.y, 12.0f);
    EXPECT_EQ(v1.z, 21.0f);
    EXPECT_EQ(v1.w, 32.0f);
}

TEST(Vector4Default, Division)
{
    mim::vec4f v1(5.0f, 6.0f, 7.0f, 8.0f);
    mim::vec4f v2(1.0f, 2.0f, 3.0f, 4.0f);
    mim::vec4f v3 = v1 / v2;
    EXPECT_EQ(v3.x, 5.0f);
    EXPECT_EQ(v3.y, 3.0f);
    EXPECT_EQ(v3.z, 2.33333333f);
    EXPECT_EQ(v3.w, 2.0f);
}

TEST(Vector4Default, DivisionAssignment)
{
    mim::vec4f v1(5.0f, 6.0f, 7.0f, 8.0f);
    mim::vec4f v2(1.0f, 2.0f, 3.0f, 4.0f);
    v1 /= v2;
    EXPECT_EQ(v1.x, 5.0f);
    EXPECT_EQ(v1.y, 3.0f);
    EXPECT_EQ(v1.z, 2.33333333f);
    EXPECT_EQ(v1.w, 2.0f);
}


