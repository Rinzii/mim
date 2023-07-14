// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#include "mim/detail/compute/compute_vector.hpp"
#include <type_traits>

namespace mim
{

	// Element Accessors

	template <typename T, qualifier Q>
	constexpr T& vec<1, T, Q>::operator[](typename vec<1, T, Q>::size_type)
	{
		return x;
	}

	template <typename T, qualifier Q>
	constexpr const T& vec<1, T, Q>::operator[](typename vec<1, T, Q>::size_type) const
	{
		return x;
	}

	template <typename T, qualifier Q>
	T& vec<1, T, Q>::at(typename vec<1, T, Q>::size_type i)
	{
		static_assert(i < size(), "vec<1, T, Q>::at() : Index out of range.");

		return x;
	}

	template <typename T, qualifier Q>
	const T& vec<1, T, Q>::at(typename vec<1, T, Q>::size_type i) const
	{
		static_assert(i < size(), "vec<1, T, Q>::at() : Index out of range.");

		return x;
	}

	/// Constructors

	template <typename T, qualifier Q>
	constexpr vec<1, T, Q>::vec() : x(0)
	{
	}

	template <typename T, qualifier Q>
	constexpr vec<1, T, Q>::vec(vec<1, T, Q> const& v) : x(v.x)
	{
	}

	template <typename T, qualifier Q>
	constexpr vec<1, T, Q>::vec(T scalar) : x(scalar)
	{
	}

	/// Template Constructors

	template <typename T, qualifier Q>
	template <qualifier P>
	constexpr vec<1, T, Q>::vec(vec<1, T, P> const& v) : x(v.x)
	{
	}

	// U Constructors

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<1, T, Q>::vec(U scalar) : x(static_cast<T>(scalar))
	{
	}

	template <typename T, qualifier Q>
	template <typename U, qualifier P>
	constexpr vec<1, T, Q>::vec(vec<1, U, P> const& v) : x(static_cast<T>(v.x))
	{
	}

	template <typename T, qualifier Q>
	template <typename U, qualifier P>
	constexpr vec<1, T, Q>::vec(vec<2, U, P> const& v) : x(static_cast<T>(v.x))
	{
	}

	template <typename T, qualifier Q>
	template <typename U, qualifier P>
	constexpr vec<1, T, Q>::vec(vec<3, U, P> const& v) : x(static_cast<T>(v.x))
	{
	}

	template <typename T, qualifier Q>
	template <typename U, qualifier P>
	constexpr vec<1, T, Q>::vec(vec<4, U, P> const& v) : x(static_cast<T>(v.x))
	{
	}

	// Assignment Operators

	template <typename T, qualifier Q>
	constexpr vec<1, T, Q>& vec<1, T, Q>::operator=(T scalar)
	{
		this->x = scalar;
		return *this;
	}

