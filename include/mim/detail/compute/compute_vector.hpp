// Copyright WizWorks, Inc. All Rights Reserved.

#pragma once

#include "system/core.hpp"
#include <limits>

namespace mim::detail
{

    template <typename T, qualifier Q, bool IsFloat, std::size_t Size, bool IsAligned>
    struct Equal
    {
        static RIOT_CONSTEXPR bool compute(T a, T b)
        {
            return a == b;
        }

        static RIOT_CONSTEXPR bool compute(VectorT<1, T, Q> const& a, VectorT<1, T, Q> const& b)
        {
            return a.x == b.x;
        }

        static RIOT_CONSTEXPR bool compute(VectorT<2, T, Q> const& a, VectorT<2, T, Q> const& b)
        {
            return a.x == b.x && a.y == b.y;
        }

        static RIOT_CONSTEXPR bool compute(VectorT<3, T, Q> const& a, VectorT<3, T, Q> const& b)
        {
            return a.x == b.x && a.y == b.y && a.z == b.z;
        }

        static RIOT_CONSTEXPR bool compute(VectorT<4, T, Q> const& a, VectorT<4, T, Q> const& b)
        {
            return a.x == b.x && a.y == b.y && a.z == b.z && a.w == b.w;
        }
    };

    template <typename T, qualifier Q, bool IsFloat, std::size_t Size, bool IsAligned>
    struct NotEqual
    {
        static RIOT_CONSTEXPR bool compute(T a, T b)
        {
            return a != b;
        }

        static RIOT_CONSTEXPR bool compute(VectorT<1, T, Q> const& a, VectorT<1, T, Q> const& b)
        {
            return a.x != b.x;
        }

        static RIOT_CONSTEXPR bool compute(VectorT<2, T, Q> const& a, VectorT<2, T, Q> const& b)
        {
            return a.x != b.x || a.y != b.y;
        }

        static RIOT_CONSTEXPR bool compute(VectorT<3, T, Q> const& a, VectorT<3, T, Q> const& b)
        {
            return a.x != b.x || a.y != b.y || a.z != b.z;
        }

        static RIOT_CONSTEXPR bool compute(VectorT<4, T, Q> const& a, VectorT<4, T, Q> const& b)
        {
            return a.x != b.x || a.y != b.y || a.z != b.z || a.w != b.w;
        }
    };

    template <typename T, qualifier Q, bool Aligned>
    struct Add
    {
        static RIOT_CONSTEXPR bool compute(T a, T b)
        {
            return a + b;
        }

        static RIOT_CONSTEXPR bool compute(VectorT<1, T, Q> const& a, VectorT<1, T, Q> const& b)
        {
            return VectorT<1, T, Q>(a.x + b.x);
        }

        static RIOT_CONSTEXPR bool compute(VectorT<2, T, Q> const& a, VectorT<2, T, Q> const& b)
        {
            return VectorT<2, T, Q>(a.x + b.x, a.y + b.y);
        }

        static RIOT_CONSTEXPR bool compute(VectorT<3, T, Q> const& a, VectorT<3, T, Q> const& b)
        {
            return VectorT<3, T, Q>(a.x + b.x, a.y + b.y, a.z + b.z);
        }

        RIOT_CONSTEXPR static VectorT<4, T, Q> compute(VectorT<4, T, Q> const& a, VectorT<4, T, Q> const& b)
        {
            return VectorT<4, T, Q>(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
        }
    };

    template <typename T, qualifier Q, bool Aligned>
    struct Sub
    {
        static RIOT_CONSTEXPR bool compute(T a, T b)
        {
            return a - b;
        }

        static RIOT_CONSTEXPR bool compute(VectorT<1, T, Q> const& a, VectorT<1, T, Q> const& b)
        {
            return VectorT<1, T, Q>(a.x - b.x);
        }

        static RIOT_CONSTEXPR bool compute(VectorT<2, T, Q> const& a, VectorT<2, T, Q> const& b)
        {
            return VectorT<2, T, Q>(a.x - b.x, a.y - b.y);
        }

        static RIOT_CONSTEXPR bool compute(VectorT<3, T, Q> const& a, VectorT<3, T, Q> const& b)
        {
            return VectorT<3, T, Q>(a.x - b.x, a.y - b.y, a.z - b.z);
        }

