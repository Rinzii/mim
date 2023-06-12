// Copyright (c) 2023-Present Mim contributors (see LICENSE)

/// \ref core
/// \file mim/detail/type/type_vector1.hpp

#pragma once

#include <iostream>

#include "mim/detail/qualifier.hpp"

// I've decided a vec1 should be treated like a scalar as this appears to be a common
// convention in GLSL. This means that a vec1 can be implicitly converted to a scalar.

namespace mim
{
	template <typename T, qualifier Q>
	struct VectorT<1, T, Q> {
		/// Aliases

		using value_type = T;
		using type = VectorT<1, T, Q>;
		using size_type = size_t;
		static constexpr auto size_v = 1;

		/// Data
		T x;

		/// Element Accessors

		static constexpr std::size_t size() { return size_v; }

		constexpr T& operator[](std::size_t i);

		constexpr const T& operator[](std::size_t i) const;

		T& at(std::size_t i);

		const T& at(std::size_t i) const;

		// Much of this code uses as reference section 5.4.1 of the GLSL 1.30.08 specification

		/// Constructors

		constexpr VectorT();

		constexpr VectorT(VectorT<1, T, Q> const& v);

		constexpr explicit VectorT(T scalar);

		/// Template Constructors

		template <qualifier P>
		constexpr explicit VectorT(VectorT<1, T, P> const& v);

		template <typename U>
		constexpr explicit VectorT(U scalar);

		template <typename U, qualifier P>
		constexpr explicit VectorT(VectorT<1, U, P> const& v);

		template <typename U, qualifier P>
		constexpr explicit VectorT(VectorT<2, U, P> const& v);

		template <typename U, qualifier P>
		constexpr explicit VectorT(VectorT<3, U, P> const& v);

		template <typename U, qualifier P>
		constexpr explicit VectorT(VectorT<4, U, P> const& v);

		/// Assignment Operators

		constexpr VectorT<1, T, Q>& operator=(T scalar);

		constexpr VectorT<1, T, Q>& operator=(VectorT<1, T, Q> const& v);

		template <typename U>
		constexpr VectorT<1, T, Q>& operator=(VectorT<1, U, Q> const& v);

		template <typename U>
		constexpr VectorT<1, T, Q>& operator=(VectorT<2, U, Q> const& v);

		template <typename U>
		constexpr VectorT<1, T, Q>& operator=(VectorT<3, U, Q> const& v);

		template <typename U>
		constexpr VectorT<1, T, Q>& operator=(VectorT<4, U, Q> const& v);

		template <typename U>
		constexpr VectorT<1, T, Q>& operator+=(U scalar);

		template <typename U>
		constexpr VectorT<1, T, Q>& operator+=(VectorT<1, U, Q> const& v);

		template <typename U>
		constexpr VectorT<1, T, Q>& operator+=(VectorT<2, U, Q> const& v);

		template <typename U>
		constexpr VectorT<1, T, Q>& operator+=(VectorT<3, U, Q> const& v);

		template <typename U>
		constexpr VectorT<1, T, Q>& operator+=(VectorT<4, U, Q> const& v);

		template <typename U>
		constexpr VectorT<1, T, Q>& operator-=(U scalar);

		template <typename U>
		constexpr VectorT<1, T, Q>& operator-=(VectorT<1, U, Q> const& v);

		template <typename U>
		constexpr VectorT<1, T, Q>& operator-=(VectorT<2, U, Q> const& v);

		template <typename U>
		constexpr VectorT<1, T, Q>& operator-=(VectorT<3, U, Q> const& v);

		template <typename U>
		constexpr VectorT<1, T, Q>& operator-=(VectorT<4, U, Q> const& v);

		template <typename U>
		constexpr VectorT<1, T, Q>& operator*=(U scalar);

		template <typename U>
		constexpr VectorT<1, T, Q>& operator*=(VectorT<1, U, Q> const& v);

