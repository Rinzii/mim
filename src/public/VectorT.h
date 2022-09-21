#pragma once
#include <array>
#include <cstdint>

/*
 * Copied from: https://github.com/cpp-gamedev/tray/blob/main/tray/src/tray/vec.hpp
 *
 * Original code made by Karn Kaul.
 * Github: https://github.com/karnkaul
 *
 * Modified by Ian Pike.
 * Github: https://github.com/Rinzii
 */
namespace mathematical {
    template<typename Type, std::size_t Dim>
    struct VectorT {
        std::array<Type, Dim> values{};

        constexpr Type &x() { return values[0]; }

        constexpr Type const &x() const { return values[0]; }

        constexpr Type &y() requires (Dim > 1) { return values[1]; }

        constexpr Type const &y() const requires (Dim > 1) { return values[1]; }

        constexpr Type &z() requires (Dim > 2) { return values[2]; }

        constexpr Type const &z() const requires (Dim > 2) { return values[2]; }
    };
}