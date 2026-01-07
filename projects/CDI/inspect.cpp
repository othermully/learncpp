#include "inspect.h"
#include <iomanip> // For std::setprecision
#include <iostream>

void inspect_integer(int i){
	std::cout << "Inspecting: " << i << '\n';

	if (i > 0)
		std::cout << i << " is a positive number" << '\n';
	else if (i < 0)
		std::cout << i << " is a negative number" << '\n';
	else if (i == 0) 
		std::cout << i << " is equal to 0" << '\n';
	else 
		std::cout << i << " is unknown" << '\n';

	if (i % 2 == 0)
		std::cout << i << " is an even number." << '\n';
	else
		std::cout << i << " is an odd number." << '\n';

	std::size_t int_size { sizeof(i) };
	std::cout << "The size of " << i << " is " 
		  << int_size << " bytes.\n";
}

void inspect_floating(double d){
	std::cout << "Inspecting: " << d << '\n';
	std::cout << "Default precision set to 6." << '\n';

	if (d > 0)
		std::cout << d << " is positive.\n";
	else if (d < 0)
		std::cout << d << " is negative.\n";
	else if (d == 0.0)
		std::cout << d << " is zero.\n";
	else
		std::cout << d << " is unknown.\n";

	std::size_t double_size { sizeof(d) };
	std::cout << "The size of " << d << " is " << double_size << " bytes.\n";

	std::cout << std::setprecision(12); // changing the default precision 
	std::cout << "After changing the precision to 12: " << d << '\n';

	std::cout << "Adding 6.66 (Floating-point literal) to " << d << ": " << d + 6.66f << '\n'; // The `f` suffix means float literal, default is double
}

void inspect_char(char c){
	std::cout << "Inspecting: " << c << '\n';
	std::cout << "The integer value of " << c << " is " << static_cast<int>(c) << '\n';

	if (c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' || c == '0')
		std::cout << c << " is a digit.\n";
	else
		std::cout << c << " is a letter, or something else..\n";
}

void numeral_systems(){
	std::cout << "Numeral system example: " << '\n';
	constexpr int x { 5 };

	std::cout << "Decimal format: " << x << '\n';
	std::cout << "Octal format: " << std::oct << x << '\n';
	std::cout << "Hexadecimal format: " << std::hex << x << '\n';
}

void inspect_string(std::string_view sv){

	std::cout << "You have entered: " << sv << '\n';
	std::cout << "The string argument passed is a view type" << '\n';
	std::cout << "Any changes to the orignal, will invalidate the view." 
	          << '\n';

	constexpr std::string_view message { "This message is a constexpr string_view" };
	std::cout << message << '\n';

}
