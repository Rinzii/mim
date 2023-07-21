// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#include <mim/vec.hpp>
#include <gtest/gtest.h>


// TODO: We are still missing many tests for core vector1 functionality. Aim to try and add more over time.


// Accessors

TEST(Vector1Defaults, ElementsAccessor)
{
	mim::vec1f v1f(1.0f);
	mim::vec1d v1d(1.0);
	mim::vec1i v1i(1);
	mim::vec1u v1u(1u);
	mim::vec1b v1b(true);
	EXPECT_EQ(v1f.x, 1.0f);
	EXPECT_EQ(v1d.x, 1.0);
	EXPECT_EQ(v1i.x, 1);
	EXPECT_EQ(v1u.x, 1u);
	EXPECT_EQ(v1b.x, true);
}

TEST(Vector1Defaults, Size)
{
	mim::vec1f v1(1.0f);
	EXPECT_EQ(v1.size(), 1);
}

TEST(Vector1Defaults, ArrayAccessor)
{
	mim::vec1f v1(1.0f);
	EXPECT_EQ(v1[0], 1.0f);
}

TEST(Vector1Defaults, AtAccessor)
{
	mim::vec1f v1(1.0f);
	// TODO: Look into this issue. This test fails to compile.
	//EXPECT_EQ(v1.at(0), 1.0f);
}


// Constructors

TEST(Vector1Defaults, DefaultConstructor)
{
    mim::vec1f vf;
	mim::vec1d vd;
	mim::vec1i vi;
	mim::vec1u vu;
	mim::vec1b vb;
    EXPECT_EQ(vf.x, 0.0f);
	EXPECT_EQ(vd.x, 0.0);
	EXPECT_EQ(vi.x, 0);
	EXPECT_EQ(vu.x, 0u);
	EXPECT_EQ(vb.x, false);
}

TEST(Vector1Defaults, CopyConstructor)
{
	mim::vec1f v1f(1.0f);
	mim::vec1d v1d(1.0);
	mim::vec1i v1i(1);
	mim::vec1u v1u(1u);
	mim::vec1b v1b(true);
	mim::vec1f v2f(v1f);
	mim::vec1d v2d(v1d);
	mim::vec1i v2i(v1i);
	mim::vec1u v2u(v1u);
	mim::vec1b v2b(v1b);
	EXPECT_EQ(v2f.x, 1.0f);
	EXPECT_EQ(v2d.x, 1.0);
	EXPECT_EQ(v2i.x, 1);
	EXPECT_EQ(v2u.x, 1u);
	EXPECT_EQ(v2b.x, true);
}

TEST(Vector1Defaults, CopyConstructorWithQualifier)
{
	mim::lowp_vec1 v1(1.0f);
	mim::vec1f v2(v1);
	EXPECT_EQ(v2.x, 1.0f);
}

TEST(Vector1Defaults, ValueConstructor)
{
    mim::vec1f vf(1.0f);
	mim::vec1d vd(1.0);
	mim::vec1i vi(1);
	mim::vec1u vu(1u);
	mim::vec1b vb(true);
    EXPECT_EQ(vf.x, 1.0f);
	EXPECT_EQ(vd.x, 1.0);
	EXPECT_EQ(vi.x, 1);
	EXPECT_EQ(vu.x, 1u);
	EXPECT_EQ(vb.x, true);
}

TEST(Vector1Defaults, QualifierConstructor)
{
    mim::vec1f vf(1.0f);
    mim::highp_vec1 vhf(vf);
	mim::mediump_vec1 vmf(vf);
	mim::lowp_vec1 vlf(vf);
    EXPECT_EQ(vhf.x, 1.0f);
	EXPECT_EQ(vmf.x, 1.0f);
	EXPECT_EQ(vlf.x, 1.0f);
}

TEST(Vector1Defaults, Vector2Constructor)
{
	mim::vec2f v2f(1.0f, 2.0f);
    mim::vec2d v2d(1.0, 2.0);
    mim::vec2i v2i(1, 2);
    mim::vec2u v2u(1u, 2u);
    mim::vec2b v2b(true, false);
    mim::vec1f v1f(v2f);
    mim::vec1d v1d(v2d);
    mim::vec1i v1i(v2i);
    mim::vec1u v1u(v2u);
    mim::vec1b v1b(v2b);
    EXPECT_EQ(v1f.x, 1.0f);
    EXPECT_EQ(v1d.x, 1.0);
    EXPECT_EQ(v1i.x, 1);
    EXPECT_EQ(v1u.x, 1u);
    EXPECT_EQ(v1b.x, true);
}

