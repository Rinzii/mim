// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#pragma once

#include "mim/detail/defines.hpp"

namespace mim
{
	template <typename T>
	struct vec<2, T> {
		// Aliases

		using value_type = T;
		using type = vec<2, T>;
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

		// Constructors

		constexpr vec();

		constexpr vec(T _x, T _y);

		constexpr vec(vec const& v);

		constexpr explicit vec(T scalar);

		// U Template Constructors

		template <typename U>
		constexpr explicit vec(vec<1, U> const& scalar);

		template <typename U>
		constexpr explicit vec(vec<2, U> const& v);

		template <typename U>
		constexpr explicit vec(vec<3, U> const& v);

		template <typename U>
		constexpr explicit vec(vec<4, U> const& v);

		// AB Template Constructors

		template <typename A, typename B>
		constexpr explicit vec(A _x, B _y);

		template <typename A, typename B>
		constexpr vec(vec<1, A> const& _x, B _y);

		template <typename A, typename B>
		constexpr vec(A _x, vec<1, B> const& _y);

		template <typename A, typename B>
		constexpr vec(vec<1, A> const& _x, vec<1, B> const& _y);

		// Assignment Operators

		constexpr vec<2, T>& operator=(T scalar);

		constexpr vec<2, T>& operator=(vec<2, T> const& v);

		template <typename U>
		constexpr vec<2, T>& operator=(vec<1, U> const& scalar);

		template <typename U>
		constexpr vec<2, T>& operator=(vec<2, U> const& v);

		template <typename U>
		constexpr vec<2, T>& operator+=(U scalar);

		template <typename U>
		constexpr vec<2, T>& operator+=(vec<1, U> const& scalar);

		template <typename U>
		constexpr vec<2, T>& operator+=(vec<2, U> const& v);

		template <typename U>
		constexpr vec<2, T>& operator-=(U scalar);

		template <typename U>
		constexpr vec<2, T>& operator-=(vec<1, U> const& scalar);

		template <typename U>
		constexpr vec<2, T>& operator-=(vec<2, U> const& v);

		template <typename U>
		constexpr vec<2, T>& operator*=(U scalar);

		template <typename U>
		constexpr vec<2, T>& operator*=(vec<1, U> const& scalar);

		template <typename U>
		constexpr vec<2, T>& operator*=(vec<2, U> const& v);

		template <typename U>
		constexpr vec<2, T>& operator/=(U scalar);

		template <typename U>
		constexpr vec<2, T>& operator/=(vec<1, U> const& scalar);

		template <typename U>
		constexpr vec<2, T>& operator/=(vec<2, U> const& v);

		template <typename U>
		constexpr vec<2, T>& operator%=(U scalar);

		template <typename U>
		constexpr vec<2, T>& operator%=(vec<1, U> const& scalar);

		template <typename U>
		constexpr vec<2, T>& operator%=(vec<2, U> const& v);

		// Increment and Decrement Operators

		constexpr vec<2, T>& operator++();

		constexpr vec<2, T>& operator--();

		constexpr const vec<2, T> operator++(int);

		constexpr const vec<2, T> operator--(int);

		// Bitwise Assignment Operators

		template <typename U>
		constexpr vec<2, T>& operator&=(U scalar);

		template <typename U>
		constexpr vec<2, T>& operator&=(vec<1, U> const& scalar);

		template <typename U>
		constexpr vec<2, T>& operator&=(vec<2, U> const& v);

		template <typename U>
		constexpr vec<2, T>& operator|=(U scalar);

		template <typename U>
		constexpr vec<2, T>& operator|=(vec<1, U> const& scalar);

		template <typename U>
		constexpr vec<2, T>& operator|=(vec<2, U> const& v);

		template <typename U>
		constexpr vec<2, T>& operator^=(U scalar);

		template <typename U>
		constexpr vec<2, T>& operator^=(vec<1, U> const& scalar);

		template <typename U>
		constexpr vec<2, T>& operator^=(vec<2, U> const& v);

		template <typename U>
		constexpr vec<2, T>& operator<<=(U scalar);

		template <typename U>
		constexpr vec<2, T>& operator<<=(vec<1, U> const& scalar);

		template <typename U>
		constexpr vec<2, T>& operator<<=(vec<2, U> const& v);

		template <typename U>
		constexpr vec<2, T>& operator>>=(U scalar);

		template <typename U>
		constexpr vec<2, T>& operator>>=(vec<1, U> const& scalar);

		template <typename U>
		constexpr vec<2, T>& operator>>=(vec<2, U> const& v);


		// Function Declarations

		constexpr T length() const;

		constexpr T length_squared() const;

		constexpr void normalize();

