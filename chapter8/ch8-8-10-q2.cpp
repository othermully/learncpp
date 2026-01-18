#include <iostream>

static int sumTo(int value){
	int sum{};

	for (int i{ 0 }; i <= value; ++i){
		sum += i;
	}
	return sum;

}

int main(){
	std::cout << sumTo(5) << '\n';
	return 0;
}
