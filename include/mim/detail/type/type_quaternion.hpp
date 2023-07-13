// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#pragma once

#include "mim/detail/qualifier.hpp"
#include "mim/detail/compute/compute_quaternion.hpp"

namespace mim
{
	template <typename T, qualifier Q>
	struct quat {
		using value_type = T;
		using type = quat<T, Q>;
		using size_type = size_t;

		static constexpr auto sizeV = 4;

		T w, x, y, z;

		static constexpr auto size() { return sizeV; }

		constexpr T& operator[](size_type i)
		{
			static_assert(i < size(), "Out of range: quat::operator[]");

			return (&w)[i];
		}

		constexpr T const& operator[](size_type i) const
		{
			static_assert(i < size(), "Out of range: quat::operator[]");

			return (&w)[i];
		}

		constexpr T const& at(size_type i) const
        {
			static_assert(i < size(), "Out of range: quat::at");

			return (&w)[i];

		}

		constexpr quat();
		constexpr quat(quat const&);
		template <qualifier P>
		constexpr explicit quat(quat<T, P> const& q);

		constexpr quat(T const& s, vec<3, T, Q> const& v);


		constexpr quat(T const& w, T const& x, T const& y, T const& z);

		template <typename U, qualifier P>
		constexpr explicit quat(quat<U, P> const& q);

		explicit operator mat<3, 3, T, Q>() const;
		explicit operator mat<4, 4, T, Q>() const;

		quat(vec<3, T, Q> const& a1, vec<3, T, Q> const& a2);

		constexpr explicit quat(vec<3, T, Q> const& euler);

		/* TODO: Once matrix is implemented bring this back in.
		constexpr explicit quat(mat<3, 3, T, Q> const& m);
		constexpr explicit quat(mat<4, 4, T, Q> const& m);
		 */

		constexpr quat<T, Q>& operator=(quat<T, Q> const& q) = default;

		template <typename U>
		constexpr quat<T, Q>& operator=(quat<U, Q> const& q);

		template <typename U>
		constexpr quat<T, Q>& operator+=(quat<U, Q> const& q);

		template <typename U>
		constexpr quat<T, Q>& operator-=(quat<U, Q> const& q);

		template <typename U>
		constexpr quat<T, Q>& operator*=(quat<U, Q> const& r);

		template <typename U>
		constexpr quat<T, Q>& operator*=(U const& scalar);

		template <typename U>
		constexpr quat<T, Q>& operator/=(U const& scalar);

		constexpr T length() const;
		constexpr void normalize();
		constexpr quat<T, Q> normalized() const;
		MIM_NODISCARD constexpr bool is_normalized() const;
		constexpr quat<T, Q> inverse() const;

		//vec<3, T, Q> get_euler() const;
	};

	template <typename T, qualifier Q>
	constexpr quat<T, Q> operator+(quat<T, Q> const& q);

	template <typename T, qualifier Q>
	constexpr quat<T, Q> operator-(quat<T, Q> const& q);

	template <typename T, qualifier Q>
	constexpr quat<T, Q> operator+(quat<T, Q> const& q1, quat<T, Q> const& p);

	template <typename T, qualifier Q>
	constexpr quat<T, Q> operator-(quat<T, Q> const& q1, quat<T, Q> const& p);

	template <typename T, qualifier Q>
	constexpr quat<T, Q> operator*(quat<T, Q> const& q1, quat<T, Q> const& p);

	template <typename T, qualifier Q>
	constexpr quat<T, Q> operator*(quat<T, Q> const& q, vec<3, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr quat<T, Q> operator*(vec<3, T, Q> const& v, quat<T, Q> const& q);

	template <typename T, qualifier Q>
	constexpr quat<T, Q> operator*(quat<T, Q> const& q, vec<4, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr quat<T, Q> operator*(vec<4, T, Q> const& v, quat<T, Q> const& q);

	template <typename T, qualifier Q>
	constexpr quat<T, Q> operator*(quat<T, Q> const& q, T const& scalar);

	template <typename T, qualifier Q>
	constexpr quat<T, Q> operator*(T const& scalar, quat<T, Q> const& q);

	template <typename T, qualifier Q>
	constexpr quat<T, Q> operator/(quat<T, Q> const& q, T const& scalar);

	template <typename T, qualifier Q>
	constexpr bool operator==(quat<T, Q> const& q1, quat<T, Q> const& p);

	template <typename T, qualifier Q>
	constexpr bool operator!=(quat<T, Q> const& q1, quat<T, Q> const& p);

} // namespace mim

#include "mim/detail/type/type_quaternion.inl"
#include "mim/detail/func/func_quaternion.inl"
