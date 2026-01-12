#include <iostream>

int main(){
	std::cout << "Enter an integer: ";
	int smaller{}; // smaller enters scope here
	std::cin >> smaller; 

	std::cout << "Enter a larger integer: ";
	int larger{}; // larger enters scope here
	std::cin >> larger; 

	if (smaller > larger){
		std::cout << "Swapping the values" << '\n';
		int temp { larger }; // temp enters scope here
		larger = smaller;
		smaller = temp;
	} // temp destroyed here 
	
	std::cout << "The smaller value is " << smaller << '\n';
	std::cout << "The larger value is " << larger << '\n';

	return 0;
} // larger, smaller destroyed here
