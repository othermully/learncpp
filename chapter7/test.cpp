#include <iostream>


int main(){

	for (char c{ 'a' }; c <= 'e'; ++c)
	{
	      std::cout << c << '\n';
	      std::cout << static_cast<int>(c) << '\n';
	
	}

	return 0;
}
