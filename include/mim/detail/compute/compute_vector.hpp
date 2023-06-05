// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#pragma once

#include "mim/detail/qualifier.hpp" 
#include <limits>

namespace mim::detail
{

    template <typename T, qualifier Q, bool IsFloat, std::size_t Size, bool IsAligned>
    struct Equal
    {
        static MIM_CONSTEXPR bool compute(T a, T b)
        {
            return a == b;
        }

        static MIM_CONSTEXPR bool compute(VectorT<1, T, Q> const& a, VectorT<1, T, Q> const& b)
        {
            return a.x == b.x;
        }

        static MIM_CONSTEXPR bool compute(VectorT<2, T, Q> const& a, VectorT<2, T, Q> const& b)
        {
            return a.x == b.x && a.y == b.y;
        }

        static MIM_CONSTEXPR bool compute(VectorT<3, T, Q> const& a, VectorT<3, T, Q> const& b)
        {
            return a.x == b.x && a.y == b.y && a.z == b.z;
        }

        static MIM_CONSTEXPR bool compute(VectorT<4, T, Q> const& a, VectorT<4, T, Q> const& b)
        {
            return a.x == b.x && a.y == b.y && a.z == b.z && a.w == b.w;
        }
    };

    template <typename T, qualifier Q, bool IsFloat, std::size_t Size, bool IsAligned>
    struct NotEqual
    {
        static MIM_CONSTEXPR bool compute(T a, T b)
        {
            return a != b;
        }

        static MIM_CONSTEXPR bool compute(VectorT<1, T, Q> const& a, VectorT<1, T, Q> const& b)
        {
            return a.x != b.x;
        }

        static MIM_CONSTEXPR bool compute(VectorT<2, T, Q> const& a, VectorT<2, T, Q> const& b)
        {
            return a.x != b.x || a.y != b.y;
        }

        static MIM_CONSTEXPR bool compute(VectorT<3, T, Q> const& a, VectorT<3, T, Q> const& b)
        {
            return a.x != b.x || a.y != b.y || a.z != b.z;
        }

        static MIM_CONSTEXPR bool compute(VectorT<4, T, Q> const& a, VectorT<4, T, Q> const& b)
        {
            return a.x != b.x || a.y != b.y || a.z != b.z || a.w != b.w;
        }
    };

    template <typename T, qualifier Q, bool Aligned>
    struct Add
    {
        static MIM_CONSTEXPR bool compute(T a, T b)
        {
            return a + b;
        }

        static MIM_CONSTEXPR bool compute(VectorT<1, T, Q> const& a, VectorT<1, T, Q> const& b)
        {
            return VectorT<1, T, Q>(a.x + b.x);
        }

        static MIM_CONSTEXPR bool compute(VectorT<2, T, Q> const& a, VectorT<2, T, Q> const& b)
        {
            return VectorT<2, T, Q>(a.x + b.x, a.y + b.y);
        }

        static MIM_CONSTEXPR bool compute(VectorT<3, T, Q> const& a, VectorT<3, T, Q> const& b)
        {
            return VectorT<3, T, Q>(a.x + b.x, a.y + b.y, a.z + b.z);
        }

        MIM_CONSTEXPR static VectorT<4, T, Q> compute(VectorT<4, T, Q> const& a, VectorT<4, T, Q> const& b)
        {
            return VectorT<4, T, Q>(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
        }
    };

    template <typename T, qualifier Q, bool Aligned>
    struct Sub
    {
        static MIM_CONSTEXPR bool compute(T a, T b)
        {
            return a - b;
        }

        static MIM_CONSTEXPR bool compute(VectorT<1, T, Q> const& a, VectorT<1, T, Q> const& b)
        {
            return VectorT<1, T, Q>(a.x - b.x);
        }

        static MIM_CONSTEXPR bool compute(VectorT<2, T, Q> const& a, VectorT<2, T, Q> const& b)
        {
            return VectorT<2, T, Q>(a.x - b.x, a.y - b.y);
        }

        static MIM_CONSTEXPR bool compute(VectorT<3, T, Q> const& a, VectorT<3, T, Q> const& b)
        {
            return VectorT<3, T, Q>(a.x - b.x, a.y - b.y, a.z - b.z);
        }

