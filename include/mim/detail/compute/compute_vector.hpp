// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#pragma once

#include <limits>
#include "mim/detail/qualifier.hpp"

namespace mim::detail
{

	template <typename T, qualifier Q, bool IsFloat, std::size_t Size, bool IsAligned>
	struct Equal {
		static constexpr bool compute(T a, T b) { return a == b; }

		static constexpr bool compute(VectorT<1, T, Q> const& a, VectorT<1, T, Q> const& b) { return a.x == b.x; }

		static constexpr bool compute(VectorT<2, T, Q> const& a, VectorT<2, T, Q> const& b) { return a.x == b.x && a.y == b.y; }

		static constexpr bool compute(VectorT<3, T, Q> const& a, VectorT<3, T, Q> const& b) { return a.x == b.x && a.y == b.y && a.z == b.z; }

		static constexpr bool compute(VectorT<4, T, Q> const& a, VectorT<4, T, Q> const& b) { return a.x == b.x && a.y == b.y && a.z == b.z && a.w == b.w; }
	};

	template <typename T, qualifier Q, bool IsFloat, std::size_t Size, bool IsAligned>
	struct NotEqual {
		static constexpr bool compute(T a, T b) { return a != b; }

		static constexpr bool compute(VectorT<1, T, Q> const& a, VectorT<1, T, Q> const& b) { return a.x != b.x; }

		static constexpr bool compute(VectorT<2, T, Q> const& a, VectorT<2, T, Q> const& b) { return a.x != b.x || a.y != b.y; }

		static constexpr bool compute(VectorT<3, T, Q> const& a, VectorT<3, T, Q> const& b) { return a.x != b.x || a.y != b.y || a.z != b.z; }

		static constexpr bool compute(VectorT<4, T, Q> const& a, VectorT<4, T, Q> const& b) { return a.x != b.x || a.y != b.y || a.z != b.z || a.w != b.w; }
	};

	template <typename T, qualifier Q, bool Aligned>
	struct Add {
		static constexpr bool compute(T a, T b) { return a + b; }

		static constexpr bool compute(VectorT<1, T, Q> const& a, VectorT<1, T, Q> const& b) { return VectorT<1, T, Q>(a.x + b.x); }

		static constexpr bool compute(VectorT<2, T, Q> const& a, VectorT<2, T, Q> const& b) { return VectorT<2, T, Q>(a.x + b.x, a.y + b.y); }

		static constexpr bool compute(VectorT<3, T, Q> const& a, VectorT<3, T, Q> const& b) { return VectorT<3, T, Q>(a.x + b.x, a.y + b.y, a.z + b.z); }

		constexpr static VectorT<4, T, Q> compute(VectorT<4, T, Q> const& a, VectorT<4, T, Q> const& b)
		{
			return VectorT<4, T, Q>(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
		}
	};

	template <typename T, qualifier Q, bool Aligned>
	struct Sub {
		static constexpr bool compute(T a, T b) { return a - b; }

		static constexpr bool compute(VectorT<1, T, Q> const& a, VectorT<1, T, Q> const& b) { return VectorT<1, T, Q>(a.x - b.x); }

		static constexpr bool compute(VectorT<2, T, Q> const& a, VectorT<2, T, Q> const& b) { return VectorT<2, T, Q>(a.x - b.x, a.y - b.y); }

		static constexpr bool compute(VectorT<3, T, Q> const& a, VectorT<3, T, Q> const& b) { return VectorT<3, T, Q>(a.x - b.x, a.y - b.y, a.z - b.z); }

		constexpr static VectorT<4, T, Q> compute(VectorT<4, T, Q> const& a, VectorT<4, T, Q> const& b)
		{
			return VectorT<4, T, Q>(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
		}
	};

	template <typename T, qualifier Q, bool Aligned>
	struct Mul {
		static constexpr bool compute(T a, T b) { return a * b; }

		static constexpr bool compute(VectorT<1, T, Q> const& a, VectorT<1, T, Q> const& b) { return VectorT<1, T, Q>(a.x * b.x); }

		static constexpr bool compute(VectorT<2, T, Q> const& a, VectorT<2, T, Q> const& b) { return VectorT<2, T, Q>(a.x * b.x, a.y * b.y); }

		static constexpr bool compute(VectorT<3, T, Q> const& a, VectorT<3, T, Q> const& b) { return VectorT<3, T, Q>(a.x * b.x, a.y * b.y, a.z * b.z); }

