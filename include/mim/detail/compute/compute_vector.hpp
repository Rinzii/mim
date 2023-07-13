// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#pragma once

#include <limits>
#include "mim/detail/qualifier.hpp"

/*
 * Compute should only handle data type independent operations for the specified type we are computing.
 * We should not be implementing non-standard operations here. Such as the Dot product and so on.
 * The point of this file is to just offload more simple computations such as equality and inequality.
 * Allowing for internal implementation details to be instead handled in a singular place.
 * Anything detailing more specialized operations such as Dot and Cross should be handled inside func_vector.inl.
 */
namespace mim::detail
{

	template <typename T, qualifier Q, bool IsFloat, std::size_t Size, bool IsAligned>
	struct Equal {
		static constexpr bool compute(T a, T b) { return a == b; }

		static constexpr bool compute(vec<1, T, Q> const& a, vec<1, T, Q> const& b) { return a.x == b.x; }

		static constexpr bool compute(vec<2, T, Q> const& a, vec<2, T, Q> const& b) { return a.x == b.x && a.y == b.y; }

		static constexpr bool compute(vec<3, T, Q> const& a, vec<3, T, Q> const& b) { return a.x == b.x && a.y == b.y && a.z == b.z; }

		static constexpr bool compute(vec<4, T, Q> const& a, vec<4, T, Q> const& b) { return a.x == b.x && a.y == b.y && a.z == b.z && a.w == b.w; }
	};

	template <typename T, qualifier Q, bool IsFloat, std::size_t Size, bool IsAligned>
	struct NotEqual {
		static constexpr bool compute(T a, T b) { return a != b; }

		static constexpr bool compute(vec<1, T, Q> const& a, vec<1, T, Q> const& b) { return a.x != b.x; }

		static constexpr bool compute(vec<2, T, Q> const& a, vec<2, T, Q> const& b) { return a.x != b.x || a.y != b.y; }

		static constexpr bool compute(vec<3, T, Q> const& a, vec<3, T, Q> const& b) { return a.x != b.x || a.y != b.y || a.z != b.z; }

		static constexpr bool compute(vec<4, T, Q> const& a, vec<4, T, Q> const& b) { return a.x != b.x || a.y != b.y || a.z != b.z || a.w != b.w; }
	};

	template <typename T, qualifier Q, bool Aligned>
	struct Add {
		static constexpr bool compute(T a, T b) { return a + b; }

		static constexpr bool compute(vec<1, T, Q> const& a, vec<1, T, Q> const& b) { return vec<1, T, Q>(a.x + b.x); }

		static constexpr bool compute(vec<2, T, Q> const& a, vec<2, T, Q> const& b) { return vec<2, T, Q>(a.x + b.x, a.y + b.y); }

		static constexpr bool compute(vec<3, T, Q> const& a, vec<3, T, Q> const& b) { return vec<3, T, Q>(a.x + b.x, a.y + b.y, a.z + b.z); }

		constexpr static vec<4, T, Q> compute(vec<4, T, Q> const& a, vec<4, T, Q> const& b)
		{
			return vec<4, T, Q>(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
		}
	};

	template <typename T, qualifier Q, bool Aligned>
	struct Sub {
		static constexpr bool compute(T a, T b) { return a - b; }

		static constexpr bool compute(vec<1, T, Q> const& a, vec<1, T, Q> const& b) { return vec<1, T, Q>(a.x - b.x); }

		static constexpr bool compute(vec<2, T, Q> const& a, vec<2, T, Q> const& b) { return vec<2, T, Q>(a.x - b.x, a.y - b.y); }

		static constexpr bool compute(vec<3, T, Q> const& a, vec<3, T, Q> const& b) { return vec<3, T, Q>(a.x - b.x, a.y - b.y, a.z - b.z); }

		constexpr static vec<4, T, Q> compute(vec<4, T, Q> const& a, vec<4, T, Q> const& b)
		{
			return vec<4, T, Q>(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
		}
	};

	template <typename T, qualifier Q, bool Aligned>
	struct Mul {
		static constexpr bool compute(T a, T b) { return a * b; }

		static constexpr bool compute(vec<1, T, Q> const& a, vec<1, T, Q> const& b) { return vec<1, T, Q>(a.x * b.x); }

		static constexpr bool compute(vec<2, T, Q> const& a, vec<2, T, Q> const& b) { return vec<2, T, Q>(a.x * b.x, a.y * b.y); }

