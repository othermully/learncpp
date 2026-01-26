#include <ios>
#include <iostream>
#include <limits> // for std::numeric_limits

bool hasUnextractedInput(){
	// std::cin.eof() function returns true if the last input operation reached the end of the input stream
	// std::cin.peek() function allows us to peek at the next character in the input stream without extracting it
	return !std::cin.eof() && std::cin.peek() != '\n';
}

void ignoreLine(){
	// std::cin.ignore(100, '\n'); - Clear up to 100 characters out of the buffer, or until a '\n' char is removed
	
	// std::numeric_limits<std::streamsize>::max() -> Returns the largest value that can be stored in a variable of type std::streamsize. Passing this value to std::cin.ignore() causes it to disable the count check

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

double getDouble(){
	while (true) {
		std::cout << "Enter a decimal number: ";
		double x{};
		std::cin >> x;

		if (std::cin.fail()){	    // If the previous extraction failed
			std::cin.clear();  // Put us back in 'normal' operation mode
			ignoreLine();     // And remove the bad input
			continue;
		} 

		// Our extractin succeeded if we made it here
		ignoreLine(); // Ignore any additinal input on this line
		return x;     // Return the value we extracted
	}
	// For fundamental types, a failed extraction due to invalid input will cause the variable to be assigned the value `0` (or whatever 0 converts to in the variables type)
}

char getOperator(){
	while (true) { // Loop until user enters valid input
		std::cout << "Enter one of the following: +, -, *, or /: ";
		char op{};
		std::cin >> op;

		// Check whether the user entered meaningful input
		switch (op) {
		case '+':
		case '-':
		case '*':
		case '/':
			return op; // return it to the caller
		default: std::cout << "Oops, that input is invalid.\n";
		}
	}
}

void printResult(double x, char op, double y){
	std::cout << x << ' ' << op << ' ' << y << " is ";

	switch (op) {
	case '+':
		std::cout << x + y << '\n';
		return;
	case '-':
		std::cout << x - y << '\n';
		return;
	case '*':
		std::cout << x * y << '\n';
		return;
	case '/':
		std::cout << x / y << '\n';
		return;
	}
}

int main(){
	double x	{ getDouble() };
	char operation	{ getOperator() };
	double y	{ getDouble() };

	printResult(x, operation, y);

	return 0;
}
