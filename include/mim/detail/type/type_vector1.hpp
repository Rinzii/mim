// Copyright (c) 2023-Present Mim contributors (see LICENSE)

/// \ref core
/// \file mim/detail/type/type_vector1.hpp

#pragma once

#include <iostream>

#include "mim/detail/qualifier.hpp"

namespace mim
{
template <typename T, qualifier Q>
struct VectorT<1, T, Q>
{
	// Aliases

	using value_type = T;
	using type = VectorT<1, T, Q>;
	using size_type = size_t;
	static constexpr auto size_v = 1;


	// Data

	union {
		struct { T x; };

		typename detail::Storage<1, T, detail::IsAligned<Q>::value>::type data;
	};


	// Element Accessors

	static constexpr std::size_t size() { return size_v; }

	constexpr T& operator[](std::size_t i);

	constexpr const T& operator[](std::size_t i) const;

	T& at(std::size_t i);

	const T& at(std::size_t i) const;


	// Much of this code uses as reference section 5.4.1 of the GLSL 1.30.08 specification

	// Constructors

	constexpr VectorT();

	constexpr VectorT(VectorT const& v);

	constexpr explicit VectorT(T scalar);

	template <qualifier P>
	constexpr explicit VectorT(VectorT<1, T, P> const& v);

	template <typename U, qualifier P>
	constexpr explicit VectorT(VectorT<1, U, P> const& v);

	template <typename U, qualifier P>
	constexpr explicit VectorT(VectorT<2, U, P> const& v);

	template <typename U, qualifier P>
	constexpr explicit VectorT(VectorT<3, U, P> const& v);

	template <typename U, qualifier P>
	constexpr explicit VectorT(VectorT<4, U, P> const& v);


	// Assignment Operators

	constexpr VectorT<1, T, Q>& operator=(T scalar);

	constexpr VectorT<1, T, Q>& operator=(VectorT const& v);

	template <typename U>
	constexpr VectorT<1, T, Q>& operator=(VectorT<1, U, Q> const& v);

	template <typename U>
	constexpr VectorT<1, T, Q>& operator=(VectorT<2, U, Q> const& v);

	template <typename U>
	constexpr VectorT<1, T, Q>& operator=(VectorT<3, U, Q> const& v);

	template <typename U>
	constexpr VectorT<1, T, Q>& operator=(VectorT<4, U, Q> const& v);

	template <typename U>
	constexpr VectorT<1, T, Q>& operator+=(U scalar);

	template <typename U>
	constexpr VectorT<1, T, Q>& operator+=(VectorT<1, U, Q> const& v);

	template <typename U>
	constexpr VectorT<1, T, Q>& operator+=(VectorT<2, U, Q> const& v);

	template <typename U>
	constexpr VectorT<1, T, Q>& operator+=(VectorT<3, U, Q> const& v);

	template <typename U>
	constexpr VectorT<1, T, Q>& operator+=(VectorT<4, U, Q> const& v);

	template <typename U>
	constexpr VectorT<1, T, Q>& operator-=(U scalar);

	template <typename U>
	constexpr VectorT<1, T, Q>& operator-=(VectorT<1, U, Q> const& v);


	template <typename U>
	constexpr VectorT<1, T, Q>& operator-=(VectorT<2, U, Q> const& v);


	template <typename U>
	constexpr VectorT<1, T, Q>& operator-=(VectorT<3, U, Q> const& v);


	template <typename U>
	constexpr VectorT<1, T, Q>& operator-=(VectorT<4, U, Q> const& v);

	template <typename U>
	constexpr VectorT<1, T, Q>& operator*=(U scalar);

	template <typename U>
	constexpr VectorT<1, T, Q>& operator*=(VectorT<1, U, Q> const& v);

	template <typename U>
	constexpr VectorT<1, T, Q>& operator*=(VectorT<2, U, Q> const& v);

	template <typename U>
	constexpr VectorT<1, T, Q>& operator*=(VectorT<3, U, Q> const& v);

	template <typename U>
	constexpr VectorT<1, T, Q>& operator*=(VectorT<4, U, Q> const& v);

	template <typename U>
	constexpr VectorT<1, T, Q>& operator/=(U scalar);

	template <typename U>
	constexpr VectorT<1, T, Q>& operator/=(VectorT<1, U, Q> const& v);

	template <typename U>
	constexpr VectorT<1, T, Q>& operator/=(VectorT<2, U, Q> const& v);

	template <typename U>
	constexpr VectorT<1, T, Q>& operator/=(VectorT<3, U, Q> const& v);

	template <typename U>
	constexpr VectorT<1, T, Q>& operator/=(VectorT<4, U, Q> const& v);


	// Increment and Decrement Operators

	constexpr VectorT<1, T, Q>& operator++();

	constexpr VectorT<1, T, Q>& operator--();

	constexpr const VectorT<1, T, Q> operator++(int);

	constexpr const VectorT<1, T, Q> operator--(int);


	// Bitwise Assignment Operators

	template <typename U>
	constexpr VectorT<1, T, Q>& operator%=(U scalar);

	template <typename U>
	constexpr VectorT<1, T, Q>& operator%=(VectorT<1, U, Q> const& v);

	template <typename U>
	constexpr VectorT<1, T, Q>& operator&=(U scalar);

	template <typename U>
	constexpr VectorT<1, T, Q>& operator&=(VectorT<1, U, Q> const& v);

	template <typename U>
	constexpr VectorT<1, T, Q>& operator|=(U scalar);

	template <typename U>
	constexpr VectorT<1, T, Q>& operator|=(VectorT<1, U, Q> const& v);

	template <typename U>
	constexpr VectorT<1, T, Q>& operator^=(U scalar);

	template <typename U>
	constexpr VectorT<1, T, Q>& operator^=(VectorT<1, U, Q> const& v);

