#pragma once

// TODO: Finish this class at some point.

#include <cstdint>
#include "simdQuad.hpp"

namespace mim
{
    namespace simd
    {
        class alignas(16) Scalar
        {
        public:
            // Constructors
            Scalar() {}
            Scalar(const float f) : X(f), Y(f), Z(f), W(f) {}
            Scalar(const Scalar& v) : X(v.X), Y(v.Y), Z(v.Z), W(v.W) {}
            Scalar(const float* f) : X(f[0]), Y(f[1]), Z(f[2]), W(f[3]) {}
            Scalar(const Quad v) : V(v) {}

            // Destructor
            ~Scalar() {}

            const float* AsFloat() const { return &X; }

            // Assignment Operator - We shouldn't allow for more than this.
            Scalar& operator=(const Scalar& v)
            {
                X = v.X;
                Y = v.Y;
                Z = v.Z;
                W = v.W;
                return *this;
            }

            operator float() const { return X; }

            // Setting
            void Set(float f)
            {
                X = f;
                Y = f;
                Z = f;
                W = f;
            }

            void Set(const Scalar& v)
            {
                X = v.X;
                Y = v.Y;
                Z = v.Z;
                W = v.W;
            }

            void Set(const float* f)
            {
                X = f[0];
                Y = f[1];
                Z = f[2];
                W = f[3];
            }

            // Special Sets
            void SetZeros() { Set(0.0f); }
            void SetOnes() { Set(1.0f); }

            // Manipulation Methods.
            Scalar& Negate()
            {
                X = -X;
                Y = -Y;
                Z = -Z;
                W = -W;
                return *this;
            }

            Scalar Negated() const;

            Scalar Abs() const;

            bool IsZero() const;

            bool IsAlmostZero(const Quad epsilon = EPSILON_VALUE) const;

            union
            {
                struct
                {
                    float X;
                    float Y;
                    float Z;
                    float W;
                };
                struct
                {
                    uint32_t Xi;
                    uint32_t Yi;
                    uint32_t Zi;
                    uint32_t Wi;
                };
                Quad V;
            };
        };
    } // namespace simd
} // namespace mim