        RIOT_CONSTEXPR static VectorT<4, T, Q> compute(VectorT<4, T, Q> const& a, VectorT<4, T, Q> const& b)
        {
            return VectorT<4, T, Q>(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
        }
    };

    template <typename T, qualifier Q, bool Aligned>
    struct Mul
    {
        static RIOT_CONSTEXPR bool compute(T a, T b)
        {
            return a * b;
        }

        static RIOT_CONSTEXPR bool compute(VectorT<1, T, Q> const& a, VectorT<1, T, Q> const& b)
        {
            return VectorT<1, T, Q>(a.x * b.x);
        }

        static RIOT_CONSTEXPR bool compute(VectorT<2, T, Q> const& a, VectorT<2, T, Q> const& b)
        {
            return VectorT<2, T, Q>(a.x * b.x, a.y * b.y);
        }

        static RIOT_CONSTEXPR bool compute(VectorT<3, T, Q> const& a, VectorT<3, T, Q> const& b)
        {
            return VectorT<3, T, Q>(a.x * b.x, a.y * b.y, a.z * b.z);
        }

        RIOT_CONSTEXPR static VectorT<4, T, Q> compute(VectorT<4, T, Q> const& a, VectorT<4, T, Q> const& b)
        {
            return VectorT<4, T, Q>(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w);
        }
    };

    template <typename T, qualifier Q, bool Aligned>
    struct Div
    {
        static RIOT_CONSTEXPR bool compute(T a, T b)
        {
            return a / b;
        }

        static RIOT_CONSTEXPR bool compute(VectorT<1, T, Q> const& a, VectorT<1, T, Q> const& b)
        {
            return VectorT<1, T, Q>(a.x / b.x);
        }

        static RIOT_CONSTEXPR bool compute(VectorT<2, T, Q> const& a, VectorT<2, T, Q> const& b)
        {
            return VectorT<2, T, Q>(a.x / b.x, a.y / b.y);
        }

        static RIOT_CONSTEXPR bool compute(VectorT<3, T, Q> const& a, VectorT<3, T, Q> const& b)
        {
            return VectorT<3, T, Q>(a.x / b.x, a.y / b.y, a.z / b.z);
        }

        RIOT_CONSTEXPR static VectorT<4, T, Q> compute(VectorT<4, T, Q> const& a, VectorT<4, T, Q> const& b)
        {
            return VectorT<4, T, Q>(a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w);
        }
    };

    template <typename T, qualifier Q, bool Aligned>
    struct Mod
    {
        static RIOT_CONSTEXPR bool compute(T a, T b)
        {
            return a % b;
        }

        static RIOT_CONSTEXPR bool compute(VectorT<1, T, Q> const& a, VectorT<1, T, Q> const& b)
        {
            return VectorT<1, T, Q>(a.x % b.x);
        }

        static RIOT_CONSTEXPR bool compute(VectorT<2, T, Q> const& a, VectorT<2, T, Q> const& b)
        {
            return VectorT<2, T, Q>(a.x % b.x, a.y % b.y);
        }

        static RIOT_CONSTEXPR bool compute(VectorT<3, T, Q> const& a, VectorT<3, T, Q> const& b)
        {
            return VectorT<3, T, Q>(a.x % b.x, a.y % b.y, a.z % b.z);
        }

        RIOT_CONSTEXPR static VectorT<4, T, Q> compute(VectorT<4, T, Q> const& a, VectorT<4, T, Q> const& b)
        {
            return VectorT<4, T, Q>(a.x % b.x, a.y % b.y, a.z % b.z, a.w % b.w);
        }
    };

    template <typename T, qualifier Q, int IsInt, std::size_t Size, bool Aligned>
    struct BitwiseAnd
    {
        static RIOT_CONSTEXPR bool compute(T a, T b)
        {
            return a & b;
        }

        static RIOT_CONSTEXPR bool compute(VectorT<1, T, Q> const& a, VectorT<1, T, Q> const& b)
        {
            return VectorT<1, T, Q>(a.x & b.x);
        }

        static RIOT_CONSTEXPR bool compute(VectorT<2, T, Q> const& a, VectorT<2, T, Q> const& b)
        {
            return VectorT<2, T, Q>(a.x & b.x, a.y & b.y);
        }

