// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#pragma once

#include <array>
//#include "mim/detail/defines.hpp"
#include "mim/detail/type/type_vector2.hpp"

namespace mim
{
	template <typename T>
	struct mat<3, 2, T> {
		using type = mat<3, 2, T>;
		using row_type = vec<3, T>;
		using column_type = vec<2, T>;
		using transpose_type = mat<3, 2, T>;
		using value_type = T;
		using size_type = std::size_t;
		static constexpr std::size_t column_size_v = 3;
		static constexpr std::size_t row_size_v = 2;
		static constexpr T size_v = vec<2, std::size_t>(column_size_v, row_size_v);

	private:
		using data = std::array<column_type, column_size_v>;

	public:
		static constexpr size_type size() { return size_v; }
		static constexpr size_type row_size() { return row_size_v; }
		static constexpr size_type column_size() { return column_size_v; }

		constexpr column_type& operator[](size_type i) noexcept;
		constexpr column_type const& operator[](size_type i) const noexcept;

		constexpr row_type row(size_type i) const noexcept;
		constexpr column_type column(size_type i) const noexcept;
		// constexpr column_type at(size_type i, size_type j) const noexcept;
	};
} // namespace mim
