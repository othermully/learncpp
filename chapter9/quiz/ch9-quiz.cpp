#include <iostream>
#include <cassert>
#include <limits>
#include <random>

namespace rng{
	std::mt19937& engine(){
		std::mt19937 mt { std::random_device(){} };
		return mt;
	}

}

int main(){
	return 0;
}
