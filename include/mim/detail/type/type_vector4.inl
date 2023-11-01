// Copyright (c) 2023-Present Mim contributors (see LICENSE)


namespace mim
{

	template <typename T>
	constexpr T& vec<4, T>::operator[](size_type i)
	{
		switch (i) {
		default:
		case 0: return x;
		case 1: return y;
		case 2: return z;
		case 3: return w;
		}
	}

	template <typename T>
	constexpr T const& vec<4, T>::operator[](size_type i) const
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

	template <typename T>
	constexpr vec<4, T>::vec() : x(0), y(0), z(0), w(0)
	{
	}

	template <typename T>
	constexpr vec<4, T>::vec(T _x, T _y, T _z, T _w) : x(_x), y(_y), z(_z), w(_w)
	{
	}

	template <typename T>
	constexpr vec<4, T>::vec(vec<4, T> const& v) : x(v.x), y(v.y), z(v.z), w(v.w)
	{
	}

	template <typename T>
	constexpr vec<4, T>::vec(T scalar) : x(scalar), y(scalar), z(scalar), w(scalar)
	{
	}

	template <typename T>
	template <typename U>
	constexpr vec<4, T>::vec(vec<1, U> const& v)
		: x(static_cast<T>(v.x)), y(static_cast<T>(v.x)), z(static_cast<T>(v.x)), w(static_cast<T>(v.x))
	{
	}

	template <typename T>
	template <typename X, typename Y, typename Z, typename W>
	constexpr vec<4, T>::vec(X _x, Y _y, Z _z, W _w) : x(static_cast<T>(_x)), y(static_cast<T>(_y)), z(static_cast<T>(_z)), w(static_cast<T>(_w))
	{
	}

	template <typename T>
	template <typename X, typename Y, typename Z, typename W>
	constexpr vec<4, T>::vec(vec<1, X> const& _x, Y _y, Z _z, W _w)
		: x(static_cast<T>(_x.x)), y(static_cast<T>(_y)), z(static_cast<T>(_z)), w(static_cast<T>(_w))
	{
	}

	template <typename T>
	template <typename X, typename Y, typename Z, typename W>
	constexpr vec<4, T>::vec(X _x, vec<1, Y> const& _y, Z _z, W _w)
		: x(static_cast<T>(_x)), y(static_cast<T>(_y.x)), z(static_cast<T>(_z)), w(static_cast<T>(_w))
	{
	}

	template <typename T>
	template <typename X, typename Y, typename Z, typename W>
	constexpr vec<4, T>::vec(vec<1, X> const& _x, vec<1, Y> const& _y, Z _z, W _w)
		: x(static_cast<T>(_x.x)), y(static_cast<T>(_y.x)), z(static_cast<T>(_z)), w(static_cast<T>(_w))
	{
	}

	template <typename T>
	template <typename X, typename Y, typename Z, typename W>
	constexpr vec<4, T>::vec(X _x, Y _y, vec<1, Z> const& _z, W _w)
		: x(static_cast<T>(_x)), y(static_cast<T>(_y)), z(static_cast<T>(_z.x)), w(static_cast<T>(_w))
	{
	}

	template <typename T>
	template <typename X, typename Y, typename Z, typename W>
	constexpr vec<4, T>::vec(vec<1, X> const& _x, Y _y, vec<1, Z> const& _z, W _w)
		: x(static_cast<T>(_x.x)), y(static_cast<T>(_y)), z(static_cast<T>(_z.x)), w(static_cast<T>(_w))
	{
	}

	template <typename T>
	template <typename X, typename Y, typename Z, typename W>
	constexpr vec<4, T>::vec(X _x, vec<1, Y> const& _y, vec<1, Z> const& _z, W _w)
		: x(static_cast<T>(_x)), y(static_cast<T>(_y.x)), z(static_cast<T>(_z.x)), w(static_cast<T>(_w))
	{
	}

	template <typename T>
	template <typename X, typename Y, typename Z, typename W>
	constexpr vec<4, T>::vec(vec<1, X> const& _x, vec<1, Y> const& _y, vec<1, Z> const& _z, W _w)
		: x(static_cast<T>(_x.x)), y(static_cast<T>(_y.x)), z(static_cast<T>(_z.x)), w(static_cast<T>(_w))
	{
	}

