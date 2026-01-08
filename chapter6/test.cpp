#include <iostream>
#include <string>
#include <string_view>


void output_string(std::string_view sv){
	// sv parameter is read-only object referencing the input string
	std::cout << sv << '\n';
}

constexpr int pass_by_value(int x){
	x += 1;
	return x;
}

void pass_by_reference(int &x){
	// This function modifies the original x value, since we pass in the memory address where object x is loctated
	x += 5;
}

int main(){
	std::string s { "Hello, world!" };
	output_string(s);

	int x { pass_by_value(5) };
	std::cout << x << '\n';

	pass_by_reference(x);

	std::cout << "After pass by reference: " << x << '\n';

	// Conditional testing
	
	int b1{};

	// b1 with value-intialization evaluates to 0, thus is false
	if (b1)
		std::cout << b1 << " True!" << '\n';
	else
		std::cout << b1 << " False!" << '\n';


	// Pointers - Variable that holds a memory address
	// Uses the address-of operator &
	// Uses the dereference operator *
	
	int num { 7 };
	int *pNum = &num;

	std::cout << pNum << " This should be the memory address of num\n";
	std::cout << *pNum << " This shoud be the value stored in the memory address of num\n";

	return 0;
	
}
