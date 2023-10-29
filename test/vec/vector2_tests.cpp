// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#include <mim/vec.hpp>
#include <gtest/gtest.h>

// TODO: We are still missing many tests for core vector2 functionality. Aim to try and add more over time.


// Element Accessors

TEST(Vector2Defaults, Data)
{
    mim::vec2f v(1.0f, 2.0f);
	EXPECT_EQ(v.x, 1.0f);
	EXPECT_EQ(v.y, 2.0f);
}

TEST(Vector2Defaults, SizeFunction)
{
	mim::vec2f v;
	EXPECT_EQ(v.size(), 2);
}

TEST(Vector2Defaults, ElementAccessors)
{
	mim::vec2f v(1.0f, 2.0f);
    EXPECT_EQ(v[0], 1.0f);
    EXPECT_EQ(v[1], 2.0f);
    EXPECT_EQ(v.at(0), 1.0f);
    EXPECT_EQ(v.at(1), 2.0f);
}


// Constructors

TEST(Vector2Defaults, DefaultConstructor)
{
    mim::vec2f v;
    EXPECT_EQ(v.x, 0.0f);
    EXPECT_EQ(v.y, 0.0f);
}

TEST(Vector2Defaults, ValueConstructor)
{
    mim::vec2f v(1.0f, 2.0f);
    EXPECT_EQ(v.x, 1.0f);
    EXPECT_EQ(v.y, 2.0f);
}

TEST(Vector2Defaults, CopyConstructor)
{
    mim::vec2f v1(1.0f, 2.0f);
    mim::vec2f v2(v1);
    EXPECT_EQ(v2.x, 1.0f);
    EXPECT_EQ(v2.y, 2.0f);
}

TEST(Vector2Defaults, ScalarConstructor)
{
	mim::vec2f v(1.0f);
	EXPECT_EQ(v.x, 1.0f);
	EXPECT_EQ(v.y, 1.0f);
}

TEST(Vector2Defaults, ValueConstructorWithTemplate)
{
	mim::vec2f v(1.0f, 2.0f);
    mim::vec2d v2(v);
    EXPECT_EQ(v2.x, 1.0f);
    EXPECT_EQ(v2.y, 2.0f);
}

TEST(Vector2Defaults, ConstructorWithLeftVec1RightScalar)
{
    mim::vec1f v(1.0f);
    mim::vec2f v2(v, 3.0f);
    EXPECT_EQ(v2.x, 1.0f);
    EXPECT_EQ(v2.y, 3.0f);
}

TEST(Vector2Defaults, ConstructorWithLeftScalarRightVec1)
{
    mim::vec1f v(1.0f);
    mim::vec2f v2(3.0f, v);
    EXPECT_EQ(v2.x, 3.0f);
    EXPECT_EQ(v2.y, 1.0f);
}

TEST(Vector2Defaults, ConstructorWithLeftVec1RightVec1)
{
    mim::vec1f v(1.0f);
    mim::vec2f v2(v, v);
    EXPECT_EQ(v2.x, 1.0f);
    EXPECT_EQ(v2.y, 1.0f);
}

TEST(Vector2Defaults, Vector2Constructor)
{
    mim::vec2f v1(1.0f, 2.0f);
    mim::vec2f v2(v1);
    EXPECT_EQ(v2.x, 1.0f);
    EXPECT_EQ(v2.y, 2.0f);
}

TEST(Vector2Defaults, Vector3Constructor)
{
    mim::vec3f v1(1.0f, 2.0f, 3.0f);
    mim::vec2f v2(v1);
    EXPECT_EQ(v2.x, 1.0f);
    EXPECT_EQ(v2.y, 2.0f);
}

TEST(Vector2Defaults, Vector4Constructor)
{
    mim::vec4f v1(1.0f, 2.0f, 3.0f, 4.0f);
    mim::vec2f v2(v1);
    EXPECT_EQ(v2.x, 1.0f);
    EXPECT_EQ(v2.y, 2.0f);
}


