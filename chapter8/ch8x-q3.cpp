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

void start_game(){
	const int ran_num { rng::get(1, 100) };
	std::cout << "Starting game... Guess a number between 1-100" << '\n';

	for (int n_guess{ 1 }; n_guess <= 7; ++n_guess){ // Loop through guesses
		std::cout << "Guess #" << n_guess << ": ";
		int guess{};
		std::cin >> guess;

		if (guess > ran_num){
			std::cout << "Your guess is too high" << '\n';
		}
		else if (guess < ran_num){
			std::cout << "Your guess is too low" << '\n';
		}
		else if (guess == ran_num){
			std::cout << "Correct! You win!" << '\n';
			return;
		}
	}
	std::cout << "Sorry you lose. The correct number was " << ran_num << std::endl;
	return;

}

bool play_again(){
	while (true) { // Loop until the user selects y or n
		std::cout << "Would you like to play again (y/n)? ";
		char c{};
		std::cin >> c;

		switch (c) {
			case 'y': return true;
			case 'n': return false;
		}
	}
}

int main(){
	// Ignore these for now
	[[maybe_unused]] constexpr int n_guesses { 7 };
	[[maybe_unused]] constexpr int max       { 100 };
	[[maybe_unused]] constexpr int min       { 1 };

	do {
		start_game(); // Call this function first
	}
	while (play_again()); // Once start_game returns, this gets executed

	return 0;
}
