// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#pragma once

#include "mim/detail/defines.hpp"

namespace mim
{
	template <typename T>
	struct vec<4, T> {
		using value_type = T;
		using type = vec<4, T>;
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

		constexpr vec(vec<4, T> const& v);

		constexpr explicit vec(T scalar);

		/// U Template Constructors

		template <typename U>
		constexpr explicit vec(vec<1, U> const& v);

		template <typename U>
		constexpr explicit vec(vec<4, U> const& v);

		// XYZW Template Constructors

		template <typename X, typename Y, typename Z, typename W>
		constexpr vec(X _x, Y _y, Z _z, W _w);

		template <typename X, typename Y, typename Z, typename W>
		constexpr vec(vec<1, X> const& _x, Y _y, Z _z, W _w);

		template <typename X, typename Y, typename Z, typename W>
		constexpr vec(X _x, vec<1, Y> const& _y, Z _z, W _w);

		template <typename X, typename Y, typename Z, typename W>
		constexpr vec(vec<1, X> const& _x, vec<1, Y> const& _y, Z _z, W _w);

		template <typename X, typename Y, typename Z, typename W>
		constexpr vec(X _x, Y _y, vec<1, Z> const& _z, W _w);

		template <typename X, typename Y, typename Z, typename W>
		constexpr vec(vec<1, X> const& _x, Y _y, vec<1, Z> const& _z, W _w);

		template <typename X, typename Y, typename Z, typename W>
		constexpr vec(X _x, vec<1, Y> const& _y, vec<1, Z> const& _z, W _w);

		template <typename X, typename Y, typename Z, typename W>
		constexpr vec(vec<1, X> const& _x, vec<1, Y> const& _y, vec<1, Z> const& _z, W _w);

		template <typename X, typename Y, typename Z, typename W>
		constexpr vec(vec<1, X> const& _x, Y _y, Z _z, vec<1, W> const& _w);

		template <typename X, typename Y, typename Z, typename W>
		constexpr vec(X _x, vec<1, Y> const& _y, Z _z, vec<1, W> const& _w);

		template <typename X, typename Y, typename Z, typename W>
		constexpr vec(vec<1, X> const& _x, vec<1, Y> const& _y, Z _z, vec<1, W> const& _w);

		template <typename X, typename Y, typename Z, typename W>
		constexpr vec(X _x, Y _y, vec<1, Z> const& _z, vec<1, W> const& _w);

		template <typename X, typename Y, typename Z, typename W>
		constexpr vec(vec<1, X> const& _x, Y _y, vec<1, Z> const& _z, vec<1, W> const& _w);

		template <typename X, typename Y, typename Z, typename W>
		constexpr vec(X _x, vec<1, Y> const& _y, vec<1, Z> const& _z, vec<1, W> const& _w);

		template <typename X, typename Y, typename Z, typename W>
		constexpr vec(vec<1, X> const& _x, vec<1, Y> const& _y, vec<1, Z> const& _z, vec<1, W> const& _w);

		/// ABC Template Constructors

		template <typename A, typename B, typename C>
		constexpr vec(vec<2, A> const& _xy, B _z, C _w);

		template <typename A, typename B, typename C>
		constexpr vec(vec<2, A> const& _xy, vec<1, B> const& _z, C _w);

		template <typename A, typename B, typename C>
		constexpr vec(vec<2, A> const& _xy, B _z, vec<1, C> const& _w);

		template <typename A, typename B, typename C>
		constexpr vec(vec<2, A> const& _xy, vec<1, B> const& _z, vec<1, C> const& _w);

		template <typename A, typename B, typename C>
		constexpr vec(A _x, vec<2, B> const& _yz, C _w);

		template <typename A, typename B, typename C>
		constexpr vec(vec<1, A> const& _x, vec<2, B> const& _yz, C _w);

		template <typename A, typename B, typename C>
		constexpr vec(A _x, vec<2, B> const& _yz, vec<1, C> const& _w);

		template <typename A, typename B, typename C>
		constexpr vec(vec<1, A> const& _x, vec<2, B> const& _yz, vec<1, C> const& _w);

		template <typename A, typename B, typename C>
		constexpr vec(A _x, B _y, vec<2, C> const& _zw);

