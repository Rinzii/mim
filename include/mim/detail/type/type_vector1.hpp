// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#pragma once

#include "mim/detail/qualifier.hpp"

namespace mim {

    template<typename T, qualifier Q>
    struct VectorT<1, T, Q>
    {
        using value_type = T;
        using type = VectorT<1, T, Q>;
        using bool_type = VectorT<1, bool, Q>;
        using size_type = size_t;
        static MIM_CONSTEXPR auto sizeV = 1;


        union
        {
            T x;
            T r;
            T s;

            typename detail::Storage<1, T, detail::IsAligned<Q>::value>::type data;
        };


        // Element Accessors

        static MIM_CONSTEXPR std::size_t size() { return sizeV; }

        MIM_CONSTEXPR T& operator [] (std::size_t i);
        MIM_CONSTEXPR const T& operator [] (std::size_t i) const;

        // Implicit Basic Constructors

        MIM_CONSTEXPR VectorT() = default;
        MIM_CONSTEXPR VectorT(VectorT const& v) = default;
        template<qualifier P> MIM_CONSTEXPR VectorT(VectorT<1, T, P> const& v);


        // Explicit Basic Constructors

        MIM_CONSTEXPR explicit VectorT(T scalar);


#pragma region Conversion Constructors

        /// Explicit conversions from section 5.4.1 of GLSL 1.30.08 specification

        template<typename U, qualifier P>
        MIM_CONSTEXPR MIM_EXPLICIT VectorT(VectorT<1, U, P> const& v);
        template<typename U, qualifier P>
        MIM_CONSTEXPR MIM_EXPLICIT VectorT(VectorT<2, U, P> const& v);
        template<typename U, qualifier P>
        MIM_CONSTEXPR MIM_EXPLICIT VectorT(VectorT<3, U, P> const& v);
        template<typename U, qualifier P>
        MIM_CONSTEXPR MIM_EXPLICIT VectorT(VectorT<4, U, P> const& v);

#pragma endregion Conversion Constructors

#pragma region Unary Operators

        MIM_CONSTEXPR VectorT<1, T, Q>& operator = (VectorT const& v) = default;

        template<typename U>
        MIM_CONSTEXPR VectorT<1, T, Q>& operator = (VectorT<1, U, Q> const& v);

        template<typename U>
        MIM_CONSTEXPR VectorT<1, T, Q>& operator += (U scalar);
        template<typename U>
        MIM_CONSTEXPR VectorT<1, T, Q>& operator += (VectorT<1, U, Q> const& v);

        template<typename U>
        MIM_CONSTEXPR VectorT<1, T, Q>& operator -= (U scalar);
        template<typename U>
        MIM_CONSTEXPR VectorT<1, T, Q>& operator -= (VectorT<1, U, Q> const& v);

        template<typename U>
        MIM_CONSTEXPR VectorT<1, T, Q>& operator *= (U scalar);
        template<typename U>
        MIM_CONSTEXPR VectorT<1, T, Q>& operator *= (VectorT<1, U, Q> const& v);

        template<typename U>
        MIM_CONSTEXPR VectorT<1, T, Q>& operator /= (U scalar);
        template<typename U>
        MIM_CONSTEXPR VectorT<1, T, Q>& operator /= (VectorT<1, U, Q> const& v);


#pragma endregion Unary Operators

#pragma region Postfix and Prefix

        MIM_CONSTEXPR VectorT<1, T, Q>& operator ++ ();
        MIM_CONSTEXPR VectorT<1, T, Q>& operator -- ();
        MIM_CONSTEXPR VectorT<1, T, Q> operator ++ (int);
        MIM_CONSTEXPR VectorT<1, T, Q> operator -- (int);

#pragma endregion Postfix and Prefix

#pragma region Unary Bit Operators

        template<typename U>
        MIM_CONSTEXPR VectorT<1, T, Q>& operator%=(U scalar);
        template<typename U>
        MIM_CONSTEXPR VectorT<1, T, Q>& operator%=(VectorT<1, U, Q> const& v);

        template<typename U>
        MIM_CONSTEXPR VectorT<1, T, Q>& operator&=(U scalar);
        template<typename U>
        MIM_CONSTEXPR VectorT<1, T, Q>& operator&=(VectorT<1, U, Q> const& v);

        template<typename U>
        MIM_CONSTEXPR VectorT<1, T, Q>& operator|=(U scalar);
        template<typename U>
        MIM_CONSTEXPR VectorT<1, T, Q>& operator|=(VectorT<1, U, Q> const& v);

