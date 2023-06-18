





set(mim_detail_compute_headers
        include/mim/detail/compute/compute_functors.hpp
        include/mim/detail/compute/compute_matrix.hpp
        include/mim/detail/compute/compute_quaternion.hpp
        include/mim/detail/compute/compute_vector.hpp
        )

set(mim_detail_func_headers
        include/mim/detail/func/func_matrix2x2.inl
        include/mim/detail/func/func_matrix2x3.inl
        include/mim/detail/func/func_matrix2x4.inl
        include/mim/detail/func/func_matrix3x2.inl
        include/mim/detail/func/func_matrix3x3.inl
        include/mim/detail/func/func_matrix3x4.inl
        include/mim/detail/func/func_matrix4x2.inl
        include/mim/detail/func/func_matrix4x3.inl
        include/mim/detail/func/func_matrix4x4.inl
        include/mim/detail/func/func_matrix4x4_simd.inl

        include/mim/detail/func/func_quaternion.inl
        include/mim/detail/func/func_quaternion_simd.inl

        include/mim/detail/func/func_vector1.inl
        include/mim/detail/func/func_vector2.inl
        include/mim/detail/func/func_vector3.inl
        include/mim/detail/func/func_vector4.inl
        )

set(mim_detail_type_headers
        include/mim/detail/type/type_matrix2x2.hpp
        include/mim/detail/type/type_matrix2x2.inl
        include/mim/detail/type/type_matrix2x3.hpp
        include/mim/detail/type/type_matrix2x3.inl
        include/mim/detail/type/type_matrix2x4.hpp
        include/mim/detail/type/type_matrix2x4.inl
        include/mim/detail/type/type_matrix3x2.hpp
        include/mim/detail/type/type_matrix3x2.inl
        include/mim/detail/type/type_matrix3x3.hpp
        include/mim/detail/type/type_matrix3x3.inl
        include/mim/detail/type/type_matrix3x4.hpp
        include/mim/detail/type/type_matrix3x4.inl
        include/mim/detail/type/type_matrix4x2.hpp
        include/mim/detail/type/type_matrix4x2.inl
        include/mim/detail/type/type_matrix4x3.hpp
        include/mim/detail/type/type_matrix4x3.inl
        include/mim/detail/type/type_matrix4x4.hpp
        include/mim/detail/type/type_matrix4x4.inl

        include/mim/detail/type/type_quaternion.hpp
        include/mim/detail/type/type_quaternion.inl
        include/mim/detail/type/type_quaternion_simd.inl


        include/mim/detail/type/type_vector1.hpp
        include/mim/detail/type/type_vector1.inl
        include/mim/detail/type/type_vector2.hpp
        include/mim/detail/type/type_vector2.inl
        include/mim/detail/type/type_vector3.hpp
        include/mim/detail/type/type_vector3.inl
        include/mim/detail/type/type_vector4.hpp
        include/mim/detail/type/type_vector4.inl
        include/mim/detail/type/type_vector4_simd.inl
        )


set(mim_detail_headers
        ${mim_detail_compute_headers}
        ${mim_detail_func_headers}
        ${mim_detail_type_headers}

        include/mim/detail/qualifier.hpp
        )

set(mim_internal_config_headers
        include/mim/internal/config/architecture.hpp
        include/mim/internal/config/compiler.hpp
        include/mim/internal/config/compiler_features.hpp
        include/mim/internal/config/compiler_traits.hpp
        include/mim/internal/config/platform.hpp
        )
set(mim_internal_misc_headers
        include/mim/internal/misc/pcg_random.hpp
        include/mim/internal/misc/pcg_extras.hpp
        include/mim/internal/misc/pcg_uint128.hpp
        )

set(mim_internal_headers
        ${mim_internal_config_headers}
        ${mim_internal_misc_headers}

        include/mim/internal/float16compressor.hpp
        include/mim/internal/functionpacker.hpp
        include/mim/internal/functionpacker.inl
        include/mim/internal/functionpacker_simd.inl
        include/mim/internal/setup.hpp
        )

set(mim_simd_headers
        include/mim/simd/simdNeon.hpp
        include/mim/simd/simdSetup.hpp
        include/mim/simd/simdUtil.hpp
)


set(mim_headers
        ${mim_detail_headers}
        ${mim_internal_headers}
        ${mim_simd_headers}


        include/mim/mim.hpp

        include/mim/half.hpp
        include/mim/mat.hpp
        include/mim/mat2.hpp
        include/mim/mat3.hpp
        include/mim/mat4.hpp
        include/mim/mathUtils.hpp
        include/mim/mimMath.hpp
        include/mim/mimConstants.hpp
        include/mim/quat.hpp
        include/mim/random.hpp
        include/mim/vec.hpp
        include/mim/vec1.hpp
        include/mim/vec2.hpp
        include/mim/vec3.hpp
        include/mim/vec4.hpp
        )
