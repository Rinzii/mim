#pragma once

template <std::size_t Dim, typename T>
struct vectorT {
	using VecSize = std::array<T, Dim>;

  public:
	using value_type = T;
	using iterator = typename VecSize::iterator;
	using const_iterator = typename VecSize::const_iterator;
	static constexpr auto size_v = Dim;

	static constexpr std::size_t size() { return size_v; }

	vectorT() = default;

	vectorT(T value) {
		for (auto& i : m_data) {
			i = value;
		}
	}

};