// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#pragma once

#include <iostream>
#include "mim/detail/qualifier.hpp"

namespace mim
{

	template <typename T, qualifier Q>
	struct VectorT<3, T, Q> {
		using value_type = T;
		using type = VectorT<3, T, Q>;
		using size_type = size_t;
		static constexpr auto size_v = 3;

		// Data
		T x, y, z;

		static constexpr size_type size() { return size_v; }

		constexpr T& operator[](size_type i);
		constexpr T const& operator[](size_type i) const;

		// Many of these constructors use as reference section 5.4.1 of the GLSL 1.30.08 specification

		/// Constructors

		constexpr VectorT();

		constexpr VectorT(T _x, T _y, T _z);

		constexpr VectorT(VectorT<3, T, Q> const& v);

		constexpr explicit VectorT(T scalar);

		/// Template Constructors

		template <qualifier P>
		constexpr explicit VectorT(VectorT<3, T, P> const& v);

		// U Template Constructors

		template <typename U, qualifier P>
		constexpr explicit VectorT(VectorT<1, U, P> const& scalar);

		template <typename U, qualifier P>
		constexpr explicit VectorT(VectorT<3, U, P> const& v);

		// XYZ Template Constructors

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

		// AB Template Constructors

		template <typename A, typename B, qualifier P>
		constexpr VectorT(VectorT<2, A, P> const& _xy, B _z);

		template <typename A, typename B, qualifier P>
		constexpr VectorT(A _x, VectorT<2, B, P> const& _yz);

		template <typename A, typename B, qualifier P>
		constexpr VectorT(VectorT<2, A, P> const& _xy, VectorT<1, B, P> const& _z);

		template <typename A, typename B, qualifier P>
		constexpr VectorT(VectorT<1, A, P> const& _x, VectorT<2, B, P> const& _yz);

		/// Assignment Operators

		constexpr VectorT<3, T, Q>& operator=(T scalar);

		constexpr VectorT<3, T, Q>& operator=(VectorT<3, T, Q> const& v);

		template <typename U>
		constexpr VectorT<3, T, Q>& operator=(VectorT<1, U, Q> const& scalar);

		template <typename U>
		constexpr VectorT<3, T, Q>& operator=(VectorT<3, U, Q> const& v);

		template <typename U>
		constexpr VectorT<3, T, Q>& operator+=(U scalar);

		template <typename U>
		constexpr VectorT<3, T, Q>& operator+=(VectorT<1, U, Q> const& v);

		template <typename U>
		constexpr VectorT<3, T, Q>& operator+=(VectorT<3, U, Q> const& v);

		template <typename U>
		constexpr VectorT<3, T, Q>& operator-=(U scalar);

		template <typename U>
		constexpr VectorT<3, T, Q>& operator-=(VectorT<1, U, Q> const& scalar);

		template <typename U>
		constexpr VectorT<3, T, Q>& operator-=(VectorT<3, U, Q> const& v);

		template <typename U>
		constexpr VectorT<3, T, Q>& operator*=(U scalar);

		template <typename U>
		constexpr VectorT<3, T, Q>& operator*=(VectorT<1, U, Q> const& v);

		template <typename U>
		constexpr VectorT<3, T, Q>& operator*=(VectorT<3, U, Q> const& v);

		template <typename U>
		constexpr VectorT<3, T, Q>& operator/=(U scalar);

		template <typename U>
		constexpr VectorT<3, T, Q>& operator/=(VectorT<1, U, Q> const& v);

		template <typename U>
		constexpr VectorT<3, T, Q>& operator/=(VectorT<3, U, Q> const& v);

		template <typename U>
		constexpr VectorT<3, T, Q>& operator%=(U scalar);

		template <typename U>
		constexpr VectorT<3, T, Q>& operator%=(VectorT<1, U, Q> const& v);

		template <typename U>
		constexpr VectorT<3, T, Q>& operator%=(VectorT<3, U, Q> const& v);

