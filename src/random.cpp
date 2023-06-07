// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#include "mim/internal/setup.hpp"

#include "mim/random.hpp"
//#include "../include/mim/internal/setup.hpp"
//#include "../include/mim/random.hpp"

#include <climits>

namespace mim
{
	void random::set_seed(detail::u64 newSeed)
	{
		current_seed = newSeed;
		rng.seed(current_seed);
	}

	void random::seed(detail::u64 newSeed)
	{
		current_seed = newSeed;
		rng.seed(current_seed);
	}

	detail::u64 random::get_seed() const
	{
		return current_seed;
	}

    detail::i32 random::next()
    {
		std::uniform_int_distribution<detail::i32> uniform_dist(0, INT_MAX);
        return uniform_dist(rng);
    }

    detail::i32 random::next(detail::i32 upperBound)
    {
		if (upperBound < 0)
        {
            upperBound = -upperBound;
        }

		std::uniform_int_distribution<detail::i32> uniform_dist(0, upperBound);
		return uniform_dist(rng);
    }

    detail::i32 random::next(detail::i32 lowerBound, detail::i32 upperBound)
    {
		std::uniform_int_distribution<detail::i32> uniform_dist(lowerBound, upperBound);
		return uniform_dist(rng);
    }

	detail::i64 random::next_int64()
    {
		std::uniform_int_distribution<detail::i64> uniform_dist(0, INT64_MAX);
		return uniform_dist(rng);
    }

    detail::i64 random::next_int64(detail::i64 upperBound)
    {
		if (upperBound < 0)
		{
			upperBound = -upperBound;
		}

		std::uniform_int_distribution<detail::i64> uniform_dist(0, upperBound);
		return uniform_dist(rng);
    }

    detail::i64 random::next_int64(detail::i64 lowerBound, detail::i64 upperBound)
    {
		std::uniform_int_distribution<detail::i64> uniform_dist(lowerBound, upperBound);
		return uniform_dist(rng);
    }

    float random::next_single()
    {
		std::uniform_real_distribution<float> uniform_dist(0, 1);
		return uniform_dist(rng);
    }

	float random::next_single(float upperBound)
	{
        if (upperBound < 0)
        {
            upperBound = -upperBound;
        }

		std::uniform_real_distribution<float> uniform_dist(0, upperBound);
		return uniform_dist(rng);
	}
	float random::next_single(float lowerBound, float upperBound)
	{
		std::uniform_real_distribution<float> uniform_dist(lowerBound, upperBound);
		return uniform_dist(rng);
	}

    double random::next_double()
    {
		std::uniform_real_distribution<double> uniform_dist(0, 1);
		return uniform_dist(rng);
    }

	double random::next_double(double upperBound)
	{
		if (upperBound < 0)
		{
			upperBound = -upperBound;
		}

		std::uniform_real_distribution<double> uniform_dist(0, upperBound);
		return uniform_dist(rng);
	}
	double random::next_double(double lowerBound, double upperBound)
	{

		std::uniform_real_distribution<double> uniform_dist(lowerBound, upperBound);
		return uniform_dist(rng);
	}

}
