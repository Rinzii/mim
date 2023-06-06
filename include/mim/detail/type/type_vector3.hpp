// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#pragma once

#include "mim/detail/qualifier.hpp"

namespace mim {

    template<typename T, qualifier Q>
    struct VectorT<3, T, Q>
    {
        using value_type = T;
        using type = VectorT<3, T, Q>;
        using bool_type = VectorT<3, bool, Q>;
        using size_type = size_t;
        static constexpr auto sizeV = 3;


        union
        {
            struct { T x, y, z; };
            struct { T r, g, b; };
            struct { T s, t, p; };

            typename detail::Storage<3, T, detail::IsAligned<Q>::value>::type data;
        };

#pragma region Element Accessors

        static constexpr size_type size() { return sizeV; }

        constexpr T & operator[](size_type i);
        constexpr T const & operator[](size_type i) const;

#pragma endregion Element Accessors

#pragma region Implicit Basic Constructors

        constexpr VectorT() = default;
        constexpr VectorT(VectorT const & v) = default;

        template <qualifier P>
        constexpr VectorT(VectorT<3, T, P> const & v);

#pragma endregion Implicit Basic Constructors

#pragma region Explicit Basic Constructors

        constexpr explicit VectorT(T scalar);
        constexpr VectorT(T a, T b, T c);

#pragma endregion Explicit Basic Constructors

#pragma region Conversion Scalar Constructors

        template <typename U, qualifier P>
        constexpr explicit VectorT(VectorT<1, U, P> const & v);

        /// Explicit conversions (From section 5.4.1 Conversion and scalar constructors of GLSL 1.30.08 specification)
        template <typename X, typename Y, typename Z>
        constexpr VectorT(X _x, Y _y, Z _z);
        template <typename X, typename Y, typename Z>
        constexpr VectorT(VectorT<1, X, Q> const & _x, Y _y, Z _z);
        template <typename X, typename Y, typename Z>
        constexpr VectorT(X _x, VectorT<1, Y, Q> const & _y, Z _z);
        template <typename X, typename Y, typename Z>
        constexpr VectorT(X _x, Y _y, VectorT<1, Z, Q> const & _z);
        template <typename X, typename Y, typename Z>
        constexpr VectorT(VectorT<1, X, Q> const & _x, VectorT<1, Y, Q> const & _y, Z _z);
        template <typename X, typename Y, typename Z>
        constexpr VectorT(VectorT<1, X, Q> const & _x, Y _y, VectorT<1, Z, Q> const & _z);
        template <typename X, typename Y, typename Z>
        constexpr VectorT(X _x, VectorT<1, Y, Q> const & _y, VectorT<1, Z, Q> const & _z);
        template <typename X, typename Y, typename Z>
        constexpr VectorT(VectorT<1, X, Q> const & _x, VectorT<1, Y, Q> const & _y, VectorT<1, Z, Q> const & _z);

#pragma endregion Conversion Scalar Constructors

#pragma region Conversion Vector Constructors

        /// Explicit conversions from section 5.4.1 of GLSL 1.30.08 specification

        template <typename A, typename B, qualifier P>
        constexpr VectorT(VectorT<2, A, P> const & _xy, B _z);
        template <typename A, typename B, qualifier P>
        constexpr VectorT(A _x, VectorT<2, B, P> const & _yz);

        template <typename A, typename B, qualifier P>
        constexpr VectorT(VectorT<2, A, P> const & _xy, VectorT<1, B, P> const & _z);
        template <typename A, typename B, qualifier P>
        constexpr VectorT(VectorT<1, A, P> const & _x, VectorT<2, B, P> const & _yz);

        template <typename U, qualifier P>
        constexpr explicit VectorT(VectorT<3, U, P> const & v);

        template <typename U, qualifier P>
        constexpr explicit VectorT(VectorT<4, U, P> const & v);

#pragma endregion Conversion Vector Constructors

#pragma region Unary Arithmatic Operators

        constexpr VectorT & operator = (VectorT const & v) = default;

        template <typename U>
        constexpr VectorT & operator = (VectorT<3, U, Q> const & v);

        template <typename U>
        constexpr VectorT & operator += (U scalar);
        template <typename U>
        constexpr VectorT & operator += (VectorT<1, U, Q> const & v);
        template <typename U>
        constexpr VectorT & operator += (VectorT<3, U, Q> const & v);

