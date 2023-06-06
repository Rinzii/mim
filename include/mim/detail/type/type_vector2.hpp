// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#pragma once

#include <iostream>
#include "mim/detail/qualifier.hpp"

namespace mim {

template <typename T, qualifier Q>
struct VectorT<2, T, Q> {
	using value_type = T;
	using type = VectorT<2, T, Q>;
	using bool_type = VectorT<2, bool, Q>;
	using size_type = size_t;
	static constexpr auto size_v = 2;

	union {
		// This anonymous struct is only for syntactic sugar.
		struct {
			T x, y;
		};

		typename detail::Storage<2, T, detail::IsAligned<Q>::value>::type data;
	};

	static constexpr std::size_t size() { return size_v; }

	constexpr T& operator[](std::size_t i);
	constexpr T const& operator[](std::size_t i) const;

	// Many of these constructors use as reference section 5.4.1 of the GLSL 1.30.08 specification

	constexpr VectorT();
	constexpr VectorT(VectorT const& v);

	template <qualifier P>
	constexpr explicit VectorT(VectorT<2, T, P> const& v);

	constexpr explicit VectorT(T scalar);
	constexpr VectorT(T x, T y);

	template <typename U, qualifier P>
	constexpr explicit VectorT(VectorT<1, U, P> const& v);

	template <typename A, typename B>
	constexpr explicit VectorT(A x, B y);
	template <typename A, typename B>
	constexpr VectorT(VectorT<1, A, Q> const& v1, B y);
	template <typename A, typename B>
	constexpr VectorT(A x, VectorT<1, B, Q> const& y);
	template <typename A, typename B>
	constexpr VectorT(VectorT<1, A, Q> const& x, VectorT<1, B, Q> const& y);

	template <typename U, qualifier P>
	constexpr explicit VectorT(VectorT<2, U, P> const& v);
	template <typename U, qualifier P>
	constexpr explicit VectorT(VectorT<3, U, P> const& v);
	template <typename U, qualifier P>
	constexpr explicit VectorT(VectorT<4, U, P> const& v);

	constexpr VectorT<2, T, Q>& operator=(VectorT const& v) = default;

	template <typename U>
	constexpr VectorT<2, T, Q>& operator=(VectorT<2, U, Q> const& v);

	template <typename U>
	constexpr VectorT<2, T, Q>& operator+=(U scalar);
	template <typename U>
	constexpr VectorT<2, T, Q>& operator+=(VectorT<1, U, Q> const& v);
	template <typename U>
	constexpr VectorT<2, T, Q>& operator+=(VectorT<2, U, Q> const& v);

	template <typename U>
	constexpr VectorT<2, T, Q>& operator-=(U scalar);
	template <typename U>
	constexpr VectorT<2, T, Q>& operator-=(VectorT<1, U, Q> const& v);
	template <typename U>
	constexpr VectorT<2, T, Q>& operator-=(VectorT<2, U, Q> const& v);

	template <typename U>
	constexpr VectorT<2, T, Q>& operator*=(U scalar);
	template <typename U>
	constexpr VectorT<2, T, Q>& operator*=(VectorT<1, U, Q> const& v);
	template <typename U>
	constexpr VectorT<2, T, Q>& operator*=(VectorT<2, U, Q> const& v);

	template <typename U>
	constexpr VectorT<2, T, Q>& operator/=(U scalar);
	template <typename U>
	constexpr VectorT<2, T, Q>& operator/=(VectorT<1, U, Q> const& v);
	template <typename U>
	constexpr VectorT<2, T, Q>& operator/=(VectorT<2, U, Q> const& v);

	constexpr VectorT<2, T, Q>& operator++();
	constexpr VectorT<2, T, Q>& operator--();
	constexpr const VectorT<2, T, Q> operator++(int);
	constexpr const VectorT<2, T, Q> operator--(int);

	template <typename U>
	constexpr VectorT<2, T, Q>& operator%=(U scalar);
	template <typename U>
	constexpr VectorT<2, T, Q>& operator%=(VectorT<1, U, Q> const& v);
	template <typename U>
	constexpr VectorT<2, T, Q>& operator%=(VectorT<2, U, Q> const& v);

	template <typename U>
	constexpr VectorT<2, T, Q>& operator&=(U scalar);
	template <typename U>
	constexpr VectorT<2, T, Q>& operator&=(VectorT<1, U, Q> const& v);
	template <typename U>
	constexpr VectorT<2, T, Q>& operator&=(VectorT<2, U, Q> const& v);

