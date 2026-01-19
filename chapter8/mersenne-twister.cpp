#include <iostream>
#include <random> // for std::mt19937 and std::uniform_int_distribution
#include <chrono>

int main(){
	// Seed our Mersenne Twister using steady_clock
	std::mt19937 mt{
		static_cast<std::mt19937::result_type>(
			std::chrono::steady_clock::now().time_since_epoch().count()
		)
	};

	// Create a reusable random number gen that gens uniform numbers between 1 and 6
	std::uniform_int_distribution die6{ 1, 6};
	std::cout << die6 << '\n';

	for (int count{ 1 }; count <= 40; ++count){

		std::cout << die6(mt) << '\t';

		// If we've printed 10 numbers, start a new row
		if (count % 10 == 0)
			std::cout << '\n';
	}
	return 0;
}