        template <typename U>
        constexpr VectorT & operator -= (U scalar);
        template <typename U>
        constexpr VectorT & operator -= (VectorT<1, U, Q> const & v);
        template <typename U>
        constexpr VectorT & operator -= (VectorT<3, U, Q> const & v);

        template <typename U>
        constexpr VectorT & operator *= (U scalar);
        template <typename U>
        constexpr VectorT & operator *= (VectorT<1, U, Q> const & v);
        template <typename U>
        constexpr VectorT & operator *= (VectorT<3, U, Q> const & v);

        template <typename U>
        constexpr VectorT & operator /= (U scalar);
        template <typename U>
        constexpr VectorT & operator /= (VectorT<1, U, Q> const & v);
        template <typename U>
        constexpr VectorT & operator /= (VectorT<3, U, Q> const & v);

#pragma endregion Unary Arithmatic Operators

#pragma region Increment and Decrement Operators

        constexpr VectorT & operator ++ ();
        constexpr VectorT & operator -- ();
        constexpr VectorT operator ++ (int);
        constexpr VectorT operator -- (int);

#pragma endregion Increment and Decrement Operators

#pragma region Unary Bitwise Operators

        template <typename U>
        constexpr VectorT & operator %= (U scalar);
        template <typename U>
        constexpr VectorT & operator %= (VectorT<1, U, Q> const & v);
        template <typename U>
        constexpr VectorT & operator %= (VectorT<3, U, Q> const & v);

        template <typename U>
        constexpr VectorT & operator &= (U scalar);
        template <typename U>
        constexpr VectorT & operator &= (VectorT<1, U, Q> const & v);
        template <typename U>
        constexpr VectorT & operator &= (VectorT<3, U, Q> const & v);

        template <typename U>
        constexpr VectorT & operator |= (U scalar);
        template <typename U>
        constexpr VectorT & operator |= (VectorT<1, U, Q> const & v);
        template <typename U>
        constexpr VectorT & operator |= (VectorT<3, U, Q> const & v);

        template <typename U>
        constexpr VectorT & operator ^= (U scalar);
        template <typename U>
        constexpr VectorT & operator ^= (VectorT<1, U, Q> const & v);
        template <typename U>
        constexpr VectorT & operator ^= (VectorT<3, U, Q> const & v);

        template <typename U>
        constexpr VectorT & operator <<= (U scalar);
        template <typename U>
        constexpr VectorT & operator <<= (VectorT<1, U, Q> const & v);
        template <typename U>
        constexpr VectorT & operator <<= (VectorT<3, U, Q> const & v);

        template <typename U>
        constexpr VectorT & operator >>= (U scalar);
        template <typename U>
        constexpr VectorT & operator >>= (VectorT<1, U, Q> const & v);
        template <typename U>
        constexpr VectorT & operator >>= (VectorT<3, U, Q> const & v);

#pragma endregion Unary Bitwise Operators
    };

#pragma region Unary Operators

    template <typename T, qualifier Q>
    constexpr VectorT<3, T, Q> operator + (VectorT<3, T, Q> const & v);

    template <typename T, qualifier Q>
    constexpr VectorT<3, T, Q> operator - (VectorT<3, T, Q> const & v);

#pragma endregion Unary Operators

#pragma region Binary Operators

    template <typename T, qualifier Q>
    constexpr VectorT<3, T, Q> operator + (VectorT<3, T, Q> const & v, T scalar);
    template <typename T, qualifier Q>
    constexpr VectorT<3, T, Q> operator + (VectorT<3, T, Q> const & v1, VectorT<1, T, Q> const & v2);
    template <typename T, qualifier Q>
    constexpr VectorT<3, T, Q> operator + (T scalar, VectorT<3, T, Q> const & v);
    template <typename T, qualifier Q>
    constexpr VectorT<3, T, Q> operator + (VectorT<1, T, Q> const & v1, VectorT<3, T, Q> const & v2);
    template <typename T, qualifier Q>
    constexpr VectorT<3, T, Q> operator + (VectorT<3, T, Q> const & v1, VectorT<3, T, Q> const & v2);

