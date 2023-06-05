// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#pragma once

#include "mim/detail/qualifier.hpp"

namespace mim
{
    template<typename T, qualifier Q>
    struct VectorT<4, T, Q>
    {
        using value_type = T;
        using type = VectorT<4, T, Q>;
        using bool_type = VectorT<4, bool, Q>;
        using size_type = size_t;
        static MIM_CONSTEXPR auto sizeV = 4;

        union
        {
			// This is syntactic sugar and is being done purposely
            struct { T x, y, z, w; };

            typename detail::Storage<4, T, detail::IsAligned<Q>::value>::type data;
        };

        static MIM_CONSTEXPR size_type size() noexcept { return sizeV; }

        MIM_CONSTEXPR T & operator[](size_type i);
        MIM_CONSTEXPR T const& operator[](size_type i) const;

        // -- Implicit basic constructors --

        MIM_CONSTEXPR VectorT() = default;
        MIM_CONSTEXPR VectorT(VectorT<4, T, Q> const& v) = default;
        template<qualifier P>
        MIM_CONSTEXPR VectorT(VectorT<4, T, P> const& v);

        // -- Explicit basic constructors --

        MIM_CONSTEXPR explicit VectorT(T scalar);
        MIM_CONSTEXPR VectorT(T x, T y, T z, T w);

        // -- Conversion scalar constructors --

        template<typename U, qualifier P>
        MIM_CONSTEXPR explicit VectorT(VectorT<1, U, P> const& v);

        /// Explicit conversions (From section 5.4.1 Conversion and scalar constructors of GLSL 1.30.08 specification)
        template<typename X, typename Y, typename Z, typename W>
        MIM_CONSTEXPR VectorT(X _x, Y _y, Z _z, W _w);
        template<typename X, typename Y, typename Z, typename W>
        MIM_CONSTEXPR VectorT(VectorT<1, X, Q> const& _x, Y _y, Z _z, W _w);
        template<typename X, typename Y, typename Z, typename W>
        MIM_CONSTEXPR VectorT(X _x, VectorT<1, Y, Q> const& _y, Z _z, W _w);
        template<typename X, typename Y, typename Z, typename W>
        MIM_CONSTEXPR VectorT(VectorT<1, X, Q> const& _x, VectorT<1, Y, Q> const& _y, Z _z, W _w);
        template<typename X, typename Y, typename Z, typename W>
        MIM_CONSTEXPR VectorT(X _x, Y _y, VectorT<1, Z, Q> const& _z, W _w);
        template<typename X, typename Y, typename Z, typename W>
        MIM_CONSTEXPR VectorT(VectorT<1, X, Q> const& _x, Y _y, VectorT<1, Z, Q> const& _z, W _w);
        template<typename X, typename Y, typename Z, typename W>
        MIM_CONSTEXPR VectorT(X _x, VectorT<1, Y, Q> const& _y, VectorT<1, Z, Q> const& _z, W _w);
        template<typename X, typename Y, typename Z, typename W>
        MIM_CONSTEXPR VectorT(VectorT<1, X, Q> const& _x, VectorT<1, Y, Q> const& _y, VectorT<1, Z, Q> const& _z, W _w);
        template<typename X, typename Y, typename Z, typename W>
        MIM_CONSTEXPR VectorT(VectorT<1, X, Q> const& _x, Y _y, Z _z, VectorT<1, W, Q> const& _w);
        template<typename X, typename Y, typename Z, typename W>
        MIM_CONSTEXPR VectorT(X _x, VectorT<1, Y, Q> const& _y, Z _z, VectorT<1, W, Q> const& _w);
        template<typename X, typename Y, typename Z, typename W>
        MIM_CONSTEXPR VectorT(VectorT<1, X, Q> const& _x, VectorT<1, Y, Q> const& _y, Z _z, VectorT<1, W, Q> const& _w);
        template<typename X, typename Y, typename Z, typename W>
        MIM_CONSTEXPR VectorT(X _x, Y _y, VectorT<1, Z, Q> const& _z, VectorT<1, W, Q> const& _w);
        template<typename X, typename Y, typename Z, typename W>
        MIM_CONSTEXPR VectorT(VectorT<1, X, Q> const& _x, Y _y, VectorT<1, Z, Q> const& _z, VectorT<1, W, Q> const& _w);
        template<typename X, typename Y, typename Z, typename W>
        MIM_CONSTEXPR VectorT(X _x, VectorT<1, Y, Q> const& _y, VectorT<1, Z, Q> const& _z, VectorT<1, W, Q> const& _w);
        template<typename X, typename Y, typename Z, typename W>
        MIM_CONSTEXPR VectorT(VectorT<1, X, Q> const& _x, VectorT<1, Y, Q> const& _y, VectorT<1, Z, Q> const& _z, VectorT<1, W, Q> const& _w);

