// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#pragma once

#include "mim/detail/compute/compute_quaternion.hpp"
#include "mim/detail/type/type_vector3.hpp"

#include "mim/cmath.hpp"

#include <limits>
#include <cmath>

namespace mim
{
	template <typename T, qualifier Q>
	constexpr quat<T, Q>::quat()
	{
        w = static_cast<T>(1);
        x = static_cast<T>(0);
        y = static_cast<T>(0);
        z = static_cast<T>(0);
	}

	template <typename T, qualifier Q>
	constexpr quat<T, Q>::quat(quat const& q)
	{
		w = q.w;
        x = q.x;
        y = q.y;
        z = q.z;
	}

	template <typename T, qualifier Q>
	template <qualifier P>
	constexpr quat<T, Q>::quat(quat<T, P> const& q)
		: w(q.w), x(q.x), y(q.y), z(q.z)
	{
	}

	template <typename T, qualifier Q>
	constexpr quat<T, Q>::quat(const T& s, const vec<3, T, Q>& v)
		: w(s), x(v.x), y(v.y), z(v.z)
	{
	}

	template <typename T, qualifier Q>
	constexpr quat<T, Q>::quat(const T& w_, const T& x_, const T& y_, const T& z_) : w(w_), x(x_), y(y_), z(z_)
	{
	}

	template <typename T, qualifier Q>
	template <typename U, qualifier P>
	constexpr quat<T, Q>::quat(quat<U, P> const& q)
		: w(static_cast<T>(q.w)), x(static_cast<T>(q.x)), y(static_cast<T>(q.y)), z(static_cast<T>(q.z))
	{
	}

	template <typename T, qualifier Q>
	quat<T, Q>::operator mat<3, 3, T, Q>() const
	{
		return mat<3, 3, T, Q>();
	}

	template <typename T, qualifier Q>
	quat<T, Q>::operator mat<4, 4, T, Q>() const
	{
		return mat<4, 4, T, Q>();
	}

	// TODO: This is currently broken.
	template <typename T, qualifier Q>
	quat<T, Q>::quat(const vec<3, T, Q>& a1, const vec<3, T, Q>& a2)
	{
		T normalizeAxis = ::mim::math::sqrt(::mim::dot(a1, a1) * ::mim::dot(a2, a2));
		T real = normalizeAxis + ::mim::dot(a1, a2);
		vec<3, T, Q> tmp;

		if (real < static_cast<T>(1.e-6f) * normalizeAxis) {
			// If a1 and a2 are exactly opposite, rotate 180 degrees
			real = static_cast<T>(0);
			tmp = ::mim::math::abs(a1.x) > ::mim::math::abs(a1.z) ? vec<3, T, Q>(-a1.y, a1.x, static_cast<T>(0)) : vec<3, T, Q>(static_cast<T>(0), -a1.z, a1.y);
		} else {
			// Else, build normal quaternion
			tmp = ::mim::cross(a1, a2);
		}

		*this = ::mim::normalize(quat<T, Q>(real, tmp));
	}

	// TODO: This may not work as constexpr due to using std::cos and std::sin.

	template <typename T, qualifier Q>
	constexpr quat<T, Q>::quat(const vec<3, T, Q>& euler)
	{
		vec<3, T, Q> c = ::std::cos(euler * static_cast<T>(0.5));
		vec<3, T, Q> s = ::std::sin(euler * static_cast<T>(0.5));

		w = c.x * c.y * c.z + s.x * s.y * s.z;
		x = s.x * c.y * c.z - c.x * s.y * s.z;
		y = c.x * s.y * c.z + s.x * c.y * s.z;
		z = c.x * c.y * s.z - s.x * s.y * c.z;
	}

	/* TODO: Once matrix is implemented bring this back in.
	template <typename T, qualifier Q>
	constexpr quat<T, Q>::quat(const mat<3, 3, T, Q>& m) {

	}

	template <typename T, qualifier Q>
	constexpr quat<T, Q>::quat(const mat<4, 4, T, Q>& m) {

	}
	*/

