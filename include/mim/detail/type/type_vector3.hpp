// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#pragma once

#include "mim/detail/qualifier.hpp"

namespace mim
{

	template <typename T, qualifier Q>
	struct vec<3, T, Q> {
		using value_type = T;
		using type = vec<3, T, Q>;
		using size_type = size_t;
		static constexpr auto size_v = 3;

		// Data
		T x, y, z;

		static constexpr size_type size() { return size_v; }

		constexpr T& operator[](size_type i);
		constexpr T const& operator[](size_type i) const;

		// Many of these constructors use as reference section 5.4.1 of the GLSL 1.30.08 specification

		/// Constructors

		constexpr vec();

		constexpr vec(T _x, T _y, T _z);

		constexpr vec(vec<3, T, Q> const& v);

		constexpr explicit vec(T scalar);

		/// Template Constructors

		template <qualifier P>
		constexpr explicit vec(vec<3, T, P> const& v);

		// U Template Constructors

		template <typename U, qualifier P>
		constexpr explicit vec(vec<1, U, P> const& scalar);

		template <typename U, qualifier P>
		constexpr explicit vec(vec<3, U, P> const& v);

		// XYZ Template Constructors

		template <typename X, typename Y, typename Z>
		constexpr vec(X _x, Y _y, Z _z);

		template <typename X, typename Y, typename Z>
		constexpr vec(vec<1, X, Q> const& _x, Y _y, Z _z);

		template <typename X, typename Y, typename Z>
		constexpr vec(X _x, vec<1, Y, Q> const& _y, Z _z);

		template <typename X, typename Y, typename Z>
		constexpr vec(X _x, Y _y, vec<1, Z, Q> const& _z);

		template <typename X, typename Y, typename Z>
		constexpr vec(vec<1, X, Q> const& _x, vec<1, Y, Q> const& _y, Z _z);

		template <typename X, typename Y, typename Z>
		constexpr vec(vec<1, X, Q> const& _x, Y _y, vec<1, Z, Q> const& _z);

		template <typename X, typename Y, typename Z>
		constexpr vec(X _x, vec<1, Y, Q> const& _y, vec<1, Z, Q> const& _z);

		template <typename X, typename Y, typename Z>
		constexpr vec(vec<1, X, Q> const& _x, vec<1, Y, Q> const& _y, vec<1, Z, Q> const& _z);

		// AB Template Constructors

		template <typename A, typename B, qualifier P>
		constexpr vec(vec<2, A, P> const& _xy, B _z);

		template <typename A, typename B, qualifier P>
		constexpr vec(A _x, vec<2, B, P> const& _yz);

		template <typename A, typename B, qualifier P>
		constexpr vec(vec<2, A, P> const& _xy, vec<1, B, P> const& _z);

		template <typename A, typename B, qualifier P>
		constexpr vec(vec<1, A, P> const& _x, vec<2, B, P> const& _yz);

		/// Assignment Operators

		constexpr vec<3, T, Q>& operator=(T scalar);

		constexpr vec<3, T, Q>& operator=(vec<3, T, Q> const& v);

		template <typename U>
		constexpr vec<3, T, Q>& operator=(vec<1, U, Q> const& scalar);

		template <typename U>
		constexpr vec<3, T, Q>& operator=(vec<3, U, Q> const& v);

		template <typename U>
		constexpr vec<3, T, Q>& operator+=(U scalar);

		template <typename U>
		constexpr vec<3, T, Q>& operator+=(vec<1, U, Q> const& v);

		template <typename U>
		constexpr vec<3, T, Q>& operator+=(vec<3, U, Q> const& v);

		template <typename U>
		constexpr vec<3, T, Q>& operator-=(U scalar);

		template <typename U>
		constexpr vec<3, T, Q>& operator-=(vec<1, U, Q> const& scalar);

		template <typename U>
		constexpr vec<3, T, Q>& operator-=(vec<3, U, Q> const& v);

		template <typename U>
		constexpr vec<3, T, Q>& operator*=(U scalar);

		template <typename U>
		constexpr vec<3, T, Q>& operator*=(vec<1, U, Q> const& v);

		template <typename U>
		constexpr vec<3, T, Q>& operator*=(vec<3, U, Q> const& v);

		template <typename U>
		constexpr vec<3, T, Q>& operator/=(U scalar);

		template <typename U>
		constexpr vec<3, T, Q>& operator/=(vec<1, U, Q> const& v);

		template <typename U>
		constexpr vec<3, T, Q>& operator/=(vec<3, U, Q> const& v);

		template <typename U>
		constexpr vec<3, T, Q>& operator%=(U scalar);

		template <typename U>
		constexpr vec<3, T, Q>& operator%=(vec<1, U, Q> const& v);

		template <typename U>
		constexpr vec<3, T, Q>& operator%=(vec<3, U, Q> const& v);

