// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#pragma once

#include <array>
#include "mim/detail/qualifier.hpp"

namespace mim
{
	template <typename T, qualifier Q>
	struct MatrixT<4, 4, T, Q> {
		using Type = MatrixT<4, 4, T, Q>;
		using RowType = VectorT<4, T, Q>;
		using ColumnType = VectorT<4, T, Q>;
		using TransposeType = MatrixT<4, 4, T, Q>;
		using ValueType = T;
		using SizeType = std::size_t;
		static constexpr std::size_t RowSizeV = T{4};
		static constexpr std::size_t ColumnSizeV = T{4};
		static constexpr T SizeV = VectorT<2, std::size_t, Q>(4);

	private:
		using Data = std::array<ColumnType, ColumnSizeV>;

	public:
		static constexpr SizeType size() { return SizeV; }
		static constexpr SizeType row_size() { return RowSizeV; }
		static constexpr SizeType column_size() { return ColumnSizeV; }
	};
} // namespace mim
