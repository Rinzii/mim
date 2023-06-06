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
        static constexpr auto sizeV = 1;


        union
        {
            T x;
            T r;
            T s;

            typename detail::Storage<1, T, detail::IsAligned<Q>::value>::type data;
        };


        // Element Accessors

        static constexpr std::size_t size() { return sizeV; }

        constexpr T& operator [] (std::size_t i);
        constexpr const T& operator [] (std::size_t i) const;

        // Implicit Basic Constructors

        constexpr VectorT() = default;
        constexpr VectorT(VectorT const& v) = default;
        template<qualifier P> constexpr explicit VectorT(VectorT<1, T, P> const& v);


        // Explicit Basic Constructors

        constexpr explicit VectorT(T scalar);


#pragma region Conversion Constructors

        /// Explicit conversions from section 5.4.1 of GLSL 1.30.08 specification

        template<typename U, qualifier P>
        constexpr explicit VectorT(VectorT<1, U, P> const& v);
        template<typename U, qualifier P>
        constexpr explicit VectorT(VectorT<2, U, P> const& v);
        template<typename U, qualifier P>
        constexpr explicit VectorT(VectorT<3, U, P> const& v);
        template<typename U, qualifier P>
        constexpr explicit VectorT(VectorT<4, U, P> const& v);

#pragma endregion Conversion Constructors

#pragma region Unary Operators

        constexpr VectorT<1, T, Q>& operator = (VectorT const& v) = default;

        template<typename U>
        constexpr VectorT<1, T, Q>& operator = (VectorT<1, U, Q> const& v);

        template<typename U>
        constexpr VectorT<1, T, Q>& operator += (U scalar);
        template<typename U>
        constexpr VectorT<1, T, Q>& operator += (VectorT<1, U, Q> const& v);

        template<typename U>
        constexpr VectorT<1, T, Q>& operator -= (U scalar);
        template<typename U>
        constexpr VectorT<1, T, Q>& operator -= (VectorT<1, U, Q> const& v);

        template<typename U>
        constexpr VectorT<1, T, Q>& operator *= (U scalar);
        template<typename U>
        constexpr VectorT<1, T, Q>& operator *= (VectorT<1, U, Q> const& v);

        template<typename U>
        constexpr VectorT<1, T, Q>& operator /= (U scalar);
        template<typename U>
        constexpr VectorT<1, T, Q>& operator /= (VectorT<1, U, Q> const& v);


#pragma endregion Unary Operators

#pragma region Postfix and Prefix

        constexpr VectorT<1, T, Q>& operator ++ ();
        constexpr VectorT<1, T, Q>& operator -- ();
        constexpr const VectorT<1, T, Q> operator ++ (int);
        constexpr const VectorT<1, T, Q> operator -- (int);

#pragma endregion Postfix and Prefix

#pragma region Unary Bit Operators

        template<typename U>
        constexpr VectorT<1, T, Q>& operator%=(U scalar);
        template<typename U>
        constexpr VectorT<1, T, Q>& operator%=(VectorT<1, U, Q> const& v);

        template<typename U>
        constexpr VectorT<1, T, Q>& operator&=(U scalar);
        template<typename U>
        constexpr VectorT<1, T, Q>& operator&=(VectorT<1, U, Q> const& v);

        template<typename U>
        constexpr VectorT<1, T, Q>& operator|=(U scalar);
        template<typename U>
        constexpr VectorT<1, T, Q>& operator|=(VectorT<1, U, Q> const& v);

        template<typename U>
        constexpr VectorT<1, T, Q>& operator^=(U scalar);
        template<typename U>
        constexpr VectorT<1, T, Q>& operator^=(VectorT<1, U, Q> const& v);

        template <typename U>
        constexpr VectorT<1, T, Q>& operator<<=(U scalar);
        template <typename U>
        constexpr VectorT<1, T, Q>& operator<<=(VectorT<1, U, Q> const& v);

        template <typename U>
        constexpr VectorT<1, T, Q>& operator>>=(U scalar);
        template <typename U>
        constexpr VectorT<1, T, Q>& operator>>=(VectorT<1, U, Q> const& v);

#pragma endregion Unary Bit Operators
    };

#pragma region Unary Operators

    template <typename T, qualifier Q>
    constexpr VectorT<1, T, Q> operator + (VectorT<1, T, Q> const& v);

    template <typename T, qualifier Q>
    constexpr VectorT<1, T, Q> operator - (VectorT<1, T, Q> const& v);

#pragma endregion Unary Operators

