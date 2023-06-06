// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#pragma once

#include <iostream>
#include "mim/detail/qualifier.hpp"

namespace mim {

template <typename T, qualifier Q>
struct VectorT<3, T, Q> {
	using value_type = T;
	using type = VectorT<3, T, Q>;
	using bool_type = VectorT<3, bool, Q>;
	using size_type = size_t;
	static constexpr auto size_v = 3;

	union {
		// This anonymous struct is only for syntactic sugar.
		struct {
			T x, y, z;
		};

		typename detail::Storage<3, T, detail::IsAligned<Q>::value>::type data;
	};

	static constexpr size_type size() { return size_v; }

	constexpr T& operator[](size_type i);
	constexpr T const& operator[](size_type i) const;

	// Many of these constructors use as reference section 5.4.1 of the GLSL 1.30.08 specification

	constexpr VectorT();
	constexpr VectorT(VectorT const& v);

	template <qualifier P>
	constexpr VectorT(VectorT<3, T, P> const& v);

	constexpr explicit VectorT(T scalar);
	constexpr VectorT(T a, T b, T c);

	template <typename U, qualifier P>
	constexpr explicit VectorT(VectorT<1, U, P> const& v);

	template <typename X, typename Y, typename Z>
	constexpr VectorT(X _x, Y _y, Z _z);
	template <typename X, typename Y, typename Z>
	constexpr VectorT(VectorT<1, X, Q> const& _x, Y _y, Z _z);
	template <typename X, typename Y, typename Z>
	constexpr VectorT(X _x, VectorT<1, Y, Q> const& _y, Z _z);
	template <typename X, typename Y, typename Z>
	constexpr VectorT(X _x, Y _y, VectorT<1, Z, Q> const& _z);
	template <typename X, typename Y, typename Z>
	constexpr VectorT(VectorT<1, X, Q> const& _x, VectorT<1, Y, Q> const& _y, Z _z);
	template <typename X, typename Y, typename Z>
	constexpr VectorT(VectorT<1, X, Q> const& _x, Y _y, VectorT<1, Z, Q> const& _z);
	template <typename X, typename Y, typename Z>
	constexpr VectorT(X _x, VectorT<1, Y, Q> const& _y, VectorT<1, Z, Q> const& _z);
	template <typename X, typename Y, typename Z>
	constexpr VectorT(VectorT<1, X, Q> const& _x, VectorT<1, Y, Q> const& _y, VectorT<1, Z, Q> const& _z);

	template <typename A, typename B, qualifier P>
	constexpr VectorT(VectorT<2, A, P> const& _xy, B _z);
	template <typename A, typename B, qualifier P>
	constexpr VectorT(A _x, VectorT<2, B, P> const& _yz);

	template <typename A, typename B, qualifier P>
	constexpr VectorT(VectorT<2, A, P> const& _xy, VectorT<1, B, P> const& _z);
	template <typename A, typename B, qualifier P>
	constexpr VectorT(VectorT<1, A, P> const& _x, VectorT<2, B, P> const& _yz);

	template <typename U, qualifier P>
	constexpr explicit VectorT(VectorT<3, U, P> const& v);

	template <typename U, qualifier P>
	constexpr explicit VectorT(VectorT<4, U, P> const& v);

	constexpr VectorT& operator=(VectorT const& v) = default;

	template <typename U>
	constexpr VectorT& operator=(VectorT<3, U, Q> const& v);

	template <typename U>
	constexpr VectorT& operator+=(U scalar);
	template <typename U>
	constexpr VectorT& operator+=(VectorT<1, U, Q> const& v);
	template <typename U>
	constexpr VectorT& operator+=(VectorT<3, U, Q> const& v);

	template <typename U>
	constexpr VectorT& operator-=(U scalar);
	template <typename U>
	constexpr VectorT& operator-=(VectorT<1, U, Q> const& v);
	template <typename U>
	constexpr VectorT& operator-=(VectorT<3, U, Q> const& v);

	template <typename U>
	constexpr VectorT& operator*=(U scalar);
	template <typename U>
	constexpr VectorT& operator*=(VectorT<1, U, Q> const& v);
	template <typename U>
	constexpr VectorT& operator*=(VectorT<3, U, Q> const& v);

	template <typename U>
	constexpr VectorT& operator/=(U scalar);
	template <typename U>
	constexpr VectorT& operator/=(VectorT<1, U, Q> const& v);
	template <typename U>
	constexpr VectorT& operator/=(VectorT<3, U, Q> const& v);

	constexpr VectorT& operator++();
	constexpr VectorT& operator--();
	constexpr const VectorT operator++(int);
	constexpr const VectorT operator--(int);

	template <typename U>
	constexpr VectorT& operator%=(U scalar);
	template <typename U>
	constexpr VectorT& operator%=(VectorT<1, U, Q> const& v);
	template <typename U>
	constexpr VectorT& operator%=(VectorT<3, U, Q> const& v);

	template <typename U>
	constexpr VectorT& operator&=(U scalar);
	template <typename U>
	constexpr VectorT& operator&=(VectorT<1, U, Q> const& v);
	template <typename U>
	constexpr VectorT& operator&=(VectorT<3, U, Q> const& v);

	template <typename U>
	constexpr VectorT& operator|=(U scalar);
	template <typename U>
	constexpr VectorT& operator|=(VectorT<1, U, Q> const& v);
	template <typename U>
	constexpr VectorT& operator|=(VectorT<3, U, Q> const& v);

	template <typename U>
	constexpr VectorT& operator^=(U scalar);
	template <typename U>
	constexpr VectorT& operator^=(VectorT<1, U, Q> const& v);
	template <typename U>
	constexpr VectorT& operator^=(VectorT<3, U, Q> const& v);

