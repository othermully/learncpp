#include <iostream>

void printUpto(int outer){
	int inner{ 1 };
	while (inner <= outer){
		std::cout << inner << ' ';
		++inner;
	}
} // inner is destroyed here 

int main(){
	int outer{ 1 };
	while (outer <= 5){
		printUpto(outer);
		std::cout << '\n';
		++outer;
	}

	return 0;
}