#pragma region Binary Operators

    template <typename T, qualifier Q>
    constexpr VectorT<1, T, Q> operator + (VectorT<1, T, Q> const& v, T scalar);

    template <typename T, qualifier Q>
    constexpr VectorT<1, T, Q> operator + (T scalar, VectorT<1, T, Q> const& v);

    template <typename T, qualifier Q>
    constexpr VectorT<1, T, Q> operator + (VectorT<1, T, Q> const& v1, VectorT<1, T, Q> const& v2);

    template <typename T, qualifier Q>
    constexpr VectorT<1, T, Q> operator - (VectorT<1, T, Q> const& v, T scalar);

    template <typename T, qualifier Q>
    constexpr VectorT<1, T, Q> operator - (T scalar, VectorT<1, T, Q> const& v);

    template <typename T, qualifier Q>
    constexpr VectorT<1, T, Q> operator - (VectorT<1, T, Q> const& v1, VectorT<1, T, Q> const& v2);

    template <typename T, qualifier Q>
    constexpr VectorT<1, T, Q> operator * (VectorT<1, T, Q> const& v, T scalar);

    template <typename T, qualifier Q>
    constexpr VectorT<1, T, Q> operator * (T scalar, VectorT<1, T, Q> const& v);

    template <typename T, qualifier Q>
    constexpr VectorT<1, T, Q> operator * (VectorT<1, T, Q> const& v1, VectorT<1, T, Q> const& v2);

    template <typename T, qualifier Q>
    constexpr VectorT<1, T, Q> operator / (VectorT<1, T, Q> const& v, T scalar);

    template <typename T, qualifier Q>
    constexpr VectorT<1, T, Q> operator / (T scalar, VectorT<1, T, Q> const& v);

    template <typename T, qualifier Q>
    constexpr VectorT<1, T, Q> operator / (VectorT<1, T, Q> const& v1, VectorT<1, T, Q> const& v2);

    template <typename T, qualifier Q>
    constexpr VectorT<1, T, Q> operator % (VectorT<1, T, Q> const& v, T scalar);

    template <typename T, qualifier Q>
    constexpr VectorT<1, T, Q> operator % (T scalar, VectorT<1, T, Q> const& v);

    template <typename T, qualifier Q>
    constexpr VectorT<1, T, Q> operator % (VectorT<1, T, Q> const& v1, VectorT<1, T, Q> const& v2);

    template <typename T, qualifier Q>
    constexpr VectorT<1, T, Q> operator & (VectorT<1, T, Q> const& v, T scalar);

    template <typename T, qualifier Q>
    constexpr VectorT<1, T, Q> operator & (T scalar, VectorT<1, T, Q> const& v);

    template <typename T, qualifier Q>
    constexpr VectorT<1, T, Q> operator & (VectorT<1, T, Q> const& v1, VectorT<1, T, Q> const& v2);

    template <typename T, qualifier Q>
    constexpr VectorT<1, T, Q> operator | (VectorT<1, T, Q> const& v, T scalar);

    template <typename T, qualifier Q>
    constexpr VectorT<1, T, Q> operator | (T scalar, VectorT<1, T, Q> const& v);

    template <typename T, qualifier Q>
    constexpr VectorT<1, T, Q> operator | (VectorT<1, T, Q> const& v1, VectorT<1, T, Q> const& v2);

    template <typename T, qualifier Q>
    constexpr VectorT<1, T, Q> operator ^ (VectorT<1, T, Q> const& v, T scalar);

    template <typename T, qualifier Q>
    constexpr VectorT<1, T, Q> operator ^ (T scalar, VectorT<1, T, Q> const& v);

    template <typename T, qualifier Q>
    constexpr VectorT<1, T, Q> operator ^ (VectorT<1, T, Q> const& v1, VectorT<1, T, Q> const& v2);

    template <typename T, qualifier Q>
    constexpr VectorT<1, T, Q> operator << (VectorT<1, T, Q> const& v, T scalar);

    template <typename T, qualifier Q>
    constexpr VectorT<1, T, Q> operator << (T scalar, VectorT<1, T, Q> const& v);

    template <typename T, qualifier Q>
    constexpr VectorT<1, T, Q> operator << (VectorT<1, T, Q> const& v1, VectorT<1, T, Q> const& v2);

    template <typename T, qualifier Q>
    constexpr VectorT<1, T, Q> operator >> (VectorT<1, T, Q> const& v, T scalar);

    template <typename T, qualifier Q>
    constexpr VectorT<1, T, Q> operator >> (T scalar, VectorT<1, T, Q> const& v);

    template <typename T, qualifier Q>
    constexpr VectorT<1, T, Q> operator >> (VectorT<1, T, Q> const& v1, VectorT<1, T, Q> const& v2);

    template <typename T, qualifier Q>
    constexpr VectorT<1, bool, Q> operator ~ (VectorT<1, T, Q> const& v);

#pragma endregion Binary Operators

#pragma region Boolean Operators

    template <typename T, qualifier Q>
    constexpr bool operator == (VectorT<1, T, Q> const& v1, VectorT<1, T, Q> const& v2);

    template <typename T, qualifier Q>
    constexpr bool operator != (VectorT<1, T, Q> const& v1, VectorT<1, T, Q> const& v2);

    template <qualifier Q>
    constexpr bool operator && (VectorT<1, bool, Q> const& v1, VectorT<1, bool, Q> const& v2);

    template <qualifier Q>
    constexpr bool operator || (VectorT<1, bool, Q> const& v1, VectorT<1, bool, Q> const& v2);

#pragma endregion Boolean Operators
} // namespace mim

#include "mim/detail/type/type_vector1.inl"
#include "mim/detail/func/func_vector1.inl"
