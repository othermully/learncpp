#include <iostream>


int main(){

	char c { 'c' };
start: // Statement label
	std::cout << "Start!" << '\n';

	switch (c){
	case 'c': [[fallthrough]];
	case 'd': [[fallthrough]];
	case 'e':
		std::cout << "Switch case 'e' triggered" << '\n';
		goto start; // Create an infinite loop 
		return 0;
	default:
		std::cout << "Switch case 'default' triggered" << '\n';
		return 0;
	}
	return 0;
}


