// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#pragma once

#include <cstdint>
#include <cstring>

#include "mim/internal/float16compressor.hpp"

// TODO: The half class needs to be further built on, but I need to use it internally more before I will improve it.

namespace mim
{
    struct half
    {
        uint16_t value;

        half() = default;

        inline half(const half& other) : value(other.value) {}
        inline explicit half(const uint16_t other) : value(other) {}

        inline half& operator=(const half& other) = default;

        inline explicit half(const float other)
        {
            value = Float16Compressor::Compress(other);
        }

        inline explicit operator float() const
        {
            uint16_t temp;
            std::memcpy(&temp, &value, sizeof(temp));
            return Float16Compressor::Decompress(temp);
        }

        inline float toFloat() const
        {
            uint16_t temp;
            std::memcpy(&temp, &value, sizeof(temp));
            return Float16Compressor::Decompress(temp);
        }

        inline bool operator==(const half& other) const
        {
            return value == other.value;
        }

        inline bool operator!=(const half& other) const
        {
            return value != other.value;
        }

        static half Zero() { return half(static_cast<uint16_t>(0)); }
    };

    // Validate that the half structure is packed correctly.
    static_assert(sizeof(half) == sizeof(uint16_t), "half structure is not packed correctly.");
}
