// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#include "mim/detail/compute/compute_vector.hpp"

namespace mim
{

	template <typename T, qualifier Q>
	constexpr T& vec<4, T, Q>::operator[](size_type i)
	{
		switch (i) {
		default:
		case 0: return x;
		case 1: return y;
		case 2: return z;
		case 3: return w;
		}
	}

	template <typename T, qualifier Q>
	constexpr T const& vec<4, T, Q>::operator[](size_type i) const
	{
		switch (i) {
		default:
		case 0: return x;
		case 1: return y;
		case 2: return z;
		case 3: return w;
		}
	}

	/// Constructors

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q>::vec() : x(0), y(0), z(0), w(0)
	{
	}

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q>::vec(T _x, T _y, T _z, T _w) : x(_x), y(_y), z(_z), w(_w)
	{
	}

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q>::vec(vec<4, T, Q> const& v) : x(v.x), y(v.y), z(v.z), w(v.w)
	{
	}

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q>::vec(T scalar) : x(scalar), y(scalar), z(scalar), w(scalar)
	{
	}

	/// Template constructors

	template <typename T, qualifier Q>
	template <qualifier P>
	constexpr vec<4, T, Q>::vec(vec<4, T, P> const& v) : x(v.x), y(v.y), z(v.z), w(v.w)
	{
	}

	template <typename T, qualifier Q>
	template <typename U, qualifier P>
	constexpr vec<4, T, Q>::vec(vec<1, U, P> const& v)
		: x(static_cast<T>(v.x)), y(static_cast<T>(v.x)), z(static_cast<T>(v.x)), w(static_cast<T>(v.x))
	{
	}

	template <typename T, qualifier Q>
	template <typename X, typename Y, typename Z, typename W>
	constexpr vec<4, T, Q>::vec(X _x, Y _y, Z _z, W _w) : x(static_cast<T>(_x)), y(static_cast<T>(_y)), z(static_cast<T>(_z)), w(static_cast<T>(_w))
	{
	}

	template <typename T, qualifier Q>
	template <typename X, typename Y, typename Z, typename W>
	constexpr vec<4, T, Q>::vec(vec<1, X, Q> const& _x, Y _y, Z _z, W _w)
		: x(static_cast<T>(_x.x)), y(static_cast<T>(_y)), z(static_cast<T>(_z)), w(static_cast<T>(_w))
	{
	}

	template <typename T, qualifier Q>
	template <typename X, typename Y, typename Z, typename W>
	constexpr vec<4, T, Q>::vec(X _x, vec<1, Y, Q> const& _y, Z _z, W _w)
		: x(static_cast<T>(_x)), y(static_cast<T>(_y.x)), z(static_cast<T>(_z)), w(static_cast<T>(_w))
	{
	}

	template <typename T, qualifier Q>
	template <typename X, typename Y, typename Z, typename W>
	constexpr vec<4, T, Q>::vec(vec<1, X, Q> const& _x, vec<1, Y, Q> const& _y, Z _z, W _w)
		: x(static_cast<T>(_x.x)), y(static_cast<T>(_y.x)), z(static_cast<T>(_z)), w(static_cast<T>(_w))
	{
	}

	template <typename T, qualifier Q>
	template <typename X, typename Y, typename Z, typename W>
	constexpr vec<4, T, Q>::vec(X _x, Y _y, vec<1, Z, Q> const& _z, W _w)
		: x(static_cast<T>(_x)), y(static_cast<T>(_y)), z(static_cast<T>(_z.x)), w(static_cast<T>(_w))
	{
	}

	template <typename T, qualifier Q>
	template <typename X, typename Y, typename Z, typename W>
	constexpr vec<4, T, Q>::vec(vec<1, X, Q> const& _x, Y _y, vec<1, Z, Q> const& _z, W _w)
		: x(static_cast<T>(_x.x)), y(static_cast<T>(_y)), z(static_cast<T>(_z.x)), w(static_cast<T>(_w))
	{
	}

	template <typename T, qualifier Q>
	template <typename X, typename Y, typename Z, typename W>
	constexpr vec<4, T, Q>::vec(X _x, vec<1, Y, Q> const& _y, vec<1, Z, Q> const& _z, W _w)
		: x(static_cast<T>(_x)), y(static_cast<T>(_y.x)), z(static_cast<T>(_z.x)), w(static_cast<T>(_w))
	{
	}

