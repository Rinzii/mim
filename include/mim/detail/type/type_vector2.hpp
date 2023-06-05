// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#pragma once

#include "mim/detail/qualifier.hpp"

namespace mim {

    template<typename T, qualifier Q>
    struct VectorT<2, T, Q>
    {
        using value_type = T;
        using type = VectorT<2, T, Q>;
        using bool_type = VectorT<2, bool, Q>;
        using size_type = size_t;
        static MIM_CONSTEXPR auto sizeV = 2;


        union
        {
            struct { T x, y; };
            struct { T r, g; };
            struct { T s, t; };

            typename detail::Storage<2, T, detail::IsAligned<Q>::value>::type data;
        };


        static MIM_CONSTEXPR std::size_t size() { return sizeV; }

        MIM_CONSTEXPR T& operator [] (std::size_t i);
        MIM_CONSTEXPR T const& operator [] (std::size_t i) const;

        MIM_CONSTEXPR VectorT() = default;
        MIM_CONSTEXPR VectorT(VectorT const& v) = default;

        template<qualifier P>
        MIM_CONSTEXPR VectorT(VectorT<2, T, P> const& v);

        MIM_CONSTEXPR explicit VectorT(T scalar);
        MIM_CONSTEXPR VectorT(T x, T y);

        template<typename U, qualifier P>
        MIM_CONSTEXPR explicit VectorT(VectorT<1, U, P> const& v);


        /// Explicit conversions from section 5.4.1 of GLSL 1.30.08 specification

        template<typename A, typename B>
        MIM_CONSTEXPR explicit VectorT(A x, B y);
        template<typename A, typename B>
        MIM_CONSTEXPR VectorT(VectorT<1, A, Q> const& v1, B y);
        template<typename A, typename B>
        MIM_CONSTEXPR VectorT(A x, VectorT<1, B, Q> const& y);
        template<typename A, typename B>
        MIM_CONSTEXPR VectorT(VectorT<1, A, Q> const& x, VectorT<1, B, Q> const& y);


        /// Explicit conversions from section 5.4.1 of GLSL 1.30.08 specification

        template<typename U, qualifier P>
        MIM_CONSTEXPR MIM_EXPLICIT VectorT(VectorT<2, U, P> const& v);
        template<typename U, qualifier P>
        MIM_CONSTEXPR MIM_EXPLICIT VectorT(VectorT<3, U, P> const& v);
        template<typename U, qualifier P>
        MIM_CONSTEXPR MIM_EXPLICIT VectorT(VectorT<4, U, P> const& v);

#pragma region Unary Operators

        MIM_CONSTEXPR VectorT<2, T, Q>& operator=(VectorT const& v) = default;

        template<typename U>
        MIM_CONSTEXPR VectorT<2, T, Q>& operator=(VectorT<2, U, Q> const& v);

        template<typename U>
        MIM_CONSTEXPR VectorT<2, T, Q>& operator+=(U scalar);
        template<typename U>
        MIM_CONSTEXPR VectorT<2, T, Q>& operator+=(VectorT<1, U, Q> const& v);
        template<typename U>
        MIM_CONSTEXPR VectorT<2, T, Q>& operator+=(VectorT<2, U, Q> const& v);

        template<typename U>
        MIM_CONSTEXPR VectorT<2, T, Q>& operator-=(U scalar);
        template<typename U>
        MIM_CONSTEXPR VectorT<2, T, Q>& operator-=(VectorT<1, U, Q> const& v);
        template<typename U>
        MIM_CONSTEXPR VectorT<2, T, Q>& operator-=(VectorT<2, U, Q> const& v);

        template<typename U>
        MIM_CONSTEXPR VectorT<2, T, Q>& operator*=(U scalar);
        template<typename U>
        MIM_CONSTEXPR VectorT<2, T, Q>& operator*=(VectorT<1, U, Q> const& v);
        template<typename U>
        MIM_CONSTEXPR VectorT<2, T, Q>& operator*=(VectorT<2, U, Q> const& v);

        template<typename U>
        MIM_CONSTEXPR VectorT<2, T, Q>& operator/=(U scalar);
        template<typename U>
        MIM_CONSTEXPR VectorT<2, T, Q>& operator/=(VectorT<1, U, Q> const& v);
        template<typename U>
        MIM_CONSTEXPR VectorT<2, T, Q>& operator/=(VectorT<2, U, Q> const& v);

#pragma endregion Unary Operators

#pragma region Postfix and Prefix

