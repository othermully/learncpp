#include <iostream>
#include <random> // for std::random_device

namespace rng{
	std::mt19937& engine(){
		static std::mt19937 mt { std::random_device{}() };
		return mt;
	}
	
	int get(int min, int max){
		std::uniform_int_distribution rd{ 1, 6 };
		return rd(engine());
	}
}

