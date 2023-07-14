// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#include "mim/detail/compute/compute_vector.hpp"

namespace mim
{

	// Element Accessors

	template <typename T, qualifier Q>
	constexpr T& vec<2, T, Q>::operator[](size_type i)
	{
		switch (i) {
		default:
		case 0: return x;
		case 1: return y;
		}
	}

	template <typename T, qualifier Q>
	constexpr T const& vec<2, T, Q>::operator[](size_type i) const
	{

		switch (i) {
		default:
		case 0: return x;
		case 1: return y;
		}
	}

	template <typename T, qualifier Q>
	T& vec<2, T, Q>::at(std::size_t i)
	{

		switch (i) {
		default:
		case 0: return x;
		case 1: return y;
		}
	}

	template <typename T, qualifier Q>
	const T& vec<2, T, Q>::at(std::size_t i) const
	{

		switch (i) {
		default:
		case 0: return x;
		case 1: return y;
		}
	}

	/// Constructors

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q>::vec() : x(0), y(0)
	{
	}

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q>::vec(T _x, T _y) : x(_x), y(_y)
	{
	}

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q>::vec(vec<2, T, Q> const& v) : x(v.x), y(v.y)
	{
	}

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q>::vec(T scalar) : x(scalar), y(scalar)
	{
	}

	/// Template Constructors

	template <typename T, qualifier Q>
	template <qualifier P>
	constexpr vec<2, T, Q>::vec(vec<2, T, P> const& v) : x(v.x), y(v.y)
	{
	}

	// U Template Constructors

	template <typename T, qualifier Q>
	template <typename U, qualifier P>
	constexpr vec<2, T, Q>::vec(vec<1, U, P> const& scalar) : x(static_cast<T>(scalar.x)), y(static_cast<T>(scalar.x))
	{
	}

	template <typename T, qualifier Q>
	template <typename U, qualifier P>
	constexpr vec<2, T, Q>::vec(vec<2, U, P> const& v) : x(static_cast<T>(v.x)), y(static_cast<T>(v.y))
	{
	}

	template <typename T, qualifier Q>
	template <typename U, qualifier P>
	constexpr vec<2, T, Q>::vec(vec<3, U, P> const& v) : x(static_cast<T>(v.x)), y(static_cast<T>(v.y))
	{
	}

	template <typename T, qualifier Q>
	template <typename U, qualifier P>
	constexpr vec<2, T, Q>::vec(vec<4, U, P> const& v) : x(static_cast<T>(v.x)), y(static_cast<T>(v.y))
	{
	}

	// AB Template Constructors

	template <typename T, qualifier Q>
	template <typename A, typename B>
	constexpr vec<2, T, Q>::vec(A _x, B _y) : x(static_cast<T>(_x)), y(static_cast<T>(_y))
	{
	}

	template <typename T, qualifier Q>
	template <typename A, typename B>
	constexpr vec<2, T, Q>::vec(vec<1, A, Q> const& _x, B _y) : x(static_cast<T>(_x.x)), y(static_cast<T>(_y))
	{
	}

	template <typename T, qualifier Q>
	template <typename A, typename B>
	constexpr vec<2, T, Q>::vec(A _x, vec<1, B, Q> const& _y) : x(static_cast<T>(_x)), y(static_cast<T>(_y.x))
	{
	}

	template <typename T, qualifier Q>
	template <typename A, typename B>
	constexpr vec<2, T, Q>::vec(vec<1, A, Q> const& _x, vec<1, B, Q> const& _y) : x(static_cast<T>(_x.x)), y(static_cast<T>(_y.x))
	{
	}

