#include <iostream>
#include <bitset>

int main(){
	float x { 3.1f }; // This causes loss of precision
	std::cout << "size of x: " << sizeof(x) << '\n';
	std::cout << "x is now type 'float'" << std::endl;

	// Octal literal
	int y { 012 };
	std::cout << "Octal 012: " << y << '\n';

	// Hexadecimal literal
	int z { 0xF }; // 0x before the number means this is hexadecimal
	std::cout << "Hex 0xF: " << z << '\n';

	// Binary
	int bin{};
	bin = 0b1; // Assign binary 0000 0000 0000 0001 to the variable
	std::cout << "Binary 0b1: " << bin << '\n';

	std::bitset<8> bin1 { 0b1100'0101 }; // binary literal for binary 1100 0101
	std::cout << bin1 << '\n';
	

	return 0;
}