        MIM_CONSTEXPR static VectorT<4, T, Q> compute(VectorT<4, T, Q> const& a, VectorT<4, T, Q> const& b)
        {
            return VectorT<4, T, Q>(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
        }
    };

    template <typename T, qualifier Q, bool Aligned>
    struct Mul
    {
        static MIM_CONSTEXPR bool compute(T a, T b)
        {
            return a * b;
        }

        static MIM_CONSTEXPR bool compute(VectorT<1, T, Q> const& a, VectorT<1, T, Q> const& b)
        {
            return VectorT<1, T, Q>(a.x * b.x);
        }

        static MIM_CONSTEXPR bool compute(VectorT<2, T, Q> const& a, VectorT<2, T, Q> const& b)
        {
            return VectorT<2, T, Q>(a.x * b.x, a.y * b.y);
        }

        static MIM_CONSTEXPR bool compute(VectorT<3, T, Q> const& a, VectorT<3, T, Q> const& b)
        {
            return VectorT<3, T, Q>(a.x * b.x, a.y * b.y, a.z * b.z);
        }

        MIM_CONSTEXPR static VectorT<4, T, Q> compute(VectorT<4, T, Q> const& a, VectorT<4, T, Q> const& b)
        {
            return VectorT<4, T, Q>(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w);
        }
    };

    template <typename T, qualifier Q, bool Aligned>
    struct Div
    {
        static MIM_CONSTEXPR bool compute(T a, T b)
        {
            return a / b;
        }

        static MIM_CONSTEXPR bool compute(VectorT<1, T, Q> const& a, VectorT<1, T, Q> const& b)
        {
            return VectorT<1, T, Q>(a.x / b.x);
        }

        static MIM_CONSTEXPR bool compute(VectorT<2, T, Q> const& a, VectorT<2, T, Q> const& b)
        {
            return VectorT<2, T, Q>(a.x / b.x, a.y / b.y);
        }

        static MIM_CONSTEXPR bool compute(VectorT<3, T, Q> const& a, VectorT<3, T, Q> const& b)
        {
            return VectorT<3, T, Q>(a.x / b.x, a.y / b.y, a.z / b.z);
        }

        MIM_CONSTEXPR static VectorT<4, T, Q> compute(VectorT<4, T, Q> const& a, VectorT<4, T, Q> const& b)
        {
            return VectorT<4, T, Q>(a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w);
        }
    };

    template <typename T, qualifier Q, bool Aligned>
    struct Mod
    {
        static MIM_CONSTEXPR bool compute(T a, T b)
        {
            return a % b;
        }

        static MIM_CONSTEXPR bool compute(VectorT<1, T, Q> const& a, VectorT<1, T, Q> const& b)
        {
            return VectorT<1, T, Q>(a.x % b.x);
        }

        static MIM_CONSTEXPR bool compute(VectorT<2, T, Q> const& a, VectorT<2, T, Q> const& b)
        {
            return VectorT<2, T, Q>(a.x % b.x, a.y % b.y);
        }

        static MIM_CONSTEXPR bool compute(VectorT<3, T, Q> const& a, VectorT<3, T, Q> const& b)
        {
            return VectorT<3, T, Q>(a.x % b.x, a.y % b.y, a.z % b.z);
        }

        MIM_CONSTEXPR static VectorT<4, T, Q> compute(VectorT<4, T, Q> const& a, VectorT<4, T, Q> const& b)
        {
            return VectorT<4, T, Q>(a.x % b.x, a.y % b.y, a.z % b.z, a.w % b.w);
        }
    };

    template <typename T, qualifier Q, int IsInt, std::size_t Size, bool Aligned>
    struct BitwiseAnd
    {
        static MIM_CONSTEXPR bool compute(T a, T b)
        {
            return a & b;
        }

        static MIM_CONSTEXPR bool compute(VectorT<1, T, Q> const& a, VectorT<1, T, Q> const& b)
        {
            return VectorT<1, T, Q>(a.x & b.x);
        }

        static MIM_CONSTEXPR bool compute(VectorT<2, T, Q> const& a, VectorT<2, T, Q> const& b)
        {
            return VectorT<2, T, Q>(a.x & b.x, a.y & b.y);
        }

