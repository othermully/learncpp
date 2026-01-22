#include <random>
#include <iostream>


bool play_game(int);

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

void play_again(){
	std::cout << "Would you like to play again (y/n)? ";
	char c{};
	std::cin >> c;

}

bool play_game(int rd){
	std::cout << "Let's play a game. Pick a number between 1-7, you have 7 tries" << '\n';
	for (int n_guess{ 1 }; n_guess <= 7; ++n_guess){
		std::cout << "Guess #" << n_guess << ':';
		int guess{};
		std::cin >> guess;

		if (guess > rd){
			std::cout << "You guess is too high." << '\n';
		}
		if (guess < rd){
			std::cout << "Your guess is too low." << '\n';
		}
		if (guess == rd){
			std::cout << "Correct! You win!" << '\n';
			return true;
		}
	}
	return true;
}

int main(){
	int rd { rng::get(1, 7) };

	if (play_game(rd)){
		play_again();
	}
	// Start game
	// Check user input
	// If guesses > 7, you lose, ask to play again
	// If number was correct, you win, ask to play again
	return 0;
}
