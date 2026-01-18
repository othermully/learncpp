#include <iostream>
// Interate through every number between 1 and 50
static void counter(){
	int count{ 1 };
	
	while (count <= 50){
		if (count < 10){
			std::cout << '0';
		}

		std::cout << count << ' ';

		if (count % 10 == 0){
			std::cout << '\n';
		}
		++count;
	}
}

int main(){
	counter();
	return 0;
}
