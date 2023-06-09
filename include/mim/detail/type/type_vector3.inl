// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#include "mim/detail/compute/compute_vector.hpp"

namespace mim {

template <typename T, qualifier Q>
constexpr T& VectorT<3, T, Q>::operator[](size_type i) {
	if (i >= this->length()) {
		throw std::out_of_range("VectorT<3, T, Q>::operator[]");
    }

	switch (i) {
	default:
	case 0: return x;
	case 1: return y;
	case 2: return z;
	}
}

template <typename T, qualifier Q>
constexpr T const& VectorT<3, T, Q>::operator[](size_type i) const {
	if (i >= this->length()) {
		throw std::out_of_range("VectorT<3, T, Q>::operator[]");
	}

	switch (i) {
	default:
	case 0: return x;
	case 1: return y;
	case 2: return z;
	}
}

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q>::VectorT() : x(0), y(0), z(0) {}

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q>::VectorT(VectorT const& v) : x(v.x), y(v.y), z(v.z) {}

template <typename T, qualifier Q>
template <qualifier P>
constexpr VectorT<3, T, Q>::VectorT(VectorT<3, T, P> const& v) : x(v.x), y(v.y), z(v.z) {}

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q>::VectorT(T scalar) : x(scalar), y(scalar), z(scalar) {}

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q>::VectorT(T _x, T _y, T _z) : x(_x), y(_y), z(_z) {}

template <typename T, qualifier Q>
template <typename U, qualifier P>
constexpr VectorT<3, T, Q>::VectorT(VectorT<1, U, P> const& v) : x(static_cast<T>(v.x)), y(static_cast<T>(v.y)), z(static_cast<T>(v.z)) {}

template <typename T, qualifier Q>
template <typename X, typename Y, typename Z>
constexpr VectorT<3, T, Q>::VectorT(X _x, Y _y, Z _z) : x(static_cast<T>(_x)), y(static_cast<T>(_y)), z(static_cast<T>(_z)) {}

template <typename T, qualifier Q>
template <typename X, typename Y, typename Z>
constexpr VectorT<3, T, Q>::VectorT(VectorT<1, X, Q> const& _x, Y _y, Z _z) : x(static_cast<T>(_x.x)), y(static_cast<T>(_y)), z(static_cast<T>(_z)) {}

template <typename T, qualifier Q>
template <typename X, typename Y, typename Z>
constexpr VectorT<3, T, Q>::VectorT(X _x, VectorT<1, Y, Q> const& _y, Z _z) : x(static_cast<T>(_x)), y(static_cast<T>(_y.y)), z(static_cast<T>(_z)) {}

template <typename T, qualifier Q>
template <typename X, typename Y, typename Z>
constexpr VectorT<3, T, Q>::VectorT(X _x, Y _y, VectorT<1, Z, Q> const& _z) : x(static_cast<T>(_x)), y(static_cast<T>(_y)), z(static_cast<T>(_z.z)) {}

template <typename T, qualifier Q>
template <typename X, typename Y, typename Z>
constexpr VectorT<3, T, Q>::VectorT(VectorT<1, X, Q> const& _x, VectorT<1, Y, Q> const& _y, Z _z)
	: x(static_cast<T>(_x.x)), y(static_cast<T>(_y.y)), z(static_cast<T>(_z)) {}

template <typename T, qualifier Q>
template <typename X, typename Y, typename Z>
constexpr VectorT<3, T, Q>::VectorT(VectorT<1, X, Q> const& _x, Y _y, VectorT<1, Z, Q> const& _z)
	: x(static_cast<T>(_x.x)), y(static_cast<T>(_y)), z(static_cast<T>(_z.z)) {}

template <typename T, qualifier Q>
template <typename X, typename Y, typename Z>
constexpr VectorT<3, T, Q>::VectorT(X _x, VectorT<1, Y, Q> const& _y, VectorT<1, Z, Q> const& _z)
	: x(static_cast<T>(_x)), y(static_cast<T>(_y.y)), z(static_cast<T>(_z.z)) {}

template <typename T, qualifier Q>
template <typename X, typename Y, typename Z>
constexpr VectorT<3, T, Q>::VectorT(VectorT<1, X, Q> const& _x, VectorT<1, Y, Q> const& _y, VectorT<1, Z, Q> const& _z)
	: x(static_cast<T>(_x.x)), y(static_cast<T>(_y.y)), z(static_cast<T>(_z.z)) {}

template <typename T, qualifier Q>
template <typename A, typename B, qualifier P>
constexpr VectorT<3, T, Q>::VectorT(VectorT<2, A, P> const& _xy, B _z) : x(static_cast<T>(_xy.x)), y(static_cast<T>(_xy.y)), z(static_cast<T>(_z)) {}

template <typename T, qualifier Q>
template <typename A, typename B, qualifier P>
constexpr VectorT<3, T, Q>::VectorT(VectorT<2, A, P> const& _xy, VectorT<1, B, P> const& _z)
	: x(static_cast<T>(_xy.x)), y(static_cast<T>(_xy.y)), z(static_cast<T>(_z.z)) {}

template <typename T, qualifier Q>
template <typename A, typename B, qualifier P>
constexpr VectorT<3, T, Q>::VectorT(A _x, VectorT<2, B, P> const& _yz) : x(static_cast<T>(_x)), y(static_cast<T>(_yz.y)), z(static_cast<T>(_yz.z)) {}

template <typename T, qualifier Q>
template <typename A, typename B, qualifier P>
constexpr VectorT<3, T, Q>::VectorT(VectorT<1, A, P> const& _x, VectorT<2, B, P> const& _yz)
	: x(static_cast<T>(_x.x)), y(static_cast<T>(_yz.y)), z(static_cast<T>(_yz.z)) {}

template <typename T, qualifier Q>
template <typename U, qualifier P>
constexpr VectorT<3, T, Q>::VectorT(VectorT<3, U, P> const& v) : x(static_cast<T>(v.x)), y(static_cast<T>(v.y)), z(static_cast<T>(v.z)) {}

template <typename T, qualifier Q>
template <typename U, qualifier P>
constexpr VectorT<3, T, Q>::VectorT(VectorT<4, U, P> const& v) : x(static_cast<T>(v.x)), y(static_cast<T>(v.y)), z(static_cast<T>(v.z)) {}

template <typename T, qualifier Q>
template <typename U>
constexpr VectorT<3, T, Q>& VectorT<3, T, Q>::operator=(VectorT<3, U, Q> const& v) {
	x = static_cast<T>(v.x);
	y = static_cast<T>(v.y);
	z = static_cast<T>(v.z);
	return *this;
}

template <typename T, qualifier Q>
template <typename U>
constexpr VectorT<3, T, Q>& VectorT<3, T, Q>::operator+=(U scalar) {
	x += static_cast<T>(scalar);
	y += static_cast<T>(scalar);
	z += static_cast<T>(scalar);
	return *this;
}

template <typename T, qualifier Q>
template <typename U>
constexpr VectorT<3, T, Q>& VectorT<3, T, Q>::operator+=(VectorT<1, U, Q> const& v) {
	x += static_cast<T>(v.x);
	y += static_cast<T>(v.x);
	z += static_cast<T>(v.x);
	return *this;
}

template <typename T, qualifier Q>
template <typename U>
constexpr VectorT<3, T, Q>& VectorT<3, T, Q>::operator+=(VectorT<3, U, Q> const& v) {
	x += static_cast<T>(v.x);
	y += static_cast<T>(v.y);
	z += static_cast<T>(v.z);
	return *this;
}

template <typename T, qualifier Q>
template <typename U>
constexpr VectorT<3, T, Q>& VectorT<3, T, Q>::operator-=(U scalar) {
	x -= static_cast<T>(scalar);
	y -= static_cast<T>(scalar);
	z -= static_cast<T>(scalar);
	return *this;
}

template <typename T, qualifier Q>
template <typename U>
constexpr VectorT<3, T, Q>& VectorT<3, T, Q>::operator-=(VectorT<1, U, Q> const& v) {
	x -= static_cast<T>(v.x);
	y -= static_cast<T>(v.x);
	z -= static_cast<T>(v.x);
	return *this;
}

template <typename T, qualifier Q>
template <typename U>
constexpr VectorT<3, T, Q>& VectorT<3, T, Q>::operator-=(VectorT<3, U, Q> const& v) {
	x -= static_cast<T>(v.x);
	y -= static_cast<T>(v.y);
	z -= static_cast<T>(v.z);
	return *this;
}

template <typename T, qualifier Q>
template <typename U>
constexpr VectorT<3, T, Q>& VectorT<3, T, Q>::operator*=(U scalar) {
	x *= static_cast<T>(scalar);
	y *= static_cast<T>(scalar);
	z *= static_cast<T>(scalar);
	return *this;
}

template <typename T, qualifier Q>
template <typename U>
constexpr VectorT<3, T, Q>& VectorT<3, T, Q>::operator*=(VectorT<1, U, Q> const& v) {
	x *= static_cast<T>(v.x);
	y *= static_cast<T>(v.x);
	z *= static_cast<T>(v.x);
	return *this;
}

template <typename T, qualifier Q>
template <typename U>
constexpr VectorT<3, T, Q>& VectorT<3, T, Q>::operator*=(VectorT<3, U, Q> const& v) {
	x *= static_cast<T>(v.x);
	y *= static_cast<T>(v.y);
	z *= static_cast<T>(v.z);
	return *this;
}

template <typename T, qualifier Q>
template <typename U>
constexpr VectorT<3, T, Q>& VectorT<3, T, Q>::operator/=(U scalar) {
	x /= static_cast<T>(scalar);
	y /= static_cast<T>(scalar);
	z /= static_cast<T>(scalar);
	return *this;
}

template <typename T, qualifier Q>
template <typename U>
constexpr VectorT<3, T, Q>& VectorT<3, T, Q>::operator/=(VectorT<1, U, Q> const& v) {
	x /= static_cast<T>(v.x);
	y /= static_cast<T>(v.x);
	z /= static_cast<T>(v.x);
	return *this;
}

template <typename T, qualifier Q>
template <typename U>
constexpr VectorT<3, T, Q>& VectorT<3, T, Q>::operator/=(VectorT<3, U, Q> const& v) {
	x /= static_cast<T>(v.x);
	y /= static_cast<T>(v.y);
	z /= static_cast<T>(v.z);
	return *this;
}

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q>& VectorT<3, T, Q>::operator++() {
	++this->x;
	++this->y;
	++this->z;
	return *this;
}

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q>& VectorT<3, T, Q>::operator--() {
	--this->x;
	--this->y;
	--this->z;
	return *this;
}

template <typename T, qualifier Q>
constexpr const VectorT<3, T, Q> VectorT<3, T, Q>::operator++(int) {
	VectorT<3, T, Q> result(*this);
	++*this;
	return result;
}

template <typename T, qualifier Q>
constexpr const VectorT<3, T, Q> VectorT<3, T, Q>::operator--(int) {
	VectorT<3, T, Q> result(*this);
	--*this;
	return result;
}

template <typename T, qualifier Q>
template <typename U>
constexpr VectorT<3, T, Q>& VectorT<3, T, Q>::operator%=(U scalar) {
	x %= static_cast<T>(scalar);
	y %= static_cast<T>(scalar);
	z %= static_cast<T>(scalar);
	return *this;
}

template <typename T, qualifier Q>
template <typename U>
constexpr VectorT<3, T, Q>& VectorT<3, T, Q>::operator%=(VectorT<1, U, Q> const& v) {
	x %= static_cast<T>(v.x);
	y %= static_cast<T>(v.x);
	z %= static_cast<T>(v.x);
	return *this;
}

template <typename T, qualifier Q>
template <typename U>
constexpr VectorT<3, T, Q>& VectorT<3, T, Q>::operator%=(VectorT<3, U, Q> const& v) {
	x %= static_cast<T>(v.x);
	y %= static_cast<T>(v.y);
	z %= static_cast<T>(v.z);
	return *this;
}

template <typename T, qualifier Q>
template <typename U>
constexpr VectorT<3, T, Q>& VectorT<3, T, Q>::operator&=(U scalar) {
	x &= static_cast<T>(scalar);
	y &= static_cast<T>(scalar);
	z &= static_cast<T>(scalar);
	return *this;
}

template <typename T, qualifier Q>
template <typename U>
constexpr VectorT<3, T, Q>& VectorT<3, T, Q>::operator&=(VectorT<1, U, Q> const& v) {
	x &= static_cast<T>(v.x);
	y &= static_cast<T>(v.x);
	z &= static_cast<T>(v.x);
	return *this;
}

template <typename T, qualifier Q>
template <typename U>
constexpr VectorT<3, T, Q>& VectorT<3, T, Q>::operator&=(VectorT<3, U, Q> const& v) {
	x &= static_cast<T>(v.x);
	y &= static_cast<T>(v.y);
	z &= static_cast<T>(v.z);
	return *this;
}

template <typename T, qualifier Q>
template <typename U>
constexpr VectorT<3, T, Q>& VectorT<3, T, Q>::operator|=(U scalar) {
	x |= static_cast<T>(scalar);
	y |= static_cast<T>(scalar);
	z |= static_cast<T>(scalar);
	return *this;
}

template <typename T, qualifier Q>
template <typename U>
constexpr VectorT<3, T, Q>& VectorT<3, T, Q>::operator|=(VectorT<1, U, Q> const& v) {
	x |= static_cast<T>(v.x);
	y |= static_cast<T>(v.x);
	z |= static_cast<T>(v.x);
	return *this;
}

template <typename T, qualifier Q>
template <typename U>
constexpr VectorT<3, T, Q>& VectorT<3, T, Q>::operator|=(VectorT<3, U, Q> const& v) {
	x |= static_cast<T>(v.x);
	y |= static_cast<T>(v.y);
	z |= static_cast<T>(v.z);
	return *this;
}

template <typename T, qualifier Q>
template <typename U>
constexpr VectorT<3, T, Q>& VectorT<3, T, Q>::operator^=(U scalar) {
	x ^= static_cast<T>(scalar);
	y ^= static_cast<T>(scalar);
	z ^= static_cast<T>(scalar);
	return *this;
}

template <typename T, qualifier Q>
template <typename U>
constexpr VectorT<3, T, Q>& VectorT<3, T, Q>::operator^=(VectorT<1, U, Q> const& v) {
	x ^= static_cast<T>(v.x);
	y ^= static_cast<T>(v.x);
	z ^= static_cast<T>(v.x);
	return *this;
}

template <typename T, qualifier Q>
template <typename U>
constexpr VectorT<3, T, Q>& VectorT<3, T, Q>::operator^=(VectorT<3, U, Q> const& v) {
	x ^= static_cast<T>(v.x);
	y ^= static_cast<T>(v.y);
	z ^= static_cast<T>(v.z);
	return *this;
}

template <typename T, qualifier Q>
template <typename U>
constexpr VectorT<3, T, Q>& VectorT<3, T, Q>::operator<<=(U scalar) {
	x <<= static_cast<T>(scalar);
	y <<= static_cast<T>(scalar);
	z <<= static_cast<T>(scalar);
	return *this;
}

template <typename T, qualifier Q>
template <typename U>
constexpr VectorT<3, T, Q>& VectorT<3, T, Q>::operator<<=(VectorT<1, U, Q> const& v) {
	x <<= static_cast<T>(v.x);
	y <<= static_cast<T>(v.x);
	z <<= static_cast<T>(v.x);
	return *this;
}

template <typename T, qualifier Q>
template <typename U>
constexpr VectorT<3, T, Q>& VectorT<3, T, Q>::operator<<=(VectorT<3, U, Q> const& v) {
	x <<= static_cast<T>(v.x);
	y <<= static_cast<T>(v.y);
	z <<= static_cast<T>(v.z);
	return *this;
}

template <typename T, qualifier Q>
template <typename U>
constexpr VectorT<3, T, Q>& VectorT<3, T, Q>::operator>>=(U scalar) {
	x >>= static_cast<T>(scalar);
	y >>= static_cast<T>(scalar);
	z >>= static_cast<T>(scalar);
	return *this;
}

template <typename T, qualifier Q>
template <typename U>
constexpr VectorT<3, T, Q>& VectorT<3, T, Q>::operator>>=(VectorT<1, U, Q> const& v) {
	x >>= static_cast<T>(v.x);
	y >>= static_cast<T>(v.x);
	z >>= static_cast<T>(v.x);
	return *this;
}

template <typename T, qualifier Q>
template <typename U>
constexpr VectorT<3, T, Q>& VectorT<3, T, Q>::operator>>=(VectorT<3, U, Q> const& v) {
	x >>= static_cast<T>(v.x);
	y >>= static_cast<T>(v.y);
	z >>= static_cast<T>(v.z);
	return *this;
}

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator+(VectorT<3, T, Q> const& v) {
	return v;
}

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator-(VectorT<3, T, Q> const& v) {
	return VectorT<3, T, Q>(-v.x, -v.y, -v.z);
}

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator+(VectorT<3, T, Q> const& v, T scalar) {
	return VectorT<3, T, Q>(v.x + scalar, v.y + scalar, v.z + scalar);
}

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator+(VectorT<3, T, Q> const& v, VectorT<1, T, Q> const& sv) {
	return VectorT<3, T, Q>(v.x + sv.x, v.y + sv.x, v.z + sv.x);
}

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator+(T scalar, VectorT<3, T, Q> const& v) {
	return VectorT<3, T, Q>(scalar + v.x, scalar + v.y, scalar + v.z);
}

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator+(VectorT<1, T, Q> const& sv, VectorT<3, T, Q> const& v) {
	return VectorT<3, T, Q>(sv.x + v.x, sv.x + v.y, sv.x + v.z);
}

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator+(VectorT<3, T, Q> const& v1, VectorT<3, T, Q> const& v2) {
	return VectorT<3, T, Q>(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator-(VectorT<3, T, Q> const& v, T scalar) {
	return VectorT<3, T, Q>(v.x - scalar, v.y - scalar, v.z - scalar);
}

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator-(VectorT<3, T, Q> const& v, VectorT<1, T, Q> const& sv) {
	return VectorT<3, T, Q>(v.x - sv.x, v.y - sv.x, v.z - sv.x);
}

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator-(T scalar, VectorT<3, T, Q> const& v) {
	return VectorT<3, T, Q>(scalar - v.x, scalar - v.y, scalar - v.z);
}

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator-(VectorT<1, T, Q> const& sv, VectorT<3, T, Q> const& v) {
	return VectorT<3, T, Q>(sv.x - v.x, sv.x - v.y, sv.x - v.z);
}

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator-(VectorT<3, T, Q> const& v1, VectorT<3, T, Q> const& v2) {
	return VectorT<3, T, Q>(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator*(VectorT<3, T, Q> const& v, T scalar) {
	return VectorT<3, T, Q>(v.x * scalar, v.y * scalar, v.z * scalar);
}

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator*(VectorT<3, T, Q> const& v, VectorT<1, T, Q> const& sv) {
	return VectorT<3, T, Q>(v.x * sv.x, v.y * sv.x, v.z * sv.x);
}

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator*(T scalar, VectorT<3, T, Q> const& v) {
	return VectorT<3, T, Q>(scalar * v.x, scalar * v.y, scalar * v.z);
}

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator*(VectorT<1, T, Q> const& sv, VectorT<3, T, Q> const& v) {
	return VectorT<3, T, Q>(sv.x * v.x, sv.x * v.y, sv.x * v.z);
}

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator*(VectorT<3, T, Q> const& v1, VectorT<3, T, Q> const& v2) {
	return VectorT<3, T, Q>(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);
}

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator/(VectorT<3, T, Q> const& v, T scalar) {
	return VectorT<3, T, Q>(v.x / scalar, v.y / scalar, v.z / scalar);
}

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator/(VectorT<3, T, Q> const& v, VectorT<1, T, Q> const& sv) {
	return VectorT<3, T, Q>(v.x / sv.x, v.y / sv.x, v.z / sv.x);
}

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator/(T scalar, VectorT<3, T, Q> const& v) {
	return VectorT<3, T, Q>(scalar / v.x, scalar / v.y, scalar / v.z);
}

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator/(VectorT<1, T, Q> const& sv, VectorT<3, T, Q> const& v) {
	return VectorT<3, T, Q>(sv.x / v.x, sv.x / v.y, sv.x / v.z);
}

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator/(VectorT<3, T, Q> const& v1, VectorT<3, T, Q> const& v2) {
	return VectorT<3, T, Q>(v1.x / v2.x, v1.y / v2.y, v1.z / v2.z);
}

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator%(VectorT<3, T, Q> const& v, T scalar) {
	return VectorT<3, T, Q>(v.x % scalar, v.y % scalar, v.z % scalar);
}

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator%(VectorT<3, T, Q> const& v, VectorT<1, T, Q> const& sv) {
	return VectorT<3, T, Q>(v.x % sv.x, v.y % sv.x, v.z % sv.x);
}

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator%(T scalar, VectorT<3, T, Q> const& v) {
	return VectorT<3, T, Q>(scalar % v.x, scalar % v.y, scalar % v.z);
}

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator%(VectorT<1, T, Q> const& sv, VectorT<3, T, Q> const& v) {
	return VectorT<3, T, Q>(sv.x % v.x, sv.x % v.y, sv.x % v.z);
}

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator%(VectorT<3, T, Q> const& v1, VectorT<3, T, Q> const& v2) {
	return VectorT<3, T, Q>(v1.x % v2.x, v1.y % v2.y, v1.z % v2.z);
}

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator&(VectorT<3, T, Q> const& v, T scalar) {
	return VectorT<3, T, Q>(v.x & scalar, v.y & scalar, v.z & scalar);
}

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator&(VectorT<3, T, Q> const& v, VectorT<1, T, Q> const& sv) {
	return VectorT<3, T, Q>(v.x & sv.x, v.y & sv.x, v.z & sv.x);
}

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator&(T scalar, VectorT<3, T, Q> const& v) {
	return VectorT<3, T, Q>(scalar & v.x, scalar & v.y, scalar & v.z);
}

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator&(VectorT<1, T, Q> const& sv, VectorT<3, T, Q> const& v) {
	return VectorT<3, T, Q>(sv.x & v.x, sv.x & v.y, sv.x & v.z);
}

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator&(VectorT<3, T, Q> const& v1, VectorT<3, T, Q> const& v2) {
	return VectorT<3, T, Q>(v1.x & v2.x, v1.y & v2.y, v1.z & v2.z);
}

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator|(VectorT<3, T, Q> const& v, T scalar) {
	return VectorT<3, T, Q>(v.x | scalar, v.y | scalar, v.z | scalar);
}

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator|(VectorT<3, T, Q> const& v, VectorT<1, T, Q> const& sv) {
	return VectorT<3, T, Q>(v.x | sv.x, v.y | sv.x, v.z | sv.x);
}

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator|(T scalar, VectorT<3, T, Q> const& v) {
	return VectorT<3, T, Q>(scalar | v.x, scalar | v.y, scalar | v.z);
}

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator|(VectorT<1, T, Q> const& sv, VectorT<3, T, Q> const& v) {
	return VectorT<3, T, Q>(sv.x | v.x, sv.x | v.y, sv.x | v.z);
}

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator|(VectorT<3, T, Q> const& v1, VectorT<3, T, Q> const& v2) {
	return VectorT<3, T, Q>(v1.x | v2.x, v1.y | v2.y, v1.z | v2.z);
}

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator^(VectorT<3, T, Q> const& v, T scalar) {
	return VectorT<3, T, Q>(v.x ^ scalar, v.y ^ scalar, v.z ^ scalar);
}

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator^(VectorT<3, T, Q> const& v, VectorT<1, T, Q> const& sv) {
	return VectorT<3, T, Q>(v.x ^ sv.x, v.y ^ sv.x, v.z ^ sv.x);
}

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator^(T scalar, VectorT<3, T, Q> const& v) {
	return VectorT<3, T, Q>(scalar ^ v.x, scalar ^ v.y, scalar ^ v.z);
}

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator^(VectorT<1, T, Q> const& sv, VectorT<3, T, Q> const& v) {
	return VectorT<3, T, Q>(sv.x ^ v.x, sv.x ^ v.y, sv.x ^ v.z);
}

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator^(VectorT<3, T, Q> const& v1, VectorT<3, T, Q> const& v2) {
	return VectorT<3, T, Q>(v1.x ^ v2.x, v1.y ^ v2.y, v1.z ^ v2.z);
}

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator<<(VectorT<3, T, Q> const& v, T scalar) {
	return VectorT<3, T, Q>(v.x << scalar, v.y << scalar, v.z << scalar);
}

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator<<(VectorT<3, T, Q> const& v, VectorT<1, T, Q> const& sv) {
	return VectorT<3, T, Q>(v.x << sv.x, v.y << sv.x, v.z << sv.x);
}

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator<<(T scalar, VectorT<3, T, Q> const& v) {
	return VectorT<3, T, Q>(scalar << v.x, scalar << v.y, scalar << v.z);
}

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator<<(VectorT<1, T, Q> const& sv, VectorT<3, T, Q> const& v) {
	return VectorT<3, T, Q>(sv.x << v.x, sv.x << v.y, sv.x << v.z);
}

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator<<(VectorT<3, T, Q> const& v1, VectorT<3, T, Q> const& v2) {
	return VectorT<3, T, Q>(v1.x << v2.x, v1.y << v2.y, v1.z << v2.z);
}

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator>>(VectorT<3, T, Q> const& v, T scalar) {
	return VectorT<3, T, Q>(v.x >> scalar, v.y >> scalar, v.z >> scalar);
}

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator>>(VectorT<3, T, Q> const& v, VectorT<1, T, Q> const& sv) {
	return VectorT<3, T, Q>(v.x >> sv.x, v.y >> sv.x, v.z >> sv.x);
}

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator>>(T scalar, VectorT<3, T, Q> const& v) {
	return VectorT<3, T, Q>(scalar >> v.x, scalar >> v.y, scalar >> v.z);
}

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator>>(VectorT<1, T, Q> const& sv, VectorT<3, T, Q> const& v) {
	return VectorT<3, T, Q>(sv.x >> v.x, sv.x >> v.y, sv.x >> v.z);
}

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator>>(VectorT<3, T, Q> const& v1, VectorT<3, T, Q> const& v2) {
	return VectorT<3, T, Q>(v1.x >> v2.x, v1.y >> v2.y, v1.z >> v2.z);
}

template <typename T, qualifier Q>
constexpr VectorT<3, T, Q> operator~(VectorT<3, T, Q> const& v) {
	return VectorT<3, T, Q>(~v.x, ~v.y, ~v.z);
}

template <typename T, qualifier Q>
constexpr bool operator==(VectorT<3, T, Q> const& v1, VectorT<3, T, Q> const& v2) {
	return detail::Equal<T, Q, std::numeric_limits<T>::is_iec559, sizeof(T) * 6, detail::IsAligned<Q>::value>::compute(v1, v2);
}

template <typename T, qualifier Q>
constexpr bool operator!=(VectorT<3, T, Q> const& v1, VectorT<3, T, Q> const& v2) {
	return !(v1 == v2);
}

template <typename T, qualifier Q>
constexpr VectorT<3, bool, Q> operator&&(VectorT<3, T, Q> const& v1, VectorT<3, T, Q> const& v2) {
	return (v1.x && v2.x, v1.y && v2.y, v1.z && v2.z);
}

template <typename T, qualifier Q>
constexpr VectorT<3, bool, Q> operator||(VectorT<3, T, Q> const& v1, VectorT<3, T, Q> const& v2) {
	return (v1.x || v2.x, v1.y || v2.y, v1.z || v2.z);
}
} // namespace mim

#include "mim/detail/func/func_vector3.inl"