	template <typename T, qualifier Q>
	template <typename X, typename Y, typename Z, typename W>
	constexpr vec<4, T, Q>::vec(vec<1, X, Q> const& _x, vec<1, Y, Q> const& _y, vec<1, Z, Q> const& _z, W _w)
		: x(static_cast<T>(_x.x)), y(static_cast<T>(_y.x)), z(static_cast<T>(_z.x)), w(static_cast<T>(_w))
	{
	}

	template <typename T, qualifier Q>
	template <typename X, typename Y, typename Z, typename W>
	constexpr vec<4, T, Q>::vec(vec<1, X, Q> const& _x, Y _y, Z _z, vec<1, W, Q> const& _w)
		: x(static_cast<T>(_x.x)), y(static_cast<T>(_y)), z(static_cast<T>(_z)), w(static_cast<T>(_w.x))
	{
	}

	template <typename T, qualifier Q>
	template <typename X, typename Y, typename Z, typename W>
	constexpr vec<4, T, Q>::vec(X _x, vec<1, Y, Q> const& _y, Z _z, vec<1, W, Q> const& _w)
		: x(static_cast<T>(_x)), y(static_cast<T>(_y.x)), z(static_cast<T>(_z)), w(static_cast<T>(_w.x))
	{
	}

	template <typename T, qualifier Q>
	template <typename X, typename Y, typename Z, typename W>
	constexpr vec<4, T, Q>::vec(vec<1, X, Q> const& _x, vec<1, Y, Q> const& _y, Z _z, vec<1, W, Q> const& _w)
		: x(static_cast<T>(_x.x)), y(static_cast<T>(_y.x)), z(static_cast<T>(_z)), w(static_cast<T>(_w.x))
	{
	}

	template <typename T, qualifier Q>
	template <typename X, typename Y, typename Z, typename W>
	constexpr vec<4, T, Q>::vec(X _x, Y _y, vec<1, Z, Q> const& _z, vec<1, W, Q> const& _w)
		: x(static_cast<T>(_x)), y(static_cast<T>(_y)), z(static_cast<T>(_z.x)), w(static_cast<T>(_w.x))
	{
	}

	template <typename T, qualifier Q>
	template <typename X, typename Y, typename Z, typename W>
	constexpr vec<4, T, Q>::vec(vec<1, X, Q> const& _x, Y _y, vec<1, Z, Q> const& _z, vec<1, W, Q> const& _w)
		: x(static_cast<T>(_x.x)), y(static_cast<T>(_y)), z(static_cast<T>(_z.x)), w(static_cast<T>(_w.x))
	{
	}

	template <typename T, qualifier Q>
	template <typename X, typename Y, typename Z, typename W>
	constexpr vec<4, T, Q>::vec(X _x, vec<1, Y, Q> const& _y, vec<1, Z, Q> const& _z, vec<1, W, Q> const& _w)
		: x(static_cast<T>(_x)), y(static_cast<T>(_y.x)), z(static_cast<T>(_z.x)), w(static_cast<T>(_w.x))
	{
	}

	template <typename T, qualifier Q>
	template <typename X, typename Y, typename Z, typename W>
	constexpr vec<4, T, Q>::vec(vec<1, X, Q> const& _x, vec<1, Y, Q> const& _y, vec<1, Z, Q> const& _z, vec<1, W, Q> const& _w)
		: x(static_cast<T>(_x.x)), y(static_cast<T>(_y.x)), z(static_cast<T>(_z.x)), w(static_cast<T>(_w.x))
	{
	}

	template <typename T, qualifier Q>
	template <typename A, typename B, typename C, qualifier P>
	constexpr vec<4, T, Q>::vec(vec<2, A, P> const& _xy, B _z, C _w)
		: x(static_cast<T>(_xy.x)), y(static_cast<T>(_xy.y)), z(static_cast<T>(_z)), w(static_cast<T>(_w))
	{
	}

	template <typename T, qualifier Q>
	template <typename A, typename B, typename C, qualifier P>
	constexpr vec<4, T, Q>::vec(vec<2, A, P> const& _xy, vec<1, B, P> const& _z, C _w)
		: x(static_cast<T>(_xy.x)), y(static_cast<T>(_xy.y)), z(static_cast<T>(_z.x)), w(static_cast<T>(_w))
	{
	}