	template <typename U>
	constexpr VectorT<2, T, Q>& operator|=(U scalar);
	template <typename U>
	constexpr VectorT<2, T, Q>& operator|=(VectorT<1, U, Q> const& v);
	template <typename U>
	constexpr VectorT<2, T, Q>& operator|=(VectorT<2, U, Q> const& v);

	template <typename U>
	constexpr VectorT<2, T, Q>& operator^=(U scalar);
	template <typename U>
	constexpr VectorT<2, T, Q>& operator^=(VectorT<1, U, Q> const& v);
	template <typename U>
	constexpr VectorT<2, T, Q>& operator^=(VectorT<2, U, Q> const& v);

	template <typename U>
	constexpr VectorT<2, T, Q>& operator<<=(U scalar);
	template <typename U>
	constexpr VectorT<2, T, Q>& operator<<=(VectorT<1, U, Q> const& v);
	template <typename U>
	constexpr VectorT<2, T, Q>& operator<<=(VectorT<2, U, Q> const& v);

	template <typename U>
	constexpr VectorT<2, T, Q>& operator>>=(U scalar);
	template <typename U>
	constexpr VectorT<2, T, Q>& operator>>=(VectorT<1, U, Q> const& v);
	template <typename U>
	constexpr VectorT<2, T, Q>& operator>>=(VectorT<2, U, Q> const& v);

