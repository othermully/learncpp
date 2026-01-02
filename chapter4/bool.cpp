#include <ios>
#include <iostream>
bool b1 {}; // Default inti to 'false'

// Bools print 0 for false and 1 for true
// You can use the std::boolalpha manipulator to output true/false

int main(){
	std::cout << true << '\n'; // Prints 1
	std::cout << false << '\n'; // Prints 0
	
	std::cout << std::boolalpha; // prints bools as true/false
	
	std::cout << true << '\n'; // Prints true
	std::cout << false << '\n'; // Prints false 
	
	std::cout << std::noboolalpha; // Turn off boolalpha
	
	return 0;
}

int integer_to_bool_conversion(){
	bool bFalse	{ 0 }; // okay: intialized to false
	bool bTrue	{ 1 }; // okay: intialized to true
	bool bNo	{ 2 }; // error: narrowing conversion disallowed
	
	std::cout << std::boolalpha;
	bool b1 = 4; // Copy intialization allows implicit conversion from int to bool
	std::cout << b1 << '\n'; // Prints true
	
	bool b2 = 0; // Copy-init allows implicit conversion from int to bool
	std::cout << b2 << '\n'; // Prints false
	
	return 0;
}

int inputting_bools(){

	bool b{}; // Default init to false
	std::cout << "Enter a bool value: ";
	std::cin >> b;
	std::cout << "You entered: " << b << '\n'; // Return 0 because bool accepts numeric input
	return 0;

	std::cout << "Enter a bool value: ";
	bool c{}; // Default init to false

	// This allows 'true' and 'false' input (CASE SENSITIVE)
	std::cin >> std::boolalpha;
	std::cin >> c;

	std::cout << std::boolalpha;
	std::cout << "You entered: " << c << '\n';
	
	return 0;
}

int bool_return_values(int x, int y){
	return x == y;
}

int bool_return_main(){
	std::cout << "Enter an integer: ";
	int x{};
	std::cin >> x;

	std::cout << "Enter another integer: ";
	int y{};
	std::cin >> y;

	std::cout << std::boolalpha; // Allow printing of true/false
	
	std::cout << bool_return_values(x, y) << '\n'; 

}
