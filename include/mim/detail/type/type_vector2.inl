// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#include "mim/detail/compute/compute_vector.hpp"

namespace mim
{

	// Element Accessors

	template <typename T>
	constexpr T& vec<2, T>::operator[](size_type i)
	{
		switch (i) {
		default:
		case 0: return x;
		case 1: return y;
		}
	}

	template <typename T>
	constexpr T const& vec<2, T>::operator[](size_type i) const
	{

		switch (i) {
		default:
		case 0: return x;
		case 1: return y;
		}
	}

	template <typename T>
	T& vec<2, T>::at(std::size_t i)
	{

		switch (i) {
		default:
		case 0: return x;
		case 1: return y;
		}
	}

	template <typename T>
	const T& vec<2, T>::at(std::size_t i) const
	{

		switch (i) {
		default:
		case 0: return x;
		case 1: return y;
		}
	}

	/// Constructors

	template <typename T>
	constexpr vec<2, T>::vec() : x(0), y(0)
	{
	}

	template <typename T>
	constexpr vec<2, T>::vec(T _x, T _y) : x(_x), y(_y)
	{
	}

	template <typename T>
	constexpr vec<2, T>::vec(vec<2, T> const& v) : x(v.x), y(v.y)
	{
	}

	template <typename T>
	constexpr vec<2, T>::vec(T scalar) : x(scalar), y(scalar)
	{
	}

	// U Template Constructors

	template <typename T>
	template <typename U>
	constexpr vec<2, T>::vec(vec<1, U> const& scalar) : x(static_cast<T>(scalar.x)), y(static_cast<T>(scalar.x))
	{
	}

	template <typename T>
	template <typename U>
	constexpr vec<2, T>::vec(vec<2, U> const& v) : x(static_cast<T>(v.x)), y(static_cast<T>(v.y))
	{
	}

	template <typename T>
	template <typename U>
	constexpr vec<2, T>::vec(vec<3, U> const& v) : x(static_cast<T>(v.x)), y(static_cast<T>(v.y))
	{
	}

	template <typename T>
	template <typename U>
	constexpr vec<2, T>::vec(vec<4, U> const& v) : x(static_cast<T>(v.x)), y(static_cast<T>(v.y))
	{
	}

	// AB Template Constructors

	template <typename T>
	template <typename A, typename B>
	constexpr vec<2, T>::vec(A _x, B _y) : x(static_cast<T>(_x)), y(static_cast<T>(_y))
	{
	}

	template <typename T>
	template <typename A, typename B>
	constexpr vec<2, T>::vec(vec<1, A> const& _x, B _y) : x(static_cast<T>(_x.x)), y(static_cast<T>(_y))
	{
	}

	template <typename T>
	template <typename A, typename B>
	constexpr vec<2, T>::vec(A _x, vec<1, B> const& _y) : x(static_cast<T>(_x)), y(static_cast<T>(_y.x))
	{
	}

	template <typename T>
	template <typename A, typename B>
	constexpr vec<2, T>::vec(vec<1, A> const& _x, vec<1, B> const& _y) : x(static_cast<T>(_x.x)), y(static_cast<T>(_y.x))
	{
	}

	/// Assignment Operators

	template <typename T>
	constexpr vec<2, T>& vec<2, T>::operator=(T scalar)
	{
		this->x = scalar;
		this->y = scalar;
		return *this;
	}

