// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#include <mim/vec2.hpp>
#include <gtest/gtest.h>

TEST(Vector2, DefaultConstructor)
{
    mim::vec2f v;
    EXPECT_EQ(v.x, 0.0f);
    EXPECT_EQ(v.y, 0.0f);
}

TEST(Vector2, ValueConstructor)
{
    mim::vec2f v(1.0f, 2.0f);
    EXPECT_EQ(v.x, 1.0f);
    EXPECT_EQ(v.y, 2.0f);
}

TEST(Vector2, CopyConstructor)
{
    mim::vec2f v1(1.0f, 2.0f);
    mim::vec2f v2(v1);
    EXPECT_EQ(v2.x, 1.0f);
    EXPECT_EQ(v2.y, 2.0f);
}

TEST(Vector2, MoveConstructor)
{
    mim::vec2f v1(1.0f, 2.0f);
    mim::vec2f v2(std::move(v1));
    EXPECT_EQ(v2.x, 1.0f);
    EXPECT_EQ(v2.y, 2.0f);
}

TEST(Vector2, CopyAssignment)
{
    mim::vec2f v1(1.0f, 2.0f);
    mim::vec2f v2;
    v2 = v1;
    EXPECT_EQ(v2.x, 1.0f);
    EXPECT_EQ(v2.y, 2.0f);
}

TEST(Vector2, MoveAssignment)
{
    mim::vec2f v1(1.0f, 2.0f);
    mim::vec2f v2;
    v2 = std::move(v1);
    EXPECT_EQ(v2.x, 1.0f);
    EXPECT_EQ(v2.y, 2.0f);
}

TEST(Vector2, Addition)
{
    mim::vec2f v1(1.0f, 2.0f);
    mim::vec2f v2(3.0f, 4.0f);
    mim::vec2f v3 = v1 + v2;
    EXPECT_EQ(v3.x, 4.0f);
    EXPECT_EQ(v3.y, 6.0f);
}

TEST(Vector2, Subtraction)
{
    mim::vec2f v1(1.0f, 2.0f);
    mim::vec2f v2(3.0f, 4.0f);
    mim::vec2f v3 = v1 - v2;
    EXPECT_EQ(v3.x, -2.0f);
    EXPECT_EQ(v3.y, -2.0f);
}

TEST(Vector2, Multiplication)
{
    mim::vec2f v1(1.0f, 2.0f);
    mim::vec2f v2(3.0f, 4.0f);
    mim::vec2f v3 = v1 * v2;
    EXPECT_EQ(v3.x, 3.0f);
    EXPECT_EQ(v3.y, 8.0f);
}

TEST(Vector2, Division)
{
    mim::vec2f v1(1.0f, 2.0f);
    mim::vec2f v2(3.0f, 4.0f);
    mim::vec2f v3 = v1 / v2;
    EXPECT_EQ(v3.x, 1.0f / 3.0f);
    EXPECT_EQ(v3.y, 2.0f / 4.0f);
}

TEST(Vector2, AdditionAssignment)
{
    mim::vec2f v1(1.0f, 2.0f);
    mim::vec2f v2(3.0f, 4.0f);
    v1 += v2;
    EXPECT_EQ(v1.x, 4.0f);
    EXPECT_EQ(v1.y, 6.0f);
}

TEST(Vector2, SubtractionAssignment)
{
    mim::vec2f v1(1.0f, 2.0f);
    mim::vec2f v2(3.0f, 4.0f);
    v1 -= v2;
    EXPECT_EQ(v1.x, -2.0f);
    EXPECT_EQ(v1.y, -2.0f);
}

TEST(Vector2, MultiplicationAssignment)
{
    mim::vec2f v1(1.0f, 2.0f);
    mim::vec2f v2(3.0f, 4.0f);
    v1 *= v2;
    EXPECT_EQ(v1.x, 3.0f);
    EXPECT_EQ(v1.y, 8.0f);
}