		constexpr static VectorT<4, T, Q> compute(VectorT<4, T, Q> const& a, VectorT<4, T, Q> const& b)
		{
			return VectorT<4, T, Q>(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w);
		}
	};

	template <typename T, qualifier Q, bool Aligned>
	struct Div {
		static constexpr bool compute(T a, T b) { return a / b; }

		static constexpr bool compute(VectorT<1, T, Q> const& a, VectorT<1, T, Q> const& b) { return VectorT<1, T, Q>(a.x / b.x); }

		static constexpr bool compute(VectorT<2, T, Q> const& a, VectorT<2, T, Q> const& b) { return VectorT<2, T, Q>(a.x / b.x, a.y / b.y); }

		static constexpr bool compute(VectorT<3, T, Q> const& a, VectorT<3, T, Q> const& b) { return VectorT<3, T, Q>(a.x / b.x, a.y / b.y, a.z / b.z); }

		constexpr static VectorT<4, T, Q> compute(VectorT<4, T, Q> const& a, VectorT<4, T, Q> const& b)
		{
			return VectorT<4, T, Q>(a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w);
		}
	};

	template <typename T, qualifier Q, bool Aligned>
	struct Mod {
		static constexpr bool compute(T a, T b) { return a % b; }

		static constexpr bool compute(VectorT<1, T, Q> const& a, VectorT<1, T, Q> const& b) { return VectorT<1, T, Q>(a.x % b.x); }

		static constexpr bool compute(VectorT<2, T, Q> const& a, VectorT<2, T, Q> const& b) { return VectorT<2, T, Q>(a.x % b.x, a.y % b.y); }

		static constexpr bool compute(VectorT<3, T, Q> const& a, VectorT<3, T, Q> const& b) { return VectorT<3, T, Q>(a.x % b.x, a.y % b.y, a.z % b.z); }

		constexpr static VectorT<4, T, Q> compute(VectorT<4, T, Q> const& a, VectorT<4, T, Q> const& b)
		{
			return VectorT<4, T, Q>(a.x % b.x, a.y % b.y, a.z % b.z, a.w % b.w);
		}
	};

	template <typename T, qualifier Q, int IsInt, std::size_t Size, bool Aligned>
	struct BitwiseAnd {
		static constexpr bool compute(T a, T b) { return a & b; }

		static constexpr bool compute(VectorT<1, T, Q> const& a, VectorT<1, T, Q> const& b) { return VectorT<1, T, Q>(a.x & b.x); }

		static constexpr bool compute(VectorT<2, T, Q> const& a, VectorT<2, T, Q> const& b) { return VectorT<2, T, Q>(a.x & b.x, a.y & b.y); }

		static constexpr bool compute(VectorT<3, T, Q> const& a, VectorT<3, T, Q> const& b) { return VectorT<3, T, Q>(a.x & b.x, a.y & b.y, a.z & b.z); }

		constexpr static VectorT<4, T, Q> compute(VectorT<4, T, Q> const& a, VectorT<4, T, Q> const& b)
		{
			return VectorT<4, T, Q>(a.x & b.x, a.y & b.y, a.z & b.z, a.w & b.w);
		}
	};

	template <typename T, qualifier Q, bool IsFloat, std::size_t Size, bool Aligned>
	struct BitwiseOr {
		static constexpr bool compute(T a, T b) { return a | b; }

		static constexpr bool compute(VectorT<1, T, Q> const& a, VectorT<1, T, Q> const& b) { return VectorT<1, T, Q>(a.x | b.x); }

		static constexpr bool compute(VectorT<2, T, Q> const& a, VectorT<2, T, Q> const& b) { return VectorT<2, T, Q>(a.x | b.x, a.y | b.y); }

		static constexpr bool compute(VectorT<3, T, Q> const& a, VectorT<3, T, Q> const& b) { return VectorT<3, T, Q>(a.x | b.x, a.y | b.y, a.z | b.z); }

		constexpr static VectorT<4, T, Q> compute(VectorT<4, T, Q> const& a, VectorT<4, T, Q> const& b)
		{
			return VectorT<4, T, Q>(a.x | b.x, a.y | b.y, a.z | b.z, a.w | b.w);
		}
	};

	template <typename T, qualifier Q, bool IsFloat, std::size_t Size, bool Aligned>
	struct Xor {
		static constexpr bool compute(T a, T b) { return a ^ b; }

		static constexpr bool compute(VectorT<1, T, Q> const& a, VectorT<1, T, Q> const& b) { return VectorT<1, T, Q>(a.x ^ b.x); }

