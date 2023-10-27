// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#pragma once

#include "mim/detail/compute/compute_quaternion.hpp"
#include "mim/detail/type/type_vector3.hpp"

#include "mim/cmath.hpp"

#include <limits>
#include <cmath>

namespace mim
{
	template <typename T>
	constexpr quat<T>::quat()
	{
        w = static_cast<T>(1);
        x = static_cast<T>(0);
        y = static_cast<T>(0);
        z = static_cast<T>(0);
	}

	template <typename T>
	constexpr quat<T>::quat(quat const& q)
	{
		w = q.w;
        x = q.x;
        y = q.y;
        z = q.z;
	}

	template <typename T>
	constexpr quat<T>::quat(const T& s, const vec<3, T>& v)
		: w(s), x(v.x), y(v.y), z(v.z)
	{
	}

	template <typename T>
	constexpr quat<T>::quat(const T& w_, const T& x_, const T& y_, const T& z_) : w(w_), x(x_), y(y_), z(z_)
	{
	}

	template <typename T>
	template <typename U>
	constexpr quat<T>::quat(quat<U> const& q)
		: w(static_cast<T>(q.w)), x(static_cast<T>(q.x)), y(static_cast<T>(q.y)), z(static_cast<T>(q.z))
	{
	}

	template <typename T>
	quat<T>::operator mat<3, 3, T>() const
	{
		return mat<3, 3, T>();
	}

	template <typename T>
	quat<T>::operator mat<4, 4, T>() const
	{
		return mat<4, 4, T>();
	}

	// TODO: This is currently broken.
	template <typename T>
	quat<T>::quat(const vec<3, T>& a1, const vec<3, T>& a2)
	{
		T normalizeAxis = ::mim::math::sqrt(::mim::dot(a1, a1) * ::mim::dot(a2, a2));
		T real = normalizeAxis + ::mim::dot(a1, a2);
		vec<3, T> tmp;

		if (real < static_cast<T>(1.e-6f) * normalizeAxis) {
			// If a1 and a2 are exactly opposite, rotate 180 degrees
			real = static_cast<T>(0);
			tmp = ::mim::math::abs(a1.x) > ::mim::math::abs(a1.z) ? vec<3, T>(-a1.y, a1.x, static_cast<T>(0)) : vec<3, T>(static_cast<T>(0), -a1.z, a1.y);
		} else {
			// Else, build normal quaternion
			tmp = ::mim::cross(a1, a2);
		}

		*this = ::mim::normalize(quat<T>(real, tmp));
	}

	// TODO: This may not work as constexpr due to using std::cos and std::sin.

	template <typename T>
	constexpr quat<T>::quat(const vec<3, T>& euler)
	{
		vec<3, T> c = ::std::cos(euler * static_cast<T>(0.5));
		vec<3, T> s = ::std::sin(euler * static_cast<T>(0.5));

		w = c.x * c.y * c.z + s.x * s.y * s.z;
		x = s.x * c.y * c.z - c.x * s.y * s.z;
		y = c.x * s.y * c.z + s.x * c.y * s.z;
		z = c.x * c.y * s.z - s.x * s.y * c.z;
	}

	/* TODO: Once matrix is implemented bring this back in.
	template <typename T>
	constexpr quat<T>::quat(const mat<3, 3, T>& m) {

	}

	template <typename T>
	constexpr quat<T>::quat(const mat<4, 4, T>& m) {

	}
	*/

	template <typename T>
	template <typename U>
	constexpr quat<T>& quat<T>::operator=(const quat<U>& q)
	{
		this->x = static_cast<T>(q.w);
		this->y = static_cast<T>(q.x);
		this->z = static_cast<T>(q.y);
		this->w = static_cast<T>(q.z);
		return (*this);
	}

	template <typename T>
	template <typename U>
	constexpr quat<T>& quat<T>::operator+=(const quat<U>& q)
	{
		this->w += static_cast<T>(q.w);
		this->x += static_cast<T>(q.x);
		this->y += static_cast<T>(q.y);
		this->z += static_cast<T>(q.z);
		return (*this);
	}

	template <typename T>
	template <typename U>
	constexpr quat<T>& quat<T>::operator-=(const quat<U>& q)
	{
		this->w -= static_cast<T>(q.w);
		this->x -= static_cast<T>(q.x);
		this->y -= static_cast<T>(q.y);
		this->z -= static_cast<T>(q.z);
		return (*this);
	}

	template <typename T>
	template <typename U>
	constexpr quat<T>& quat<T>::operator*=(const quat<U>& r)
	{
		quat<T> p(*this);
		quat<T> q(r);

		this->w = p.w * q.w - p.x * q.x - p.y * q.y - p.z * q.z;
		this->x = p.w * q.x + p.x * q.w + p.y * q.z - p.z * q.y;
		this->y = p.w * q.y + p.y * q.w + p.z * q.x - p.x * q.z;
		this->z = p.w * q.z + p.z * q.w + p.x * q.y - p.y * q.x;
		return (*this);
	}

	template <typename T>
	template <typename U>
	constexpr quat<T>& quat<T>::operator/=(const U& scalar)
	{
		return (*this) *= static_cast<T>(1) / scalar;
	}

	template <typename T>
	template <typename U>
	constexpr quat<T>& quat<T>::operator*=(const U& scalar)
	{
		this->x *= scalar;
		this->y *= scalar;
		this->z *= scalar;
		this->w *= scalar;
		return (*this);
	}

	template <typename T>
	constexpr quat<T> operator+(const quat<T>& q)
	{
		return q;
	}

	template <typename T>
	constexpr quat<T> operator-(quat<T> const& q)
	{
		return quat<T>(-q.w, -q.x, -q.y, -q.z);
	}

	template <typename T>
	constexpr quat<T> operator+(quat<T> const& q, quat<T> const& p)
	{
		return quat<T>(q) += p;
	}

	template <typename T>
	constexpr quat<T> operator-(quat<T> const& q, quat<T> const& p)
	{
		return quat<T>(q) -= p;
	}

	template <typename T>
	constexpr quat<T> operator*(quat<T> const& q, quat<T> const& p)
	{
		return quat<T>(q) *= p;
	}

	template <typename T>
	constexpr quat<T> operator*(quat<T> const& q, vec<3, T> const& v)
	{
		vec<3, T> const QuatVector(q.x, q.y, q.z);
		vec<3, T> const uv(::mim::cross(QuatVector, v));
		vec<3, T> const uuv(::mim::cross(QuatVector, uv));

		return v + ((uv * q.w) + uuv) * static_cast<T>(2);
	}

	template <typename T>
	constexpr quat<T> operator*(vec<3, T> const& v, quat<T> const& q)
	{
		::mim::inverse(q) * v;
	}

	template <typename T>
	constexpr quat<T> operator*(quat<T> const& q, T const& scalar)
	{
		return quat<T>(q.w * scalar, q.x * scalar, q.y * scalar, q.z * scalar);
	}

	template <typename T>
	constexpr quat<T> operator*(T const& scalar, quat<T> const& q)
	{
		return q * scalar;
	}

	template <typename T>
	constexpr quat<T> operator/(quat<T> const& q, T const& scalar)
	{
		return quat<T>(q.w / scalar, q.x / scalar, q.y / scalar, q.z / scalar);
	}

	template <typename T>
	constexpr bool operator==(quat<T> const& q, quat<T> const& p)
	{
		return q.w == p.w && q.x == p.x && q.y == p.y && q.z == p.z;
	}

	template <typename T>
	constexpr bool operator!=(quat<T> const& q, quat<T> const& p)
	{
		return !(q == p);
	}
} // namespace mim