        static RIOT_CONSTEXPR bool compute(VectorT<3, T, Q> const& a, VectorT<3, T, Q> const& b)
        {
            return VectorT<3, T, Q>(a.x & b.x, a.y & b.y, a.z & b.z);
        }

        RIOT_CONSTEXPR static VectorT<4, T, Q> compute(VectorT<4, T, Q> const& a, VectorT<4, T, Q> const& b)
        {
            return VectorT<4, T, Q>(a.x & b.x, a.y & b.y, a.z & b.z, a.w & b.w);
        }
    };

    template <typename T, qualifier Q, bool IsFloat, std::size_t Size, bool Aligned>
    struct BitwiseOr
    {
        static RIOT_CONSTEXPR bool compute(T a, T b)
        {
            return a | b;
        }

        static RIOT_CONSTEXPR bool compute(VectorT<1, T, Q> const& a, VectorT<1, T, Q> const& b)
        {
            return VectorT<1, T, Q>(a.x | b.x);
        }

        static RIOT_CONSTEXPR bool compute(VectorT<2, T, Q> const& a, VectorT<2, T, Q> const& b)
        {
            return VectorT<2, T, Q>(a.x | b.x, a.y | b.y);
        }

        static RIOT_CONSTEXPR bool compute(VectorT<3, T, Q> const& a, VectorT<3, T, Q> const& b)
        {
            return VectorT<3, T, Q>(a.x | b.x, a.y | b.y, a.z | b.z);
        }

        RIOT_CONSTEXPR static VectorT<4, T, Q> compute(VectorT<4, T, Q> const& a, VectorT<4, T, Q> const& b)
        {
            return VectorT<4, T, Q>(a.x | b.x, a.y | b.y, a.z | b.z, a.w | b.w);
        }
    };

    template <typename T, qualifier Q, bool IsFloat, std::size_t Size, bool Aligned>
    struct Xor
    {
        static RIOT_CONSTEXPR bool compute(T a, T b)
        {
            return a ^ b;
        }

        static RIOT_CONSTEXPR bool compute(VectorT<1, T, Q> const& a, VectorT<1, T, Q> const& b)
        {
            return VectorT<1, T, Q>(a.x ^ b.x);
        }

        static RIOT_CONSTEXPR bool compute(VectorT<2, T, Q> const& a, VectorT<2, T, Q> const& b)
        {
            return VectorT<2, T, Q>(a.x ^ b.x, a.y ^ b.y);
        }

        static RIOT_CONSTEXPR bool compute(VectorT<3, T, Q> const& a, VectorT<3, T, Q> const& b)
        {
            return VectorT<3, T, Q>(a.x ^ b.x, a.y ^ b.y, a.z ^ b.z);
        }

        RIOT_CONSTEXPR static VectorT<4, T, Q> compute(VectorT<4, T, Q> const& a, VectorT<4, T, Q> const& b)
        {
            return VectorT<4, T, Q>(a.x ^ b.x, a.y ^ b.y, a.z ^ b.z, a.w ^ b.w);
        }
    };

    template <typename T, qualifier Q, bool IsFloat, std::size_t Size, bool Aligned>
    struct ShiftLeft
    {
        static RIOT_CONSTEXPR bool compute(T a, T b)
        {
            return a << b;
        }

        static RIOT_CONSTEXPR bool compute(VectorT<1, T, Q> const& a, VectorT<1, T, Q> const& b)
        {
            return VectorT<1, T, Q>(a.x << b.x);
        }

        static RIOT_CONSTEXPR bool compute(VectorT<2, T, Q> const& a, VectorT<2, T, Q> const& b)
        {
            return VectorT<2, T, Q>(a.x << b.x, a.y << b.y);
        }

        static RIOT_CONSTEXPR bool compute(VectorT<3, T, Q> const& a, VectorT<3, T, Q> const& b)
        {
            return VectorT<3, T, Q>(a.x << b.x, a.y << b.y, a.z << b.z);
        }

        RIOT_CONSTEXPR static VectorT<4, T, Q> compute(VectorT<4, T, Q> const& v, int shift)
        {
            return VectorT<4, T, Q>(v.x << shift, v.y << shift, v.z << shift, v.w << shift);
        }
    };

    template <typename T, qualifier Q, bool IsFloat, std::size_t Size, bool Aligned>
    struct ShiftRight
    {
        static RIOT_CONSTEXPR bool compute(T a, T b)
        {
            return a >> b;
        }