        MIM_CONSTEXPR VectorT<2, T, Q> & operator++();
        MIM_CONSTEXPR VectorT<2, T, Q> & operator--();
        MIM_CONSTEXPR VectorT<2, T, Q> operator++(int);
        MIM_CONSTEXPR VectorT<2, T, Q> operator--(int);

#pragma endregion Postfix and Prefix

#pragma region Unary Bit Operators

        template<typename U>
        MIM_CONSTEXPR VectorT<2, T, Q>& operator%=(U scalar);
        template<typename U>
        MIM_CONSTEXPR VectorT<2, T, Q>& operator%=(VectorT<1, U, Q> const& v);
        template<typename U>
        MIM_CONSTEXPR VectorT<2, T, Q>& operator%=(VectorT<2, U, Q> const& v);

        template<typename U>
        MIM_CONSTEXPR VectorT<2, T, Q>& operator&=(U scalar);
        template<typename U>
        MIM_CONSTEXPR VectorT<2, T, Q>& operator&=(VectorT<1, U, Q> const& v);
        template<typename U>
        MIM_CONSTEXPR VectorT<2, T, Q>& operator&=(VectorT<2, U, Q> const& v);

        template<typename U>
        MIM_CONSTEXPR VectorT<2, T, Q>& operator|=(U scalar);
        template<typename U>
        MIM_CONSTEXPR VectorT<2, T, Q>& operator|=(VectorT<1, U, Q> const& v);
        template<typename U>
        MIM_CONSTEXPR VectorT<2, T, Q>& operator|=(VectorT<2, U, Q> const& v);

        template<typename U>
        MIM_CONSTEXPR VectorT<2, T, Q>& operator^=(U scalar);
        template<typename U>
        MIM_CONSTEXPR VectorT<2, T, Q>& operator^=(VectorT<1, U, Q> const& v);
        template<typename U>
        MIM_CONSTEXPR VectorT<2, T, Q>& operator^=(VectorT<2, U, Q> const& v);

        template<typename U>
        MIM_CONSTEXPR VectorT<2, T, Q>& operator<<=(U scalar);
        template<typename U>
        MIM_CONSTEXPR VectorT<2, T, Q>& operator<<=(VectorT<1, U, Q> const& v);
        template<typename U>
        MIM_CONSTEXPR VectorT<2, T, Q>& operator<<=(VectorT<2, U, Q> const& v);