	template <typename T>
	template <typename X, typename Y, typename Z, typename W>
	constexpr vec<4, T>::vec(vec<1, X> const& _x, Y _y, Z _z, vec<1, W> const& _w)
		: x(static_cast<T>(_x.x)), y(static_cast<T>(_y)), z(static_cast<T>(_z)), w(static_cast<T>(_w.x))
	{
	}

	template <typename T>
	template <typename X, typename Y, typename Z, typename W>
	constexpr vec<4, T>::vec(X _x, vec<1, Y> const& _y, Z _z, vec<1, W> const& _w)
		: x(static_cast<T>(_x)), y(static_cast<T>(_y.x)), z(static_cast<T>(_z)), w(static_cast<T>(_w.x))
	{
	}

	template <typename T>
	template <typename X, typename Y, typename Z, typename W>
	constexpr vec<4, T>::vec(vec<1, X> const& _x, vec<1, Y> const& _y, Z _z, vec<1, W> const& _w)
		: x(static_cast<T>(_x.x)), y(static_cast<T>(_y.x)), z(static_cast<T>(_z)), w(static_cast<T>(_w.x))
	{
	}

	template <typename T>
	template <typename X, typename Y, typename Z, typename W>
	constexpr vec<4, T>::vec(X _x, Y _y, vec<1, Z> const& _z, vec<1, W> const& _w)
		: x(static_cast<T>(_x)), y(static_cast<T>(_y)), z(static_cast<T>(_z.x)), w(static_cast<T>(_w.x))
	{
	}

	template <typename T>
	template <typename X, typename Y, typename Z, typename W>
	constexpr vec<4, T>::vec(vec<1, X> const& _x, Y _y, vec<1, Z> const& _z, vec<1, W> const& _w)
		: x(static_cast<T>(_x.x)), y(static_cast<T>(_y)), z(static_cast<T>(_z.x)), w(static_cast<T>(_w.x))
	{
	}

	template <typename T>
	template <typename X, typename Y, typename Z, typename W>
	constexpr vec<4, T>::vec(X _x, vec<1, Y> const& _y, vec<1, Z> const& _z, vec<1, W> const& _w)
		: x(static_cast<T>(_x)), y(static_cast<T>(_y.x)), z(static_cast<T>(_z.x)), w(static_cast<T>(_w.x))
	{
	}

	template <typename T>
	template <typename X, typename Y, typename Z, typename W>
	constexpr vec<4, T>::vec(vec<1, X> const& _x, vec<1, Y> const& _y, vec<1, Z> const& _z, vec<1, W> const& _w)
		: x(static_cast<T>(_x.x)), y(static_cast<T>(_y.x)), z(static_cast<T>(_z.x)), w(static_cast<T>(_w.x))
	{
	}

	template <typename T>
	template <typename A, typename B, typename C>
	constexpr vec<4, T>::vec(vec<2, A> const& _xy, B _z, C _w)
		: x(static_cast<T>(_xy.x)), y(static_cast<T>(_xy.y)), z(static_cast<T>(_z)), w(static_cast<T>(_w))
	{
	}

	template <typename T>
	template <typename A, typename B, typename C>
	constexpr vec<4, T>::vec(vec<2, A> const& _xy, vec<1, B> const& _z, C _w)
		: x(static_cast<T>(_xy.x)), y(static_cast<T>(_xy.y)), z(static_cast<T>(_z.x)), w(static_cast<T>(_w))
	{
	}

	template <typename T>
	template <typename A, typename B, typename C>
	constexpr vec<4, T>::vec(vec<2, A> const& _xy, B _z, vec<1, C> const& _w)
		: x(static_cast<T>(_xy.x)), y(static_cast<T>(_xy.y)), z(static_cast<T>(_z)), w(static_cast<T>(_w.x))
	{
	}

	template <typename T>
	template <typename A, typename B, typename C>
	constexpr vec<4, T>::vec(vec<2, A> const& _xy, vec<1, B> const& _z, vec<1, C> const& _w)
		: x(static_cast<T>(_xy.x)), y(static_cast<T>(_xy.y)), z(static_cast<T>(_z.x)), w(static_cast<T>(_w.x))
	{
	}

