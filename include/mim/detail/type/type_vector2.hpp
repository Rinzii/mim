// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#pragma once

#include "mim/detail/qualifier.hpp"

namespace mim
{
	template <typename T, qualifier Q>
	struct VectorT<2, T, Q> {
		// Aliases

		using value_type = T;
		using type = VectorT<2, T, Q>;
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

		constexpr VectorT();

		constexpr VectorT(T _x, T _y);

		constexpr VectorT(VectorT const& v);

		constexpr explicit VectorT(T scalar);

		/// Template Constructors

		template <qualifier P>
		constexpr explicit VectorT(VectorT<2, T, P> const& v);

		// U Template Constructors

		template <typename U, qualifier P>
		constexpr explicit VectorT(VectorT<1, U, P> const& scalar);

		template <typename U, qualifier P>
		constexpr explicit VectorT(VectorT<2, U, P> const& v);

		template <typename U, qualifier P>
		constexpr explicit VectorT(VectorT<3, U, P> const& v);

		template <typename U, qualifier P>
		constexpr explicit VectorT(VectorT<4, U, P> const& v);

		// AB Template Constructors

		template <typename A, typename B>
		constexpr explicit VectorT(A _x, B _y);

		template <typename A, typename B>
		constexpr VectorT(VectorT<1, A, Q> const& _x, B _y);

		template <typename A, typename B>
		constexpr VectorT(A _x, VectorT<1, B, Q> const& _y);

		template <typename A, typename B>
		constexpr VectorT(VectorT<1, A, Q> const& _x, VectorT<1, B, Q> const& _y);

		/// Assignment Operators

		constexpr VectorT<2, T, Q>& operator=(T scalar);

		constexpr VectorT<2, T, Q>& operator=(VectorT<2, T, Q> const& v);

		template <typename U>
		constexpr VectorT<2, T, Q>& operator=(VectorT<1, U, Q> const& scalar);

		template <typename U>
		constexpr VectorT<2, T, Q>& operator=(VectorT<2, U, Q> const& v);

		template <typename U>
		constexpr VectorT<2, T, Q>& operator+=(U scalar);

		template <typename U>
		constexpr VectorT<2, T, Q>& operator+=(VectorT<1, U, Q> const& scalar);

		template <typename U>
		constexpr VectorT<2, T, Q>& operator+=(VectorT<2, U, Q> const& v);

		template <typename U>
		constexpr VectorT<2, T, Q>& operator-=(U scalar);

		template <typename U>
		constexpr VectorT<2, T, Q>& operator-=(VectorT<1, U, Q> const& scalar);

		template <typename U>
		constexpr VectorT<2, T, Q>& operator-=(VectorT<2, U, Q> const& v);

		template <typename U>
		constexpr VectorT<2, T, Q>& operator*=(U scalar);

		template <typename U>
		constexpr VectorT<2, T, Q>& operator*=(VectorT<1, U, Q> const& scalar);

		template <typename U>
		constexpr VectorT<2, T, Q>& operator*=(VectorT<2, U, Q> const& v);

		template <typename U>
		constexpr VectorT<2, T, Q>& operator/=(U scalar);

		template <typename U>
		constexpr VectorT<2, T, Q>& operator/=(VectorT<1, U, Q> const& scalar);

		template <typename U>
		constexpr VectorT<2, T, Q>& operator/=(VectorT<2, U, Q> const& v);

		template <typename U>
		constexpr VectorT<2, T, Q>& operator%=(U scalar);

		template <typename U>
		constexpr VectorT<2, T, Q>& operator%=(VectorT<1, U, Q> const& scalar);

		template <typename U>
		constexpr VectorT<2, T, Q>& operator%=(VectorT<2, U, Q> const& v);

		/// Increment and Decrement Operators

		constexpr VectorT<2, T, Q>& operator++();

		constexpr VectorT<2, T, Q>& operator--();

		constexpr const VectorT<2, T, Q> operator++(int);

