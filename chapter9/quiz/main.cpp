// Hi-Lo but handle invalid guesses (e.g. 'x'), out of bounds guesses (e.g. 0 or 101) or valid guesses that have extraneous characters. Also handle the user entering extra characters when the game asks if they want ti play again
// Write a function to handle the user inputting their guess (along with the associated error handling)
#include "random.h"
#include <cstdlib>
#include <iostream>
#include <limits>
#include <cassert>
#define PASS

// Clear up to n characters in input buffer up to a '\n';
void ignoreLine(){
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Clear fail flags on std::cin and put it back into 'normal' mode, handling failures
bool clearFailedExtraction(){
	if (!std::cin) { // If std::cin is in failed state

		if (std::cin.eof()){
			std::cout << "EOF character";
			std::exit(0);
		}

		std::cin.clear(); // Put us back in normal mode
		ignoreLine(); // Remove extraneous characters in input buffer
		
		return true;
	}
	return false;
}

bool playAgain(){
	while (true) {
		std::cout << "Do you want to play again? (y/n): ";
		char c{};
		std::cin >> c;

		if(clearFailedExtraction()){
			std::cout << "Invalid input, please enter 'y' or 'n'" << '\n';
			continue;
		}

		switch (c) {
			case 'y': return true;
			case 'n': return false;
		}
	}
}

int getGuess(int n_guess){
	while (true) {
		std::cout << "Guess #" << n_guess << " ";
		int guess{};
		std::cin >> guess;

		if (clearFailedExtraction()) {
			std::cout << "Invalid input, try again.\n";
			continue;
		}

		if (guess <= 0 || guess > 100) {
			std::cout << "Guess out of bounds.\n";
			continue;
		}

		return guess;
	}
}

void playGame(){
	const int rd { Random::get(1,100) }; // Generate random number between 1-100, using Mersenne Twisted seeded with clock
	
	std::cout << "I'm thinking of a number between 1-100.. You have 7 tries to guess it\n";

	for (int n_guess { 1 }; n_guess <= 7; ++n_guess){
		int guess = getGuess(n_guess);

		if (guess < rd) {
			std::cout << "Too low.\n";
			continue;

		}
		if (guess > rd){
			std::cout << "Too high.\n";
			continue;
		}

		std::cout << "Correct! The number was " << rd << ".\n";
		return;
	}

	std::cout << "You ran out of guesses, the number was: " << rd << std::endl;
	return;
}

int main(){
	do {
	playGame();
	}while (playAgain());

	return 0;
}