		template <typename U>
		constexpr VectorT<1, T, Q>& operator*=(VectorT<2, U, Q> const& v);

		template <typename U>
		constexpr VectorT<1, T, Q>& operator*=(VectorT<3, U, Q> const& v);

		template <typename U>
		constexpr VectorT<1, T, Q>& operator*=(VectorT<4, U, Q> const& v);

		template <typename U>
		constexpr VectorT<1, T, Q>& operator/=(U scalar);

		template <typename U>
		constexpr VectorT<1, T, Q>& operator/=(VectorT<1, U, Q> const& v);

		template <typename U>
		constexpr VectorT<1, T, Q>& operator/=(VectorT<2, U, Q> const& v);

		template <typename U>
		constexpr VectorT<1, T, Q>& operator/=(VectorT<3, U, Q> const& v);

		template <typename U>
		constexpr VectorT<1, T, Q>& operator/=(VectorT<4, U, Q> const& v);

		template <typename U>
		constexpr VectorT<1, T, Q>& operator%=(U scalar);

		template <typename U>
		constexpr VectorT<1, T, Q>& operator%=(VectorT<1, U, Q> const& v);

		/// Increment and Decrement Operators

		constexpr VectorT<1, T, Q>& operator++();

		constexpr VectorT<1, T, Q>& operator--();

		constexpr const VectorT<1, T, Q> operator++(int);

		constexpr const VectorT<1, T, Q> operator--(int);

		/// Bitwise Assignment Operators

		template <typename U>
		constexpr VectorT<1, T, Q>& operator&=(U scalar);

		template <typename U>
		constexpr VectorT<1, T, Q>& operator&=(VectorT<1, U, Q> const& v);

		template <typename U>
		constexpr VectorT<1, T, Q>& operator|=(U scalar);

		template <typename U>
		constexpr VectorT<1, T, Q>& operator|=(VectorT<1, U, Q> const& v);

		template <typename U>
		constexpr VectorT<1, T, Q>& operator^=(U scalar);

		template <typename U>
		constexpr VectorT<1, T, Q>& operator^=(VectorT<1, U, Q> const& v);

		template <typename U>
		constexpr VectorT<1, T, Q>& operator<<=(U scalar);

		template <typename U>
		constexpr VectorT<1, T, Q>& operator<<=(VectorT<1, U, Q> const& v);

		template <typename U>
		constexpr VectorT<1, T, Q>& operator>>=(U scalar);

		template <typename U>
		constexpr VectorT<1, T, Q>& operator>>=(VectorT<1, U, Q> const& v);

		/// Stream Implementation

		friend std::ostream& operator<<(std::ostream& os, VectorT<1, T, Q> const& v) { return os << "(" << v.x << ")"; }


		/// Function Declarations

		MIM_NODISCARD bool isfinite() const;
        VectorT<1, T, Q> sign() const;
		VectorT<1, T, Q> floor() const;
		VectorT<1, T, Q> ceil() const;
		VectorT<1, T, Q> round() const;
		VectorT<1, T, Q> min(const VectorT<1, T, Q>& v) const;
		VectorT<1, T, Q> max(const VectorT<1, T, Q>& v) const;

		T length() const;

		T length_squared() const;

		void normalize();

		VectorT<1, T, Q> normalized() const;

		MIM_NODISCARD bool is_normalized() const;

		T distance(const VectorT<1, T, Q>& v) const;

		T distance_squared(const VectorT<1, T, Q>& v) const;



	};

	/// Unary Operators

