#include <iostream>

namespace {
	constexpr double gravity { 9.8 };
}

double getTowerHeight(){
	std::cout << "Enter the height of the tower in meters: ";
	double towerHeight{};
	std::cin >> towerHeight;
	return towerHeight;
}

// Returns the current ball height after n seconds
double calculateBallHeight(double towerHeight, int seconds){

	// using formula: s = (u * t) + (a * t^2) / 2
	// here u (initial velocity) = 0, so (u * t) = 0
	const double fallDistance { gravity * (seconds * seconds) / 2.0 };
	const double ballHeight   { towerHeight - fallDistance };

	if (ballHeight < 0.0)
		return 0.0;

	return ballHeight;
}

// Prints ball height above ground
void printBallHeight(double ballHeight, int seconds){
	if (ballHeight > 0.0){
		std::cout << "At " << seconds << " seconds, the ball is at height: "
			  << ballHeight << " meters\n";
	}
	else{
		std::cout << "At " << seconds << " seconds, the ball is on the ground\n";
	}
	
}

// Helper function to calculate and print
double calculateAndPrintBallHeight(double towerHeight, int seconds){
	const double ballHeight { calculateBallHeight(towerHeight, seconds) };
	printBallHeight(ballHeight, seconds);

	return ballHeight;
}

int main(){
	const double towerHeight { getTowerHeight() };
	int seconds{ 0 };

	while (calculateAndPrintBallHeight(towerHeight, seconds) > 0.0){
		++seconds;
	}


	return 0;
}