		/// Increment and Decrement Operators

		constexpr VectorT<3, T, Q>& operator++();

		constexpr VectorT<3, T, Q>& operator--();

		constexpr const VectorT<3, T, Q> operator++(int);

		constexpr const VectorT<3, T, Q> operator--(int);

		/// Bitwise Assignment Operators

		template <typename U>
		constexpr VectorT<3, T, Q>& operator&=(U scalar);

		template <typename U>
		constexpr VectorT<3, T, Q>& operator&=(VectorT<1, U, Q> const& v);

		template <typename U>
		constexpr VectorT<3, T, Q>& operator&=(VectorT<3, U, Q> const& v);

		template <typename U>
		constexpr VectorT<3, T, Q>& operator|=(U scalar);

		template <typename U>
		constexpr VectorT<3, T, Q>& operator|=(VectorT<1, U, Q> const& v);

		template <typename U>
		constexpr VectorT<3, T, Q>& operator|=(VectorT<3, U, Q> const& v);

		template <typename U>
		constexpr VectorT<3, T, Q>& operator^=(U scalar);

		template <typename U>
		constexpr VectorT<3, T, Q>& operator^=(VectorT<1, U, Q> const& v);

		template <typename U>
		constexpr VectorT<3, T, Q>& operator^=(VectorT<3, U, Q> const& v);

		template <typename U>
		constexpr VectorT<3, T, Q>& operator<<=(U scalar);

		template <typename U>
		constexpr VectorT<3, T, Q>& operator<<=(VectorT<1, U, Q> const& v);

		template <typename U>
		constexpr VectorT<3, T, Q>& operator<<=(VectorT<3, U, Q> const& v);

		template <typename U>
		constexpr VectorT<3, T, Q>& operator>>=(U scalar);

		template <typename U>
		constexpr VectorT<3, T, Q>& operator>>=(VectorT<1, U, Q> const& v);

		template <typename U>
		constexpr VectorT<3, T, Q>& operator>>=(VectorT<3, U, Q> const& v);

		/// Stream Implementation

		friend std::ostream& operator<<(std::ostream& os, VectorT<3, T, Q> const& v) { return os << "(" << v.x << ", " << v.y << ", " << v.z << ")"; }


		/// Generic Function Declarations

		MIM_NODISCARD bool isfinite() const;
		VectorT<3, T, Q> sign() const;
		VectorT<3, T, Q> floor() const;
		VectorT<3, T, Q> ceil() const;
		VectorT<3, T, Q> round() const;
		VectorT<3, T, Q> min(const VectorT<3, T, Q>& v) const;
		VectorT<3, T, Q> max(const VectorT<3, T, Q>& v) const;

		T length() const;

		T length_squared() const;

		void normalize();

		VectorT<3, T, Q> normalized() const;

		MIM_NODISCARD bool is_normalized() const;

		T distance(const VectorT<3, T, Q>& v) const;

		T distance_squared(const VectorT<3, T, Q>& v) const;


		/// Function Declarations

		T dot(const VectorT<3, T, Q>& v) const;
		T cross(const VectorT<3, T, Q>& v) const;
		void rotate(T angle);
		VectorT<3, T, Q> rotated(T angle) const;
		VectorT<3, T, Q> clamp(const VectorT<3, T, Q>& min, const VectorT<3, T, Q>& max) const;
		VectorT<3, T, Q> reflect(const VectorT<3, T, Q>& normal) const;
		VectorT<3, T, Q> refract(const VectorT<3, T, Q>& normal, T eta) const;
		VectorT<3, T, Q> project(const VectorT<3, T, Q>& normal) const;

	};