    template <typename T, qualifier Q>
    constexpr VectorT<3, T, Q> operator - (VectorT<3, T, Q> const & v, T scalar);
    template <typename T, qualifier Q>
    constexpr VectorT<3, T, Q> operator - (VectorT<3, T, Q> const & v1, VectorT<1, T, Q> const & v2);
    template <typename T, qualifier Q>
    constexpr VectorT<3, T, Q> operator - (T scalar, VectorT<3, T, Q> const & v);
    template <typename T, qualifier Q>
    constexpr VectorT<3, T, Q> operator - (VectorT<1, T, Q> const & v1, VectorT<3, T, Q> const & v2);
    template <typename T, qualifier Q>
    constexpr VectorT<3, T, Q> operator - (VectorT<3, T, Q> const & v1, VectorT<3, T, Q> const & v2);

    template <typename T, qualifier Q>
    constexpr VectorT<3, T, Q> operator * (VectorT<3, T, Q> const & v, T scalar);
    template <typename T, qualifier Q>
    constexpr VectorT<3, T, Q> operator * (VectorT<3, T, Q> const & v1, VectorT<1, T, Q> const & v2);
    template <typename T, qualifier Q>
    constexpr VectorT<3, T, Q> operator * (T scalar, VectorT<3, T, Q> const & v);
    template <typename T, qualifier Q>
    constexpr VectorT<3, T, Q> operator * (VectorT<1, T, Q> const & v1, VectorT<3, T, Q> const & v2);
    template <typename T, qualifier Q>
    constexpr VectorT<3, T, Q> operator * (VectorT<3, T, Q> const & v1, VectorT<3, T, Q> const & v2);

    template <typename T, qualifier Q>
    constexpr VectorT<3, T, Q> operator / (VectorT<3, T, Q> const & v, T scalar);
    template <typename T, qualifier Q>
    constexpr VectorT<3, T, Q> operator / (VectorT<3, T, Q> const & v1, VectorT<1, T, Q> const & v2);
    template <typename T, qualifier Q>
    constexpr VectorT<3, T, Q> operator / (T scalar, VectorT<3, T, Q> const & v);
    template <typename T, qualifier Q>
    constexpr VectorT<3, T, Q> operator / (VectorT<1, T, Q> const & v1, VectorT<3, T, Q> const & v2);
    template <typename T, qualifier Q>
    constexpr VectorT<3, T, Q> operator / (VectorT<3, T, Q> const & v1, VectorT<3, T, Q> const & v2);

    template <typename T, qualifier Q>
    constexpr VectorT<3, T, Q> operator % (VectorT<3, T, Q> const & v, T scalar);
    template <typename T, qualifier Q>
    constexpr VectorT<3, T, Q> operator % (VectorT<3, T, Q> const & v1, VectorT<1, T, Q> const & v2);
    template <typename T, qualifier Q>
    constexpr VectorT<3, T, Q> operator % (T scalar, VectorT<3, T, Q> const & v);
    template <typename T, qualifier Q>
    constexpr VectorT<3, T, Q> operator % (VectorT<1, T, Q> const & v1, VectorT<3, T, Q> const & v2);
    template <typename T, qualifier Q>
    constexpr VectorT<3, T, Q> operator % (VectorT<3, T, Q> const & v1, VectorT<3, T, Q> const & v2);

    template <typename T, qualifier Q>
    constexpr VectorT<3, T, Q> operator & (VectorT<3, T, Q> const & v, T scalar);
    template <typename T, qualifier Q>
    constexpr VectorT<3, T, Q> operator & (VectorT<3, T, Q> const & v1, VectorT<1, T, Q> const & v2);
    template <typename T, qualifier Q>
    constexpr VectorT<3, T, Q> operator & (T scalar, VectorT<3, T, Q> const & v);
    template <typename T, qualifier Q>
    constexpr VectorT<3, T, Q> operator & (VectorT<1, T, Q> const & v1, VectorT<3, T, Q> const & v2);
    template <typename T, qualifier Q>
    constexpr VectorT<3, T, Q> operator & (VectorT<3, T, Q> const & v1, VectorT<3, T, Q> const & v2);

