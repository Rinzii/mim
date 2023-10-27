// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#include "mim/detail/compute/compute_vector.hpp"

namespace mim
{

	template <typename T>
	constexpr T& vec<3, T>::operator[](size_type i)
	{
		static_assert(i < this->length(), "Out of range: vec<3, T>::operator[]");

		switch (i) {
		default:
		case 0: return x;
		case 1: return y;
		case 2: return z;
		}
	}

	template <typename T>
	constexpr T const& vec<3, T>::operator[](size_type i) const
	{
		static_assert(i < this->length(), "Out of range: vec<3, T>::operator[]");

		switch (i) {
		default:
		case 0: return x;
		case 1: return y;
		case 2: return z;
		}
	}

	/// Constructors

	template <typename T>
	constexpr vec<3, T>::vec() : x(0), y(0), z(0)
	{
	}

	template <typename T>
	constexpr vec<3, T>::vec(T _x, T _y, T _z) : x(_x), y(_y), z(_z)
	{
	}

	template <typename T>
	constexpr vec<3, T>::vec(vec<3, T> const& v) : x(v.x), y(v.y), z(v.z)
	{
	}

	template <typename T>
	constexpr vec<3, T>::vec(T scalar) : x(scalar), y(scalar), z(scalar)
	{
	}

	/// U Template Constructors

	// Vec1 is deliberately treated like a scalar to mimic shader languages.

	template <typename T>
	template <typename U>
	constexpr vec<3, T>::vec(vec<1, U> const& scalar) : x(static_cast<T>(scalar.x)), y(static_cast<T>(scalar.x)), z(static_cast<T>(scalar.x))
	{
	}

	template <typename T>
	template <typename U>
	constexpr vec<3, T>::vec(vec<3, U> const& v) : x(static_cast<T>(v.x)), y(static_cast<T>(v.y)), z(static_cast<T>(v.z))
	{
	}

	// XYZ Template Constructors

	template <typename T>
	template <typename X, typename Y, typename Z>
	constexpr vec<3, T>::vec(X _x, Y _y, Z _z) : x(static_cast<T>(_x)), y(static_cast<T>(_y)), z(static_cast<T>(_z))
	{
	}

	template <typename T>
	template <typename X, typename Y, typename Z>
	constexpr vec<3, T>::vec(vec<1, X> const& _x, Y _y, Z _z) : x(static_cast<T>(_x.x)), y(static_cast<T>(_y)), z(static_cast<T>(_z))
	{
	}

	template <typename T>
	template <typename X, typename Y, typename Z>
	constexpr vec<3, T>::vec(X _x, vec<1, Y> const& _y, Z _z) : x(static_cast<T>(_x)), y(static_cast<T>(_y.y)), z(static_cast<T>(_z))
	{
	}

	template <typename T>
	template <typename X, typename Y, typename Z>
	constexpr vec<3, T>::vec(X _x, Y _y, vec<1, Z> const& _z) : x(static_cast<T>(_x)), y(static_cast<T>(_y)), z(static_cast<T>(_z.z))
	{
	}

	template <typename T>
	template <typename X, typename Y, typename Z>
	constexpr vec<3, T>::vec(vec<1, X> const& _x, vec<1, Y> const& _y, Z _z)
		: x(static_cast<T>(_x.x)), y(static_cast<T>(_y.y)), z(static_cast<T>(_z))
	{
	}

	template <typename T>
	template <typename X, typename Y, typename Z>
	constexpr vec<3, T>::vec(vec<1, X> const& _x, Y _y, vec<1, Z> const& _z)
		: x(static_cast<T>(_x.x)), y(static_cast<T>(_y)), z(static_cast<T>(_z.z))
	{
	}

	template <typename T>
	template <typename X, typename Y, typename Z>
	constexpr vec<3, T>::vec(X _x, vec<1, Y> const& _y, vec<1, Z> const& _z)
		: x(static_cast<T>(_x)), y(static_cast<T>(_y.y)), z(static_cast<T>(_z.z))
	{
	}

	template <typename T>
	template <typename X, typename Y, typename Z>
	constexpr vec<3, T>::vec(vec<1, X> const& _x, vec<1, Y> const& _y, vec<1, Z> const& _z)
		: x(static_cast<T>(_x.x)), y(static_cast<T>(_y.y)), z(static_cast<T>(_z.z))
	{
	}

