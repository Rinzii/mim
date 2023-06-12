// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#include "mim/detail/compute/compute_vector.hpp"
#include "mim/mimMath.hpp"

namespace mim
{

	// Element Accessors

	template <typename T, qualifier Q>
	constexpr T& VectorT<2, T, Q>::operator[](size_type i)
	{
		if (i >= this->size()) { throw std::out_of_range("VectorT<2, T, Q>::operator[]"); }
		switch (i) {
		default:
		case 0: return x;
		case 1: return y;
		}
	}

	template <typename T, qualifier Q>
	constexpr T const& VectorT<2, T, Q>::operator[](size_type i) const
	{
		if (i >= this->size()) { throw std::out_of_range("VectorT<2, T, Q>::operator[]"); }

		switch (i) {
		default:
		case 0: return x;
		case 1: return y;
		}
	}

	template <typename T, qualifier Q>
	T& VectorT<2, T, Q>::at(std::size_t i)
	{
		if (i >= this->size()) { throw std::out_of_range("VectorT<2, T, Q>::at"); }

		switch (i) {
		default:
		case 0: return x;
		case 1: return y;
		}
	}

	template <typename T, qualifier Q>
	const T& VectorT<2, T, Q>::at(std::size_t i) const
	{
		if (i >= this->size()) { throw std::out_of_range("VectorT<2, T, Q>::at"); }

		switch (i) {
		default:
		case 0: return x;
		case 1: return y;
		}
	}

	/// Constructors

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q>::VectorT() : x(0), y(0)
	{
	}

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q>::VectorT(T _x, T _y) : x(_x), y(_y)
	{
	}

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q>::VectorT(VectorT<2, T, Q> const& v) : x(v.x), y(v.y)
	{
	}

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q>::VectorT(T scalar) : x(scalar), y(scalar)
	{
	}

	/// Template Constructors

	template <typename T, qualifier Q>
	template <qualifier P>
	constexpr VectorT<2, T, Q>::VectorT(VectorT<2, T, P> const& v) : x(v.x), y(v.y)
	{
	}

	// U Template Constructors

	template <typename T, qualifier Q>
	template <typename U, qualifier P>
	constexpr VectorT<2, T, Q>::VectorT(VectorT<1, U, P> const& scalar) : x(static_cast<T>(scalar.x)), y(static_cast<T>(scalar.x))
	{
	}

	template <typename T, qualifier Q>
	template <typename U, qualifier P>
	constexpr VectorT<2, T, Q>::VectorT(VectorT<2, U, P> const& v) : x(static_cast<T>(v.x)), y(static_cast<T>(v.y))
	{
	}

	template <typename T, qualifier Q>
	template <typename U, qualifier P>
	constexpr VectorT<2, T, Q>::VectorT(VectorT<3, U, P> const& v) : x(static_cast<T>(v.x)), y(static_cast<T>(v.y))
	{
	}

	template <typename T, qualifier Q>
	template <typename U, qualifier P>
	constexpr VectorT<2, T, Q>::VectorT(VectorT<4, U, P> const& v) : x(static_cast<T>(v.x)), y(static_cast<T>(v.y))
	{
	}

	// AB Template Constructors

	template <typename T, qualifier Q>
	template <typename A, typename B>
	constexpr VectorT<2, T, Q>::VectorT(A _x, B _y) : x(static_cast<T>(_x)), y(static_cast<T>(_y))
	{
	}

	template <typename T, qualifier Q>
	template <typename A, typename B>
	constexpr VectorT<2, T, Q>::VectorT(VectorT<1, A, Q> const& _x, B _y) : x(static_cast<T>(_x.x)), y(static_cast<T>(_y))
	{
	}

	template <typename T, qualifier Q>
	template <typename A, typename B>
	constexpr VectorT<2, T, Q>::VectorT(A _x, VectorT<1, B, Q> const& _y) : x(static_cast<T>(_x)), y(static_cast<T>(_y.x))
	{
	}

	template <typename T, qualifier Q>
	template <typename A, typename B>
	constexpr VectorT<2, T, Q>::VectorT(VectorT<1, A, Q> const& _x, VectorT<1, B, Q> const& _y) : x(static_cast<T>(_x.x)), y(static_cast<T>(_y.x))
	{
	}

