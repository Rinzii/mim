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
        static MIM_CONSTEXPR auto sizeV = 3;


        union
        {
            struct { T x, y, z; };
            struct { T r, g, b; };
            struct { T s, t, p; };

            typename detail::Storage<3, T, detail::IsAligned<Q>::value>::type data;
        };

#pragma region Element Accessors

        static MIM_CONSTEXPR size_type size() { return sizeV; }

        MIM_CONSTEXPR T & operator[](size_type i);
        MIM_CONSTEXPR T const & operator[](size_type i) const;

#pragma endregion Element Accessors

#pragma region Implicit Basic Constructors

        MIM_CONSTEXPR VectorT() = default;
        MIM_CONSTEXPR VectorT(VectorT const & v) = default;

        template <qualifier P>
        MIM_CONSTEXPR VectorT(VectorT<3, T, P> const & v);

#pragma endregion Implicit Basic Constructors

#pragma region Explicit Basic Constructors

        MIM_CONSTEXPR explicit VectorT(T scalar);
        MIM_CONSTEXPR VectorT(T a, T b, T c);

#pragma endregion Explicit Basic Constructors

#pragma region Conversion Scalar Constructors

        template <typename U, qualifier P>
        MIM_CONSTEXPR explicit VectorT(VectorT<1, U, P> const & v);

        /// Explicit conversions (From section 5.4.1 Conversion and scalar constructors of GLSL 1.30.08 specification)
        template <typename X, typename Y, typename Z>
        MIM_CONSTEXPR VectorT(X _x, Y _y, Z _z);
        template <typename X, typename Y, typename Z>
        MIM_CONSTEXPR VectorT(VectorT<1, X, Q> const & _x, Y _y, Z _z);
        template <typename X, typename Y, typename Z>
        MIM_CONSTEXPR VectorT(X _x, VectorT<1, Y, Q> const & _y, Z _z);
        template <typename X, typename Y, typename Z>
        MIM_CONSTEXPR VectorT(X _x, Y _y, VectorT<1, Z, Q> const & _z);
        template <typename X, typename Y, typename Z>
        MIM_CONSTEXPR VectorT(VectorT<1, X, Q> const & _x, VectorT<1, Y, Q> const & _y, Z _z);
        template <typename X, typename Y, typename Z>
        MIM_CONSTEXPR VectorT(VectorT<1, X, Q> const & _x, Y _y, VectorT<1, Z, Q> const & _z);
        template <typename X, typename Y, typename Z>
        MIM_CONSTEXPR VectorT(X _x, VectorT<1, Y, Q> const & _y, VectorT<1, Z, Q> const & _z);
        template <typename X, typename Y, typename Z>
        MIM_CONSTEXPR VectorT(VectorT<1, X, Q> const & _x, VectorT<1, Y, Q> const & _y, VectorT<1, Z, Q> const & _z);

#pragma endregion Conversion Scalar Constructors

#pragma region Conversion Vector Constructors

        /// Explicit conversions from section 5.4.1 of GLSL 1.30.08 specification

        template <typename A, typename B, qualifier P>
        MIM_CONSTEXPR VectorT(VectorT<2, A, P> const & _xy, B _z);
        template <typename A, typename B, qualifier P>
        MIM_CONSTEXPR VectorT(A _x, VectorT<2, B, P> const & _yz);

        template <typename A, typename B, qualifier P>
        MIM_CONSTEXPR VectorT(VectorT<2, A, P> const & _xy, VectorT<1, B, P> const & _z);
        template <typename A, typename B, qualifier P>
        MIM_CONSTEXPR VectorT(VectorT<1, A, P> const & _x, VectorT<2, B, P> const & _yz);

        template <typename U, qualifier P>
        MIM_CONSTEXPR MIM_EXPLICIT VectorT(VectorT<3, U, P> const & v);

        template <typename U, qualifier P>
        MIM_CONSTEXPR MIM_EXPLICIT VectorT(VectorT<4, U, P> const & v);

#pragma endregion Conversion Vector Constructors

#pragma region Unary Arithmatic Operators

        MIM_CONSTEXPR VectorT & operator = (VectorT const & v) = default;

        template <typename U>
        MIM_CONSTEXPR VectorT & operator = (VectorT<3, U, Q> const & v);

        template <typename U>
        MIM_CONSTEXPR VectorT & operator += (U scalar);
        template <typename U>
        MIM_CONSTEXPR VectorT & operator += (VectorT<1, U, Q> const & v);
        template <typename U>
        MIM_CONSTEXPR VectorT & operator += (VectorT<3, U, Q> const & v);

        template <typename U>
        MIM_CONSTEXPR VectorT & operator -= (U scalar);
        template <typename U>
        MIM_CONSTEXPR VectorT & operator -= (VectorT<1, U, Q> const & v);
        template <typename U>
        MIM_CONSTEXPR VectorT & operator -= (VectorT<3, U, Q> const & v);

        template <typename U>
        MIM_CONSTEXPR VectorT & operator *= (U scalar);
        template <typename U>
        MIM_CONSTEXPR VectorT & operator *= (VectorT<1, U, Q> const & v);
        template <typename U>
        MIM_CONSTEXPR VectorT & operator *= (VectorT<3, U, Q> const & v);

        template <typename U>
        MIM_CONSTEXPR VectorT & operator /= (U scalar);
        template <typename U>
        MIM_CONSTEXPR VectorT & operator /= (VectorT<1, U, Q> const & v);
        template <typename U>
        MIM_CONSTEXPR VectorT & operator /= (VectorT<3, U, Q> const & v);

