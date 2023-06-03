// Copyright WizWorks, Inc. All Rights Reserved.

#pragma once

#include "system/core.hpp"

#include <climits>

namespace mim
{
    template <typename T> const T MIM_PI = static_cast<T>(3.141592653589793238462643);
    template <typename T> const T MIM_2PI = static_cast<T>(6.283185307179586476925287);
    template <typename T> const T MIM_TAU = static_cast<T>(6.283185307179586476925287);
    template <typename T> const T MIM_E = static_cast<T>(2.7182818284590452353602874714);

    template <typename T> const T MIM_EPSILON = std::numeric_limits<T>::epsilon();
    template <> const float MIM_EPSILON<float> = FLT_EPSILON;
    template <> const double MIM_EPSILON<double> = DBL_EPSILON;
    template <> const long double MIM_EPSILON<long double> = LDBL_EPSILON;

    template <typename T> const T MIM_UNIT_EPSILON = T{ 0.00001 }

}

