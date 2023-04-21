#pragma once

namespace mim
{
    struct vector4f
    {
        float x, y, z, w;

        inline vector4f() = default;

        vector4f(const float value) : x(value), y(value), z(value), w(value) {}
        vector4f(const float x, const float y, const float z, const float w) : x(x), y(y), z(z), w(w) {}
        vector4f(const vector2f& other) : x(other.x), y(other.y), z(0.0f), w(0.0f) {}
        vector4f(const vector3f& other) : x(other.x), y(other.y), z(other.z), w(0.0f) {}
        vector4f(const vector4f& other) : x(other.x), y(other.y), z(other.z), w(other.w) {}

        vector4f(const VectorT<2, float>& vec) : x(vec[0]), y(vec[1]), z(0.0f), w(0.0f) {}
        vector4f(const VectorT<3, float>& vec) : x(vec[0]), y(vec[1]), z(vec[2]), w(0.0f) {}
        vector4f(const VectorT<4, float>& vec) : x(vec[0]), y(vec[1]), z(vec[2]), w(vec[3]) {}

        vector4f(vector2f&& other) noexcept : x(other.x), y(other.y), z(0.0f), w(0.0f) {}
        vector4f(vector3f&& other) noexcept : x(other.x), y(other.y), z(other.z), w(0.0f) {}
        vector4f(vector4f&& other) noexcept : x(other.x), y(other.y), z(other.z), w(other.w) {}

        vector4f(VectorT<2, float>&& vec) : x(vec[0]), y(vec[1]), z(0.0f), w(0.0f) {}
        vector4f(VectorT<3, float>&& vec) : x(vec[0]), y(vec[1]), z(vec[2]), w(0.0f) {}
        vector4f(VectorT<4, float>&& vec) : x(vec[0]), y(vec[1]), z(vec[2]), w(vec[3]) {}

        vector4f& operator=(const vector2f& other)
        {
            x = other.x;
            y = other.y;
            z = 0.0f;
            w = 0.0f;
            return *this;
        }

        vector4f& operator=(const vector3f& other)
        {
            x = other.x;
            y = other.y;
            z = other.z;
            w = 0.0f;
            return *this;
        }

        vector4f& operator=(const vector4f& other)
        {
            x = other.x;
            y = other.y;
            z = other.z;
            w = other.w;
            return *this;
        }

        vector4f& operator=(const VectorT<2, float>& vec)
        {
            x = vec[0];
            y = vec[1];
            z = 0.0f;
            w = 0.0f;
            return *this;
        }

        vector4f& operator=(const VectorT<3, float>& vec)
        {
            x = vec[0];
            y = vec[1];
            z = vec[2];
            w = 0.0f;
            return *this;
        }

        vector4f& operator=(const VectorT<4, float>& vec)
        {
            x = vec[0];
            y = vec[1];
            z = vec[2];
            w = vec[3];
            return *this;
        }

        vector4f& operator=(vector2f&& other) noexcept
        {
            x = other.x;
            y = other.y;
            z = 0.0f;
            w = 0.0f;
            return *this;
        }

        vector4f& operator=(vector3f&& other) noexcept
        {
            x = other.x;
            y = other.y;
            z = other.z;
            w = 0.0f;
            return *this;
        }

        vector4f& operator=(vector4f&& other) noexcept
        {
            x = other.x;
            y = other.y;
            z = other.z;
            w = other.w;
            return *this;
        }

        vector4f& operator=(VectorT<2, float>&& vec)
        {
            x = vec[0];
            y = vec[1];
            z = 0.0f;
            w = 0.0f;
            return *this;
        }

        vector4f& operator=(VectorT<3, float>&& vec)
        {
            x = vec[0];
            y = vec[1];
            z = vec[2];
            w = 0.0f;
            return *this;
        }

        vector4f& operator=(VectorT<4, float>&& vec)
        {
            x = vec[0];
            y = vec[1];
            z = vec[2];
            w = vec[3];
            return *this;
        }

        // TODO: Add methods for vector4f
    };
}