	template <typename U>
	constexpr VectorT& operator<<=(U scalar);
	template <typename U>
	constexpr VectorT& operator<<=(VectorT<1, U, Q> const& v);
	template <typename U>
	constexpr VectorT& operator<<=(VectorT<3, U, Q> const& v);

	template <typename U>
	constexpr VectorT& operator>>=(U scalar);
	template <typename U>
	constexpr VectorT& operator>>=(VectorT<1, U, Q> const& v);
	template <typename U>
	constexpr VectorT& operator>>=(VectorT<3, U, Q> const& v);

	friend std::ostream& operator<<(std::ostream& os, VectorT<3, T, Q> const& v);
};

template <typename T, qualifier Q>
std::ostream& operator<<(std::ostream& os, VectorT<3, T, Q> const& v)
{
	return os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
}

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator+(VectorT<3, T, Q> const& v);

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator-(VectorT<3, T, Q> const& v);

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator+(VectorT<3, T, Q> const& v, T scalar);
template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator+(VectorT<3, T, Q> const& v1, VectorT<1, T, Q> const& v2);
template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator+(T scalar, VectorT<3, T, Q> const& v);
template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator+(VectorT<1, T, Q> const& v1, VectorT<3, T, Q> const& v2);
template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator+(VectorT<3, T, Q> const& v1, VectorT<3, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator-(VectorT<3, T, Q> const& v, T scalar);
template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator-(VectorT<3, T, Q> const& v1, VectorT<1, T, Q> const& v2);
template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator-(T scalar, VectorT<3, T, Q> const& v);
template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator-(VectorT<1, T, Q> const& v1, VectorT<3, T, Q> const& v2);
template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator-(VectorT<3, T, Q> const& v1, VectorT<3, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator*(VectorT<3, T, Q> const& v, T scalar);
template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator*(VectorT<3, T, Q> const& v1, VectorT<1, T, Q> const& v2);
template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator*(T scalar, VectorT<3, T, Q> const& v);
template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator*(VectorT<1, T, Q> const& v1, VectorT<3, T, Q> const& v2);
template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator*(VectorT<3, T, Q> const& v1, VectorT<3, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator/(VectorT<3, T, Q> const& v, T scalar);
template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator/(VectorT<3, T, Q> const& v1, VectorT<1, T, Q> const& v2);
template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator/(T scalar, VectorT<3, T, Q> const& v);
template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator/(VectorT<1, T, Q> const& v1, VectorT<3, T, Q> const& v2);
template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator/(VectorT<3, T, Q> const& v1, VectorT<3, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator%(VectorT<3, T, Q> const& v, T scalar);
template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator%(VectorT<3, T, Q> const& v1, VectorT<1, T, Q> const& v2);
template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator%(T scalar, VectorT<3, T, Q> const& v);
template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator%(VectorT<1, T, Q> const& v1, VectorT<3, T, Q> const& v2);
template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator%(VectorT<3, T, Q> const& v1, VectorT<3, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator&(VectorT<3, T, Q> const& v, T scalar);
template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator&(VectorT<3, T, Q> const& v1, VectorT<1, T, Q> const& v2);
template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator&(T scalar, VectorT<3, T, Q> const& v);
template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator&(VectorT<1, T, Q> const& v1, VectorT<3, T, Q> const& v2);
template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator&(VectorT<3, T, Q> const& v1, VectorT<3, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator|(VectorT<3, T, Q> const& v, T scalar);
template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator|(VectorT<3, T, Q> const& v1, VectorT<1, T, Q> const& v2);
template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator|(T scalar, VectorT<3, T, Q> const& v);
template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator|(VectorT<1, T, Q> const& v1, VectorT<3, T, Q> const& v2);
template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator|(VectorT<3, T, Q> const& v1, VectorT<3, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator^(VectorT<3, T, Q> const& v, T scalar);
template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator^(VectorT<3, T, Q> const& v1, VectorT<1, T, Q> const& v2);
template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator^(T scalar, VectorT<3, T, Q> const& v);
template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator^(VectorT<1, T, Q> const& v1, VectorT<3, T, Q> const& v2);
template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator^(VectorT<3, T, Q> const& v1, VectorT<3, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator<<(VectorT<3, T, Q> const& v, T scalar);
template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator<<(VectorT<3, T, Q> const& v1, VectorT<1, T, Q> const& v2);
template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator<<(T scalar, VectorT<3, T, Q> const& v);
template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator<<(VectorT<1, T, Q> const& v1, VectorT<3, T, Q> const& v2);
template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator<<(VectorT<3, T, Q> const& v1, VectorT<3, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator>>(VectorT<3, T, Q> const& v, T scalar);
template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator>>(VectorT<3, T, Q> const& v1, VectorT<1, T, Q> const& v2);
template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator>>(T scalar, VectorT<3, T, Q> const& v);
template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator>>(VectorT<1, T, Q> const& v1, VectorT<3, T, Q> const& v2);
template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator>>(VectorT<3, T, Q> const& v1, VectorT<3, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator~(VectorT<3, T, Q> const& v);

template <typename T, qualifier Q>
constexpr bool operator==(VectorT<3, T, Q> const& v1, VectorT<3, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr bool operator!=(VectorT<3, T, Q> const& v1, VectorT<3, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr bool operator&&(VectorT<3, T, Q> const& v1, VectorT<3, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr bool operator||(VectorT<3, T, Q> const& v1, VectorT<3, T, Q> const& v2);

} // namespace mim

#include "mim/detail/type/type_vector3.inl"
