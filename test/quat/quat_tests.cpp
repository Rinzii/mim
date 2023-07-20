// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#include <mim/quat.hpp>
#include <mim/vec.hpp>
#include <gtest/gtest.h>

#define PI 3.14159265358979323846

using namespace mim;

// Helper function to compare floating-point values within a small epsilon
template <typename T>
bool IsClose(T a, T b, T epsilon = static_cast<T>(1e-6))
{
	return std::abs(a - b) < epsilon;
}

// Test fixture for the quaternion class
template <typename T>
class QuaternionTest : public ::testing::Test
{
protected:
	// Helper function to create a vector with specified components
	vec<3, T> MakeVector(T x, T y, T z)
	{
		return vec<3, T>(x, y, z);
	}
};

// List of types to test (float and double)
using QuaternionTypes = ::testing::Types<float, double>;
TYPED_TEST_SUITE(QuaternionTest, QuaternionTypes);

TYPED_TEST(QuaternionTest, DefaultConstructor)
{
	quat<TypeParam> q;
	EXPECT_TRUE(IsClose(q.x, static_cast<TypeParam>(0)));
	EXPECT_TRUE(IsClose(q.y, static_cast<TypeParam>(0)));
	EXPECT_TRUE(IsClose(q.z, static_cast<TypeParam>(0)));
	EXPECT_TRUE(IsClose(q.w, static_cast<TypeParam>(1)));
}

TYPED_TEST(QuaternionTest, CopyConstructor)
{
	quat<TypeParam> q1(1, 2, 3, 4);
	quat<TypeParam> q2(q1);
	EXPECT_EQ(q1, q2);
}

TYPED_TEST(QuaternionTest, VectorConstructor)
{
	vec<3, TypeParam> v(1, 2, 3);
	quat<TypeParam> q(4, v);
	EXPECT_TRUE(IsClose(q.x, static_cast<TypeParam>(1)));
	EXPECT_TRUE(IsClose(q.y, static_cast<TypeParam>(2)));
	EXPECT_TRUE(IsClose(q.z, static_cast<TypeParam>(3)));
	EXPECT_TRUE(IsClose(q.w, static_cast<TypeParam>(4)));
}

TYPED_TEST(QuaternionTest, AxisAngleConstructor)
{
	vec<3, TypeParam> axis = this->MakeVector(1, 0, 0);
	quat<TypeParam> q(PI / 2, axis);

	EXPECT_TRUE(IsClose(q.w, static_cast<TypeParam>(std::cos(PI / 4))));
	EXPECT_TRUE(IsClose(q.x, static_cast<TypeParam>(std::sin(PI / 4))));
	EXPECT_TRUE(IsClose(q.y, static_cast<TypeParam>(0)));
	EXPECT_TRUE(IsClose(q.z, static_cast<TypeParam>(0)));
}

/*
TYPED_TEST(QuaternionTest, EulerConstructor)
{
	vec<3, TypeParam> euler(PI / 2, 0, PI / 2);
	quat<TypeParam> q(euler);

	EXPECT_TRUE(IsClose(q.w, static_cast<TypeParam>(std::cos(PI / 4) * std::cos(PI / 4))));
	EXPECT_TRUE(IsClose(q.x, static_cast<TypeParam>(std::sin(PI / 4) * std::cos(PI / 4))));
	EXPECT_TRUE(IsClose(q.y, static_cast<TypeParam>(0)));
	EXPECT_TRUE(IsClose(q.z, static_cast<TypeParam>(std::cos(PI / 4) * std::sin(PI / 4))));
}
*/

TYPED_TEST(QuaternionTest, AssignmentOperator)
{
	quat<TypeParam> q1(1, 2, 3, 4);
	quat<TypeParam> q2 = q1;
	EXPECT_EQ(q1, q2);
}

TYPED_TEST(QuaternionTest, AdditionOperator)
{
	quat<TypeParam> q1(1, 2, 3, 4);
	quat<TypeParam> q2(5, 6, 7, 8);
	quat<TypeParam> result = q1 + q2;
	quat<TypeParam> expected(6, 8, 10, 12);
	EXPECT_EQ(result, expected);
}

TYPED_TEST(QuaternionTest, SubtractionOperator)
{
	quat<TypeParam> q1(5, 6, 7, 8);
	quat<TypeParam> q2(1, 2, 3, 4);
	quat<TypeParam> result = q1 - q2;
	quat<TypeParam> expected(4, 4, 4, 4);
	EXPECT_EQ(result, expected);
}

TYPED_TEST(QuaternionTest, MultiplicationOperator)
{
	quat<TypeParam> q1(1, 2, 3, 4);
	quat<TypeParam> q2(5, 6, 7, 8);
	quat<TypeParam> result = q1 * q2;
	quat<TypeParam> expected(-60, 12, 30, 24);
	EXPECT_EQ(result, expected);
}

TYPED_TEST(QuaternionTest, ScalarMultiplication)
{
	quat<TypeParam> q(1, 2, 3, 4);
	auto scalar = static_cast<TypeParam>(2);
	quat<TypeParam> result = q * scalar;
	quat<TypeParam> expected(2, 4, 6, 8);
	EXPECT_EQ(result, expected);
}

TYPED_TEST(QuaternionTest, ScalarDivision)
{
	quat<TypeParam> q(2, 4, 6, 8);
	auto scalar = static_cast<TypeParam>(2);
	quat<TypeParam> result = q / scalar;
	quat<TypeParam> expected(1, 2, 3, 4);
	EXPECT_EQ(result, expected);
}

TYPED_TEST(QuaternionTest, EqualityOperator)
{
	quat<TypeParam> q1(1, 2, 3, 4);
	quat<TypeParam> q2(1, 2, 3, 4);
	EXPECT_TRUE(q1 == q2);

	quat<TypeParam> q3(5, 6, 7, 8);
	EXPECT_FALSE(q1 == q3);
}

TYPED_TEST(QuaternionTest, InequalityOperator)
{
	quat<TypeParam> q1(1, 2, 3, 4);
	quat<TypeParam> q2(1, 2, 3, 4);
	EXPECT_FALSE(q1 != q2);

	quat<TypeParam> q3(5, 6, 7, 8);
	EXPECT_TRUE(q1 != q3);
}

/*
TYPED_TEST(QuaternionTest, QuaternionMultiplicationVector)
{
	quat<TypeParam> q(1, 2, 3, 4);
	vec<3, TypeParam> v(1, 2, 3);
	vec<3, TypeParam> result = q * v;
	vec<3, TypeParam> expected(14, 22, 32);
	EXPECT_EQ(result, expected);
}

*/


