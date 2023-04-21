#pragma once

#include <array>
#include <cassert>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <numeric>

template <std::size_t Dim, typename T>
struct VectorT
{
    std::array<T, Dim> m_data;

    using value_type = T;
    using iterator = typename std::array<T, Dim>::iterator;
    using const_iterator = typename std::array<T, Dim>::const_iterator;
    static constexpr std::size_t size_v = Dim;

    static constexpr std::size_t size() noexcept { return size_v; }

    VectorT() noexcept = default;

    explicit VectorT(T value) noexcept
        : m_data{} // zero-initialize the array
    {
        m_data.fill(value);
    }

    VectorT(std::initializer_list<T> list) noexcept
    {
        assert(list.size() == Dim);
        std::copy(list.begin(), list.end(), m_data.begin());
    }

    T& operator[](std::size_t index) noexcept { return m_data[index]; }

    const T& operator[](std::size_t index) const noexcept { return m_data[index]; }

    VectorT& operator+=(const VectorT& other) noexcept
    {
        std::transform(m_data.begin(), m_data.end(), other.m_data.begin(), m_data.begin(), std::plus<T>{});
        return *this;
    }

    VectorT& operator-=(const VectorT& other) noexcept
    {
        std::transform(m_data.begin(), m_data.end(), other.m_data.begin(), m_data.begin(), std::minus<T>{});
        return *this;
    }

    VectorT& operator*=(T scalar) noexcept
    {
        std::transform(m_data.begin(), m_data.end(), m_data.begin(), [scalar](T& x) { return x * scalar; });
        return *this;
    }

    VectorT& operator/=(T scalar)
    {
        assert(scalar != 0);
        std::transform(m_data.begin(), m_data.end(), m_data.begin(), [scalar](T& x) { return x / scalar; });
        return *this;
    }

    friend VectorT operator+(VectorT lhs, const VectorT& rhs) noexcept { return lhs += rhs; }

    friend VectorT operator-(VectorT lhs, const VectorT& rhs) noexcept { return lhs -= rhs; }

    friend VectorT operator*(VectorT lhs, T scalar) noexcept { return lhs *= scalar; }

    friend VectorT operator*(T scalar, VectorT rhs) noexcept { return rhs *= scalar; }

    friend VectorT operator/(VectorT lhs, T scalar) { return lhs /= scalar; }

    T dot(const VectorT& other) const noexcept
    {
        return std::inner_product(m_data.begin(), m_data.end(), other.m_data.begin(), static_cast<T>(0));
    }

    T length_squared() const noexcept { return dot(*this); }

    T length() const noexcept { return std::sqrt(length_squared()); }

    VectorT normalized() const noexcept
    {
        assert(length() != 0);
        return *this / length();
    }

    iterator begin() noexcept { return m_data.begin(); }

    iterator end() noexcept { return m_data.end(); }

    const_iterator begin() const noexcept { return m_data.cbegin(); }

    const_iterator end() const noexcept { return m_data.cend(); }

    const_iterator cbegin() const noexcept { return m_data.cbegin(); }

    const_iterator cend() const noexcept { return m_data.cend(); }

    friend std::ostream& operator<<(std::ostream& os, const VectorT& v) noexcept
    {
        os << "[ ";
        for (const auto& x : v.m_data)
		{
			os << x << " ";
		}
		os << "]";
		return os;
	}
};
