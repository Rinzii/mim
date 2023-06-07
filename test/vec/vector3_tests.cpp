// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#include <mim/vec3.hpp>
#include <gtest/gtest.h>

TEST(Vector3Default, DefaultConstructor)
{
    mim::vec3f v;
    EXPECT_EQ(v.x, 0.0f);
    EXPECT_EQ(v.y, 0.0f);
    EXPECT_EQ(v.z, 0.0f);
}

TEST(Vector3Default, ValueConstructor)
{
    mim::vec3f v(1.0f, 2.0f, 3.0f);
    EXPECT_EQ(v.x, 1.0f);
    EXPECT_EQ(v.y, 2.0f);
    EXPECT_EQ(v.z, 3.0f);
}

TEST(Vector3Default, CopyConstructor)
{
    mim::vec3f v1(1.0f, 2.0f, 3.0f);
    mim::vec3f v2(v1);
    EXPECT_EQ(v2.x, 1.0f);
    EXPECT_EQ(v2.y, 2.0f);
    EXPECT_EQ(v2.z, 3.0f);
}

TEST(Vector3Default, MoveConstructor)
{
    mim::vec3f v1(1.0f, 2.0f, 3.0f);
    mim::vec3f v2(std::move(v1));
    EXPECT_EQ(v2.x, 1.0f);
    EXPECT_EQ(v2.y, 2.0f);
    EXPECT_EQ(v2.z, 3.0f);
}

TEST(Vector3Default, CopyAssignment)
{
    mim::vec3f v1(1.0f, 2.0f, 3.0f);
    mim::vec3f v2;
    v2 = v1;
    EXPECT_EQ(v2.x, 1.0f);
    EXPECT_EQ(v2.y, 2.0f);
    EXPECT_EQ(v2.z, 3.0f);
}

TEST(Vector3Default, MoveAssignment)
{
    mim::vec3f v1(1.0f, 2.0f, 3.0f);
    mim::vec3f v2;
    v2 = std::move(v1);
    EXPECT_EQ(v2.x, 1.0f);
    EXPECT_EQ(v2.y, 2.0f);
    EXPECT_EQ(v2.z, 3.0f);
}

TEST(Vector3Default, Addition)
{
    mim::vec3f v1(1.0f, 2.0f, 3.0f);
    mim::vec3f v2(4.0f, 5.0f, 6.0f);
    mim::vec3f v3 = v1 + v2;
    EXPECT_EQ(v3.x, 5.0f);
    EXPECT_EQ(v3.y, 7.0f);
    EXPECT_EQ(v3.z, 9.0f);
}

TEST(Vector3Default, Subtraction)
{
    mim::vec3f v1(1.0f, 2.0f, 3.0f);
    mim::vec3f v2(4.0f, 5.0f, 6.0f);
    mim::vec3f v3 = v1 - v2;
    EXPECT_EQ(v3.x, -3.0f);
    EXPECT_EQ(v3.y, -3.0f);
    EXPECT_EQ(v3.z, -3.0f);
}

TEST(Vector3Default, Multiplication)
{
    mim::vec3f v1(1.0f, 2.0f, 3.0f);
    mim::vec3f v2(4.0f, 5.0f, 6.0f);
    mim::vec3f v3 = v1 * v2;
    EXPECT_EQ(v3.x, 4.0f);
    EXPECT_EQ(v3.y, 10.0f);
    EXPECT_EQ(v3.z, 18.0f);
}

TEST(Vector3Default, Division)
{
    mim::vec3f v1(1.0f, 2.0f, 3.0f);
    mim::vec3f v2(4.0f, 5.0f, 6.0f);
    mim::vec3f v3 = v1 / v2;
    EXPECT_EQ(v3.x, 0.25f);
    EXPECT_EQ(v3.y, 0.4f);
    EXPECT_EQ(v3.z, 0.5f);
}

TEST(Vector3Default, AdditionAssignment)
{
    mim::vec3f v1(1.0f, 2.0f, 3.0f);
    v1 += mim::vec3f(4.0f, 5.0f, 6.0f);
    EXPECT_EQ(v1.x, 5.0f);
    EXPECT_EQ(v1.y, 7.0f);
    EXPECT_EQ(v1.z, 9.0f);
}

