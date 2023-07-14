// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#pragma once

#include "mim/detail/qualifier.hpp"

namespace mim
{
	template <typename T, qualifier Q>
	struct vec<2, T, Q> {
		// Aliases

		using value_type = T;
		using type = vec<2, T, Q>;
		using size_type = size_t;
		static constexpr auto size_v = 2;

		// Data
		T x, y;

		// Element Accessors

		static constexpr std::size_t size() { return size_v; }

		constexpr T& operator[](std::size_t i);

		constexpr T const& operator[](std::size_t i) const;

		T& at(std::size_t i);

		const T& at(std::size_t i) const;

		// Many of these constructors use as reference section 5.4.1 of the GLSL 1.30.08 specification

		/// Constructors

		constexpr vec();

		constexpr vec(T _x, T _y);

		constexpr vec(vec const& v);

		constexpr explicit vec(T scalar);

		/// Template Constructors

		template <qualifier P>
		constexpr explicit vec(vec<2, T, P> const& v);

		// U Template Constructors

		template <typename U, qualifier P>
		constexpr explicit vec(vec<1, U, P> const& scalar);

		template <typename U, qualifier P>
		constexpr explicit vec(vec<2, U, P> const& v);

		template <typename U, qualifier P>
		constexpr explicit vec(vec<3, U, P> const& v);

		template <typename U, qualifier P>
		constexpr explicit vec(vec<4, U, P> const& v);

		// AB Template Constructors

		template <typename A, typename B>
		constexpr explicit vec(A _x, B _y);

		template <typename A, typename B>
		constexpr vec(vec<1, A, Q> const& _x, B _y);

		template <typename A, typename B>
		constexpr vec(A _x, vec<1, B, Q> const& _y);

		template <typename A, typename B>
		constexpr vec(vec<1, A, Q> const& _x, vec<1, B, Q> const& _y);

		/// Assignment Operators

		constexpr vec<2, T, Q>& operator=(T scalar);

		constexpr vec<2, T, Q>& operator=(vec<2, T, Q> const& v);

		template <typename U>
		constexpr vec<2, T, Q>& operator=(vec<1, U, Q> const& scalar);

		template <typename U>
		constexpr vec<2, T, Q>& operator=(vec<2, U, Q> const& v);

		template <typename U>
		constexpr vec<2, T, Q>& operator+=(U scalar);

		template <typename U>
		constexpr vec<2, T, Q>& operator+=(vec<1, U, Q> const& scalar);

		template <typename U>
		constexpr vec<2, T, Q>& operator+=(vec<2, U, Q> const& v);

		template <typename U>
		constexpr vec<2, T, Q>& operator-=(U scalar);

		template <typename U>
		constexpr vec<2, T, Q>& operator-=(vec<1, U, Q> const& scalar);

		template <typename U>
		constexpr vec<2, T, Q>& operator-=(vec<2, U, Q> const& v);

		template <typename U>
		constexpr vec<2, T, Q>& operator*=(U scalar);

		template <typename U>
		constexpr vec<2, T, Q>& operator*=(vec<1, U, Q> const& scalar);

		template <typename U>
		constexpr vec<2, T, Q>& operator*=(vec<2, U, Q> const& v);

		template <typename U>
		constexpr vec<2, T, Q>& operator/=(U scalar);

		template <typename U>
		constexpr vec<2, T, Q>& operator/=(vec<1, U, Q> const& scalar);

		template <typename U>
		constexpr vec<2, T, Q>& operator/=(vec<2, U, Q> const& v);

		template <typename U>
		constexpr vec<2, T, Q>& operator%=(U scalar);

		template <typename U>
		constexpr vec<2, T, Q>& operator%=(vec<1, U, Q> const& scalar);

		template <typename U>
		constexpr vec<2, T, Q>& operator%=(vec<2, U, Q> const& v);

		/// Increment and Decrement Operators

		constexpr vec<2, T, Q>& operator++();

		constexpr vec<2, T, Q>& operator--();

		constexpr const vec<2, T, Q> operator++(int);

		constexpr const vec<2, T, Q> operator--(int);

		/// Bitwise Assignment Operators

		template <typename U>
		constexpr vec<2, T, Q>& operator&=(U scalar);

		template <typename U>
		constexpr vec<2, T, Q>& operator&=(vec<1, U, Q> const& scalar);

		template <typename U>
		constexpr vec<2, T, Q>& operator&=(vec<2, U, Q> const& v);

		template <typename U>
		constexpr vec<2, T, Q>& operator|=(U scalar);

		template <typename U>
		constexpr vec<2, T, Q>& operator|=(vec<1, U, Q> const& scalar);

		template <typename U>
		constexpr vec<2, T, Q>& operator|=(vec<2, U, Q> const& v);

		template <typename U>
		constexpr vec<2, T, Q>& operator^=(U scalar);

		template <typename U>
		constexpr vec<2, T, Q>& operator^=(vec<1, U, Q> const& scalar);

		template <typename U>
		constexpr vec<2, T, Q>& operator^=(vec<2, U, Q> const& v);

		template <typename U>
		constexpr vec<2, T, Q>& operator<<=(U scalar);

		template <typename U>
		constexpr vec<2, T, Q>& operator<<=(vec<1, U, Q> const& scalar);

		template <typename U>
		constexpr vec<2, T, Q>& operator<<=(vec<2, U, Q> const& v);

