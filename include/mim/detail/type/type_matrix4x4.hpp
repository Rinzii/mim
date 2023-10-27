// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#pragma once

#include <array>
#include "mim/detail/defines.hpp"

namespace mim
{
	template <typename T>
	struct mat<4, 4, T> {
		using Type = mat<4, 4, T>;
		using RowType = vec<4, T>;
		using ColumnType = vec<4, T>;
		using TransposeType = mat<4, 4, T>;
		using ValueType = T;
		using SizeType = std::size_t;
		static constexpr std::size_t RowSizeV = T{4};
		static constexpr std::size_t ColumnSizeV = T{4};
		static constexpr T SizeV = vec<2, std::size_t>(4);

	private:
		using Data = std::array<ColumnType, ColumnSizeV>;

	public:
		static constexpr SizeType size() { return SizeV; }
		static constexpr SizeType row_size() { return RowSizeV; }
		static constexpr SizeType column_size() { return ColumnSizeV; }
	};
} // namespace mim