	template <typename T>
	template <typename A, typename B, typename C>
	constexpr vec<4, T>::vec(A _x, vec<2, B> const& _yz, C _w)
		: x(static_cast<T>(_x)), y(static_cast<T>(_yz.x)), z(static_cast<T>(_yz.y)), w(static_cast<T>(_w))
	{
	}

	template <typename T>
	template <typename A, typename B, typename C>
	constexpr vec<4, T>::vec(vec<1, A> const& _x, vec<2, B> const& _yz, C _w)
		: x(static_cast<T>(_x.x)), y(static_cast<T>(_yz.x)), z(static_cast<T>(_yz.y)), w(static_cast<T>(_w))
	{
	}

	template <typename T>
	template <typename A, typename B, typename C>
	constexpr vec<4, T>::vec(A _x, vec<2, B> const& _yz, vec<1, C> const& _w)
		: x(static_cast<T>(_x)), y(static_cast<T>(_yz.x)), z(static_cast<T>(_yz.y)), w(static_cast<T>(_w.x))
	{
	}

	template <typename T>
	template <typename A, typename B, typename C>
	constexpr vec<4, T>::vec(vec<1, A> const& _x, vec<2, B> const& _yz, vec<1, C> const& _w)
		: x(static_cast<T>(_x.x)), y(static_cast<T>(_yz.x)), z(static_cast<T>(_yz.y)), w(static_cast<T>(_w.x))
	{
	}

	template <typename T>
	template <typename A, typename B, typename C>
	constexpr vec<4, T>::vec(A _x, B _y, vec<2, C> const& _zw)
		: x(static_cast<T>(_x)), y(static_cast<T>(_y)), z(static_cast<T>(_zw.x)), w(static_cast<T>(_zw.y))
	{
	}

	template <typename T>
	template <typename A, typename B, typename C>
	constexpr vec<4, T>::vec(vec<1, A> const& _x, B _y, vec<2, C> const& _zw)
		: x(static_cast<T>(_x.x)), y(static_cast<T>(_y)), z(static_cast<T>(_zw.x)), w(static_cast<T>(_zw.y))
	{
	}

	template <typename T>
	template <typename A, typename B, typename C>
	constexpr vec<4, T>::vec(A _x, vec<1, B> const& _y, vec<2, C> const& _zw)
		: x(static_cast<T>(_x)), y(static_cast<T>(_y.x)), z(static_cast<T>(_zw.x)), w(static_cast<T>(_zw.y))
	{
	}

	template <typename T>
	template <typename A, typename B, typename C>
	constexpr vec<4, T>::vec(vec<1, A> const& _x, vec<1, B> const& _y, vec<2, C> const& _zw)
		: x(static_cast<T>(_x.x)), y(static_cast<T>(_y.x)), z(static_cast<T>(_zw.x)), w(static_cast<T>(_zw.y))
	{
	}

	template <typename T>
	template <typename A, typename B>
	constexpr vec<4, T>::vec(vec<3, A> const& _xyz, B _w)
		: x(static_cast<T>(_xyz.x)), y(static_cast<T>(_xyz.y)), z(static_cast<T>(_xyz.z)), w(static_cast<T>(_w))
	{
	}

	template <typename T>
	template <typename A, typename B>
	constexpr vec<4, T>::vec(vec<3, A> const& _xyz, vec<1, B> const& _w)
		: x(static_cast<T>(_xyz.x)), y(static_cast<T>(_xyz.y)), z(static_cast<T>(_xyz.z)), w(static_cast<T>(_w.x))
	{
	}

	template <typename T>
	template <typename A, typename B>
	constexpr vec<4, T>::vec(A _x, vec<3, B> const& _yzw)
		: x(static_cast<T>(_x)), y(static_cast<T>(_yzw.x)), z(static_cast<T>(_yzw.y)), w(static_cast<T>(_yzw.z))
	{
	}

	template <typename T>
	template <typename A, typename B>
	constexpr vec<4, T>::vec(vec<1, A> const& _x, vec<3, B> const& _yzw)
		: x(static_cast<T>(_x.x)), y(static_cast<T>(_yzw.x)), z(static_cast<T>(_yzw.y)), w(static_cast<T>(_yzw.z))
	{
	}