TEST(Vector2, DivisionAssignment)
{
    mim::vec2f v1(1.0f, 2.0f);
    mim::vec2f v2(3.0f, 4.0f);
    v1 /= v2;
    EXPECT_EQ(v1.x, 1.0f / 3.0f);
    EXPECT_EQ(v1.y, 2.0f / 4.0f);
}

TEST(Vector2, AdditionScalar)
{
    mim::vec2f v1(1.0f, 2.0f);
    mim::vec2f v2 = v1 + 3.0f;
    EXPECT_EQ(v2.x, 4.0f);
    EXPECT_EQ(v2.y, 5.0f);
}

TEST(Vector2, SubtractionScalar)
{
    mim::vec2f v1(1.0f, 2.0f);
    mim::vec2f v2 = v1 - 3.0f;
    EXPECT_EQ(v2.x, -2.0f);
    EXPECT_EQ(v2.y, -1.0f);
}

TEST(Vector2, MultiplicationScalar)
{
    mim::vec2f v1(1.0f, 2.0f);
    mim::vec2f v2 = v1 * 3.0f;
    EXPECT_EQ(v2.x, 3.0f);
    EXPECT_EQ(v2.y, 6.0f);
}

TEST(Vector2, DivisionScalar)
{
    mim::vec2f v1(1.0f, 2.0f);
    mim::vec2f v2 = v1 / 3.0f;
    EXPECT_EQ(v2.x, 1.0f / 3.0f);
    EXPECT_EQ(v2.y, 2.0f / 3.0f);
}

TEST(Vector2, AdditionScalarAssignment)
{
    mim::vec2f v1(1.0f, 2.0f);
    v1 += 3.0f;
    EXPECT_EQ(v1.x, 4.0f);
    EXPECT_EQ(v1.y, 5.0f);
}

TEST(Vector2, SubtractionScalarAssignment)
{
    mim::vec2f v1(1.0f, 2.0f);
    v1 -= 3.0f;
    EXPECT_EQ(v1.x, -2.0f);
    EXPECT_EQ(v1.y, -1.0f);
}

TEST(Vector2, MultiplicationScalarAssignment)
{
    mim::vec2f v1(1.0f, 2.0f);
    v1 *= 3.0f;
    EXPECT_EQ(v1.x, 3.0f);
    EXPECT_EQ(v1.y, 6.0f);
}

TEST(Vector2, DivisionScalarAssignment)
{
    mim::vec2f v1(1.0f, 2.0f);
    v1 /= 3.0f;
    EXPECT_EQ(v1.x, 1.0f / 3.0f);
    EXPECT_EQ(v1.y, 2.0f / 3.0f);
}

/* I'm having issues with this operator
//TODO: Investigate.
TEST(Vector2, BitwiseNot)
{
    mim::vec2i v1(1, 2);
    mim::vec2i v2 = ~v1;
    EXPECT_EQ(v2.x, ~1);
    EXPECT_EQ(v2.y, ~2);
}
*/

TEST(Vector2, BitwiseAnd)
{
    mim::vec2i v1(1, 2);
    mim::vec2i v2(3, 4);
    mim::vec2i v3 = v1 & v2;
    EXPECT_EQ(v3.x, 1 & 3);
    EXPECT_EQ(v3.y, 2 & 4);
}

TEST(Vector2, BitwiseOr)
{
    mim::vec2i v1(1, 2);
    mim::vec2i v2(3, 4);
    mim::vec2i v3 = v1 | v2;
    EXPECT_EQ(v3.x, 1 | 3);
    EXPECT_EQ(v3.y, 2 | 4);
}

TEST(Vector2, BitwiseXor)
{
    mim::vec2i v1(1, 2);
    mim::vec2i v2(3, 4);
    mim::vec2i v3 = v1 ^ v2;
    EXPECT_EQ(v3.x, 1 ^ 3);
    EXPECT_EQ(v3.y, 2 ^ 4);
}

TEST(Vector2, BitwiseAndAssignment)
{
    mim::vec2i v1(1, 2);
    mim::vec2i v2(3, 4);
    v1 &= v2;
    EXPECT_EQ(v1.x, 1 & 3);
    EXPECT_EQ(v1.y, 2 & 4);
}