	template <typename T, qualifier Q>
	constexpr VectorT<1, T, Q> operator+(VectorT<1, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr VectorT<1, T, Q> operator-(VectorT<1, T, Q> const& v);

	/// Binary Operators

	template <typename T, qualifier Q>
	constexpr VectorT<1, T, Q> operator+(VectorT<1, T, Q> const& v, T scalar);

	template <typename T, qualifier Q>
	constexpr VectorT<1, T, Q> operator+(T scalar, VectorT<1, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr VectorT<1, T, Q> operator+(VectorT<1, T, Q> const& v1, VectorT<1, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<1, T, Q> operator-(VectorT<1, T, Q> const& v, T scalar);

	template <typename T, qualifier Q>
	constexpr VectorT<1, T, Q> operator-(T scalar, VectorT<1, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr VectorT<1, T, Q> operator-(VectorT<1, T, Q> const& v1, VectorT<1, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<1, T, Q> operator*(VectorT<1, T, Q> const& v, T scalar);

	template <typename T, qualifier Q>
	constexpr VectorT<1, T, Q> operator*(T scalar, VectorT<1, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr VectorT<1, T, Q> operator*(VectorT<1, T, Q> const& v1, VectorT<1, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<1, T, Q> operator/(VectorT<1, T, Q> const& v, T scalar);

	template <typename T, qualifier Q>
	constexpr VectorT<1, T, Q> operator/(T scalar, VectorT<1, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr VectorT<1, T, Q> operator/(VectorT<1, T, Q> const& v1, VectorT<1, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<1, T, Q> operator%(VectorT<1, T, Q> const& v, T scalar);

	template <typename T, qualifier Q>
	constexpr VectorT<1, T, Q> operator%(T scalar, VectorT<1, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr VectorT<1, T, Q> operator%(VectorT<1, T, Q> const& v1, VectorT<1, T, Q> const& v2);

	/// Bitwise Binary Operators

	template <typename T, qualifier Q>
	constexpr VectorT<1, T, Q> operator&(VectorT<1, T, Q> const& v, T scalar);

	template <typename T, qualifier Q>
	constexpr VectorT<1, T, Q> operator&(T scalar, VectorT<1, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr VectorT<1, T, Q> operator&(VectorT<1, T, Q> const& v1, VectorT<1, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<1, T, Q> operator|(VectorT<1, T, Q> const& v, T scalar);

	template <typename T, qualifier Q>
	constexpr VectorT<1, T, Q> operator|(T scalar, VectorT<1, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr VectorT<1, T, Q> operator|(VectorT<1, T, Q> const& v1, VectorT<1, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<1, T, Q> operator^(VectorT<1, T, Q> const& v, T scalar);

	template <typename T, qualifier Q>
	constexpr VectorT<1, T, Q> operator^(T scalar, VectorT<1, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr VectorT<1, T, Q> operator^(VectorT<1, T, Q> const& v1, VectorT<1, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<1, T, Q> operator<<(VectorT<1, T, Q> const& v, T scalar);

	template <typename T, qualifier Q>
	constexpr VectorT<1, T, Q> operator<<(T scalar, VectorT<1, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr VectorT<1, T, Q> operator<<(VectorT<1, T, Q> const& v1, VectorT<1, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<1, T, Q> operator>>(VectorT<1, T, Q> const& v, T scalar);

	template <typename T, qualifier Q>
	constexpr VectorT<1, T, Q> operator>>(T scalar, VectorT<1, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr VectorT<1, T, Q> operator>>(VectorT<1, T, Q> const& v1, VectorT<1, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<1, T, Q> operator~(VectorT<1, T, Q> const& v);

	/// Comparison Operators

	template <typename T, qualifier Q>
	constexpr bool operator==(VectorT<1, T, Q> const& v1, VectorT<1, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr bool operator!=(VectorT<1, T, Q> const& v1, VectorT<1, T, Q> const& v2);

	template <qualifier Q>
	constexpr bool operator&&(VectorT<1, bool, Q> const& v1, VectorT<1, bool, Q> const& v2);

	template <qualifier Q>
	constexpr bool operator||(VectorT<1, bool, Q> const& v1, VectorT<1, bool, Q> const& v2);


} // namespace mim

#include "mim/detail/type/type_vector1.inl"
#include "mim/detail/func/func_vector1.inl"
