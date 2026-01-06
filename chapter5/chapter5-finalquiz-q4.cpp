#include <iostream>
#include <string>
#include <string_view>

std::string getName(unsigned int num){
	std::cout << "Enter the name of person #" << num << ": ";
	std::string name{};
	std::getline(std::cin >> std::ws, name);

	return name;
}

unsigned int getAge(std::string_view person){
	std::cout << "Enter the age of " << person << ": ";
	unsigned int age{};
	std::cin >> age;

	return age;
}

void printOlder(std::string_view p1, int a1,
		std::string_view p2, int a2){

	if (a1 > a2)
		std::cout 
			<< p1 << "(age " 
			<< a1 << ") "
			<< "is older than " 
			<< p2 << " (age "
			<< a2 << ") ." << '\n';
	else
		std::cout 
			<< p2 << " (age " 
			<< a2 << ") "
			<< "is older than " 
			<< p1 << " (age "
		        << a1 << ") ." << '\n';
}

int main(){

	const std::string person1 { getName(1) };
	const int age1		  { getAge(person1) };

	const std::string person2 { getName(2) };
	const int age2		  { getAge(person2) };

	printOlder(person1, age1,
		   person2, age2);

	return 0;
}
