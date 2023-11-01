// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#pragma once

#include "mim/detail/defines.hpp"

namespace mim
{

	template <typename T>
	struct vec<3, T> {
		using value_type = T;
		using type = vec<3, T>;
		using size_type = size_t;
		static constexpr auto size_v = 3;

		// Data
		T x, y, z;

		static constexpr size_type size() { return size_v; }

		constexpr T& operator[](size_type i);
		constexpr T const& operator[](size_type i) const;

		// Constructors

		constexpr vec();

		constexpr vec(T _x, T _y, T _z);

		constexpr vec(vec<3, T> const& v);

		constexpr explicit vec(T scalar);

		// U Template Constructors

		template <typename U>
		constexpr explicit vec(vec<1, U> const& scalar);

		template <typename U>
		constexpr explicit vec(vec<3, U> const& v);

		// XYZ Template Constructors

		template <typename X, typename Y, typename Z>
		constexpr vec(X _x, Y _y, Z _z);

		template <typename X, typename Y, typename Z>
		constexpr vec(vec<1, X> const& _x, Y _y, Z _z);

		template <typename X, typename Y, typename Z>
		constexpr vec(X _x, vec<1, Y> const& _y, Z _z);

		template <typename X, typename Y, typename Z>
		constexpr vec(X _x, Y _y, vec<1, Z> const& _z);

		template <typename X, typename Y, typename Z>
		constexpr vec(vec<1, X> const& _x, vec<1, Y> const& _y, Z _z);

		template <typename X, typename Y, typename Z>
		constexpr vec(vec<1, X> const& _x, Y _y, vec<1, Z> const& _z);

		template <typename X, typename Y, typename Z>
		constexpr vec(X _x, vec<1, Y> const& _y, vec<1, Z> const& _z);

		template <typename X, typename Y, typename Z>
		constexpr vec(vec<1, X> const& _x, vec<1, Y> const& _y, vec<1, Z> const& _z);

		// AB Template Constructors

		template <typename A, typename B>
		constexpr vec(vec<2, A> const& _xy, B _z);

		template <typename A, typename B>
		constexpr vec(A _x, vec<2, B> const& _yz);

		template <typename A, typename B>
		constexpr vec(vec<2, A> const& _xy, vec<1, B> const& _z);

		template <typename A, typename B>
		constexpr vec(vec<1, A> const& _x, vec<2, B> const& _yz);

		// Assignment Operators

		constexpr vec<3, T>& operator=(T scalar);

		constexpr vec<3, T>& operator=(vec<3, T> const& v);

		template <typename U>
		constexpr vec<3, T>& operator=(vec<1, U> const& scalar);

		template <typename U>
		constexpr vec<3, T>& operator=(vec<3, U> const& v);

		template <typename U>
		constexpr vec<3, T>& operator+=(U scalar);

		template <typename U>
		constexpr vec<3, T>& operator+=(vec<1, U> const& v);

		template <typename U>
		constexpr vec<3, T>& operator+=(vec<3, U> const& v);

		template <typename U>
		constexpr vec<3, T>& operator-=(U scalar);

		template <typename U>
		constexpr vec<3, T>& operator-=(vec<1, U> const& scalar);

		template <typename U>
		constexpr vec<3, T>& operator-=(vec<3, U> const& v);

		template <typename U>
		constexpr vec<3, T>& operator*=(U scalar);

		template <typename U>
		constexpr vec<3, T>& operator*=(vec<1, U> const& v);

		template <typename U>
		constexpr vec<3, T>& operator*=(vec<3, U> const& v);

		template <typename U>
		constexpr vec<3, T>& operator/=(U scalar);

		template <typename U>
		constexpr vec<3, T>& operator/=(vec<1, U> const& v);

		template <typename U>
		constexpr vec<3, T>& operator/=(vec<3, U> const& v);

		template <typename U>
		constexpr vec<3, T>& operator%=(U scalar);

		template <typename U>
		constexpr vec<3, T>& operator%=(vec<1, U> const& v);

		template <typename U>
		constexpr vec<3, T>& operator%=(vec<3, U> const& v);

		// Increment and Decrement Operators

		constexpr vec<3, T>& operator++();

		constexpr vec<3, T>& operator--();

		constexpr const vec<3, T> operator++(int);

		constexpr const vec<3, T> operator--(int);

		// Bitwise Assignment Operators

		template <typename U>
		constexpr vec<3, T>& operator&=(U scalar);

		template <typename U>
		constexpr vec<3, T>& operator&=(vec<1, U> const& v);

		template <typename U>
		constexpr vec<3, T>& operator&=(vec<3, U> const& v);

		template <typename U>
		constexpr vec<3, T>& operator|=(U scalar);

		template <typename U>
		constexpr vec<3, T>& operator|=(vec<1, U> const& v);

		template <typename U>
		constexpr vec<3, T>& operator|=(vec<3, U> const& v);

		template <typename U>
		constexpr vec<3, T>& operator^=(U scalar);

		template <typename U>
		constexpr vec<3, T>& operator^=(vec<1, U> const& v);

