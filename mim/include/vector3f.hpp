#pragma once

namespace mim
{
    struct vector3f
    {
        float x;
        float y;
        float z;

        inline vector3f() = default;
        vector3f(const float x, const float y, const float z) : x(x), y(y), z(z) {}
        vector3f(const vector3f& other) : x(other.x), y(other.y), z(other.z) {}
        vector3f(vector3f&& other) noexcept : x(other.x), y(other.y), z(other.z) {}
        vector3f& operator=(const vector3f& other)
        {
            x = other.x;
            y = other.y;
            z = other.z;
            return *this;
        }
        vector3f& operator=(vector3f&& other) noexcept
        {
            x = other.x;
            y = other.y;
            z = other.z;
            return *this;
        }
        ~vector3f() = default;

        inline bool operator==(const vector3f& other) const
        {
            return x == other.x && y == other.y && z == other.z;
        }

        inline bool operator!=(const vector3f& other) const
        {
            return x != other.x || y != other.y || z != other.z;
        }

        inline vector3f operator+(const vector3f& other) const
        {
            return vector3f(x + other.x, y + other.y, z + other.z);
        }

        inline vector3f operator-(const vector3f& other) const
        {
            return vector3f(x - other.x, y - other.y, z - other.z);
        }


    };
}