		template <typename U>
		constexpr vec<2, T, Q>& operator>>=(U scalar);

		template <typename U>
		constexpr vec<2, T, Q>& operator>>=(vec<1, U, Q> const& scalar);

		template <typename U>
		constexpr vec<2, T, Q>& operator>>=(vec<2, U, Q> const& v);


		/// Generic Function Declarations

		constexpr T length() const;

		constexpr T length_squared() const;

		constexpr void normalize();

		constexpr vec<2, T, Q> normalized() const;

		MIM_NODISCARD constexpr bool is_normalized() const;

		constexpr T distance(const vec<2, T, Q>& v) const;

		constexpr T distance_squared(const vec<2, T, Q>& v) const;


		/// Function Declarations

		constexpr T dot(const vec<2, T, Q>& v) const;

		constexpr T cross(const vec<2, T, Q>& v) const;

		vec<2, T, Q> rotated(T angle) const;

		constexpr vec<2, T, Q> clamp(const vec<2, T, Q>& min, const vec<2, T, Q>& max) const;

		constexpr vec<2, T, Q> reflect(const vec<2, T, Q>& normal) const;

		constexpr vec<2, T, Q> refract(const vec<2, T, Q>& normal, T eta) const;

		constexpr vec<2, T, Q> project(const vec<2, T, Q>& to) const;
	};

	/// Unary Operators

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator+(vec<2, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator-(vec<2, T, Q> const& v);

	/// Binary Operators
	// TODO: Decide if we should allow scalar operations on vec2 using vec3-4

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator+(vec<2, T, Q> const& v, T scalar);

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator+(T scalar, vec<2, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator+(vec<2, T, Q> const& v1, vec<2, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator+(vec<1, T, Q> const& v1, vec<2, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator+(vec<2, T, Q> const& v1, vec<1, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator-(vec<2, T, Q> const& v, T scalar);

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator-(T scalar, vec<2, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator-(vec<2, T, Q> const& v1, vec<2, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator-(vec<1, T, Q> const& v1, vec<2, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator-(vec<2, T, Q> const& v1, vec<1, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator*(vec<2, T, Q> const& v, T scalar);

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator*(T scalar, vec<2, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator*(vec<2, T, Q> const& v1, vec<2, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator*(vec<1, T, Q> const& v1, vec<2, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator*(vec<2, T, Q> const& v1, vec<1, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator/(vec<2, T, Q> const& v, T scalar);

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator/(T scalar, vec<2, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator/(vec<2, T, Q> const& v1, vec<2, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator/(vec<1, T, Q> const& v1, vec<2, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator/(vec<2, T, Q> const& v1, vec<1, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator%(vec<2, T, Q> const& v, T scalar);

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator%(T scalar, vec<2, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator%(vec<2, T, Q> const& v1, vec<2, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator%(vec<1, T, Q> const& v, vec<2, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator%(vec<2, T, Q> const& v1, vec<1, T, Q> const& v);

	/// Bitwise Binary Operators
	// TODO: Decide if we should allow bitwise operations on vec2 using vec3-4

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator&(vec<2, T, Q> const& v, T scalar);

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator&(T scalar, vec<2, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator&(vec<2, T, Q> const& v1, vec<2, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator&(vec<1, T, Q> const& v1, vec<2, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator&(vec<2, T, Q> const& v1, vec<1, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator|(vec<2, T, Q> const& v1, T scalar);

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator|(T scalar, vec<2, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator|(vec<2, T, Q> const& v1, vec<2, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator|(vec<1, T, Q> const& v1, vec<2, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator|(vec<2, T, Q> const& v1, vec<1, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator^(vec<2, T, Q> const& v1, T scalar);

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator^(T scalar, vec<2, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator^(vec<2, T, Q> const& v1, vec<2, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator^(vec<1, T, Q> const& v1, vec<2, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator^(vec<2, T, Q> const& v1, vec<1, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator<<(vec<2, T, Q> const& v, T scalar);

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator<<(T scalar, vec<2, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator<<(vec<2, T, Q> const& v1, vec<2, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator<<(vec<1, T, Q> const& v1, vec<2, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator<<(vec<2, T, Q> const& v1, vec<1, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator>>(vec<2, T, Q> const& v, T scalar);

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator>>(T scalar, vec<2, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator>>(vec<2, T, Q> const& v1, vec<2, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator>>(vec<1, T, Q> const& v1, vec<2, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator>>(vec<2, T, Q> const& v1, vec<1, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr vec<2, T, Q> operator~(vec<2, T, Q> const& v);

	/// Conditional operators

	template <typename T, qualifier Q>
	constexpr bool operator==(vec<2, T, Q> const& v1, vec<2, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr bool operator!=(vec<2, T, Q> const& v1, vec<2, T, Q> const& v2);

	template <qualifier Q>
	constexpr bool operator&&(vec<2, bool, Q> const& v1, vec<2, bool, Q> const& v2);

	template <qualifier Q>
	constexpr bool operator||(vec<2, bool, Q> const& v1, vec<2, bool, Q> const& v2);


} // namespace mim

#include "mim/detail/type/type_vector2.inl"
#include "mim/detail/func/func_vector2.inl"