		template <typename U>
		constexpr vec<3, T>& operator^=(vec<3, U> const& v);

		template <typename U>
		constexpr vec<3, T>& operator<<=(U scalar);

		template <typename U>
		constexpr vec<3, T>& operator<<=(vec<1, U> const& v);

		template <typename U>
		constexpr vec<3, T>& operator<<=(vec<3, U> const& v);

		template <typename U>
		constexpr vec<3, T>& operator>>=(U scalar);

		template <typename U>
		constexpr vec<3, T>& operator>>=(vec<1, U> const& v);

		template <typename U>
		constexpr vec<3, T>& operator>>=(vec<3, U> const& v);


		// Function Declarations

		constexpr vec<3, T> inverse() const;

		constexpr T length() const;

		constexpr T length_squared() const;

		constexpr void normalize();

		constexpr vec<3, T> normalized() const;

		MIM_NODISCARD constexpr bool is_normalized() const;

		constexpr T distance(const vec<3, T>& v) const;

		constexpr T distance_squared(const vec<3, T>& v) const;

		constexpr T dot(const vec<3, T>& v) const;

		constexpr vec<3, T> cross(const vec<3, T>& v) const;

		constexpr vec<3, T> hadamard(const vec<3, T>& v) const;

		constexpr void rotate(const vec<3, T>& axis, T angle);

		constexpr vec<3, T> rotated(T angle) const;

		constexpr vec<3, T> clamp(const vec<3, T>& min, const vec<3, T>& max) const;

		constexpr vec<3, T> reflect(const vec<3, T>& normal) const;

		constexpr vec<3, T> refract(const vec<3, T>& normal, T eta) const;

		constexpr vec<3, T> project(const vec<3, T>& normal) const;

	};

	/// Free operators

	// Unary Operators

	template <typename T>
	constexpr vec<3, T> operator+(vec<3, T> const& v);

	template <typename T>
	constexpr vec<3, T> operator-(vec<3, T> const& v);

	// Binary Operators

	template <typename T>
	constexpr vec<3, T> operator+(vec<3, T> const& v, T scalar);

	template <typename T>
	constexpr vec<3, T> operator+(vec<3, T> const& v1, vec<1, T> const& sv);

	template <typename T>
	constexpr vec<3, T> operator+(T scalar, vec<3, T> const& v);

	template <typename T>
	constexpr vec<3, T> operator+(vec<1, T> const& sv, vec<3, T> const& v2);

	template <typename T>
	constexpr vec<3, T> operator+(vec<3, T> const& v1, vec<3, T> const& v2);

	template <typename T>
	constexpr vec<3, T> operator-(vec<3, T> const& v, T scalar);

	template <typename T>
	constexpr vec<3, T> operator-(vec<3, T> const& v1, vec<1, T> const& sv);

	template <typename T>
	constexpr vec<3, T> operator-(T scalar, vec<3, T> const& v);

	template <typename T>
	constexpr vec<3, T> operator-(vec<1, T> const& sv, vec<3, T> const& v2);

	template <typename T>
	constexpr vec<3, T> operator-(vec<3, T> const& v1, vec<3, T> const& v2);

	template <typename T>
	constexpr vec<3, T> operator*(vec<3, T> const& v, T scalar);

	template <typename T>
	constexpr vec<3, T> operator*(vec<3, T> const& v1, vec<1, T> const& sv);

	template <typename T>
	constexpr vec<3, T> operator*(T scalar, vec<3, T> const& v);

	template <typename T>
	constexpr vec<3, T> operator*(vec<1, T> const& sv, vec<3, T> const& v2);

	template <typename T>
	constexpr vec<3, T> operator*(vec<3, T> const& v1, vec<3, T> const& v2);

	template <typename T>
	constexpr vec<3, T> operator/(vec<3, T> const& v, T scalar);

	template <typename T>
	constexpr vec<3, T> operator/(vec<3, T> const& v1, vec<1, T> const& sv);

	template <typename T>
	constexpr vec<3, T> operator/(T scalar, vec<3, T> const& v);

	template <typename T>
	constexpr vec<3, T> operator/(vec<1, T> const& sv, vec<3, T> const& v2);

	template <typename T>
	constexpr vec<3, T> operator/(vec<3, T> const& v1, vec<3, T> const& v2);

	template <typename T>
	constexpr vec<3, T> operator%(vec<3, T> const& v, T scalar);

	template <typename T>
	constexpr vec<3, T> operator%(vec<3, T> const& v1, vec<1, T> const& sv);

	template <typename T>
	constexpr vec<3, T> operator%(T scalar, vec<3, T> const& v);

	template <typename T>
	constexpr vec<3, T> operator%(vec<1, T> const& sv, vec<3, T> const& v2);

	template <typename T>
	constexpr vec<3, T> operator%(vec<3, T> const& v1, vec<3, T> const& v2);

	// Bitwise Binary Operators

	template <typename T>
	constexpr vec<3, T> operator&(vec<3, T> const& v, T scalar);

	template <typename T>
	constexpr vec<3, T> operator&(vec<3, T> const& v1, vec<1, T> const& sv);