TEST(Vector1Defaults, Vector3Constructor)
{
	mim::vec3f v3f(1.0f, 2.0f, 3.0f);
    mim::vec3d v3d(1.0, 2.0, 3.0);
    mim::vec3i v3i(1, 2, 3);
    mim::vec3u v3u(1u, 2u, 3u);
    mim::vec3b v3b(true, false, true);
    mim::vec1f v1f(v3f);
    mim::vec1d v1d(v3d);
    mim::vec1i v1i(v3i);
    mim::vec1u v1u(v3u);
    mim::vec1b v1b(v3b);
    EXPECT_EQ(v1f.x, 1.0f);
    EXPECT_EQ(v1d.x, 1.0);
    EXPECT_EQ(v1i.x, 1);
    EXPECT_EQ(v1u.x, 1u);
    EXPECT_EQ(v1b.x, true);
}

TEST(Vector1Defaults, Vector4Constructor)
{
	mim::vec4f v4f(1.0f, 2.0f, 3.0f, 4.0f);
    mim::vec4d v4d(1.0, 2.0, 3.0, 4.0);
    mim::vec4i v4i(1, 2, 3, 4);
    mim::vec4u v4u(1u, 2u, 3u, 4u);
    mim::vec4b v4b(true, false, true, false);
    mim::vec1f v1f(v4f);
    mim::vec1d v1d(v4d);
    mim::vec1i v1i(v4i);
    mim::vec1u v1u(v4u);
    mim::vec1b v1b(v4b);
    EXPECT_EQ(v1f.x, 1.0f);
    EXPECT_EQ(v1d.x, 1.0);
    EXPECT_EQ(v1i.x, 1);
    EXPECT_EQ(v1u.x, 1u);
    EXPECT_EQ(v1b.x, true);
}

// Assignment operators

TEST(Vector1Defaults, AssignmentOperator)
{
	mim::vec1f v1f(1.0f);
    mim::vec1d v1d(1.0);
    mim::vec1i v1i(1);
    mim::vec1u v1u(1u);
    mim::vec1b v1b(true);
    v1f = 2.0f;
	v1d = 2.0;
	v1i = 2;
	v1u = 2u;
	v1b = false;
    EXPECT_EQ(v1f.x, 2.0f);
    EXPECT_EQ(v1d.x, 2.0);
    EXPECT_EQ(v1i.x, 2);
    EXPECT_EQ(v1u.x, 2u);
    EXPECT_EQ(v1b.x, false);

}

TEST(Vector1Defaults, CopyAssignment)
{
    mim::vec1f v1f(1.0f);
	mim::vec1d v1d(1.0);
	mim::vec1i v1i(1);
	mim::vec1u v1u(1u);
	mim::vec1b v1b(true);
	mim::vec1f v2f;
	mim::vec1d v2d;
	mim::vec1i v2i;
	mim::vec1u v2u;
	mim::vec1b v2b;
	v2f = v1f;
	v2d = v1d;
	v2i = v1i;
	v2u = v1u;
	v2b = v1b;
    EXPECT_EQ(v2f.x, 1.0f);
	EXPECT_EQ(v2d.x, 1.0);
	EXPECT_EQ(v2i.x, 1);
	EXPECT_EQ(v2u.x, 1u);
	EXPECT_EQ(v2b.x, true);
}

TEST(Vector1Defaults, AdditionAssignment)
{
	mim::vec1f v1f(10.0f);
	mim::vec1f v2f(20.0f);
	v1f += v2f;
	EXPECT_EQ(v1f.x, 30.0f);
}

TEST(Vector1Defaults, SubtractionAssignment)
{
	mim::vec1f v1(1.0f);
	mim::vec1f v2(2.0f);
	v1 -= v2;
	EXPECT_EQ(v1.x, -1.0f);
}

TEST(Vector1Defaults, MultiplicationAssignment)
{
	mim::vec1f v1(2.0f);
	mim::vec1f v2(3.0f);
	v1 *= v2;
	EXPECT_EQ(v1.x, 6.0f);
}

TEST(Vector1Defaults, DivisionAssignment)
{
	mim::vec1f v1(6.0f);
	mim::vec1f v2(3.0f);
	v1 /= v2;
	EXPECT_EQ(v1.x, 2.0f);
}