		static constexpr bool compute(vec<3, T, Q> const& a, vec<3, T, Q> const& b) { return vec<3, T, Q>(a.x * b.x, a.y * b.y, a.z * b.z); }

		constexpr static vec<4, T, Q> compute(vec<4, T, Q> const& a, vec<4, T, Q> const& b)
		{
			return vec<4, T, Q>(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w);
		}
	};

	template <typename T, qualifier Q, bool Aligned>
	struct Div {
		static constexpr bool compute(T a, T b) { return a / b; }

		static constexpr bool compute(vec<1, T, Q> const& a, vec<1, T, Q> const& b) { return vec<1, T, Q>(a.x / b.x); }

		static constexpr bool compute(vec<2, T, Q> const& a, vec<2, T, Q> const& b) { return vec<2, T, Q>(a.x / b.x, a.y / b.y); }

		static constexpr bool compute(vec<3, T, Q> const& a, vec<3, T, Q> const& b) { return vec<3, T, Q>(a.x / b.x, a.y / b.y, a.z / b.z); }

		constexpr static vec<4, T, Q> compute(vec<4, T, Q> const& a, vec<4, T, Q> const& b)
		{
			return vec<4, T, Q>(a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w);
		}
	};

	template <typename T, qualifier Q, bool Aligned>
	struct Mod {
		static constexpr bool compute(T a, T b) { return a % b; }

		static constexpr bool compute(vec<1, T, Q> const& a, vec<1, T, Q> const& b) { return vec<1, T, Q>(a.x % b.x); }

		static constexpr bool compute(vec<2, T, Q> const& a, vec<2, T, Q> const& b) { return vec<2, T, Q>(a.x % b.x, a.y % b.y); }

		static constexpr bool compute(vec<3, T, Q> const& a, vec<3, T, Q> const& b) { return vec<3, T, Q>(a.x % b.x, a.y % b.y, a.z % b.z); }

		constexpr static vec<4, T, Q> compute(vec<4, T, Q> const& a, vec<4, T, Q> const& b)
		{
			return vec<4, T, Q>(a.x % b.x, a.y % b.y, a.z % b.z, a.w % b.w);
		}
	};

	template <typename T, qualifier Q, int IsInt, std::size_t Size, bool Aligned>
	struct BitwiseAnd {
		static constexpr bool compute(T a, T b) { return a & b; }

		static constexpr bool compute(vec<1, T, Q> const& a, vec<1, T, Q> const& b) { return vec<1, T, Q>(a.x & b.x); }

		static constexpr bool compute(vec<2, T, Q> const& a, vec<2, T, Q> const& b) { return vec<2, T, Q>(a.x & b.x, a.y & b.y); }

		static constexpr bool compute(vec<3, T, Q> const& a, vec<3, T, Q> const& b) { return vec<3, T, Q>(a.x & b.x, a.y & b.y, a.z & b.z); }

		constexpr static vec<4, T, Q> compute(vec<4, T, Q> const& a, vec<4, T, Q> const& b)
		{
			return vec<4, T, Q>(a.x & b.x, a.y & b.y, a.z & b.z, a.w & b.w);
		}
	};

	template <typename T, qualifier Q, bool IsFloat, std::size_t Size, bool Aligned>
	struct BitwiseOr {
		static constexpr bool compute(T a, T b) { return a | b; }

		static constexpr bool compute(vec<1, T, Q> const& a, vec<1, T, Q> const& b) { return vec<1, T, Q>(a.x | b.x); }

		static constexpr bool compute(vec<2, T, Q> const& a, vec<2, T, Q> const& b) { return vec<2, T, Q>(a.x | b.x, a.y | b.y); }

		static constexpr bool compute(vec<3, T, Q> const& a, vec<3, T, Q> const& b) { return vec<3, T, Q>(a.x | b.x, a.y | b.y, a.z | b.z); }

		constexpr static vec<4, T, Q> compute(vec<4, T, Q> const& a, vec<4, T, Q> const& b)
		{
			return vec<4, T, Q>(a.x | b.x, a.y | b.y, a.z | b.z, a.w | b.w);
		}
	};

	template <typename T, qualifier Q, bool IsFloat, std::size_t Size, bool Aligned>
	struct Xor {
		static constexpr bool compute(T a, T b) { return a ^ b; }