        // -- Conversion vector constructors --

        /// Explicit conversions (From section 5.4.1 Conversion and scalar constructors of GLSL 1.30.08 specification)
        template<typename A, typename B, typename C, qualifier P>
        MIM_CONSTEXPR VectorT(VectorT<2, A, P> const& _xy, B _z, C _w);
        template<typename A, typename B, typename C, qualifier P>
        MIM_CONSTEXPR VectorT(VectorT<2, A, P> const& _xy, VectorT<1, B, P> const& _z, C _w);
        template<typename A, typename B, typename C, qualifier P>
        MIM_CONSTEXPR VectorT(VectorT<2, A, P> const& _xy, B _z, VectorT<1, C, P> const& _w);
        template<typename A, typename B, typename C, qualifier P>
        MIM_CONSTEXPR VectorT(VectorT<2, A, P> const& _xy, VectorT<1, B, P> const& _z, VectorT<1, C, P> const& _w);
        template<typename A, typename B, typename C, qualifier P>
        MIM_CONSTEXPR VectorT(A _x, VectorT<2, B, P> const& _yz, C _w);
        template<typename A, typename B, typename C, qualifier P>
        MIM_CONSTEXPR VectorT(VectorT<1, A, P> const& _x, VectorT<2, B, P> const& _yz, C _w);
        template<typename A, typename B, typename C, qualifier P>
        MIM_CONSTEXPR VectorT(A _x, VectorT<2, B, P> const& _yz, VectorT<1, C, P> const& _w);
        template<typename A, typename B, typename C, qualifier P>
        MIM_CONSTEXPR VectorT(VectorT<1, A, P> const& _x, VectorT<2, B, P> const& _yz, VectorT<1, C, P> const& _w);
        template<typename A, typename B, typename C, qualifier P>
        MIM_CONSTEXPR VectorT(A _x, B _y, VectorT<2, C, P> const& _zw);
        template<typename A, typename B, typename C, qualifier P>
        MIM_CONSTEXPR VectorT(VectorT<1, A, P> const& _x, B _y, VectorT<2, C, P> const& _zw);
        template<typename A, typename B, typename C, qualifier P>
        MIM_CONSTEXPR VectorT(A _x, VectorT<1, B, P> const& _y, VectorT<2, C, P> const& _zw);
        template<typename A, typename B, typename C, qualifier P>
        MIM_CONSTEXPR VectorT(VectorT<1, A, P> const& _x, VectorT<1, B, P> const& _y, VectorT<2, C, P> const& _zw);
        template<typename A, typename B, qualifier P>
        MIM_CONSTEXPR VectorT(VectorT<3, A, P> const& _xyz, B _w);
        template<typename A, typename B, qualifier P>
        MIM_CONSTEXPR VectorT(VectorT<3, A, P> const& _xyz, VectorT<1, B, P> const& _w);
        template<typename A, typename B, qualifier P>
        MIM_CONSTEXPR VectorT(A _x, VectorT<3, B, P> const& _yzw);
        template<typename A, typename B, qualifier P>
        MIM_CONSTEXPR VectorT(VectorT<1, A, P> const& _x, VectorT<3, B, P> const& _yzw);
        template<typename A, typename B, qualifier P>
        MIM_CONSTEXPR VectorT(VectorT<2, A, P> const& _xy, VectorT<2, B, P> const& _zw);

