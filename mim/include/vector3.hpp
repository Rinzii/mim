#pragma once

#include <stdexcept>
#include <cassert>
#include <concepts>
#include <numbers>
#include <cmath>

// All data structures in numerics should only do the bare minimum and not
// handle any operations more complex than basic mathematics. All complex operations
// should be handled by math.hpp.
namespace mim
{
    template <typename T>
    struct vector3
    {
        T X;
        T Y;
        T Z;

        constexpr vector3() noexcept
            : X{ T{0} }
            , Y{ T{0} }
            , Z{ T{0} }
        {
        }

        constexpr vector3(T const& x, T const& y, T const& z) noexcept
            : X{ x }
            , Y{ y }
            , Z{ z }
        {
        }

        constexpr vector3(vector3 const& other) noexcept
            : X{ other.X }
            , Y{ other.Y }
            , Z{ other.Z }
        {
        }

        constexpr vector3(vector3&& other) noexcept
            : X{ std::move(other.X) }
            , Y{ std::move(other.Y) }
            , Z{ std::move(other.Z) }
        {
        }

        constexpr vector3& operator=(vector3 const& other) noexcept
        {
            X = other.X;
            Y = other.Y;
            Z = other.Z;

            return *this;
        }

        constexpr vector3& operator=(vector3&& other) noexcept
        {
            X = std::move(other.X);
            Y = std::move(other.Y);
            Z = std::move(other.Z);

            return *this;
        }

        constexpr vector3& operator+=(vector3 const& rhs) noexcept
        {
            X += rhs.X;
            Y += rhs.Y;
            Z += rhs.Z;

            return *this;
        }

        constexpr vector3& operator-=(vector3 const& rhs) noexcept
        {
            X -= rhs.X;
            Y -= rhs.Y;
            Z -= rhs.Z;

            return *this;
        }

        constexpr vector3& operator*=(vector3 const& rhs) noexcept
        {
            X *= rhs.X;
            Y *= rhs.Y;
            Z *= rhs.Z;

            return *this;
        }

        constexpr vector3& operator/=(vector3 const& rhs) noexcept
        {
            if (rhs.X != T{ 0 } && rhs.Y != T{ 0 } && rhs.Z != T{ 0 })
            {
                X /= rhs.X;
                Y /= rhs.Y;
                Z /= rhs.Z;

                return *this;
            }

            throw std::runtime_error("Math Error: Divide by zero error.\n");
        }
    };
}