	friend std::ostream& operator<<(std::ostream& os, VectorT<2, T, Q> const& v);
};

template <typename T, qualifier Q>
std::ostream& operator<<(std::ostream& os, VectorT<2, T, Q> const& v)
{
	return os << "(" << v.x << ", " << v.y << ")";
}

template <typename T, qualifier Q>
constexpr VectorT<2, T, Q> operator+(VectorT<2, T, Q> const& v);

template <typename T, qualifier Q>
constexpr VectorT<2, T, Q> operator-(VectorT<2, T, Q> const& v);

template <typename T, qualifier Q>
constexpr VectorT<2, T, Q> operator+(VectorT<2, T, Q> const& v, T scalar);

template <typename T, qualifier Q>
constexpr VectorT<2, T, Q> operator+(T scalar, VectorT<2, T, Q> const& v);

template <typename T, qualifier Q>
constexpr VectorT<2, T, Q> operator+(VectorT<2, T, Q> const& v1, VectorT<2, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr VectorT<2, T, Q> operator+(VectorT<1, T, Q> const& v, VectorT<2, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr VectorT<2, T, Q> operator+(VectorT<2, T, Q> const& v1, VectorT<1, T, Q> const& v);

template <typename T, qualifier Q>
constexpr VectorT<2, T, Q> operator-(VectorT<2, T, Q> const& v, T scalar);

template <typename T, qualifier Q>
constexpr VectorT<2, T, Q> operator-(T scalar, VectorT<2, T, Q> const& v);

template <typename T, qualifier Q>
constexpr VectorT<2, T, Q> operator-(VectorT<2, T, Q> const& v1, VectorT<2, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr VectorT<2, T, Q> operator-(VectorT<1, T, Q> const& v, VectorT<2, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr VectorT<2, T, Q> operator-(VectorT<2, T, Q> const& v1, VectorT<1, T, Q> const& v);

template <typename T, qualifier Q>
constexpr VectorT<2, T, Q> operator*(VectorT<2, T, Q> const& v, T scalar);

template <typename T, qualifier Q>
constexpr VectorT<2, T, Q> operator*(T scalar, VectorT<2, T, Q> const& v);

template <typename T, qualifier Q>
constexpr VectorT<2, T, Q> operator*(VectorT<2, T, Q> const& v1, VectorT<2, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr VectorT<2, T, Q> operator*(VectorT<1, T, Q> const& v, VectorT<2, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr VectorT<2, T, Q> operator*(VectorT<2, T, Q> const& v1, VectorT<1, T, Q> const& v);

template <typename T, qualifier Q>
constexpr VectorT<2, T, Q> operator/(VectorT<2, T, Q> const& v, T scalar);

template <typename T, qualifier Q>
constexpr VectorT<2, T, Q> operator/(T scalar, VectorT<2, T, Q> const& v);

template <typename T, qualifier Q>
constexpr VectorT<2, T, Q> operator/(VectorT<2, T, Q> const& v1, VectorT<2, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr VectorT<2, T, Q> operator/(VectorT<1, T, Q> const& v, VectorT<2, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr VectorT<2, T, Q> operator/(VectorT<2, T, Q> const& v1, VectorT<1, T, Q> const& v);

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

template <typename T, qualifier Q>
constexpr VectorT<2, T, Q> operator&(VectorT<2, T, Q> const& v, T scalar);

template <typename T, qualifier Q>
constexpr VectorT<2, T, Q> operator&(T scalar, VectorT<2, T, Q> const& v);

template <typename T, qualifier Q>
constexpr VectorT<2, T, Q> operator&(VectorT<2, T, Q> const& v1, VectorT<2, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr VectorT<2, T, Q> operator&(VectorT<1, T, Q> const& v, VectorT<2, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr VectorT<2, T, Q> operator&(VectorT<2, T, Q> const& v1, VectorT<1, T, Q> const& v);

template <typename T, qualifier Q>
constexpr VectorT<2, T, Q> operator|(VectorT<2, T, Q> const& v, T scalar);

template <typename T, qualifier Q>
constexpr VectorT<2, T, Q> operator|(T scalar, VectorT<2, T, Q> const& v);

template <typename T, qualifier Q>
constexpr VectorT<2, T, Q> operator|(VectorT<2, T, Q> const& v1, VectorT<2, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr VectorT<2, T, Q> operator|(VectorT<1, T, Q> const& v, VectorT<2, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr VectorT<2, T, Q> operator|(VectorT<2, T, Q> const& v1, VectorT<1, T, Q> const& v);

template <typename T, qualifier Q>
constexpr VectorT<2, T, Q> operator^(VectorT<2, T, Q> const& v1, T scalar);

template <typename T, qualifier Q>
constexpr VectorT<2, T, Q> operator^(T scalar, VectorT<2, T, Q> const& v);

template <typename T, qualifier Q>
constexpr VectorT<2, T, Q> operator^(VectorT<2, T, Q> const& v1, VectorT<2, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr VectorT<2, T, Q> operator^(VectorT<1, T, Q> const& v, VectorT<2, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr VectorT<2, T, Q> operator^(VectorT<2, T, Q> const& v1, VectorT<1, T, Q> const& v);

template <typename T, qualifier Q>
constexpr VectorT<2, T, Q> operator<<(VectorT<2, T, Q> const& v, T scalar);

template <typename T, qualifier Q>
constexpr VectorT<2, T, Q> operator<<(T scalar, VectorT<2, T, Q> const& v);

template <typename T, qualifier Q>
constexpr VectorT<2, T, Q> operator<<(VectorT<2, T, Q> const& v1, VectorT<2, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr VectorT<2, T, Q> operator<<(VectorT<1, T, Q> const& v, VectorT<2, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr VectorT<2, T, Q> operator<<(VectorT<2, T, Q> const& v1, VectorT<1, T, Q> const& v);

template <typename T, qualifier Q>
constexpr VectorT<2, T, Q> operator>>(VectorT<2, T, Q> const& v, T scalar);

template <typename T, qualifier Q>
constexpr VectorT<2, T, Q> operator>>(T scalar, VectorT<2, T, Q> const& v);

template <typename T, qualifier Q>
constexpr VectorT<2, T, Q> operator>>(VectorT<2, T, Q> const& v1, VectorT<2, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr VectorT<2, T, Q> operator>>(VectorT<1, T, Q> const& v, VectorT<2, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr VectorT<2, T, Q> operator>>(VectorT<2, T, Q> const& v1, VectorT<1, T, Q> const& v);

template <typename T, qualifier Q>
constexpr VectorT<2, bool, Q> operator~(VectorT<2, T, Q> const& v);

template <typename T, qualifier Q>
constexpr VectorT<2, bool, Q> operator==(VectorT<2, T, Q> const& v1, VectorT<2, T, Q> const& v2);

template <typename T, qualifier Q>
constexpr VectorT<2, bool, Q> operator!=(VectorT<2, T, Q> const& v1, VectorT<2, T, Q> const& v2);

template <qualifier Q>
constexpr VectorT<2, bool, Q> operator&&(VectorT<2, bool, Q> const& v1, VectorT<2, bool, Q> const& v2);

template <qualifier Q>
constexpr VectorT<2, bool, Q> operator||(VectorT<2, bool, Q> const& v1, VectorT<2, bool, Q> const& v2);
} // namespace mim

#include "mim/detail/type/type_vector2.inl"