        template<typename U, qualifier P>
        MIM_CONSTEXPR MIM_EXPLICIT VectorT(VectorT<4, U, P> const& v);
        

        // -- Unary arithmetic operators --

        MIM_CONSTEXPR VectorT<4, T, Q>& operator=(VectorT<4, T, Q> const& v) = default;

        template<typename U>
        MIM_CONSTEXPR VectorT<4, T, Q>& operator=(VectorT<4, U, Q> const& v);
        template<typename U>
        MIM_CONSTEXPR VectorT<4, T, Q>& operator+=(U scalar);
        template<typename U>
        MIM_CONSTEXPR VectorT<4, T, Q>& operator+=(VectorT<1, U, Q> const& v);
        template<typename U>
        MIM_CONSTEXPR VectorT<4, T, Q>& operator+=(VectorT<4, U, Q> const& v);
        template<typename U>
        MIM_CONSTEXPR VectorT<4, T, Q>& operator-=(U scalar);
        template<typename U>
        MIM_CONSTEXPR VectorT<4, T, Q>& operator-=(VectorT<1, U, Q> const& v);
        template<typename U>
        MIM_CONSTEXPR VectorT<4, T, Q>& operator-=(VectorT<4, U, Q> const& v);
        template<typename U>
        MIM_CONSTEXPR VectorT<4, T, Q>& operator*=(U scalar);
        template<typename U>
        MIM_CONSTEXPR VectorT<4, T, Q>& operator*=(VectorT<1, U, Q> const& v);
        template<typename U>
        MIM_CONSTEXPR VectorT<4, T, Q>& operator*=(VectorT<4, U, Q> const& v);
        template<typename U>
        MIM_CONSTEXPR VectorT<4, T, Q>& operator/=(U scalar);
        template<typename U>
        MIM_CONSTEXPR VectorT<4, T, Q>& operator/=(VectorT<1, U, Q> const& v);
        template<typename U>
        MIM_CONSTEXPR VectorT<4, T, Q>& operator/=(VectorT<4, U, Q> const& v);

        // -- Increment and decrement operators --

        MIM_CONSTEXPR VectorT<4, T, Q> & operator++();
        MIM_CONSTEXPR VectorT<4, T, Q> & operator--();
        MIM_CONSTEXPR VectorT<4, T, Q> operator++(int);
        MIM_CONSTEXPR VectorT<4, T, Q> operator--(int);

        // -- Unary bit operators --

        template<typename U>
        MIM_CONSTEXPR VectorT<4, T, Q> & operator%=(U scalar);
        template<typename U>
        MIM_CONSTEXPR VectorT<4, T, Q> & operator%=(VectorT<1, U, Q> const& v);
        template<typename U>
        MIM_CONSTEXPR VectorT<4, T, Q> & operator%=(VectorT<4, U, Q> const& v);
        template<typename U>
        MIM_CONSTEXPR VectorT<4, T, Q> & operator&=(U scalar);
        template<typename U>
        MIM_CONSTEXPR VectorT<4, T, Q> & operator&=(VectorT<1, U, Q> const& v);
        template<typename U>
        MIM_CONSTEXPR VectorT<4, T, Q> & operator&=(VectorT<4, U, Q> const& v);
        template<typename U>
        MIM_CONSTEXPR VectorT<4, T, Q> & operator|=(U scalar);
        template<typename U>
        MIM_CONSTEXPR VectorT<4, T, Q> & operator|=(VectorT<1, U, Q> const& v);
        template<typename U>
        MIM_CONSTEXPR VectorT<4, T, Q> & operator|=(VectorT<4, U, Q> const& v);
        template<typename U>
        MIM_CONSTEXPR VectorT<4, T, Q> & operator^=(U scalar);
        template<typename U>
        MIM_CONSTEXPR VectorT<4, T, Q> & operator^=(VectorT<1, U, Q> const& v);
        template<typename U>
        MIM_CONSTEXPR VectorT<4, T, Q> & operator^=(VectorT<4, U, Q> const& v);
        template<typename U>
        MIM_CONSTEXPR VectorT<4, T, Q> & operator<<=(U scalar);
        template<typename U>
        MIM_CONSTEXPR VectorT<4, T, Q> & operator<<=(VectorT<1, U, Q> const& v);
        template<typename U>
        MIM_CONSTEXPR VectorT<4, T, Q> & operator<<=(VectorT<4, U, Q> const& v);
        template<typename U>
        MIM_CONSTEXPR VectorT<4, T, Q> & operator>>=(U scalar);
        template<typename U>
        MIM_CONSTEXPR VectorT<4, T, Q> & operator>>=(VectorT<1, U, Q> const& v);
        template<typename U>
        MIM_CONSTEXPR VectorT<4, T, Q> & operator>>=(VectorT<4, U, Q> const& v);
    };

