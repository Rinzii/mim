// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#pragma once

#include <array>
#include "mim/detail/defines.hpp"

namespace mim
{
	template <typename T>
	struct mat<4, 3, T> {
		using type = mat<4, 3, T>;
		using row_type = vec<4, T>;
		using column_type = vec<3, T>;
		using transpose_type = mat<4, 3, T>;
		using value_type = T;
		using size_type = std::size_t;
		static constexpr std::size_t column_size_v = 4;
		static constexpr std::size_t row_size_v = 3;

	private:
		using data = std::array<column_type, column_size_v>;

	public:
		static constexpr size_type size() { return 4; }
		static constexpr size_type row_size() { return row_size_v; }
		static constexpr size_type column_size() { return column_size_v; }

		constexpr column_type& operator[](size_type i) noexcept;
		constexpr column_type const& operator[](size_type i) const noexcept;

		constexpr row_type row(size_type i) const noexcept;
		constexpr column_type column(size_type i) const noexcept;
		constexpr column_type at(size_type i, size_type j) const noexcept;

		constexpr mat() noexcept;
		explicit constexpr mat(T const& val) noexcept;
		constexpr mat(
			T const& x0, T const& y0, T const& z0,
            T const& x1, T const& y1, T const& z1,
            T const& x2, T const& y2, T const& z2,
            T const& x3, T const& y3, T const& z3);
		constexpr mat(
			column_type const& v0,
			column_type const& v1,
			column_type const& v2,
			column_type const& v3);

		/// General conversions


		template <
		        typename X1, typename Y1, typename Z1,
			    typename X2, typename Y2, typename Z2,
                typename X3, typename Y3, typename Z3,
                typename X4, typename Y4, typename Z4>
        constexpr mat(
			X1 const& x1, Y1 const& y1, Z1 const& z1,
            X2 const& x2, Y2 const& y2, Z2 const& z2,
            X3 const& x3, Y3 const& y3, Z3 const& z3,
            X4 const& x4, Y4 const& y4, Z4 const& z4);

		template <typename V1, typename V2, typename V3, typename V4>
		constexpr mat(
            vec<3, V1> const& v1,
            vec<3, V2> const& v2,
            vec<3, V3> const& v3,
            vec<3, V4> const& v4);


		/// Matrix conversions

		explicit constexpr mat(mat<2, 2, T> const& m);
        explicit constexpr mat(mat<3, 3, T> const& m);
		explicit constexpr mat(mat<4, 4, T> const& m);
		explicit constexpr mat(mat<2, 3, T> const& m);
		explicit constexpr mat(mat<3, 2, T> const& m);
		explicit constexpr mat(mat<2, 4, T> const& m);
		explicit constexpr mat(mat<4, 2, T> const& m);
		explicit constexpr mat(mat<3, 4, T> const& m);

		template <typename U>
		explicit constexpr mat(mat<4, 3, U> const& m);


		/// Arithmetic operators

		template <typename U>
		mat<4, 3, T> & operator = (mat<4, 3, U> const& m);
		template <typename U>
		mat<4, 3, T> & operator += (U const& s);
		template <typename U>
		mat<4, 3, T> & operator += (mat<4, 3, U> const& m);
		template <typename U>
		mat<4, 3, T> & operator -= (U const& s);
		template <typename U>
		mat<4, 3, T> & operator -= (mat<4, 3, U> const& m);
		template <typename U>
		mat<4, 3, T> & operator *= (U const& s);
		template <typename U>
		mat<4, 3, T> & operator /= (U const& s);


		/// Increment and decrement operators

		mat<4, 3, T> & operator ++ ();
		mat<4, 3, T> & operator -- ();
		mat<4, 3, T> operator ++ (int);
		mat<4, 3, T> operator -- (int);

	};

	/// Unary operators

    template <typename T>
    mat<4, 3, T> operator + (mat<4, 3, T> const& m);

	template <typename T>
	mat<4, 3, T> operator - (mat<4, 3, T> const& m);


	/// Binary operators

	template <typename T>
	mat<4, 3, T> operator + (mat<4, 3, T> const& m, T const& s);

	template <typename T>
	mat<4, 3, T> operator + (mat<4, 3, T> const& m1, mat<4, 3, T> const& m2);

	template <typename T>
	mat<4, 3, T> operator - (mat<4, 3, T> const& m, T const& s);

	template <typename T>
	mat<4, 3, T> operator - (mat<4, 3, T> const& m1, mat<4, 3, T> const& m2);

	template <typename T>
	mat<4, 3, T> operator * (mat<4, 3, T> const& m, T const& s);

	template <typename T>
	mat<4, 3, T> operator * (T const& s, mat<4, 3, T> const& m);

	template <typename T>
	typename mat<4, 3, T>::col_type operator * (mat<4, 3, T> const& m, typename mat<4, 3, T>::row_type const& v);

	template <typename T>
	typename mat<4, 3, T>::row_type operator * (typename mat<4, 3, T>::col_type const& v, mat<4, 3, T> const& m);



} // namespace mim
