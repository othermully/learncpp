#include "input.h"
#include <iostream>
#include <string>

int get_integer_input(){
	std::cout << "Please enter an integer: ";
	int user_input{};
	std::cin >> user_input;

	return user_input;
}

double get_floating_input(){
	std::cout << "Please enter a floating-point number: ";
	double user_input{};
	std::cin >> user_input;

	return user_input;
}

char get_char_input(){
	std::cout << "Please enter a char: ";
	char user_input{};
	std::cin >> user_input;

	return user_input;
}

std::string get_string_input(){
	std::cout << "Enter a string: ";
	std::string s{};
	std::getline(std::cin >> std::ws, s);

	return s;
}


