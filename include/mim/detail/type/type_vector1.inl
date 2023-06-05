// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#include "mim/detail/compute/compute_vector.hpp"

namespace mim
{
    /// Implicit basic constructors

    template <typename T, qualifier Q>
    template <qualifier P>
    MIM_CONSTEXPR VectorT<1, T, Q>::VectorT(VectorT<1, T, P> const& v) : x(v.x) {}


    /// Explicit basic constructors

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q>::VectorT(T scalar) : x(scalar) {}


    /// Conversion constructors

    template <typename T, qualifier Q>
    template <typename U, qualifier P>
    MIM_CONSTEXPR VectorT<1, T, Q>::VectorT(VectorT<1, U, P> const& v) : x(static_cast<T>(v.x)) {}


    template <typename T, qualifier Q>
    template <typename U, qualifier P>
    MIM_CONSTEXPR VectorT<1, T, Q>::VectorT(VectorT<2, U, P> const& v) : x(static_cast<T>(v.x)) {}


    template <typename T, qualifier Q>
    template <typename U, qualifier P>
    MIM_CONSTEXPR VectorT<1, T, Q>::VectorT(VectorT<3, U, P> const& v) : x(static_cast<T>(v.x)) {}


    /// Element Accessors

    template <typename T, qualifier Q>
    MIM_CONSTEXPR T& VectorT<1, T, Q>::operator [] (typename VectorT<1, T, Q>::size_type)
    {
        return x;
    }

    template <typename T, qualifier Q>
    MIM_CONSTEXPR const T& VectorT<1, T, Q>::operator [] (typename VectorT<1, T, Q>::size_type) const
    {
        return x;
    }


    /// Unary Operators

    template <typename T, qualifier Q>
    template <typename U>
    MIM_CONSTEXPR VectorT<1, T, Q>& VectorT<1, T, Q>::operator = (VectorT<1, U, Q> const& v)
    {
        this->x = static_cast<T>(v.x);
        return *this;
    }

    template <typename T, qualifier Q>
    template <typename U>
    MIM_CONSTEXPR VectorT<1, T, Q>& VectorT<1, T, Q>::operator += (U scalar)
    {
        this->x += static_cast<T>(scalar);
        return *this;
    }

    template <typename T, qualifier Q>
    template <typename U>
    MIM_CONSTEXPR VectorT<1, T, Q>& VectorT<1, T, Q>::operator += (VectorT<1, U, Q> const& v)
    {
        this->x += static_cast<T>(v.x);
        return *this;
    }

    template <typename T, qualifier Q>
    template <typename U>
    MIM_CONSTEXPR VectorT<1, T, Q>& VectorT<1, T, Q>::operator -= (U scalar)
    {
        this->x -= static_cast<T>(scalar);
        return *this;
    }

    template <typename T, qualifier Q>
    template <typename U>
    MIM_CONSTEXPR VectorT<1, T, Q>& VectorT<1, T, Q>::operator -= (VectorT<1, U, Q> const& v)
    {
        this->x -= static_cast<T>(v.x);
        return *this;
    }

    template <typename T, qualifier Q>
    template <typename U>
    MIM_CONSTEXPR VectorT<1, T, Q>& VectorT<1, T, Q>::operator *= (U scalar)
    {
        this->x *= static_cast<T>(scalar);
        return *this;
    }

    template <typename T, qualifier Q>
    template <typename U>
    MIM_CONSTEXPR VectorT<1, T, Q>& VectorT<1, T, Q>::operator *= (VectorT<1, U, Q> const& v)
    {
        this->x *= static_cast<T>(v.x);
        return *this;
    }

    template <typename T, qualifier Q>
    template <typename U>
    MIM_CONSTEXPR VectorT<1, T, Q>& VectorT<1, T, Q>::operator /= (U scalar)
    {
        this->x /= static_cast<T>(scalar);
        return *this;
    }

    template <typename T, qualifier Q>
    template <typename U>
    MIM_CONSTEXPR VectorT<1, T, Q>& VectorT<1, T, Q>::operator /= (VectorT<1, U, Q> const& v)
    {
        this->x /= static_cast<T>(v.x);
        return *this;
    }

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q>& VectorT<1, T, Q>::operator ++ ()
    {
        ++this->x;
        return *this;
    }

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q>& VectorT<1, T, Q>::operator -- ()
    {
        --this->x;
        return *this;
    }

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> VectorT<1, T, Q>::operator ++ (int)
    {
        VectorT<1, T, Q> result(*this);
        ++*this;
        return result;
    }

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> VectorT<1, T, Q>::operator -- (int)
    {
        VectorT<1, T, Q> result(*this);
        --*this;
        return result;
    }


    /// Unary bit operators

