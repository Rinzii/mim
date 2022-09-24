#pragma once

#include <stdexcept>
#include <cassert>
#include <concepts>
#include <numbers>
#include <cmath>

namespace math
{

    template <typename T>
    concept ValidVecType = std::floating_point<T> || (std::integral<T> && !std::same_as<T, bool>);


    template <ValidVecType T>
    struct Vector3
    {
        //using ϵ = std::numeric_limits<T>::epsilon()
        // Vector properties
        T X {};

        T Y {};

        T Z {};

        /***************************************
        *	Constructors
        ****************************************/

        constexpr Vector3() noexcept : X( 0.0 ), Y( 0.0 ), Z( 0.0 ) {}

        constexpr Vector3( T x, T y, T z ) noexcept : X( x ), Y( y ), Z( z ) {}

        constexpr Vector3( const Vector3& in ) noexcept : X( in.X ), Y( in.Y ), Z( in.Z ) {}


        /***************************************
        *	Operators
        ****************************************/

        friend constexpr Vector3 operator+(Vector3 const& a, Vector3 const& b) noexcept {
            return { a.X + b.X, a.Y + b.Y, a.Z + b.Z };
        }

        friend constexpr Vector3 operator-(Vector3 const& a, Vector3 const& b) noexcept {
            return { a.X - b.X, a.Y - b.Y, a.Z - b.Z };
        }

        friend constexpr Vector3 operator*(Vector3 const& a, Vector3 const& b) noexcept {
            return { a.X * b.X, a.Y * b.Y, a.Z * b.Z };
        }

        friend constexpr Vector3 operator/(Vector3 const& a, Vector3 const& b) noexcept {
            if (b.X == 0.0 || b.X == 0.0 || b.X == 0.0)
                throw std::runtime_error("Math Error: Divide by zero error.\n");
            return { a.X / b.X, a.Y / b.Y, a.Z / b.Z };
        }

        friend constexpr Vector3 operator==(Vector3 const& l, Vector3 const& r) noexcept {
            float diffX = l.X - r.X;
            float diffY = l.Y - r.Y;
            float diffZ = l.Z - r.Z;
            float sqrtMag = diffX * diffX + diffY * diffY + diffZ * diffZ;
            return sqrtMag < std::numeric_limits<T>::epsilon();
        }

        friend constexpr Vector3 operator!=(Vector3 const& l, Vector3 const& r) noexcept {
            return !(l == r);
        }

        /***************************************
        *	Assignment Operators
        ****************************************/

        constexpr Vector3& operator+=(Vector3 const& rhs) noexcept {
            X += rhs.X;
            Y += rhs.Y;
            Z += rhs.Z;

            return *this;
        }

        constexpr Vector3& operator-=(Vector3 const& rhs) noexcept {
            X -= rhs.X;
            Y -= rhs.Y;
            Z -= rhs.Z;

            return *this;
        }

        constexpr Vector3& operator*=(Vector3 const& rhs) noexcept {
            X *= rhs.X;
            Y *= rhs.Y;
            Z *= rhs.Z;

            return *this;
        }

        constexpr Vector3& operator/=(Vector3 const& rhs) noexcept {

            if (rhs.X != 0.0 && rhs.Y != 0.0 && rhs.Z != 0.0)
            {
                X /= rhs.X;
                Y /= rhs.Y;
                Z /= rhs.Z;

                return *this;
            }

            throw std::runtime_error("Math Error: Divide by zero error.\n");
        }

        constexpr Vector3& operator+=(T const& type) noexcept {
            X += type.X;
            Y += type.Y;
            Z += type.Z;

            return *this;
        }

        constexpr Vector3& operator-=(T const& type) noexcept {
            X -= type.X;
            Y -= type.Y;
            Z -= type.Z;

            return *this;
        }

        constexpr Vector3& operator*=(T const& type) noexcept {
            X *= type.X;
            Y *= type.Y;
            Z *= type.Z;

            return *this;
        }

        constexpr Vector3& operator/=(T const& type) noexcept {
            if (type != 0.0)
            {
                X /= type;
                Y /= type;
                Z /= type;

                return *this;
            }

            throw std::runtime_error("Math Error: Divide by zero error.\n");
        }


    };

    template <typename T>
    constexpr Vector3<T> min(Vector3<T> const& a, Vector3<T> const& b) noexcept {
        return { std::min(a.X, b.X), std::min(a.Y, b.Y), std::min(a.Z, b.Z) };
    }

    template <typename T>
    constexpr Vector3<T> max(Vector3<T> const& a, Vector3<T> const& b) noexcept {
        return { std::max(a.X, b.X), std::max(a.Y, b.Y), std::max(a.Z, b.Z) };
    }

    template <typename T>
    constexpr Vector3<T> abs(Vector3<T> const& a) noexcept {
        return { std::abs(a.X), std::abs(a.Y), std::abs(a.Z) };
    }

    template <typename T>
    constexpr Vector3<T> lerp(Vector3<T> const& left, Vector3<T> const& right, float const& amount) noexcept {
        return {
                std::lerp(left.X, right.X, amount),
                std::lerp(left.Y, right.Y, amount),
                std::lerp(left.Z, right.Z, amount)
        };
    }

    template <typename T>
    constexpr float dot(Vector3<T> const& a, Vector3<T> const& b) noexcept {
        return  (a.X * b.X) + (a.Y * b.Y) + (a.Z * b.Z);
    }

    template <typename T>
    constexpr Vector3<T> cross(Vector3<T> const& left, Vector3<T> const& right) noexcept {
        return  {
                (left.Y * right.Z) - (left.Z * right.Y),
                (left.Z * right.X) - (left.X * right.Z),
                (left.X * right.Y) - (left.Y * right.X)
        };
    }

    template <typename T>
    constexpr Vector3<T> magnitude(Vector3<T> const& a, Vector3<T> const& b) noexcept {
        return std::sqrt(math::dot(a, b));
    }

    template <typename T>
    constexpr float distance(Vector3<T> const& a, Vector3<T> const& b) noexcept {
        return  math::magnitude(a - b);
    }

    template <typename T>
    constexpr Vector3<T> normalize(Vector3<T> const& a, Vector3<T> const& b) noexcept {
        return { a.X * b.X, a.Y * b.Y, a.Z * b.Z };
    }

    template <std::floating_point T>
    bool almost_equal(T x, T y, int ulp = 1) noexcept {
        constexpr auto ϵ = std::numeric_limits<T>::epsilon();
        return std::abs(x - y) <= ϵ * std::abs(x + y) * ulp
               || std::abs(x - y) <= std::numeric_limits<T>::min();
    }

}