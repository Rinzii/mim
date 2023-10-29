// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#pragma once

#include "mim/detail/compute/compute_quaternion.hpp"
#include "mim/detail/defines.hpp"

namespace mim
{
	template <typename T>
	struct quat {
		using value_type = T;
		using type = quat<T>;
		using size_type = size_t;

		static constexpr auto sizeV = 4;

		T w, x, y, z;

		static constexpr auto size() { return sizeV; }

		constexpr T& operator[](const size_type i)
		{
			switch (i)
			{
			default: // TODO: Should we make this throw an exception as the default case?
			    case 0: return w;
				case 1: return x;
                case 2: return y;
				case 3: return z;
			}
		}

		constexpr T const& operator[](const size_type i) const
		{
			switch (i)
			{
			default: // TODO: Should we make this throw an exception as the default case?
			case 0: return w;
			case 1: return x;
			case 2: return y;
			case 3: return z;
			}
		}

		constexpr T const& at(const size_type i) const
        {
			switch (i)
			{
			default: // TODO: Should we make this throw an exception as the default case?
			case 0: return w;
			case 1: return x;
			case 2: return y;
			case 3: return z;
			}

		}

		constexpr quat();
		constexpr quat(quat const&);
		

		constexpr quat(T const& s, vec<3, T> const& v);


		constexpr quat(T const& w, T const& x, T const& y, T const& z);

		template <typename U>
		constexpr explicit quat(quat<U> const& q);

		explicit operator mat<3, 3, T>() const;
		explicit operator mat<4, 4, T>() const;

		quat(vec<3, T> const& a1, vec<3, T> const& a2);

		constexpr explicit quat(vec<3, T> const& euler);

		/* TODO: Once matrix is implemented bring this back in.
		constexpr explicit quat(mat<3, 3, T> const& m);
		constexpr explicit quat(mat<4, 4, T> const& m);
		 */

		constexpr quat<T>& operator=(quat<T> const& q) = default;

		template <typename U>
		constexpr quat<T>& operator=(quat<U> const& q);

		template <typename U>
		constexpr quat<T>& operator+=(quat<U> const& q);

		template <typename U>
		constexpr quat<T>& operator-=(quat<U> const& q);

		template <typename U>
		constexpr quat<T>& operator*=(quat<U> const& r);

		template <typename U>
		constexpr quat<T>& operator*=(U const& scalar);

		template <typename U>
		constexpr quat<T>& operator/=(U const& scalar);

		constexpr T length() const;
		constexpr void normalize();
		constexpr quat<T> normalized() const;
		MIM_NODISCARD constexpr bool is_normalized() const;
		constexpr quat<T> inverse() const;

		//vec<3, T> get_euler() const;
	};

	template <typename T>
	constexpr quat<T> operator+(quat<T> const& q);

	template <typename T>
	constexpr quat<T> operator-(quat<T> const& q);

	template <typename T>
	constexpr quat<T> operator+(quat<T> const& q1, quat<T> const& p);

	template <typename T>
	constexpr quat<T> operator-(quat<T> const& q1, quat<T> const& p);

	template <typename T>
	constexpr quat<T> operator*(quat<T> const& q1, quat<T> const& p);

	template <typename T>
	constexpr quat<T> operator*(quat<T> const& q, vec<3, T> const& v);

	template <typename T>
	constexpr quat<T> operator*(vec<3, T> const& v, quat<T> const& q);

	template <typename T>
	constexpr quat<T> operator*(quat<T> const& q, vec<4, T> const& v);

	template <typename T>
	constexpr quat<T> operator*(vec<4, T> const& v, quat<T> const& q);

	template <typename T>
	constexpr quat<T> operator*(quat<T> const& q, T const& scalar);

	template <typename T>
	constexpr quat<T> operator*(T const& scalar, quat<T> const& q);

	template <typename T>
	constexpr quat<T> operator/(quat<T> const& q, T const& scalar);

	template <typename T>
	constexpr bool operator==(quat<T> const& q1, quat<T> const& p);

	template <typename T>
	constexpr bool operator!=(quat<T> const& q1, quat<T> const& p);


	/// Free functions

	template <typename T>
	constexpr quat<T> normalize(quat<T> const& q);


} // namespace mim

#include "mim/detail/type/type_quaternion.inl"
#include "mim/detail/func/func_quaternion.inl"
