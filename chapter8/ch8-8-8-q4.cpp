// Using while loops and if statements - produce the following output:
//x x x x 1
//x x x 2 1
//x x 3 2 1
//x 4 3 2 1
//5 4 3 2 1 

#include <iostream>

int main(){

	int   outer{ 5 };
	int counter{ 1 };
	while (outer >= 1)
	{
		int inner{ 5 };
		while (inner >= 1){
			if (inner > counter){
				std::cout << 'x';
				--inner;
			}
			else{
				std::cout << inner--;
			}
		}
		++counter;
		std::cout << '\n';
		--outer;
	} // inner destroyed here
	
	return 0;
} 