TEST(Vector2, BitwiseOrAssignment)
{
    mim::vec2i v1(1, 2);
    mim::vec2i v2(3, 4);
    v1 |= v2;
    EXPECT_EQ(v1.x, 1 | 3);
    EXPECT_EQ(v1.y, 2 | 4);
}

TEST(Vector2, BitwiseXorAssignment)
{
    mim::vec2i v1(1, 2);
    mim::vec2i v2(3, 4);
    v1 ^= v2;
    EXPECT_EQ(v1.x, 1 ^ 3);
    EXPECT_EQ(v1.y, 2 ^ 4);
}

TEST(Vector2, BitwiseLeftShift)
{
    mim::vec2i v1(1, 2);
    mim::vec2i v2 = v1 << 3;
    EXPECT_EQ(v2.x, 1 << 3);
    EXPECT_EQ(v2.y, 2 << 3);
}

TEST(Vector2, BitwiseRightShift)
{
    mim::vec2i v1(1, 2);
    mim::vec2i v2 = v1 >> 3;
    EXPECT_EQ(v2.x, 1 >> 3);
    EXPECT_EQ(v2.y, 2 >> 3);
}

TEST(Vector2, BitwiseLeftShiftAssignment)
{
    mim::vec2i v1(1, 2);
    v1 <<= 3;
    EXPECT_EQ(v1.x, 1 << 3);
    EXPECT_EQ(v1.y, 2 << 3);
}

TEST(Vector2, BitwiseRightShiftAssignment)
{
    mim::vec2i v1(1, 2);
    v1 >>= 3;
    EXPECT_EQ(v1.x, 1 >> 3);
    EXPECT_EQ(v1.y, 2 >> 3);
}

/* I'm having issues with these operators
//TODO: Investigate.
TEST(Vector2, Equal)
{
    mim::vec2f v1(1.0f, 2.0f);
    mim::vec2f v2(1.0f, 2.0f);
    EXPECT_TRUE(v1 == v2);
}

TEST(Vector2, NotEqual)
{
    mim::vec2f v1(1.0f, 2.0f);
    mim::vec2f v2(3.0f, 4.0f);
    EXPECT_TRUE(v1 != v2);
}

TEST(Vector2, LessThan)
{
    mim::vec2f v1(1.0f, 2.0f);
    mim::vec2f v2(3.0f, 4.0f);
    EXPECT_TRUE(v1 < v2);
}

TEST(Vector2, LessThanEqual)
{
    mim::vec2f v1(1.0f, 2.0f);
    mim::vec2f v2(3.0f, 4.0f);
    mim::vec2f v3(1.0f, 2.0f);
    EXPECT_TRUE(v1 <= v2);
    EXPECT_TRUE(v1 <= v3);
}

TEST(Vector2, GreaterThan)
{
    mim::vec2f v1(1.0f, 2.0f);
    mim::vec2f v2(3.0f, 4.0f);
    EXPECT_TRUE(v2 > v1);
}

TEST(Vector2, GreaterThanEqual)
{
    mim::vec2f v1(1.0f, 2.0f);
    mim::vec2f v2(3.0f, 4.0f);
    mim::vec2f v3(1.0f, 2.0f);
    EXPECT_TRUE(v2 >= v1);
    EXPECT_TRUE(v1 >= v3);
}

TEST(Vector2, StreamOutput)
{
    mim::vec2f v1(1.0f, 2.0f);
    std::stringstream ss;
    ss << v1;
    EXPECT_EQ(ss.str(), "vec2(1, 2)");
}

TEST(Vector2, StreamInput)
{
    mim::vec2f v1;
    std::stringstream ss;
    ss << "1 2";
    ss >> v1;
    EXPECT_EQ(v1.x, 1.0f);
    EXPECT_EQ(v1.y, 2.0f);
}
*/

TEST(Vector2, Size)
{
    mim::vec2f v1(1.0f, 2.0f);
    EXPECT_EQ(v1.size(), 2);
}






