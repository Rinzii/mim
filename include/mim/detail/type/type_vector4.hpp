// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#pragma once

#include "mim/detail/qualifier.hpp"

namespace mim
{
	template <typename T, qualifier Q>
	struct vec<4, T, Q> {
		using value_type = T;
		using type = vec<4, T, Q>;
		using size_type = size_t;
		static constexpr auto size_v = 4;

		// Data
		T x, y, z, w;

		static constexpr size_type size() noexcept { return size_v; }

		constexpr T& operator[](size_type i);
		constexpr T const& operator[](size_type i) const;

		// Many of these constructors use as reference section 5.4.1 of the GLSL 1.30.08 specification

		/// Constructors

		constexpr vec();

		constexpr vec(T x, T y, T z, T w);

		constexpr vec(vec<4, T, Q> const& v);

		constexpr explicit vec(T scalar);

		/// Template Constructors

		template <qualifier P>
		constexpr explicit vec(vec<4, T, P> const& v);

		// U Template Constructors

		template <typename U, qualifier P>
		constexpr explicit vec(vec<1, U, P> const& v);

		template <typename U, qualifier P>
		constexpr explicit vec(vec<4, U, P> const& v);

		// XYZW Template Constructors

		template <typename X, typename Y, typename Z, typename W>
		constexpr vec(X _x, Y _y, Z _z, W _w);

		template <typename X, typename Y, typename Z, typename W>
		constexpr vec(vec<1, X, Q> const& _x, Y _y, Z _z, W _w);

		template <typename X, typename Y, typename Z, typename W>
		constexpr vec(X _x, vec<1, Y, Q> const& _y, Z _z, W _w);

		template <typename X, typename Y, typename Z, typename W>
		constexpr vec(vec<1, X, Q> const& _x, vec<1, Y, Q> const& _y, Z _z, W _w);

		template <typename X, typename Y, typename Z, typename W>
		constexpr vec(X _x, Y _y, vec<1, Z, Q> const& _z, W _w);

		template <typename X, typename Y, typename Z, typename W>
		constexpr vec(vec<1, X, Q> const& _x, Y _y, vec<1, Z, Q> const& _z, W _w);

		template <typename X, typename Y, typename Z, typename W>
		constexpr vec(X _x, vec<1, Y, Q> const& _y, vec<1, Z, Q> const& _z, W _w);

		template <typename X, typename Y, typename Z, typename W>
		constexpr vec(vec<1, X, Q> const& _x, vec<1, Y, Q> const& _y, vec<1, Z, Q> const& _z, W _w);

		template <typename X, typename Y, typename Z, typename W>
		constexpr vec(vec<1, X, Q> const& _x, Y _y, Z _z, vec<1, W, Q> const& _w);

		template <typename X, typename Y, typename Z, typename W>
		constexpr vec(X _x, vec<1, Y, Q> const& _y, Z _z, vec<1, W, Q> const& _w);

		template <typename X, typename Y, typename Z, typename W>
		constexpr vec(vec<1, X, Q> const& _x, vec<1, Y, Q> const& _y, Z _z, vec<1, W, Q> const& _w);

		template <typename X, typename Y, typename Z, typename W>
		constexpr vec(X _x, Y _y, vec<1, Z, Q> const& _z, vec<1, W, Q> const& _w);

		template <typename X, typename Y, typename Z, typename W>
		constexpr vec(vec<1, X, Q> const& _x, Y _y, vec<1, Z, Q> const& _z, vec<1, W, Q> const& _w);

		template <typename X, typename Y, typename Z, typename W>
		constexpr vec(X _x, vec<1, Y, Q> const& _y, vec<1, Z, Q> const& _z, vec<1, W, Q> const& _w);

		template <typename X, typename Y, typename Z, typename W>
		constexpr vec(vec<1, X, Q> const& _x, vec<1, Y, Q> const& _y, vec<1, Z, Q> const& _z, vec<1, W, Q> const& _w);

		// ABC Template Constructors

		template <typename A, typename B, typename C, qualifier P>
		constexpr vec(vec<2, A, P> const& _xy, B _z, C _w);

		template <typename A, typename B, typename C, qualifier P>
		constexpr vec(vec<2, A, P> const& _xy, vec<1, B, P> const& _z, C _w);

		template <typename A, typename B, typename C, qualifier P>
		constexpr vec(vec<2, A, P> const& _xy, B _z, vec<1, C, P> const& _w);

		template <typename A, typename B, typename C, qualifier P>
		constexpr vec(vec<2, A, P> const& _xy, vec<1, B, P> const& _z, vec<1, C, P> const& _w);

		template <typename A, typename B, typename C, qualifier P>
		constexpr vec(A _x, vec<2, B, P> const& _yz, C _w);

		template <typename A, typename B, typename C, qualifier P>
		constexpr vec(vec<1, A, P> const& _x, vec<2, B, P> const& _yz, C _w);

		template <typename A, typename B, typename C, qualifier P>
		constexpr vec(A _x, vec<2, B, P> const& _yz, vec<1, C, P> const& _w);

