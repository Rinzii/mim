// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#include <mim/vec1.hpp>
#include <gtest/gtest.h>

TEST(Vector1, DefaultConstructor)
{
    mim::vec1f v;
    EXPECT_EQ(v.x, 0.0f);
}

TEST(Vector1, ValueConstructor)
{
    mim::vec1f v(1.0f);
    EXPECT_EQ(v.x, 1.0f);
}

TEST(Vector1, CopyConstructor)
{
    mim::vec1f v1(1.0f);
    mim::vec1f v2(v1);
    EXPECT_EQ(v2.x, 1.0f);
}

TEST(Vector1, MoveConstructor)
{
    mim::vec1f v1(1.0f);
    mim::vec1f v2(std::move(v1));
    EXPECT_EQ(v2.x, 1.0f);
}

TEST(Vector1, CopyAssignment)
{
    mim::vec1f v1(1.0f);
    mim::vec1f v2;
    v2 = v1;
    EXPECT_EQ(v2.x, 1.0f);
}

TEST(Vector1, MoveAssignment)
{
    mim::vec1f v1(1.0f);
    mim::vec1f v2;
    v2 = std::move(v1);
    EXPECT_EQ(v2.x, 1.0f);
}

TEST(Vector1, Addition)
{
    mim::vec1f v1(1.0f);
    mim::vec1f v2(2.0f);
    mim::vec1f v3 = v1 + v2;
    EXPECT_EQ(v3.x, 3.0f);
}

TEST(Vector1, Subtraction)
{
    mim::vec1f v1(1.0f);
    mim::vec1f v2(2.0f);
    mim::vec1f v3 = v1 - v2;
    EXPECT_EQ(v3.x, -1.0f);
}

TEST(Vector1, Multiplication)
{
    mim::vec1f v1(2.0f);
    mim::vec1f v2(3.0f);
    mim::vec1f v3 = v1 * v2;
    EXPECT_EQ(v3.x, 6.0f);
}

TEST(Vector1, Division)
{
    mim::vec1f v1(6.0f);
    mim::vec1f v2(3.0f);
    mim::vec1f v3 = v1 / v2;
    EXPECT_EQ(v3.x, 2.0f);
}

TEST(Vector1, AdditionAssignment)
{
    mim::vec1f v1(1.0f);
    mim::vec1f v2(2.0f);
    v1 += v2;
    EXPECT_EQ(v1.x, 3.0f);
}

TEST(Vector1, SubtractionAssignment)
{
    mim::vec1f v1(1.0f);
    mim::vec1f v2(2.0f);
    v1 -= v2;
    EXPECT_EQ(v1.x, -1.0f);
}

TEST(Vector1, MultiplicationAssignment)
{
    mim::vec1f v1(2.0f);
    mim::vec1f v2(3.0f);
    v1 *= v2;
    EXPECT_EQ(v1.x, 6.0f);
}

TEST(Vector1, DivisionAssignment)
{
    mim::vec1f v1(6.0f);
    mim::vec1f v2(3.0f);
    v1 /= v2;
    EXPECT_EQ(v1.x, 2.0f);
}

TEST(Vector1, AdditionScalar)
{
    mim::vec1f v1(1.0f);
    mim::vec1f v2 = v1 + 2.0f;
    EXPECT_EQ(v2.x, 3.0f);
}

TEST(Vector1, SubtractionScalar)
{
    mim::vec1f v1(1.0f);
    mim::vec1f v2 = v1 - 2.0f;
    EXPECT_EQ(v2.x, -1.0f);
}

TEST(Vector1, MultiplicationScalar)
{
    mim::vec1f v1(2.0f);
    mim::vec1f v2 = v1 * 3.0f;
    EXPECT_EQ(v2.x, 6.0f);
}

TEST(Vector1, DivisionScalar)
{
    mim::vec1f v1(6.0f);
    mim::vec1f v2 = v1 / 3.0f;
    EXPECT_EQ(v2.x, 2.0f);
}

TEST(Vector1, AdditionScalarAssignment)
{
    mim::vec1f v1(1.0f);
    v1 += 2.0f;
    EXPECT_EQ(v1.x, 3.0f);
}

TEST(Vector1, SubtractionScalarAssignment)
{
    mim::vec1f v1(1.0f);
    v1 -= 2.0f;
    EXPECT_EQ(v1.x, -1.0f);
}

TEST(Vector1, MultiplicationScalarAssignment)
{
    mim::vec1f v1(2.0f);
    v1 *= 3.0f;
    EXPECT_EQ(v1.x, 6.0f);
}

TEST(Vector1, DivisionScalarAssignment)
{
    mim::vec1f v1(6.0f);
    v1 /= 3.0f;
    EXPECT_EQ(v1.x, 2.0f);
}

TEST(Vector1, Negation)
{
    mim::vec1f v1(1.0f);
    mim::vec1f v2 = -v1;
    EXPECT_EQ(v2.x, -1.0f);
}

TEST(Vector1, Equality)
{
    mim::vec1f v1(1.0f);
    mim::vec1f v2(1.0f);
    EXPECT_TRUE(v1 == v2);
}

TEST(Vector1, Inequality)
{
    mim::vec1f v1(1.0f);
    mim::vec1f v2(2.0f);
    EXPECT_TRUE(v1 != v2);
}

TEST(Vector1, Size)
{
    mim::vec1f v1(1.0f);
    EXPECT_EQ(v1.size(), 1);
}