	template <typename T>
	constexpr vec<2, T>& vec<2, T>::operator=(vec const& v)
	{
		this->x = v.x;
		this->y = v.y;
		return *this;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	template <typename U>
	constexpr vec<2, T>& vec<2, T>::operator=(vec<1, U> const& scalar)
	{
		this->x = static_cast<T>(scalar.x);
		this->y = static_cast<T>(scalar.x);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<2, T>& vec<2, T>::operator=(vec<2, U> const& v)
	{
		this->x = static_cast<T>(v.x);
		this->y = static_cast<T>(v.y);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<2, T>& vec<2, T>::operator+=(U scalar)
	{
		this->x += static_cast<T>(scalar);
		this->y += static_cast<T>(scalar);
		return *this;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	template <typename U>
	constexpr vec<2, T>& vec<2, T>::operator+=(vec<1, U> const& scalar)
	{
		this->x += static_cast<T>(scalar.x);
		this->y += static_cast<T>(scalar.x);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<2, T>& vec<2, T>::operator+=(vec<2, U> const& v)
	{
		this->x += static_cast<T>(v.x);
		this->y += static_cast<T>(v.y);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<2, T>& vec<2, T>::operator-=(U scalar)
	{
		this->x -= static_cast<T>(scalar);
		this->y -= static_cast<T>(scalar);
		return *this;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	template <typename U>
	constexpr vec<2, T>& vec<2, T>::operator-=(vec<1, U> const& scalar)
	{
		this->x -= static_cast<T>(scalar.x);
		this->y -= static_cast<T>(scalar.x);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<2, T>& vec<2, T>::operator-=(vec<2, U> const& v)
	{
		this->x -= static_cast<T>(v.x);
		this->y -= static_cast<T>(v.y);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<2, T>& vec<2, T>::operator*=(U scalar)
	{
		this->x *= static_cast<T>(scalar);
		this->y *= static_cast<T>(scalar);
		return *this;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	template <typename U>
	constexpr vec<2, T>& vec<2, T>::operator*=(vec<1, U> const& scalar)
	{
		this->x *= static_cast<T>(scalar.x);
		this->y *= static_cast<T>(scalar.x);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<2, T>& vec<2, T>::operator*=(vec<2, U> const& v)
	{
		this->x *= static_cast<T>(v.x);
		this->y *= static_cast<T>(v.y);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<2, T>& vec<2, T>::operator/=(U scalar)
	{
		this->x /= static_cast<T>(scalar);
		this->y /= static_cast<T>(scalar);
		return *this;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	template <typename U>
	constexpr vec<2, T>& vec<2, T>::operator/=(vec<1, U> const& scalar)
	{
		this->x /= static_cast<T>(scalar.x);
		this->y /= static_cast<T>(scalar.x);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<2, T>& vec<2, T>::operator/=(vec<2, U> const& v)
	{
		this->x /= static_cast<T>(v.x);
		this->y /= static_cast<T>(v.y);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<2, T>& vec<2, T>::operator%=(U scalar)
	{
		this->x %= static_cast<T>(scalar);
		this->y %= static_cast<T>(scalar);
		return *this;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	template <typename U>
	constexpr vec<2, T>& vec<2, T>::operator%=(vec<1, U> const& scalar)
	{
		this->x %= static_cast<T>(scalar.x);
		this->y %= static_cast<T>(scalar.x);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<2, T>& vec<2, T>::operator%=(vec<2, U> const& v)
	{
		this->x %= static_cast<T>(v.x);
		this->y %= static_cast<T>(v.y);
		return *this;
	}

	/// Increment and Decrement Operators

	template <typename T>
	constexpr vec<2, T>& vec<2, T>::operator++()
	{
		++this->x;
		++this->y;
		return *this;
	}

	template <typename T>
	constexpr vec<2, T>& vec<2, T>::operator--()
	{
		--this->x;
		--this->y;
		return *this;
	}

	template <typename T>
	constexpr const vec<2, T> vec<2, T>::operator++(int)
	{
		vec<2, T> v(*this);
		++this->x;
		++this->y;
		return v;
	}

	template <typename T>
	constexpr const vec<2, T> vec<2, T>::operator--(int)
	{
		vec<2, T> v(*this);
		--this->x;
		--this->y;
		return v;
	}

	/// Bitwise Assignment Operators
	// We will not be supporting bitwise assignment operations between vec 3-4 as it would not make much sense from a math standpoint.
	// This can change at a later date but for now I'm not going to bother with it for now.

	template <typename T>
	template <typename U>
	constexpr vec<2, T>& vec<2, T>::operator&=(U scalar)
	{
		this->x &= static_cast<T>(scalar);
		this->y &= static_cast<T>(scalar);
		return *this;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	template <typename U>
	constexpr vec<2, T>& vec<2, T>::operator&=(vec<1, U> const& scalar)
	{
		this->x &= static_cast<T>(scalar.x);
		this->y &= static_cast<T>(scalar.x);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<2, T>& vec<2, T>::operator&=(vec<2, U> const& v)
	{
		this->x &= static_cast<T>(v.x);
		this->y &= static_cast<T>(v.y);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<2, T>& vec<2, T>::operator|=(U scalar)
	{
		this->x |= static_cast<T>(scalar);
		this->y |= static_cast<T>(scalar);
		return *this;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	template <typename U>
	constexpr vec<2, T>& vec<2, T>::operator|=(vec<1, U> const& scalar)
	{
		this->x |= static_cast<T>(scalar.x);
		this->y |= static_cast<T>(scalar.x);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<2, T>& vec<2, T>::operator|=(vec<2, U> const& v)
	{
		this->x |= static_cast<T>(v.x);
		this->y |= static_cast<T>(v.y);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<2, T>& vec<2, T>::operator^=(U scalar)
	{
		this->x ^= static_cast<T>(scalar);
		this->y ^= static_cast<T>(scalar);
		return *this;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	template <typename U>
	constexpr vec<2, T>& vec<2, T>::operator^=(vec<1, U> const& scalar)
	{
		this->x ^= static_cast<T>(scalar.x);
		this->y ^= static_cast<T>(scalar.x);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<2, T>& vec<2, T>::operator^=(vec<2, U> const& v)
	{
		this->x ^= static_cast<T>(v.x);
		this->y ^= static_cast<T>(v.y);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<2, T>& vec<2, T>::operator<<=(U scalar)
	{
		this->x <<= static_cast<T>(scalar);
		this->y <<= static_cast<T>(scalar);
		return *this;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	template <typename U>
	constexpr vec<2, T>& vec<2, T>::operator<<=(vec<1, U> const& scalar)
	{
		this->x <<= static_cast<T>(scalar.x);
		this->y <<= static_cast<T>(scalar.x);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<2, T>& vec<2, T>::operator<<=(vec<2, U> const& v)
	{
		this->x <<= static_cast<T>(v.x);
		this->y <<= static_cast<T>(v.y);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<2, T>& vec<2, T>::operator>>=(U scalar)
	{
		this->x >>= static_cast<T>(scalar);
		this->y >>= static_cast<T>(scalar);
		return *this;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	template <typename U>
	constexpr vec<2, T>& vec<2, T>::operator>>=(vec<1, U> const& scalar)
	{
		this->x >>= static_cast<T>(scalar.x);
		this->y >>= static_cast<T>(scalar.x);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<2, T>& vec<2, T>::operator>>=(vec<2, U> const& v)
	{
		this->x >>= static_cast<T>(v.x);
		this->y >>= static_cast<T>(v.y);
		return *this;
	}

	// We will not be supporting binary operations between vec 3-4 as it would not make much sense from a math standpoint.
	// This can change at a later date but for now I'm not going to bother with it for now.

	/// Unary operators

	template <typename T>
	constexpr vec<2, T> operator+(vec<2, T> const& v)
	{
		return v;
	}

	template <typename T>
	constexpr vec<2, T> operator-(vec<2, T> const& v)
	{
		return vec<2, T>(-v.x, -v.y);
	}

	/// Binary Operators

	template <typename T>
	constexpr vec<2, T> operator+(vec<2, T> const& v, T scalar)
	{
		return vec<2, T>(v.x + scalar, v.y + scalar);
	}

	template <typename T>
	constexpr vec<2, T> operator+(T scalar, vec<2, T> const& v)
	{
		return vec<2, T>(scalar + v.x, scalar + v.y);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	constexpr vec<2, T> operator+(vec<2, T> const& v1, vec<1, T> const& v2)
	{
		return vec<2, T>(v1.x + v2.x, v1.y + v2.x);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	constexpr vec<2, T> operator+(vec<1, T> const& v1, vec<2, T> const& v2)
	{
		return vec<2, T>(v1.x + v2.x, v1.x + v2.y);
	}

	template <typename T>
	constexpr vec<2, T> operator+(vec<2, T> const& v1, vec<2, T> const& v2)
	{
		return vec<2, T>(v1.x + v2.x, v1.y + v2.y);
	}

	template <typename T>
	constexpr vec<2, T> operator-(vec<2, T> const& v, T scalar)
	{
		return vec<2, T>(v.x - scalar, v.y - scalar);
	}

	template <typename T>
	constexpr vec<2, T> operator-(T scalar, vec<2, T> const& v)
	{
		return vec<2, T>(scalar - v.x, scalar - v.y);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	constexpr vec<2, T> operator-(vec<2, T> const& v1, vec<1, T> const& v2)
	{
		return vec<2, T>(v1.x - v2.x, v1.y - v2.x);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	constexpr vec<2, T> operator-(vec<1, T> const& v1, vec<2, T> const& v2)
	{
		return vec<2, T>(v1.x - v2.x, v1.x - v2.y);
	}

	template <typename T>
	constexpr vec<2, T> operator-(vec<2, T> const& v1, vec<2, T> const& v2)
	{
		return vec<2, T>(v1.x - v2.x, v1.y - v2.y);
	}

	template <typename T>
	constexpr vec<2, T> operator*(vec<2, T> const& v, T scalar)
	{
		return vec<2, T>(v.x * scalar, v.y * scalar);
	}

	template <typename T>
	constexpr vec<2, T> operator*(T scalar, vec<2, T> const& v)
	{
		return vec<2, T>(scalar * v.x, scalar * v.y);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	constexpr vec<2, T> operator*(vec<2, T> const& v1, vec<1, T> const& v2)
	{
		return vec<2, T>(v1.x * v2.x, v1.y * v2.x);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	constexpr vec<2, T> operator*(vec<1, T> const& v1, vec<2, T> const& v2)
	{
		return vec<2, T>(v1.x * v2.x, v1.x * v2.y);
	}

	template <typename T>
	constexpr vec<2, T> operator*(vec<2, T> const& v1, vec<2, T> const& v2)
	{
		return vec<2, T>(v1.x * v2.x, v1.y * v2.y);
	}

	template <typename T>
	constexpr vec<2, T> operator/(vec<2, T> const& v, T scalar)
	{
		return vec<2, T>(v.x / scalar, v.y / scalar);
	}

	template <typename T>
	constexpr vec<2, T> operator/(T scalar, vec<2, T> const& v)
	{
		return vec<2, T>(scalar / v.x, scalar / v.y);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	constexpr vec<2, T> operator/(vec<2, T> const& v1, vec<1, T> const& v2)
	{
		return vec<2, T>(v1.x / v2.x, v1.y / v2.x);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	constexpr vec<2, T> operator/(vec<1, T> const& v1, vec<2, T> const& v2)
	{
		return vec<2, T>(v1.x / v2.x, v1.x / v2.y);
	}

	template <typename T>
	constexpr vec<2, T> operator/(vec<2, T> const& v1, vec<2, T> const& v2)
	{
		return vec<2, T>(v1.x / v2.x, v1.y / v2.y);
	}

	template <typename T>
	constexpr vec<2, T> operator%(vec<2, T> const& v, T scalar)
	{
		return vec<2, T>(v.x % scalar, v.y % scalar);
	}

	template <typename T>
	constexpr vec<2, T> operator%(T scalar, vec<2, T> const& v)
	{
		return vec<2, T>(scalar % v.x, scalar % v.y);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	constexpr vec<2, T> operator%(vec<2, T> const& v1, vec<1, T> const& v2)
	{
		return vec<2, T>(v1.x % v2.x, v1.y % v2.x);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	constexpr vec<2, T> operator%(vec<1, T> const& v1, vec<2, T> const& v2)
	{
		return vec<2, T>(v1.x % v2.x, v1.x % v2.y);
	}

	template <typename T>
	constexpr vec<2, T> operator%(vec<2, T> const& v1, vec<2, T> const& v2)
	{
		return vec<2, T>(v1.x % v2.x, v1.y % v2.y);
	}

	/// Bitwise Binary Operators

	template <typename T>
	constexpr vec<2, T> operator&(vec<2, T> const& v, T scalar)
	{
		return vec<2, T>(v.x & scalar, v.y & scalar);
	}

	template <typename T>
	constexpr vec<2, T> operator&(T scalar, vec<2, T> const& v)
	{
		return vec<2, T>(scalar & v.x, scalar & v.y);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	constexpr vec<2, T> operator&(vec<2, T> const& v1, vec<1, T> const& v2)
	{
		return vec<2, T>(v1.x & v2.x, v1.y & v2.x);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	constexpr vec<2, T> operator&(vec<1, T> const& v1, vec<2, T> const& v2)
	{
		return vec<2, T>(v1.x & v2.x, v1.x & v2.y);
	}

	template <typename T>
	constexpr vec<2, T> operator&(vec<2, T> const& v1, vec<2, T> const& v2)
	{
		return vec<2, T>(v1.x & v2.x, v1.y & v2.y);
	}

	template <typename T>
	constexpr vec<2, T> operator|(vec<2, T> const& v, T scalar)
	{
		return vec<2, T>(v.x | scalar, v.y | scalar);
	}

	template <typename T>
	constexpr vec<2, T> operator|(T scalar, vec<2, T> const& v)
	{
		return vec<2, T>(scalar | v.x, scalar | v.y);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	constexpr vec<2, T> operator|(vec<2, T> const& v1, vec<1, T> const& v2)
	{
		return vec<2, T>(v1.x | v2.x, v1.y | v2.x);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	constexpr vec<2, T> operator|(vec<1, T> const& v1, vec<2, T> const& v2)
	{
		return vec<2, T>(v1.x | v2.x, v1.x | v2.y);
	}

	template <typename T>
	constexpr vec<2, T> operator|(vec<2, T> const& v1, vec<2, T> const& v2)
	{
		return vec<2, T>(v1.x | v2.x, v1.y | v2.y);
	}

	template <typename T>
	constexpr vec<2, T> operator^(vec<2, T> const& v, T scalar)
	{
		return vec<2, T>(v.x ^ scalar, v.y ^ scalar);
	}

	template <typename T>
	constexpr vec<2, T> operator^(T scalar, vec<2, T> const& v)
	{
		return vec<2, T>(scalar ^ v.x, scalar ^ v.y);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	constexpr vec<2, T> operator^(vec<2, T> const& v1, vec<1, T> const& v2)
	{
		return vec<2, T>(v1.x ^ v2.x, v1.y ^ v2.x);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	constexpr vec<2, T> operator^(vec<1, T> const& v1, vec<2, T> const& v2)
	{
		return vec<2, T>(v1.x ^ v2.x, v1.x ^ v2.y);
	}

	template <typename T>
	constexpr vec<2, T> operator^(vec<2, T> const& v1, vec<2, T> const& v2)
	{
		return vec<2, T>(v1.x ^ v2.x, v1.y ^ v2.y);
	}

	template <typename T>
	constexpr vec<2, T> operator<<(vec<2, T> const& v, T scalar)
	{
		return vec<2, T>(v.x << scalar, v.y << scalar);
	}

	template <typename T>
	constexpr vec<2, T> operator<<(T scalar, vec<2, T> const& v)
	{
		return vec<2, T>(scalar << v.x, scalar << v.y);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	constexpr vec<2, T> operator<<(vec<2, T> const& v1, vec<1, T> const& v2)
	{
		return vec<2, T>(v1.x << v2.x, v1.y << v2.x);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	constexpr vec<2, T> operator<<(vec<1, T> const& v1, vec<2, T> const& v2)
	{
		return vec<2, T>(v1.x << v2.x, v1.x << v2.y);
	}

	template <typename T>
	constexpr vec<2, T> operator<<(vec<2, T> const& v1, vec<2, T> const& v2)
	{
		return vec<2, T>(v1.x << v2.x, v1.y << v2.y);
	}

	template <typename T>
	constexpr vec<2, T> operator>>(vec<2, T> const& v, T scalar)
	{
		return vec<2, T>(v.x >> scalar, v.y >> scalar);
	}

	template <typename T>
	constexpr vec<2, T> operator>>(T scalar, vec<2, T> const& v)
	{
		return vec<2, T>(scalar >> v.x, scalar >> v.y);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	constexpr vec<2, T> operator>>(vec<2, T> const& v1, vec<1, T> const& v2)
	{
		return vec<2, T>(v1.x >> v2.x, v1.y >> v2.x);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	constexpr vec<2, T> operator>>(vec<1, T> const& v1, vec<2, T> const& v2)
	{
		return vec<2, T>(v1.x >> v2.x, v1.x >> v2.y);
	}

	template <typename T>
	constexpr vec<2, T> operator>>(vec<2, T> const& v1, vec<2, T> const& v2)
	{
		return vec<2, T>(v1.x >> v2.x, v1.y >> v2.y);
	}

	template <typename T>
	constexpr vec<2, T> operator~(vec<2, T> const& v)
	{
		return vec<2, T>(~v.x, ~v.y);
	}

	/// Conditional Operators

	// TODO: Would it be more correct to account for floating point error in a template specialization?

	template <typename T>
	constexpr bool operator==(vec<2, T> const& v1, vec<2, T> const& v2)
	{
		return (v1.x == v2.x, v1.y == v2.y);
	}

	template <typename T>
	constexpr bool operator!=(vec<2, T> const& v1, vec<2, T> const& v2)
	{
		return !(v1 == v2);
	}

	template <typename T>
	constexpr vec<2, bool> operator&&(vec<2, T> const& v1, vec<2, T> const& v2)
	{
		return {v1.x && v2.x, v1.y && v2.y};
	}

	template <typename T>
	constexpr vec<2, bool> operator||(vec<2, T> const& v1, vec<2, T> const& v2)
	{
		return {v1.x || v2.x, v1.y || v2.y};
	}

} // namespace mim

