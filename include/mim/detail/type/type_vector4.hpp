// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#pragma once

#include "mim/detail/qualifier.hpp"

#include <iostream>

namespace mim {
template <typename T, qualifier Q>
struct VectorT<4, T, Q> {
	using value_type = T;
	using type = VectorT<4, T, Q>;
	using bool_type = VectorT<4, bool, Q>;
	using size_type = size_t;
	static constexpr auto size_v = 4;

	// Data
	T x, y, z, w;

	static constexpr size_type size() noexcept { return size_v; }

	constexpr T& operator[](size_type i);
	constexpr T const& operator[](size_type i) const;

	// Many of these constructors use as reference section 5.4.1 of the GLSL 1.30.08 specification

	constexpr VectorT();
	constexpr VectorT(VectorT<4, T, Q> const& v);
	template <qualifier P>
	constexpr explicit VectorT(VectorT<4, T, P> const& v);

	constexpr explicit VectorT(T scalar);
	constexpr VectorT(T x, T y, T z, T w);

	template <typename U, qualifier P>
	constexpr explicit VectorT(VectorT<1, U, P> const& v);

	template <typename X, typename Y, typename Z, typename W>
	constexpr VectorT(X _x, Y _y, Z _z, W _w);
	template <typename X, typename Y, typename Z, typename W>
	constexpr VectorT(VectorT<1, X, Q> const& _x, Y _y, Z _z, W _w);
	template <typename X, typename Y, typename Z, typename W>
	constexpr VectorT(X _x, VectorT<1, Y, Q> const& _y, Z _z, W _w);
	template <typename X, typename Y, typename Z, typename W>
	constexpr VectorT(VectorT<1, X, Q> const& _x, VectorT<1, Y, Q> const& _y, Z _z, W _w);
	template <typename X, typename Y, typename Z, typename W>
	constexpr VectorT(X _x, Y _y, VectorT<1, Z, Q> const& _z, W _w);
	template <typename X, typename Y, typename Z, typename W>
	constexpr VectorT(VectorT<1, X, Q> const& _x, Y _y, VectorT<1, Z, Q> const& _z, W _w);
	template <typename X, typename Y, typename Z, typename W>
	constexpr VectorT(X _x, VectorT<1, Y, Q> const& _y, VectorT<1, Z, Q> const& _z, W _w);
	template <typename X, typename Y, typename Z, typename W>
	constexpr VectorT(VectorT<1, X, Q> const& _x, VectorT<1, Y, Q> const& _y, VectorT<1, Z, Q> const& _z, W _w);
	template <typename X, typename Y, typename Z, typename W>
	constexpr VectorT(VectorT<1, X, Q> const& _x, Y _y, Z _z, VectorT<1, W, Q> const& _w);
	template <typename X, typename Y, typename Z, typename W>
	constexpr VectorT(X _x, VectorT<1, Y, Q> const& _y, Z _z, VectorT<1, W, Q> const& _w);
	template <typename X, typename Y, typename Z, typename W>
	constexpr VectorT(VectorT<1, X, Q> const& _x, VectorT<1, Y, Q> const& _y, Z _z, VectorT<1, W, Q> const& _w);
	template <typename X, typename Y, typename Z, typename W>
	constexpr VectorT(X _x, Y _y, VectorT<1, Z, Q> const& _z, VectorT<1, W, Q> const& _w);
	template <typename X, typename Y, typename Z, typename W>
	constexpr VectorT(VectorT<1, X, Q> const& _x, Y _y, VectorT<1, Z, Q> const& _z, VectorT<1, W, Q> const& _w);
	template <typename X, typename Y, typename Z, typename W>
	constexpr VectorT(X _x, VectorT<1, Y, Q> const& _y, VectorT<1, Z, Q> const& _z, VectorT<1, W, Q> const& _w);
	template <typename X, typename Y, typename Z, typename W>
	constexpr VectorT(VectorT<1, X, Q> const& _x, VectorT<1, Y, Q> const& _y, VectorT<1, Z, Q> const& _z, VectorT<1, W, Q> const& _w);