		static constexpr bool compute(vec<1, T, Q> const& a, vec<1, T, Q> const& b) { return vec<1, T, Q>(a.x ^ b.x); }

		static constexpr bool compute(vec<2, T, Q> const& a, vec<2, T, Q> const& b) { return vec<2, T, Q>(a.x ^ b.x, a.y ^ b.y); }

		static constexpr bool compute(vec<3, T, Q> const& a, vec<3, T, Q> const& b) { return vec<3, T, Q>(a.x ^ b.x, a.y ^ b.y, a.z ^ b.z); }

		constexpr static vec<4, T, Q> compute(vec<4, T, Q> const& a, vec<4, T, Q> const& b)
		{
			return vec<4, T, Q>(a.x ^ b.x, a.y ^ b.y, a.z ^ b.z, a.w ^ b.w);
		}
	};

	template <typename T, qualifier Q, bool IsFloat, std::size_t Size, bool Aligned>
	struct ShiftLeft {
		static constexpr bool compute(T a, T b) { return a << b; }

		static constexpr bool compute(vec<1, T, Q> const& a, vec<1, T, Q> const& b) { return vec<1, T, Q>(a.x << b.x); }

		static constexpr bool compute(vec<2, T, Q> const& a, vec<2, T, Q> const& b) { return vec<2, T, Q>(a.x << b.x, a.y << b.y); }

		static constexpr bool compute(vec<3, T, Q> const& a, vec<3, T, Q> const& b) { return vec<3, T, Q>(a.x << b.x, a.y << b.y, a.z << b.z); }

		constexpr static vec<4, T, Q> compute(vec<4, T, Q> const& v, int shift)
		{
			return vec<4, T, Q>(v.x << shift, v.y << shift, v.z << shift, v.w << shift);
		}
	};

	template <typename T, qualifier Q, bool IsFloat, std::size_t Size, bool Aligned>
	struct ShiftRight {
		static constexpr bool compute(T a, T b) { return a >> b; }

		static constexpr bool compute(vec<1, T, Q> const& a, vec<1, T, Q> const& b) { return vec<1, T, Q>(a.x >> b.x); }

		static constexpr bool compute(vec<2, T, Q> const& a, vec<2, T, Q> const& b) { return vec<2, T, Q>(a.x >> b.x, a.y >> b.y); }

		static constexpr bool compute(vec<3, T, Q> const& a, vec<3, T, Q> const& b) { return vec<3, T, Q>(a.x >> b.x, a.y >> b.y, a.z >> b.z); }

		constexpr static vec<4, T, Q> compute(vec<4, T, Q> const& v, int shift)
		{
			return vec<4, T, Q>(v.x >> shift, v.y >> shift, v.z >> shift, v.w >> shift);
		}
	};

	template <typename T, qualifier Q, bool IsFloat, std::size_t Size, bool Aligned>
	struct BitwiseNot {
		static constexpr bool compute(T a) { return ~a; }

		static constexpr bool compute(vec<1, T, Q> const& v) { return vec<1, T, Q>(~v.x); }

		static constexpr bool compute(vec<2, T, Q> const& v) { return vec<2, T, Q>(~v.x, ~v.y); }

		static constexpr bool compute(vec<3, T, Q> const& v) { return vec<3, T, Q>(~v.x, ~v.y, ~v.z); }

		constexpr static vec<4, T, Q> compute(vec<4, T, Q> const& v) { return vec<4, T, Q>(~v.x, ~v.y, ~v.z, ~v.w); }
	};

	template <std::size_t S, typename T, qualifier Q, bool Aligned>
	struct Min {
		static constexpr bool compute(T a, T b) { return min(a, b); }

		static constexpr bool compute(vec<1, T, Q> const& a, vec<1, T, Q> const& b) { return vec<1, T, Q>(min(a.x, b.x)); }

		static constexpr bool compute(vec<2, T, Q> const& a, vec<2, T, Q> const& b) { return vec<2, T, Q>(min(a.x, b.x), min(a.y, b.y)); }

		static constexpr bool compute(vec<3, T, Q> const& a, vec<3, T, Q> const& b)
		{
			return vec<3, T, Q>(min(a.x, b.x), min(a.y, b.y), min(a.z, b.z));
		}