	template <typename T, qualifier Q>
	template <typename A, typename B, typename C, qualifier P>
	constexpr vec<4, T, Q>::vec(vec<2, A, P> const& _xy, B _z, vec<1, C, P> const& _w)
		: x(static_cast<T>(_xy.x)), y(static_cast<T>(_xy.y)), z(static_cast<T>(_z)), w(static_cast<T>(_w.x))
	{
	}

	template <typename T, qualifier Q>
	template <typename A, typename B, typename C, qualifier P>
	constexpr vec<4, T, Q>::vec(vec<2, A, P> const& _xy, vec<1, B, P> const& _z, vec<1, C, P> const& _w)
		: x(static_cast<T>(_xy.x)), y(static_cast<T>(_xy.y)), z(static_cast<T>(_z.x)), w(static_cast<T>(_w.x))
	{
	}

	template <typename T, qualifier Q>
	template <typename A, typename B, typename C, qualifier P>
	constexpr vec<4, T, Q>::vec(A _x, vec<2, B, P> const& _yz, C _w)
		: x(static_cast<T>(_x)), y(static_cast<T>(_yz.x)), z(static_cast<T>(_yz.y)), w(static_cast<T>(_w))
	{
	}

	template <typename T, qualifier Q>
	template <typename A, typename B, typename C, qualifier P>
	constexpr vec<4, T, Q>::vec(vec<1, A, P> const& _x, vec<2, B, P> const& _yz, C _w)
		: x(static_cast<T>(_x.x)), y(static_cast<T>(_yz.x)), z(static_cast<T>(_yz.y)), w(static_cast<T>(_w))
	{
	}

	template <typename T, qualifier Q>
	template <typename A, typename B, typename C, qualifier P>
	constexpr vec<4, T, Q>::vec(A _x, vec<2, B, P> const& _yz, vec<1, C, P> const& _w)
		: x(static_cast<T>(_x)), y(static_cast<T>(_yz.x)), z(static_cast<T>(_yz.y)), w(static_cast<T>(_w.x))
	{
	}

	template <typename T, qualifier Q>
	template <typename A, typename B, typename C, qualifier P>
	constexpr vec<4, T, Q>::vec(vec<1, A, P> const& _x, vec<2, B, P> const& _yz, vec<1, C, P> const& _w)
		: x(static_cast<T>(_x.x)), y(static_cast<T>(_yz.x)), z(static_cast<T>(_yz.y)), w(static_cast<T>(_w.x))
	{
	}

	template <typename T, qualifier Q>
	template <typename A, typename B, typename C, qualifier P>
	constexpr vec<4, T, Q>::vec(A _x, B _y, vec<2, C, P> const& _zw)
		: x(static_cast<T>(_x)), y(static_cast<T>(_y)), z(static_cast<T>(_zw.x)), w(static_cast<T>(_zw.y))
	{
	}

	template <typename T, qualifier Q>
	template <typename A, typename B, typename C, qualifier P>
	constexpr vec<4, T, Q>::vec(vec<1, A, P> const& _x, B _y, vec<2, C, P> const& _zw)
		: x(static_cast<T>(_x.x)), y(static_cast<T>(_y)), z(static_cast<T>(_zw.x)), w(static_cast<T>(_zw.y))
	{
	}

	template <typename T, qualifier Q>
	template <typename A, typename B, typename C, qualifier P>
	constexpr vec<4, T, Q>::vec(A _x, vec<1, B, P> const& _y, vec<2, C, P> const& _zw)
		: x(static_cast<T>(_x)), y(static_cast<T>(_y.x)), z(static_cast<T>(_zw.x)), w(static_cast<T>(_zw.y))
	{
	}

	template <typename T, qualifier Q>
	template <typename A, typename B, typename C, qualifier P>
	constexpr vec<4, T, Q>::vec(vec<1, A, P> const& _x, vec<1, B, P> const& _y, vec<2, C, P> const& _zw)
		: x(static_cast<T>(_x.x)), y(static_cast<T>(_y.x)), z(static_cast<T>(_zw.x)), w(static_cast<T>(_zw.y))
	{
	}

