// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#pragma once

#include "mim/detail/qualifier.hpp"
#include "mim/detail/compute/compute_quaternion.hpp"

namespace mim
{
	template <typename T, qualifier Q>
	struct Quaternion {
		using value_type = T;
		using type = Quaternion<T, Q>;
		using size_type = size_t;

		static constexpr auto sizeV = 4;

		T w, x, y, z;

		static constexpr auto size() { return sizeV; }

		constexpr T& operator[](size_type i)
		{
			static_assert(i < size(), "Out of range: Quaternion::operator[]");

			return (&w)[i];
		}

		constexpr T const& operator[](size_type i) const
		{
			static_assert(i < size(), "Out of range: Quaternion::operator[]");

			return (&w)[i];
		}

		constexpr T const& at(size_type i) const
        {
			static_assert(i < size(), "Out of range: Quaternion::at");

			return (&w)[i];

		}

		constexpr Quaternion();
		constexpr Quaternion(Quaternion const&);
		template <qualifier P>
		constexpr explicit Quaternion(Quaternion<T, P> const& q);

		constexpr Quaternion(T const& s, VectorT<3, T, Q> const& v);


		constexpr Quaternion(T const& w, T const& x, T const& y, T const& z);

		template <typename U, qualifier P>
		constexpr explicit Quaternion(Quaternion<U, P> const& q);

		explicit operator MatrixT<3, 3, T, Q>() const;
		explicit operator MatrixT<4, 4, T, Q>() const;

		Quaternion(VectorT<3, T, Q> const& a1, VectorT<3, T, Q> const& a2);

		constexpr explicit Quaternion(VectorT<3, T, Q> const& euler);

		/* TODO: Once matrix is implemented bring this back in.
		constexpr explicit Quaternion(MatrixT<3, 3, T, Q> const& m);
		constexpr explicit Quaternion(MatrixT<4, 4, T, Q> const& m);
		 */

		constexpr Quaternion<T, Q>& operator=(Quaternion<T, Q> const& q) = default;

		template <typename U>
		constexpr Quaternion<T, Q>& operator=(Quaternion<U, Q> const& q);

		template <typename U>
		constexpr Quaternion<T, Q>& operator+=(Quaternion<U, Q> const& q);

		template <typename U>
		constexpr Quaternion<T, Q>& operator-=(Quaternion<U, Q> const& q);

		template <typename U>
		constexpr Quaternion<T, Q>& operator*=(Quaternion<U, Q> const& r);

		template <typename U>
		constexpr Quaternion<T, Q>& operator*=(U const& scalar);

		template <typename U>
		constexpr Quaternion<T, Q>& operator/=(U const& scalar);

		MIM_NODISCARD constexpr bool isfinite() const;
		constexpr T length() const;
		constexpr void normalize();
		constexpr Quaternion<T, Q> normalized() const;
		MIM_NODISCARD constexpr bool is_normalized() const;
		constexpr Quaternion<T, Q> inverse() const;

		//VectorT<3, T, Q> get_euler() const;
	};

	template <typename T, qualifier Q>
	constexpr Quaternion<T, Q> operator+(Quaternion<T, Q> const& q);

	template <typename T, qualifier Q>
	constexpr Quaternion<T, Q> operator-(Quaternion<T, Q> const& q);

	template <typename T, qualifier Q>
	constexpr Quaternion<T, Q> operator+(Quaternion<T, Q> const& q1, Quaternion<T, Q> const& p);

	template <typename T, qualifier Q>
	constexpr Quaternion<T, Q> operator-(Quaternion<T, Q> const& q1, Quaternion<T, Q> const& p);

	template <typename T, qualifier Q>
	constexpr Quaternion<T, Q> operator*(Quaternion<T, Q> const& q1, Quaternion<T, Q> const& p);

	template <typename T, qualifier Q>
	constexpr Quaternion<T, Q> operator*(Quaternion<T, Q> const& q, VectorT<3, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr Quaternion<T, Q> operator*(VectorT<3, T, Q> const& v, Quaternion<T, Q> const& q);

	template <typename T, qualifier Q>
	constexpr Quaternion<T, Q> operator*(Quaternion<T, Q> const& q, VectorT<4, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr Quaternion<T, Q> operator*(VectorT<4, T, Q> const& v, Quaternion<T, Q> const& q);

	template <typename T, qualifier Q>
	constexpr Quaternion<T, Q> operator*(Quaternion<T, Q> const& q, T const& scalar);

	template <typename T, qualifier Q>
	constexpr Quaternion<T, Q> operator*(T const& scalar, Quaternion<T, Q> const& q);

	template <typename T, qualifier Q>
	constexpr Quaternion<T, Q> operator/(Quaternion<T, Q> const& q, T const& scalar);

	template <typename T, qualifier Q>
	constexpr bool operator==(Quaternion<T, Q> const& q1, Quaternion<T, Q> const& p);

	template <typename T, qualifier Q>
	constexpr bool operator!=(Quaternion<T, Q> const& q1, Quaternion<T, Q> const& p);

} // namespace mim

#include "mim/detail/type/type_quaternion.inl"
#include "mim/detail/func/func_quaternion.inl"
