#include <iostream>
#include <string>

std::string getFullName(){
	std::cout << "Enter your full name: ";
	std::string fullName{};
	std::getline(std::cin >> std::ws, fullName); // Ignore leading whitespace

	return fullName;
}

int getAge(){
	std::cout << "Enter your age: ";
	int age{};
	std::cin >> age;

	return age;
}

// Passing name by reference, no expensive copy, and function won't modify
int calcLength(int age, const std::string& name){
	// just knowledge-checking pass-by-ref
	std::cout << "Address of name inside of calcLength: " << &name << '\n';
	return age + static_cast<int>(name.length());
}

int main(){
	const std::string fullName      { getFullName() };
	const int age			{ getAge() };
	const int result		{ calcLength(age, fullName) };

	std::cout << "Your age + length of name is: " << result << '\n';
	std::cout << "Address of name inside of main: " << &fullName << '\n';

	return 0;
}