        template<typename U>
        MIM_CONSTEXPR VectorT<1, T, Q>& operator^=(U scalar);
        template<typename U>
        MIM_CONSTEXPR VectorT<1, T, Q>& operator^=(VectorT<1, U, Q> const& v);

        template <typename U>
        MIM_CONSTEXPR VectorT<1, T, Q>& operator<<=(U scalar);
        template <typename U>
        MIM_CONSTEXPR VectorT<1, T, Q>& operator<<=(VectorT<1, U, Q> const& v);

        template <typename U>
        MIM_CONSTEXPR VectorT<1, T, Q>& operator>>=(U scalar);
        template <typename U>
        MIM_CONSTEXPR VectorT<1, T, Q>& operator>>=(VectorT<1, U, Q> const& v);

#pragma endregion Unary Bit Operators
    };

#pragma region Unary Operators

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator + (VectorT<1, T, Q> const& v);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator - (VectorT<1, T, Q> const& v);

#pragma endregion Unary Operators

#pragma region Binary Operators

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator + (VectorT<1, T, Q> const& v, T scalar);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator + (T scalar, VectorT<1, T, Q> const& v);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator + (VectorT<1, T, Q> const& v1, VectorT<1, T, Q> const& v2);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator - (VectorT<1, T, Q> const& v, T scalar);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator - (T scalar, VectorT<1, T, Q> const& v);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator - (VectorT<1, T, Q> const& v1, VectorT<1, T, Q> const& v2);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator * (VectorT<1, T, Q> const& v, T scalar);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator * (T scalar, VectorT<1, T, Q> const& v);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator * (VectorT<1, T, Q> const& v1, VectorT<1, T, Q> const& v2);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator / (VectorT<1, T, Q> const& v, T scalar);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator / (T scalar, VectorT<1, T, Q> const& v);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator / (VectorT<1, T, Q> const& v1, VectorT<1, T, Q> const& v2);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator % (VectorT<1, T, Q> const& v, T scalar);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator % (T scalar, VectorT<1, T, Q> const& v);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator % (VectorT<1, T, Q> const& v1, VectorT<1, T, Q> const& v2);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator & (VectorT<1, T, Q> const& v, T scalar);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator & (T scalar, VectorT<1, T, Q> const& v);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator & (VectorT<1, T, Q> const& v1, VectorT<1, T, Q> const& v2);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator | (VectorT<1, T, Q> const& v, T scalar);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator | (T scalar, VectorT<1, T, Q> const& v);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator | (VectorT<1, T, Q> const& v1, VectorT<1, T, Q> const& v2);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator ^ (VectorT<1, T, Q> const& v, T scalar);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator ^ (T scalar, VectorT<1, T, Q> const& v);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator ^ (VectorT<1, T, Q> const& v1, VectorT<1, T, Q> const& v2);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator << (VectorT<1, T, Q> const& v, T scalar);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator << (T scalar, VectorT<1, T, Q> const& v);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator << (VectorT<1, T, Q> const& v1, VectorT<1, T, Q> const& v2);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator >> (VectorT<1, T, Q> const& v, T scalar);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator >> (T scalar, VectorT<1, T, Q> const& v);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator >> (VectorT<1, T, Q> const& v1, VectorT<1, T, Q> const& v2);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, bool, Q> operator ~ (VectorT<1, T, Q> const& v);

#pragma endregion Binary Operators

#pragma region Boolean Operators

    template <typename T, qualifier Q>
    MIM_CONSTEXPR bool operator == (VectorT<1, T, Q> const& v1, VectorT<1, T, Q> const& v2);

    template <typename T, qualifier Q>
    MIM_CONSTEXPR bool operator != (VectorT<1, T, Q> const& v1, VectorT<1, T, Q> const& v2);

    template <qualifier Q>
    MIM_CONSTEXPR bool operator && (VectorT<1, bool, Q> const& v1, VectorT<1, bool, Q> const& v2);

    template <qualifier Q>
    MIM_CONSTEXPR bool operator || (VectorT<1, bool, Q> const& v1, VectorT<1, bool, Q> const& v2);

#pragma endregion Boolean Operators
} // namespace mim

#include "mim/detail/type/type_vector1.inl"
#include "mim/detail/func/func_vector1.inl"