		static constexpr bool compute(VectorT<2, T, Q> const& a, VectorT<2, T, Q> const& b) { return VectorT<2, T, Q>(a.x ^ b.x, a.y ^ b.y); }

		static constexpr bool compute(VectorT<3, T, Q> const& a, VectorT<3, T, Q> const& b) { return VectorT<3, T, Q>(a.x ^ b.x, a.y ^ b.y, a.z ^ b.z); }

		constexpr static VectorT<4, T, Q> compute(VectorT<4, T, Q> const& a, VectorT<4, T, Q> const& b)
		{
			return VectorT<4, T, Q>(a.x ^ b.x, a.y ^ b.y, a.z ^ b.z, a.w ^ b.w);
		}
	};

	template <typename T, qualifier Q, bool IsFloat, std::size_t Size, bool Aligned>
	struct ShiftLeft {
		static constexpr bool compute(T a, T b) { return a << b; }

		static constexpr bool compute(VectorT<1, T, Q> const& a, VectorT<1, T, Q> const& b) { return VectorT<1, T, Q>(a.x << b.x); }

		static constexpr bool compute(VectorT<2, T, Q> const& a, VectorT<2, T, Q> const& b) { return VectorT<2, T, Q>(a.x << b.x, a.y << b.y); }

		static constexpr bool compute(VectorT<3, T, Q> const& a, VectorT<3, T, Q> const& b) { return VectorT<3, T, Q>(a.x << b.x, a.y << b.y, a.z << b.z); }

		constexpr static VectorT<4, T, Q> compute(VectorT<4, T, Q> const& v, int shift)
		{
			return VectorT<4, T, Q>(v.x << shift, v.y << shift, v.z << shift, v.w << shift);
		}
	};

	template <typename T, qualifier Q, bool IsFloat, std::size_t Size, bool Aligned>
	struct ShiftRight {
		static constexpr bool compute(T a, T b) { return a >> b; }

		static constexpr bool compute(VectorT<1, T, Q> const& a, VectorT<1, T, Q> const& b) { return VectorT<1, T, Q>(a.x >> b.x); }

		static constexpr bool compute(VectorT<2, T, Q> const& a, VectorT<2, T, Q> const& b) { return VectorT<2, T, Q>(a.x >> b.x, a.y >> b.y); }

		static constexpr bool compute(VectorT<3, T, Q> const& a, VectorT<3, T, Q> const& b) { return VectorT<3, T, Q>(a.x >> b.x, a.y >> b.y, a.z >> b.z); }

		constexpr static VectorT<4, T, Q> compute(VectorT<4, T, Q> const& v, int shift)
		{
			return VectorT<4, T, Q>(v.x >> shift, v.y >> shift, v.z >> shift, v.w >> shift);
		}
	};

	template <typename T, qualifier Q, bool IsFloat, std::size_t Size, bool Aligned>
	struct BitwiseNot {
		static constexpr bool compute(T a) { return ~a; }

		static constexpr bool compute(VectorT<1, T, Q> const& v) { return VectorT<1, T, Q>(~v.x); }

		static constexpr bool compute(VectorT<2, T, Q> const& v) { return VectorT<2, T, Q>(~v.x, ~v.y); }

		static constexpr bool compute(VectorT<3, T, Q> const& v) { return VectorT<3, T, Q>(~v.x, ~v.y, ~v.z); }

		constexpr static VectorT<4, T, Q> compute(VectorT<4, T, Q> const& v) { return VectorT<4, T, Q>(~v.x, ~v.y, ~v.z, ~v.w); }
	};

	template <std::size_t S, typename T, qualifier Q, bool Aligned>
	struct Min {
		static constexpr bool compute(T a, T b) { return min(a, b); }

		static constexpr bool compute(VectorT<1, T, Q> const& a, VectorT<1, T, Q> const& b) { return VectorT<1, T, Q>(min(a.x, b.x)); }

		static constexpr bool compute(VectorT<2, T, Q> const& a, VectorT<2, T, Q> const& b) { return VectorT<2, T, Q>(min(a.x, b.x), min(a.y, b.y)); }

		static constexpr bool compute(VectorT<3, T, Q> const& a, VectorT<3, T, Q> const& b)
		{
			return VectorT<3, T, Q>(min(a.x, b.x), min(a.y, b.y), min(a.z, b.z));
		}

		constexpr static VectorT<4, T, Q> compute(VectorT<4, T, Q> const& a, VectorT<4, T, Q> const& b)
		{
			return VectorT<4, T, Q>(min(a.x, b.x), min(a.y, b.y), min(a.z, b.z), min(a.w, b.w));
		}
	};