	template <typename T, qualifier Q>
	template <typename A, typename B, qualifier P>
	constexpr vec<4, T, Q>::vec(vec<3, A, P> const& _xyz, B _w)
		: x(static_cast<T>(_xyz.x)), y(static_cast<T>(_xyz.y)), z(static_cast<T>(_xyz.z)), w(static_cast<T>(_w))
	{
	}

	template <typename T, qualifier Q>
	template <typename A, typename B, qualifier P>
	constexpr vec<4, T, Q>::vec(vec<3, A, P> const& _xyz, vec<1, B, P> const& _w)
		: x(static_cast<T>(_xyz.x)), y(static_cast<T>(_xyz.y)), z(static_cast<T>(_xyz.z)), w(static_cast<T>(_w.x))
	{
	}

	template <typename T, qualifier Q>
	template <typename A, typename B, qualifier P>
	constexpr vec<4, T, Q>::vec(A _x, vec<3, B, P> const& _yzw)
		: x(static_cast<T>(_x)), y(static_cast<T>(_yzw.x)), z(static_cast<T>(_yzw.y)), w(static_cast<T>(_yzw.z))
	{
	}

	template <typename T, qualifier Q>
	template <typename A, typename B, qualifier P>
	constexpr vec<4, T, Q>::vec(vec<1, A, P> const& _x, vec<3, B, P> const& _yzw)
		: x(static_cast<T>(_x.x)), y(static_cast<T>(_yzw.x)), z(static_cast<T>(_yzw.y)), w(static_cast<T>(_yzw.z))
	{
	}

	template <typename T, qualifier Q>
	template <typename A, typename B, qualifier P>
	constexpr vec<4, T, Q>::vec(vec<2, A, P> const& _xy, vec<2, B, P> const& _zw)
		: x(static_cast<T>(_xy.x)), y(static_cast<T>(_xy.y)), z(static_cast<T>(_zw.x)), w(static_cast<T>(_zw.y))
	{
	}

	template <typename T, qualifier Q>
	template <typename U, qualifier P>
	constexpr vec<4, T, Q>::vec(vec<4, U, P> const& v)
		: x(static_cast<T>(v.x)), y(static_cast<T>(v.y)), z(static_cast<T>(v.z)), w(static_cast<T>(v.w))
	{
	}

