// Copyright (c) 2023-Present Mim contributors (see LICENSE)

/// \ref core
/// \file mim/detail/type/type_vector1.hpp

#pragma once

#include "mim/detail/defines.hpp"

// I've decided a vec1 should be treated like a scalar as this appears to be a common
// convention in GLSL. This means that a vec1 can be implicitly converted to a scalar.

namespace mim
{
	template <typename T>
	struct vec<1, T> {
		// Aliases

		using value_type = T;
		using type = vec<1, T>;
		using size_type = size_t;
		static constexpr auto size_v = 1;

		// Data
		T x;

		// Element Accessors

		static constexpr std::size_t size() { return size_v; }

		constexpr T& operator[](std::size_t i);

		constexpr const T& operator[](std::size_t i) const;

		T& at(std::size_t i);

		const T& at(std::size_t i) const;


		// Constructors

		constexpr vec();

		constexpr vec(vec<1, T> const& v);

		constexpr explicit vec(T scalar);

		// Template Constructors

		template <typename U>
		constexpr explicit vec(U scalar);

		template <typename U>
		constexpr explicit vec(vec<1, U> const& v);

		template <typename U>
		constexpr explicit vec(vec<2, U> const& v);

		template <typename U>
		constexpr explicit vec(vec<3, U> const& v);

		template <typename U>
		constexpr explicit vec(vec<4, U> const& v);

		// Assignment Operators

		constexpr vec<1, T>& operator=(T scalar);

		constexpr vec<1, T>& operator=(vec<1, T> const& v);

		template <typename U>
		constexpr vec<1, T>& operator=(vec<1, U> const& v);

		template <typename U>
		constexpr vec<1, T>& operator=(vec<2, U> const& v);

		template <typename U>
		constexpr vec<1, T>& operator=(vec<3, U> const& v);

		template <typename U>
		constexpr vec<1, T>& operator=(vec<4, U> const& v);

		template <typename U>
		constexpr vec<1, T>& operator+=(U scalar);

		template <typename U>
		constexpr vec<1, T>& operator+=(vec<1, U> const& v);

		template <typename U>
		constexpr vec<1, T>& operator+=(vec<2, U> const& v);

		template <typename U>
		constexpr vec<1, T>& operator+=(vec<3, U> const& v);

		template <typename U>
		constexpr vec<1, T>& operator+=(vec<4, U> const& v);

		template <typename U>
		constexpr vec<1, T>& operator-=(U scalar);

		template <typename U>
		constexpr vec<1, T>& operator-=(vec<1, U> const& v);

		template <typename U>
		constexpr vec<1, T>& operator-=(vec<2, U> const& v);

		template <typename U>
		constexpr vec<1, T>& operator-=(vec<3, U> const& v);

		template <typename U>
		constexpr vec<1, T>& operator-=(vec<4, U> const& v);

		template <typename U>
		constexpr vec<1, T>& operator*=(U scalar);

		template <typename U>
		constexpr vec<1, T>& operator*=(vec<1, U> const& v);

		template <typename U>
		constexpr vec<1, T>& operator*=(vec<2, U> const& v);

		template <typename U>
		constexpr vec<1, T>& operator*=(vec<3, U> const& v);

		template <typename U>
		constexpr vec<1, T>& operator*=(vec<4, U> const& v);

		template <typename U>
		constexpr vec<1, T>& operator/=(U scalar);

		template <typename U>
		constexpr vec<1, T>& operator/=(vec<1, U> const& v);

		template <typename U>
		constexpr vec<1, T>& operator/=(vec<2, U> const& v);

		template <typename U>
		constexpr vec<1, T>& operator/=(vec<3, U> const& v);

		template <typename U>
		constexpr vec<1, T>& operator/=(vec<4, U> const& v);

		template <typename U>
		constexpr vec<1, T>& operator%=(U scalar);

		template <typename U>
		constexpr vec<1, T>& operator%=(vec<1, U> const& v);

		// Increment and Decrement Operators

		constexpr vec<1, T>& operator++();

		constexpr vec<1, T>& operator--();

		constexpr const vec<1, T> operator++(int);

		constexpr const vec<1, T> operator--(int);

		// Bitwise Assignment Operators

		template <typename U>
		constexpr vec<1, T>& operator&=(U scalar);

		template <typename U>
		constexpr vec<1, T>& operator&=(vec<1, U> const& v);

		template <typename U>
		constexpr vec<1, T>& operator|=(U scalar);

		template <typename U>
		constexpr vec<1, T>& operator|=(vec<1, U> const& v);

		template <typename U>
		constexpr vec<1, T>& operator^=(U scalar);

		template <typename U>
		constexpr vec<1, T>& operator^=(vec<1, U> const& v);

		template <typename U>
		constexpr vec<1, T>& operator<<=(U scalar);

		template <typename U>
		constexpr vec<1, T>& operator<<=(vec<1, U> const& v);

		template <typename U>
		constexpr vec<1, T>& operator>>=(U scalar);

		template <typename U>
		constexpr vec<1, T>& operator>>=(vec<1, U> const& v);


		// Function Declarations

		constexpr T length() const;

		constexpr T length_squared() const;

		constexpr void normalize();

		constexpr vec<1, T> normalized() const;