	template <typename T, qualifier Q>
	template <typename U>
	constexpr quat<T, Q>& quat<T, Q>::operator=(const quat<U, Q>& q)
	{
		this->x = static_cast<T>(q.w);
		this->y = static_cast<T>(q.x);
		this->z = static_cast<T>(q.y);
		this->w = static_cast<T>(q.z);
		return (*this);
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr quat<T, Q>& quat<T, Q>::operator+=(const quat<U, Q>& q)
	{
		this->w += static_cast<T>(q.w);
		this->x += static_cast<T>(q.x);
		this->y += static_cast<T>(q.y);
		this->z += static_cast<T>(q.z);
		return (*this);
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr quat<T, Q>& quat<T, Q>::operator-=(const quat<U, Q>& q)
	{
		this->w -= static_cast<T>(q.w);
		this->x -= static_cast<T>(q.x);
		this->y -= static_cast<T>(q.y);
		this->z -= static_cast<T>(q.z);
		return (*this);
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr quat<T, Q>& quat<T, Q>::operator*=(const quat<U, Q>& r)
	{
		quat<T, Q> p(*this);
		quat<T, Q> q(r);

		this->w = p.w * q.w - p.x * q.x - p.y * q.y - p.z * q.z;
		this->x = p.w * q.x + p.x * q.w + p.y * q.z - p.z * q.y;
		this->y = p.w * q.y + p.y * q.w + p.z * q.x - p.x * q.z;
		this->z = p.w * q.z + p.z * q.w + p.x * q.y - p.y * q.x;
		return (*this);
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr quat<T, Q>& quat<T, Q>::operator/=(const U& scalar)
	{
		return (*this) *= static_cast<T>(1) / scalar;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr quat<T, Q>& quat<T, Q>::operator*=(const U& scalar)
	{
		this->x *= scalar;
		this->y *= scalar;
		this->z *= scalar;
		this->w *= scalar;
		return (*this);
	}

	template <typename T, qualifier Q>
	constexpr quat<T, Q> operator+(const quat<T, Q>& q)
	{
		return q;
	}

	template <typename T, qualifier Q>
	constexpr quat<T, Q> operator-(quat<T, Q> const& q)
	{
		return quat<T, Q>(-q.w, -q.x, -q.y, -q.z);
	}

	template <typename T, qualifier Q>
	constexpr quat<T, Q> operator+(quat<T, Q> const& q, quat<T, Q> const& p)
	{
		return quat<T, Q>(q) += p;
	}

	template <typename T, qualifier Q>
	constexpr quat<T, Q> operator-(quat<T, Q> const& q, quat<T, Q> const& p)
	{
		return quat<T, Q>(q) -= p;
	}

	template <typename T, qualifier Q>
	constexpr quat<T, Q> operator*(quat<T, Q> const& q, quat<T, Q> const& p)
	{
		return quat<T, Q>(q) *= p;
	}

	template <typename T, qualifier Q>
	constexpr quat<T, Q> operator*(quat<T, Q> const& q, vec<3, T, Q> const& v)
	{
		vec<3, T, Q> const QuatVector(q.x, q.y, q.z);
		vec<3, T, Q> const uv(::mim::cross(QuatVector, v));
		vec<3, T, Q> const uuv(::mim::cross(QuatVector, uv));

		return v + ((uv * q.w) + uuv) * static_cast<T>(2);
	}

	template <typename T, qualifier Q>
	constexpr quat<T, Q> operator*(vec<3, T, Q> const& v, quat<T, Q> const& q)
	{
		::mim::inverse(q) * v;
	}

	template <typename T, qualifier Q>
	constexpr quat<T, Q> operator*(quat<T, Q> const& q, T const& scalar)
	{
		return quat<T, Q>(q.w * scalar, q.x * scalar, q.y * scalar, q.z * scalar);
	}

	template <typename T, qualifier Q>
	constexpr quat<T, Q> operator*(T const& scalar, quat<T, Q> const& q)
	{
		return q * scalar;
	}

	template <typename T, qualifier Q>
	constexpr quat<T, Q> operator/(quat<T, Q> const& q, T const& scalar)
	{
		return quat<T, Q>(q.w / scalar, q.x / scalar, q.y / scalar, q.z / scalar);
	}

	template <typename T, qualifier Q>
	constexpr bool operator==(quat<T, Q> const& q, quat<T, Q> const& p)
	{
		return q.w == p.w && q.x == p.x && q.y == p.y && q.z == p.z;
	}

	template <typename T, qualifier Q>
	constexpr bool operator!=(quat<T, Q> const& q, quat<T, Q> const& p)
	{
		return !(q == p);
	}
} // namespace mim
