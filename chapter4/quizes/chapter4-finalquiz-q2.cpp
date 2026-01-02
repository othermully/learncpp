// Ask user to enter 2 floating point numbers
// Ask user to enter math symbol (+, -, *, /)
// Program computes the answer, and prints results
// Invalid input prints nothing

#include <iostream>

double getNum(){
	std::cout << "Enter floating point number: ";
	double num{};
	std::cin >> num;

	return num;
}

char getSymbol(){
	std::cout << "Choose '+' , '-', '*', '/': ";
	char symbol{};
	std::cin >> symbol;
	return symbol;
}

void printResult(double x, double y, char operation){
	double result{};

	if (operation == '+')
		result = x + y;
	else if (operation == '*')
		result = x * y;
	else if (operation == '-')
		result = x - y;
	else if (operation == '/')
		result = x / y;
	else
		return;

	std::cout << x << " " << operation << " " << y << " is: " << result << '\n';
}

int main(){
	double x	{ getNum() };
	double y	{ getNum() };
	char symbol	{ getSymbol() };

	printResult(x, y, symbol);

	return 0;
}