	template <typename T>
	constexpr vec<3, T> operator&(T scalar, vec<3, T> const& v);

	template <typename T>
	constexpr vec<3, T> operator&(vec<1, T> const& sv, vec<3, T> const& v2);

	template <typename T>
	constexpr vec<3, T> operator&(vec<3, T> const& v1, vec<3, T> const& v2);

	template <typename T>
	constexpr vec<3, T> operator|(vec<3, T> const& v, T scalar);

	template <typename T>
	constexpr vec<3, T> operator|(vec<3, T> const& v1, vec<1, T> const& sv);

	template <typename T>
	constexpr vec<3, T> operator|(T scalar, vec<3, T> const& v);

	template <typename T>
	constexpr vec<3, T> operator|(vec<1, T> const& sv, vec<3, T> const& v2);

	template <typename T>
	constexpr vec<3, T> operator|(vec<3, T> const& v1, vec<3, T> const& v2);

	template <typename T>
	constexpr vec<3, T> operator^(vec<3, T> const& v, T scalar);

	template <typename T>
	constexpr vec<3, T> operator^(vec<3, T> const& v1, vec<1, T> const& sv);

	template <typename T>
	constexpr vec<3, T> operator^(T scalar, vec<3, T> const& v);

	template <typename T>
	constexpr vec<3, T> operator^(vec<1, T> const& sv, vec<3, T> const& v2);

	template <typename T>
	constexpr vec<3, T> operator^(vec<3, T> const& v1, vec<3, T> const& v2);

	template <typename T>
	constexpr vec<3, T> operator<<(vec<3, T> const& v, T scalar);

	template <typename T>
	constexpr vec<3, T> operator<<(vec<3, T> const& v1, vec<1, T> const& sv);

	template <typename T>
	constexpr vec<3, T> operator<<(T scalar, vec<3, T> const& v);

	template <typename T>
	constexpr vec<3, T> operator<<(vec<1, T> const& sv, vec<3, T> const& v2);

	template <typename T>
	constexpr vec<3, T> operator<<(vec<3, T> const& v1, vec<3, T> const& v2);

	template <typename T>
	constexpr vec<3, T> operator>>(vec<3, T> const& v, T scalar);

	template <typename T>
	constexpr vec<3, T> operator>>(vec<3, T> const& v1, vec<1, T> const& sv);

	template <typename T>
	constexpr vec<3, T> operator>>(T scalar, vec<3, T> const& v);

	template <typename T>
	constexpr vec<3, T> operator>>(vec<1, T> const& sv, vec<3, T> const& v2);

	template <typename T>
	constexpr vec<3, T> operator>>(vec<3, T> const& v1, vec<3, T> const& v2);

	template <typename T>
	constexpr vec<3, T> operator~(vec<3, T> const& v);

	// Conditional Operators

	template <typename T>
	constexpr bool operator==(vec<3, T> const& v1, vec<3, T> const& v2);

	template <typename T>
	constexpr bool operator!=(vec<3, T> const& v1, vec<3, T> const& v2);

	template <typename T>
	constexpr vec<3, bool> operator&&(vec<3, T> const& v1, vec<3, T> const& v2);

	template <typename T>
	constexpr vec<3, bool> operator||(vec<3, T> const& v1, vec<3, T> const& v2);


	/// Free functions

	template <typename T>
	constexpr vec<3, T> inverse(vec<3, T> const& v);

	template <typename T>
	constexpr T length(vec<3, T> const& v);

	template <typename T>
	constexpr T length_squared(vec<3, T> const& v);

	template <typename T>
	constexpr vec<3, T> normalized(vec<3, T> const& v);

	template <typename T>
	MIM_NODISCARD constexpr bool is_normalized(vec<3, T> const& v);

	template <typename T>
	constexpr T distance(vec<3, T> const& v1, vec<3, T> const& v2);

	template <typename T>
	constexpr T distance_squared(vec<3, T> const& v1, vec<3, T> const& v2);

	template <typename T>
	constexpr vec<3, T> dot(vec<3, T> const& v1, vec<3, T> const& v2);

	template <typename T>
	constexpr vec<3, T> cross(vec<3, T> const& v1, vec<3, T> const& v2);

	template <typename T>
	constexpr vec<3, T> hadamard(vec<3, T> const& v1, vec<3, T> const& v2);

	template <typename T>
	constexpr vec<3, T> rotated(vec<3, T> const& v, T angle);

	template <typename T>
	constexpr vec<3, T> clamp(vec<3, T> const& v, vec<3, T> const& min, vec<3, T> const& max);

	template <typename T>
	constexpr vec<3, T> reflect(vec<3, T> const& v, vec<3, T> const& normal);

	template <typename T>
	constexpr vec<3, T> refract(vec<3, T> const& v, vec<3, T> const& normal, T eta);

	template <typename T>
	constexpr vec<3, T> project(vec<3, T> const& v, vec<3, T> const& normal);

} // namespace mim

#include "mim/detail/type/type_vector3.inl"
#include "mim/detail/func/func_vector3.inl"
