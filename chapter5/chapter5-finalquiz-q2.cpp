#include <iostream>

int main(){
	constexpr int drivingAge { 16 };

	std::cout << "How old are you?\n";

	int age{};
	std::cin >> age;

	std::cout << "Allowed to drive a car in Texas: ";

	if (age >= drivingAge)
		std::cout << "Yes";
	else
		std::cout << "No";

	std::cout << "\n";

	return 0;

}