		constexpr const VectorT<2, T, Q> operator--(int);

		/// Bitwise Assignment Operators

		template <typename U>
		constexpr VectorT<2, T, Q>& operator&=(U scalar);

		template <typename U>
		constexpr VectorT<2, T, Q>& operator&=(VectorT<1, U, Q> const& scalar);

		template <typename U>
		constexpr VectorT<2, T, Q>& operator&=(VectorT<2, U, Q> const& v);

		template <typename U>
		constexpr VectorT<2, T, Q>& operator|=(U scalar);

		template <typename U>
		constexpr VectorT<2, T, Q>& operator|=(VectorT<1, U, Q> const& scalar);

		template <typename U>
		constexpr VectorT<2, T, Q>& operator|=(VectorT<2, U, Q> const& v);

		template <typename U>
		constexpr VectorT<2, T, Q>& operator^=(U scalar);

		template <typename U>
		constexpr VectorT<2, T, Q>& operator^=(VectorT<1, U, Q> const& scalar);

		template <typename U>
		constexpr VectorT<2, T, Q>& operator^=(VectorT<2, U, Q> const& v);

		template <typename U>
		constexpr VectorT<2, T, Q>& operator<<=(U scalar);

		template <typename U>
		constexpr VectorT<2, T, Q>& operator<<=(VectorT<1, U, Q> const& scalar);

		template <typename U>
		constexpr VectorT<2, T, Q>& operator<<=(VectorT<2, U, Q> const& v);

		template <typename U>
		constexpr VectorT<2, T, Q>& operator>>=(U scalar);

		template <typename U>
		constexpr VectorT<2, T, Q>& operator>>=(VectorT<1, U, Q> const& scalar);

		template <typename U>
		constexpr VectorT<2, T, Q>& operator>>=(VectorT<2, U, Q> const& v);


		/// Generic Function Declarations

		MIM_NODISCARD constexpr bool isfinite() const;
		constexpr VectorT<2, T, Q> sign() const;
		constexpr VectorT<2, T, Q> floor() const;
		constexpr VectorT<2, T, Q> ceil() const;
		constexpr VectorT<2, T, Q> round() const;
		constexpr VectorT<2, T, Q> min(const VectorT<2, T, Q>& v) const;
		constexpr VectorT<2, T, Q> max(const VectorT<2, T, Q>& v) const;

		constexpr T length() const;

		constexpr T length_squared() const;

		constexpr void normalize();

		constexpr VectorT<2, T, Q> normalized() const;

		MIM_NODISCARD constexpr bool is_normalized() const;

		constexpr T distance(const VectorT<2, T, Q>& v) const;

		constexpr T distance_squared(const VectorT<2, T, Q>& v) const;


		/// Function Declarations

		constexpr T dot(const VectorT<2, T, Q>& v) const;

		constexpr T cross(const VectorT<2, T, Q>& v) const;

		constexpr VectorT<2, T, Q> rotated(T angle) const;

		constexpr VectorT<2, T, Q> clamp(const VectorT<2, T, Q>& min, const VectorT<2, T, Q>& max) const;

		constexpr VectorT<2, T, Q> reflect(const VectorT<2, T, Q>& normal) const;

		constexpr VectorT<2, T, Q> refract(const VectorT<2, T, Q>& normal, T eta) const;

		constexpr VectorT<2, T, Q> project(const VectorT<2, T, Q>& normal) const;
	};