	template <std::size_t S, typename T, qualifier Q, bool Aligned>
	struct Max {
		static constexpr bool compute(T a, T b) { return max(a, b); }

		static constexpr bool compute(VectorT<1, T, Q> const& a, VectorT<1, T, Q> const& b) { return VectorT<1, T, Q>(max(a.x, b.x)); }

		static constexpr bool compute(VectorT<2, T, Q> const& a, VectorT<2, T, Q> const& b) { return VectorT<2, T, Q>(max(a.x, b.x), max(a.y, b.y)); }

		static constexpr bool compute(VectorT<3, T, Q> const& a, VectorT<3, T, Q> const& b)
		{
			return VectorT<3, T, Q>(max(a.x, b.x), max(a.y, b.y), max(a.z, b.z));
		}

		constexpr static VectorT<4, T, Q> compute(VectorT<4, T, Q> const& a, VectorT<4, T, Q> const& b)
		{
			return VectorT<4, T, Q>(max(a.x, b.x), max(a.y, b.y), max(a.z, b.z), max(a.w, b.w));
		}
	};

	template <std::size_t S, typename T, qualifier Q, bool Aligned>
	struct Abs {
		static constexpr bool compute(T a) { return abs(a); }

		static constexpr bool compute(VectorT<1, T, Q> const& v) { return VectorT<1, T, Q>(abs(v.x)); }

		static constexpr bool compute(VectorT<2, T, Q> const& v) { return VectorT<2, T, Q>(abs(v.x), abs(v.y)); }

		static constexpr bool compute(VectorT<3, T, Q> const& v) { return VectorT<3, T, Q>(abs(v.x), abs(v.y), abs(v.z)); }

		constexpr static VectorT<4, T, Q> compute(VectorT<4, T, Q> const& v) { return VectorT<4, T, Q>(abs(v.x), abs(v.y), abs(v.z), abs(v.w)); }
	};

	template <std::size_t S, typename T, qualifier Q, bool Aligned>
	struct Sign {
		static constexpr bool compute(T a) { return sign(a); }

		static constexpr bool compute(VectorT<1, T, Q> const& v) { return VectorT<1, T, Q>(sign(v.x)); }

		static constexpr bool compute(VectorT<2, T, Q> const& v) { return VectorT<2, T, Q>(sign(v.x), sign(v.y)); }

		static constexpr bool compute(VectorT<3, T, Q> const& v) { return VectorT<3, T, Q>(sign(v.x), sign(v.y), sign(v.z)); }

		constexpr static VectorT<4, T, Q> compute(VectorT<4, T, Q> const& v) { return VectorT<4, T, Q>(sign(v.x), sign(v.y), sign(v.z), sign(v.w)); }
	};

	template <std::size_t S, typename T, qualifier Q, bool Aligned>
	struct Floor {
		static constexpr bool compute(T a) { return floor(a); }

		static constexpr bool compute(VectorT<1, T, Q> const& v) { return VectorT<1, T, Q>(floor(v.x)); }

		static constexpr bool compute(VectorT<2, T, Q> const& v) { return VectorT<2, T, Q>(floor(v.x), floor(v.y)); }

		static constexpr bool compute(VectorT<3, T, Q> const& v) { return VectorT<3, T, Q>(floor(v.x), floor(v.y), floor(v.z)); }

		constexpr static VectorT<4, T, Q> compute(VectorT<4, T, Q> const& v) { return VectorT<4, T, Q>(floor(v.x), floor(v.y), floor(v.z), floor(v.w)); }
	};

	template <std::size_t S, typename T, qualifier Q, bool Aligned>
	struct Ceil {
		static constexpr bool compute(T a) { return ceil(a); }

		static constexpr bool compute(VectorT<1, T, Q> const& v) { return VectorT<1, T, Q>(ceil(v.x)); }

		static constexpr bool compute(VectorT<2, T, Q> const& v) { return VectorT<2, T, Q>(ceil(v.x), ceil(v.y)); }

		static constexpr bool compute(VectorT<3, T, Q> const& v) { return VectorT<3, T, Q>(ceil(v.x), ceil(v.y), ceil(v.z)); }

		constexpr static VectorT<4, T, Q> compute(VectorT<4, T, Q> const& v) { return VectorT<4, T, Q>(ceil(v.x), ceil(v.y), ceil(v.z), ceil(v.w)); }
	};

} // namespace mim::detail