        static RIOT_CONSTEXPR bool compute(VectorT<1, T, Q> const& a, VectorT<1, T, Q> const& b)
        {
            return VectorT<1, T, Q>(a.x >> b.x);
        }

        static RIOT_CONSTEXPR bool compute(VectorT<2, T, Q> const& a, VectorT<2, T, Q> const& b)
        {
            return VectorT<2, T, Q>(a.x >> b.x, a.y >> b.y);
        }

        static RIOT_CONSTEXPR bool compute(VectorT<3, T, Q> const& a, VectorT<3, T, Q> const& b)
        {
            return VectorT<3, T, Q>(a.x >> b.x, a.y >> b.y, a.z >> b.z);
        }

        RIOT_CONSTEXPR static VectorT<4, T, Q> compute(VectorT<4, T, Q> const& v, int shift)
        {
            return VectorT<4, T, Q>(v.x >> shift, v.y >> shift, v.z >> shift, v.w >> shift);
        }
    };

    template <typename T, qualifier Q, bool IsFloat, std::size_t Size, bool Aligned>
    struct BitwiseNot
    {
        static RIOT_CONSTEXPR bool compute(T a)
        {
            return ~a;
        }

        static RIOT_CONSTEXPR bool compute(VectorT<1, T, Q> const& v)
        {
            return VectorT<1, T, Q>(~v.x);
        }

        static RIOT_CONSTEXPR bool compute(VectorT<2, T, Q> const& v)
        {
            return VectorT<2, T, Q>(~v.x, ~v.y);
        }

        static RIOT_CONSTEXPR bool compute(VectorT<3, T, Q> const& v)
        {
            return VectorT<3, T, Q>(~v.x, ~v.y, ~v.z);
        }

        RIOT_CONSTEXPR static VectorT<4, T, Q> compute(VectorT<4, T, Q> const& v)
        {
            return VectorT<4, T, Q>(~v.x, ~v.y, ~v.z, ~v.w);
        }
    };

    template <std::size_t S, typename T, qualifier Q, bool Aligned>
    struct Min
    {
        static RIOT_CONSTEXPR bool compute(T a, T b)
        {
            return min(a, b);
        }

        static RIOT_CONSTEXPR bool compute(VectorT<1, T, Q> const& a, VectorT<1, T, Q> const& b)
        {
            return VectorT<1, T, Q>(min(a.x, b.x));
        }

        static RIOT_CONSTEXPR bool compute(VectorT<2, T, Q> const& a, VectorT<2, T, Q> const& b)
        {
            return VectorT<2, T, Q>(min(a.x, b.x), min(a.y, b.y));
        }

        static RIOT_CONSTEXPR bool compute(VectorT<3, T, Q> const& a, VectorT<3, T, Q> const& b)
        {
            return VectorT<3, T, Q>(min(a.x, b.x), min(a.y, b.y), min(a.z, b.z));
        }

        RIOT_CONSTEXPR static VectorT<4, T, Q> compute(VectorT<4, T, Q> const& a, VectorT<4, T, Q> const& b)
        {
            return VectorT<4, T, Q>(min(a.x, b.x), min(a.y, b.y), min(a.z, b.z), min(a.w, b.w));
        }
    };

    template <std::size_t S, typename T, qualifier Q, bool Aligned>
    struct Max
    {
        static RIOT_CONSTEXPR bool compute(T a, T b)
        {
            return max(a, b);
        }

        static RIOT_CONSTEXPR bool compute(VectorT<1, T, Q> const& a, VectorT<1, T, Q> const& b)
        {
            return VectorT<1, T, Q>(max(a.x, b.x));
        }

        static RIOT_CONSTEXPR bool compute(VectorT<2, T, Q> const& a, VectorT<2, T, Q> const& b)
        {
            return VectorT<2, T, Q>(max(a.x, b.x), max(a.y, b.y));
        }

        static RIOT_CONSTEXPR bool compute(VectorT<3, T, Q> const& a, VectorT<3, T, Q> const& b)
        {
            return VectorT<3, T, Q>(max(a.x, b.x), max(a.y, b.y), max(a.z, b.z));
        }

