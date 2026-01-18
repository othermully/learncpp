#include <iostream>


int main(){
	for (int i{ 0 }; i != 10; ++i){
		std::cout << "Start of if statement: " << i << '\n';
		if (i == 9) {
			std::cout << "Inside if statement: " << i << '\n';
			++i;
			std::cout << "After increment: " << i << '\n';
			break;
		} 
		std::cout << "Before going to start: " << i << '\n';
	}

	return 0;
}
