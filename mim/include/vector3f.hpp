#pragma once

namespace mim
{
    struct vector3f
    {
        float x, y, z;

        inline vector3f() = default;

        vector3f(const float value) : x(value), y(value), z(value) {}
        vector3f(const float x, const float y, const float z) : x(x), y(y), z(z) {}
        vector3f(const vector2f& other) : x(other.x), y(other.y), z(0.0f) {}
        vector3f(const vector3f& other) : x(other.x), y(other.y), z(other.z) {}
        vector3f(const vector4f& other) : x(other.x), y(other.y), z(other.z) {}

        vector3f(const VectorT<2, float>& vec) : x(vec[0]), y(vec[1]), z(0.0f) {}
        vector3f(const VectorT<3, float>& vec) : x(vec[0]), y(vec[1]), z(vec[2]) {}
        vector3f(const VectorT<4, float>& vec) : x(vec[0]), y(vec[1]), z(vec[2]) {}

        vector3f(vector2f&& other) noexcept : x(other.x), y(other.y), z(0.0f) {}
        vector3f(vector3f&& other) noexcept : x(other.x), y(other.y), z(other.z) {}
        vector3f(vector4f&& other) noexcept : x(other.x), y(other.y), z(other.z) {}

        vector3f(VectorT<2, float>&& vec) : x(vec[0]), y(vec[1]), z(0.0f) {}
        vector3f(VectorT<3, float>&& vec) : x(vec[0]), y(vec[1]), z(vec[2]) {}
        vector3f(VectorT<4, float>&& vec) : x(vec[0]), y(vec[1]), z(vec[2]) {}

        vector3f& operator=(const vector2f& other)
        {
            x = other.x;
            y = other.y;
            z = 0.0f;
            return *this;
        }

        vector3f& operator=(const vector3f& other)
        {
            x = other.x;
            y = other.y;
            z = other.z;
            return *this;
        }

        vector3f& operator=(const vector4f& other)
        {
            x = other.x;
            y = other.y;
            z = other.z;
            return *this;
        }

        vector3f& operator=(const VectorT<2, float>& vec)
        {
            x = vec[0];
            y = vec[1];
            z = 0.0f;
            return *this;
        }

        vector3f& operator=(const VectorT<3, float>& vec)
        {
            x = vec[0];
            y = vec[1];
            z = vec[2];
            return *this;
        }

        vector3f& operator=(const VectorT<4, float>& vec)
        {
            x = vec[0];
            y = vec[1];
            z = vec[2];
            return *this;
        }

        vector3f& operator=(vector2f&& other) noexcept
        {
            x = other.x;
            y = other.y;
            z = 0.0f;
            return *this;
        }

        vector3f& operator=(vector3f&& other) noexcept
        {
            x = other.x;
            y = other.y;
            z = other.z;
            return *this;
        }

        vector3f& operator=(vector4f&& other) noexcept
        {
            x = other.x;
            y = other.y;
            z = other.z;
            return *this;
        }

        vector3f& operator=(VectorT<2, float>&& vec)
        {
            x = vec[0];
            y = vec[1];
            z = 0.0f;
            return *this;
        }

        vector3f& operator=(VectorT<3, float>&& vec)
        {
            x = vec[0];
            y = vec[1];
            z = vec[2];
            return *this;
        }

        vector3f& operator=(VectorT<4, float>&& vec)
        {
            x = vec[0];
            y = vec[1];
            z = vec[2];
            return *this;
        }
        
        // TODO: Add methods for vector3f
    };
}