// Assignment Operators

TEST(Vector2Defaults, ScalarAssignment)
{
    mim::vec2f v;
    v = 1.0f;
    EXPECT_EQ(v.x, 1.0f);
    EXPECT_EQ(v.y, 1.0f);
}

TEST(Vector2Defaults, CopyAssignment)
{
    mim::vec2f v1(1.0f, 2.0f);
    mim::vec2f v2;
    v2 = v1;
    EXPECT_EQ(v2.x, 1.0f);
    EXPECT_EQ(v2.y, 2.0f);
}

TEST(Vector2Defaults, CopyAssignmentTemplated)
{
	mim::vec2d v1(1.0f, 2.0f);
	mim::vec2f v2;
	v2 = v1;
	EXPECT_EQ(v2.x, 1.0f);
	EXPECT_EQ(v2.y, 2.0f);
}

TEST(Vector2Defaults, AdditionAssignmentScalar)
{
    mim::vec2f v(1.0f, 2.0f);
    v += 1.0f;
    EXPECT_EQ(v.x, 2.0f);
    EXPECT_EQ(v.y, 3.0f);
}

TEST(Vector2Defaults, AdditionAssignmentVec1)
{
    mim::vec2f v1(1.0f, 2.0f);
    mim::vec1f v2(3.0f);
    v1 += v2;
    EXPECT_EQ(v1.x, 4.0f);
    EXPECT_EQ(v1.y, 5.0f);
}

TEST(Vector2Defaults, AdditionAssignmentVec2)
{
    mim::vec2f v1(1.0f, 2.0f);
    mim::vec2f v2(3.0f, 4.0f);
    v1 += v2;
    EXPECT_EQ(v1.x, 4.0f);
    EXPECT_EQ(v1.y, 6.0f);
}

TEST(Vector2Defaults, MultiplicationAssignment)
{
    mim::vec2f v1(1.0f, 2.0f);
    mim::vec2f v2(3.0f, 4.0f);
    v1 *= v2;
    EXPECT_EQ(v1.x, 3.0f);
    EXPECT_EQ(v1.y, 8.0f);
}

TEST(Vector2Defaults, DivisionAssignment)
{
    mim::vec2f v1(1.0f, 2.0f);
    mim::vec2f v2(3.0f, 4.0f);
    v1 /= v2;
    EXPECT_EQ(v1.x, 1.0f / 3.0f);
    EXPECT_EQ(v1.y, 2.0f / 4.0f);
}

TEST(Vector2Defaults, AdditionScalar)
{
    mim::vec2f v1(1.0f, 2.0f);
    mim::vec2f v2 = v1 + 3.0f;
    EXPECT_EQ(v2.x, 4.0f);
    EXPECT_EQ(v2.y, 5.0f);
}

TEST(Vector2Defaults, SubtractionScalar)
{
    mim::vec2f v1(1.0f, 2.0f);
    mim::vec2f v2 = v1 - 3.0f;
    EXPECT_EQ(v2.x, -2.0f);
    EXPECT_EQ(v2.y, -1.0f);
}

TEST(Vector2Defaults, MultiplicationScalar)
{
    mim::vec2f v1(1.0f, 2.0f);
    mim::vec2f v2 = v1 * 3.0f;
    EXPECT_EQ(v2.x, 3.0f);
    EXPECT_EQ(v2.y, 6.0f);
}

TEST(Vector2Defaults, DivisionScalar)
{
    mim::vec2f v1(1.0f, 2.0f);
    mim::vec2f v2 = v1 / 3.0f;
    EXPECT_EQ(v2.x, 1.0f / 3.0f);
    EXPECT_EQ(v2.y, 2.0f / 3.0f);
}

TEST(Vector2Defaults, AdditionScalarAssignment)
{
    mim::vec2f v1(1.0f, 2.0f);
    v1 += 3.0f;
    EXPECT_EQ(v1.x, 4.0f);
    EXPECT_EQ(v1.y, 5.0f);
}

