#pragma once

namespace mim
{
    // forward declaration
    struct vector3f;
    struct vector4f;
    struct vectorT;
}

namespace mim
{
    struct vector2f
    {
        float x, y;

        inline vector2f() = default;

        vector2f(const float value) : x(value), y(value) {}
        vector2f(const float x, const float y) : x(x), y(y) {}
        vector2f(const vector2f& other) : x(other.x), y(other.y) {}
        vector2f(const vector3f& other) : x(other.x), y(other.y) {}
        vector2f(const vector4f& other) : x(other.x), y(other.y) {}

        vector2f(const VectorT<2, float>& vec) : x(vec[0]), y(vec[1]) {}
        vector2f(const VectorT<3, float>& vec) : x(vec[0]), y(vec[1]) {}
        vector2f(const VectorT<4, float>& vec) : x(vec[0]), y(vec[1]) {}

        vector2f(vector2f&& other) noexcept : x(other.x), y(other.y) {}
        vector2f(vector3f&& other) noexcept : x(other.x), y(other.y) {}
        vector2f(vector4f&& other) noexcept : x(other.x), y(other.y) {}

        vector2f(VectorT<2, float>&& vec) : x(vec[0]), y(vec[1]) {}
        vector2f(VectorT<3, float>&& vec) : x(vec[0]), y(vec[1]) {}
        vector2f(VectorT<4, float>&& vec) : x(vec[0]), y(vec[1]) {}

        vector2f& operator=(const vector2f& other)
        {
            x = other.x;
            y = other.y;
            return *this;
        }

        vector2f& operator=(const vector3f& other)
        {
            x = other.x;
            y = other.y;
            return *this;
        }

        vector2f& operator=(const vector4f& other)
        {
            x = other.x;
            y = other.y;
            return *this;
        }

        vector2f& operator=(const VectorT<2, float>& vec)
        {
            x = vec[0];
            y = vec[1];
            return *this;
        }

        vector2f& operator=(const VectorT<3, float>& vec)
        {
            x = vec[0];
            y = vec[1];
            return *this;
        }

        vector2f& operator=(const VectorT<4, float>& vec)
        {
            x = vec[0];
            y = vec[1];
            return *this;
        }

        vector2f& operator=(vector2f&& other) noexcept
        {
            x = other.x;
            y = other.y;
            return *this;
        }

        vector2f& operator=(vector3f&& other) noexcept
        {
            x = other.x;
            y = other.y;
            return *this;
        }

        vector2f& operator=(vector4f&& other) noexcept
        {
            x = other.x;
            y = other.y;
            return *this;
        }

        vector2f& operator=(VectorT<2, float>&& vec)
        {
            x = vec[0];
            y = vec[1];
            return *this;
        }

        vector2f& operator=(VectorT<3, float>&& vec)
        {
            x = vec[0];
            y = vec[1];
            return *this;
        }

        vector2f& operator=(VectorT<4, float>&& vec)
        {
            x = vec[0];
            y = vec[1];
            return *this;
        }


        ~vector2f() = default;

        // TODO: Add methods for vector3f


    };
}