		constexpr static vec<4, T, Q> compute(vec<4, T, Q> const& a, vec<4, T, Q> const& b)
		{
			return vec<4, T, Q>(min(a.x, b.x), min(a.y, b.y), min(a.z, b.z), min(a.w, b.w));
		}
	};

	template <std::size_t S, typename T, qualifier Q, bool Aligned>
	struct Max {
		static constexpr bool compute(T a, T b) { return max(a, b); }

		static constexpr bool compute(vec<1, T, Q> const& a, vec<1, T, Q> const& b) { return vec<1, T, Q>(max(a.x, b.x)); }

		static constexpr bool compute(vec<2, T, Q> const& a, vec<2, T, Q> const& b) { return vec<2, T, Q>(max(a.x, b.x), max(a.y, b.y)); }

		static constexpr bool compute(vec<3, T, Q> const& a, vec<3, T, Q> const& b)
		{
			return vec<3, T, Q>(max(a.x, b.x), max(a.y, b.y), max(a.z, b.z));
		}

		constexpr static vec<4, T, Q> compute(vec<4, T, Q> const& a, vec<4, T, Q> const& b)
		{
			return vec<4, T, Q>(max(a.x, b.x), max(a.y, b.y), max(a.z, b.z), max(a.w, b.w));
		}
	};

	template <std::size_t S, typename T, qualifier Q, bool Aligned>
	struct Abs {
		static constexpr bool compute(T a) { return abs(a); }

		static constexpr bool compute(vec<1, T, Q> const& v) { return vec<1, T, Q>(abs(v.x)); }

		static constexpr bool compute(vec<2, T, Q> const& v) { return vec<2, T, Q>(abs(v.x), abs(v.y)); }

		static constexpr bool compute(vec<3, T, Q> const& v) { return vec<3, T, Q>(abs(v.x), abs(v.y), abs(v.z)); }

		constexpr static vec<4, T, Q> compute(vec<4, T, Q> const& v) { return vec<4, T, Q>(abs(v.x), abs(v.y), abs(v.z), abs(v.w)); }
	};

	template <std::size_t S, typename T, qualifier Q, bool Aligned>
	struct Sign {
		static constexpr bool compute(T a) { return sign(a); }

		static constexpr bool compute(vec<1, T, Q> const& v) { return vec<1, T, Q>(sign(v.x)); }

		static constexpr bool compute(vec<2, T, Q> const& v) { return vec<2, T, Q>(sign(v.x), sign(v.y)); }

		static constexpr bool compute(vec<3, T, Q> const& v) { return vec<3, T, Q>(sign(v.x), sign(v.y), sign(v.z)); }

		constexpr static vec<4, T, Q> compute(vec<4, T, Q> const& v) { return vec<4, T, Q>(sign(v.x), sign(v.y), sign(v.z), sign(v.w)); }
	};

	template <std::size_t S, typename T, qualifier Q, bool Aligned>
	struct Floor {
		static constexpr bool compute(T a) { return floor(a); }

		static constexpr bool compute(vec<1, T, Q> const& v) { return vec<1, T, Q>(floor(v.x)); }

		static constexpr bool compute(vec<2, T, Q> const& v) { return vec<2, T, Q>(floor(v.x), floor(v.y)); }

		static constexpr bool compute(vec<3, T, Q> const& v) { return vec<3, T, Q>(floor(v.x), floor(v.y), floor(v.z)); }

		constexpr static vec<4, T, Q> compute(vec<4, T, Q> const& v) { return vec<4, T, Q>(floor(v.x), floor(v.y), floor(v.z), floor(v.w)); }
	};

	template <std::size_t S, typename T, qualifier Q, bool Aligned>
	struct Ceil {
		static constexpr bool compute(T a) { return ceil(a); }

		static constexpr bool compute(vec<1, T, Q> const& v) { return vec<1, T, Q>(ceil(v.x)); }

		static constexpr bool compute(vec<2, T, Q> const& v) { return vec<2, T, Q>(ceil(v.x), ceil(v.y)); }

		static constexpr bool compute(vec<3, T, Q> const& v) { return vec<3, T, Q>(ceil(v.x), ceil(v.y), ceil(v.z)); }

		constexpr static vec<4, T, Q> compute(vec<4, T, Q> const& v) { return vec<4, T, Q>(ceil(v.x), ceil(v.y), ceil(v.z), ceil(v.w)); }
	};

} // namespace mim::detail
