// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#pragma once

#include "mim/internal/setup.hpp"
#include "mim/simd/simdSetup.hpp"

#include <cstddef>

namespace mim
{

	enum qualifier {
		packed_highp,
		packed_mediump,
		packed_lowp,

#if defined(MIM_SIMD)
		aligned_highp,
		aligned_mediump,
		aligned_lowp,
		aligned = aligned_highp,
#endif

		highp = packed_highp,
		mediump = packed_mediump,
		lowp = packed_lowp,
		packed = packed_highp,

#if MIM_SIMD
		defaultp = aligned_highp,
#else
		defaultp = packed_highp,
#endif
	};

	using precision = qualifier;

	template <std::size_t S, typename T, qualifier Q = defaultp>
	struct VectorT;
	template <std::size_t C, std::size_t R, typename T, qualifier Q = defaultp>
	struct MatrixT;
	template <typename T, qualifier Q = defaultp>
	struct Quaternion;

	// TODO: Decide what to do with this
	// Currently I'm planning to move away from this more complex implementation
	// of storage handling and instead moving towards a simpler approach though I plan to keep this here for now
	// just in case I decided to go back to it/

	namespace detail
	{

		template <qualifier P>
		struct IsAligned {
			static const bool value = false;
		};
#if MIM_SIMD
		template <>
		struct IsAligned<aligned_highp> {
			static const bool value = true;
		};

		template <>
		struct IsAligned<aligned_mediump> {
			static const bool value = true;
		};

		template <>
		struct IsAligned<aligned_lowp> {
			static const bool value = true;
		};
#endif

		/*
		template <size_t S, typename T, bool is_aligned>
		struct Storage {
			using type = struct Type {
				T data[S];
			};
		};

		#if !defined(MIM_COMPILER_NO_ALIGNOF)
		template <size_t S, typename T>
		struct Storage<S, T, true> {
			using type = struct alignas(S * sizeof(T)) Type {
				T data[S];
			};
		};

		template <typename T>
		struct Storage<3, T, true> {
			using type = struct alignas(4 * sizeof(T)) Type {
				T data[4];
			};
		};
		#endif

		#if MIM_SIMD_SSE2

		template <>
		struct Storage<4, float, true> {
			using type = MIM_f32vec4;
		};

		template <>
		struct Storage<4, int32_t, true> {
			using type = MIM_i32vec4;
		};

		template <>
		struct Storage<4, uint32_t, true> {
			using type = MIM_u32vec4;
		};

		template <>
		struct Storage<2, double, true> {
			using type = MIM_f32vec2;
		};

		template <>
		struct Storage<2, int64_t, true> {
			using type = MIM_i64vec2;
		};

		template <>
		struct Storage<2, uint64_t, true> {
			using type = MIM_u64vec2;
		};
		#endif
		#if MIM_SIMD_AVX
		template <>
		struct Storage<4, double, true> {
			using type = MIM_f64vec4;
		};
		#endif
		#if MIM_SIMD_AVX2
		template <>
		struct Storage<4, int64_t, true> {
			using type = MIM_i64vec4;
		};

		template <>
		struct Storage<4, uint64_t, true> {
			using type = MIM_u64vec4;
		};
		#endif
		#if MIM_SIMD_NEON

		template <>
		struct Storage<4, float, true> {
			using type = MIM_f32vec4;
		};

		template <>
		struct Storage<4, int32_t, true> {
			using type = MIM_i32vec4;
		};

		template <>
		struct Storage<4, uint32_t, true> {
			using type = MIM_u32vec4;
		};
		#endif
		*/
	} // namespace detail
} // namespace mim