		/// Increment and Decrement Operators

		constexpr vec<3, T, Q>& operator++();

		constexpr vec<3, T, Q>& operator--();

		constexpr const vec<3, T, Q> operator++(int);

		constexpr const vec<3, T, Q> operator--(int);

		/// Bitwise Assignment Operators

		template <typename U>
		constexpr vec<3, T, Q>& operator&=(U scalar);

		template <typename U>
		constexpr vec<3, T, Q>& operator&=(vec<1, U, Q> const& v);

		template <typename U>
		constexpr vec<3, T, Q>& operator&=(vec<3, U, Q> const& v);

		template <typename U>
		constexpr vec<3, T, Q>& operator|=(U scalar);

		template <typename U>
		constexpr vec<3, T, Q>& operator|=(vec<1, U, Q> const& v);

		template <typename U>
		constexpr vec<3, T, Q>& operator|=(vec<3, U, Q> const& v);

		template <typename U>
		constexpr vec<3, T, Q>& operator^=(U scalar);

		template <typename U>
		constexpr vec<3, T, Q>& operator^=(vec<1, U, Q> const& v);

		template <typename U>
		constexpr vec<3, T, Q>& operator^=(vec<3, U, Q> const& v);

		template <typename U>
		constexpr vec<3, T, Q>& operator<<=(U scalar);

		template <typename U>
		constexpr vec<3, T, Q>& operator<<=(vec<1, U, Q> const& v);

		template <typename U>
		constexpr vec<3, T, Q>& operator<<=(vec<3, U, Q> const& v);

		template <typename U>
		constexpr vec<3, T, Q>& operator>>=(U scalar);

		template <typename U>
		constexpr vec<3, T, Q>& operator>>=(vec<1, U, Q> const& v);

		template <typename U>
		constexpr vec<3, T, Q>& operator>>=(vec<3, U, Q> const& v);


		/// Generic Function Declarations

		constexpr T length() const;

		constexpr T length_squared() const;

		constexpr void normalize();

		constexpr vec<3, T, Q> normalized() const;

		MIM_NODISCARD constexpr bool is_normalized() const;

		constexpr T distance(const vec<3, T, Q>& v) const;

		constexpr T distance_squared(const vec<3, T, Q>& v) const;


		/// Function Declarations

		constexpr T dot(const vec<3, T, Q>& v) const;
		constexpr T cross(const vec<3, T, Q>& v) const;
		constexpr void rotate(T angle);
		constexpr vec<3, T, Q> rotated(T angle) const;
		constexpr vec<3, T, Q> clamp(const vec<3, T, Q>& min, const vec<3, T, Q>& max) const;
		constexpr vec<3, T, Q> reflect(const vec<3, T, Q>& normal) const;
		constexpr vec<3, T, Q> refract(const vec<3, T, Q>& normal, T eta) const;
		constexpr vec<3, T, Q> project(const vec<3, T, Q>& normal) const;

	};

	/// Unary Operators