	template <typename A, typename B, typename C, qualifier P>
	constexpr VectorT(VectorT<2, A, P> const& _xy, B _z, C _w);
	template <typename A, typename B, typename C, qualifier P>
	constexpr VectorT(VectorT<2, A, P> const& _xy, VectorT<1, B, P> const& _z, C _w);
	template <typename A, typename B, typename C, qualifier P>
	constexpr VectorT(VectorT<2, A, P> const& _xy, B _z, VectorT<1, C, P> const& _w);
	template <typename A, typename B, typename C, qualifier P>
	constexpr VectorT(VectorT<2, A, P> const& _xy, VectorT<1, B, P> const& _z, VectorT<1, C, P> const& _w);
	template <typename A, typename B, typename C, qualifier P>
	constexpr VectorT(A _x, VectorT<2, B, P> const& _yz, C _w);
	template <typename A, typename B, typename C, qualifier P>
	constexpr VectorT(VectorT<1, A, P> const& _x, VectorT<2, B, P> const& _yz, C _w);
	template <typename A, typename B, typename C, qualifier P>
	constexpr VectorT(A _x, VectorT<2, B, P> const& _yz, VectorT<1, C, P> const& _w);
	template <typename A, typename B, typename C, qualifier P>
	constexpr VectorT(VectorT<1, A, P> const& _x, VectorT<2, B, P> const& _yz, VectorT<1, C, P> const& _w);
	template <typename A, typename B, typename C, qualifier P>
	constexpr VectorT(A _x, B _y, VectorT<2, C, P> const& _zw);
	template <typename A, typename B, typename C, qualifier P>
	constexpr VectorT(VectorT<1, A, P> const& _x, B _y, VectorT<2, C, P> const& _zw);
	template <typename A, typename B, typename C, qualifier P>
	constexpr VectorT(A _x, VectorT<1, B, P> const& _y, VectorT<2, C, P> const& _zw);
	template <typename A, typename B, typename C, qualifier P>
	constexpr VectorT(VectorT<1, A, P> const& _x, VectorT<1, B, P> const& _y, VectorT<2, C, P> const& _zw);
	template <typename A, typename B, qualifier P>
	constexpr VectorT(VectorT<3, A, P> const& _xyz, B _w);
	template <typename A, typename B, qualifier P>
	constexpr VectorT(VectorT<3, A, P> const& _xyz, VectorT<1, B, P> const& _w);
	template <typename A, typename B, qualifier P>
	constexpr VectorT(A _x, VectorT<3, B, P> const& _yzw);
	template <typename A, typename B, qualifier P>
	constexpr VectorT(VectorT<1, A, P> const& _x, VectorT<3, B, P> const& _yzw);
	template <typename A, typename B, qualifier P>
	constexpr VectorT(VectorT<2, A, P> const& _xy, VectorT<2, B, P> const& _zw);

	template <typename U, qualifier P>
	constexpr explicit VectorT(VectorT<4, U, P> const& v);

	constexpr VectorT<4, T, Q>& operator=(VectorT<4, T, Q> const& v) = default;

	template <typename U>
	constexpr VectorT<4, T, Q>& operator=(VectorT<4, U, Q> const& v);
	template <typename U>
	constexpr VectorT<4, T, Q>& operator+=(U scalar);
	template <typename U>
	constexpr VectorT<4, T, Q>& operator+=(VectorT<1, U, Q> const& v);
	template <typename U>
	constexpr VectorT<4, T, Q>& operator+=(VectorT<4, U, Q> const& v);
	template <typename U>
	constexpr VectorT<4, T, Q>& operator-=(U scalar);
	template <typename U>
	constexpr VectorT<4, T, Q>& operator-=(VectorT<1, U, Q> const& v);
	template <typename U>
	constexpr VectorT<4, T, Q>& operator-=(VectorT<4, U, Q> const& v);
	template <typename U>
	constexpr VectorT<4, T, Q>& operator*=(U scalar);
	template <typename U>
	constexpr VectorT<4, T, Q>& operator*=(VectorT<1, U, Q> const& v);
	template <typename U>
	constexpr VectorT<4, T, Q>& operator*=(VectorT<4, U, Q> const& v);
	template <typename U>
	constexpr VectorT<4, T, Q>& operator/=(U scalar);
	template <typename U>
	constexpr VectorT<4, T, Q>& operator/=(VectorT<1, U, Q> const& v);
	template <typename U>
	constexpr VectorT<4, T, Q>& operator/=(VectorT<4, U, Q> const& v);

	constexpr VectorT<4, T, Q>& operator++();
	constexpr VectorT<4, T, Q>& operator--();
	constexpr const VectorT<4, T, Q> operator++(int);
	constexpr const VectorT<4, T, Q> operator--(int);

	template <typename U>
	constexpr VectorT<4, T, Q>& operator%=(U scalar);
	template <typename U>
	constexpr VectorT<4, T, Q>& operator%=(VectorT<1, U, Q> const& v);
	template <typename U>
	constexpr VectorT<4, T, Q>& operator%=(VectorT<4, U, Q> const& v);
	template <typename U>
	constexpr VectorT<4, T, Q>& operator&=(U scalar);
	template <typename U>
	constexpr VectorT<4, T, Q>& operator&=(VectorT<1, U, Q> const& v);
	template <typename U>
	constexpr VectorT<4, T, Q>& operator&=(VectorT<4, U, Q> const& v);
	template <typename U>
	constexpr VectorT<4, T, Q>& operator|=(U scalar);
	template <typename U>
	constexpr VectorT<4, T, Q>& operator|=(VectorT<1, U, Q> const& v);
	template <typename U>
	constexpr VectorT<4, T, Q>& operator|=(VectorT<4, U, Q> const& v);
	template <typename U>
	constexpr VectorT<4, T, Q>& operator^=(U scalar);
	template <typename U>
	constexpr VectorT<4, T, Q>& operator^=(VectorT<1, U, Q> const& v);
	template <typename U>
	constexpr VectorT<4, T, Q>& operator^=(VectorT<4, U, Q> const& v);
	template <typename U>
	constexpr VectorT<4, T, Q>& operator<<=(U scalar);
	template <typename U>
	constexpr VectorT<4, T, Q>& operator<<=(VectorT<1, U, Q> const& v);
	template <typename U>
	constexpr VectorT<4, T, Q>& operator<<=(VectorT<4, U, Q> const& v);
	template <typename U>
	constexpr VectorT<4, T, Q>& operator>>=(U scalar);
	template <typename U>
	constexpr VectorT<4, T, Q>& operator>>=(VectorT<1, U, Q> const& v);
	template <typename U>
	constexpr VectorT<4, T, Q>& operator>>=(VectorT<4, U, Q> const& v);

