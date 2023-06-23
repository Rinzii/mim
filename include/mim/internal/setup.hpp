// Copyright (c) 2023-Present Mim contributors (see LICENSE.txt)

#pragma once

#include <cstdint>

// System Detection
#include "mim/internal/config/architecture.hpp"
#include "mim/internal/config/compiler_traits.hpp"
#include "mim/internal/config/platform.hpp"

// Active states
#define MIM_DISABLE 0
#define MIM_ENABLE 1

namespace mim::detail
{
	using u8 = std::uint8_t;
	using i8 = std::int8_t;
	using u16 = std::uint16_t;
	using i16 = std::int16_t;
	using u32 = std::uint32_t;
	using i32 = std::int32_t;
	using u64 = std::uint64_t;
	using i64 = std::int64_t;
} // namespace mim::detail

#if defined(MIM_SIMD)
	#define MIM_SIMD MIM_ENABLE
#else
	#define MIM_SIMD MIM_DISABLE
#endif