        static MIM_CONSTEXPR bool compute(VectorT<3, T, Q> const& a, VectorT<3, T, Q> const& b)
        {
            return VectorT<3, T, Q>(a.x & b.x, a.y & b.y, a.z & b.z);
        }

        MIM_CONSTEXPR static VectorT<4, T, Q> compute(VectorT<4, T, Q> const& a, VectorT<4, T, Q> const& b)
        {
            return VectorT<4, T, Q>(a.x & b.x, a.y & b.y, a.z & b.z, a.w & b.w);
        }
    };

    template <typename T, qualifier Q, bool IsFloat, std::size_t Size, bool Aligned>
    struct BitwiseOr
    {
        static MIM_CONSTEXPR bool compute(T a, T b)
        {
            return a | b;
        }

        static MIM_CONSTEXPR bool compute(VectorT<1, T, Q> const& a, VectorT<1, T, Q> const& b)
        {
            return VectorT<1, T, Q>(a.x | b.x);
        }

        static MIM_CONSTEXPR bool compute(VectorT<2, T, Q> const& a, VectorT<2, T, Q> const& b)
        {
            return VectorT<2, T, Q>(a.x | b.x, a.y | b.y);
        }

        static MIM_CONSTEXPR bool compute(VectorT<3, T, Q> const& a, VectorT<3, T, Q> const& b)
        {
            return VectorT<3, T, Q>(a.x | b.x, a.y | b.y, a.z | b.z);
        }

        MIM_CONSTEXPR static VectorT<4, T, Q> compute(VectorT<4, T, Q> const& a, VectorT<4, T, Q> const& b)
        {
            return VectorT<4, T, Q>(a.x | b.x, a.y | b.y, a.z | b.z, a.w | b.w);
        }
    };

    template <typename T, qualifier Q, bool IsFloat, std::size_t Size, bool Aligned>
    struct Xor
    {
        static MIM_CONSTEXPR bool compute(T a, T b)
        {
            return a ^ b;
        }

        static MIM_CONSTEXPR bool compute(VectorT<1, T, Q> const& a, VectorT<1, T, Q> const& b)
        {
            return VectorT<1, T, Q>(a.x ^ b.x);
        }

        static MIM_CONSTEXPR bool compute(VectorT<2, T, Q> const& a, VectorT<2, T, Q> const& b)
        {
            return VectorT<2, T, Q>(a.x ^ b.x, a.y ^ b.y);
        }

        static MIM_CONSTEXPR bool compute(VectorT<3, T, Q> const& a, VectorT<3, T, Q> const& b)
        {
            return VectorT<3, T, Q>(a.x ^ b.x, a.y ^ b.y, a.z ^ b.z);
        }

        MIM_CONSTEXPR static VectorT<4, T, Q> compute(VectorT<4, T, Q> const& a, VectorT<4, T, Q> const& b)
        {
            return VectorT<4, T, Q>(a.x ^ b.x, a.y ^ b.y, a.z ^ b.z, a.w ^ b.w);
        }
    };

    template <typename T, qualifier Q, bool IsFloat, std::size_t Size, bool Aligned>
    struct ShiftLeft
    {
        static MIM_CONSTEXPR bool compute(T a, T b)
        {
            return a << b;
        }

        static MIM_CONSTEXPR bool compute(VectorT<1, T, Q> const& a, VectorT<1, T, Q> const& b)
        {
            return VectorT<1, T, Q>(a.x << b.x);
        }

        static MIM_CONSTEXPR bool compute(VectorT<2, T, Q> const& a, VectorT<2, T, Q> const& b)
        {
            return VectorT<2, T, Q>(a.x << b.x, a.y << b.y);
        }

        static MIM_CONSTEXPR bool compute(VectorT<3, T, Q> const& a, VectorT<3, T, Q> const& b)
        {
            return VectorT<3, T, Q>(a.x << b.x, a.y << b.y, a.z << b.z);
        }

        MIM_CONSTEXPR static VectorT<4, T, Q> compute(VectorT<4, T, Q> const& v, int shift)
        {
            return VectorT<4, T, Q>(v.x << shift, v.y << shift, v.z << shift, v.w << shift);
        }
    };

    template <typename T, qualifier Q, bool IsFloat, std::size_t Size, bool Aligned>
    struct ShiftRight
    {
        static MIM_CONSTEXPR bool compute(T a, T b)
        {
            return a >> b;
        }

