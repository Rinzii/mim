// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#pragma once

#include <random>

#include "mim/internal/misc/pcg_random.hpp"
#include "mim/internal/setup.hpp"

// TODO: Test this class.

namespace mim
{
	/**
	 * \brief A random number generator using the PCG algorithm.
	 */
	class random
	{
	public:
		static constexpr detail::u64 DEFAULT_SEED = 1442695040888963407ULL;
		static constexpr detail::u64 DEFAULT_INC = 1442695040888963407ULL;

		explicit random()
		{

			current_seed = DEFAULT_SEED;
			current_inc = DEFAULT_INC;

			rng = {seed_source};
		}

		template <typename T = detail::u64>
		explicit random(T seed_, T inc_)
		{

			if (seed_ < 0) seed_ = -seed_;

			if (inc_ < 0) inc_ = -inc_;

			current_seed = static_cast<detail::u64>(seed_);
			current_inc = static_cast<detail::u64>(inc_);

			rng = {seed_source};
		}

		template <typename T = detail::u64>
		explicit random(T seed_)
		{

			if (seed_ < 0) seed_ = -seed_;

			current_seed = static_cast<detail::u64>(seed_);
			current_inc = DEFAULT_INC;

			rng = {seed_source};
		}

		// A random object is not copyable or movable.
		random(const random&) = delete;
		random(random&&) = delete;
		random& operator=(const random&) = delete;
		random& operator=(random&&) = delete;

		/**
		 * \brief Sets the seed of the random number generator.
		 * @param newSeed The new seed.
		 */
		void set_seed(detail::u64 newSeed);

		/**
		 * \brief Sets the seed of the random number generator.
		 * @param newSeed The new seed.
		 */
		void seed(detail::u64 newSeed);

		/**
		 * \brief Gets the current set seed.
		 * @return The current seed.
		 */
		MIM_NODISCARD detail::u64 get_seed() const;

		/**
		 * \brief Generates a random 32-bit integer.
		 * @return A random 32-bit integer between 0 and the maximum value of a 32-bit integer.
		 */
		detail::i32 next();

		/**
		 * \brief Generates a random 32-bit integer.
		 * \note The upper bound MUST be positive. If it is negative, it will be made positive.
		 * @param upperBound The upper bound of the random number.
		 * @return A random 32-bit integer between 0 and a upperBound.
		 */
		detail::i32 next(detail::i32 upperBound);

		/**
		 * \brief Generates a random 32-bit integer.
		 * @param lowerBound The lower bound of the random number.
		 * @param upperBound The upper bound of the random number.
		 * @return A random 32-bit integer between a lowerBound and upperBound.
		 */
		detail::i32 next(detail::i32 lowerBound, detail::i32 upperBound);

		/**
		 * \brief Generates a random 64-bit integer.
		 * @return A random 64-bit integer between 0 and the maximum value of a 64-bit integer.
		 */
		detail::i64 next_int64();

		/**
		 * \brief Generates a random 64-bit integer.
		 * \note The upper bound MUST be positive. If it is negative, it will be made positive.
		 * \param upperBound The upper bound of the random number.
		 * \return A random 64-bit integer between 0 and a upperBound.
		 */
		detail::i64 next_int64(detail::i64 upperBound);

		/**
		 * \brief Generates a random 64-bit integer.
		 * \param lowerBound The lower bound of the random number.
		 * \param upperBound The upper bound of the random number.
		 * \return A random 64-bit integer between a lowerBound and upperBound.
		 */
		detail::i64 next_int64(detail::i64 lowerBound, detail::i64 upperBound);

		/**
		 * \brief Generates a random float.
		 * @return A random float between 0.0 and 1.0.
		 */
		float next_single();

		/**
		 * \brief Generates a random float.
		 * \note The upper bound MUST be positive. If it is negative, it will be made positive.
		 * @param upperBound The upper bound of the random number.
		 * @return A random float between 0.0 and a upperBound.
		 */
		float next_single(float upperBound);

		/**
		 * \brief Generates a random float.
		 * @param lowerBound The lower bound of the random number.
		 * @param upperBound The upper bound of the random number.
		 * @return A random float between a lowerBound and upperBound.
		 */
		float next_single(float lowerBound, float upperBound);

		/**
		 * \brief Generates a random double.
		 * @return A random double between 0.0 and 1.0.
		 */
		double next_double();

		/**
		 * \brief Generates a random double.
		 * \note The upper bound MUST be positive. If it is negative, it will be made positive.
		 * @param upperBound The upper bound of the random number.
		 * @return A random double between 0.0 and a upperBound.
		 */
		double next_double(double upperBound);

		/**
		 * \brief Generates a random double.
		 * @param lowerBound The lower bound of the random number.
		 * @param upperBound The upper bound of the random number.
		 * @return A random double between a lowerBound and upperBound.
		 */
		double next_double(double lowerBound, double upperBound);

	private:
		pcg_extras::seed_seq_from<std::random_device> seed_source; /*!< The seed source. */
		pcg32 rng;												   /*!< The random number generator using the PCG Algorithm. */
		detail::u64 current_seed = 0;							   /*!< The current seed. */
		detail::u64 current_inc = 0;							   /*!< The current increment. */
	};

} // namespace mim
