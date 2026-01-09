#include <iostream>

bool isEven(int x){

	// if x % 2 == 0, 2 divides evenly into our number, meaning its even
	return !(x % 2);
}

int main(){

	std::cout << "Enter an integer: ";
	int x{};
	std::cin >> x;

	if (isEven(x))
		std::cout << x << " is even";
	else
		std::cout << x << " is odd";

	return 0;
}
