#include <iostream>
// Definitions of floating point variables:
float f;
double d;
long double ld;

int a { 5 }; 	// 5 Mean integer
double b { 5.0 }; // 5.0 is a floating point literal
float c { 5.0f }; // 5.0 is a floating point literal, f suffix means float type

int d { 0 }; // 0 is an integer
double e { 0.0 }; // 0.0 is a double

// By default, floating point literals default to type double. An 'f' suffix is used to denote a literal of type float

// Always make sure the type of your literals match the type of the variables they're being assigned to or used to initialize. Otherwise an unnecessary conversion will result, possibly with a loss of precision.

// std::cout has a default precision of 6, will truncate anything after that

int main(){
	std::cout << 5.0 << '\n'; // Prints 5 - 0 fractinal part gets removed when printing 
	std::cout << 6.7f << '\n'; // Prints 6.7
	std::cout << 987653.21 << '\n'; // Prints 9.87654e+06
	
	std::cout << 9.87654321f; // Prints 9.8754
	std::cout << 987.654321f; // Prints 987.654
	std::cout << 987654.321f; // Prints 987654
	std::cout << 9876543.21f; // Prints 987654e+006
	std::cout << 0.0000987654321f; // Prints 9.87654e-005
}

// Note that 9.87654e+006 is the same as 9.87654e6

// We can override the default precision that std::cout shows by using an output manipulator function named std::setprecisin(). Output manipulators alter how data is output, and are defined in the <iomanip> header

#include <iomanip>
void floating(){
	std::cout << std::setprecision(17); // Show 17 digits of precision
	std::cout <<
	3.33333333333333333333333333333333333333f; // 
	// f suffix means float - Outputs: 3.3333332538604736
	
	std::cout <<
	3.33333333333333333333333333333333333333; //
	// no suffix means double - Outputs: 3.3333333333333335
}

// Output manipulators are sticky - if you set them they will remain set
// Except for std::setw. Some IO operations reset std::setw , so std::setw should be used everytime it is needed

// Best practive to favor double over float unless space is at a premium, as the lack of precision in a float will often lead to inaccuracies

// Rounding errors make floating point comparisons tricky
// Be wary of using floating point numbers for financial or currency data

// NaN and Inf

void nan_inf(){
	double zero { 0.0 };
	double posinf { 5.0 / zero }; // Positive inf
	
	double neginf { -5.0 / zero }; // Negative inf
	
	double z1 { 0.0 / posinf }; // Positive zero
	double z2 { -0.0 / posinf } ; // Negative zero
	
	double nan { zero / zero }; // Not a Number (NaN) (Mathematically invalid)
}
