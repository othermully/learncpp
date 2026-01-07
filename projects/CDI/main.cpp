#include "input.h"
#include "convert.h"
#include "inspect.h"
#include <iostream>

void type_conversion_menu(){
	std::cout << "Select a conversion to preform: " << '\n';
	std::cout << "1. char -> int" << '\n';
	std::cout << "2. int -> double" << '\n';

	unsigned int user_selection{};
	std::cin >> user_selection;

	if (user_selection == 1)
		convert_char();
	else if (user_selection == 2)
		convert_int();
	else
		std::cout << "Please select a valid option.." << '\n';
}

void display_menu(){
	std::cout << "SELECT A MENU OPTION (1-5): " << '\n';
	std::cout << "1. Inspect a integer" << '\n';
	std::cout << "2. Inspect a floating-point number" << '\n';
	std::cout << "3. Inspect a character" << '\n';
	std::cout << "4. Convert between types" << '\n';
	std::cout << "5. Display system/type information" << '\n';
	std::cout << "6. Display numeral systems" << '\n';
	std::cout << "7. Boolean variables" << '\n';
	std::cout << "8. Strings" << '\n';
}

int main(){
	display_menu();

	std::cout << "Selection: ";
	unsigned int user_selection{};
	std::cin >> user_selection;
	std::cout << '\n';


	// This if/else chain handles the users selection and calls the respective functions required to handle the task.
	if (user_selection == 1)
		inspect_integer(get_integer_input());

	else if (user_selection == 2)
		inspect_floating(get_floating_input());

	else if (user_selection == 3)
		inspect_char(get_char_input());

	else if (user_selection == 4)
		type_conversion_menu();

	else if (user_selection == 5)
		std::cout << "Display info selected." << '\n';

	else if (user_selection == 6)
		numeral_systems();

	else if (user_selection == 7)
		// Boolean logic
		[[maybe_unused]] int x; // please compile

	else if (user_selection == 8)
		inspect_string(get_string_input());
	else
		std::cout << "Please enter a valid menu option (1-5)" << '\n';

	return 0;
}
