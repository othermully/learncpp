#include <cstdint>
#include <ios>
#include <iostream>
#include <limits>

void printSizeAndLimits(){
	std::cout << "Numeric_limits on double: ";
	std::cout << std::numeric_limits<double>::max() << '\n';

	std::cout << "Size of double: ";
	std::cout << sizeof(double) << " bytes\n";


	std::cout << '\n';
	std::cout << "Numeric_limits on unsigned int: ";
	std::cout << std::numeric_limits<unsigned int>::max();

	std::cout << '\n';

	std::cout << "Size of unsigned int: ";
	std::cout << sizeof(unsigned int) << " bytes\n";

	std::cout << "Size of signed int: ";
	std::cout << sizeof(int) << " bytes\n";

	std::cout << "Numeric_limits on signed int: ";
	std::cout << std::numeric_limits<int>::max();

	std::cout << '\n';

	std::cout << "Numeric limits on std::streamsize: ";
	std::cout << std::numeric_limits<std::streamsize>::max() << std::endl;
}

void testingStdCin(){
	std::cout << "Enter an integer: "; // No new line since user presses enter which sends \n to buffer
	int x{};
	std::cin >> x;

	std::cout << "User entered " << x << '\n';

	if (std::cin.fail()){
		std::cout << "Extraction failed, STATUS: " << std::cin.fail() << '\n';
		std::cout << "Putting it back into 'normal mode'..." << '\n';
		std::cin.clear();
		std::cout << "std::cin STATUS: " << std::cin.fail() << '\n';
	}
}

int main(){
	printSizeAndLimits();
	testingStdCin();
	return 0;
}