#pragma endregion Unary Arithmatic Operators

#pragma region Increment and Decrement Operators

        MIM_CONSTEXPR VectorT & operator ++ ();
        MIM_CONSTEXPR VectorT & operator -- ();
        MIM_CONSTEXPR VectorT operator ++ (int);
        MIM_CONSTEXPR VectorT operator -- (int);

#pragma endregion Increment and Decrement Operators

#pragma region Unary Bitwise Operators

        template <typename U>
        MIM_CONSTEXPR VectorT & operator %= (U scalar);
        template <typename U>
        MIM_CONSTEXPR VectorT & operator %= (VectorT<1, U, Q> const & v);
        template <typename U>
        MIM_CONSTEXPR VectorT & operator %= (VectorT<3, U, Q> const & v);

        template <typename U>
        MIM_CONSTEXPR VectorT & operator &= (U scalar);
        template <typename U>
        MIM_CONSTEXPR VectorT & operator &= (VectorT<1, U, Q> const & v);
        template <typename U>
        MIM_CONSTEXPR VectorT & operator &= (VectorT<3, U, Q> const & v);

        template <typename U>
        MIM_CONSTEXPR VectorT & operator |= (U scalar);
        template <typename U>
        MIM_CONSTEXPR VectorT & operator |= (VectorT<1, U, Q> const & v);
        template <typename U>
        MIM_CONSTEXPR VectorT & operator |= (VectorT<3, U, Q> const & v);

        template <typename U>
        MIM_CONSTEXPR VectorT & operator ^= (U scalar);
        template <typename U>
        MIM_CONSTEXPR VectorT & operator ^= (VectorT<1, U, Q> const & v);
        template <typename U>
        MIM_CONSTEXPR VectorT & operator ^= (VectorT<3, U, Q> const & v);

        template <typename U>
        MIM_CONSTEXPR VectorT & operator <<= (U scalar);
        template <typename U>
        MIM_CONSTEXPR VectorT & operator <<= (VectorT<1, U, Q> const & v);
        template <typename U>
        MIM_CONSTEXPR VectorT & operator <<= (VectorT<3, U, Q> const & v);

        template <typename U>
        MIM_CONSTEXPR VectorT & operator >>= (U scalar);
        template <typename U>
        MIM_CONSTEXPR VectorT & operator >>= (VectorT<1, U, Q> const & v);
        template <typename U>
        MIM_CONSTEXPR VectorT & operator >>= (VectorT<3, U, Q> const & v);

#pragma endregion Unary Bitwise Operators
    };

#pragma region Unary Operators

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<3, T, Q> operator + (VectorT<3, T, Q> const & v);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<3, T, Q> operator - (VectorT<3, T, Q> const & v);

#pragma endregion Unary Operators