	/// Unary Operators

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator+(VectorT<2, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator-(VectorT<2, T, Q> const& v);

	/// Binary Operators
	// TODO: Decide if we should allow scalar operations on vec2 using vec3-4

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator+(VectorT<2, T, Q> const& v, T scalar);

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator+(T scalar, VectorT<2, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator+(VectorT<2, T, Q> const& v1, VectorT<2, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator+(VectorT<1, T, Q> const& v1, VectorT<2, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator+(VectorT<2, T, Q> const& v1, VectorT<1, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator-(VectorT<2, T, Q> const& v, T scalar);

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator-(T scalar, VectorT<2, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator-(VectorT<2, T, Q> const& v1, VectorT<2, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator-(VectorT<1, T, Q> const& v1, VectorT<2, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator-(VectorT<2, T, Q> const& v1, VectorT<1, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator*(VectorT<2, T, Q> const& v, T scalar);

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator*(T scalar, VectorT<2, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator*(VectorT<2, T, Q> const& v1, VectorT<2, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator*(VectorT<1, T, Q> const& v1, VectorT<2, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator*(VectorT<2, T, Q> const& v1, VectorT<1, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator/(VectorT<2, T, Q> const& v, T scalar);

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator/(T scalar, VectorT<2, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator/(VectorT<2, T, Q> const& v1, VectorT<2, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator/(VectorT<1, T, Q> const& v1, VectorT<2, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator/(VectorT<2, T, Q> const& v1, VectorT<1, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator%(VectorT<2, T, Q> const& v, T scalar);

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator%(T scalar, VectorT<2, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator%(VectorT<2, T, Q> const& v1, VectorT<2, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator%(VectorT<1, T, Q> const& v, VectorT<2, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator%(VectorT<2, T, Q> const& v1, VectorT<1, T, Q> const& v);

	/// Bitwise Binary Operators
	// TODO: Decide if we should allow bitwise operations on vec2 using vec3-4

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator&(VectorT<2, T, Q> const& v, T scalar);

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator&(T scalar, VectorT<2, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator&(VectorT<2, T, Q> const& v1, VectorT<2, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator&(VectorT<1, T, Q> const& v1, VectorT<2, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator&(VectorT<2, T, Q> const& v1, VectorT<1, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator|(VectorT<2, T, Q> const& v1, T scalar);

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator|(T scalar, VectorT<2, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator|(VectorT<2, T, Q> const& v1, VectorT<2, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator|(VectorT<1, T, Q> const& v1, VectorT<2, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator|(VectorT<2, T, Q> const& v1, VectorT<1, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator^(VectorT<2, T, Q> const& v1, T scalar);

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator^(T scalar, VectorT<2, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator^(VectorT<2, T, Q> const& v1, VectorT<2, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator^(VectorT<1, T, Q> const& v1, VectorT<2, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator^(VectorT<2, T, Q> const& v1, VectorT<1, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator<<(VectorT<2, T, Q> const& v, T scalar);

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator<<(T scalar, VectorT<2, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator<<(VectorT<2, T, Q> const& v1, VectorT<2, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator<<(VectorT<1, T, Q> const& v1, VectorT<2, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator<<(VectorT<2, T, Q> const& v1, VectorT<1, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator>>(VectorT<2, T, Q> const& v, T scalar);

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator>>(T scalar, VectorT<2, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator>>(VectorT<2, T, Q> const& v1, VectorT<2, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator>>(VectorT<1, T, Q> const& v1, VectorT<2, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator>>(VectorT<2, T, Q> const& v1, VectorT<1, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<2, T, Q> operator~(VectorT<2, T, Q> const& v);

	/// Conditional operators

	template <typename T, qualifier Q>
	constexpr bool operator==(VectorT<2, T, Q> const& v1, VectorT<2, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr bool operator!=(VectorT<2, T, Q> const& v1, VectorT<2, T, Q> const& v2);

	template <qualifier Q>
	constexpr bool operator&&(VectorT<2, bool, Q> const& v1, VectorT<2, bool, Q> const& v2);

	template <qualifier Q>
	constexpr bool operator||(VectorT<2, bool, Q> const& v1, VectorT<2, bool, Q> const& v2);


} // namespace mim

#include "mim/detail/type/type_vector2.inl"
#include "mim/detail/func/func_vector2.inl"