	template <typename U>
	constexpr VectorT<1, T, Q>& operator<<=(U scalar);

	template <typename U>
	constexpr VectorT<1, T, Q>& operator<<=(VectorT<1, U, Q> const& v);

	template <typename U>
	constexpr VectorT<1, T, Q>& operator>>=(U scalar);

	template <typename U>
	constexpr VectorT<1, T, Q>& operator>>=(VectorT<1, U, Q> const& v);


	// Stream Operators

	friend std::ostream& operator<<(std::ostream& os, VectorT<1, T, Q> const& v)
	{
		return os << "(" << v.x << ")";
	}

};

// TODO: Implement Unary Operators for vec2-4

// Unary Operators

template <typename T, qualifier Q>
constexpr VectorT<1, T, Q> operator+(VectorT<1, T, Q> const& v);

template <typename T, qualifier Q>
constexpr VectorT<1, T, Q> operator-(VectorT<1, T, Q> const& v);

template <typename T, qualifier Q>
constexpr VectorT<1, T, Q> operator+(VectorT<1, T, Q> const& v, T scalar);

template <typename T, qualifier Q>
constexpr VectorT<1, T, Q> operator+(T scalar, VectorT<1, T, Q> const& v);

template <typename T, qualifier Q>
constexpr VectorT<1, T, Q> operator+(VectorT<1, T, Q> const& v1, VectorT<1, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr VectorT<1, T, Q> operator-(VectorT<1, T, Q> const& v, T scalar);

template <typename T, qualifier Q>
constexpr VectorT<1, T, Q> operator-(T scalar, VectorT<1, T, Q> const& v);

template <typename T, qualifier Q>
constexpr VectorT<1, T, Q> operator-(VectorT<1, T, Q> const& v1, VectorT<1, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr VectorT<1, T, Q> operator*(VectorT<1, T, Q> const& v, T scalar);

template <typename T, qualifier Q>
constexpr VectorT<1, T, Q> operator*(T scalar, VectorT<1, T, Q> const& v);

template <typename T, qualifier Q>
constexpr VectorT<1, T, Q> operator*(VectorT<1, T, Q> const& v1, VectorT<1, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr VectorT<1, T, Q> operator/(VectorT<1, T, Q> const& v, T scalar);

template <typename T, qualifier Q>
constexpr VectorT<1, T, Q> operator/(T scalar, VectorT<1, T, Q> const& v);

template <typename T, qualifier Q>
constexpr VectorT<1, T, Q> operator/(VectorT<1, T, Q> const& v1, VectorT<1, T, Q> const& v2);


// Bitwise Operators

template <typename T, qualifier Q>
constexpr VectorT<1, T, Q> operator%(VectorT<1, T, Q> const& v, T scalar);

template <typename T, qualifier Q>
constexpr VectorT<1, T, Q> operator%(T scalar, VectorT<1, T, Q> const& v);

template <typename T, qualifier Q>
constexpr VectorT<1, T, Q> operator%(VectorT<1, T, Q> const& v1, VectorT<1, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr VectorT<1, T, Q> operator&(VectorT<1, T, Q> const& v, T scalar);

template <typename T, qualifier Q>
constexpr VectorT<1, T, Q> operator&(T scalar, VectorT<1, T, Q> const& v);

template <typename T, qualifier Q>
constexpr VectorT<1, T, Q> operator&(VectorT<1, T, Q> const& v1, VectorT<1, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr VectorT<1, T, Q> operator|(VectorT<1, T, Q> const& v, T scalar);

template <typename T, qualifier Q>
constexpr VectorT<1, T, Q> operator|(T scalar, VectorT<1, T, Q> const& v);

template <typename T, qualifier Q>
constexpr VectorT<1, T, Q> operator|(VectorT<1, T, Q> const& v1, VectorT<1, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr VectorT<1, T, Q> operator^(VectorT<1, T, Q> const& v, T scalar);

template <typename T, qualifier Q>
constexpr VectorT<1, T, Q> operator^(T scalar, VectorT<1, T, Q> const& v);

template <typename T, qualifier Q>
constexpr VectorT<1, T, Q> operator^(VectorT<1, T, Q> const& v1, VectorT<1, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr VectorT<1, T, Q> operator<<(VectorT<1, T, Q> const& v, T scalar);

template <typename T, qualifier Q>
constexpr VectorT<1, T, Q> operator<<(T scalar, VectorT<1, T, Q> const& v);

template <typename T, qualifier Q>
constexpr VectorT<1, T, Q> operator<<(VectorT<1, T, Q> const& v1, VectorT<1, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr VectorT<1, T, Q> operator>>(VectorT<1, T, Q> const& v, T scalar);

template <typename T, qualifier Q>
constexpr VectorT<1, T, Q> operator>>(T scalar, VectorT<1, T, Q> const& v);

template <typename T, qualifier Q>
constexpr VectorT<1, T, Q> operator>>(VectorT<1, T, Q> const& v1, VectorT<1, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr VectorT<1, T, Q> operator~(VectorT<1, T, Q> const& v);


// Comparison Operators

template <typename T, qualifier Q>
constexpr bool operator==(VectorT<1, T, Q> const& v1, VectorT<1, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr bool operator!=(VectorT<1, T, Q> const& v1, VectorT<1, T, Q> const& v2);

// TODO: These two operators are not working currently and need to be fixed.

template <qualifier Q>
constexpr bool operator&&(VectorT<1, bool, Q> const& v1, VectorT<1, bool, Q> const& v2);

template <qualifier Q>
constexpr bool operator||(VectorT<1, bool, Q> const& v1, VectorT<1, bool, Q> const& v2);

} // namespace mim

#include "mim/detail/type/type_vector1.inl"