		template <typename A, typename B, typename C, qualifier P>
		constexpr vec(vec<1, A, P> const& _x, vec<2, B, P> const& _yz, vec<1, C, P> const& _w);

		template <typename A, typename B, typename C, qualifier P>
		constexpr vec(A _x, B _y, vec<2, C, P> const& _zw);

		template <typename A, typename B, typename C, qualifier P>
		constexpr vec(vec<1, A, P> const& _x, B _y, vec<2, C, P> const& _zw);

		template <typename A, typename B, typename C, qualifier P>
		constexpr vec(A _x, vec<1, B, P> const& _y, vec<2, C, P> const& _zw);

		template <typename A, typename B, typename C, qualifier P>
		constexpr vec(vec<1, A, P> const& _x, vec<1, B, P> const& _y, vec<2, C, P> const& _zw);

		// AB Template Constructors

		template <typename A, typename B, qualifier P>
		constexpr vec(vec<3, A, P> const& _xyz, B _w);

		template <typename A, typename B, qualifier P>
		constexpr vec(vec<3, A, P> const& _xyz, vec<1, B, P> const& _w);

		template <typename A, typename B, qualifier P>
		constexpr vec(A _x, vec<3, B, P> const& _yzw);

		template <typename A, typename B, qualifier P>
		constexpr vec(vec<1, A, P> const& _x, vec<3, B, P> const& _yzw);

		template <typename A, typename B, qualifier P>
		constexpr vec(vec<2, A, P> const& _xy, vec<2, B, P> const& _zw);

		/// Assignment Operators

		constexpr vec<4, T, Q>& operator=(vec<4, T, Q> const& v);

		template <typename U>
		constexpr vec<4, T, Q>& operator=(vec<4, U, Q> const& v);

		template <typename U>
		constexpr vec<4, T, Q>& operator+=(U scalar);

		template <typename U>
		constexpr vec<4, T, Q>& operator+=(vec<1, U, Q> const& v);

		template <typename U>
		constexpr vec<4, T, Q>& operator+=(vec<4, U, Q> const& v);

		template <typename U>
		constexpr vec<4, T, Q>& operator-=(U scalar);

		template <typename U>
		constexpr vec<4, T, Q>& operator-=(vec<1, U, Q> const& v);

		template <typename U>
		constexpr vec<4, T, Q>& operator-=(vec<4, U, Q> const& v);

		template <typename U>
		constexpr vec<4, T, Q>& operator*=(U scalar);

		template <typename U>
		constexpr vec<4, T, Q>& operator*=(vec<1, U, Q> const& v);

		template <typename U>
		constexpr vec<4, T, Q>& operator*=(vec<4, U, Q> const& v);

		template <typename U>
		constexpr vec<4, T, Q>& operator/=(U scalar);

		template <typename U>
		constexpr vec<4, T, Q>& operator/=(vec<1, U, Q> const& v);

		template <typename U>
		constexpr vec<4, T, Q>& operator/=(vec<4, U, Q> const& v);

		template <typename U>
		constexpr vec<4, T, Q>& operator%=(U scalar);

		template <typename U>
		constexpr vec<4, T, Q>& operator%=(vec<1, U, Q> const& v);

		template <typename U>
		constexpr vec<4, T, Q>& operator%=(vec<4, U, Q> const& v);

		/// Increment and Decrement Operators

		constexpr vec<4, T, Q>& operator++();

		constexpr vec<4, T, Q>& operator--();

		constexpr const vec<4, T, Q> operator++(int);

		constexpr const vec<4, T, Q> operator--(int);

		/// Bitwise Assignment Operators

		template <typename U>
		constexpr vec<4, T, Q>& operator&=(U scalar);

		template <typename U>
		constexpr vec<4, T, Q>& operator&=(vec<1, U, Q> const& v);

		template <typename U>
		constexpr vec<4, T, Q>& operator&=(vec<4, U, Q> const& v);

		template <typename U>
		constexpr vec<4, T, Q>& operator|=(U scalar);

		template <typename U>
		constexpr vec<4, T, Q>& operator|=(vec<1, U, Q> const& v);

		template <typename U>
		constexpr vec<4, T, Q>& operator|=(vec<4, U, Q> const& v);

		template <typename U>
		constexpr vec<4, T, Q>& operator^=(U scalar);

		template <typename U>
		constexpr vec<4, T, Q>& operator^=(vec<1, U, Q> const& v);

		template <typename U>
		constexpr vec<4, T, Q>& operator^=(vec<4, U, Q> const& v);

		template <typename U>
		constexpr vec<4, T, Q>& operator<<=(U scalar);

		template <typename U>
		constexpr vec<4, T, Q>& operator<<=(vec<1, U, Q> const& v);

		template <typename U>
		constexpr vec<4, T, Q>& operator<<=(vec<4, U, Q> const& v);

		template <typename U>
		constexpr vec<4, T, Q>& operator>>=(U scalar);

		template <typename U>
		constexpr vec<4, T, Q>& operator>>=(vec<1, U, Q> const& v);

