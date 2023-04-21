#include "vectorT.hpp" // TODO: Got a lot of work that still needs to be done in here.

// TODO: These vector classes need cleaning up. I'd prob be worth moving there implementation details into a source file.
#include "vector2f.hpp"
#include "vector3f.hpp"
#include "vector4f.hpp"

namespace mim
{
    // Generic vector type. If you want to use a vector with a different dimension or type that is not already defined, use this.
    template <std::size_t Dim, typename T>
    using vec = vectorT<Dim, T>;

    using vec2 = vector2f;
    using vec3 = vector3f;
    using vec4 = vector4f;

    using vec2f = vector2f;
    using vec3f = vector3f;
    using vec4f = vector4f;

    using vec2i = vec<2, int>;
    using vec3i = vec<3, int>;
    using vec4i = vec<4, int>;

}