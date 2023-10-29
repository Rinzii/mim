// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#pragma once

#include "mim/detail/defines.hpp"

namespace mim::detail
{
	template <template <std::size_t S, typename T> class VectorT, std::size_t S, typename R, typename T>
	struct functor1 {
	};

	template <template <std::size_t S, typename T> class VectorT, typename R, typename T>
	struct functor1<VectorT, 1, R, T> {
		constexpr static VectorT<1, R> compute(R (*Func)(T x), VectorT<1, T> const& v) { return VectorT<1, R>(Func(v.x)); }
	};

	template <template <std::size_t S, typename T> class VectorT, typename R, typename T>
	struct functor1<VectorT, 2, R, T> {
		constexpr static VectorT<2, R> compute(R (*Func)(T x), VectorT<2, T> const& v) { return VectorT<2, R>(Func(v.x), Func(v.y)); }
	};

	template <template <std::size_t S, typename T> class VectorT, typename R, typename T>
	struct functor1<VectorT, 3, R, T> {
		constexpr static VectorT<3, R> compute(R (*Func)(T x), VectorT<3, T> const& v) { return VectorT<3, R>(Func(v.x), Func(v.y), Func(v.z)); }
	};

	template <template <std::size_t S, typename T> class VectorT, typename R, typename T>
	struct functor1<VectorT, 4, R, T> {
		constexpr static VectorT<4, R> compute(R (*Func)(T x), VectorT<4, T> const& v)
		{
			return VectorT<4, R>(Func(v.x), Func(v.y), Func(v.z), Func(v.w));
		}
	};

	template <template <std::size_t S, typename T> class VectorT, std::size_t S, typename R, typename T>
	struct functor2 {
	};

	template <template <std::size_t S, typename T> class VectorT, typename R, typename T>
	struct functor2<VectorT, 1, R, T> {
		constexpr static R compute(R (*Func)(T x, T y), VectorT<1, T> const& v1, VectorT<1, T> const& v2) { return Func(v1.x, v2.x); }
	};

	template <template <std::size_t S, typename T> class VectorT, typename R, typename T>
	struct functor2<VectorT, 2, R, T> {
		constexpr static VectorT<2, R> compute(R (*Func)(T x, T y), VectorT<2, T> const& v1, VectorT<2, T> const& v2)
		{
			return VectorT<2, R>(Func(v1.x, v2.x), Func(v1.y, v2.y));
		}
	};

	template <template <std::size_t S, typename T> class VectorT, typename R, typename T>
	struct functor2<VectorT, 3, R, T> {
		constexpr static VectorT<3, R> compute(R (*Func)(T x, T y), VectorT<3, T> const& v1, VectorT<3, T> const& v2)
		{
			return VectorT<3, R>(Func(v1.x, v2.x), Func(v1.y, v2.y), Func(v1.z, v2.z));
		}
	};

	template <template <std::size_t S, typename T> class VectorT, typename R, typename T>
	struct functor2<VectorT, 4, R, T> {
		constexpr static VectorT<4, R> compute(R (*Func)(T x, T y), VectorT<4, T> const& v1, VectorT<4, T> const& v2)
		{
			return VectorT<4, R>(Func(v1.x, v2.x), Func(v1.y, v2.y), Func(v1.z, v2.z), Func(v1.w, v2.w));
		}
	};

} // namespace mim::detail
