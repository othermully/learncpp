#include <random>
#include <iostream>

bool check_num(int, int);

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

void start_game(){
	int rd { rng::get(1, 7) };
	std::cout << "Let's play a game. Pick a number between 1-7, you have 7 tries" << '\n';
}

int main(){
	// Start game
	// Check user input
	// If guesses > 7, you lose, ask to play again
	// If number was correct, you win, ask to play again
	return 0;
}