	/// Assignment Operators

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q>& VectorT<2, T, Q>::operator=(T scalar)
	{
		this->x = scalar;
		this->y = scalar;
		return *this;
	}

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q>& VectorT<2, T, Q>::operator=(VectorT const& v)
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
	constexpr VectorT<2, T, Q>& VectorT<2, T, Q>::operator=(VectorT<1, U, Q> const& scalar)
	{
		this->x = static_cast<T>(scalar.x);
		this->y = static_cast<T>(scalar.x);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr VectorT<2, T, Q>& VectorT<2, T, Q>::operator=(VectorT<2, U, Q> const& v)
	{
		this->x = static_cast<T>(v.x);
		this->y = static_cast<T>(v.y);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr VectorT<2, T, Q>& VectorT<2, T, Q>::operator+=(U scalar)
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
	constexpr VectorT<2, T, Q>& VectorT<2, T, Q>::operator+=(VectorT<1, U, Q> const& scalar)
	{
		this->x += static_cast<T>(scalar.x);
		this->y += static_cast<T>(scalar.x);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr VectorT<2, T, Q>& VectorT<2, T, Q>::operator+=(VectorT<2, U, Q> const& v)
	{
		this->x += static_cast<T>(v.x);
		this->y += static_cast<T>(v.y);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr VectorT<2, T, Q>& VectorT<2, T, Q>::operator-=(U scalar)
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
	constexpr VectorT<2, T, Q>& VectorT<2, T, Q>::operator-=(VectorT<1, U, Q> const& scalar)
	{
		this->x -= static_cast<T>(scalar.x);
		this->y -= static_cast<T>(scalar.x);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr VectorT<2, T, Q>& VectorT<2, T, Q>::operator-=(VectorT<2, U, Q> const& v)
	{
		this->x -= static_cast<T>(v.x);
		this->y -= static_cast<T>(v.y);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr VectorT<2, T, Q>& VectorT<2, T, Q>::operator*=(U scalar)
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
	constexpr VectorT<2, T, Q>& VectorT<2, T, Q>::operator*=(VectorT<1, U, Q> const& scalar)
	{
		this->x *= static_cast<T>(scalar.x);
		this->y *= static_cast<T>(scalar.x);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr VectorT<2, T, Q>& VectorT<2, T, Q>::operator*=(VectorT<2, U, Q> const& v)
	{
		this->x *= static_cast<T>(v.x);
		this->y *= static_cast<T>(v.y);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr VectorT<2, T, Q>& VectorT<2, T, Q>::operator/=(U scalar)
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
	constexpr VectorT<2, T, Q>& VectorT<2, T, Q>::operator/=(VectorT<1, U, Q> const& scalar)
	{
		this->x /= static_cast<T>(scalar.x);
		this->y /= static_cast<T>(scalar.x);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr VectorT<2, T, Q>& VectorT<2, T, Q>::operator/=(VectorT<2, U, Q> const& v)
	{
		this->x /= static_cast<T>(v.x);
		this->y /= static_cast<T>(v.y);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr VectorT<2, T, Q>& VectorT<2, T, Q>::operator%=(U scalar)
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
	constexpr VectorT<2, T, Q>& VectorT<2, T, Q>::operator%=(VectorT<1, U, Q> const& scalar)
	{
		this->x %= static_cast<T>(scalar.x);
		this->y %= static_cast<T>(scalar.x);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr VectorT<2, T, Q>& VectorT<2, T, Q>::operator%=(VectorT<2, U, Q> const& v)
	{
		this->x %= static_cast<T>(v.x);
		this->y %= static_cast<T>(v.y);
		return *this;
	}

	/// Increment and Decrement Operators

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q>& VectorT<2, T, Q>::operator++()
	{
		++this->x;
		++this->y;
		return *this;
	}

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q>& VectorT<2, T, Q>::operator--()
	{
		--this->x;
		--this->y;
		return *this;
	}

	template <typename T, qualifier Q>
	constexpr const VectorT<2, T, Q> VectorT<2, T, Q>::operator++(int)
	{
		VectorT<2, T, Q> v(*this);
		++this->x;
		++this->y;
		return v;
	}

	template <typename T, qualifier Q>
	constexpr const VectorT<2, T, Q> VectorT<2, T, Q>::operator--(int)
	{
		VectorT<2, T, Q> v(*this);
		--this->x;
		--this->y;
		return v;
	}

	/// Bitwise Assignment Operators
	// We will not be supporting bitwise assignment operations between vec 3-4 as it would not make much sense from a math standpoint.
	// This can change at a later date but for now I'm not going to bother with it for now.

	template <typename T, qualifier Q>
	template <typename U>
	constexpr VectorT<2, T, Q>& VectorT<2, T, Q>::operator&=(U scalar)
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
	constexpr VectorT<2, T, Q>& VectorT<2, T, Q>::operator&=(VectorT<1, U, Q> const& scalar)
	{
		this->x &= static_cast<T>(scalar.x);
		this->y &= static_cast<T>(scalar.x);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr VectorT<2, T, Q>& VectorT<2, T, Q>::operator&=(VectorT<2, U, Q> const& v)
	{
		this->x &= static_cast<T>(v.x);
		this->y &= static_cast<T>(v.y);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr VectorT<2, T, Q>& VectorT<2, T, Q>::operator|=(U scalar)
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
	constexpr VectorT<2, T, Q>& VectorT<2, T, Q>::operator|=(VectorT<1, U, Q> const& scalar)
	{
		this->x |= static_cast<T>(scalar.x);
		this->y |= static_cast<T>(scalar.x);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr VectorT<2, T, Q>& VectorT<2, T, Q>::operator|=(VectorT<2, U, Q> const& v)
	{
		this->x |= static_cast<T>(v.x);
		this->y |= static_cast<T>(v.y);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr VectorT<2, T, Q>& VectorT<2, T, Q>::operator^=(U scalar)
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
	constexpr VectorT<2, T, Q>& VectorT<2, T, Q>::operator^=(VectorT<1, U, Q> const& scalar)
	{
		this->x ^= static_cast<T>(scalar.x);
		this->y ^= static_cast<T>(scalar.x);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr VectorT<2, T, Q>& VectorT<2, T, Q>::operator^=(VectorT<2, U, Q> const& v)
	{
		this->x ^= static_cast<T>(v.x);
		this->y ^= static_cast<T>(v.y);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr VectorT<2, T, Q>& VectorT<2, T, Q>::operator<<=(U scalar)
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
	constexpr VectorT<2, T, Q>& VectorT<2, T, Q>::operator<<=(VectorT<1, U, Q> const& scalar)
	{
		this->x <<= static_cast<T>(scalar.x);
		this->y <<= static_cast<T>(scalar.x);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr VectorT<2, T, Q>& VectorT<2, T, Q>::operator<<=(VectorT<2, U, Q> const& v)
	{
		this->x <<= static_cast<T>(v.x);
		this->y <<= static_cast<T>(v.y);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr VectorT<2, T, Q>& VectorT<2, T, Q>::operator>>=(U scalar)
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
	constexpr VectorT<2, T, Q>& VectorT<2, T, Q>::operator>>=(VectorT<1, U, Q> const& scalar)
	{
		this->x >>= static_cast<T>(scalar.x);
		this->y >>= static_cast<T>(scalar.x);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr VectorT<2, T, Q>& VectorT<2, T, Q>::operator>>=(VectorT<2, U, Q> const& v)
	{
		this->x >>= static_cast<T>(v.x);
		this->y >>= static_cast<T>(v.y);
		return *this;
	}

	// We will not be supporting binary operations between vec 3-4 as it would not make much sense from a math standpoint.
	// This can change at a later date but for now I'm not going to bother with it for now.

	/// Unary operators

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator+(VectorT<2, T, Q> const& v)
	{
		return v;
	}

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator-(VectorT<2, T, Q> const& v)
	{
		return VectorT<2, T, Q>(-v.x, -v.y);
	}

	/// Binary Operators

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator+(VectorT<2, T, Q> const& v, T scalar)
	{
		return VectorT<2, T, Q>(v.x + scalar, v.y + scalar);
	}

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator+(T scalar, VectorT<2, T, Q> const& v)
	{
		return VectorT<2, T, Q>(scalar + v.x, scalar + v.y);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator+(VectorT<2, T, Q> const& v1, VectorT<1, T, Q> const& v2)
	{
		return VectorT<2, T, Q>(v1.x + v2.x, v1.y + v2.x);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator+(VectorT<1, T, Q> const& v1, VectorT<2, T, Q> const& v2)
	{
		return VectorT<2, T, Q>(v1.x + v2.x, v1.x + v2.y);
	}

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator+(VectorT<2, T, Q> const& v1, VectorT<2, T, Q> const& v2)
	{
		return VectorT<2, T, Q>(v1.x + v2.x, v1.y + v2.y);
	}

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator-(VectorT<2, T, Q> const& v, T scalar)
	{
		return VectorT<2, T, Q>(v.x - scalar, v.y - scalar);
	}

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator-(T scalar, VectorT<2, T, Q> const& v)
	{
		return VectorT<2, T, Q>(scalar - v.x, scalar - v.y);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator-(VectorT<2, T, Q> const& v1, VectorT<1, T, Q> const& v2)
	{
		return VectorT<2, T, Q>(v1.x - v2.x, v1.y - v2.x);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator-(VectorT<1, T, Q> const& v1, VectorT<2, T, Q> const& v2)
	{
		return VectorT<2, T, Q>(v1.x - v2.x, v1.x - v2.y);
	}

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator-(VectorT<2, T, Q> const& v1, VectorT<2, T, Q> const& v2)
	{
		return VectorT<2, T, Q>(v1.x - v2.x, v1.y - v2.y);
	}

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator*(VectorT<2, T, Q> const& v, T scalar)
	{
		return VectorT<2, T, Q>(v.x * scalar, v.y * scalar);
	}

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator*(T scalar, VectorT<2, T, Q> const& v)
	{
		return VectorT<2, T, Q>(scalar * v.x, scalar * v.y);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator*(VectorT<2, T, Q> const& v1, VectorT<1, T, Q> const& v2)
	{
		return VectorT<2, T, Q>(v1.x * v2.x, v1.y * v2.x);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator*(VectorT<1, T, Q> const& v1, VectorT<2, T, Q> const& v2)
	{
		return VectorT<2, T, Q>(v1.x * v2.x, v1.x * v2.y);
	}

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator*(VectorT<2, T, Q> const& v1, VectorT<2, T, Q> const& v2)
	{
		return VectorT<2, T, Q>(v1.x * v2.x, v1.y * v2.y);
	}

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator/(VectorT<2, T, Q> const& v, T scalar)
	{
		return VectorT<2, T, Q>(v.x / scalar, v.y / scalar);
	}

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator/(T scalar, VectorT<2, T, Q> const& v)
	{
		return VectorT<2, T, Q>(scalar / v.x, scalar / v.y);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator/(VectorT<2, T, Q> const& v1, VectorT<1, T, Q> const& v2)
	{
		return VectorT<2, T, Q>(v1.x / v2.x, v1.y / v2.x);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator/(VectorT<1, T, Q> const& v1, VectorT<2, T, Q> const& v2)
	{
		return VectorT<2, T, Q>(v1.x / v2.x, v1.x / v2.y);
	}

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator/(VectorT<2, T, Q> const& v1, VectorT<2, T, Q> const& v2)
	{
		return VectorT<2, T, Q>(v1.x / v2.x, v1.y / v2.y);
	}

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator%(VectorT<2, T, Q> const& v, T scalar)
	{
		return VectorT<2, T, Q>(v.x % scalar, v.y % scalar);
	}

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator%(T scalar, VectorT<2, T, Q> const& v)
	{
		return VectorT<2, T, Q>(scalar % v.x, scalar % v.y);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator%(VectorT<2, T, Q> const& v1, VectorT<1, T, Q> const& v2)
	{
		return VectorT<2, T, Q>(v1.x % v2.x, v1.y % v2.x);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator%(VectorT<1, T, Q> const& v1, VectorT<2, T, Q> const& v2)
	{
		return VectorT<2, T, Q>(v1.x % v2.x, v1.x % v2.y);
	}

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator%(VectorT<2, T, Q> const& v1, VectorT<2, T, Q> const& v2)
	{
		return VectorT<2, T, Q>(v1.x % v2.x, v1.y % v2.y);
	}

	/// Bitwise Binary Operators

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator&(VectorT<2, T, Q> const& v, T scalar)
	{
		return VectorT<2, T, Q>(v.x & scalar, v.y & scalar);
	}

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator&(T scalar, VectorT<2, T, Q> const& v)
	{
		return VectorT<2, T, Q>(scalar & v.x, scalar & v.y);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator&(VectorT<2, T, Q> const& v1, VectorT<1, T, Q> const& v2)
	{
		return VectorT<2, T, Q>(v1.x & v2.x, v1.y & v2.x);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator&(VectorT<1, T, Q> const& v1, VectorT<2, T, Q> const& v2)
	{
		return VectorT<2, T, Q>(v1.x & v2.x, v1.x & v2.y);
	}

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator&(VectorT<2, T, Q> const& v1, VectorT<2, T, Q> const& v2)
	{
		return VectorT<2, T, Q>(v1.x & v2.x, v1.y & v2.y);
	}

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator|(VectorT<2, T, Q> const& v, T scalar)
	{
		return VectorT<2, T, Q>(v.x | scalar, v.y | scalar);
	}

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator|(T scalar, VectorT<2, T, Q> const& v)
	{
		return VectorT<2, T, Q>(scalar | v.x, scalar | v.y);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator|(VectorT<2, T, Q> const& v1, VectorT<1, T, Q> const& v2)
	{
		return VectorT<2, T, Q>(v1.x | v2.x, v1.y | v2.x);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator|(VectorT<1, T, Q> const& v1, VectorT<2, T, Q> const& v2)
	{
		return VectorT<2, T, Q>(v1.x | v2.x, v1.x | v2.y);
	}

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator|(VectorT<2, T, Q> const& v1, VectorT<2, T, Q> const& v2)
	{
		return VectorT<2, T, Q>(v1.x | v2.x, v1.y | v2.y);
	}

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator^(VectorT<2, T, Q> const& v, T scalar)
	{
		return VectorT<2, T, Q>(v.x ^ scalar, v.y ^ scalar);
	}

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator^(T scalar, VectorT<2, T, Q> const& v)
	{
		return VectorT<2, T, Q>(scalar ^ v.x, scalar ^ v.y);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator^(VectorT<2, T, Q> const& v1, VectorT<1, T, Q> const& v2)
	{
		return VectorT<2, T, Q>(v1.x ^ v2.x, v1.y ^ v2.x);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator^(VectorT<1, T, Q> const& v1, VectorT<2, T, Q> const& v2)
	{
		return VectorT<2, T, Q>(v1.x ^ v2.x, v1.x ^ v2.y);
	}

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator^(VectorT<2, T, Q> const& v1, VectorT<2, T, Q> const& v2)
	{
		return VectorT<2, T, Q>(v1.x ^ v2.x, v1.y ^ v2.y);
	}

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator<<(VectorT<2, T, Q> const& v, T scalar)
	{
		return VectorT<2, T, Q>(v.x << scalar, v.y << scalar);
	}

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator<<(T scalar, VectorT<2, T, Q> const& v)
	{
		return VectorT<2, T, Q>(scalar << v.x, scalar << v.y);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator<<(VectorT<2, T, Q> const& v1, VectorT<1, T, Q> const& v2)
	{
		return VectorT<2, T, Q>(v1.x << v2.x, v1.y << v2.x);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator<<(VectorT<1, T, Q> const& v1, VectorT<2, T, Q> const& v2)
	{
		return VectorT<2, T, Q>(v1.x << v2.x, v1.x << v2.y);
	}

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator<<(VectorT<2, T, Q> const& v1, VectorT<2, T, Q> const& v2)
	{
		return VectorT<2, T, Q>(v1.x << v2.x, v1.y << v2.y);
	}

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator>>(VectorT<2, T, Q> const& v, T scalar)
	{
		return VectorT<2, T, Q>(v.x >> scalar, v.y >> scalar);
	}

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator>>(T scalar, VectorT<2, T, Q> const& v)
	{
		return VectorT<2, T, Q>(scalar >> v.x, scalar >> v.y);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator>>(VectorT<2, T, Q> const& v1, VectorT<1, T, Q> const& v2)
	{
		return VectorT<2, T, Q>(v1.x >> v2.x, v1.y >> v2.x);
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator>>(VectorT<1, T, Q> const& v1, VectorT<2, T, Q> const& v2)
	{
		return VectorT<2, T, Q>(v1.x >> v2.x, v1.x >> v2.y);
	}

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator>>(VectorT<2, T, Q> const& v1, VectorT<2, T, Q> const& v2)
	{
		return VectorT<2, T, Q>(v1.x >> v2.x, v1.y >> v2.y);
	}

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator~(VectorT<2, T, Q> const& v)
	{
		return VectorT<2, T, Q>(~v.x, ~v.y);
	}

	/// Conditional Operators

	template <typename T, qualifier Q>
	constexpr bool operator==(VectorT<2, T, Q> const& v1, VectorT<2, T, Q> const& v2)
	{
		return detail::Equal<T, Q, std::numeric_limits<T>::is_iec559, sizeof(T) * 4, detail::IsAligned<Q>::value>::compute(v1, v2);
	}

	template <typename T, qualifier Q>
	constexpr bool operator!=(VectorT<2, T, Q> const& v1, VectorT<2, T, Q> const& v2)
	{
		return !(v1 == v2);
	}

	template <typename T, qualifier Q>
	constexpr bool operator&&(VectorT<2, T, Q> const& v1, VectorT<2, T, Q> const& v2)
	{
		return (v1.x && v2.x, v1.y && v2.y);
	}

	template <typename T, qualifier Q>
	constexpr bool operator||(VectorT<2, T, Q> const& v1, VectorT<2, T, Q> const& v2)
	{
		return (v1.x || v2.x, v1.y || v2.y);
	}

} // namespace mim