    // -- Unary operators --

    template<typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<4, T, Q> operator+(VectorT<4, T, Q> const& v);

    template<typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<4, T, Q> operator-(VectorT<4, T, Q> const& v);

    // -- Binary operators --

    template<typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<4, T, Q> operator+(VectorT<4, T, Q> const& v, T const & scalar);

    template<typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<4, T, Q> operator+(VectorT<4, T, Q> const& v1, VectorT<1, T, Q> const& v2);

    template<typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<4, T, Q> operator+(T scalar, VectorT<4, T, Q> const& v);

    template<typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<4, T, Q> operator+(VectorT<1, T, Q> const& v1, VectorT<4, T, Q> const& v2);

    template<typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<4, T, Q> operator+(VectorT<4, T, Q> const& v1, VectorT<4, T, Q> const& v2);

    template<typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<4, T, Q> operator-(VectorT<4, T, Q> const& v, T const & scalar);

    template<typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<4, T, Q> operator-(VectorT<4, T, Q> const& v1, VectorT<1, T, Q> const& v2);

    template<typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<4, T, Q> operator-(T scalar, VectorT<4, T, Q> const& v);

    template<typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<4, T, Q> operator-(VectorT<1, T, Q> const& v1, VectorT<4, T, Q> const& v2);

    template<typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<4, T, Q> operator-(VectorT<4, T, Q> const& v1, VectorT<4, T, Q> const& v2);

    template<typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<4, T, Q> operator*(VectorT<4, T, Q> const& v, T const & scalar);

    template<typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<4, T, Q> operator*(VectorT<4, T, Q> const& v1, VectorT<1, T, Q> const& v2);

    template<typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<4, T, Q> operator*(T scalar, VectorT<4, T, Q> const& v);

    template<typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<4, T, Q> operator*(VectorT<1, T, Q> const& v1, VectorT<4, T, Q> const& v2);

    template<typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<4, T, Q> operator*(VectorT<4, T, Q> const& v1, VectorT<4, T, Q> const& v2);

    template<typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<4, T, Q> operator/(VectorT<4, T, Q> const& v, T const & scalar);

    template<typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<4, T, Q> operator/(VectorT<4, T, Q> const& v1, VectorT<1, T, Q> const& v2);

    template<typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<4, T, Q> operator/(T scalar, VectorT<4, T, Q> const& v);

    template<typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<4, T, Q> operator/(VectorT<1, T, Q> const& v1, VectorT<4, T, Q> const& v2);

    template<typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<4, T, Q> operator/(VectorT<4, T, Q> const& v1, VectorT<4, T, Q> const& v2);

    template<typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<4, T, Q> operator%(VectorT<4, T, Q> const& v, T scalar);

    template<typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<4, T, Q> operator%(VectorT<4, T, Q> const& v, VectorT<1, T, Q> const& scalar);

    template<typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<4, T, Q> operator%(T scalar, VectorT<4, T, Q> const& v);

    template<typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<4, T, Q> operator%(VectorT<1, T, Q> const& scalar, VectorT<4, T, Q> const& v);

    template<typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<4, T, Q> operator%(VectorT<4, T, Q> const& v1, VectorT<4, T, Q> const& v2);