		constexpr vec<2, T> normalized() const;

		MIM_NODISCARD constexpr bool is_normalized() const;

		constexpr T distance(const vec<2, T>& v) const;

		constexpr T distance_squared(const vec<2, T>& v) const;

		constexpr T dot(const vec<2, T>& v) const;

		constexpr vec<2, T> cross(const vec<2, T>& v) const;

		constexpr vec<2, T> hadamard(const vec<2, T>& v) const;

		vec<2, T> rotated(T angle) const;

		constexpr vec<2, T> clamp(const vec<2, T>& min, const vec<2, T>& max) const;

		constexpr vec<2, T> reflect(const vec<2, T>& normal) const;

		constexpr vec<2, T> refract(const vec<2, T>& normal, T eta) const;

		constexpr vec<2, T> project(const vec<2, T>& to) const;
	};

	/// Free operators

	// Unary Operators

	template <typename T>
	constexpr vec<2, T> operator+(vec<2, T> const& v);

	template <typename T>
	constexpr vec<2, T> operator-(vec<2, T> const& v);

	// Binary Operators
	// TODO: Decide if we should allow scalar operations on vec2 using vec3-4

	template <typename T>
	constexpr vec<2, T> operator+(vec<2, T> const& v, T scalar);

	template <typename T>
	constexpr vec<2, T> operator+(T scalar, vec<2, T> const& v);

	template <typename T>
	constexpr vec<2, T> operator+(vec<2, T> const& v1, vec<2, T> const& v2);

	template <typename T>
	constexpr vec<2, T> operator+(vec<1, T> const& v1, vec<2, T> const& v2);

	template <typename T>
	constexpr vec<2, T> operator+(vec<2, T> const& v1, vec<1, T> const& v);

	template <typename T>
	constexpr vec<2, T> operator-(vec<2, T> const& v, T scalar);

	template <typename T>
	constexpr vec<2, T> operator-(T scalar, vec<2, T> const& v);

	template <typename T>
	constexpr vec<2, T> operator-(vec<2, T> const& v1, vec<2, T> const& v2);

	template <typename T>
	constexpr vec<2, T> operator-(vec<1, T> const& v1, vec<2, T> const& v2);

	template <typename T>
	constexpr vec<2, T> operator-(vec<2, T> const& v1, vec<1, T> const& v2);

	template <typename T>
	constexpr vec<2, T> operator*(vec<2, T> const& v, T scalar);

	template <typename T>
	constexpr vec<2, T> operator*(T scalar, vec<2, T> const& v);

	template <typename T>
	constexpr vec<2, T> operator*(vec<2, T> const& v1, vec<2, T> const& v2);

	template <typename T>
	constexpr vec<2, T> operator*(vec<1, T> const& v1, vec<2, T> const& v2);

	template <typename T>
	constexpr vec<2, T> operator*(vec<2, T> const& v1, vec<1, T> const& v);

	template <typename T>
	constexpr vec<2, T> operator/(vec<2, T> const& v, T scalar);

	template <typename T>
	constexpr vec<2, T> operator/(T scalar, vec<2, T> const& v);

	template <typename T>
	constexpr vec<2, T> operator/(vec<2, T> const& v1, vec<2, T> const& v2);

	template <typename T>
	constexpr vec<2, T> operator/(vec<1, T> const& v1, vec<2, T> const& v2);

	template <typename T>
	constexpr vec<2, T> operator/(vec<2, T> const& v1, vec<1, T> const& v2);

	template <typename T>
	constexpr vec<2, T> operator%(vec<2, T> const& v, T scalar);

	template <typename T>
	constexpr vec<2, T> operator%(T scalar, vec<2, T> const& v);

	template <typename T>
	constexpr vec<2, T> operator%(vec<2, T> const& v1, vec<2, T> const& v2);

	template <typename T>
	constexpr vec<2, T> operator%(vec<1, T> const& v, vec<2, T> const& v2);

	template <typename T>
	constexpr vec<2, T> operator%(vec<2, T> const& v1, vec<1, T> const& v);

	// Bitwise Binary Operators
	// TODO: Decide if we should allow bitwise operations on vec2 using vec3-4

	template <typename T>
	constexpr vec<2, T> operator&(vec<2, T> const& v, T scalar);

	template <typename T>
	constexpr vec<2, T> operator&(T scalar, vec<2, T> const& v);

	template <typename T>
	constexpr vec<2, T> operator&(vec<2, T> const& v1, vec<2, T> const& v2);

	template <typename T>
	constexpr vec<2, T> operator&(vec<1, T> const& v1, vec<2, T> const& v2);