		template <typename U>
		constexpr vec<4, T, Q>& operator>>=(vec<4, U, Q> const& v);


		/// Generic Function Declarations

		constexpr T length() const;

		constexpr T length_squared() const;

		constexpr void normalize();

		constexpr vec<4, T, Q> normalized() const;

		MIM_NODISCARD constexpr bool is_normalized() const;

		constexpr T distance(const vec<4, T, Q>& v) const;

		constexpr T distance_squared(const vec<4, T, Q>& v) const;


		/// Function Declarations

		constexpr T dot(const vec<4, T, Q>& v) const;
		constexpr T cross(const vec<4, T, Q>& v) const;
		constexpr vec<4, T, Q> rotated(T angle) const;
		constexpr vec<4, T, Q> clamp(const vec<4, T, Q>& min, const vec<4, T, Q>& max) const;
		constexpr vec<4, T, Q> reflect(const vec<4, T, Q>& normal) const;
		constexpr vec<4, T, Q> refract(const vec<4, T, Q>& normal, T eta) const;
		constexpr vec<4, T, Q> project(const vec<4, T, Q>& normal) const;
	};

	/// Unary Operators

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator+(vec<4, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator-(vec<4, T, Q> const& v);

	/// Binary Operators

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator+(vec<4, T, Q> const& v, T const& scalar);

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator+(T scalar, vec<4, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator+(vec<4, T, Q> const& v1, vec<1, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator+(vec<1, T, Q> const& v1, vec<4, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator+(vec<4, T, Q> const& v1, vec<4, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator-(vec<4, T, Q> const& v, T const& scalar);

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator-(T scalar, vec<4, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator-(vec<4, T, Q> const& v1, vec<1, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator-(vec<1, T, Q> const& v1, vec<4, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator-(vec<4, T, Q> const& v1, vec<4, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator*(vec<4, T, Q> const& v, T const& scalar);

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator*(T scalar, vec<4, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator*(vec<4, T, Q> const& v1, vec<1, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator*(vec<1, T, Q> const& v1, vec<4, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator*(vec<4, T, Q> const& v1, vec<4, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator/(vec<4, T, Q> const& v, T const& scalar);

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator/(T scalar, vec<4, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator/(vec<4, T, Q> const& v1, vec<1, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator/(vec<1, T, Q> const& v1, vec<4, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator/(vec<4, T, Q> const& v1, vec<4, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator%(vec<4, T, Q> const& v, T scalar);

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator%(T scalar, vec<4, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator%(vec<4, T, Q> const& v, vec<1, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator%(vec<1, T, Q> const& scalar, vec<4, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator%(vec<4, T, Q> const& v1, vec<4, T, Q> const& v2);

	/// Bitwise Binary Operators

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator&(vec<4, T, Q> const& v, T scalar);

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator&(T scalar, vec<4, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator&(vec<4, T, Q> const& v, vec<1, T, Q> const& scalar);

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator&(vec<1, T, Q> const& v1, vec<4, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator&(vec<4, T, Q> const& v1, vec<4, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator|(vec<4, T, Q> const& v, T scalar);

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator|(T scalar, vec<4, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator|(vec<4, T, Q> const& v, vec<1, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator|(vec<1, T, Q> const& v1, vec<4, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator|(vec<4, T, Q> const& v1, vec<4, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator^(vec<4, T, Q> const& v, T scalar);

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator^(T scalar, vec<4, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator^(vec<4, T, Q> const& v, vec<1, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator^(vec<1, T, Q> const& v1, vec<4, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator^(vec<4, T, Q> const& v1, vec<4, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator<<(vec<4, T, Q> const& v, T scalar);

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator<<(T scalar, vec<4, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator<<(vec<4, T, Q> const& v, vec<1, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator<<(vec<1, T, Q> const& v1, vec<4, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator<<(vec<4, T, Q> const& v1, vec<4, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator>>(vec<4, T, Q> const& v, T scalar);

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator>>(T scalar, vec<4, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator>>(vec<4, T, Q> const& v, vec<1, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator>>(vec<1, T, Q> const& v1, vec<4, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator>>(vec<4, T, Q> const& v1, vec<4, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator~(vec<4, T, Q> const& v);

	/// Conditional Binary Operators

	template <typename T, qualifier Q>
	constexpr bool operator==(vec<4, T, Q> const& v1, vec<4, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr bool operator!=(vec<4, T, Q> const& v1, vec<4, T, Q> const& v2);

	template <qualifier Q>
	constexpr bool operator&&(vec<4, bool, Q> const& v1, vec<4, bool, Q> const& v2);

	template <qualifier Q>
	constexpr bool operator||(vec<4, bool, Q> const& v1, vec<4, bool, Q> const& v2);


} // namespace mim

#include "mim/detail/type/type_vector4.inl"
#include "mim/detail/func/func_vector4.inl"
