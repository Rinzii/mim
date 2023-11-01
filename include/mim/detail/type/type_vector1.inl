// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#include <type_traits>

namespace mim
{

	// Element Accessors

	template <typename T>
	constexpr T& vec<1, T>::operator[](typename vec<1, T>::size_type)
	{
		return x;
	}

	template <typename T>
	constexpr const T& vec<1, T>::operator[](typename vec<1, T>::size_type) const
	{
		return x;
	}

	template <typename T>
	T& vec<1, T>::at(typename vec<1, T>::size_type i)
	{
		static_assert(i < this->size(), "vec<1, T>::at() : Index out of range.");

		return x;
	}

	template <typename T>
	const T& vec<1, T>::at(typename vec<1, T>::size_type i) const
	{
		static_assert(i < size(), "vec<1, T>::at() : Index out of range.");

		return x;
	}

	/// Constructors

	template <typename T>
	constexpr vec<1, T>::vec() : x(0)
	{
	}

	template <typename T>
	constexpr vec<1, T>::vec(vec<1, T> const& v) : x(v.x)
	{
	}

	template <typename T>
	constexpr vec<1, T>::vec(T scalar) : x(scalar)
	{
	}

	/// Template Constructors

	// U Constructors

	template <typename T>
	template <typename U>
	constexpr vec<1, T>::vec(U scalar) : x(static_cast<T>(scalar))
	{
	}

	template <typename T>
	template <typename U>
	constexpr vec<1, T>::vec(vec<1, U> const& v) : x(static_cast<T>(v.x))
	{
	}

	template <typename T>
	template <typename U>
	constexpr vec<1, T>::vec(vec<2, U> const& v) : x(static_cast<T>(v.x))
	{
	}

	template <typename T>
	template <typename U>
	constexpr vec<1, T>::vec(vec<3, U> const& v) : x(static_cast<T>(v.x))
	{
	}

	template <typename T>
	template <typename U>
	constexpr vec<1, T>::vec(vec<4, U> const& v) : x(static_cast<T>(v.x))
	{
	}

	// Assignment Operators

	template <typename T>
	constexpr vec<1, T>& vec<1, T>::operator=(T scalar)
	{
		this->x = scalar;
		return *this;
	}

