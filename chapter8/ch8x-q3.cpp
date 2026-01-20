#include <random>
#include <iostream>

namespace rng {
	// Seed PRNG using std::random_device
	std::mt19937& engine() {
		static std::mt19937 mt { std::random_device{}() };
		return mt;
	}
	int get(int min, int max){
		std::uniform_int_distribution ran_range{ min, max };
		return ran_range(engine());
	}
}

int main(){
	std::random_device rd2{};
	int rd { rng::get(1, 6) };
	std::cout << rd << '\n';
	return 0;
}
