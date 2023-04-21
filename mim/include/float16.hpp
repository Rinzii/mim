// 16 bit floating point data structure

#pragma once

#include <cstdint>
#include "internal/float16compressor.hpp"

namespace mim
{
    struct float16
    {
		union
		{
			uint16_t value;

			struct
			{
				uint16_t mantissa : 10;
				uint16_t exponent : 5;
				uint16_t sign : 1;
			} bits;
		};

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
			return Float16Compressor::Decompress(value);
		}

		inline float ToFloat() const
		{
			return Float16Compressor::Decompress(value);
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
}