        static MIM_CONSTEXPR bool compute(VectorT<1, T, Q> const& a, VectorT<1, T, Q> const& b)
        {
            return VectorT<1, T, Q>(a.x >> b.x);
        }

        static MIM_CONSTEXPR bool compute(VectorT<2, T, Q> const& a, VectorT<2, T, Q> const& b)
        {
            return VectorT<2, T, Q>(a.x >> b.x, a.y >> b.y);
        }

        static MIM_CONSTEXPR bool compute(VectorT<3, T, Q> const& a, VectorT<3, T, Q> const& b)
        {
            return VectorT<3, T, Q>(a.x >> b.x, a.y >> b.y, a.z >> b.z);
        }

        MIM_CONSTEXPR static VectorT<4, T, Q> compute(VectorT<4, T, Q> const& v, int shift)
        {
            return VectorT<4, T, Q>(v.x >> shift, v.y >> shift, v.z >> shift, v.w >> shift);
        }
    };

    template <typename T, qualifier Q, bool IsFloat, std::size_t Size, bool Aligned>
    struct BitwiseNot
    {
        static MIM_CONSTEXPR bool compute(T a)
        {
            return ~a;
        }

        static MIM_CONSTEXPR bool compute(VectorT<1, T, Q> const& v)
        {
            return VectorT<1, T, Q>(~v.x);
        }

        static MIM_CONSTEXPR bool compute(VectorT<2, T, Q> const& v)
        {
            return VectorT<2, T, Q>(~v.x, ~v.y);
        }

        static MIM_CONSTEXPR bool compute(VectorT<3, T, Q> const& v)
        {
            return VectorT<3, T, Q>(~v.x, ~v.y, ~v.z);
        }

        MIM_CONSTEXPR static VectorT<4, T, Q> compute(VectorT<4, T, Q> const& v)
        {
            return VectorT<4, T, Q>(~v.x, ~v.y, ~v.z, ~v.w);
        }
    };

    template <std::size_t S, typename T, qualifier Q, bool Aligned>
    struct Min
    {
        static MIM_CONSTEXPR bool compute(T a, T b)
        {
            return min(a, b);
        }

        static MIM_CONSTEXPR bool compute(VectorT<1, T, Q> const& a, VectorT<1, T, Q> const& b)
        {
            return VectorT<1, T, Q>(min(a.x, b.x));
        }

        static MIM_CONSTEXPR bool compute(VectorT<2, T, Q> const& a, VectorT<2, T, Q> const& b)
        {
            return VectorT<2, T, Q>(min(a.x, b.x), min(a.y, b.y));
        }

        static MIM_CONSTEXPR bool compute(VectorT<3, T, Q> const& a, VectorT<3, T, Q> const& b)
        {
            return VectorT<3, T, Q>(min(a.x, b.x), min(a.y, b.y), min(a.z, b.z));
        }

        MIM_CONSTEXPR static VectorT<4, T, Q> compute(VectorT<4, T, Q> const& a, VectorT<4, T, Q> const& b)
        {
            return VectorT<4, T, Q>(min(a.x, b.x), min(a.y, b.y), min(a.z, b.z), min(a.w, b.w));
        }
    };

    template <std::size_t S, typename T, qualifier Q, bool Aligned>
    struct Max
    {
        static MIM_CONSTEXPR bool compute(T a, T b)
        {
            return max(a, b);
        }

        static MIM_CONSTEXPR bool compute(VectorT<1, T, Q> const& a, VectorT<1, T, Q> const& b)
        {
            return VectorT<1, T, Q>(max(a.x, b.x));
        }

        static MIM_CONSTEXPR bool compute(VectorT<2, T, Q> const& a, VectorT<2, T, Q> const& b)
        {
            return VectorT<2, T, Q>(max(a.x, b.x), max(a.y, b.y));
        }

        static MIM_CONSTEXPR bool compute(VectorT<3, T, Q> const& a, VectorT<3, T, Q> const& b)
        {
            return VectorT<3, T, Q>(max(a.x, b.x), max(a.y, b.y), max(a.z, b.z));
        }