	/// AB Template Constructors

	template <typename T>
	template <typename A, typename B>
	constexpr vec<3, T>::vec(vec<2, A> const& _xy, B _z) : x(static_cast<T>(_xy.x)), y(static_cast<T>(_xy.y)), z(static_cast<T>(_z))
	{
	}

	template <typename T>
	template <typename A, typename B>
	constexpr vec<3, T>::vec(vec<2, A> const& _xy, vec<1, B> const& _z)
		: x(static_cast<T>(_xy.x)), y(static_cast<T>(_xy.y)), z(static_cast<T>(_z.z))
	{
	}

	template <typename T>
	template <typename A, typename B>
	constexpr vec<3, T>::vec(A _x, vec<2, B> const& _yz) : x(static_cast<T>(_x)), y(static_cast<T>(_yz.y)), z(static_cast<T>(_yz.z))
	{
	}

	template <typename T>
	template <typename A, typename B>
	constexpr vec<3, T>::vec(vec<1, A> const& _x, vec<2, B> const& _yz)
		: x(static_cast<T>(_x.x)), y(static_cast<T>(_yz.y)), z(static_cast<T>(_yz.z))
	{
	}

	/// Assignment Operators

	template <typename T>
	constexpr vec<3, T>& vec<3, T>::operator=(T scalar)
	{
		x = scalar;
		y = scalar;
		z = scalar;
		return *this;
	}

