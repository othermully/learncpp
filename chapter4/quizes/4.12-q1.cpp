/* This program asks a user to enter a single character, then will print the value of the entered character along with its ASCII code using static_cast
*/
#include <iostream>

int main(){
	std::cout << "Enter a single character: ";
	char ch{};
	std::cin >> ch;

	std::cout << "You entered '" << ch << "', which has ASCII code " 
		<< static_cast<int>(ch) << '\n';

	return 0;
}