	/// Unary Operators

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> operator+(VectorT<3, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> operator-(VectorT<3, T, Q> const& v);

	/// Binary Operators

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> operator+(VectorT<3, T, Q> const& v, T scalar);

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> operator+(VectorT<3, T, Q> const& v1, VectorT<1, T, Q> const& sv);

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> operator+(T scalar, VectorT<3, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> operator+(VectorT<1, T, Q> const& sv, VectorT<3, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> operator+(VectorT<3, T, Q> const& v1, VectorT<3, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> operator-(VectorT<3, T, Q> const& v, T scalar);

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> operator-(VectorT<3, T, Q> const& v1, VectorT<1, T, Q> const& sv);

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> operator-(T scalar, VectorT<3, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> operator-(VectorT<1, T, Q> const& sv, VectorT<3, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> operator-(VectorT<3, T, Q> const& v1, VectorT<3, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> operator*(VectorT<3, T, Q> const& v, T scalar);

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> operator*(VectorT<3, T, Q> const& v1, VectorT<1, T, Q> const& sv);

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> operator*(T scalar, VectorT<3, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> operator*(VectorT<1, T, Q> const& sv, VectorT<3, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> operator*(VectorT<3, T, Q> const& v1, VectorT<3, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> operator/(VectorT<3, T, Q> const& v, T scalar);

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> operator/(VectorT<3, T, Q> const& v1, VectorT<1, T, Q> const& sv);

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> operator/(T scalar, VectorT<3, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> operator/(VectorT<1, T, Q> const& sv, VectorT<3, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> operator/(VectorT<3, T, Q> const& v1, VectorT<3, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> operator%(VectorT<3, T, Q> const& v, T scalar);

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> operator%(VectorT<3, T, Q> const& v1, VectorT<1, T, Q> const& sv);

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> operator%(T scalar, VectorT<3, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> operator%(VectorT<1, T, Q> const& sv, VectorT<3, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> operator%(VectorT<3, T, Q> const& v1, VectorT<3, T, Q> const& v2);

	/// Bitwise Binary Operators

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> operator&(VectorT<3, T, Q> const& v, T scalar);

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> operator&(VectorT<3, T, Q> const& v1, VectorT<1, T, Q> const& sv);

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> operator&(T scalar, VectorT<3, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> operator&(VectorT<1, T, Q> const& sv, VectorT<3, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> operator&(VectorT<3, T, Q> const& v1, VectorT<3, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> operator|(VectorT<3, T, Q> const& v, T scalar);

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> operator|(VectorT<3, T, Q> const& v1, VectorT<1, T, Q> const& sv);

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> operator|(T scalar, VectorT<3, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> operator|(VectorT<1, T, Q> const& sv, VectorT<3, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> operator|(VectorT<3, T, Q> const& v1, VectorT<3, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> operator^(VectorT<3, T, Q> const& v, T scalar);

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> operator^(VectorT<3, T, Q> const& v1, VectorT<1, T, Q> const& sv);

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> operator^(T scalar, VectorT<3, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> operator^(VectorT<1, T, Q> const& sv, VectorT<3, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> operator^(VectorT<3, T, Q> const& v1, VectorT<3, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> operator<<(VectorT<3, T, Q> const& v, T scalar);

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> operator<<(VectorT<3, T, Q> const& v1, VectorT<1, T, Q> const& sv);

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> operator<<(T scalar, VectorT<3, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> operator<<(VectorT<1, T, Q> const& sv, VectorT<3, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> operator<<(VectorT<3, T, Q> const& v1, VectorT<3, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> operator>>(VectorT<3, T, Q> const& v, T scalar);

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> operator>>(VectorT<3, T, Q> const& v1, VectorT<1, T, Q> const& sv);

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> operator>>(T scalar, VectorT<3, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> operator>>(VectorT<1, T, Q> const& sv, VectorT<3, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> operator>>(VectorT<3, T, Q> const& v1, VectorT<3, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<3, T, Q> operator~(VectorT<3, T, Q> const& v);

	/// Conditional Operators

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
#include "mim/detail/func/func_vector3.inl"