    template <typename T, qualifier Q>
    constexpr VectorT<3, T, Q> operator | (VectorT<3, T, Q> const & v, T scalar);
    template <typename T, qualifier Q>
    constexpr VectorT<3, T, Q> operator | (VectorT<3, T, Q> const & v1, VectorT<1, T, Q> const & v2);
    template <typename T, qualifier Q>
    constexpr VectorT<3, T, Q> operator | (T scalar, VectorT<3, T, Q> const & v);
    template <typename T, qualifier Q>
    constexpr VectorT<3, T, Q> operator | (VectorT<1, T, Q> const & v1, VectorT<3, T, Q> const & v2);
    template <typename T, qualifier Q>
    constexpr VectorT<3, T, Q> operator | (VectorT<3, T, Q> const & v1, VectorT<3, T, Q> const & v2);

    template <typename T, qualifier Q>
    constexpr VectorT<3, T, Q> operator ^ (VectorT<3, T, Q> const & v, T scalar);
    template <typename T, qualifier Q>
    constexpr VectorT<3, T, Q> operator ^ (VectorT<3, T, Q> const & v1, VectorT<1, T, Q> const & v2);
    template <typename T, qualifier Q>
    constexpr VectorT<3, T, Q> operator ^ (T scalar, VectorT<3, T, Q> const & v);
    template <typename T, qualifier Q>
    constexpr VectorT<3, T, Q> operator ^ (VectorT<1, T, Q> const & v1, VectorT<3, T, Q> const & v2);
    template <typename T, qualifier Q>
    constexpr VectorT<3, T, Q> operator ^ (VectorT<3, T, Q> const & v1, VectorT<3, T, Q> const & v2);

    template <typename T, qualifier Q>
    constexpr VectorT<3, T, Q> operator << (VectorT<3, T, Q> const & v, T scalar);
    template <typename T, qualifier Q>
    constexpr VectorT<3, T, Q> operator << (VectorT<3, T, Q> const & v1, VectorT<1, T, Q> const & v2);
    template <typename T, qualifier Q>
    constexpr VectorT<3, T, Q> operator << (T scalar, VectorT<3, T, Q> const & v);
    template <typename T, qualifier Q>
    constexpr VectorT<3, T, Q> operator << (VectorT<1, T, Q> const & v1, VectorT<3, T, Q> const & v2);
    template <typename T, qualifier Q>
    constexpr VectorT<3, T, Q> operator << (VectorT<3, T, Q> const & v1, VectorT<3, T, Q> const & v2);

    template <typename T, qualifier Q>
    constexpr VectorT<3, T, Q> operator >> (VectorT<3, T, Q> const & v, T scalar);
    template <typename T, qualifier Q>
    constexpr VectorT<3, T, Q> operator >> (VectorT<3, T, Q> const & v1, VectorT<1, T, Q> const & v2);
    template <typename T, qualifier Q>
    constexpr VectorT<3, T, Q> operator >> (T scalar, VectorT<3, T, Q> const & v);
    template <typename T, qualifier Q>
    constexpr VectorT<3, T, Q> operator >> (VectorT<1, T, Q> const & v1, VectorT<3, T, Q> const & v2);
    template <typename T, qualifier Q>
    constexpr VectorT<3, T, Q> operator >> (VectorT<3, T, Q> const & v1, VectorT<3, T, Q> const & v2);

    template <typename T, qualifier Q>
    constexpr VectorT<3, T, Q> operator ~ (VectorT<3, T, Q> const & v);

#pragma endregion Binary Operators

#pragma region Boolean Operators

    template <typename T, qualifier Q>
    constexpr bool operator == (VectorT<3, T, Q> const & v1, VectorT<3, T, Q> const & v2);

    template <typename T, qualifier Q>
    constexpr bool operator != (VectorT<3, T, Q> const & v1, VectorT<3, T, Q> const & v2);

    template <typename T, qualifier Q>
    constexpr bool operator && (VectorT<3, T, Q> const & v1, VectorT<3, T, Q> const & v2);

    template <typename T, qualifier Q>
    constexpr bool operator || (VectorT<3, T, Q> const & v1, VectorT<3, T, Q> const & v2);

#pragma endregion Boolean Operators
} // namespace mim

#include "mim/detail/type/type_vector3.inl"
#include "mim/detail/func/func_vector3.inl"
