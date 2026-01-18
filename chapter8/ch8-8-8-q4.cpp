// Using while loops and if statements - produce the following output:
//        1
//      2 1
//    3 2 1
//  4 3 2 1
//5 4 3 2 1 

#include <iostream>

int main(){

	int outer { 5 };
	while (outer >= 1)
	{
		
		int inner { 5 };
		while (inner >= 1)
		{

			if (inner >= outer)
				std::cout << ' ';
			else
			{
				std::cout << inner;
				--inner;
			}

			std::cout << '\n';
			--outer;
		}

	}
	return 0;
} 