TEST(Vector1Defaults, AdditionScalarAssignment)
{
	mim::vec1f v1(1.0f);
	v1 += 2.0f;
	EXPECT_EQ(v1.x, 3.0f);
}

TEST(Vector1Defaults, SubtractionScalarAssignment)
{
	mim::vec1f v1(1.0f);
	v1 -= 2.0f;
	EXPECT_EQ(v1.x, -1.0f);
}

TEST(Vector1Defaults, MultiplicationScalarAssignment)
{
	mim::vec1f v1(2.0f);
	v1 *= 3.0f;
	EXPECT_EQ(v1.x, 6.0f);
}

TEST(Vector1Defaults, DivisionScalarAssignment)
{
	mim::vec1f v1(6.0f);
	v1 /= 3.0f;
	EXPECT_EQ(v1.x, 2.0f);
}


// Increment and Decrement Operators

TEST(Vector1Defaults, Increment)
{
	mim::vec1f v1(1.0f);
	mim::vec1f v2 = ++v1;
	EXPECT_EQ(v1.x, 2.0f);
	EXPECT_EQ(v2.x, 2.0f);
}

TEST(Vector1Defaults, Decrement)
{
	mim::vec1f v1(1.0f);
	mim::vec1f v2 = --v1;
	EXPECT_EQ(v1.x, 0.0f);
	EXPECT_EQ(v2.x, 0.0f);
}


// Bitwise Assignment Operators

TEST(Vector1Defaults, ModuloAssignmentScalar)
{
	mim::vec1i v1(5);
	v1 %= 3.0f;
	EXPECT_EQ(v1.x, 2.0f);
}


TEST(Vector1Defaults, ModuloAssignmentVector)
{
	mim::vec1i v1(5);
	mim::vec1f v2(3.0f);
	v1 %= v2;
	EXPECT_EQ(v1.x, 2.0f);
}

TEST(Vector1Defaults, BitwiseAndAssignmentScalar)
{
	mim::vec1i v1(5);
	v1 &= 3.0f;
	EXPECT_EQ(v1.x, 1.0f);
}

TEST(Vector1Defaults, BitwiseAndAssignmentVector)
{
	mim::vec1i v1(5);
	mim::vec1f v2(3.0f);
	v1 &= v2;
	EXPECT_EQ(v1.x, 1.0f);
}

TEST(Vector1Defaults, BitwiseOrAssignmentScalar)
{
	mim::vec1i v1(5);
	v1 |= 3.0f;
	EXPECT_EQ(v1.x, 7.0f);
}

TEST(Vector1Defaults, BitwiseOrAssignmentVector)
{
	mim::vec1i v1(5);
	mim::vec1f v2(3.0f);
	v1 |= v2;
	EXPECT_EQ(v1.x, 7.0f);
}

TEST(Vector1Defaults, BitwiseXorAssignmentScalar)
{
	mim::vec1i v1(5);
	v1 ^= 3.0f;
	EXPECT_EQ(v1.x, 6.0f);
}

TEST(Vector1Defaults, BitwiseXorAssignmentVector)
{
	mim::vec1i v1(5);
	mim::vec1f v2(3.0f);
	v1 ^= v2;
	EXPECT_EQ(v1.x, 6.0f);
}

TEST(Vector1Defaults, LeftShiftAssignmentScalar)
{
	mim::vec1i v1(5);
	v1 <<= 3.0f;
	EXPECT_EQ(v1.x, 40.0f);
}

TEST(Vector1Defaults, LeftShiftAssignmentVector)
{
	mim::vec1i v1(5);
	mim::vec1f v2(3.0f);
	v1 <<= v2;
	EXPECT_EQ(v1.x, 40.0f);
}

TEST(Vector1Defaults, RightShiftAssignmentScalar)
{
	mim::vec1i v1(5);
	v1 >>= 3.0f;
	EXPECT_EQ(v1.x, 0.0f);
}

TEST(Vector1Defaults, RightShiftAssignmentVector)
{
	mim::vec1i v1(5);
	mim::vec1f v2(3.0f);
	v1 >>= v2;
	EXPECT_EQ(v1.x, 0.0f);
}




// Unary Operators

TEST(Vector1Defaults, Negation)
{
	mim::vec1f v1(1.0f);
	mim::vec1f v2 = -v1;
	EXPECT_EQ(v2.x, -1.0f);
}