    template<typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<4, T, Q> operator&(VectorT<4, T, Q> const& v, T scalar);

    template<typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<4, T, Q> operator&(VectorT<4, T, Q> const& v, VectorT<1, T, Q> const& scalar);

    template<typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<4, T, Q> operator&(T scalar, VectorT<4, T, Q> const& v);

    template<typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<4, T, Q> operator&(VectorT<1, T, Q> const& scalar, VectorT<4, T, Q> const& v);

    template<typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<4, T, Q> operator&(VectorT<4, T, Q> const& v1, VectorT<4, T, Q> const& v2);

    template<typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<4, T, Q> operator|(VectorT<4, T, Q> const& v, T scalar);

    template<typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<4, T, Q> operator|(VectorT<4, T, Q> const& v, VectorT<1, T, Q> const& scalar);

    template<typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<4, T, Q> operator|(T scalar, VectorT<4, T, Q> const& v);

    template<typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<4, T, Q> operator|(VectorT<1, T, Q> const& scalar, VectorT<4, T, Q> const& v);

    template<typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<4, T, Q> operator|(VectorT<4, T, Q> const& v1, VectorT<4, T, Q> const& v2);

    template<typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<4, T, Q> operator^(VectorT<4, T, Q> const& v, T scalar);

    template<typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<4, T, Q> operator^(VectorT<4, T, Q> const& v, VectorT<1, T, Q> const& scalar);

    template<typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<4, T, Q> operator^(T scalar, VectorT<4, T, Q> const& v);

    template<typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<4, T, Q> operator^(VectorT<1, T, Q> const& scalar, VectorT<4, T, Q> const& v);

    template<typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<4, T, Q> operator^(VectorT<4, T, Q> const& v1, VectorT<4, T, Q> const& v2);

    template<typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<4, T, Q> operator<<(VectorT<4, T, Q> const& v, T scalar);

    template<typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<4, T, Q> operator<<(VectorT<4, T, Q> const& v, VectorT<1, T, Q> const& scalar);

    template<typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<4, T, Q> operator<<(T scalar, VectorT<4, T, Q> const& v);

    template<typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<4, T, Q> operator<<(VectorT<1, T, Q> const& scalar, VectorT<4, T, Q> const& v);

    template<typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<4, T, Q> operator<<(VectorT<4, T, Q> const& v1, VectorT<4, T, Q> const& v2);

    template<typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<4, T, Q> operator>>(VectorT<4, T, Q> const& v, T scalar);

    template<typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<4, T, Q> operator>>(VectorT<4, T, Q> const& v, VectorT<1, T, Q> const& scalar);

    template<typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<4, T, Q> operator>>(T scalar, VectorT<4, T, Q> const& v);

    template<typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<4, T, Q> operator>>(VectorT<1, T, Q> const& scalar, VectorT<4, T, Q> const& v);

    template<typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<4, T, Q> operator>>(VectorT<4, T, Q> const& v1, VectorT<4, T, Q> const& v2);

    template<typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<4, T, Q> operator~(VectorT<4, T, Q> const& v);

    // -- Boolean operators --

    template<typename T, qualifier Q>
    MIM_CONSTEXPR bool operator==(VectorT<4, T, Q> const& v1, VectorT<4, T, Q> const& v2);

    template<typename T, qualifier Q>
    MIM_CONSTEXPR bool operator!=(VectorT<4, T, Q> const& v1, VectorT<4, T, Q> const& v2);

    template<qualifier Q>
    MIM_CONSTEXPR VectorT<4, bool, Q> operator&&(VectorT<4, bool, Q> const& v1, VectorT<4, bool, Q> const& v2);

    template<qualifier Q>
    MIM_CONSTEXPR VectorT<4, bool, Q> operator||(VectorT<4, bool, Q> const& v1, VectorT<4, bool, Q> const& v2);
} // namespace riot

#include "math/detail/type_vector4.inl"
#include "math/detail/func_vector.inl"
