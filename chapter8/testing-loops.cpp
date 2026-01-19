#include <iostream>

namespace {
	[[maybe_unused]] void print_stack_four(){
		int outer { 5 };
		while (outer >= 1){

			int inner{ 5 };
			while (inner <= outer){
				std::cout << inner--;
			}

			std::cout << '\n';
			--outer;
		}
	}

	[[maybe_unused]] void print_stack_three(){

		int outer{ 1 };
		while (outer <= 5){

			int inner{ 1 };
			while (inner <= outer){
				std::cout << inner++;
			}

			std::cout << '\n';
			++outer;
		}
	}

	[[maybe_unused]] void print_stack_two(int count){

		int outer{ count };
		while (outer >= 1){

			int inner{ 1 };
			while (inner <= outer){
				std::cout << inner++;
			}

			std::cout << '\n';
			--outer;
		}
	}

	[[maybe_unused]] void print_stack_one(int count){

		int outer{ count };
		while (outer >= 1){ // Loop between count and 1
			//
			int inner{ outer };
			while (inner >= 1){
				std::cout << inner;
				--inner;
			}

			std::cout << '\n';
			--outer;
		} // inner destroyed here
	}

	[[maybe_unused]] void looping_two(){
		for (int x{ 0 }, y{ 9 }; x < 10; ++x, --y){
			std::cout << x << ' ' << y << '\n';
		}
	}
}

int main(){
//	print_stack_one(5);
//	print_stack_two(5);
//	print_stack_three();
//	print_stack_four();
	funcs::looping_two();

	return 0;
}