        MIM_CONSTEXPR static VectorT<4, T, Q> compute(VectorT<4, T, Q> const& a, VectorT<4, T, Q> const& b)
        {
            return VectorT<4, T, Q>(max(a.x, b.x), max(a.y, b.y), max(a.z, b.z), max(a.w, b.w));
        }
    };

    template <std::size_t S, typename T, qualifier Q, bool Aligned>
    struct Abs
    {
        static MIM_CONSTEXPR bool compute(T a)
        {
            return abs(a);
        }

        static MIM_CONSTEXPR bool compute(VectorT<1, T, Q> const& v)
        {
            return VectorT<1, T, Q>(abs(v.x));
        }

        static MIM_CONSTEXPR bool compute(VectorT<2, T, Q> const& v)
        {
            return VectorT<2, T, Q>(abs(v.x), abs(v.y));
        }

        static MIM_CONSTEXPR bool compute(VectorT<3, T, Q> const& v)
        {
            return VectorT<3, T, Q>(abs(v.x), abs(v.y), abs(v.z));
        }

        MIM_CONSTEXPR static VectorT<4, T, Q> compute(VectorT<4, T, Q> const& v)
        {
            return VectorT<4, T, Q>(abs(v.x), abs(v.y), abs(v.z), abs(v.w));
        }

    };

    template <std::size_t S, typename T, qualifier Q, bool Aligned>
    struct Sign
    {
        static MIM_CONSTEXPR bool compute(T a)
        {
            return sign(a);
        }

        static MIM_CONSTEXPR bool compute(VectorT<1, T, Q> const& v)
        {
            return VectorT<1, T, Q>(sign(v.x));
        }

        static MIM_CONSTEXPR bool compute(VectorT<2, T, Q> const& v)
        {
            return VectorT<2, T, Q>(sign(v.x), sign(v.y));
        }

        static MIM_CONSTEXPR bool compute(VectorT<3, T, Q> const& v)
        {
            return VectorT<3, T, Q>(sign(v.x), sign(v.y), sign(v.z));
        }

        MIM_CONSTEXPR static VectorT<4, T, Q> compute(VectorT<4, T, Q> const& v)
        {
            return VectorT<4, T, Q>(sign(v.x), sign(v.y), sign(v.z), sign(v.w));
        }
    };

    template <std::size_t S, typename T, qualifier Q, bool Aligned>
    struct Floor
    {
        static MIM_CONSTEXPR bool compute(T a)
        {
            return floor(a);
        }

        static MIM_CONSTEXPR bool compute(VectorT<1, T, Q> const& v)
        {
            return VectorT<1, T, Q>(floor(v.x));
        }

        static MIM_CONSTEXPR bool compute(VectorT<2, T, Q> const& v)
        {
            return VectorT<2, T, Q>(floor(v.x), floor(v.y));
        }

        static MIM_CONSTEXPR bool compute(VectorT<3, T, Q> const& v)
        {
            return VectorT<3, T, Q>(floor(v.x), floor(v.y), floor(v.z));
        }

        MIM_CONSTEXPR static VectorT<4, T, Q> compute(VectorT<4, T, Q> const& v)
        {
            return VectorT<4, T, Q>(floor(v.x), floor(v.y), floor(v.z), floor(v.w));
        }
    };

    template <std::size_t S, typename T, qualifier Q, bool Aligned>
    struct Ceil
    {
        static MIM_CONSTEXPR bool compute(T a)
        {
            return ceil(a);
        }

        static MIM_CONSTEXPR bool compute(VectorT<1, T, Q> const& v)
        {
            return VectorT<1, T, Q>(ceil(v.x));
        }

        static MIM_CONSTEXPR bool compute(VectorT<2, T, Q> const& v)
        {
            return VectorT<2, T, Q>(ceil(v.x), ceil(v.y));
        }

        static MIM_CONSTEXPR bool compute(VectorT<3, T, Q> const& v)
        {
            return VectorT<3, T, Q>(ceil(v.x), ceil(v.y), ceil(v.z));
        }

        MIM_CONSTEXPR static VectorT<4, T, Q> compute(VectorT<4, T, Q> const& v)
        {
            return VectorT<4, T, Q>(ceil(v.x), ceil(v.y), ceil(v.z), ceil(v.w));
        }
    };

} // namespace mim::detail
