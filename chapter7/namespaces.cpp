#include <iostream>

int doSomething(int x, int y){
	return x * y;
}

namespace foo{
	int doSomething(int x, int y){
		return x + y;
	}
}

namespace goo{
	int doSomething(int x, int y){
		return x - y;
	}
}

int main(){
	const int x { 5 };
	const int y { 1 };


	std::cout << goo::doSomething(x, y) << '\n';
	std::cout << foo::doSomething(x, y) << '\n';
	std::cout << ::doSomething(x, y) << '\n';

	return 0;
}