		template <typename A, typename B, typename C>
		constexpr vec(vec<1, A> const& _x, B _y, vec<2, C> const& _zw);

		template <typename A, typename B, typename C>
		constexpr vec(A _x, vec<1, B> const& _y, vec<2, C> const& _zw);

		template <typename A, typename B, typename C>
		constexpr vec(vec<1, A> const& _x, vec<1, B> const& _y, vec<2, C> const& _zw);

		/// AB Template Constructors

		template <typename A, typename B>
		constexpr vec(vec<3, A> const& _xyz, B _w);

		template <typename A, typename B>
		constexpr vec(vec<3, A> const& _xyz, vec<1, B> const& _w);

		template <typename A, typename B>
		constexpr vec(A _x, vec<3, B> const& _yzw);

		template <typename A, typename B>
		constexpr vec(vec<1, A> const& _x, vec<3, B> const& _yzw);

		template <typename A, typename B>
		constexpr vec(vec<2, A> const& _xy, vec<2, B> const& _zw);

		/// Assignment Operators

		constexpr vec<4, T>& operator=(vec<4, T> const& v);

		template <typename U>
		constexpr vec<4, T>& operator=(vec<4, U> const& v);

		template <typename U>
		constexpr vec<4, T>& operator+=(U scalar);

		template <typename U>
		constexpr vec<4, T>& operator+=(vec<1, U> const& v);

		template <typename U>
		constexpr vec<4, T>& operator+=(vec<4, U> const& v);

		template <typename U>
		constexpr vec<4, T>& operator-=(U scalar);

		template <typename U>
		constexpr vec<4, T>& operator-=(vec<1, U> const& v);

		template <typename U>
		constexpr vec<4, T>& operator-=(vec<4, U> const& v);

		template <typename U>
		constexpr vec<4, T>& operator*=(U scalar);

		template <typename U>
		constexpr vec<4, T>& operator*=(vec<1, U> const& v);

		template <typename U>
		constexpr vec<4, T>& operator*=(vec<4, U> const& v);

		template <typename U>
		constexpr vec<4, T>& operator/=(U scalar);

		template <typename U>
		constexpr vec<4, T>& operator/=(vec<1, U> const& v);

		template <typename U>
		constexpr vec<4, T>& operator/=(vec<4, U> const& v);

		template <typename U>
		constexpr vec<4, T>& operator%=(U scalar);

		template <typename U>
		constexpr vec<4, T>& operator%=(vec<1, U> const& v);

		template <typename U>
		constexpr vec<4, T>& operator%=(vec<4, U> const& v);

		// Increment and Decrement Operators

		constexpr vec<4, T>& operator++();

		constexpr vec<4, T>& operator--();

		constexpr const vec<4, T> operator++(int);

		constexpr const vec<4, T> operator--(int);

		// Bitwise Assignment Operators

		template <typename U>
		constexpr vec<4, T>& operator&=(U scalar);

		template <typename U>
		constexpr vec<4, T>& operator&=(vec<1, U> const& v);

		template <typename U>
		constexpr vec<4, T>& operator&=(vec<4, U> const& v);

		template <typename U>
		constexpr vec<4, T>& operator|=(U scalar);

		template <typename U>
		constexpr vec<4, T>& operator|=(vec<1, U> const& v);

		template <typename U>
		constexpr vec<4, T>& operator|=(vec<4, U> const& v);

		template <typename U>
		constexpr vec<4, T>& operator^=(U scalar);

		template <typename U>
		constexpr vec<4, T>& operator^=(vec<1, U> const& v);

		template <typename U>
		constexpr vec<4, T>& operator^=(vec<4, U> const& v);

		template <typename U>
		constexpr vec<4, T>& operator<<=(U scalar);

		template <typename U>
		constexpr vec<4, T>& operator<<=(vec<1, U> const& v);

		template <typename U>
		constexpr vec<4, T>& operator<<=(vec<4, U> const& v);

		template <typename U>
		constexpr vec<4, T>& operator>>=(U scalar);

		template <typename U>
		constexpr vec<4, T>& operator>>=(vec<1, U> const& v);