TEST(Vector1Defaults, Addition)
{
    mim::vec1f v1f(1.0f);
	mim::vec1d v1d(1.0);
	mim::vec1i v1i(1);
	mim::vec1u v1u(1u);
	mim::vec1b v1b(true);
	mim::vec1f v2f(2.0f);
	mim::vec1d v2d(2.0);
	mim::vec1i v2i(2);
	mim::vec1u v2u(2u);
	mim::vec1b v2b(false);
	mim::vec1f v3f = v1f + v2f;
	mim::vec1d v3d = v1d + v2d;
	mim::vec1i v3i = v1i + v2i;
	mim::vec1u v3u = v1u + v2u;
	mim::vec1b v3b = v1b + v2b;
    EXPECT_EQ(v3f.x, 3.0f);
	EXPECT_EQ(v3d.x, 3.0);
	EXPECT_EQ(v3i.x, 3);
	EXPECT_EQ(v3u.x, 3u);
	EXPECT_EQ(v3b.x, true);
}

TEST(Vector1Defaults, Subtraction)
{
    mim::vec1f v1f(1.0f);
	mim::vec1d v1d(1.0);
	mim::vec1i v1i(1);
	mim::vec1u v1u(1u);
	mim::vec1b v1b(true);
	mim::vec1f v2f(2.0f);
	mim::vec1d v2d(2.0);
	mim::vec1i v2i(2);
	mim::vec1u v2u(2u);
	mim::vec1b v2b(false);
	mim::vec1f v3f = v1f - v2f;
	mim::vec1d v3d = v1d - v2d;
	mim::vec1i v3i = v1i - v2i;
	mim::vec1u v3u = v1u - v2u;
	mim::vec1b v3b = v1b - v2b;
    EXPECT_EQ(v3f.x, -1.0f);
	EXPECT_EQ(v3d.x, -1.0);
	EXPECT_EQ(v3i.x, -1);
	EXPECT_EQ(v3u.x, -1u);
	EXPECT_EQ(typeid(unsigned int), typeid(v3u.x));
	EXPECT_EQ(v3b.x, true);
}

TEST(Vector1Defaults, Multiplication)
{
    mim::vec1f v1f(4.0f);
	mim::vec1d v1d(4.0);
	mim::vec1i v1i(4);
	mim::vec1u v1u(4u);
	mim::vec1b v1b(true);
	mim::vec1f v2f(2.0f);
	mim::vec1d v2d(2.0);
	mim::vec1i v2i(2);
	mim::vec1u v2u(2u);
	mim::vec1b v2b(false);
	mim::vec1f v3f = v1f * v2f;
	mim::vec1d v3d = v1d * v2d;
	mim::vec1i v3i = v1i * v2i;
	mim::vec1u v3u = v1u * v2u;
	mim::vec1b v3b = v1b * v2b;
    EXPECT_EQ(v3f.x, 8.0f);
	EXPECT_EQ(v3d.x, 8.0);
	EXPECT_EQ(v3i.x, 8);
	EXPECT_EQ(v3u.x, 8u);
	EXPECT_EQ(v3b.x, false);
}

TEST(Vector1Defaults, Division)
{
    mim::vec1f v1f(16.0f);
	mim::vec1d v1d(16.0);
	mim::vec1i v1i(16);
	mim::vec1u v1u(16u);
	mim::vec1f v2f(2.0f);
	mim::vec1d v2d(2.0);
	mim::vec1i v2i(2);
	mim::vec1u v2u(2u);
	mim::vec1f v3f = v1f / v2f;
	mim::vec1d v3d = v1d / v2d;
	mim::vec1i v3i = v1i / v2i;
	mim::vec1u v3u = v1u / v2u;
    EXPECT_EQ(v3f.x, 8.0f);
	EXPECT_EQ(v3d.x, 8.0);
	EXPECT_EQ(v3i.x, 8);
	EXPECT_EQ(v3u.x, 8u);
}

TEST(Vector1Defaults, AdditionScalar)
{
    mim::vec1f v1(1.0f);
    mim::vec1f v2 = v1 + 2.0f;
    EXPECT_EQ(v2.x, 3.0f);
}

TEST(Vector1Defaults, SubtractionScalar)
{
    mim::vec1f v1(1.0f);
    mim::vec1f v2 = v1 - 2.0f;
    EXPECT_EQ(v2.x, -1.0f);
}