    template <typename T, qualifier Q>
    template <typename U>
    MIM_CONSTEXPR VectorT<1, T, Q>& VectorT<1, T, Q>::operator %= (U scalar)
    {
        this->x %= static_cast<T>(scalar);
        return *this;
    }

    template <typename T, qualifier Q>
    template <typename U>
    MIM_CONSTEXPR VectorT<1, T, Q>& VectorT<1, T, Q>::operator %= (VectorT<1, U, Q> const& v)
    {
        this->x %= static_cast<T>(v.x);
        return *this;
    }

    template <typename T, qualifier Q>
    template <typename U>
    MIM_CONSTEXPR VectorT<1, T, Q>& VectorT<1, T, Q>::operator &= (U scalar)
    {
        this->x &= static_cast<T>(scalar);
        return *this;
    }

    template <typename T, qualifier Q>
    template <typename U>
    MIM_CONSTEXPR VectorT<1, T, Q>& VectorT<1, T, Q>::operator &= (VectorT<1, U, Q> const& v)
    {
        this->x &= static_cast<T>(v.x);
        return *this;
    }

    template <typename T, qualifier Q>
    template <typename U>
    MIM_CONSTEXPR VectorT<1, T, Q>& VectorT<1, T, Q>::operator |= (U scalar)
    {
        this->x |= static_cast<T>(scalar);
        return *this;
    }

    template <typename T, qualifier Q>
    template <typename U>
    MIM_CONSTEXPR VectorT<1, T, Q>& VectorT<1, T, Q>::operator |= (VectorT<1, U, Q> const& v)
    {
        this->x |= static_cast<T>(v.x);
        return *this;
    }

    template <typename T, qualifier Q>
    template <typename U>
    MIM_CONSTEXPR VectorT<1, T, Q>& VectorT<1, T, Q>::operator ^= (U scalar)
    {
        this->x ^= static_cast<T>(scalar);
        return *this;
    }

    template <typename T, qualifier Q>
    template <typename U>
    MIM_CONSTEXPR VectorT<1, T, Q>& VectorT<1, T, Q>::operator ^= (VectorT<1, U, Q> const& v)
    {
        this->x ^= static_cast<T>(v.x);
        return *this;
    }

    template <typename T, qualifier Q>
    template <typename U>
    MIM_CONSTEXPR VectorT<1, T, Q>& VectorT<1, T, Q>::operator <<= (U scalar)
    {
        this->x <<= static_cast<T>(scalar);
        return *this;
    }

    template <typename T, qualifier Q>
    template <typename U>
    MIM_CONSTEXPR VectorT<1, T, Q>& VectorT<1, T, Q>::operator <<= (VectorT<1, U, Q> const& v)
    {
        this->x <<= static_cast<T>(v.x);
        return *this;
    }

    template <typename T, qualifier Q>
    template <typename U>
    MIM_CONSTEXPR VectorT<1, T, Q>& VectorT<1, T, Q>::operator >>= (U scalar)
    {
        this->x >>= static_cast<T>(scalar);
        return *this;
    }

    template <typename T, qualifier Q>
    template <typename U>
    MIM_CONSTEXPR VectorT<1, T, Q>& VectorT<1, T, Q>::operator >>= (VectorT<1, U, Q> const& v)
    {
        this->x >>= static_cast<T>(v.x);
        return *this;
    }


    /// Unary constant operators

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator + (VectorT<1, T, Q> const& v)
    {
        return v;
    }

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator - (VectorT<1, T, Q> const& v)
    {
        return VectorT<1, T, Q>(-v.x);
    }


    /// Binary arithmetic operators

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator + (VectorT<1, T, Q> const& v, T scalar)
    {
        return VectorT<1, T, Q>(v.x + scalar);
    }

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator + (T scalar, VectorT<1, T, Q> const& v)
    {
        return VectorT<1, T, Q>(scalar + v.x);
    }

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator + (VectorT<1, T, Q> const& v1, VectorT<1, T, Q> const& v2)
    {
        return VectorT<1, T, Q>(v1.x + v2.x);
    }

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator - (VectorT<1, T, Q> const& v, T scalar)
    {
        return VectorT<1, T, Q>(v.x - scalar);
    }

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator - (T scalar, VectorT<1, T, Q> const& v)
    {
        return VectorT<1, T, Q>(scalar - v.x);
    }

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator - (VectorT<1, T, Q> const& v1, VectorT<1, T, Q> const& v2)
    {
        return VectorT<1, T, Q>(v1.x - v2.x);
    }

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator * (VectorT<1, T, Q> const& v, T scalar)
    {
        return VectorT<1, T, Q>(v.x * scalar);
    }

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator * (T scalar, VectorT<1, T, Q> const& v)
    {
        return VectorT<1, T, Q>(scalar * v.x);
    }

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator * (VectorT<1, T, Q> const& v1, VectorT<1, T, Q> const& v2)
    {
        return VectorT<1, T, Q>(v1.x * v2.x);
    }

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator / (VectorT<1, T, Q> const& v, T scalar)
    {
        return VectorT<1, T, Q>(v.x / scalar);
    }

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator / (T scalar, VectorT<1, T, Q> const& v)
    {
        return VectorT<1, T, Q>(scalar / v.x);
    }

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator / (VectorT<1, T, Q> const& v1, VectorT<1, T, Q> const& v2)
    {
        return VectorT<1, T, Q>(v1.x / v2.x);
    }


