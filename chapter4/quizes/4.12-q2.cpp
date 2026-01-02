#include <iostream>

int print(int x){ // Implicit type conversion happens when the value is copied to the functions paramter
	return x;
}

int charAsInt(char c){ // Implicit type conversion happens when the return value is returned to the caller
	return c;
}

int main(){
	std::cout << "Enter a single character: ";
	char c{};
	std::cin >> c;

	std::cout << "You entered '" << c << "', which has ASCII code " << print(c) << '\n';

	// Another way of implicit type conversion
	int ascii { c };
	std::cout << "ASCII: " << c << '\n';

	return 0;
}