	template <typename T>
	constexpr vec<2, T> operator&(vec<2, T> const& v1, vec<1, T> const& v2);

	template <typename T>
	constexpr vec<2, T> operator|(vec<2, T> const& v1, T scalar);

	template <typename T>
	constexpr vec<2, T> operator|(T scalar, vec<2, T> const& v);

	template <typename T>
	constexpr vec<2, T> operator|(vec<2, T> const& v1, vec<2, T> const& v2);

	template <typename T>
	constexpr vec<2, T> operator|(vec<1, T> const& v1, vec<2, T> const& v2);

	template <typename T>
	constexpr vec<2, T> operator|(vec<2, T> const& v1, vec<1, T> const& v2);

	template <typename T>
	constexpr vec<2, T> operator^(vec<2, T> const& v1, T scalar);

	template <typename T>
	constexpr vec<2, T> operator^(T scalar, vec<2, T> const& v);

	template <typename T>
	constexpr vec<2, T> operator^(vec<2, T> const& v1, vec<2, T> const& v2);

	template <typename T>
	constexpr vec<2, T> operator^(vec<1, T> const& v1, vec<2, T> const& v2);

	template <typename T>
	constexpr vec<2, T> operator^(vec<2, T> const& v1, vec<1, T> const& v2);

	template <typename T>
	constexpr vec<2, T> operator<<(vec<2, T> const& v, T scalar);

	template <typename T>
	constexpr vec<2, T> operator<<(T scalar, vec<2, T> const& v);

	template <typename T>
	constexpr vec<2, T> operator<<(vec<2, T> const& v1, vec<2, T> const& v2);

	template <typename T>
	constexpr vec<2, T> operator<<(vec<1, T> const& v1, vec<2, T> const& v2);

	template <typename T>
	constexpr vec<2, T> operator<<(vec<2, T> const& v1, vec<1, T> const& v2);

	template <typename T>
	constexpr vec<2, T> operator>>(vec<2, T> const& v, T scalar);

	template <typename T>
	constexpr vec<2, T> operator>>(T scalar, vec<2, T> const& v);

	template <typename T>
	constexpr vec<2, T> operator>>(vec<2, T> const& v1, vec<2, T> const& v2);

	template <typename T>
	constexpr vec<2, T> operator>>(vec<1, T> const& v1, vec<2, T> const& v2);

	template <typename T>
	constexpr vec<2, T> operator>>(vec<2, T> const& v1, vec<1, T> const& v2);

	template <typename T>
	constexpr vec<2, T> operator~(vec<2, T> const& v);

	// Conditional operators

	template <typename T>
	constexpr bool operator==(vec<2, T> const& v1, vec<2, T> const& v2);

	template <typename T>
	constexpr bool operator!=(vec<2, T> const& v1, vec<2, T> const& v2);

	constexpr vec<2, bool> operator&&(vec<2, bool> const& v1, vec<2, bool> const& v2);

	constexpr vec<2, bool> operator||(vec<2, bool> const& v1, vec<2, bool> const& v2);

	/// Free functions

	template <typename T>
	constexpr T length(const vec<2, T>& v);

	template <typename T>
	constexpr T length_squared(const vec<2, T>& v);

	template <typename T>
	constexpr vec<2, T> normalized(const vec<2, T>& v);

	template <typename T>
	MIM_NODISCARD constexpr bool is_normalized(const vec<2, T>& v);

	template <typename T>
	constexpr T distance(const vec<2, T>& v1, const vec<2, T>& v2);

	template <typename T>
	constexpr T distance_squared(const vec<2, T>& v1, const vec<2, T>& v2);

	template <typename T>
	constexpr T dot(const vec<2, T>& v1, const vec<2, T>& v2);

	template <typename T>
	constexpr vec<2, T> cross(const vec<2, T>& v1, const vec<2, T>& v2);

	template <typename T>
	constexpr vec<2, T> hadamard(const vec<2, T>& v1, const vec<2, T>& v2);

	template <typename T>
	constexpr vec<2, T> rotated(const vec<2, T>& v, T angle);

	template <typename T>
	constexpr vec<2, T> clamp(const vec<2, T>& v, const vec<2, T>& min, const vec<2, T>& max);

	template <typename T>
	constexpr vec<2, T> reflect(const vec<2, T>& v, const vec<2, T>& normal);

	template <typename T>
	constexpr vec<2, T> refract(const vec<2, T>& v, const vec<2, T>& normal, T eta);

	template <typename T>
	constexpr vec<2, T> project(const vec<2, T>& v, const vec<2, T>& to);




} // namespace mim

#include "mim/detail/type/type_vector2.inl"
#include "mim/detail/func/func_vector2.inl"
