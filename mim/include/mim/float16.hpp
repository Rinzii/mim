// 16 bit floating point data structure

#pragma once

#include <cstdint>
#include "internal/float16compressor.hpp"

namespace mim
{
    struct float16
    {
        uint16_t value;

        float16() = default;

        inline float16(const float16& other) : value(other.value) {}
        inline explicit float16(const uint16_t other) : value(other) {}

        inline float16& operator=(const float16& other)
        {
            value = other.value;
            return *this;
        }

        inline explicit float16(const float other)
        {
            value = Float16Compressor::Compress(other);
        }

        inline explicit operator float() const
        {
            uint16_t temp;
            std::memcpy(&temp, &value, sizeof(temp));
            return Float16Compressor::Decompress(temp);
        }

        inline float ToFloat() const
        {
            uint16_t temp;
            std::memcpy(&temp, &value, sizeof(temp));
            return Float16Compressor::Decompress(temp);
        }

        inline bool operator==(const float16& other) const
        {
            return value == other.value;
        }

        inline bool operator!=(const float16& other) const
        {
            return value != other.value;
        }

        static const float16 Zero() { return float16(static_cast<uint16_t>(0)); }
    };

    // Validate that the float16 structure is packed correctly.
    static_assert(sizeof(float16) == sizeof(uint16_t), "float16 structure is not packed correctly.");
}
