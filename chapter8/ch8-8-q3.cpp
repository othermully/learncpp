#include <iostream>

int main(){

	// outer loops between 5 and 1
	int outer{ 5 };
	while (outer >= 1){

		// Loop between outer and 1

		int inner{ outer };
		while (inner >= 1){
			std::cout << inner-- << ' '; // Print original, then increment
		}

		std::cout << '\n';
		--outer;
	} // inner destroyed here

	return 0;
}