	/// Assignment operators

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q>& vec<4, T, Q>::operator=(vec<4, T, Q> const& v)
	{
		this->x = v.x;
		this->y = v.y;
		this->z = v.z;
		this->w = v.w;
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<4, T, Q>& vec<4, T, Q>::operator=(vec<4, U, Q> const& v)
	{
		this->x = static_cast<T>(v.x);
		this->y = static_cast<T>(v.y);
		this->z = static_cast<T>(v.z);
		this->w = static_cast<T>(v.w);
		return *this;
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<4, T, Q>& vec<4, T, Q>::operator+=(U scalar)
	{
		return (*this = detail::Add<T, Q, detail::IsAligned<Q>::value>::compute(*this, vec<4, T, Q>(scalar)));
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<4, T, Q>& vec<4, T, Q>::operator+=(vec<1, U, Q> const& v)
	{
		return (*this = detail::Add<T, Q, detail::IsAligned<Q>::value>::compute(*this, vec<4, T, Q>(v.x)));
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<4, T, Q>& vec<4, T, Q>::operator+=(vec<4, U, Q> const& v)
	{
		return (*this = detail::Add<T, Q, detail::IsAligned<Q>::value>::compute(*this, vec<4, T, Q>(v)));
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<4, T, Q>& vec<4, T, Q>::operator-=(U scalar)
	{
		return (*this = detail::Sub<T, Q, detail::IsAligned<Q>::value>::compute(*this, vec<4, T, Q>(scalar)));
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<4, T, Q>& vec<4, T, Q>::operator-=(vec<1, U, Q> const& v)
	{
		return (*this = detail::Sub<T, Q, detail::IsAligned<Q>::value>::compute(*this, vec<4, T, Q>(v.x)));
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<4, T, Q>& vec<4, T, Q>::operator-=(vec<4, U, Q> const& v)
	{
		return (*this = detail::Sub<T, Q, detail::IsAligned<Q>::value>::compute(*this, vec<4, T, Q>(v)));
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<4, T, Q>& vec<4, T, Q>::operator*=(U scalar)
	{
		return (*this = detail::Mul<T, Q, detail::IsAligned<Q>::value>::compute(*this, vec<4, T, Q>(scalar)));
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<4, T, Q>& vec<4, T, Q>::operator*=(vec<1, U, Q> const& v)
	{
		return (*this = detail::Mul<T, Q, detail::IsAligned<Q>::value>::compute(*this, vec<4, T, Q>(v.x)));
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<4, T, Q>& vec<4, T, Q>::operator*=(vec<4, U, Q> const& v)
	{
		return (*this = detail::Mul<T, Q, detail::IsAligned<Q>::value>::compute(*this, vec<4, T, Q>(v)));
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<4, T, Q>& vec<4, T, Q>::operator/=(U scalar)
	{
		return (*this = detail::Div<T, Q, detail::IsAligned<Q>::value>::compute(*this, vec<4, T, Q>(scalar)));
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<4, T, Q>& vec<4, T, Q>::operator/=(vec<1, U, Q> const& v)
	{
		return (*this = detail::Div<T, Q, detail::IsAligned<Q>::value>::compute(*this, vec<4, T, Q>(v.x)));
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<4, T, Q>& vec<4, T, Q>::operator/=(vec<4, U, Q> const& v)
	{
		return (*this = detail::Div<T, Q, detail::IsAligned<Q>::value>::compute(*this, vec<4, T, Q>(v)));
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<4, T, Q>& vec<4, T, Q>::operator%=(U scalar)
	{
		return (*this = detail::Mod<T, Q, detail::IsAligned<Q>::value>::compute(*this, vec<4, T, Q>(scalar)));
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<4, T, Q>& vec<4, T, Q>::operator%=(vec<1, U, Q> const& v)
	{
		return (*this = detail::Mod<T, Q, detail::IsAligned<Q>::value>::compute(*this, vec<4, T, Q>(v)));
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<4, T, Q>& vec<4, T, Q>::operator%=(vec<4, U, Q> const& v)
	{
		return (*this = detail::Mod<T, Q, detail::IsAligned<Q>::value>::compute(*this, vec<4, T, Q>(v)));
	}

	/// Increment and Decrement Operators

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q>& vec<4, T, Q>::operator++()
	{
		++this->x;
		++this->y;
		++this->z;
		++this->w;
		return *this;
	}

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q>& vec<4, T, Q>::operator--()
	{
		--this->x;
		--this->y;
		--this->z;
		--this->w;
		return *this;
	}

	template <typename T, qualifier Q>
	constexpr const vec<4, T, Q> vec<4, T, Q>::operator++(int)
	{
		vec<4, T, Q> result(*this);
		++*this;
		return result;
	}

	template <typename T, qualifier Q>
	constexpr const vec<4, T, Q> vec<4, T, Q>::operator--(int)
	{
		vec<4, T, Q> result(*this);
		--*this;
		return result;
	}

	/// Bitwise Assignment Operators

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<4, T, Q>& vec<4, T, Q>::operator&=(U scalar)
	{
		return (*this = detail::BitwiseAnd<T, Q, std::numeric_limits<T>::is_iec559, sizeof(T) * 8, detail::IsAligned<Q>::value>::compute(
					*this, vec<4, T, Q>(scalar)));
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<4, T, Q>& vec<4, T, Q>::operator&=(vec<1, U, Q> const& v)
	{
		return (*this = detail::BitwiseAnd<T, Q, std::numeric_limits<T>::is_iec559, sizeof(T) * 8, detail::IsAligned<Q>::value>::compute(*this,
																																		 vec<4, T, Q>(v)));
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<4, T, Q>& vec<4, T, Q>::operator&=(vec<4, U, Q> const& v)
	{
		return (*this = detail::BitwiseAnd<T, Q, std::numeric_limits<T>::is_iec559, sizeof(T) * 8, detail::IsAligned<Q>::value>::compute(*this,
																																		 vec<4, T, Q>(v)));
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<4, T, Q>& vec<4, T, Q>::operator|=(U scalar)
	{
		return (*this = detail::BitwiseOr<T, Q, std::numeric_limits<T>::is_iec559, sizeof(T) * 8, detail::IsAligned<Q>::value>::compute(
					*this, vec<4, T, Q>(scalar)));
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<4, T, Q>& vec<4, T, Q>::operator|=(vec<1, U, Q> const& v)
	{
		return (*this = detail::BitwiseOr<T, Q, std::numeric_limits<T>::is_iec559, sizeof(T) * 8, detail::IsAligned<Q>::value>::compute(*this,
																																		vec<4, T, Q>(v)));
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<4, T, Q>& vec<4, T, Q>::operator|=(vec<4, U, Q> const& v)
	{
		return (*this = detail::BitwiseOr<T, Q, std::numeric_limits<T>::is_iec559, sizeof(T) * 8, detail::IsAligned<Q>::value>::compute(*this,
																																		vec<4, T, Q>(v)));
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<4, T, Q>& vec<4, T, Q>::operator^=(U scalar)
	{
		return (*this =
					detail::Xor<T, Q, std::numeric_limits<T>::is_iec559, sizeof(T) * 8, detail::IsAligned<Q>::value>::compute(*this, vec<4, T, Q>(scalar)));
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<4, T, Q>& vec<4, T, Q>::operator^=(vec<1, U, Q> const& v)
	{
		return (*this = detail::Xor<T, Q, std::numeric_limits<T>::is_iec559, sizeof(T) * 8, detail::IsAligned<Q>::value>::compute(*this, vec<4, T, Q>(v)));
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<4, T, Q>& vec<4, T, Q>::operator^=(vec<4, U, Q> const& v)
	{
		return (*this = detail::Xor<T, Q, std::numeric_limits<T>::is_iec559, sizeof(T) * 8, detail::IsAligned<Q>::value>::compute(*this, vec<4, T, Q>(v)));
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<4, T, Q>& vec<4, T, Q>::operator<<=(U scalar)
	{
		return (*this = detail::ShiftLeft<T, Q, std::numeric_limits<T>::is_iec559, sizeof(T) * 8, detail::IsAligned<Q>::value>::compute(
					*this, vec<4, T, Q>(scalar)));
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<4, T, Q>& vec<4, T, Q>::operator<<=(vec<1, U, Q> const& v)
	{
		return (*this = detail::ShiftLeft<T, Q, std::numeric_limits<T>::is_iec559, sizeof(T) * 8, detail::IsAligned<Q>::value>::compute(*this,
																																		vec<4, T, Q>(v)));
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<4, T, Q>& vec<4, T, Q>::operator<<=(vec<4, U, Q> const& v)
	{
		return (*this = detail::ShiftLeft<T, Q, std::numeric_limits<T>::is_iec559, sizeof(T) * 8, detail::IsAligned<Q>::value>::compute(*this,
																																		vec<4, T, Q>(v)));
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<4, T, Q>& vec<4, T, Q>::operator>>=(U scalar)
	{
		return (*this = detail::ShiftRight<T, Q, std::numeric_limits<T>::is_iec559, sizeof(T) * 8, detail::IsAligned<Q>::value>::compute(
					*this, vec<4, T, Q>(scalar)));
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<4, T, Q>& vec<4, T, Q>::operator>>=(vec<1, U, Q> const& v)
	{
		return (*this = detail::ShiftRight<T, Q, std::numeric_limits<T>::is_iec559, sizeof(T) * 8, detail::IsAligned<Q>::value>::compute(*this,
																																		 vec<4, T, Q>(v)));
	}

	template <typename T, qualifier Q>
	template <typename U>
	constexpr vec<4, T, Q>& vec<4, T, Q>::operator>>=(vec<4, U, Q> const& v)
	{
		return (*this = detail::ShiftRight<T, Q, std::numeric_limits<T>::is_iec559, sizeof(T) * 8, detail::IsAligned<Q>::value>::compute(*this,
																																		 vec<4, T, Q>(v)));
	}

	/// Unary Operators

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator+(vec<4, T, Q> const& v)
	{
		return v;
	}

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator-(vec<4, T, Q> const& v)
	{
		return vec<4, T, Q>(0) -= v;
	}

	/// Binary Operators

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator+(vec<4, T, Q> const& v, T const& scalar)
	{
		return vec<4, T, Q>(v) += scalar;
	}

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator+(T scalar, vec<4, T, Q> const& v)
	{
		return vec<4, T, Q>(v) += scalar;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator+(vec<4, T, Q> const& v1, vec<1, T, Q> const& v2)
	{
		return vec<4, T, Q>(v1) += v2;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator+(vec<1, T, Q> const& v1, vec<4, T, Q> const& v2)
	{
		return vec<4, T, Q>(v2) += v1;
	}

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator+(vec<4, T, Q> const& v1, vec<4, T, Q> const& v2)
	{
		return vec<4, T, Q>(v1) += v2;
	}

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator-(vec<4, T, Q> const& v, T const& scalar)
	{
		return vec<4, T, Q>(v) -= scalar;
	}

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator-(T scalar, vec<4, T, Q> const& v)
	{
		return vec<4, T, Q>(scalar) -= v;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator-(vec<4, T, Q> const& v1, vec<1, T, Q> const& v2)
	{
		return vec<4, T, Q>(v1) -= v2;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator-(vec<1, T, Q> const& v1, vec<4, T, Q> const& v2)
	{
		return vec<4, T, Q>(v1.x) -= v2;
	}

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator-(vec<4, T, Q> const& v1, vec<4, T, Q> const& v2)
	{
		return vec<4, T, Q>(v1) -= v2;
	}

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator*(vec<4, T, Q> const& v, T const& scalar)
	{
		return vec<4, T, Q>(v) *= scalar;
	}

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator*(T scalar, vec<4, T, Q> const& v)
	{
		return vec<4, T, Q>(v) *= scalar;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator*(vec<4, T, Q> const& v1, vec<1, T, Q> const& v2)
	{
		return vec<4, T, Q>(v1) *= v2;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator*(vec<1, T, Q> const& v1, vec<4, T, Q> const& v2)
	{
		return vec<4, T, Q>(v2) *= v1;
	}

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator*(vec<4, T, Q> const& v1, vec<4, T, Q> const& v2)
	{
		return vec<4, T, Q>(v1) *= v2;
	}

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator/(vec<4, T, Q> const& v, T const& scalar)
	{
		return vec<4, T, Q>(v) /= scalar;
	}

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator/(T scalar, vec<4, T, Q> const& v)
	{
		return vec<4, T, Q>(scalar) /= v;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator/(vec<4, T, Q> const& v1, vec<1, T, Q> const& v2)
	{
		return vec<4, T, Q>(v1) /= v2;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator/(vec<1, T, Q> const& v1, vec<4, T, Q> const& v2)
	{
		return vec<4, T, Q>(v1.x) /= v2;
	}

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator/(vec<4, T, Q> const& v1, vec<4, T, Q> const& v2)
	{
		return vec<4, T, Q>(v1) /= v2;
	}

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator%(vec<4, T, Q> const& v, T scalar)
	{
		return vec<4, T, Q>(v) %= scalar;
	}

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator%(T scalar, vec<4, T, Q> const& v)
	{
		return vec<4, T, Q>(scalar) %= v;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator%(vec<4, T, Q> const& v1, vec<1, T, Q> const& v2)
	{
		return vec<4, T, Q>(v1) %= v2.x;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator%(vec<1, T, Q> const& scalar, vec<4, T, Q> const& v)
	{
		return vec<4, T, Q>(scalar.x) %= v;
	}

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator%(vec<4, T, Q> const& v1, vec<4, T, Q> const& v2)
	{
		return vec<4, T, Q>(v1) %= v2;
	}

	/// Bitwise Binary Operators

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator&(vec<4, T, Q> const& v, T scalar)
	{
		return vec<4, T, Q>(v) &= scalar;
	}

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator&(T scalar, vec<4, T, Q> const& v)
	{
		return vec<4, T, Q>(scalar) &= v;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator&(vec<4, T, Q> const& v, vec<1, T, Q> const& scalar)
	{
		return vec<4, T, Q>(v) &= scalar;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator&(vec<1, T, Q> const& v1, vec<4, T, Q> const& v2)
	{
		return vec<4, T, Q>(v1.x) &= v2;
	}

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator&(vec<4, T, Q> const& v1, vec<4, T, Q> const& v2)
	{
		return vec<4, T, Q>(v1) &= v2;
	}

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator|(vec<4, T, Q> const& v, T scalar)
	{
		return vec<4, T, Q>(v) |= scalar;
	}

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator|(T scalar, vec<4, T, Q> const& v)
	{
		return vec<4, T, Q>(scalar) |= v;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator|(vec<4, T, Q> const& v1, vec<1, T, Q> const& v2)
	{
		return vec<4, T, Q>(v1) |= v2.x;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator|(vec<1, T, Q> const& v1, vec<4, T, Q> const& v2)
	{
		return vec<4, T, Q>(v1.x) |= v2;
	}

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator|(vec<4, T, Q> const& v1, vec<4, T, Q> const& v2)
	{
		return vec<4, T, Q>(v1) |= v2;
	}

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator^(vec<4, T, Q> const& v, T scalar)
	{
		return vec<4, T, Q>(v) ^= scalar;
	}

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator^(T scalar, vec<4, T, Q> const& v)
	{
		return vec<4, T, Q>(scalar) ^= v;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator^(vec<4, T, Q> const& v1, vec<1, T, Q> const& v2)
	{
		return vec<4, T, Q>(v1) ^= v2.x;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator^(vec<1, T, Q> const& v1, vec<4, T, Q> const& v2)
	{
		return vec<4, T, Q>(v1.x) ^= v2;
	}

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator^(vec<4, T, Q> const& v1, vec<4, T, Q> const& v2)
	{
		return vec<4, T, Q>(v1) ^= v2;
	}

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator<<(vec<4, T, Q> const& v, T scalar)
	{
		return vec<4, T, Q>(v) <<= scalar;
	}

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator<<(T scalar, vec<4, T, Q> const& v)
	{
		return vec<4, T, Q>(scalar) <<= v;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator<<(vec<4, T, Q> const& v1, vec<1, T, Q> const& v2)
	{
		return vec<4, T, Q>(v1) <<= v2.x;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator<<(vec<1, T, Q> const& v1, vec<4, T, Q> const& v2)
	{
		return vec<4, T, Q>(v1.x) <<= v2;
	}

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator<<(vec<4, T, Q> const& v1, vec<4, T, Q> const& v2)
	{
		return vec<4, T, Q>(v1) <<= v2;
	}

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator>>(vec<4, T, Q> const& v, T scalar)
	{
		return vec<4, T, Q>(v) >>= scalar;
	}

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator>>(T scalar, vec<4, T, Q> const& v)
	{
		return vec<4, T, Q>(scalar) >>= v;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator>>(vec<4, T, Q> const& v1, vec<1, T, Q> const& v2)
	{
		return vec<4, T, Q>(v1) >>= v2.x;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator>>(vec<1, T, Q> const& v1, vec<4, T, Q> const& v2)
	{
		return vec<4, T, Q>(v1.x) >>= v2;
	}

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator>>(vec<4, T, Q> const& v1, vec<4, T, Q> const& v2)
	{
		return vec<4, T, Q>(v1) >>= v2;
	}

	template <typename T, qualifier Q>
	constexpr vec<4, T, Q> operator~(vec<4, T, Q> const& v)
	{
		return detail::BitwiseNot<T, Q, std::numeric_limits<T>::is_iec559, sizeof(T) * 8, detail::IsAligned<Q>::value>::compute(v);
	}

	/// Conditional Operators

	template <typename T, qualifier Q>
	constexpr bool operator==(vec<4, T, Q> const& v1, vec<4, T, Q> const& v2)
	{
		return detail::Equal<T, Q, std::numeric_limits<T>::is_iec559, sizeof(T) * 8, detail::IsAligned<Q>::value>::compute(v1, v2);
	}

	template <typename T, qualifier Q>
	constexpr bool operator!=(vec<4, T, Q> const& v1, vec<4, T, Q> const& v2)
	{
		return detail::NotEqual<T, Q, std::numeric_limits<T>::is_iec559, sizeof(T) * 8, detail::IsAligned<Q>::value>::compute(v1, v2);
	}

	template <qualifier Q>
	constexpr bool operator&&(vec<4, bool, Q> const& v1, vec<4, bool, Q> const& v2)
	{
		return (v1.x && v2.x, v1.y && v2.y, v1.z && v2.z, v1.w && v2.w);
	}

	template <qualifier Q>
	constexpr bool operator||(vec<4, bool, Q> const& v1, vec<4, bool, Q> const& v2)
	{
		return (v1.x || v2.x, v1.y || v2.y, v1.z || v2.z, v1.w || v2.w);
	}

} // namespace mim