#pragma region Binary Operators

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<3, T, Q> operator + (VectorT<3, T, Q> const & v, T scalar);
    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<3, T, Q> operator + (VectorT<3, T, Q> const & v1, VectorT<1, T, Q> const & v2);
    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<3, T, Q> operator + (T scalar, VectorT<3, T, Q> const & v);
    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<3, T, Q> operator + (VectorT<1, T, Q> const & v1, VectorT<3, T, Q> const & v2);
    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<3, T, Q> operator + (VectorT<3, T, Q> const & v1, VectorT<3, T, Q> const & v2);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<3, T, Q> operator - (VectorT<3, T, Q> const & v, T scalar);
    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<3, T, Q> operator - (VectorT<3, T, Q> const & v1, VectorT<1, T, Q> const & v2);
    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<3, T, Q> operator - (T scalar, VectorT<3, T, Q> const & v);
    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<3, T, Q> operator - (VectorT<1, T, Q> const & v1, VectorT<3, T, Q> const & v2);
    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<3, T, Q> operator - (VectorT<3, T, Q> const & v1, VectorT<3, T, Q> const & v2);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<3, T, Q> operator * (VectorT<3, T, Q> const & v, T scalar);
    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<3, T, Q> operator * (VectorT<3, T, Q> const & v1, VectorT<1, T, Q> const & v2);
    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<3, T, Q> operator * (T scalar, VectorT<3, T, Q> const & v);
    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<3, T, Q> operator * (VectorT<1, T, Q> const & v1, VectorT<3, T, Q> const & v2);
    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<3, T, Q> operator * (VectorT<3, T, Q> const & v1, VectorT<3, T, Q> const & v2);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<3, T, Q> operator / (VectorT<3, T, Q> const & v, T scalar);
    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<3, T, Q> operator / (VectorT<3, T, Q> const & v1, VectorT<1, T, Q> const & v2);
    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<3, T, Q> operator / (T scalar, VectorT<3, T, Q> const & v);
    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<3, T, Q> operator / (VectorT<1, T, Q> const & v1, VectorT<3, T, Q> const & v2);
    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<3, T, Q> operator / (VectorT<3, T, Q> const & v1, VectorT<3, T, Q> const & v2);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<3, T, Q> operator % (VectorT<3, T, Q> const & v, T scalar);
    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<3, T, Q> operator % (VectorT<3, T, Q> const & v1, VectorT<1, T, Q> const & v2);
    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<3, T, Q> operator % (T scalar, VectorT<3, T, Q> const & v);
    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<3, T, Q> operator % (VectorT<1, T, Q> const & v1, VectorT<3, T, Q> const & v2);
    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<3, T, Q> operator % (VectorT<3, T, Q> const & v1, VectorT<3, T, Q> const & v2);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<3, T, Q> operator & (VectorT<3, T, Q> const & v, T scalar);
    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<3, T, Q> operator & (VectorT<3, T, Q> const & v1, VectorT<1, T, Q> const & v2);
    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<3, T, Q> operator & (T scalar, VectorT<3, T, Q> const & v);
    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<3, T, Q> operator & (VectorT<1, T, Q> const & v1, VectorT<3, T, Q> const & v2);
    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<3, T, Q> operator & (VectorT<3, T, Q> const & v1, VectorT<3, T, Q> const & v2);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<3, T, Q> operator | (VectorT<3, T, Q> const & v, T scalar);
    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<3, T, Q> operator | (VectorT<3, T, Q> const & v1, VectorT<1, T, Q> const & v2);
    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<3, T, Q> operator | (T scalar, VectorT<3, T, Q> const & v);
    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<3, T, Q> operator | (VectorT<1, T, Q> const & v1, VectorT<3, T, Q> const & v2);
    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<3, T, Q> operator | (VectorT<3, T, Q> const & v1, VectorT<3, T, Q> const & v2);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<3, T, Q> operator ^ (VectorT<3, T, Q> const & v, T scalar);
    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<3, T, Q> operator ^ (VectorT<3, T, Q> const & v1, VectorT<1, T, Q> const & v2);
    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<3, T, Q> operator ^ (T scalar, VectorT<3, T, Q> const & v);
    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<3, T, Q> operator ^ (VectorT<1, T, Q> const & v1, VectorT<3, T, Q> const & v2);
    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<3, T, Q> operator ^ (VectorT<3, T, Q> const & v1, VectorT<3, T, Q> const & v2);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<3, T, Q> operator << (VectorT<3, T, Q> const & v, T scalar);
    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<3, T, Q> operator << (VectorT<3, T, Q> const & v1, VectorT<1, T, Q> const & v2);
    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<3, T, Q> operator << (T scalar, VectorT<3, T, Q> const & v);
    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<3, T, Q> operator << (VectorT<1, T, Q> const & v1, VectorT<3, T, Q> const & v2);
    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<3, T, Q> operator << (VectorT<3, T, Q> const & v1, VectorT<3, T, Q> const & v2);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<3, T, Q> operator >> (VectorT<3, T, Q> const & v, T scalar);
    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<3, T, Q> operator >> (VectorT<3, T, Q> const & v1, VectorT<1, T, Q> const & v2);
    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<3, T, Q> operator >> (T scalar, VectorT<3, T, Q> const & v);
    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<3, T, Q> operator >> (VectorT<1, T, Q> const & v1, VectorT<3, T, Q> const & v2);
    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<3, T, Q> operator >> (VectorT<3, T, Q> const & v1, VectorT<3, T, Q> const & v2);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<3, T, Q> operator ~ (VectorT<3, T, Q> const & v);

#pragma endregion Binary Operators

#pragma region Boolean Operators

    template <typename T, qualifier Q>
    MIM_CONSTEXPR bool operator == (VectorT<3, T, Q> const & v1, VectorT<3, T, Q> const & v2);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR bool operator != (VectorT<3, T, Q> const & v1, VectorT<3, T, Q> const & v2);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR bool operator && (VectorT<3, T, Q> const & v1, VectorT<3, T, Q> const & v2);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR bool operator || (VectorT<3, T, Q> const & v1, VectorT<3, T, Q> const & v2);

#pragma endregion Boolean Operators
} // namespace mim

#include "mim/detail/type/type_vector3.inl"
#include "mim/detail/func/func_vector3.inl"