	template <typename T, qualifier Q>
	constexpr vec<3, T, Q> operator+(vec<3, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr vec<3, T, Q> operator-(vec<3, T, Q> const& v);

	/// Binary Operators

	template <typename T, qualifier Q>
	constexpr vec<3, T, Q> operator+(vec<3, T, Q> const& v, T scalar);

	template <typename T, qualifier Q>
	constexpr vec<3, T, Q> operator+(vec<3, T, Q> const& v1, vec<1, T, Q> const& sv);

	template <typename T, qualifier Q>
	constexpr vec<3, T, Q> operator+(T scalar, vec<3, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr vec<3, T, Q> operator+(vec<1, T, Q> const& sv, vec<3, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<3, T, Q> operator+(vec<3, T, Q> const& v1, vec<3, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<3, T, Q> operator-(vec<3, T, Q> const& v, T scalar);

	template <typename T, qualifier Q>
	constexpr vec<3, T, Q> operator-(vec<3, T, Q> const& v1, vec<1, T, Q> const& sv);

	template <typename T, qualifier Q>
	constexpr vec<3, T, Q> operator-(T scalar, vec<3, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr vec<3, T, Q> operator-(vec<1, T, Q> const& sv, vec<3, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<3, T, Q> operator-(vec<3, T, Q> const& v1, vec<3, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<3, T, Q> operator*(vec<3, T, Q> const& v, T scalar);

	template <typename T, qualifier Q>
	constexpr vec<3, T, Q> operator*(vec<3, T, Q> const& v1, vec<1, T, Q> const& sv);

	template <typename T, qualifier Q>
	constexpr vec<3, T, Q> operator*(T scalar, vec<3, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr vec<3, T, Q> operator*(vec<1, T, Q> const& sv, vec<3, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<3, T, Q> operator*(vec<3, T, Q> const& v1, vec<3, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<3, T, Q> operator/(vec<3, T, Q> const& v, T scalar);

	template <typename T, qualifier Q>
	constexpr vec<3, T, Q> operator/(vec<3, T, Q> const& v1, vec<1, T, Q> const& sv);

	template <typename T, qualifier Q>
	constexpr vec<3, T, Q> operator/(T scalar, vec<3, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr vec<3, T, Q> operator/(vec<1, T, Q> const& sv, vec<3, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<3, T, Q> operator/(vec<3, T, Q> const& v1, vec<3, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<3, T, Q> operator%(vec<3, T, Q> const& v, T scalar);

	template <typename T, qualifier Q>
	constexpr vec<3, T, Q> operator%(vec<3, T, Q> const& v1, vec<1, T, Q> const& sv);

	template <typename T, qualifier Q>
	constexpr vec<3, T, Q> operator%(T scalar, vec<3, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr vec<3, T, Q> operator%(vec<1, T, Q> const& sv, vec<3, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<3, T, Q> operator%(vec<3, T, Q> const& v1, vec<3, T, Q> const& v2);

	/// Bitwise Binary Operators

	template <typename T, qualifier Q>
	constexpr vec<3, T, Q> operator&(vec<3, T, Q> const& v, T scalar);

	template <typename T, qualifier Q>
	constexpr vec<3, T, Q> operator&(vec<3, T, Q> const& v1, vec<1, T, Q> const& sv);

	template <typename T, qualifier Q>
	constexpr vec<3, T, Q> operator&(T scalar, vec<3, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr vec<3, T, Q> operator&(vec<1, T, Q> const& sv, vec<3, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<3, T, Q> operator&(vec<3, T, Q> const& v1, vec<3, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<3, T, Q> operator|(vec<3, T, Q> const& v, T scalar);

	template <typename T, qualifier Q>
	constexpr vec<3, T, Q> operator|(vec<3, T, Q> const& v1, vec<1, T, Q> const& sv);

	template <typename T, qualifier Q>
	constexpr vec<3, T, Q> operator|(T scalar, vec<3, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr vec<3, T, Q> operator|(vec<1, T, Q> const& sv, vec<3, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<3, T, Q> operator|(vec<3, T, Q> const& v1, vec<3, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<3, T, Q> operator^(vec<3, T, Q> const& v, T scalar);

	template <typename T, qualifier Q>
	constexpr vec<3, T, Q> operator^(vec<3, T, Q> const& v1, vec<1, T, Q> const& sv);

	template <typename T, qualifier Q>
	constexpr vec<3, T, Q> operator^(T scalar, vec<3, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr vec<3, T, Q> operator^(vec<1, T, Q> const& sv, vec<3, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<3, T, Q> operator^(vec<3, T, Q> const& v1, vec<3, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<3, T, Q> operator<<(vec<3, T, Q> const& v, T scalar);

	template <typename T, qualifier Q>
	constexpr vec<3, T, Q> operator<<(vec<3, T, Q> const& v1, vec<1, T, Q> const& sv);

	template <typename T, qualifier Q>
	constexpr vec<3, T, Q> operator<<(T scalar, vec<3, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr vec<3, T, Q> operator<<(vec<1, T, Q> const& sv, vec<3, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<3, T, Q> operator<<(vec<3, T, Q> const& v1, vec<3, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<3, T, Q> operator>>(vec<3, T, Q> const& v, T scalar);

	template <typename T, qualifier Q>
	constexpr vec<3, T, Q> operator>>(vec<3, T, Q> const& v1, vec<1, T, Q> const& sv);

	template <typename T, qualifier Q>
	constexpr vec<3, T, Q> operator>>(T scalar, vec<3, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr vec<3, T, Q> operator>>(vec<1, T, Q> const& sv, vec<3, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<3, T, Q> operator>>(vec<3, T, Q> const& v1, vec<3, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<3, T, Q> operator~(vec<3, T, Q> const& v);

	/// Conditional Operators

	template <typename T, qualifier Q>
	constexpr bool operator==(vec<3, T, Q> const& v1, vec<3, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr bool operator!=(vec<3, T, Q> const& v1, vec<3, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr bool operator&&(vec<3, T, Q> const& v1, vec<3, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr bool operator||(vec<3, T, Q> const& v1, vec<3, T, Q> const& v2);


	// Free functions

	template <typename T, qualifier Q>
	constexpr vec<3, T, Q> dot(vec<3, T, Q> const& v1, vec<3, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<3, T, Q> cross(vec<3, T, Q> const& v1, vec<3, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<3, T, Q> inverse(vec<3, T, Q> const& v, T epsilon = 0.001f);


} // namespace mim

#include "mim/detail/type/type_vector3.inl"
#include "mim/detail/func/func_vector3.inl"
