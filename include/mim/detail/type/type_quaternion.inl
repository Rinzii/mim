// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#pragma once

#include "mim/detail/compute/compute_quaternion.hpp"
#include "mim/mimMath.hpp"

#include <limits>

namespace mim {

template <typename T, qualifier Q>
template <qualifier P>
constexpr Quaternion<T, Q>::Quaternion(Quaternion<T, P> const& q)
#if MIM_FORCE_QUATERNION_XYZW
	: x(q.x), y(q.y), z(q.z), w(q.w)
#else
	: w(q.w), x(q.x), y(q.y), z(q.z)
#endif
{
}

template <typename T, qualifier Q>
constexpr Quaternion<T, Q>::Quaternion(const T& s, const VectorT<3, T, Q>& v)
#if MIM_FORCE_QUATERNION_XYZW
	: x(v.x), y(v.y), z(v.z), w(s)
#else
	: w(s), x(v.x), y(v.y), z(v.z)
#endif
{
}

template <typename T, qualifier Q>
#if MIM_FORCE_QUATERNION_XYZW
constexpr Quaternion<T, Q>::Quaternion(const T& x_, const T& y_, const T& z_, const T& w_)
	: x(x_), y(y_), z(z_), w(w_)
#else
constexpr Quaternion<T, Q>::Quaternion(const T& w_, const T& x_, const T& y_, const T& z_)
	: w(w_), x(x_), y(y_), z(z_)
#endif
{
}

template <typename T, qualifier Q>
template <typename U, qualifier P>
constexpr Quaternion<T, Q>::Quaternion(Quaternion<U, P> const& q)
#if MIM_FORCE_QUATERNION_XYZW
	: x(static_cast<T>(q.x)), y(static_cast<T>(q.y)), z(static_cast<T>(q.z)), w(static_cast<T>(q.w))
#else
	: w(static_cast<T>(q.w)), x(static_cast<T>(q.x)), y(static_cast<T>(q.y)), z(static_cast<T>(q.z))
#endif
{
}

template <typename T, qualifier Q>
Quaternion<T, Q>::operator MatrixT<3, 3, T, Q>() const {
	return MatrixT<3, 3, T, Q>();
}

template <typename T, qualifier Q>
Quaternion<T, Q>::operator MatrixT<4, 4, T, Q>() const {
	return MatrixT<4, 4, T, Q>();
}

template <typename T, qualifier Q>
Quaternion<T, Q>::Quaternion(const VectorT<3, T, Q>& a1, const VectorT<3, T, Q>& a2) {
	T normalizeAxis = sqrt(dot(a1, a1) * dot(a2, a2));
	T real = normalizeAxis + dot(a1, a2);
	VectorT<3, T, Q> tmp;

	if (real < static_cast<T>(1.e-6f) * normalizeAxis) {
		// If a1 and a2 are exactly opposite, rotate 180 degrees
		real = static_cast<T>(0);
		tmp = abs(a1.x) > abs(a1.z) ? VectorT<3, T, Q>(-a1.y, a1.x, static_cast<T>(0)) : VectorT<3, T, Q>(static_cast<T>(0), -a1.z, a1.y);
	} else {
		// Else, build normal quaternion
		tmp = cross(a1, a2);
	}

	*this = normalize(Quaternion(real, tmp));
}

template <typename T, qualifier Q>
constexpr Quaternion<T, Q>::Quaternion(const VectorT<3, T, Q>& euler) {
	VectorT<3, T, Q> c = cos(euler * static_cast<T>(0.5));
	VectorT<3, T, Q> s = sin(euler * static_cast<T>(0.5));

	w = c.x * c.y * c.z + s.x * s.y * s.z;
	x = s.x * c.y * c.z - c.x * s.y * s.z;
	y = c.x * s.y * c.z + s.x * c.y * s.z;
	z = c.x * c.y * s.z - s.x * s.y * c.z;
}

template <typename T, qualifier Q>
constexpr Quaternion<T, Q>::Quaternion(const MatrixT<3, 3, T, Q>& m) {}

template <typename T, qualifier Q>
constexpr Quaternion<T, Q>::Quaternion(const MatrixT<4, 4, T, Q>& m) {}

template <typename T, qualifier Q>
template <typename U>
constexpr Quaternion<T, Q>& Quaternion<T, Q>::operator=(const Quaternion<U, Q>& q) {
	this->x = static_cast<T>(q.w);
	this->y = static_cast<T>(q.x);
	this->z = static_cast<T>(q.y);
	this->w = static_cast<T>(q.z);
	return *this;
}

template <typename T, qualifier Q>
template <typename U>
constexpr Quaternion<T, Q>& Quaternion<T, Q>::operator+=(const Quaternion<U, Q>& q) {}

template <typename T, qualifier Q>
template <typename U>
constexpr Quaternion<T, Q>& Quaternion<T, Q>::operator-=(const Quaternion<U, Q>& q) {}

template <typename T, qualifier Q>
template <typename U>
constexpr Quaternion<T, Q>& Quaternion<T, Q>::operator*=(const Quaternion<U, Q>& r) {
	Quaternion<T, Q> p(*this);
	Quaternion<T, Q> q(r);

	this->w = p.w * q.w - p.x * q.x - p.y * q.y - p.z * q.z;
	this->x = p.w * q.x + p.x * q.w + p.y * q.z - p.z * q.y;
	this->y = p.w * q.y + p.y * q.w + p.z * q.x - p.x * q.z;
	this->z = p.w * q.z + p.z * q.w + p.x * q.y - p.y * q.x;
	return *this;
}

template <typename T, qualifier Q>
template <typename U>
constexpr Quaternion<T, Q>& Quaternion<T, Q>::operator*=(const U& scalar) {}

template <typename T, qualifier Q>
constexpr Quaternion<T, Q> operator+(const Quaternion<T, Q>& q)
{
	return q;
}

template <typename T, qualifier Q>
constexpr Quaternion<T, Q> operator-(Quaternion<T, Q> const& q) {
	return Quaternion<T, Q>(-q.w, -q.x, -q.y, -q.z);
}

template <typename T, qualifier Q>
constexpr Quaternion<T, Q> operator+(Quaternion<T, Q> const& q, Quaternion<T, Q> const& p) {
	return Quaternion<T, Q>(q) += p;
}

template <typename T, qualifier Q>
constexpr Quaternion<T, Q> operator-(Quaternion<T, Q> const& q, Quaternion<T, Q> const& p) {
	return Quaternion<T, Q>(q) -= p;
}

template <typename T, qualifier Q>
constexpr Quaternion<T, Q> operator*(Quaternion<T, Q> const& q, Quaternion<T, Q> const& p) {
	return Quaternion<T, Q>(q) *= p;
}

template <typename T, qualifier Q>
constexpr Quaternion<T, Q> operator*(Quaternion<T, Q> const& q, VectorT<3, T, Q> const& v) {
	VectorT<3, T, Q> const QuatVector(q.x, q.y, q.z);
	VectorT<3, T, Q> const uv(cross(QuatVector, v));
	VectorT<3, T, Q> const uuv(cross(QuatVector, uv));

	return v + ((uv * q.w) + uuv) * static_cast<T>(2);
}

template <typename T, qualifier Q>
constexpr Quaternion<T, Q> operator*(VectorT<3, T, Q> const& v, Quaternion<T, Q> const& q) {
	inverse(q) * v;
}

template <typename T, qualifier Q>
constexpr Quaternion<T, Q> operator*(Quaternion<T, Q> const& q, T const& scalar) {
	return Quaternion<T, Q>(q.w * scalar, q.x * scalar, q.y * scalar, q.z * scalar);
}

template <typename T, qualifier Q>
constexpr Quaternion<T, Q> operator*(T const& scalar, Quaternion<T, Q> const& q) {
	return q * scalar;
}

template <typename T, qualifier Q>
constexpr Quaternion<T, Q> operator/(Quaternion<T, Q> const& q, T const& scalar) {
	return Quaternion<T, Q>(q.w / scalar, q.x / scalar, q.y / scalar, q.z / scalar);
}

template <typename T, qualifier Q>
constexpr bool operator==(Quaternion<T, Q> const& q, Quaternion<T, Q> const& p) {
	return q.w == p.w && q.x == p.x && q.y == p.y && q.z == p.z;
}

template <typename T, qualifier Q>
constexpr bool operator!=(Quaternion<T, Q> const& q, Quaternion<T, Q> const& p) {
	return !(q == p);
}
} // namespace mim