        template <typename U>
        MIM_CONSTEXPR VectorT<2, T, Q>& operator>>=(U scalar);
        template <typename U>
        MIM_CONSTEXPR VectorT<2, T, Q>& operator>>=(VectorT<1, U, Q> const& v);
        template <typename U>
        MIM_CONSTEXPR VectorT<2, T, Q>& operator >>= (VectorT<2, U, Q> const& v);

#pragma endregion Unary Bit Operators
    };

#pragma region Unary Operators

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<2, T, Q> operator + (VectorT<2, T, Q> const& v);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<2, T, Q> operator - (VectorT<2, T, Q> const& v);

#pragma endregion Unary Operators

#pragma region Binary Operators

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<2, T, Q> operator + (VectorT<2, T, Q> const& v, T scalar);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<2, T, Q> operator + (T scalar, VectorT<2, T, Q> const& v);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<2, T, Q> operator + (VectorT<2, T, Q> const& v1, VectorT<2, T, Q> const& v2);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<2, T, Q> operator + (VectorT<1, T, Q> const& v, VectorT<2, T, Q> const& v2);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<2, T, Q> operator + (VectorT<2, T, Q> const& v1, VectorT<1, T, Q> const& v);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<2, T, Q> operator - (VectorT<2, T, Q> const& v, T scalar);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<2, T, Q> operator - (T scalar, VectorT<2, T, Q> const& v);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<2, T, Q> operator - (VectorT<2, T, Q> const& v1, VectorT<2, T, Q> const& v2);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<2, T, Q> operator - (VectorT<1, T, Q> const& v, VectorT<2, T, Q> const& v2);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<2, T, Q> operator - (VectorT<2, T, Q> const& v1, VectorT<1, T, Q> const& v);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<2, T, Q> operator * (VectorT<2, T, Q> const& v, T scalar);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<2, T, Q> operator * (T scalar, VectorT<2, T, Q> const& v);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<2, T, Q> operator * (VectorT<2, T, Q> const& v1, VectorT<2, T, Q> const& v2);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<2, T, Q> operator * (VectorT<1, T, Q> const& v, VectorT<2, T, Q> const& v2);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<2, T, Q> operator * (VectorT<2, T, Q> const& v1, VectorT<1, T, Q> const& v);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<2, T, Q> operator / (VectorT<2, T, Q> const& v, T scalar);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<2, T, Q> operator / (T scalar, VectorT<2, T, Q> const& v);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<2, T, Q> operator / (VectorT<2, T, Q> const& v1, VectorT<2, T, Q> const& v2);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<2, T, Q> operator / (VectorT<1, T, Q> const& v, VectorT<2, T, Q> const& v2);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<2, T, Q> operator / (VectorT<2, T, Q> const& v1, VectorT<1, T, Q> const& v);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<2, T, Q> operator % (VectorT<2, T, Q> const& v, T scalar);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<2, T, Q> operator % (T scalar, VectorT<2, T, Q> const& v);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<2, T, Q> operator % (VectorT<2, T, Q> const& v1, VectorT<2, T, Q> const& v2);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<2, T, Q> operator % (VectorT<1, T, Q> const& v, VectorT<2, T, Q> const& v2);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<2, T, Q> operator % (VectorT<2, T, Q> const& v1, VectorT<1, T, Q> const& v);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<2, T, Q> operator & (VectorT<2, T, Q> const& v, T scalar);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<2, T, Q> operator & (T scalar, VectorT<2, T, Q> const& v);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<2, T, Q> operator & (VectorT<2, T, Q> const& v1, VectorT<2, T, Q> const& v2);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<2, T, Q> operator & (VectorT<1, T, Q> const& v, VectorT<2, T, Q> const& v2);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<2, T, Q> operator & (VectorT<2, T, Q> const& v1, VectorT<1, T, Q> const& v);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<2, T, Q> operator | (VectorT<2, T, Q> const& v, T scalar);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<2, T, Q> operator | (T scalar, VectorT<2, T, Q> const& v);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<2, T, Q> operator | (VectorT<2, T, Q> const& v1, VectorT<2, T, Q> const& v2);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<2, T, Q> operator | (VectorT<1, T, Q> const& v, VectorT<2, T, Q> const& v2);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<2, T, Q> operator | (VectorT<2, T, Q> const& v1, VectorT<1, T, Q> const& v);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<2, T, Q> operator ^ (VectorT<2, T, Q> const& v1, T scalar);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<2, T, Q> operator ^ (T scalar, VectorT<2, T, Q> const& v);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<2, T, Q> operator ^ (VectorT<2, T, Q> const& v1, VectorT<2, T, Q> const& v2);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<2, T, Q> operator ^ (VectorT<1, T, Q> const& v, VectorT<2, T, Q> const& v2);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<2, T, Q> operator ^ (VectorT<2, T, Q> const& v1, VectorT<1, T, Q> const& v);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<2, T, Q> operator << (VectorT<2, T, Q> const& v, T scalar);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<2, T, Q> operator << (T scalar, VectorT<2, T, Q> const& v);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<2, T, Q> operator << (VectorT<2, T, Q> const& v1, VectorT<2, T, Q> const& v2);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<2, T, Q> operator << (VectorT<1, T, Q> const& v, VectorT<2, T, Q> const& v2);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<2, T, Q> operator << (VectorT<2, T, Q> const& v1, VectorT<1, T, Q> const& v);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<2, T, Q> operator >> (VectorT<2, T, Q> const& v, T scalar);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<2, T, Q> operator >> (T scalar, VectorT<2, T, Q> const& v);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<2, T, Q> operator >> (VectorT<2, T, Q> const& v1, VectorT<2, T, Q> const& v2);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<2, T, Q> operator >> (VectorT<1, T, Q> const& v, VectorT<2, T, Q> const& v2);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<2, T, Q> operator >> (VectorT<2, T, Q> const& v1, VectorT<1, T, Q> const& v);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<2, bool, Q> operator ~ (VectorT<2, T, Q> const& v);


#pragma region Boolean Operators

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<2, bool, Q> operator == (VectorT<2, T, Q> const& v1, VectorT<2, T, Q> const& v2);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<2, bool, Q> operator != (VectorT<2, T, Q> const& v1, VectorT<2, T, Q> const& v2);

    template <qualifier Q>
    MIM_CONSTEXPR VectorT<2, bool, Q> operator && (VectorT<2, bool, Q> const& v1, VectorT<2, bool, Q> const& v2);

    template <qualifier Q>
    MIM_CONSTEXPR VectorT<2, bool, Q> operator || (VectorT<2, bool, Q> const& v1, VectorT<2, bool, Q> const& v2);
} // namespace riot

#include "math/detail/type_vector2.inl"
#include "math/detail/func_vector.inl"