	template <typename T, qualifier Q>
	constexpr vec<1, T, Q>& vec<1, T, Q>::operator=(vec const& v)
	{
		this->x = v.x;
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<1, T, Q>& vec<1, T, Q>::operator=(vec<1, U, Q> const& v)
	{
		this->x = static_cast<T>(v.x);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<1, T, Q>& vec<1, T, Q>::operator=(vec<2, U, Q> const& v)
	{
		this->x = static_cast<T>(v.x);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<1, T, Q>& vec<1, T, Q>::operator=(vec<3, U, Q> const& v)
	{
		this->x = static_cast<T>(v.x);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<1, T, Q>& vec<1, T, Q>::operator=(vec<4, U, Q> const& v)
	{
		this->x = static_cast<T>(v.x);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<1, T, Q>& vec<1, T, Q>::operator+=(U scalar)
	{
		this->x += static_cast<T>(scalar);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<1, T, Q>& vec<1, T, Q>::operator+=(vec<1, U, Q> const& v)
	{
		this->x += static_cast<T>(v.x);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<1, T, Q>& vec<1, T, Q>::operator+=(vec<2, U, Q> const& v)
	{
		this->x += static_cast<T>(v.x);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<1, T, Q>& vec<1, T, Q>::operator+=(vec<3, U, Q> const& v)
	{
		this->x += static_cast<T>(v.x);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<1, T, Q>& vec<1, T, Q>::operator+=(vec<4, U, Q> const& v)
	{
		this->x += static_cast<T>(v.x);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<1, T, Q>& vec<1, T, Q>::operator-=(U scalar)
	{
		this->x -= static_cast<T>(scalar);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<1, T, Q>& vec<1, T, Q>::operator-=(vec<1, U, Q> const& v)
	{
		this->x -= static_cast<T>(v.x);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<1, T, Q>& vec<1, T, Q>::operator-=(vec<2, U, Q> const& v)
	{
		this->x -= static_cast<T>(v.x);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<1, T, Q>& vec<1, T, Q>::operator-=(vec<3, U, Q> const& v)
	{
		this->x -= static_cast<T>(v.x);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<1, T, Q>& vec<1, T, Q>::operator-=(vec<4, U, Q> const& v)
	{
		this->x -= static_cast<T>(v.x);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<1, T, Q>& vec<1, T, Q>::operator*=(U scalar)
	{
		this->x *= static_cast<T>(scalar);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<1, T, Q>& vec<1, T, Q>::operator*=(vec<1, U, Q> const& v)
	{
		this->x *= static_cast<T>(v.x);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<1, T, Q>& vec<1, T, Q>::operator*=(vec<2, U, Q> const& v)
	{
		this->x *= static_cast<T>(v.x);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<1, T, Q>& vec<1, T, Q>::operator*=(vec<3, U, Q> const& v)
	{
		this->x *= static_cast<T>(v.x);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<1, T, Q>& vec<1, T, Q>::operator*=(vec<4, U, Q> const& v)
	{
		this->x *= static_cast<T>(v.x);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<1, T, Q>& vec<1, T, Q>::operator/=(U scalar)
	{
		this->x /= static_cast<T>(scalar);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<1, T, Q>& vec<1, T, Q>::operator/=(vec<1, U, Q> const& v)
	{
		this->x /= static_cast<T>(v.x);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<1, T, Q>& vec<1, T, Q>::operator/=(vec<2, U, Q> const& v)
	{
		this->x /= static_cast<T>(v.x);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<1, T, Q>& vec<1, T, Q>::operator/=(vec<3, U, Q> const& v)
	{
		this->x /= static_cast<T>(v.x);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<1, T, Q>& vec<1, T, Q>::operator/=(vec<4, U, Q> const& v)
	{

		this->x /= static_cast<T>(v.x);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<1, T, Q>& vec<1, T, Q>::operator%=(U scalar)
	{
		static_assert(std::is_integral<T>::value, "Cannot perform modulo operation on non-integral type.");
		this->x %= static_cast<T>(scalar);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<1, T, Q>& vec<1, T, Q>::operator%=(vec<1, U, Q> const& v)
	{
		static_assert(std::is_integral<T>::value, "Cannot perform modulo operation on non-integral type.");
		this->x %= static_cast<T>(v.x);
		return *this;
	}

	/// Increment and Decrement Operators

	template <typename T, qualifier Q>
	constexpr vec<1, T, Q>& vec<1, T, Q>::operator++()
	{
		++this->x;
		return *this;
	}

	template <typename T, qualifier Q>
	constexpr vec<1, T, Q>& vec<1, T, Q>::operator--()
	{
		--this->x;
		return *this;
	}

	template <typename T, qualifier Q>
	constexpr const vec<1, T, Q> vec<1, T, Q>::operator++(int)
	{
		vec<1, T, Q> result(*this);
		++*this;
		return result;
	}

	template <typename T, qualifier Q>
	constexpr const vec<1, T, Q> vec<1, T, Q>::operator--(int)
	{
		vec<1, T, Q> result(*this);
		--*this;
		return result;
	}

	/// Bitwise Assignment Operators

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<1, T, Q>& vec<1, T, Q>::operator&=(U scalar)
	{

		this->x &= static_cast<T>(scalar);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<1, T, Q>& vec<1, T, Q>::operator&=(vec<1, U, Q> const& v)
	{
		this->x &= static_cast<T>(v.x);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<1, T, Q>& vec<1, T, Q>::operator|=(U scalar)
	{
		this->x |= static_cast<T>(scalar);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<1, T, Q>& vec<1, T, Q>::operator|=(vec<1, U, Q> const& v)
	{
		this->x |= static_cast<T>(v.x);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<1, T, Q>& vec<1, T, Q>::operator^=(U scalar)
	{
		this->x ^= static_cast<T>(scalar);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<1, T, Q>& vec<1, T, Q>::operator^=(vec<1, U, Q> const& v)
	{
		this->x ^= static_cast<T>(v.x);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<1, T, Q>& vec<1, T, Q>::operator<<=(U scalar)
	{
		this->x <<= static_cast<T>(scalar);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<1, T, Q>& vec<1, T, Q>::operator<<=(vec<1, U, Q> const& v)
	{
		this->x <<= static_cast<T>(v.x);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<1, T, Q>& vec<1, T, Q>::operator>>=(U scalar)
	{
		this->x >>= static_cast<T>(scalar);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<1, T, Q>& vec<1, T, Q>::operator>>=(vec<1, U, Q> const& v)
	{
		this->x >>= static_cast<T>(v.x);
		return *this;
	}

	// Unary Operators

	template <typename T, qualifier Q>
	constexpr vec<1, T, Q> operator+(vec<1, T, Q> const& v)
	{
		return v;
	}

	template <typename T, qualifier Q>
	constexpr vec<1, T, Q> operator-(vec<1, T, Q> const& v)
	{
		return vec<1, T, Q>(-v.x);
	}

	template <typename T, qualifier Q>
	constexpr vec<1, T, Q> operator+(vec<1, T, Q> const& v, T scalar)
	{
		return vec<1, T, Q>(v.x + scalar);
	}

	template <typename T, qualifier Q>
	constexpr vec<1, T, Q> operator+(T scalar, vec<1, T, Q> const& v)
	{
		return vec<1, T, Q>(scalar + v.x);
	}

	template <typename T, qualifier Q>
	constexpr vec<1, T, Q> operator+(vec<1, T, Q> const& v1, vec<1, T, Q> const& v2)
	{
		return vec<1, T, Q>(v1.x + v2.x);
	}

	template <typename T, qualifier Q>
	constexpr vec<1, T, Q> operator-(vec<1, T, Q> const& v, T scalar)
	{
		return vec<1, T, Q>(v.x - scalar);
	}

	template <typename T, qualifier Q>
	constexpr vec<1, T, Q> operator-(T scalar, vec<1, T, Q> const& v)
	{
		return vec<1, T, Q>(scalar - v.x);
	}

	template <typename T, qualifier Q>
	constexpr vec<1, T, Q> operator-(vec<1, T, Q> const& v1, vec<1, T, Q> const& v2)
	{
		return vec<1, T, Q>(v1.x - v2.x);
	}

	template <typename T, qualifier Q>
	constexpr vec<1, T, Q> operator*(vec<1, T, Q> const& v, T scalar)
	{
		return vec<1, T, Q>(v.x * scalar);
	}

	template <typename T, qualifier Q>
	constexpr vec<1, T, Q> operator*(T scalar, vec<1, T, Q> const& v)
	{
		return vec<1, T, Q>(scalar * v.x);
	}

	template <typename T, qualifier Q>
	constexpr vec<1, T, Q> operator*(vec<1, T, Q> const& v1, vec<1, T, Q> const& v2)
	{
		return vec<1, T, Q>(v1.x * v2.x);
	}

	template <qualifier Q>
	constexpr vec<1, bool, Q> operator*(vec<1, bool, Q> const& v1, vec<1, bool, Q> const& v2)
	{
		return vec<1, bool, Q>(v1.x && v2.x);
	}

	template <typename T, qualifier Q>
	constexpr vec<1, T, Q> operator/(vec<1, T, Q> const& v, T scalar)
	{
		return vec<1, T, Q>(v.x / scalar);
	}

	template <typename T, qualifier Q>
	constexpr vec<1, T, Q> operator/(T scalar, vec<1, T, Q> const& v)
	{
		return vec<1, T, Q>(scalar / v.x);
	}

	template <typename T, qualifier Q>
	constexpr vec<1, T, Q> operator/(vec<1, T, Q> const& v1, vec<1, T, Q> const& v2)
	{
		return vec<1, T, Q>(v1.x / v2.x);
	}

	template <typename T, qualifier Q>
	constexpr vec<1, T, Q> operator%(vec<1, T, Q> const& v, T scalar)
	{
		return vec<1, T, Q>(v.x % scalar);
	}

	template <typename T, qualifier Q>
	constexpr vec<1, T, Q> operator%(T scalar, vec<1, T, Q> const& v)
	{
		return vec<1, T, Q>(scalar % v.x);
	}

	template <typename T, qualifier Q>
	constexpr vec<1, T, Q> operator%(vec<1, T, Q> const& v1, vec<1, T, Q> const& v2)
	{
		return vec<1, T, Q>(v1.x % v2.x);
	}

	/// Bitwise Binary Operators

	template <typename T, qualifier Q>
	constexpr vec<1, T, Q> operator&(vec<1, T, Q> const& v, T scalar)
	{
		return vec<1, T, Q>(v.x & scalar);
	}

	template <typename T, qualifier Q>
	constexpr vec<1, T, Q> operator&(T scalar, vec<1, T, Q> const& v)
	{
		return vec<1, T, Q>(scalar & v.x);
	}

	template <typename T, qualifier Q>
	constexpr vec<1, T, Q> operator&(vec<1, T, Q> const& v1, vec<1, T, Q> const& v2)
	{
		return vec<1, T, Q>(v1.x & v2.x);
	}

	template <typename T, qualifier Q>
	constexpr vec<1, T, Q> operator|(vec<1, T, Q> const& v, T scalar)
	{
		return vec<1, T, Q>(v.x | scalar);
	}

	template <typename T, qualifier Q>
	constexpr vec<1, T, Q> operator|(T scalar, vec<1, T, Q> const& v)
	{
		return vec<1, T, Q>(scalar | v.x);
	}

	template <typename T, qualifier Q>
	constexpr vec<1, T, Q> operator|(vec<1, T, Q> const& v1, vec<1, T, Q> const& v2)
	{
		return vec<1, T, Q>(v1.x | v2.x);
	}

	template <typename T, qualifier Q>
	constexpr vec<1, T, Q> operator^(vec<1, T, Q> const& v, T scalar)
	{
		return vec<1, T, Q>(v.x ^ scalar);
	}

	template <typename T, qualifier Q>
	constexpr vec<1, T, Q> operator^(T scalar, vec<1, T, Q> const& v)
	{
		return vec<1, T, Q>(scalar ^ v.x);
	}

	template <typename T, qualifier Q>
	constexpr vec<1, T, Q> operator^(vec<1, T, Q> const& v1, vec<1, T, Q> const& v2)
	{
		return vec<1, T, Q>(v1.x ^ v2.x);
	}

	template <typename T, qualifier Q>
	constexpr vec<1, T, Q> operator<<(vec<1, T, Q> const& v, T scalar)
	{
		return vec<1, T, Q>(v.x << scalar);
	}

	template <typename T, qualifier Q>
	constexpr vec<1, T, Q> operator<<(T scalar, vec<1, T, Q> const& v)
	{
		return vec<1, T, Q>(scalar << v.x);
	}

	template <typename T, qualifier Q>
	constexpr vec<1, T, Q> operator<<(vec<1, T, Q> const& v1, vec<1, T, Q> const& v2)
	{
		return vec<1, T, Q>(v1.x << v2.x);
	}

	template <typename T, qualifier Q>
	constexpr vec<1, T, Q> operator>>(vec<1, T, Q> const& v, T scalar)
	{
		return vec<1, T, Q>(v.x >> scalar);
	}

	template <typename T, qualifier Q>
	constexpr vec<1, T, Q> operator>>(T scalar, vec<1, T, Q> const& v)
	{
		return vec<1, T, Q>(scalar >> v.x);
	}

	template <typename T, qualifier Q>
	constexpr vec<1, T, Q> operator>>(vec<1, T, Q> const& v1, vec<1, T, Q> const& v2)
	{
		return vec<1, T, Q>(v1.x >> v2.x);
	}

	template <typename T, qualifier Q>
	constexpr vec<1, T, Q> operator~(vec<1, T, Q> const& v)
	{
		return vec<1, T, Q>(~v.x);
	}

	/// Comparison Operators

	template <typename T, qualifier Q>
	constexpr bool operator==(vec<1, T, Q> const& v1, vec<1, T, Q> const& v2)
	{
		return detail::Equal<T, Q, std::numeric_limits<T>::is_iec559, sizeof(T) * 2, detail::IsAligned<Q>::value>::compute(v1, v2);
	}

	template <typename T, qualifier Q>
	constexpr bool operator!=(vec<1, T, Q> const& v1, vec<1, T, Q> const& v2)
	{
		return !(v1 == v2);
	}

	template <qualifier Q>
	constexpr bool operator&&(vec<1, bool, Q> const& v1, vec<1, bool, Q> const& v2)
	{
		return (v1.x && v2.x);
	}

	template <qualifier Q>
	constexpr bool operator||(vec<1, bool, Q> const& v1, vec<1, bool, Q> const& v2)
	{
		return (v1.x || v2.x);
	}

} // namespace mim