	template <typename T>
	template <typename A, typename B>
	constexpr vec<4, T>::vec(vec<2, A> const& _xy, vec<2, B> const& _zw)
		: x(static_cast<T>(_xy.x)), y(static_cast<T>(_xy.y)), z(static_cast<T>(_zw.x)), w(static_cast<T>(_zw.y))
	{
	}

	template <typename T>
	template <typename U>
	constexpr vec<4, T>::vec(vec<4, U> const& v)
		: x(static_cast<T>(v.x)), y(static_cast<T>(v.y)), z(static_cast<T>(v.z)), w(static_cast<T>(v.w))
	{
	}

	/// Assignment operators

	template <typename T>
	constexpr vec<4, T>& vec<4, T>::operator=(vec<4, T> const& v)
	{
		this->x = v.x;
		this->y = v.y;
		this->z = v.z;
		this->w = v.w;
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<4, T>& vec<4, T>::operator=(vec<4, U> const& v)
	{
		this->x = static_cast<T>(v.x);
		this->y = static_cast<T>(v.y);
		this->z = static_cast<T>(v.z);
		this->w = static_cast<T>(v.w);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<4, T>& vec<4, T>::operator+=(U scalar)
	{
		this->x += static_cast<T>(scalar);
		this->y += static_cast<T>(scalar);
		this->z += static_cast<T>(scalar);
		this->w += static_cast<T>(scalar);
		return *this;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	template <typename U>
	constexpr vec<4, T>& vec<4, T>::operator+=(vec<1, U> const& v)
	{
		this->x += static_cast<T>(v.x);
		this->y += static_cast<T>(v.x);
		this->z += static_cast<T>(v.x);
		this->w += static_cast<T>(v.x);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<4, T>& vec<4, T>::operator+=(vec<4, U> const& v)
	{
		this->x += static_cast<T>(v.x);
		this->y += static_cast<T>(v.y);
		this->z += static_cast<T>(v.z);
		this->w += static_cast<T>(v.w);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<4, T>& vec<4, T>::operator-=(U scalar)
	{
		this->x -= static_cast<T>(scalar);
		this->y -= static_cast<T>(scalar);
		this->z -= static_cast<T>(scalar);
		this->w -= static_cast<T>(scalar);
		return *this;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	template <typename U>
	constexpr vec<4, T>& vec<4, T>::operator-=(vec<1, U> const& v)
	{
		this->x -= static_cast<T>(v.x);
		this->y -= static_cast<T>(v.x);
		this->z -= static_cast<T>(v.x);
		this->w -= static_cast<T>(v.x);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<4, T>& vec<4, T>::operator-=(vec<4, U> const& v)
	{
		this->x -= static_cast<T>(v.x);
		this->y -= static_cast<T>(v.y);
		this->z -= static_cast<T>(v.z);
		this->w -= static_cast<T>(v.w);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<4, T>& vec<4, T>::operator*=(U scalar)
	{
		this->x *= static_cast<T>(scalar);
		this->y *= static_cast<T>(scalar);
		this->z *= static_cast<T>(scalar);
		this->w *= static_cast<T>(scalar);
		return *this;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	template <typename U>
	constexpr vec<4, T>& vec<4, T>::operator*=(vec<1, U> const& v)
	{
		this->x *= static_cast<T>(v.x);
		this->y *= static_cast<T>(v.x);
		this->z *= static_cast<T>(v.x);
		this->w *= static_cast<T>(v.x);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<4, T>& vec<4, T>::operator*=(vec<4, U> const& v)
	{
		this->x *= static_cast<T>(v.x);
		this->y *= static_cast<T>(v.y);
		this->z *= static_cast<T>(v.z);
		this->w *= static_cast<T>(v.w);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<4, T>& vec<4, T>::operator/=(U scalar)
	{
		this->x /= static_cast<T>(scalar);
		this->y /= static_cast<T>(scalar);
		this->z /= static_cast<T>(scalar);
		this->w /= static_cast<T>(scalar);
		return *this;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	template <typename U>
	constexpr vec<4, T>& vec<4, T>::operator/=(vec<1, U> const& v)
	{
		this->x /= static_cast<T>(v.x);
		this->y /= static_cast<T>(v.x);
		this->z /= static_cast<T>(v.x);
		this->w /= static_cast<T>(v.x);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<4, T>& vec<4, T>::operator/=(vec<4, U> const& v)
	{
		this->x /= static_cast<T>(v.x);
		this->y /= static_cast<T>(v.y);
		this->z /= static_cast<T>(v.z);
		this->w /= static_cast<T>(v.w);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<4, T>& vec<4, T>::operator%=(U scalar)
	{
		this->x %= static_cast<T>(scalar);
		this->y %= static_cast<T>(scalar);
		this->z %= static_cast<T>(scalar);
		this->w %= static_cast<T>(scalar);
		return *this;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	template <typename U>
	constexpr vec<4, T>& vec<4, T>::operator%=(vec<1, U> const& v)
	{
		this->x %= static_cast<T>(v.x);
		this->y %= static_cast<T>(v.x);
		this->z %= static_cast<T>(v.x);
		this->w %= static_cast<T>(v.x);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<4, T>& vec<4, T>::operator%=(vec<4, U> const& v)
	{
		this->x %= static_cast<T>(v.x);
		this->y %= static_cast<T>(v.y);
		this->z %= static_cast<T>(v.z);
		this->w %= static_cast<T>(v.w);
		return *this;
	}

	/// Increment and Decrement Operators

	template <typename T>
	constexpr vec<4, T>& vec<4, T>::operator++()
	{
		++this->x;
		++this->y;
		++this->z;
		++this->w;
		return *this;
	}

	template <typename T>
	constexpr vec<4, T>& vec<4, T>::operator--()
	{
		--this->x;
		--this->y;
		--this->z;
		--this->w;
		return *this;
	}

	template <typename T>
	constexpr const vec<4, T> vec<4, T>::operator++(int)
	{
		vec<4, T> result(*this);
		++*this;
		return result;
	}

	template <typename T>
	constexpr const vec<4, T> vec<4, T>::operator--(int)
	{
		vec<4, T> result(*this);
		--*this;
		return result;
	}

	/// Bitwise Assignment Operators

	template <typename T>
	template <typename U>
	constexpr vec<4, T>& vec<4, T>::operator&=(U scalar)
	{
		this->x &= static_cast<T>(scalar);
		this->y &= static_cast<T>(scalar);
		this->z &= static_cast<T>(scalar);
		this->w &= static_cast<T>(scalar);
		return *this;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	template <typename U>
	constexpr vec<4, T>& vec<4, T>::operator&=(vec<1, U> const& v)
	{
		this->x &= static_cast<T>(v.x);
		this->y &= static_cast<T>(v.x);
		this->z &= static_cast<T>(v.x);
		this->w &= static_cast<T>(v.x);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<4, T>& vec<4, T>::operator&=(vec<4, U> const& v)
	{
		this->x &= static_cast<T>(v.x);
		this->y &= static_cast<T>(v.y);
		this->z &= static_cast<T>(v.z);
		this->w &= static_cast<T>(v.w);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<4, T>& vec<4, T>::operator|=(U scalar)
	{
		this->x |= static_cast<T>(scalar);
		this->y |= static_cast<T>(scalar);
		this->z |= static_cast<T>(scalar);
		this->w |= static_cast<T>(scalar);
		return *this;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	template <typename U>
	constexpr vec<4, T>& vec<4, T>::operator|=(vec<1, U> const& v)
	{
		this->x |= static_cast<T>(v.x);
		this->y |= static_cast<T>(v.x);
		this->z |= static_cast<T>(v.x);
		this->w |= static_cast<T>(v.x);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<4, T>& vec<4, T>::operator|=(vec<4, U> const& v)
	{
		this->x |= static_cast<T>(v.x);
		this->y |= static_cast<T>(v.y);
		this->z |= static_cast<T>(v.z);
		this->w |= static_cast<T>(v.w);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<4, T>& vec<4, T>::operator^=(U scalar)
	{
		this->x ^= static_cast<T>(scalar);
		this->y ^= static_cast<T>(scalar);
		this->z ^= static_cast<T>(scalar);
		this->w ^= static_cast<T>(scalar);
		return *this;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	template <typename U>
	constexpr vec<4, T>& vec<4, T>::operator^=(vec<1, U> const& v)
	{
		this->x ^= static_cast<T>(v.x);
		this->y ^= static_cast<T>(v.x);
		this->z ^= static_cast<T>(v.x);
		this->w ^= static_cast<T>(v.x);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<4, T>& vec<4, T>::operator^=(vec<4, U> const& v)
	{
		this->x ^= static_cast<T>(v.x);
		this->y ^= static_cast<T>(v.y);
		this->z ^= static_cast<T>(v.z);
		this->w ^= static_cast<T>(v.w);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<4, T>& vec<4, T>::operator<<=(U scalar)
	{
		this->x <<= static_cast<T>(scalar);
		this->y <<= static_cast<T>(scalar);
		this->z <<= static_cast<T>(scalar);
		this->w <<= static_cast<T>(scalar);
		return *this;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	template <typename U>
	constexpr vec<4, T>& vec<4, T>::operator<<=(vec<1, U> const& v)
	{
		this->x <<= static_cast<T>(v.x);
		this->y <<= static_cast<T>(v.x);
		this->z <<= static_cast<T>(v.x);
		this->w <<= static_cast<T>(v.x);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<4, T>& vec<4, T>::operator<<=(vec<4, U> const& v)
	{
		this->x <<= static_cast<T>(v.x);
		this->y <<= static_cast<T>(v.y);
		this->z <<= static_cast<T>(v.z);
		this->w <<= static_cast<T>(v.w);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<4, T>& vec<4, T>::operator>>=(U scalar)
	{
		this->x >>= static_cast<T>(scalar);
		this->y >>= static_cast<T>(scalar);
		this->z >>= static_cast<T>(scalar);
		this->w >>= static_cast<T>(scalar);
		return *this;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	template <typename U>
	constexpr vec<4, T>& vec<4, T>::operator>>=(vec<1, U> const& v)
	{
		this->x >>= static_cast<T>(v.x);
		this->y >>= static_cast<T>(v.x);
		this->z >>= static_cast<T>(v.x);
		this->w >>= static_cast<T>(v.x);
		return *this;
	}

	template <typename T>
	template <typename U>
	constexpr vec<4, T>& vec<4, T>::operator>>=(vec<4, U> const& v)
	{
		this->x >>= static_cast<T>(v.x);
		this->y >>= static_cast<T>(v.y);
		this->z >>= static_cast<T>(v.z);
		this->w >>= static_cast<T>(v.w);
		return *this;
	}

	/// Unary Operators

	template <typename T>
	constexpr vec<4, T> operator+(vec<4, T> const& v)
	{
		return v;
	}

	template <typename T>
	constexpr vec<4, T> operator-(vec<4, T> const& v)
	{
		return vec<4, T>(0) -= v;
	}

	/// Binary Operators

	template <typename T>
	constexpr vec<4, T> operator+(vec<4, T> const& v, T const& scalar)
	{
		return vec<4, T>(v) += scalar;
	}

	template <typename T>
	constexpr vec<4, T> operator+(T scalar, vec<4, T> const& v)
	{
		return vec<4, T>(v) += scalar;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	constexpr vec<4, T> operator+(vec<4, T> const& v1, vec<1, T> const& v2)
	{
		return vec<4, T>(v1) += v2;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	constexpr vec<4, T> operator+(vec<1, T> const& v1, vec<4, T> const& v2)
	{
		return vec<4, T>(v2) += v1;
	}

	template <typename T>
	constexpr vec<4, T> operator+(vec<4, T> const& v1, vec<4, T> const& v2)
	{
		return vec<4, T>(v1) += v2;
	}

	template <typename T>
	constexpr vec<4, T> operator-(vec<4, T> const& v, T const& scalar)
	{
		return vec<4, T>(v) -= scalar;
	}

	template <typename T>
	constexpr vec<4, T> operator-(T scalar, vec<4, T> const& v)
	{
		return vec<4, T>(scalar) -= v;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	constexpr vec<4, T> operator-(vec<4, T> const& v1, vec<1, T> const& v2)
	{
		return vec<4, T>(v1) -= v2;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	constexpr vec<4, T> operator-(vec<1, T> const& v1, vec<4, T> const& v2)
	{
		return vec<4, T>(v1.x) -= v2;
	}

	template <typename T>
	constexpr vec<4, T> operator-(vec<4, T> const& v1, vec<4, T> const& v2)
	{
		return vec<4, T>(v1) -= v2;
	}

	template <typename T>
	constexpr vec<4, T> operator*(vec<4, T> const& v, T const& scalar)
	{
		return vec<4, T>(v) *= scalar;
	}

	template <typename T>
	constexpr vec<4, T> operator*(T scalar, vec<4, T> const& v)
	{
		return vec<4, T>(v) *= scalar;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	constexpr vec<4, T> operator*(vec<4, T> const& v1, vec<1, T> const& v2)
	{
		return vec<4, T>(v1) *= v2;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	constexpr vec<4, T> operator*(vec<1, T> const& v1, vec<4, T> const& v2)
	{
		return vec<4, T>(v2) *= v1;
	}

	template <typename T>
	constexpr vec<4, T> operator*(vec<4, T> const& v1, vec<4, T> const& v2)
	{
		return vec<4, T>(v1) *= v2;
	}

	template <typename T>
	constexpr vec<4, T> operator/(vec<4, T> const& v, T const& scalar)
	{
		return vec<4, T>(v) /= scalar;
	}

	template <typename T>
	constexpr vec<4, T> operator/(T scalar, vec<4, T> const& v)
	{
		return vec<4, T>(scalar) /= v;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	constexpr vec<4, T> operator/(vec<4, T> const& v1, vec<1, T> const& v2)
	{
		return vec<4, T>(v1) /= v2;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	constexpr vec<4, T> operator/(vec<1, T> const& v1, vec<4, T> const& v2)
	{
		return vec<4, T>(v1.x) /= v2;
	}

	template <typename T>
	constexpr vec<4, T> operator/(vec<4, T> const& v1, vec<4, T> const& v2)
	{
		return vec<4, T>(v1) /= v2;
	}

	template <typename T>
	constexpr vec<4, T> operator%(vec<4, T> const& v, T scalar)
	{
		return vec<4, T>(v) %= scalar;
	}

	template <typename T>
	constexpr vec<4, T> operator%(T scalar, vec<4, T> const& v)
	{
		return vec<4, T>(scalar) %= v;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	constexpr vec<4, T> operator%(vec<4, T> const& v1, vec<1, T> const& v2)
	{
		return vec<4, T>(v1) %= v2.x;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	constexpr vec<4, T> operator%(vec<1, T> const& scalar, vec<4, T> const& v)
	{
		return vec<4, T>(scalar.x) %= v;
	}

	template <typename T>
	constexpr vec<4, T> operator%(vec<4, T> const& v1, vec<4, T> const& v2)
	{
		return vec<4, T>(v1) %= v2;
	}

	/// Bitwise Binary Operators

	template <typename T>
	constexpr vec<4, T> operator&(vec<4, T> const& v, T scalar)
	{
		return vec<4, T>(v) &= scalar;
	}

	template <typename T>
	constexpr vec<4, T> operator&(T scalar, vec<4, T> const& v)
	{
		return vec<4, T>(scalar) &= v;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	constexpr vec<4, T> operator&(vec<4, T> const& v, vec<1, T> const& scalar)
	{
		return vec<4, T>(v) &= scalar;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	constexpr vec<4, T> operator&(vec<1, T> const& v1, vec<4, T> const& v2)
	{
		return vec<4, T>(v1.x) &= v2;
	}

	template <typename T>
	constexpr vec<4, T> operator&(vec<4, T> const& v1, vec<4, T> const& v2)
	{
		return vec<4, T>(v1) &= v2;
	}

	template <typename T>
	constexpr vec<4, T> operator|(vec<4, T> const& v, T scalar)
	{
		return vec<4, T>(v) |= scalar;
	}

	template <typename T>
	constexpr vec<4, T> operator|(T scalar, vec<4, T> const& v)
	{
		return vec<4, T>(scalar) |= v;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	constexpr vec<4, T> operator|(vec<4, T> const& v1, vec<1, T> const& v2)
	{
		return vec<4, T>(v1) |= v2.x;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	constexpr vec<4, T> operator|(vec<1, T> const& v1, vec<4, T> const& v2)
	{
		return vec<4, T>(v1.x) |= v2;
	}

	template <typename T>
	constexpr vec<4, T> operator|(vec<4, T> const& v1, vec<4, T> const& v2)
	{
		return vec<4, T>(v1) |= v2;
	}

	template <typename T>
	constexpr vec<4, T> operator^(vec<4, T> const& v, T scalar)
	{
		return vec<4, T>(v) ^= scalar;
	}

	template <typename T>
	constexpr vec<4, T> operator^(T scalar, vec<4, T> const& v)
	{
		return vec<4, T>(scalar) ^= v;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	constexpr vec<4, T> operator^(vec<4, T> const& v1, vec<1, T> const& v2)
	{
		return vec<4, T>(v1) ^= v2.x;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	constexpr vec<4, T> operator^(vec<1, T> const& v1, vec<4, T> const& v2)
	{
		return vec<4, T>(v1.x) ^= v2;
	}

	template <typename T>
	constexpr vec<4, T> operator^(vec<4, T> const& v1, vec<4, T> const& v2)
	{
		return vec<4, T>(v1) ^= v2;
	}

	template <typename T>
	constexpr vec<4, T> operator<<(vec<4, T> const& v, T scalar)
	{
		return vec<4, T>(v) <<= scalar;
	}

	template <typename T>
	constexpr vec<4, T> operator<<(T scalar, vec<4, T> const& v)
	{
		return vec<4, T>(scalar) <<= v;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	constexpr vec<4, T> operator<<(vec<4, T> const& v1, vec<1, T> const& v2)
	{
		return vec<4, T>(v1) <<= v2.x;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	constexpr vec<4, T> operator<<(vec<1, T> const& v1, vec<4, T> const& v2)
	{
		return vec<4, T>(v1.x) <<= v2;
	}

	template <typename T>
	constexpr vec<4, T> operator<<(vec<4, T> const& v1, vec<4, T> const& v2)
	{
		return vec<4, T>(v1) <<= v2;
	}

	template <typename T>
	constexpr vec<4, T> operator>>(vec<4, T> const& v, T scalar)
	{
		return vec<4, T>(v) >>= scalar;
	}

	template <typename T>
	constexpr vec<4, T> operator>>(T scalar, vec<4, T> const& v)
	{
		return vec<4, T>(scalar) >>= v;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	constexpr vec<4, T> operator>>(vec<4, T> const& v1, vec<1, T> const& v2)
	{
		return vec<4, T>(v1) >>= v2.x;
	}

	/*
	 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
	 */
	template <typename T>
	constexpr vec<4, T> operator>>(vec<1, T> const& v1, vec<4, T> const& v2)
	{
		return vec<4, T>(v1.x) >>= v2;
	}

	template <typename T>
	constexpr vec<4, T> operator>>(vec<4, T> const& v1, vec<4, T> const& v2)
	{
		return vec<4, T>(v1) >>= v2;
	}

	template <typename T>
	constexpr vec<4, T> operator~(vec<4, T> const& v)
	{
		return vec<4, T>(~v.x, ~v.y, ~v.z, ~v.w);
	}

	/// Conditional Operators

	template <typename T>
	constexpr bool operator==(vec<4, T> const& v1, vec<4, T> const& v2)
	{
		return v1.x == v2.x && v1.y == v2.y && v1.z == v2.z && v1.w == v2.w;
	}

	template <typename T>
	constexpr bool operator!=(vec<4, T> const& v1, vec<4, T> const& v2)
	{
		return v1.x != v2.x || v1.y != v2.y || v1.z != v2.z || v1.w != v2.w;
	}

	
	constexpr vec<4, bool> operator&&(vec<4, bool> const& v1, vec<4, bool> const& v2)
	{
		return {v1.x && v2.x, v1.y && v2.y, v1.z && v2.z, v1.w && v2.w};
	}

	
	constexpr vec<4, bool> operator||(vec<4, bool> const& v1, vec<4, bool> const& v2)
	{
		return {v1.x || v2.x, v1.y || v2.y, v1.z || v2.z, v1.w || v2.w};
	}

} // namespace mim