	friend std::ostream& operator<<(std::ostream& os, VectorT<4, T, Q> const& v)
	{
		return os << "(" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << ")";
	}

};

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator+(VectorT<4, T, Q> const& v);

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator-(VectorT<4, T, Q> const& v);

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator+(VectorT<4, T, Q> const& v, T const& scalar);

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator+(VectorT<4, T, Q> const& v1, VectorT<1, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator+(T scalar, VectorT<4, T, Q> const& v);

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator+(VectorT<1, T, Q> const& v1, VectorT<4, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator+(VectorT<4, T, Q> const& v1, VectorT<4, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator-(VectorT<4, T, Q> const& v, T const& scalar);

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator-(VectorT<4, T, Q> const& v1, VectorT<1, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator-(T scalar, VectorT<4, T, Q> const& v);

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator-(VectorT<1, T, Q> const& v1, VectorT<4, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator-(VectorT<4, T, Q> const& v1, VectorT<4, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator*(VectorT<4, T, Q> const& v, T const& scalar);

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator*(VectorT<4, T, Q> const& v1, VectorT<1, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator*(T scalar, VectorT<4, T, Q> const& v);

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator*(VectorT<1, T, Q> const& v1, VectorT<4, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator*(VectorT<4, T, Q> const& v1, VectorT<4, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator/(VectorT<4, T, Q> const& v, T const& scalar);

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator/(VectorT<4, T, Q> const& v1, VectorT<1, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator/(T scalar, VectorT<4, T, Q> const& v);

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator/(VectorT<1, T, Q> const& v1, VectorT<4, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator/(VectorT<4, T, Q> const& v1, VectorT<4, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator%(VectorT<4, T, Q> const& v, T scalar);

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator%(VectorT<4, T, Q> const& v, VectorT<1, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator%(T scalar, VectorT<4, T, Q> const& v);

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator%(VectorT<1, T, Q> const& scalar, VectorT<4, T, Q> const& v);

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator%(VectorT<4, T, Q> const& v1, VectorT<4, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator&(VectorT<4, T, Q> const& v, T scalar);

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator&(VectorT<4, T, Q> const& v, VectorT<1, T, Q> const& scalar);

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator&(T scalar, VectorT<4, T, Q> const& v);

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator&(VectorT<1, T, Q> const& v1, VectorT<4, T, Q> const& v);

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator&(VectorT<4, T, Q> const& v1, VectorT<4, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator|(VectorT<4, T, Q> const& v, T scalar);

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator|(VectorT<4, T, Q> const& v, VectorT<1, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator|(T scalar, VectorT<4, T, Q> const& v);

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator|(VectorT<1, T, Q> const& v1, VectorT<4, T, Q> const& v);

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator|(VectorT<4, T, Q> const& v1, VectorT<4, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator^(VectorT<4, T, Q> const& v, T scalar);

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator^(VectorT<4, T, Q> const& v, VectorT<1, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator^(T scalar, VectorT<4, T, Q> const& v);

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator^(VectorT<1, T, Q> const& v1, VectorT<4, T, Q> const& v);

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator^(VectorT<4, T, Q> const& v1, VectorT<4, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator<<(VectorT<4, T, Q> const& v, T scalar);

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator<<(VectorT<4, T, Q> const& v, VectorT<1, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator<<(T scalar, VectorT<4, T, Q> const& v);

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator<<(VectorT<1, T, Q> const& v1, VectorT<4, T, Q> const& v);

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator<<(VectorT<4, T, Q> const& v1, VectorT<4, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator>>(VectorT<4, T, Q> const& v, T scalar);

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator>>(VectorT<4, T, Q> const& v, VectorT<1, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator>>(T scalar, VectorT<4, T, Q> const& v);

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator>>(VectorT<1, T, Q> const& v1, VectorT<4, T, Q> const& v);

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator>>(VectorT<4, T, Q> const& v1, VectorT<4, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator~(VectorT<4, T, Q> const& v);

template <typename T, qualifier Q>
constexpr bool operator==(VectorT<4, T, Q> const& v1, VectorT<4, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr bool operator!=(VectorT<4, T, Q> const& v1, VectorT<4, T, Q> const& v2);

template <qualifier Q>
constexpr bool operator&&(VectorT<4, bool, Q> const& v1, VectorT<4, bool, Q> const& v2);

template <qualifier Q>
constexpr bool operator||(VectorT<4, bool, Q> const& v1, VectorT<4, bool, Q> const& v2);
} // namespace mim

#include "mim/detail/type/type_vector4.inl"