TEST(Vector2Defaults, SubtractionScalarAssignment)
{
    mim::vec2f v1(1.0f, 2.0f);
    v1 -= 3.0f;
    EXPECT_EQ(v1.x, -2.0f);
    EXPECT_EQ(v1.y, -1.0f);
}

TEST(Vector2Defaults, MultiplicationScalarAssignment)
{
    mim::vec2f v1(1.0f, 2.0f);
    v1 *= 3.0f;
    EXPECT_EQ(v1.x, 3.0f);
    EXPECT_EQ(v1.y, 6.0f);
}

TEST(Vector2Defaults, DivisionScalarAssignment)
{
    mim::vec2f v1(1.0f, 2.0f);
    v1 /= 3.0f;
    EXPECT_EQ(v1.x, 1.0f / 3.0f);
    EXPECT_EQ(v1.y, 2.0f / 3.0f);
}

TEST(Vector2Defaults, BitwiseAndAssignment)
{
	mim::vec2i v1(1, 2);
	mim::vec2i v2(3, 4);
	v1 &= v2;
	EXPECT_EQ(v1.x, 1 & 3);
	EXPECT_EQ(v1.y, 2 & 4);
}

TEST(Vector2Defaults, BitwiseOrAssignment)
{
	mim::vec2i v1(1, 2);
	mim::vec2i v2(3, 4);
	v1 |= v2;
	EXPECT_EQ(v1.x, 1 | 3);
	EXPECT_EQ(v1.y, 2 | 4);
}

TEST(Vector2Defaults, BitwiseXorAssignment)
{
	mim::vec2i v1(1, 2);
	mim::vec2i v2(3, 4);
	v1 ^= v2;
	EXPECT_EQ(v1.x, 1 ^ 3);
	EXPECT_EQ(v1.y, 2 ^ 4);
}

TEST(Vector2Defaults, BitwiseLeftShift)
{
	mim::vec2i v1(1, 2);
	mim::vec2i v2 = v1 << 3;
	EXPECT_EQ(v2.x, 1 << 3);
	EXPECT_EQ(v2.y, 2 << 3);
}

TEST(Vector2Defaults, BitwiseRightShift)
{
	mim::vec2i v1(1, 2);
	mim::vec2i v2 = v1 >> 3;
	EXPECT_EQ(v2.x, 1 >> 3);
	EXPECT_EQ(v2.y, 2 >> 3);
}

TEST(Vector2Defaults, BitwiseLeftShiftAssignment)
{
	mim::vec2i v1(1, 2);
	v1 <<= 3;
	EXPECT_EQ(v1.x, 1 << 3);
	EXPECT_EQ(v1.y, 2 << 3);
}

TEST(Vector2Defaults, BitwiseRightShiftAssignment)
{
	mim::vec2i v1(1, 2);
	v1 >>= 3;
	EXPECT_EQ(v1.x, 1 >> 3);
	EXPECT_EQ(v1.y, 2 >> 3);
}

TEST(Vector2Defaults, Addition)
{
	mim::vec2f v1(1.0f, 2.0f);
	mim::vec2f v2(3.0f, 4.0f);
	mim::vec2f v3 = v1 + v2;
	EXPECT_EQ(v3.x, 4.0f);
	EXPECT_EQ(v3.y, 6.0f);
}

TEST(Vector2Defaults, Subtraction)
{
	mim::vec2f v1(1.0f, 2.0f);
	mim::vec2f v2(3.0f, 4.0f);
	mim::vec2f v3 = v1 - v2;
	EXPECT_EQ(v3.x, -2.0f);
	EXPECT_EQ(v3.y, -2.0f);
}

TEST(Vector2Defaults, Multiplication)
{
	mim::vec2f v1(1.0f, 2.0f);
	mim::vec2f v2(3.0f, 4.0f);
	mim::vec2f v3 = v1 * v2;
	EXPECT_EQ(v3.x, 3.0f);
	EXPECT_EQ(v3.y, 8.0f);
}