	/// Assignment Operators

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q>& vec<2, T, Q>::operator=(T scalar)
	{
		this->x = scalar;
		this->y = scalar;
		return *this;
	}

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q>& vec<2, T, Q>::operator=(vec const& v)
	{
		this->x = v.x;
		this->y = v.y;
		return *this;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<2, T, Q>& vec<2, T, Q>::operator=(vec<1, U, Q> const& scalar)
	{
		this->x = static_cast<T>(scalar.x);
		this->y = static_cast<T>(scalar.x);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<2, T, Q>& vec<2, T, Q>::operator=(vec<2, U, Q> const& v)
	{
		this->x = static_cast<T>(v.x);
		this->y = static_cast<T>(v.y);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<2, T, Q>& vec<2, T, Q>::operator+=(U scalar)
	{
		this->x += static_cast<T>(scalar);
		this->y += static_cast<T>(scalar);
		return *this;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<2, T, Q>& vec<2, T, Q>::operator+=(vec<1, U, Q> const& scalar)
	{
		this->x += static_cast<T>(scalar.x);
		this->y += static_cast<T>(scalar.x);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<2, T, Q>& vec<2, T, Q>::operator+=(vec<2, U, Q> const& v)
	{
		this->x += static_cast<T>(v.x);
		this->y += static_cast<T>(v.y);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<2, T, Q>& vec<2, T, Q>::operator-=(U scalar)
	{
		this->x -= static_cast<T>(scalar);
		this->y -= static_cast<T>(scalar);
		return *this;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<2, T, Q>& vec<2, T, Q>::operator-=(vec<1, U, Q> const& scalar)
	{
		this->x -= static_cast<T>(scalar.x);
		this->y -= static_cast<T>(scalar.x);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<2, T, Q>& vec<2, T, Q>::operator-=(vec<2, U, Q> const& v)
	{
		this->x -= static_cast<T>(v.x);
		this->y -= static_cast<T>(v.y);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<2, T, Q>& vec<2, T, Q>::operator*=(U scalar)
	{
		this->x *= static_cast<T>(scalar);
		this->y *= static_cast<T>(scalar);
		return *this;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<2, T, Q>& vec<2, T, Q>::operator*=(vec<1, U, Q> const& scalar)
	{
		this->x *= static_cast<T>(scalar.x);
		this->y *= static_cast<T>(scalar.x);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<2, T, Q>& vec<2, T, Q>::operator*=(vec<2, U, Q> const& v)
	{
		this->x *= static_cast<T>(v.x);
		this->y *= static_cast<T>(v.y);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<2, T, Q>& vec<2, T, Q>::operator/=(U scalar)
	{
		this->x /= static_cast<T>(scalar);
		this->y /= static_cast<T>(scalar);
		return *this;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<2, T, Q>& vec<2, T, Q>::operator/=(vec<1, U, Q> const& scalar)
	{
		this->x /= static_cast<T>(scalar.x);
		this->y /= static_cast<T>(scalar.x);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<2, T, Q>& vec<2, T, Q>::operator/=(vec<2, U, Q> const& v)
	{
		this->x /= static_cast<T>(v.x);
		this->y /= static_cast<T>(v.y);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<2, T, Q>& vec<2, T, Q>::operator%=(U scalar)
	{
		this->x %= static_cast<T>(scalar);
		this->y %= static_cast<T>(scalar);
		return *this;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<2, T, Q>& vec<2, T, Q>::operator%=(vec<1, U, Q> const& scalar)
	{
		this->x %= static_cast<T>(scalar.x);
		this->y %= static_cast<T>(scalar.x);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<2, T, Q>& vec<2, T, Q>::operator%=(vec<2, U, Q> const& v)
	{
		this->x %= static_cast<T>(v.x);
		this->y %= static_cast<T>(v.y);
		return *this;
	}

	/// Increment and Decrement Operators

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q>& vec<2, T, Q>::operator++()
	{
		++this->x;
		++this->y;
		return *this;
	}

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q>& vec<2, T, Q>::operator--()
	{
		--this->x;
		--this->y;
		return *this;
	}

	template <typename T, qualifier Q>
	constexpr const vec<2, T, Q> vec<2, T, Q>::operator++(int)
	{
		vec<2, T, Q> v(*this);
		++this->x;
		++this->y;
		return v;
	}

	template <typename T, qualifier Q>
	constexpr const vec<2, T, Q> vec<2, T, Q>::operator--(int)
	{
		vec<2, T, Q> v(*this);
		--this->x;
		--this->y;
		return v;
	}

	/// Bitwise Assignment Operators
	// We will not be supporting bitwise assignment operations between vec 3-4 as it would not make much sense from a math standpoint.
	// This can change at a later date but for now I'm not going to bother with it for now.

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<2, T, Q>& vec<2, T, Q>::operator&=(U scalar)
	{
		this->x &= static_cast<T>(scalar);
		this->y &= static_cast<T>(scalar);
		return *this;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<2, T, Q>& vec<2, T, Q>::operator&=(vec<1, U, Q> const& scalar)
	{
		this->x &= static_cast<T>(scalar.x);
		this->y &= static_cast<T>(scalar.x);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<2, T, Q>& vec<2, T, Q>::operator&=(vec<2, U, Q> const& v)
	{
		this->x &= static_cast<T>(v.x);
		this->y &= static_cast<T>(v.y);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<2, T, Q>& vec<2, T, Q>::operator|=(U scalar)
	{
		this->x |= static_cast<T>(scalar);
		this->y |= static_cast<T>(scalar);
		return *this;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<2, T, Q>& vec<2, T, Q>::operator|=(vec<1, U, Q> const& scalar)
	{
		this->x |= static_cast<T>(scalar.x);
		this->y |= static_cast<T>(scalar.x);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<2, T, Q>& vec<2, T, Q>::operator|=(vec<2, U, Q> const& v)
	{
		this->x |= static_cast<T>(v.x);
		this->y |= static_cast<T>(v.y);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<2, T, Q>& vec<2, T, Q>::operator^=(U scalar)
	{
		this->x ^= static_cast<T>(scalar);
		this->y ^= static_cast<T>(scalar);
		return *this;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<2, T, Q>& vec<2, T, Q>::operator^=(vec<1, U, Q> const& scalar)
	{
		this->x ^= static_cast<T>(scalar.x);
		this->y ^= static_cast<T>(scalar.x);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<2, T, Q>& vec<2, T, Q>::operator^=(vec<2, U, Q> const& v)
	{
		this->x ^= static_cast<T>(v.x);
		this->y ^= static_cast<T>(v.y);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<2, T, Q>& vec<2, T, Q>::operator<<=(U scalar)
	{
		this->x <<= static_cast<T>(scalar);
		this->y <<= static_cast<T>(scalar);
		return *this;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<2, T, Q>& vec<2, T, Q>::operator<<=(vec<1, U, Q> const& scalar)
	{
		this->x <<= static_cast<T>(scalar.x);
		this->y <<= static_cast<T>(scalar.x);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<2, T, Q>& vec<2, T, Q>::operator<<=(vec<2, U, Q> const& v)
	{
		this->x <<= static_cast<T>(v.x);
		this->y <<= static_cast<T>(v.y);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<2, T, Q>& vec<2, T, Q>::operator>>=(U scalar)
	{
		this->x >>= static_cast<T>(scalar);
		this->y >>= static_cast<T>(scalar);
		return *this;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<2, T, Q>& vec<2, T, Q>::operator>>=(vec<1, U, Q> const& scalar)
	{
		this->x >>= static_cast<T>(scalar.x);
		this->y >>= static_cast<T>(scalar.x);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<2, T, Q>& vec<2, T, Q>::operator>>=(vec<2, U, Q> const& v)
	{
		this->x >>= static_cast<T>(v.x);
		this->y >>= static_cast<T>(v.y);
		return *this;
	}

	// We will not be supporting binary operations between vec 3-4 as it would not make much sense from a math standpoint.
	// This can change at a later date but for now I'm not going to bother with it for now.

	/// Unary operators

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator+(vec<2, T, Q> const& v)
	{
		return v;
	}

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator-(vec<2, T, Q> const& v)
	{
		return vec<2, T, Q>(-v.x, -v.y);
	}

	/// Binary Operators

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator+(vec<2, T, Q> const& v, T scalar)
	{
		return vec<2, T, Q>(v.x + scalar, v.y + scalar);
	}

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator+(T scalar, vec<2, T, Q> const& v)
	{
		return vec<2, T, Q>(scalar + v.x, scalar + v.y);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator+(vec<2, T, Q> const& v1, vec<1, T, Q> const& v2)
	{
		return vec<2, T, Q>(v1.x + v2.x, v1.y + v2.x);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator+(vec<1, T, Q> const& v1, vec<2, T, Q> const& v2)
	{
		return vec<2, T, Q>(v1.x + v2.x, v1.x + v2.y);
	}

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator+(vec<2, T, Q> const& v1, vec<2, T, Q> const& v2)
	{
		return vec<2, T, Q>(v1.x + v2.x, v1.y + v2.y);
	}

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator-(vec<2, T, Q> const& v, T scalar)
	{
		return vec<2, T, Q>(v.x - scalar, v.y - scalar);
	}

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator-(T scalar, vec<2, T, Q> const& v)
	{
		return vec<2, T, Q>(scalar - v.x, scalar - v.y);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator-(vec<2, T, Q> const& v1, vec<1, T, Q> const& v2)
	{
		return vec<2, T, Q>(v1.x - v2.x, v1.y - v2.x);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator-(vec<1, T, Q> const& v1, vec<2, T, Q> const& v2)
	{
		return vec<2, T, Q>(v1.x - v2.x, v1.x - v2.y);
	}

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator-(vec<2, T, Q> const& v1, vec<2, T, Q> const& v2)
	{
		return vec<2, T, Q>(v1.x - v2.x, v1.y - v2.y);
	}

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator*(vec<2, T, Q> const& v, T scalar)
	{
		return vec<2, T, Q>(v.x * scalar, v.y * scalar);
	}

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator*(T scalar, vec<2, T, Q> const& v)
	{
		return vec<2, T, Q>(scalar * v.x, scalar * v.y);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator*(vec<2, T, Q> const& v1, vec<1, T, Q> const& v2)
	{
		return vec<2, T, Q>(v1.x * v2.x, v1.y * v2.x);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator*(vec<1, T, Q> const& v1, vec<2, T, Q> const& v2)
	{
		return vec<2, T, Q>(v1.x * v2.x, v1.x * v2.y);
	}

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator*(vec<2, T, Q> const& v1, vec<2, T, Q> const& v2)
	{
		return vec<2, T, Q>(v1.x * v2.x, v1.y * v2.y);
	}

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator/(vec<2, T, Q> const& v, T scalar)
	{
		return vec<2, T, Q>(v.x / scalar, v.y / scalar);
	}

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator/(T scalar, vec<2, T, Q> const& v)
	{
		return vec<2, T, Q>(scalar / v.x, scalar / v.y);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator/(vec<2, T, Q> const& v1, vec<1, T, Q> const& v2)
	{
		return vec<2, T, Q>(v1.x / v2.x, v1.y / v2.x);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator/(vec<1, T, Q> const& v1, vec<2, T, Q> const& v2)
	{
		return vec<2, T, Q>(v1.x / v2.x, v1.x / v2.y);
	}

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator/(vec<2, T, Q> const& v1, vec<2, T, Q> const& v2)
	{
		return vec<2, T, Q>(v1.x / v2.x, v1.y / v2.y);
	}

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator%(vec<2, T, Q> const& v, T scalar)
	{
		return vec<2, T, Q>(v.x % scalar, v.y % scalar);
	}

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator%(T scalar, vec<2, T, Q> const& v)
	{
		return vec<2, T, Q>(scalar % v.x, scalar % v.y);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator%(vec<2, T, Q> const& v1, vec<1, T, Q> const& v2)
	{
		return vec<2, T, Q>(v1.x % v2.x, v1.y % v2.x);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator%(vec<1, T, Q> const& v1, vec<2, T, Q> const& v2)
	{
		return vec<2, T, Q>(v1.x % v2.x, v1.x % v2.y);
	}

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator%(vec<2, T, Q> const& v1, vec<2, T, Q> const& v2)
	{
		return vec<2, T, Q>(v1.x % v2.x, v1.y % v2.y);
	}

	/// Bitwise Binary Operators

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator&(vec<2, T, Q> const& v, T scalar)
	{
		return vec<2, T, Q>(v.x & scalar, v.y & scalar);
	}

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator&(T scalar, vec<2, T, Q> const& v)
	{
		return vec<2, T, Q>(scalar & v.x, scalar & v.y);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator&(vec<2, T, Q> const& v1, vec<1, T, Q> const& v2)
	{
		return vec<2, T, Q>(v1.x & v2.x, v1.y & v2.x);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator&(vec<1, T, Q> const& v1, vec<2, T, Q> const& v2)
	{
		return vec<2, T, Q>(v1.x & v2.x, v1.x & v2.y);
	}

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator&(vec<2, T, Q> const& v1, vec<2, T, Q> const& v2)
	{
		return vec<2, T, Q>(v1.x & v2.x, v1.y & v2.y);
	}

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator|(vec<2, T, Q> const& v, T scalar)
	{
		return vec<2, T, Q>(v.x | scalar, v.y | scalar);
	}

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator|(T scalar, vec<2, T, Q> const& v)
	{
		return vec<2, T, Q>(scalar | v.x, scalar | v.y);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator|(vec<2, T, Q> const& v1, vec<1, T, Q> const& v2)
	{
		return vec<2, T, Q>(v1.x | v2.x, v1.y | v2.x);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator|(vec<1, T, Q> const& v1, vec<2, T, Q> const& v2)
	{
		return vec<2, T, Q>(v1.x | v2.x, v1.x | v2.y);
	}

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator|(vec<2, T, Q> const& v1, vec<2, T, Q> const& v2)
	{
		return vec<2, T, Q>(v1.x | v2.x, v1.y | v2.y);
	}

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator^(vec<2, T, Q> const& v, T scalar)
	{
		return vec<2, T, Q>(v.x ^ scalar, v.y ^ scalar);
	}

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator^(T scalar, vec<2, T, Q> const& v)
	{
		return vec<2, T, Q>(scalar ^ v.x, scalar ^ v.y);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator^(vec<2, T, Q> const& v1, vec<1, T, Q> const& v2)
	{
		return vec<2, T, Q>(v1.x ^ v2.x, v1.y ^ v2.x);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator^(vec<1, T, Q> const& v1, vec<2, T, Q> const& v2)
	{
		return vec<2, T, Q>(v1.x ^ v2.x, v1.x ^ v2.y);
	}

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator^(vec<2, T, Q> const& v1, vec<2, T, Q> const& v2)
	{
		return vec<2, T, Q>(v1.x ^ v2.x, v1.y ^ v2.y);
	}

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator<<(vec<2, T, Q> const& v, T scalar)
	{
		return vec<2, T, Q>(v.x << scalar, v.y << scalar);
	}

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator<<(T scalar, vec<2, T, Q> const& v)
	{
		return vec<2, T, Q>(scalar << v.x, scalar << v.y);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator<<(vec<2, T, Q> const& v1, vec<1, T, Q> const& v2)
	{
		return vec<2, T, Q>(v1.x << v2.x, v1.y << v2.x);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator<<(vec<1, T, Q> const& v1, vec<2, T, Q> const& v2)
	{
		return vec<2, T, Q>(v1.x << v2.x, v1.x << v2.y);
	}

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator<<(vec<2, T, Q> const& v1, vec<2, T, Q> const& v2)
	{
		return vec<2, T, Q>(v1.x << v2.x, v1.y << v2.y);
	}

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator>>(vec<2, T, Q> const& v, T scalar)
	{
		return vec<2, T, Q>(v.x >> scalar, v.y >> scalar);
	}

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator>>(T scalar, vec<2, T, Q> const& v)
	{
		return vec<2, T, Q>(scalar >> v.x, scalar >> v.y);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator>>(vec<2, T, Q> const& v1, vec<1, T, Q> const& v2)
	{
		return vec<2, T, Q>(v1.x >> v2.x, v1.y >> v2.x);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator>>(vec<1, T, Q> const& v1, vec<2, T, Q> const& v2)
	{
		return vec<2, T, Q>(v1.x >> v2.x, v1.x >> v2.y);
	}

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator>>(vec<2, T, Q> const& v1, vec<2, T, Q> const& v2)
	{
		return vec<2, T, Q>(v1.x >> v2.x, v1.y >> v2.y);
	}

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator~(vec<2, T, Q> const& v)
	{
		return vec<2, T, Q>(~v.x, ~v.y);
	}

	/// Conditional Operators

	template <typename T, qualifier Q>
	constexpr bool operator==(vec<2, T, Q> const& v1, vec<2, T, Q> const& v2)
	{
		return detail::Equal<T, Q, std::numeric_limits<T>::is_iec559, sizeof(T) * 4, detail::IsAligned<Q>::value>::compute(v1, v2);
	}

	template <typename T, qualifier Q>
	constexpr bool operator!=(vec<2, T, Q> const& v1, vec<2, T, Q> const& v2)
	{
		return !(v1 == v2);
	}

	template <typename T, qualifier Q>
	constexpr bool operator&&(vec<2, T, Q> const& v1, vec<2, T, Q> const& v2)
	{
		return (v1.x && v2.x, v1.y && v2.y);
	}

	template <typename T, qualifier Q>
	constexpr bool operator||(vec<2, T, Q> const& v1, vec<2, T, Q> const& v2)
	{
		return (v1.x || v2.x, v1.y || v2.y);
	}

} // namespace mim