		template <typename U>
		constexpr vec<4, T>& operator>>=(vec<4, U> const& v);


		// Functions

		constexpr T length() const;

		constexpr T length_squared() const;

		constexpr void normalize();

		constexpr vec<4, T> normalized() const;

		MIM_NODISCARD constexpr bool is_normalized() const;

		constexpr T distance(const vec<4, T>& v) const;

		constexpr T distance_squared(const vec<4, T>& v) const;

		// TODO: Maybe add the wedge product as an option?

		constexpr T dot(const vec<4, T>& v) const;

		constexpr vec<4, T> hadamard(const vec<4, T>& v) const;

		constexpr vec<4, T> clamp(const vec<4, T>& min, const vec<4, T>& max) const;

	};

	/// Free functions

	// Unary Operators

	template <typename T>
	constexpr vec<4, T> operator+(vec<4, T> const& v);

	template <typename T>
	constexpr vec<4, T> operator-(vec<4, T> const& v);

	// Binary Operators

	template <typename T>
	constexpr vec<4, T> operator+(vec<4, T> const& v, T const& scalar);

	template <typename T>
	constexpr vec<4, T> operator+(T scalar, vec<4, T> const& v);

	template <typename T>
	constexpr vec<4, T> operator+(vec<4, T> const& v1, vec<1, T> const& v2);

	template <typename T>
	constexpr vec<4, T> operator+(vec<1, T> const& v1, vec<4, T> const& v2);

	template <typename T>
	constexpr vec<4, T> operator+(vec<4, T> const& v1, vec<4, T> const& v2);

	template <typename T>
	constexpr vec<4, T> operator-(vec<4, T> const& v, T const& scalar);

	template <typename T>
	constexpr vec<4, T> operator-(T scalar, vec<4, T> const& v);

	template <typename T>
	constexpr vec<4, T> operator-(vec<4, T> const& v1, vec<1, T> const& v2);

	template <typename T>
	constexpr vec<4, T> operator-(vec<1, T> const& v1, vec<4, T> const& v2);

	template <typename T>
	constexpr vec<4, T> operator-(vec<4, T> const& v1, vec<4, T> const& v2);

	template <typename T>
	constexpr vec<4, T> operator*(vec<4, T> const& v, T const& scalar);

	template <typename T>
	constexpr vec<4, T> operator*(T scalar, vec<4, T> const& v);

	template <typename T>
	constexpr vec<4, T> operator*(vec<4, T> const& v1, vec<1, T> const& v2);

	template <typename T>
	constexpr vec<4, T> operator*(vec<1, T> const& v1, vec<4, T> const& v2);

	template <typename T>
	constexpr vec<4, T> operator*(vec<4, T> const& v1, vec<4, T> const& v2);

	template <typename T>
	constexpr vec<4, T> operator/(vec<4, T> const& v, T const& scalar);

	template <typename T>
	constexpr vec<4, T> operator/(T scalar, vec<4, T> const& v);

	template <typename T>
	constexpr vec<4, T> operator/(vec<4, T> const& v1, vec<1, T> const& v2);

	template <typename T>
	constexpr vec<4, T> operator/(vec<1, T> const& v1, vec<4, T> const& v2);

	template <typename T>
	constexpr vec<4, T> operator/(vec<4, T> const& v1, vec<4, T> const& v2);

	template <typename T>
	constexpr vec<4, T> operator%(vec<4, T> const& v, T scalar);

	template <typename T>
	constexpr vec<4, T> operator%(T scalar, vec<4, T> const& v);

	template <typename T>
	constexpr vec<4, T> operator%(vec<4, T> const& v, vec<1, T> const& v2);

	template <typename T>
	constexpr vec<4, T> operator%(vec<1, T> const& scalar, vec<4, T> const& v);

	template <typename T>
	constexpr vec<4, T> operator%(vec<4, T> const& v1, vec<4, T> const& v2);

	// Bitwise Binary Operators

	template <typename T>
	constexpr vec<4, T> operator&(vec<4, T> const& v, T scalar);

	template <typename T>
	constexpr vec<4, T> operator&(T scalar, vec<4, T> const& v);