TEST(Vector3Default, SubtractionAssignment)
{
    mim::vec3f v1(1.0f, 2.0f, 3.0f);
    v1 -= mim::vec3f(4.0f, 5.0f, 6.0f);
    EXPECT_EQ(v1.x, -3.0f);
    EXPECT_EQ(v1.y, -3.0f);
    EXPECT_EQ(v1.z, -3.0f);
}

TEST(Vector3Default, MultiplicationAssignment)
{
    mim::vec3f v1(1.0f, 2.0f, 3.0f);
    v1 *= mim::vec3f(4.0f, 5.0f, 6.0f);
    EXPECT_EQ(v1.x, 4.0f);
    EXPECT_EQ(v1.y, 10.0f);
    EXPECT_EQ(v1.z, 18.0f);
}

TEST(Vector3Default, DivisionAssignment)
{
    mim::vec3f v1(1.0f, 2.0f, 3.0f);
    v1 /= mim::vec3f(4.0f, 5.0f, 6.0f);
    EXPECT_EQ(v1.x, 0.25f);
    EXPECT_EQ(v1.y, 0.4f);
    EXPECT_EQ(v1.z, 0.5f);
}

TEST(Vector3Default, AdditionScalar)
{
    mim::vec3f v1(1.0f, 2.0f, 3.0f);
    mim::vec3f v2 = v1 + 4.0f;
    EXPECT_EQ(v2.x, 5.0f);
    EXPECT_EQ(v2.y, 6.0f);
    EXPECT_EQ(v2.z, 7.0f);
}

TEST(Vector3Default, SubtractionScalar)
{
    mim::vec3f v1(1.0f, 2.0f, 3.0f);
    mim::vec3f v2 = v1 - 4.0f;
    EXPECT_EQ(v2.x, -3.0f);
    EXPECT_EQ(v2.y, -2.0f);
    EXPECT_EQ(v2.z, -1.0f);
}

TEST(Vector3Default, MultiplicationScalar)
{
    mim::vec3f v1(1.0f, 2.0f, 3.0f);
    mim::vec3f v2 = v1 * 4.0f;
    EXPECT_EQ(v2.x, 4.0f);
    EXPECT_EQ(v2.y, 8.0f);
    EXPECT_EQ(v2.z, 12.0f);
}

TEST(Vector3Default, DivisionScalar)
{
    mim::vec3f v1(1.0f, 2.0f, 3.0f);
    mim::vec3f v2 = v1 / 4.0f;
    EXPECT_EQ(v2.x, 0.25f);
    EXPECT_EQ(v2.y, 0.5f);
    EXPECT_EQ(v2.z, 0.75f);
}

TEST(Vector3Default, AdditionScalarAssignment)
{
    mim::vec3f v1(1.0f, 2.0f, 3.0f);
    v1 += 4.0f;
    EXPECT_EQ(v1.x, 5.0f);
    EXPECT_EQ(v1.y, 6.0f);
    EXPECT_EQ(v1.z, 7.0f);
}

TEST(Vector3Default, SubtractionScalarAssignment)
{
    mim::vec3f v1(1.0f, 2.0f, 3.0f);
    v1 -= 4.0f;
    EXPECT_EQ(v1.x, -3.0f);
    EXPECT_EQ(v1.y, -2.0f);
    EXPECT_EQ(v1.z, -1.0f);
}

TEST(Vector3Default, MultiplicationScalarAssignment)
{
    mim::vec3f v1(1.0f, 2.0f, 3.0f);
    v1 *= 4.0f;
    EXPECT_EQ(v1.x, 4.0f);
    EXPECT_EQ(v1.y, 8.0f);
    EXPECT_EQ(v1.z, 12.0f);
}

TEST(Vector3Default, DivisionScalarAssignment)
{
    mim::vec3f v1(1.0f, 2.0f, 3.0f);
    v1 /= 4.0f;
    EXPECT_EQ(v1.x, 0.25f);
    EXPECT_EQ(v1.y, 0.5f);
    EXPECT_EQ(v1.z, 0.75f);
}