TEST(Vector1Defaults, MultiplicationScalar)
{
    mim::vec1f v1(2.0f);
    mim::vec1f v2 = v1 * 3.0f;
    EXPECT_EQ(v2.x, 6.0f);
}

TEST(Vector1Defaults, DivisionScalar)
{
    mim::vec1f v1(6.0f);
    mim::vec1f v2 = v1 / 3.0f;
    EXPECT_EQ(v2.x, 2.0f);
}


// Bitwise Operators

TEST(Vector1Defaults, ModuloScalar)
{
    mim::vec1i v1(5);
    mim::vec1i v2 = v1 % 3;
    EXPECT_EQ(v2.x, 2);
}


TEST(Vector1Defaults, ModuloScalarReversed)
{
    mim::vec1i v1(5);
    mim::vec1i v2 = 16 % v1;

    EXPECT_EQ(v2.x, 1);
}

TEST(Vector1Defaults, ModuloVector)
{
	mim::vec1i v1(5);
    mim::vec1i v2 = v1 % mim::vec1i(3);
    EXPECT_EQ(v2.x, 2);
}

TEST(Vector1Defaults, BitwiseAndScalar)
{
    mim::vec1i v1(5);
    mim::vec1i v2 = v1 & 3;
    EXPECT_EQ(v2.x, 1);
}

TEST(Vector1Defaults, BitwiseAndScalarReversed)
{
    mim::vec1i v1(5);
    mim::vec1i v2 = 3 & v1;
    EXPECT_EQ(v2.x, 1);
}

TEST(Vector1Defaults, BitwiseAndVector)
{
    mim::vec1i v1(5);
    mim::vec1i v2 = v1 & mim::vec1i(3);
    EXPECT_EQ(v2.x, 1);
}

TEST(Vector1Defaults, BitwiseOrScalar)
{
    mim::vec1i v1(5);
    mim::vec1i v2 = v1 | 3;
    EXPECT_EQ(v2.x, 7);
}

TEST(Vector1Defaults, BitwiseOrScalarReversed)
{
    mim::vec1i v1(5);
    mim::vec1i v2 = 3 | v1;
    EXPECT_EQ(v2.x, 7);
}

TEST(Vector1Defaults, BitwiseOrVector)
{
    mim::vec1i v1(5);
    mim::vec1i v2 = v1 | mim::vec1i(3);
    EXPECT_EQ(v2.x, 7);
}

TEST(Vector1Defaults, BitwiseXorScalar)
{
    mim::vec1i v1(5);
    mim::vec1i v2 = v1 ^ 3;
    EXPECT_EQ(v2.x, 6);
}

TEST(Vector1Defaults, BitwiseXorScalarReversed)
{
    mim::vec1i v1(5);
    mim::vec1i v2 = 3 ^ v1;
    EXPECT_EQ(v2.x, 6);
}

TEST(Vector1Defaults, BitwiseXorVector)
{
    mim::vec1i v1(5);
    mim::vec1i v2 = v1 ^ mim::vec1i(3);
    EXPECT_EQ(v2.x, 6);
}

TEST(Vector1Defaults, BitwiseLeftShiftScalar)
{
    mim::vec1i v1(5);
    mim::vec1i v2 = v1 << 3;
    EXPECT_EQ(v2.x, 40);
}

TEST(Vector1Defaults, BitwiseLeftShiftScalarReversed)
{
    mim::vec1i v1(5);
    mim::vec1i v2 = 3 << v1;
    EXPECT_EQ(v2.x, 96);
}

TEST(Vector1Defaults, BitwiseLeftShiftVector)
{
    mim::vec1i v1(5);
    mim::vec1i v2 = v1 << mim::vec1i(3);
    EXPECT_EQ(v2.x, 40);
}

TEST(Vector1Defaults, BitwiseRightShiftScalar)
{
    mim::vec1i v1(40);
    mim::vec1i v2 = v1 >> 3;
    EXPECT_EQ(v2.x, 5);
}

TEST(Vector1Defaults, BitwiseRightShiftScalarReversed)
{
    mim::vec1i v1(40);
    mim::vec1i v2 = 3 >> v1;
    EXPECT_EQ(v2.x, 0);
}

TEST(Vector1Defaults, BitwiseRightShiftVector)
{
    mim::vec1i v1(40);
    mim::vec1i v2 = v1 >> mim::vec1i(3);
    EXPECT_EQ(v2.x, 5);
}


