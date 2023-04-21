#pragma once

#include <bit>
#include <immintrin.h> // TODO: have this be handled by the build system

namespace mim
{
    namespace simd // TODO: Refactor this system later when we are implementing SIMD seriously to dynamically figure out what instructions are available.
    {
        // This quad type is using SSE intrinsics to perform SIMD operations
        using Quad = __m128;

        // Define constant arrays that can be used to mask specific components of a Quad value
        // Each array is aligned to a 16-byte boundary using alignas
        // The arrays consist of 4 unsigned integers, with one element set to 0xFFFFFFFF (to enable the corresponding component)
        // and the others set to 0 (to disable the corresponding components)
        // The arrays are named according to the components they enable/disable, such as X_MASKDATA, Y_MASKDATA, etc.
        // These constant arrays can be used to manipulate the elements of Quad values in a SIMD-friendly way.
        namespace internal {
            alignas(16) const unsigned int X_MASKDATA[4] =      { 0xFFFFFFFF,   0,          0,          0           };
            alignas(16) const unsigned int Y_MASKDATA[4] =      { 0,            0xFFFFFFFF, 0,          0           };
            alignas(16) const unsigned int Z_MASKDATA[4] =      { 0,            0,          0xFFFFFFFF, 0           };
            alignas(16) const unsigned int W_MASKDATA[4] =      { 0,            0,          0,          0xFFFFFFFF  };
            alignas(16) const unsigned int XY_MASKDATA[4] =     { 0xFFFFFFFF,   0xFFFFFFFF, 0,          0           };
            alignas(16) const unsigned int XZ_MASKDATA[4] =     { 0xFFFFFFFF,   0,          0xFFFFFFFF, 0           };
            alignas(16) const unsigned int YW_MASKDATA[4] =     { 0,            0xFFFFFFFF, 0,          0xFFFFFFFF  };
            alignas(16) const unsigned int XW_MASKDATA[4] =     { 0xFFFFFFFF,   0,          0,          0xFFFFFFFF  };
            alignas(16) const unsigned int YZ_MASKDATA[4] =     { 0,            0xFFFFFFFF, 0xFFFFFFFF, 0           };
            alignas(16) const unsigned int ZW_MASKDATA[4] =     { 0,            0,          0xFFFFFFFF, 0xFFFFFFFF  };
            alignas(16) const unsigned int XYZ_MASKDATA[4] =    { 0xFFFFFFFF,   0xFFFFFFFF, 0xFFFFFFFF, 0           };
            alignas(16) const unsigned int YZW_MASKDATA[4] =    { 0,            0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF  };
        } // namespace internal

        static const Quad X_MASK = _mm_load_ps(std::bit_cast<float[4]>(internal::X_MASKDATA));
        static const Quad Y_MASK = _mm_load_ps(std::bit_cast<float[4]>(internal::Y_MASKDATA));
        static const Quad Z_MASK = _mm_load_ps(std::bit_cast<float[4]>(internal::Z_MASKDATA));
        static const Quad W_MASK = _mm_load_ps(std::bit_cast<float[4]>(internal::W_MASKDATA));
        static const Quad XY_MASK = _mm_load_ps(std::bit_cast<float[4]>(internal::XY_MASKDATA));
        static const Quad XZ_MASK = _mm_load_ps(std::bit_cast<float[4]>(internal::XZ_MASKDATA));
        static const Quad XW_MASK = _mm_load_ps(std::bit_cast<float[4]>(internal::XW_MASKDATA));
        static const Quad YZ_MASK = _mm_load_ps(std::bit_cast<float[4]>(internal::YZ_MASKDATA));
        static const Quad YW_MASK = _mm_load_ps(std::bit_cast<float[4]>(internal::YW_MASKDATA));
        static const Quad ZW_MASK = _mm_load_ps(std::bit_cast<float[4]>(internal::ZW_MASKDATA));
        static const Quad XYZ_MASK = _mm_load_ps(std::bit_cast<float[4]>(internal::XYZ_MASKDATA));
        static const Quad YZW_MASK = _mm_load_ps(std::bit_cast<float[4]>(internal::YZW_MASKDATA));
        static constexpr Quad EPSILON_VALUE = _mm_set1_ps(std::bit_cast<float>(std::numeric_limits<float>::epsilon()));

    } // namespace simd
} // namespace mim