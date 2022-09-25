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
    struct Vector2
    {
        T X {};

        T Y {};

        /***************************************
        *	Constructors
        ****************************************/
        constexpr Vector2() noexcept : X( 0.0 ), Y( 0.0 ) {}

        constexpr Vector2( T x, T y ) noexcept : X( x ), Y( y ) {}

        constexpr Vector2( const Vector2& in ) noexcept : X( in.X ), Y( in.Y ) {}


        /***************************************
         * Operators
         * *************************************/

        friend constexpr Vector2 operator+(Vector2 const& a, Vector2 const& b) noexcept {
            return { a.X + b.X, a.Y + b.Y };
        }

        friend constexpr Vector2 operator-(Vector2 const& a, Vector2 const& b) noexcept {
            return { a.X - b.X, a.Y - b.Y };
        }

        friend constexpr Vector2 operator*(Vector2 const& a, Vector2 const& b) noexcept {
            return { a.X * b.X, a.Y * b.Y };
        }

        friend constexpr Vector2 operator/(Vector2 const& a, Vector2 const& b) noexcept {
            if (b.X == T{ 0 } || b.X == T{ 0 })
                throw std::runtime_error("Math Error: Divide by zero error.\n");
            return { a.X / b.X, a.Y / b.Y };
        }

        friend constexpr Vector2 operator==(Vector2 const& l, Vector2 const& r) noexcept {
            return l.X == r.X && l.Y == r.Y;
        }

        friend constexpr Vector2 operator!=(Vector2 const& l, Vector2 const& r) noexcept {
            return !(l == r);
        }

        /***************************************
        *	Assignment Operators
        ****************************************/

        constexpr Vector2& operator=(Vector2 const& in) noexcept {
            X = in.X;
            Y = in.Y;

            return *this;
        }

        constexpr Vector2& operator+=(Vector2 const& in) noexcept {
            X += in.X;
            Y += in.Y;

            return *this;
        }

        constexpr Vector2& operator-=(Vector2 const& in) noexcept {
            X -= in.X;
            Y -= in.Y;

            return *this;
        }

        constexpr Vector2& operator*=(Vector2 const& in) noexcept {
            X *= in.X;
            Y *= in.Y;

            return *this;
        }

        constexpr Vector2& operator/=(Vector2 const& in) noexcept {
            if (in.X == T{ 0 } || in.X == T{ 0 })
                throw std::runtime_error("Math Error: Divide by zero error.\n");
            X /= in.X;
            Y /= in.Y;

            return *this;
        }

        constexpr Vector2& operator+=(T const& type) noexcept {
            X += type;
            Y += type;

            return *this;
        }

        constexpr Vector2& operator-=(T const& type) noexcept {
            X += type;
            Y += type;

            return *this;
        }

        constexpr Vector2& operator*=(T const& type) noexcept {
            X += type;
            Y += type;

            return *this;
        }

        constexpr Vector2& operator/=(T const& type) noexcept {
            if (type == T{ 0 })
                throw std::runtime_error("Math Error: Divide by zero error.\n");
            X /= type;
            Y /= type;

            return *this;
        }
    };

    // TODO: Add in all of our free functions for all Vector2 operations.
}
