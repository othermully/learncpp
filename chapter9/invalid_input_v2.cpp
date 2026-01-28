#include <cstdlib> // for std::exit
#include <iostream>
#include <limits>

void ignoreLine(){
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// returns true if the extraction failed, false otherwise
bool clearFailedExtraction(){

	// Check for failed extraction
	if (!std::cin) // If the previous extraction failed
	{
		if (std::cin.eof()) // If the stream was closed
		{ 			
			std::exit(0); // Shut donw the program now
		} 

		// Lets handle the failure
		std::cin.clear(); // Put us back in 'normal' mode
		ignoreLine();
		
		return true;
	} 

	return false;
}

double getDouble(){
	while (true) // Loop until user enters a valid input
	{
		std::cout << "Enter a decimal number: ";
		double x{};
		std::cin >> x;

		if (!clearFailedExtraction()){
			std::cout << "Invalid input. Try again.\n";
			continue;
		}

		ignoreLine(); // Remove any extraneous input
		return x;
	}
}

char getOperator(){
	while (true) {
		std::cout << "Enter +, -, *, or /: ";
		char operation{};
		std::cin >> operation;

		if (!clearFailedExtraction()){ 
			ignoreLine();
		}

		switch (operation) {
			case '+':
			case '-':
			case '*':
			case '/':
				return operation; // Return the entered char to the caller
			default: // Otherwise tell the user what went wrong
				std::cout << "Invalid input\n";
		}
	}
}