	template <typename T>
	constexpr vec<3, T>& vec<3, T>::operator=(vec<3, T> const& v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
		return *this;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	template <typename U>
	constexpr vec<3, T>& vec<3, T>::operator=(vec<1, U> const& scalar)
	{
		x = static_cast<T>(scalar.x);
		y = static_cast<T>(scalar.x);
		z = static_cast<T>(scalar.x);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<3, T>& vec<3, T>::operator=(vec<3, U> const& v)
	{
		x = static_cast<T>(v.x);
		y = static_cast<T>(v.y);
		z = static_cast<T>(v.z);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<3, T>& vec<3, T>::operator+=(U scalar)
	{
		x += static_cast<T>(scalar);
		y += static_cast<T>(scalar);
		z += static_cast<T>(scalar);
		return *this;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	template <typename U>
	constexpr vec<3, T>& vec<3, T>::operator+=(vec<1, U> const& v)
	{
		x += static_cast<T>(v.x);
		y += static_cast<T>(v.x);
		z += static_cast<T>(v.x);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<3, T>& vec<3, T>::operator+=(vec<3, U> const& v)
	{
		x += static_cast<T>(v.x);
		y += static_cast<T>(v.y);
		z += static_cast<T>(v.z);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<3, T>& vec<3, T>::operator-=(U scalar)
	{
		x -= static_cast<T>(scalar);
		y -= static_cast<T>(scalar);
		z -= static_cast<T>(scalar);
		return *this;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	template <typename U>
	constexpr vec<3, T>& vec<3, T>::operator-=(vec<1, U> const& scalar)
	{
		x -= static_cast<T>(scalar.x);
		y -= static_cast<T>(scalar.x);
		z -= static_cast<T>(scalar.x);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<3, T>& vec<3, T>::operator-=(vec<3, U> const& v)
	{
		x -= static_cast<T>(v.x);
		y -= static_cast<T>(v.y);
		z -= static_cast<T>(v.z);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<3, T>& vec<3, T>::operator*=(U scalar)
	{
		x *= static_cast<T>(scalar);
		y *= static_cast<T>(scalar);
		z *= static_cast<T>(scalar);
		return *this;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	template <typename U>
	constexpr vec<3, T>& vec<3, T>::operator*=(vec<1, U> const& v)
	{
		x *= static_cast<T>(v.x);
		y *= static_cast<T>(v.x);
		z *= static_cast<T>(v.x);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<3, T>& vec<3, T>::operator*=(vec<3, U> const& v)
	{
		x *= static_cast<T>(v.x);
		y *= static_cast<T>(v.y);
		z *= static_cast<T>(v.z);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<3, T>& vec<3, T>::operator/=(U scalar)
	{
		x /= static_cast<T>(scalar);
		y /= static_cast<T>(scalar);
		z /= static_cast<T>(scalar);
		return *this;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	template <typename U>
	constexpr vec<3, T>& vec<3, T>::operator/=(vec<1, U> const& v)
	{
		x /= static_cast<T>(v.x);
		y /= static_cast<T>(v.x);
		z /= static_cast<T>(v.x);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<3, T>& vec<3, T>::operator/=(vec<3, U> const& v)
	{
		x /= static_cast<T>(v.x);
		y /= static_cast<T>(v.y);
		z /= static_cast<T>(v.z);
		return *this;
	}

	/// Increment and decrement operators

	template <typename T>
	constexpr vec<3, T>& vec<3, T>::operator++()
	{
		++this->x;
		++this->y;
		++this->z;
		return *this;
	}

	template <typename T>
	constexpr vec<3, T>& vec<3, T>::operator--()
	{
		--this->x;
		--this->y;
		--this->z;
		return *this;
	}

	template <typename T>
	constexpr const vec<3, T> vec<3, T>::operator++(int)
	{
		vec<3, T> result(*this);
		++*this;
		return result;
	}

	template <typename T>
	constexpr const vec<3, T> vec<3, T>::operator--(int)
	{
		vec<3, T> result(*this);
		--*this;
		return result;
	}

	/// Bitwise Assignment Operators

	template <typename T>
	template <typename U>
	constexpr vec<3, T>& vec<3, T>::operator%=(U scalar)
	{
		x %= static_cast<T>(scalar);
		y %= static_cast<T>(scalar);
		z %= static_cast<T>(scalar);
		return *this;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	template <typename U>
	constexpr vec<3, T>& vec<3, T>::operator%=(vec<1, U> const& v)
	{
		x %= static_cast<T>(v.x);
		y %= static_cast<T>(v.x);
		z %= static_cast<T>(v.x);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<3, T>& vec<3, T>::operator%=(vec<3, U> const& v)
	{
		x %= static_cast<T>(v.x);
		y %= static_cast<T>(v.y);
		z %= static_cast<T>(v.z);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<3, T>& vec<3, T>::operator&=(U scalar)
	{
		x &= static_cast<T>(scalar);
		y &= static_cast<T>(scalar);
		z &= static_cast<T>(scalar);
		return *this;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	template <typename U>
	constexpr vec<3, T>& vec<3, T>::operator&=(vec<1, U> const& v)
	{
		x &= static_cast<T>(v.x);
		y &= static_cast<T>(v.x);
		z &= static_cast<T>(v.x);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<3, T>& vec<3, T>::operator&=(vec<3, U> const& v)
	{
		x &= static_cast<T>(v.x);
		y &= static_cast<T>(v.y);
		z &= static_cast<T>(v.z);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<3, T>& vec<3, T>::operator|=(U scalar)
	{
		x |= static_cast<T>(scalar);
		y |= static_cast<T>(scalar);
		z |= static_cast<T>(scalar);
		return *this;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	template <typename U>
	constexpr vec<3, T>& vec<3, T>::operator|=(vec<1, U> const& v)
	{
		x |= static_cast<T>(v.x);
		y |= static_cast<T>(v.x);
		z |= static_cast<T>(v.x);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<3, T>& vec<3, T>::operator|=(vec<3, U> const& v)
	{
		x |= static_cast<T>(v.x);
		y |= static_cast<T>(v.y);
		z |= static_cast<T>(v.z);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<3, T>& vec<3, T>::operator^=(U scalar)
	{
		x ^= static_cast<T>(scalar);
		y ^= static_cast<T>(scalar);
		z ^= static_cast<T>(scalar);
		return *this;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	template <typename U>
	constexpr vec<3, T>& vec<3, T>::operator^=(vec<1, U> const& v)
	{
		x ^= static_cast<T>(v.x);
		y ^= static_cast<T>(v.x);
		z ^= static_cast<T>(v.x);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<3, T>& vec<3, T>::operator^=(vec<3, U> const& v)
	{
		x ^= static_cast<T>(v.x);
		y ^= static_cast<T>(v.y);
		z ^= static_cast<T>(v.z);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<3, T>& vec<3, T>::operator<<=(U scalar)
	{
		x <<= static_cast<T>(scalar);
		y <<= static_cast<T>(scalar);
		z <<= static_cast<T>(scalar);
		return *this;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	template <typename U>
	constexpr vec<3, T>& vec<3, T>::operator<<=(vec<1, U> const& v)
	{
		x <<= static_cast<T>(v.x);
		y <<= static_cast<T>(v.x);
		z <<= static_cast<T>(v.x);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<3, T>& vec<3, T>::operator<<=(vec<3, U> const& v)
	{
		x <<= static_cast<T>(v.x);
		y <<= static_cast<T>(v.y);
		z <<= static_cast<T>(v.z);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<3, T>& vec<3, T>::operator>>=(U scalar)
	{
		x >>= static_cast<T>(scalar);
		y >>= static_cast<T>(scalar);
		z >>= static_cast<T>(scalar);
		return *this;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	template <typename U>
	constexpr vec<3, T>& vec<3, T>::operator>>=(vec<1, U> const& v)
	{
		x >>= static_cast<T>(v.x);
		y >>= static_cast<T>(v.x);
		z >>= static_cast<T>(v.x);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<3, T>& vec<3, T>::operator>>=(vec<3, U> const& v)
	{
		x >>= static_cast<T>(v.x);
		y >>= static_cast<T>(v.y);
		z >>= static_cast<T>(v.z);
		return *this;
	}

	template <typename T>
	constexpr vec<3, T> operator+(vec<3, T> const& v)
	{
		return v;
	}

	template <typename T>
	constexpr vec<3, T> operator-(vec<3, T> const& v)
	{
		return vec<3, T>(-v.x, -v.y, -v.z);
	}

	template <typename T>
	constexpr vec<3, T> operator+(vec<3, T> const& v, T scalar)
	{
		return vec<3, T>(v.x + scalar, v.y + scalar, v.z + scalar);
	}

	template <typename T>
	constexpr vec<3, T> operator+(T scalar, vec<3, T> const& v)
	{
		return vec<3, T>(scalar + v.x, scalar + v.y, scalar + v.z);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	constexpr vec<3, T> operator+(vec<3, T> const& v, vec<1, T> const& sv)
	{
		return vec<3, T>(v.x + sv.x, v.y + sv.x, v.z + sv.x);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	constexpr vec<3, T> operator+(vec<1, T> const& sv, vec<3, T> const& v)
	{
		return vec<3, T>(sv.x + v.x, sv.x + v.y, sv.x + v.z);
	}

	template <typename T>
	constexpr vec<3, T> operator+(vec<3, T> const& v1, vec<3, T> const& v2)
	{
		return vec<3, T>(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
	}

	template <typename T>
	constexpr vec<3, T> operator-(vec<3, T> const& v, T scalar)
	{
		return vec<3, T>(v.x - scalar, v.y - scalar, v.z - scalar);
	}

	template <typename T>
	constexpr vec<3, T> operator-(T scalar, vec<3, T> const& v)
	{
		return vec<3, T>(scalar - v.x, scalar - v.y, scalar - v.z);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	constexpr vec<3, T> operator-(vec<3, T> const& v, vec<1, T> const& sv)
	{
		return vec<3, T>(v.x - sv.x, v.y - sv.x, v.z - sv.x);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	constexpr vec<3, T> operator-(vec<1, T> const& sv, vec<3, T> const& v)
	{
		return vec<3, T>(sv.x - v.x, sv.x - v.y, sv.x - v.z);
	}

	template <typename T>
	constexpr vec<3, T> operator-(vec<3, T> const& v1, vec<3, T> const& v2)
	{
		return vec<3, T>(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
	}

	template <typename T>
	constexpr vec<3, T> operator*(vec<3, T> const& v, T scalar)
	{
		return vec<3, T>(v.x * scalar, v.y * scalar, v.z * scalar);
	}

	template <typename T>
	constexpr vec<3, T> operator*(T scalar, vec<3, T> const& v)
	{
		return vec<3, T>(scalar * v.x, scalar * v.y, scalar * v.z);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	constexpr vec<3, T> operator*(vec<3, T> const& v, vec<1, T> const& sv)
	{
		return vec<3, T>(v.x * sv.x, v.y * sv.x, v.z * sv.x);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	constexpr vec<3, T> operator*(vec<1, T> const& sv, vec<3, T> const& v)
	{
		return vec<3, T>(sv.x * v.x, sv.x * v.y, sv.x * v.z);
	}

	template <typename T>
	constexpr vec<3, T> operator*(vec<3, T> const& v1, vec<3, T> const& v2)
	{
		return vec<3, T>(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);
	}

	template <typename T>
	constexpr vec<3, T> operator/(vec<3, T> const& v, T scalar)
	{
		return vec<3, T>(v.x / scalar, v.y / scalar, v.z / scalar);
	}

	template <typename T>
	constexpr vec<3, T> operator/(T scalar, vec<3, T> const& v)
	{
		return vec<3, T>(scalar / v.x, scalar / v.y, scalar / v.z);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	constexpr vec<3, T> operator/(vec<3, T> const& v, vec<1, T> const& sv)
	{
		return vec<3, T>(v.x / sv.x, v.y / sv.x, v.z / sv.x);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	constexpr vec<3, T> operator/(vec<1, T> const& sv, vec<3, T> const& v)
	{
		return vec<3, T>(sv.x / v.x, sv.x / v.y, sv.x / v.z);
	}

	template <typename T>
	constexpr vec<3, T> operator/(vec<3, T> const& v1, vec<3, T> const& v2)
	{
		return vec<3, T>(v1.x / v2.x, v1.y / v2.y, v1.z / v2.z);
	}

	template <typename T>
	constexpr vec<3, T> operator%(vec<3, T> const& v, T scalar)
	{
		return vec<3, T>(v.x % scalar, v.y % scalar, v.z % scalar);
	}

	template <typename T>
	constexpr vec<3, T> operator%(T scalar, vec<3, T> const& v)
	{
		return vec<3, T>(scalar % v.x, scalar % v.y, scalar % v.z);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	constexpr vec<3, T> operator%(vec<3, T> const& v, vec<1, T> const& sv)
	{
		return vec<3, T>(v.x % sv.x, v.y % sv.x, v.z % sv.x);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	constexpr vec<3, T> operator%(vec<1, T> const& sv, vec<3, T> const& v)
	{
		return vec<3, T>(sv.x % v.x, sv.x % v.y, sv.x % v.z);
	}

	template <typename T>
	constexpr vec<3, T> operator%(vec<3, T> const& v1, vec<3, T> const& v2)
	{
		return vec<3, T>(v1.x % v2.x, v1.y % v2.y, v1.z % v2.z);
	}

	template <typename T>
	constexpr vec<3, T> operator&(vec<3, T> const& v, T scalar)
	{
		return vec<3, T>(v.x & scalar, v.y & scalar, v.z & scalar);
	}

	template <typename T>
	constexpr vec<3, T> operator&(T scalar, vec<3, T> const& v)
	{
		return vec<3, T>(scalar & v.x, scalar & v.y, scalar & v.z);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	constexpr vec<3, T> operator&(vec<3, T> const& v, vec<1, T> const& sv)
	{
		return vec<3, T>(v.x & sv.x, v.y & sv.x, v.z & sv.x);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	constexpr vec<3, T> operator&(vec<1, T> const& sv, vec<3, T> const& v)
	{
		return vec<3, T>(sv.x & v.x, sv.x & v.y, sv.x & v.z);
	}

	template <typename T>
	constexpr vec<3, T> operator&(vec<3, T> const& v1, vec<3, T> const& v2)
	{
		return vec<3, T>(v1.x & v2.x, v1.y & v2.y, v1.z & v2.z);
	}

	template <typename T>
	constexpr vec<3, T> operator|(vec<3, T> const& v, T scalar)
	{
		return vec<3, T>(v.x | scalar, v.y | scalar, v.z | scalar);
	}

	template <typename T>
	constexpr vec<3, T> operator|(T scalar, vec<3, T> const& v)
	{
		return vec<3, T>(scalar | v.x, scalar | v.y, scalar | v.z);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	constexpr vec<3, T> operator|(vec<3, T> const& v, vec<1, T> const& sv)
	{
		return vec<3, T>(v.x | sv.x, v.y | sv.x, v.z | sv.x);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	constexpr vec<3, T> operator|(vec<1, T> const& sv, vec<3, T> const& v)
	{
		return vec<3, T>(sv.x | v.x, sv.x | v.y, sv.x | v.z);
	}

	template <typename T>
	constexpr vec<3, T> operator|(vec<3, T> const& v1, vec<3, T> const& v2)
	{
		return vec<3, T>(v1.x | v2.x, v1.y | v2.y, v1.z | v2.z);
	}

	template <typename T>
	constexpr vec<3, T> operator^(vec<3, T> const& v, T scalar)
	{
		return vec<3, T>(v.x ^ scalar, v.y ^ scalar, v.z ^ scalar);
	}

	template <typename T>
	constexpr vec<3, T> operator^(T scalar, vec<3, T> const& v)
	{
		return vec<3, T>(scalar ^ v.x, scalar ^ v.y, scalar ^ v.z);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	constexpr vec<3, T> operator^(vec<3, T> const& v, vec<1, T> const& sv)
	{
		return vec<3, T>(v.x ^ sv.x, v.y ^ sv.x, v.z ^ sv.x);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	constexpr vec<3, T> operator^(vec<1, T> const& sv, vec<3, T> const& v)
	{
		return vec<3, T>(sv.x ^ v.x, sv.x ^ v.y, sv.x ^ v.z);
	}

	template <typename T>
	constexpr vec<3, T> operator^(vec<3, T> const& v1, vec<3, T> const& v2)
	{
		return vec<3, T>(v1.x ^ v2.x, v1.y ^ v2.y, v1.z ^ v2.z);
	}

	template <typename T>
	constexpr vec<3, T> operator<<(vec<3, T> const& v, T scalar)
	{
		return vec<3, T>(v.x << scalar, v.y << scalar, v.z << scalar);
	}

	template <typename T>
	constexpr vec<3, T> operator<<(T scalar, vec<3, T> const& v)
	{
		return vec<3, T>(scalar << v.x, scalar << v.y, scalar << v.z);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	constexpr vec<3, T> operator<<(vec<3, T> const& v, vec<1, T> const& sv)
	{
		return vec<3, T>(v.x << sv.x, v.y << sv.x, v.z << sv.x);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	constexpr vec<3, T> operator<<(vec<1, T> const& sv, vec<3, T> const& v)
	{
		return vec<3, T>(sv.x << v.x, sv.x << v.y, sv.x << v.z);
	}

	template <typename T>
	constexpr vec<3, T> operator<<(vec<3, T> const& v1, vec<3, T> const& v2)
	{
		return vec<3, T>(v1.x << v2.x, v1.y << v2.y, v1.z << v2.z);
	}

	template <typename T>
	constexpr vec<3, T> operator>>(vec<3, T> const& v, T scalar)
	{
		return vec<3, T>(v.x >> scalar, v.y >> scalar, v.z >> scalar);
	}

	template <typename T>
	constexpr vec<3, T> operator>>(T scalar, vec<3, T> const& v)
	{
		return vec<3, T>(scalar >> v.x, scalar >> v.y, scalar >> v.z);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	constexpr vec<3, T> operator>>(vec<3, T> const& v, vec<1, T> const& sv)
	{
		return vec<3, T>(v.x >> sv.x, v.y >> sv.x, v.z >> sv.x);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	constexpr vec<3, T> operator>>(vec<1, T> const& sv, vec<3, T> const& v)
	{
		return vec<3, T>(sv.x >> v.x, sv.x >> v.y, sv.x >> v.z);
	}

	template <typename T>
	constexpr vec<3, T> operator>>(vec<3, T> const& v1, vec<3, T> const& v2)
	{
		return vec<3, T>(v1.x >> v2.x, v1.y >> v2.y, v1.z >> v2.z);
	}

	template <typename T>
	constexpr vec<3, T> operator~(vec<3, T> const& v)
	{
		return vec<3, T>(~v.x, ~v.y, ~v.z);
	}

	template <typename T>
	constexpr bool operator==(vec<3, T> const& v1, vec<3, T> const& v2)
	{
		return v1.x == v2.x && v1.y == v2.y && v1.z == v2.z;
	}

	template <typename T>
	constexpr bool operator!=(vec<3, T> const& v1, vec<3, T> const& v2)
	{
		return !(v1 == v2);
	}

	template <typename T>
	constexpr vec<3, bool> operator&&(vec<3, T> const& v1, vec<3, T> const& v2)
	{
		return {v1.x && v2.x, v1.y && v2.y, v1.z && v2.z};
	}

	template <typename T>
	constexpr vec<3, bool> operator||(vec<3, T> const& v1, vec<3, T> const& v2)
	{
		return {v1.x || v2.x, v1.y || v2.y, v1.z || v2.z};
	}
} // namespace mim

