// Best practice - Write programs in small well defined units (functions or classes), compile often, and test your code as you go
// Begin testing as soon as you write a non-trivial unit
#include <cassert> // for assert
#include <cstdlib> // for std::abort
#include <iostream>

bool isLowerVowel(char c)
{

	switch (c)
	{
	case 'a':
	case 'e':
	case 'o':
	case 'i':
	case 'u':
		return true;
	default:
		return false;
	}
}

// Program will halt on any failed test case
int testVowel(){

#ifndef NDEBUG
// if NDEBUG is defined, asserts are compiled out.
std::cerr << "Tests run with NDEBUG defined (asserts compiled out)";
std::abort();
#endif

	assert(isLowerVowel('a'));
	assert(isLowerVowel('e'));
	assert(!isLowerVowel('y'));
	assert(isLowerVowel('o'));
	assert(isLowerVowel('u'));
	assert(!isLowerVowel('b'));
	assert(!isLowerVowel('q'));
	assert(!isLowerVowel('z'));

	return 0;
}

int main(){
	testVowel();

	// If we reached here, all test must have passed
	std::cout << "All test succeeded\n";

	return 0;
}