	template <typename T>
	constexpr vec<1, T>& vec<1, T>::operator=(vec const& v)
	{
		this->x = v.x;
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<1, T>& vec<1, T>::operator=(vec<1, U> const& v)
	{
		this->x = static_cast<T>(v.x);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<1, T>& vec<1, T>::operator=(vec<2, U> const& v)
	{
		this->x = static_cast<T>(v.x);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<1, T>& vec<1, T>::operator=(vec<3, U> const& v)
	{
		this->x = static_cast<T>(v.x);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<1, T>& vec<1, T>::operator=(vec<4, U> const& v)
	{
		this->x = static_cast<T>(v.x);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<1, T>& vec<1, T>::operator+=(U scalar)
	{
		this->x += static_cast<T>(scalar);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<1, T>& vec<1, T>::operator+=(vec<1, U> const& v)
	{
		this->x += static_cast<T>(v.x);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<1, T>& vec<1, T>::operator+=(vec<2, U> const& v)
	{
		this->x += static_cast<T>(v.x);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<1, T>& vec<1, T>::operator+=(vec<3, U> const& v)
	{
		this->x += static_cast<T>(v.x);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<1, T>& vec<1, T>::operator+=(vec<4, U> const& v)
	{
		this->x += static_cast<T>(v.x);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<1, T>& vec<1, T>::operator-=(U scalar)
	{
		this->x -= static_cast<T>(scalar);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<1, T>& vec<1, T>::operator-=(vec<1, U> const& v)
	{
		this->x -= static_cast<T>(v.x);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<1, T>& vec<1, T>::operator-=(vec<2, U> const& v)
	{
		this->x -= static_cast<T>(v.x);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<1, T>& vec<1, T>::operator-=(vec<3, U> const& v)
	{
		this->x -= static_cast<T>(v.x);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<1, T>& vec<1, T>::operator-=(vec<4, U> const& v)
	{
		this->x -= static_cast<T>(v.x);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<1, T>& vec<1, T>::operator*=(U scalar)
	{
		this->x *= static_cast<T>(scalar);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<1, T>& vec<1, T>::operator*=(vec<1, U> const& v)
	{
		this->x *= static_cast<T>(v.x);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<1, T>& vec<1, T>::operator*=(vec<2, U> const& v)
	{
		this->x *= static_cast<T>(v.x);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<1, T>& vec<1, T>::operator*=(vec<3, U> const& v)
	{
		this->x *= static_cast<T>(v.x);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<1, T>& vec<1, T>::operator*=(vec<4, U> const& v)
	{
		this->x *= static_cast<T>(v.x);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<1, T>& vec<1, T>::operator/=(U scalar)
	{
		this->x /= static_cast<T>(scalar);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<1, T>& vec<1, T>::operator/=(vec<1, U> const& v)
	{
		this->x /= static_cast<T>(v.x);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<1, T>& vec<1, T>::operator/=(vec<2, U> const& v)
	{
		this->x /= static_cast<T>(v.x);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<1, T>& vec<1, T>::operator/=(vec<3, U> const& v)
	{
		this->x /= static_cast<T>(v.x);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<1, T>& vec<1, T>::operator/=(vec<4, U> const& v)
	{

		this->x /= static_cast<T>(v.x);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<1, T>& vec<1, T>::operator%=(U scalar)
	{
		static_assert(std::is_integral<T>::value, "Cannot perform modulo operation on non-integral type.");
		this->x %= static_cast<T>(scalar);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<1, T>& vec<1, T>::operator%=(vec<1, U> const& v)
	{
		static_assert(std::is_integral<T>::value, "Cannot perform modulo operation on non-integral type.");
		this->x %= static_cast<T>(v.x);
		return *this;
	}

	/// Increment and Decrement Operators

	template <typename T>
	constexpr vec<1, T>& vec<1, T>::operator++()
	{
		++this->x;
		return *this;
	}

	template <typename T>
	constexpr vec<1, T>& vec<1, T>::operator--()
	{
		--this->x;
		return *this;
	}

	template <typename T>
	constexpr const vec<1, T> vec<1, T>::operator++(int)
	{
		vec<1, T> result(*this);
		++*this;
		return result;
	}

	template <typename T>
	constexpr const vec<1, T> vec<1, T>::operator--(int)
	{
		vec<1, T> result(*this);
		--*this;
		return result;
	}

	/// Bitwise Assignment Operators

	template <typename T>
	template <typename U>
	constexpr vec<1, T>& vec<1, T>::operator&=(U scalar)
	{

		this->x &= static_cast<T>(scalar);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<1, T>& vec<1, T>::operator&=(vec<1, U> const& v)
	{
		this->x &= static_cast<T>(v.x);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<1, T>& vec<1, T>::operator|=(U scalar)
	{
		this->x |= static_cast<T>(scalar);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<1, T>& vec<1, T>::operator|=(vec<1, U> const& v)
	{
		this->x |= static_cast<T>(v.x);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<1, T>& vec<1, T>::operator^=(U scalar)
	{
		this->x ^= static_cast<T>(scalar);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<1, T>& vec<1, T>::operator^=(vec<1, U> const& v)
	{
		this->x ^= static_cast<T>(v.x);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<1, T>& vec<1, T>::operator<<=(U scalar)
	{
		this->x <<= static_cast<T>(scalar);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<1, T>& vec<1, T>::operator<<=(vec<1, U> const& v)
	{
		this->x <<= static_cast<T>(v.x);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<1, T>& vec<1, T>::operator>>=(U scalar)
	{
		this->x >>= static_cast<T>(scalar);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<1, T>& vec<1, T>::operator>>=(vec<1, U> const& v)
	{
		this->x >>= static_cast<T>(v.x);
		return *this;
	}

	// Unary Operators

	template <typename T>
	constexpr vec<1, T> operator+(vec<1, T> const& v)
	{
		return v;
	}

	template <typename T>
	constexpr vec<1, T> operator-(vec<1, T> const& v)
	{
		return vec<1, T>(-v.x);
	}

	template <typename T>
	constexpr vec<1, T> operator+(vec<1, T> const& v, T scalar)
	{
		return vec<1, T>(v.x + scalar);
	}

	template <typename T>
	constexpr vec<1, T> operator+(T scalar, vec<1, T> const& v)
	{
		return vec<1, T>(scalar + v.x);
	}

	template <typename T>
	constexpr vec<1, T> operator+(vec<1, T> const& v1, vec<1, T> const& v2)
	{
		return vec<1, T>(v1.x + v2.x);
	}

	template <typename T>
	constexpr vec<1, T> operator-(vec<1, T> const& v, T scalar)
	{
		return vec<1, T>(v.x - scalar);
	}

	template <typename T>
	constexpr vec<1, T> operator-(T scalar, vec<1, T> const& v)
	{
		return vec<1, T>(scalar - v.x);
	}

	template <typename T>
	constexpr vec<1, T> operator-(vec<1, T> const& v1, vec<1, T> const& v2)
	{
		return vec<1, T>(v1.x - v2.x);
	}

	template <typename T>
	constexpr vec<1, T> operator*(vec<1, T> const& v, T scalar)
	{
		return vec<1, T>(v.x * scalar);
	}

	template <typename T>
	constexpr vec<1, T> operator*(T scalar, vec<1, T> const& v)
	{
		return vec<1, T>(scalar * v.x);
	}

	template <typename T>
	constexpr vec<1, T> operator*(vec<1, T> const& v1, vec<1, T> const& v2)
	{
		return vec<1, T>(v1.x * v2.x);
	}

	template <>
	constexpr vec<1, bool> operator*(vec<1, bool> const& v1, vec<1, bool> const& v2)
	{
		return vec<1, bool>(v1.x && v2.x);
	}

	template <typename T>
	constexpr vec<1, T> operator/(vec<1, T> const& v, T scalar)
	{
		return vec<1, T>(v.x / scalar);
	}

	template <typename T>
	constexpr vec<1, T> operator/(T scalar, vec<1, T> const& v)
	{
		return vec<1, T>(scalar / v.x);
	}

	template <typename T>
	constexpr vec<1, T> operator/(vec<1, T> const& v1, vec<1, T> const& v2)
	{
		return vec<1, T>(v1.x / v2.x);
	}

	template <typename T>
	constexpr vec<1, T> operator%(vec<1, T> const& v, T scalar)
	{
		return vec<1, T>(v.x % scalar);
	}

	template <typename T>
	constexpr vec<1, T> operator%(T scalar, vec<1, T> const& v)
	{
		return vec<1, T>(scalar % v.x);
	}

	template <typename T>
	constexpr vec<1, T> operator%(vec<1, T> const& v1, vec<1, T> const& v2)
	{
		return vec<1, T>(v1.x % v2.x);
	}

	/// Bitwise Binary Operators

	template <typename T>
	constexpr vec<1, T> operator&(vec<1, T> const& v, T scalar)
	{
		return vec<1, T>(v.x & scalar);
	}

	template <typename T>
	constexpr vec<1, T> operator&(T scalar, vec<1, T> const& v)
	{
		return vec<1, T>(scalar & v.x);
	}

	template <typename T>
	constexpr vec<1, T> operator&(vec<1, T> const& v1, vec<1, T> const& v2)
	{
		return vec<1, T>(v1.x & v2.x);
	}

	template <typename T>
	constexpr vec<1, T> operator|(vec<1, T> const& v, T scalar)
	{
		return vec<1, T>(v.x | scalar);
	}

	template <typename T>
	constexpr vec<1, T> operator|(T scalar, vec<1, T> const& v)
	{
		return vec<1, T>(scalar | v.x);
	}

	template <typename T>
	constexpr vec<1, T> operator|(vec<1, T> const& v1, vec<1, T> const& v2)
	{
		return vec<1, T>(v1.x | v2.x);
	}

	template <typename T>
	constexpr vec<1, T> operator^(vec<1, T> const& v, T scalar)
	{
		return vec<1, T>(v.x ^ scalar);
	}

	template <typename T>
	constexpr vec<1, T> operator^(T scalar, vec<1, T> const& v)
	{
		return vec<1, T>(scalar ^ v.x);
	}

	template <typename T>
	constexpr vec<1, T> operator^(vec<1, T> const& v1, vec<1, T> const& v2)
	{
		return vec<1, T>(v1.x ^ v2.x);
	}

	template <typename T>
	constexpr vec<1, T> operator<<(vec<1, T> const& v, T scalar)
	{
		return vec<1, T>(v.x << scalar);
	}

	template <typename T>
	constexpr vec<1, T> operator<<(T scalar, vec<1, T> const& v)
	{
		return vec<1, T>(scalar << v.x);
	}

	template <typename T>
	constexpr vec<1, T> operator<<(vec<1, T> const& v1, vec<1, T> const& v2)
	{
		return vec<1, T>(v1.x << v2.x);
	}

	template <typename T>
	constexpr vec<1, T> operator>>(vec<1, T> const& v, T scalar)
	{
		return vec<1, T>(v.x >> scalar);
	}

	template <typename T>
	constexpr vec<1, T> operator>>(T scalar, vec<1, T> const& v)
	{
		return vec<1, T>(scalar >> v.x);
	}

	template <typename T>
	constexpr vec<1, T> operator>>(vec<1, T> const& v1, vec<1, T> const& v2)
	{
		return vec<1, T>(v1.x >> v2.x);
	}

	template <typename T>
	constexpr vec<1, T> operator~(vec<1, T> const& v)
	{
		return vec<1, T>(~v.x);
	}

	/// Comparison Operators

	template <typename T>
	constexpr bool operator==(vec<1, T> const& v1, vec<1, T> const& v2)
	{
		return (v1.x == v2.x);
	}

	template <typename T>
	constexpr bool operator!=(vec<1, T> const& v1, vec<1, T> const& v2)
	{
		return !(v1 == v2);
	}

	constexpr vec<1, bool> operator&&(vec<1, bool> const& v1, vec<1, bool> const& v2)
	{
		return vec<1, bool>(v1.x && v2.x);
	}

	constexpr vec<1, bool> operator||(vec<1, bool> const& v1, vec<1, bool> const& v2)
	{
		return vec<1, bool>(v1.x || v2.x);
	}

} // namespace mim

