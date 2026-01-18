#include <iostream>

static int calculate(int x, int y, char c){
	
	switch (c){
	case '+':
		return x + y;
	case '-':
		return x - y;
	case '*':
		return x * y;
	case '/':
		return x / y;
	case '%':
		return x % y;
	default:
		std::cerr << "Enter a valid symbol" << std::endl;
		return 0;
	}

}

int main(){
	std::cout << "Enter an integer: ";
	int x{};
	std::cin >> x;

	std::cout << "Enter another integer: ";
	int y{};
	std::cin >> y;

	std::cout << "Enter a operator (+, -, *, %, /): ";
	char op{};
	std::cin >> op;

	int result { calculate(x, y, op) };
	std::cout << result << std::endl;

	return 0;
}