TEST(Vector2Defaults, Division)
{
	mim::vec2f v1(1.0f, 2.0f);
	mim::vec2f v2(3.0f, 4.0f);
	mim::vec2f v3 = v1 / v2;
	EXPECT_EQ(v3.x, 1.0f / 3.0f);
	EXPECT_EQ(v3.y, 2.0f / 4.0f);
}

/* I'm having issues with this operator
//TODO: Investigate.
TEST(Vector2Defaults, BitwiseNot)
{
	mim::vec2i v1(1, 2);
	mim::vec2i v2 = ~v1;
	EXPECT_EQ(v2.x, ~1);
	EXPECT_EQ(v2.y, ~2);
}
*/

TEST(Vector2Defaults, BitwiseAnd)
{
	mim::vec2i v1(1, 2);
	mim::vec2i v2(3, 4);
	mim::vec2i v3 = v1 & v2;
	EXPECT_EQ(v3.x, 1 & 3);
	EXPECT_EQ(v3.y, 2 & 4);
}

TEST(Vector2Defaults, BitwiseOr)
{
	mim::vec2i v1(1, 2);
	mim::vec2i v2(3, 4);
	mim::vec2i v3 = v1 | v2;
	EXPECT_EQ(v3.x, 1 | 3);
	EXPECT_EQ(v3.y, 2 | 4);
}

TEST(Vector2Defaults, BitwiseXor)
{
	mim::vec2i v1(1, 2);
	mim::vec2i v2(3, 4);
	mim::vec2i v3 = v1 ^ v2;
	EXPECT_EQ(v3.x, 1 ^ 3);
	EXPECT_EQ(v3.y, 2 ^ 4);
}

/* I'm having issues with these operators
//TODO: Investigate.
TEST(Vector2Defaults, Equal)
{
    mim::vec2f v1(1.0f, 2.0f);
    mim::vec2f v2(1.0f, 2.0f);
    EXPECT_TRUE(v1 == v2);
}

TEST(Vector2Defaults, NotEqual)
{
    mim::vec2f v1(1.0f, 2.0f);
    mim::vec2f v2(3.0f, 4.0f);
    EXPECT_TRUE(v1 != v2);
}

TEST(Vector2Defaults, LessThan)
{
    mim::vec2f v1(1.0f, 2.0f);
    mim::vec2f v2(3.0f, 4.0f);
    EXPECT_TRUE(v1 < v2);
}

TEST(Vector2Defaults, LessThanEqual)
{
    mim::vec2f v1(1.0f, 2.0f);
    mim::vec2f v2(3.0f, 4.0f);
    mim::vec2f v3(1.0f, 2.0f);
    EXPECT_TRUE(v1 <= v2);
    EXPECT_TRUE(v1 <= v3);
}

TEST(Vector2Defaults, GreaterThan)
{
    mim::vec2f v1(1.0f, 2.0f);
    mim::vec2f v2(3.0f, 4.0f);
    EXPECT_TRUE(v2 > v1);
}

TEST(Vector2Defaults, GreaterThanEqual)
{
    mim::vec2f v1(1.0f, 2.0f);
    mim::vec2f v2(3.0f, 4.0f);
    mim::vec2f v3(1.0f, 2.0f);
    EXPECT_TRUE(v2 >= v1);
    EXPECT_TRUE(v1 >= v3);
}

TEST(Vector2Defaults, StreamOutput)
{
    mim::vec2f v1(1.0f, 2.0f);
    std::stringstream ss;
    ss << v1;
    EXPECT_EQ(ss.str(), "vec2(1, 2)");
}

TEST(Vector2Defaults, StreamInput)
{
    mim::vec2f v1;
    std::stringstream ss;
    ss << "1 2";
    ss >> v1;
    EXPECT_EQ(v1.x, 1.0f);
    EXPECT_EQ(v1.y, 2.0f);
}
*/

TEST(Vector2Defaults, Size)
{
    mim::vec2f v1(1.0f, 2.0f);
    EXPECT_EQ(v1.size(), 2);
}






