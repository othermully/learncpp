#include <cassert>
#include <iostream>
#include <limits>

int main(){
//	static_assert(false && "False value");
	while (true) {
		std::cout << "Enter a int: ";
		int x{};
		std::cin >> x;

		assert(x != 5 && "X was equal to 5, aborting."); // std::abort if x is equal to 5

		if (!std::cin) {
			std::cout << "Input stream has failed flag\n";
			std::cin.clear(); // Bring us back to normal mode (clear flag)
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		std::cout << x << '\n';
	}
	return 0;
}