	template <typename T>
	constexpr vec<4, T> operator&(vec<4, T> const& v, vec<1, T> const& scalar);

	template <typename T>
	constexpr vec<4, T> operator&(vec<1, T> const& v1, vec<4, T> const& v);

	template <typename T>
	constexpr vec<4, T> operator&(vec<4, T> const& v1, vec<4, T> const& v2);

	template <typename T>
	constexpr vec<4, T> operator|(vec<4, T> const& v, T scalar);

	template <typename T>
	constexpr vec<4, T> operator|(T scalar, vec<4, T> const& v);

	template <typename T>
	constexpr vec<4, T> operator|(vec<4, T> const& v, vec<1, T> const& v2);

	template <typename T>
	constexpr vec<4, T> operator|(vec<1, T> const& v1, vec<4, T> const& v);

	template <typename T>
	constexpr vec<4, T> operator|(vec<4, T> const& v1, vec<4, T> const& v2);

	template <typename T>
	constexpr vec<4, T> operator^(vec<4, T> const& v, T scalar);

	template <typename T>
	constexpr vec<4, T> operator^(T scalar, vec<4, T> const& v);

	template <typename T>
	constexpr vec<4, T> operator^(vec<4, T> const& v, vec<1, T> const& v2);

	template <typename T>
	constexpr vec<4, T> operator^(vec<1, T> const& v1, vec<4, T> const& v);

	template <typename T>
	constexpr vec<4, T> operator^(vec<4, T> const& v1, vec<4, T> const& v2);

	template <typename T>
	constexpr vec<4, T> operator<<(vec<4, T> const& v, T scalar);

	template <typename T>
	constexpr vec<4, T> operator<<(T scalar, vec<4, T> const& v);

	template <typename T>
	constexpr vec<4, T> operator<<(vec<4, T> const& v, vec<1, T> const& v2);

	template <typename T>
	constexpr vec<4, T> operator<<(vec<1, T> const& v1, vec<4, T> const& v);

	template <typename T>
	constexpr vec<4, T> operator<<(vec<4, T> const& v1, vec<4, T> const& v2);

	template <typename T>
	constexpr vec<4, T> operator>>(vec<4, T> const& v, T scalar);

	template <typename T>
	constexpr vec<4, T> operator>>(T scalar, vec<4, T> const& v);

	template <typename T>
	constexpr vec<4, T> operator>>(vec<4, T> const& v, vec<1, T> const& v2);

	template <typename T>
	constexpr vec<4, T> operator>>(vec<1, T> const& v1, vec<4, T> const& v);

	template <typename T>
	constexpr vec<4, T> operator>>(vec<4, T> const& v1, vec<4, T> const& v2);

	template <typename T>
	constexpr vec<4, T> operator~(vec<4, T> const& v);

	// Conditional Binary Operators

	template <typename T>
	constexpr bool operator==(vec<4, T> const& v1, vec<4, T> const& v2);

	template <typename T>
	constexpr bool operator!=(vec<4, T> const& v1, vec<4, T> const& v2);

	constexpr vec<4, bool> operator&&(vec<4, bool> const& v1, vec<4, bool> const& v2);

	constexpr vec<4, bool> operator||(vec<4, bool> const& v1, vec<4, bool> const& v2);


	/// These functions are defined in func_vector4.inl

	template <typename T>
	constexpr T length(vec<4, T> const& v);

	template <typename T>
	constexpr T length_squared(vec<4, T> const& v);

	template <typename T>
	constexpr vec<4, T> normalized(vec<4, T> const& v);

	template <typename T>
	MIM_NODISCARD constexpr bool is_normalized(vec<4, T> const& v);

	template <typename T>
	constexpr T distance(vec<4, T> const& v1, vec<4, T> const& v2);

	template <typename T>
	constexpr T distance_squared(vec<4, T> const& v1, vec<4, T> const& v2);

	template <typename T>
	constexpr T dot(vec<4, T> const& v1, vec<4, T> const& v2);

	template <typename T>
	constexpr vec<4, T> hadamard(vec<4, T> const& v1, vec<4, T> const& v2);


} // namespace mim

#include "mim/detail/type/type_vector4.inl"
#include "mim/detail/func/func_vector4.inl"