        RIOT_CONSTEXPR static VectorT<4, T, Q> compute(VectorT<4, T, Q> const& a, VectorT<4, T, Q> const& b)
        {
            return VectorT<4, T, Q>(max(a.x, b.x), max(a.y, b.y), max(a.z, b.z), max(a.w, b.w));
        }
    };

    template <std::size_t S, typename T, qualifier Q, bool Aligned>
    struct Abs
    {
        static RIOT_CONSTEXPR bool compute(T a)
        {
            return abs(a);
        }

        static RIOT_CONSTEXPR bool compute(VectorT<1, T, Q> const& v)
        {
            return VectorT<1, T, Q>(abs(v.x));
        }

        static RIOT_CONSTEXPR bool compute(VectorT<2, T, Q> const& v)
        {
            return VectorT<2, T, Q>(abs(v.x), abs(v.y));
        }

        static RIOT_CONSTEXPR bool compute(VectorT<3, T, Q> const& v)
        {
            return VectorT<3, T, Q>(abs(v.x), abs(v.y), abs(v.z));
        }

        RIOT_CONSTEXPR static VectorT<4, T, Q> compute(VectorT<4, T, Q> const& v)
        {
            return VectorT<4, T, Q>(abs(v.x), abs(v.y), abs(v.z), abs(v.w));
        }

    };

    template <std::size_t S, typename T, qualifier Q, bool Aligned>
    struct Sign
    {
        static RIOT_CONSTEXPR bool compute(T a)
        {
            return sign(a);
        }

        static RIOT_CONSTEXPR bool compute(VectorT<1, T, Q> const& v)
        {
            return VectorT<1, T, Q>(sign(v.x));
        }

        static RIOT_CONSTEXPR bool compute(VectorT<2, T, Q> const& v)
        {
            return VectorT<2, T, Q>(sign(v.x), sign(v.y));
        }

        static RIOT_CONSTEXPR bool compute(VectorT<3, T, Q> const& v)
        {
            return VectorT<3, T, Q>(sign(v.x), sign(v.y), sign(v.z));
        }

        RIOT_CONSTEXPR static VectorT<4, T, Q> compute(VectorT<4, T, Q> const& v)
        {
            return VectorT<4, T, Q>(sign(v.x), sign(v.y), sign(v.z), sign(v.w));
        }
    };

    template <std::size_t S, typename T, qualifier Q, bool Aligned>
    struct Floor
    {
        static RIOT_CONSTEXPR bool compute(T a)
        {
            return floor(a);
        }

        static RIOT_CONSTEXPR bool compute(VectorT<1, T, Q> const& v)
        {
            return VectorT<1, T, Q>(floor(v.x));
        }

        static RIOT_CONSTEXPR bool compute(VectorT<2, T, Q> const& v)
        {
            return VectorT<2, T, Q>(floor(v.x), floor(v.y));
        }

        static RIOT_CONSTEXPR bool compute(VectorT<3, T, Q> const& v)
        {
            return VectorT<3, T, Q>(floor(v.x), floor(v.y), floor(v.z));
        }

        RIOT_CONSTEXPR static VectorT<4, T, Q> compute(VectorT<4, T, Q> const& v)
        {
            return VectorT<4, T, Q>(floor(v.x), floor(v.y), floor(v.z), floor(v.w));
        }
    };

    template <std::size_t S, typename T, qualifier Q, bool Aligned>
    struct Ceil
    {
        static RIOT_CONSTEXPR bool compute(T a)
        {
            return ceil(a);
        }

        static RIOT_CONSTEXPR bool compute(VectorT<1, T, Q> const& v)
        {
            return VectorT<1, T, Q>(ceil(v.x));
        }

        static RIOT_CONSTEXPR bool compute(VectorT<2, T, Q> const& v)
        {
            return VectorT<2, T, Q>(ceil(v.x), ceil(v.y));
        }

        static RIOT_CONSTEXPR bool compute(VectorT<3, T, Q> const& v)
        {
            return VectorT<3, T, Q>(ceil(v.x), ceil(v.y), ceil(v.z));
        }

        RIOT_CONSTEXPR static VectorT<4, T, Q> compute(VectorT<4, T, Q> const& v)
        {
            return VectorT<4, T, Q>(ceil(v.x), ceil(v.y), ceil(v.z), ceil(v.w));
        }
    };







} // namespace riot::detail
