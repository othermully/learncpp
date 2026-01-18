#include <iostream>

int main(){
	char c{ 'a' };
	while (c <= 'z'){
		std::cout << static_cast<int>(c) << ' ' << c << '\n';
		++c;
	}
	return 0;
}
