// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#pragma once

#include "mim/detail/qualifier.hpp"

#include "mim/detail/type/type_vector3.hpp"
#include "mim/detail/type/type_vector4.hpp"

#include "mim/detail/type/type_matrix3x3.hpp"
#include "mim/detail/type/type_matrix4x4.hpp"

#include "mim/detail/compute/compute_quaternion.hpp"

namespace mim {
template <typename T, qualifier Q>
struct Quaternion {
	using value_type = T;
	using type = Quaternion<T, Q>;
	using size_type = size_t;

	static constexpr auto sizeV = 4;

	union {
#ifdef MIM_FORCE_QUATERNION_XYZW
		struct {
			T x, y, z, w;
		};
#else
		struct {
			T w, x, y, z;
		};
#endif

		typename detail::Storage<4, T, detail::IsAligned<Q>::value> data;
	};

	static constexpr auto size() { return sizeV; }

	constexpr T& operator[](size_type i) {
		if (i > this->size())
			throw std::out_of_range("Quaternion::operator[]");

#if MIM_FORCE_QUATERNION_XYZW
		return (&x)[i];
#else
		return (&w)[i];
#endif
	}
	constexpr T const& operator[](size_type i) const {
		if (i > this->size())
			throw std::out_of_range("Quaternion::operator[]");

#if MIM_FORCE_QUATERNION_XYZW
		return (&x)[i];
#else
		return (&w)[i];
#endif
	}

	constexpr Quaternion() = default;
	constexpr Quaternion(Quaternion const&) = default;
	template <qualifier P>
	constexpr explicit Quaternion(Quaternion<T, P> const& q);

	constexpr Quaternion(T const& s, VectorT<3, T, Q> const& v);

#ifdef MIM_FORCE_QUATERNION_XYZW
	constexpr Quaternion(T const& x, T const& y, T const& z, T const& w);
#else
	constexpr Quaternion(T const& w, T const& x, T const& y, T const& z);
#endif

	template <typename U, qualifier P>
	constexpr explicit Quaternion(Quaternion<U, P> const& q);

	explicit operator MatrixT<3, 3, T, Q>() const;
	explicit operator MatrixT<4, 4, T, Q>() const;

	Quaternion(VectorT<3, T, Q> const& a1, VectorT<3, T, Q> const& a2);

	constexpr explicit Quaternion(VectorT<3, T, Q> const& euler);

	/* TODO: Once matrix is implemented bring this back in.
	constexpr explicit Quaternion(MatrixT<3, 3, T, Q> const& m);
	constexpr explicit Quaternion(MatrixT<4, 4, T, Q> const& m);
	 */

	constexpr Quaternion<T, Q>& operator=(Quaternion<T, Q> const& q) = default;

	template <typename U>
	constexpr Quaternion<T, Q>& operator=(Quaternion<U, Q> const& q);
	template <typename U>
	constexpr Quaternion<T, Q>& operator+=(Quaternion<U, Q> const& q);
	template <typename U>
	constexpr Quaternion<T, Q>& operator-=(Quaternion<U, Q> const& q);
	template <typename U>
	constexpr Quaternion<T, Q>& operator*=(Quaternion<U, Q> const& r);
	template <typename U>
	constexpr Quaternion<T, Q>& operator*=(U const& scalar);
	template <typename U>
	constexpr Quaternion<T, Q>& operator/=(U const& scalar);
};


template <typename T, qualifier Q>
constexpr Quaternion<T, Q> operator+(Quaternion<T, Q> const& q);

template <typename T, qualifier Q>
constexpr Quaternion<T, Q> operator-(Quaternion<T, Q> const& q);

template <typename T, qualifier Q>
constexpr Quaternion<T, Q> operator+(Quaternion<T, Q> const& q1, Quaternion<T, Q> const& p);

template <typename T, qualifier Q>
constexpr Quaternion<T, Q> operator-(Quaternion<T, Q> const& q1, Quaternion<T, Q> const& p);

template <typename T, qualifier Q>
constexpr Quaternion<T, Q> operator*(Quaternion<T, Q> const& q1, Quaternion<T, Q> const& p);
template <typename T, qualifier Q>
constexpr Quaternion<T, Q> operator*(Quaternion<T, Q> const& q, VectorT<3, T, Q> const& v);
template <typename T, qualifier Q>
constexpr Quaternion<T, Q> operator*(VectorT<3, T, Q> const& v, Quaternion<T, Q> const& q);
template <typename T, qualifier Q>
constexpr Quaternion<T, Q> operator*(Quaternion<T, Q> const& q, VectorT<4, T, Q> const& v);
template <typename T, qualifier Q>
constexpr Quaternion<T, Q> operator*(VectorT<4, T, Q> const& v, Quaternion<T, Q> const& q);
template <typename T, qualifier Q>
constexpr Quaternion<T, Q> operator*(Quaternion<T, Q> const& q, T const& scalar);
template <typename T, qualifier Q>
constexpr Quaternion<T, Q> operator*(T const& scalar, Quaternion<T, Q> const& q);

template <typename T, qualifier Q>
constexpr Quaternion<T, Q> operator/(Quaternion<T, Q> const& q, T const& scalar);

template <typename T, qualifier Q>
constexpr bool operator==(Quaternion<T, Q> const& q1, Quaternion<T, Q> const& p);

template <typename T, qualifier Q>
constexpr bool operator!=(Quaternion<T, Q> const& q1, Quaternion<T, Q> const& p);

} // namespace mim

#include "mim/detail/type/type_quaternion.inl"
