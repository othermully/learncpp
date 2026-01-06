#include "convert.h"
#include <iostream>

void implicit_conversion_banner(){
	std::cout << "Implicit conversion is avoided because it can cause loss of information and precision." << '\n';
	std::cout << "During our conversion functions, all conversion were done explicitly via static_cast." << '\n';
}

void convert_char(){
	std::cout << "Enter a char to convert: " << '\n';
	char c{};
	std::cin >> c;
	std::cout << "Converted " << c << " to int " 
		  << static_cast<int>(c) << '\n';

	implicit_conversion_banner();
}

void convert_int(){
	std::cout << "Enter a int to convert: " << '\n';
	int i{};
	std::cin >> i;
	std::cout << "Converted " << i << " to double " 
		  << static_cast<double>(i) << '\n';

	implicit_conversion_banner();

	std::cout << "You may also realize that if you inputted a floating-point number here, the precision is lost since it was orginally an int type, which has no decimal points." << '\n';
}

