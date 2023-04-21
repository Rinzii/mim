#pragma once

#include <array>
#include <cassert>
#include <cmath>
#include <iostream>

/**
 * \class vec
 * \brief A vector of dimension Dim and type T.
 * 
 * \tparam Dim The dimension of the vector.
 * \tparam T The type of the vector.
 * 
 * This is a simple vector class that provides generic vector operations.
 * It is not as efficent as our specialized vectors for floating point types.
 * It does provide a generic way to work with vectors of any dimension and type.
 * 
 * \note If you are working with floating point types, you should use the specialized vector#f (replace # with the dim) classes instead.
 * 
*/
template <std::size_t Dim, typename T>
struct vec
{
    std::array<T, Dim> m_data;

    using value_type = T;
    using iterator = typename std::array<T, Dim>::iterator;
    using const_iterator = typename std::array<T, Dim>::const_iterator;
    static constexpr std::size_t size_v = Dim;

    static constexpr std::size_t size() noexcept { return size_v; }

    vec() noexcept = default;

    explicit vec(T value) noexcept
        : m_data{} // zero-initialize the array
    {
        m_data.fill(value);
    }

    vec(std::initializer_list<T> list) noexcept
    {
        assert(list.size() == Dim);
        std::copy(list.begin(), list.end(), m_data.begin());
    }

    T& operator[](std::size_t index) noexcept { return m_data[index]; }

    const T& operator[](std::size_t index) const noexcept { return m_data[index]; }

    vec& operator+=(const vec& other) noexcept
    {
        std::transform(m_data.begin(), m_data.end(), other.m_data.begin(), m_data.begin(), std::plus<T>{});
        return *this;
    }

    vec& operator-=(const vec& other) noexcept
    {
        std::transform(m_data.begin(), m_data.end(), other.m_data.begin(), m_data.begin(), std::minus<T>{});
        return *this;
    }

    vec& operator*=(T scalar) noexcept
    {
        std::transform(m_data.begin(), m_data.end(), m_data.begin(), [scalar](T& x) { return x * scalar; });
        return *this;
    }

    vec& operator/=(T scalar)
    {
        assert(scalar != 0);
        std::transform(m_data.begin(), m_data.end(), m_data.begin(), [scalar](T& x) { return x / scalar; });
        return *this;
    }

    friend vec operator+(vec lhs, const vec& rhs) noexcept { return lhs += rhs; }

    friend vec operator-(vec lhs, const vec& rhs) noexcept { return lhs -= rhs; }

    friend vec operator*(vec lhs, T scalar) noexcept { return lhs *= scalar; }

    friend vec operator*(T scalar, vec rhs) noexcept { return rhs *= scalar; }

    friend vec operator/(vec lhs, T scalar) { return lhs /= scalar; }

    T dot(const vec& other) const noexcept
    {
        return std::inner_product(m_data.begin(), m_data.end(), other.m_data.begin(), static_cast<T>(0));
    }

    T length_squared() const noexcept { return dot(*this); }

    T length() const noexcept { return std::sqrt(length_squared()); }

    vec normalized() const noexcept
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

    friend std::ostream& operator<<(std::ostream& os, const vec& v) noexcept
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