    /// Binary bit operators

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator % (VectorT<1, T, Q> const& v, T scalar)
    {
        return VectorT<1, T, Q>(v.x % scalar);
    }

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator % (T scalar, VectorT<1, T, Q> const& v)
    {
        return VectorT<1, T, Q>(scalar % v.x);
    }

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator % (VectorT<1, T, Q> const& v1, VectorT<1, T, Q> const& v2)
    {
        return VectorT<1, T, Q>(v1.x % v2.x);
    }

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator & (VectorT<1, T, Q> const& v, T scalar)
    {
        return VectorT<1, T, Q>(v.x & scalar);
    }

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator & (T scalar, VectorT<1, T, Q> const& v)
    {
        return VectorT<1, T, Q>(scalar & v.x);
    }

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator & (VectorT<1, T, Q> const& v1, VectorT<1, T, Q> const& v2)
    {
        return VectorT<1, T, Q>(v1.x & v2.x);
    }

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator | (VectorT<1, T, Q> const& v, T scalar)
    {
        return VectorT<1, T, Q>(v.x | scalar);
    }

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator | (T scalar, VectorT<1, T, Q> const& v)
    {
        return VectorT<1, T, Q>(scalar | v.x);
    }

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator | (VectorT<1, T, Q> const& v1, VectorT<1, T, Q> const& v2)
    {
        return VectorT<1, T, Q>(v1.x | v2.x);
    }

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator ^ (VectorT<1, T, Q> const& v, T scalar)
    {
        return VectorT<1, T, Q>(v.x ^ scalar);
    }

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator ^ (T scalar, VectorT<1, T, Q> const& v)
    {
        return VectorT<1, T, Q>(scalar ^ v.x);
    }

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator ^ (VectorT<1, T, Q> const& v1, VectorT<1, T, Q> const& v2)
    {
        return VectorT<1, T, Q>(v1.x ^ v2.x);
    }

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator << (VectorT<1, T, Q> const& v, T scalar)
    {
        return VectorT<1, T, Q>(v.x << scalar);
    }

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator << (T scalar, VectorT<1, T, Q> const& v)
    {
        return VectorT<1, T, Q>(scalar << v.x);
    }

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator << (VectorT<1, T, Q> const& v1, VectorT<1, T, Q> const& v2)
    {
        return VectorT<1, T, Q>(v1.x << v2.x);
    }

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator >> (VectorT<1, T, Q> const& v, T scalar)
    {
        return VectorT<1, T, Q>(v.x >> scalar);
    }

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator >> (T scalar, VectorT<1, T, Q> const& v)
    {
        return VectorT<1, T, Q>(scalar >> v.x);
    }

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator >> (VectorT<1, T, Q> const& v1, VectorT<1, T, Q> const& v2)
    {
        return VectorT<1, T, Q>(v1.x >> v2.x);
    }

    template <typename T, qualifier Q>
    MIM_CONSTEXPR VectorT<1, T, Q> operator ~ (VectorT<1, T, Q> const& v)
    {
        return VectorT<1, T, Q>(~v.x);
    }


    /// Boolean operators

    template <typename T, qualifier Q>
    MIM_CONSTEXPR bool operator == (VectorT<1, T, Q> const& v1, VectorT<1, T, Q> const& v2)
    {
        return detail::Equal<T, Q, std::numeric_limits<T>::is_iec559, sizeof(T) * 2, detail::IsAligned<Q>::value>::compute(v1, v2);
    }

    template <typename T, qualifier Q>
    MIM_CONSTEXPR bool operator != (VectorT<1, T, Q> const& v1, VectorT<1, T, Q> const& v2)
    {
        return !(v1 == v2);
    }

    template <qualifier Q>
    MIM_CONSTEXPR bool operator && (VectorT<1, bool, Q> const& v1, VectorT<1, bool, Q> const& v2)
    {
        return VectorT<1, bool, Q>(v1.x && v2.x);
    }

    template <qualifier Q>
    MIM_CONSTEXPR bool operator || (VectorT<1, bool, Q> const& v1, VectorT<1, bool, Q> const& v2)
    {
        return VectorT<1, bool, Q>(v1.x || v2.x);
    }



} // namespace riot