		MIM_NODISCARD constexpr bool is_normalized() const;

		constexpr T distance(const vec<1, T>& v) const;

		constexpr T distance_squared(const vec<1, T>& v) const;

		constexpr vec<1, T> hadamard(const vec<1, T>& v) const;



	};

	/// Free operators

	// Unary Operators

	template <typename T>
	constexpr vec<1, T> operator+(vec<1, T> const& v);

	template <typename T>
	constexpr vec<1, T> operator-(vec<1, T> const& v);

	// Binary Operators

	template <typename T>
	constexpr vec<1, T> operator+(vec<1, T> const& v, T scalar);

	template <typename T>
	constexpr vec<1, T> operator+(T scalar, vec<1, T> const& v);

	template <typename T>
	constexpr vec<1, T> operator+(vec<1, T> const& v1, vec<1, T> const& v2);

	template <typename T>
	constexpr vec<1, T> operator-(vec<1, T> const& v, T scalar);

	template <typename T>
	constexpr vec<1, T> operator-(T scalar, vec<1, T> const& v);

	template <typename T>
	constexpr vec<1, T> operator-(vec<1, T> const& v1, vec<1, T> const& v2);

	template <typename T>
	constexpr vec<1, T> operator*(vec<1, T> const& v, T scalar);

	template <typename T>
	constexpr vec<1, T> operator*(T scalar, vec<1, T> const& v);

	template <typename T>
	constexpr vec<1, T> operator*(vec<1, T> const& v1, vec<1, T> const& v2);

	template <typename T>
	constexpr vec<1, T> operator/(vec<1, T> const& v, T scalar);

	template <typename T>
	constexpr vec<1, T> operator/(T scalar, vec<1, T> const& v);

	template <typename T>
	constexpr vec<1, T> operator/(vec<1, T> const& v1, vec<1, T> const& v2);

	template <typename T>
	constexpr vec<1, T> operator%(vec<1, T> const& v, T scalar);

	template <typename T>
	constexpr vec<1, T> operator%(T scalar, vec<1, T> const& v);

	template <typename T>
	constexpr vec<1, T> operator%(vec<1, T> const& v1, vec<1, T> const& v2);

	// Bitwise Binary Operators

	template <typename T>
	constexpr vec<1, T> operator&(vec<1, T> const& v, T scalar);

	template <typename T>
	constexpr vec<1, T> operator&(T scalar, vec<1, T> const& v);

	template <typename T>
	constexpr vec<1, T> operator&(vec<1, T> const& v1, vec<1, T> const& v2);

	template <typename T>
	constexpr vec<1, T> operator|(vec<1, T> const& v, T scalar);

	template <typename T>
	constexpr vec<1, T> operator|(T scalar, vec<1, T> const& v);

	template <typename T>
	constexpr vec<1, T> operator|(vec<1, T> const& v1, vec<1, T> const& v2);

	template <typename T>
	constexpr vec<1, T> operator^(vec<1, T> const& v, T scalar);

	template <typename T>
	constexpr vec<1, T> operator^(T scalar, vec<1, T> const& v);

	template <typename T>
	constexpr vec<1, T> operator^(vec<1, T> const& v1, vec<1, T> const& v2);

	template <typename T>
	constexpr vec<1, T> operator<<(vec<1, T> const& v, T scalar);

	template <typename T>
	constexpr vec<1, T> operator<<(T scalar, vec<1, T> const& v);

	template <typename T>
	constexpr vec<1, T> operator<<(vec<1, T> const& v1, vec<1, T> const& v2);

	template <typename T>
	constexpr vec<1, T> operator>>(vec<1, T> const& v, T scalar);

	template <typename T>
	constexpr vec<1, T> operator>>(T scalar, vec<1, T> const& v);

	template <typename T>
	constexpr vec<1, T> operator>>(vec<1, T> const& v1, vec<1, T> const& v2);

	template <typename T>
	constexpr vec<1, T> operator~(vec<1, T> const& v);

	// Comparison Operators

	template <typename T>
	constexpr bool operator==(vec<1, T> const& v1, vec<1, T> const& v2);

	template <typename T>
	constexpr bool operator!=(vec<1, T> const& v1, vec<1, T> const& v2);

	constexpr vec<1, bool> operator&&(vec<1, bool> const& v1, vec<1, bool> const& v2);

	constexpr vec<1, bool> operator||(vec<1, bool> const& v1, vec<1, bool> const& v2);


	/// Free functions

	template <typename T>
	constexpr T length(vec<1, T> const& v);

	template <typename T>
	constexpr T length_squared(vec<1, T> const& v);

	template <typename T>
	constexpr vec<1, T> normalized(vec<1, T> const& v);

	template <typename T>
	MIM_NODISCARD constexpr bool is_normalized(vec<1, T> const& v);

	template <typename T>
	constexpr T distance(vec<1, T> const& v1, vec<1, T> const& v2);

	template <typename T>
	constexpr T distance_squared(vec<1, T> const& v1, vec<1, T> const& v2);

	template <typename T>
	constexpr vec<1, T> hadamard(vec<1, T> const& v1, vec<1, T> const& v2);

} // namespace mim

#include "mim/detail/type/type_vector1.inl"
#include "mim/detail/func/func_vector1.inl"