TEST(Vector1Defaults, BitwiseNot)
{
	mim::vec1i v1(5);
    mim::vec1i v2 = ~v1;
    EXPECT_EQ(v2.x, -6);
}

TEST(Vector1Defaults, Equality)
{
	mim::vec1f v1(1.0f);
	mim::vec1f v2(1.0f);
	EXPECT_TRUE(v1 == v2);
}

TEST(Vector1Defaults, Inequality)
{
	mim::vec1f v1(1.0f);
	mim::vec1f v2(2.0f);
	EXPECT_TRUE(v1 != v2);
}

TEST(Vector1Defaults, LogicalAnd)
{
	mim::vec1b v1(true);
	mim::vec1b v2(true);

	EXPECT_EQ((v1 && v2), true);
}


TEST(Vector1Defaults, LogicalOr)
{
    mim::vec1b v1(true);
    mim::vec1b v2(false);

    EXPECT_EQ((v1 || v2), true);
}

TEST(Vector1Defaults, length)
{
	mim::vec1f v1(3.0f);
	mim::vec1d v2(3.0);
	mim::vec1i v3(3);
	mim::vec1u v4(3);
	mim::vec1b v5(true);

	EXPECT_EQ(v1.length(), 3);
	EXPECT_EQ(v2.length(), 3);
	EXPECT_EQ(v3.length(), 3);
	EXPECT_EQ(v4.length(), 3);
	EXPECT_EQ(v5.length(), true);
}

TEST(Vector1Defaults, length_squared)
{
	mim::vec1f v1(3.0f);
	mim::vec1d v2(3.0);
	mim::vec1i v3(3);
	mim::vec1u v4(3);
	mim::vec1b v5(true);

	EXPECT_EQ(v1.length_squared(), 9);
	EXPECT_EQ(v2.length_squared(), 9);
	EXPECT_EQ(v3.length_squared(), 9);
	EXPECT_EQ(v4.length_squared(), 9);
	EXPECT_EQ(v5.length_squared(), true);
}

TEST(Vector1Defaults, normalize)
{
	mim::vec1f v1(3.0f);
	mim::vec1d v2(3.0);

	v1.normalize();
	v2.normalize();

	EXPECT_TRUE(v1.x == 1);
	EXPECT_TRUE(v2.x == 1);
}

TEST(Vector1Defaults, normalized)
{
	mim::vec1f v1(3.0f);
	mim::vec1d v2(3.0);

	EXPECT_EQ(v1.normalized(), mim::vec1f(1));
	EXPECT_EQ(v2.normalized(), mim::vec1d(1));
}

// function nearlyEquals doesnt exist
//TEST(Vector1Defaults, is_normalized)
//{
//	mim::vec1f v1(3.0f);
//	mim::vec1d v2(3.0);
//	mim::vec1f v3(1.0f);
//	mim::vec1d v4(1.0);
//
//	EXPECT_EQ(v1.is_normalized(), false);
//	EXPECT_EQ(v2.is_normalized(), false);
//	EXPECT_EQ(v3.is_normalized(), true);
//	EXPECT_EQ(v4.is_normalized(), true);
//}

TEST(Vector1Defaults, distance)
{
	mim::vec1f v1(3.0f);
	mim::vec1d v2(3.0);
	mim::vec1i v3(3);
	mim::vec1u v4(3);

	mim::vec1f v6(1.0f);
	mim::vec1d v7(1.0);
	mim::vec1i v8(1);
	mim::vec1u v9(1);

	EXPECT_EQ(v1.distance(v6), 2);
	EXPECT_EQ(v2.distance(v7), 2);
	EXPECT_EQ(v3.distance(v8), 2);
	EXPECT_EQ(v4.distance(v9), 2);
}

TEST(Vector1Defaults, distance_squared)
{
	mim::vec1f v1(3.0f);
	mim::vec1d v2(3.0);
	mim::vec1i v3(3);
	mim::vec1u v4(3);

	mim::vec1f v6(1.0f);
	mim::vec1d v7(1.0);
	mim::vec1i v8(1);
	mim::vec1u v9(1);

	EXPECT_EQ(v1.distance_squared(v6), 4);
	EXPECT_EQ(v2.distance_squared(v7), 4);
	EXPECT_EQ(v3.distance_squared(v8), 4);
	EXPECT_EQ(v4.distance_squared(v9), 4);
}
