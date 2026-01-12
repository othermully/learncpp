/* This program calculates your daily calorie intake requirements based on sex, weight, age and height */
#include <iomanip>
#include <iostream>
#include <string>
#include <string_view>

constexpr double cm_per_foot  { 30.48 };
constexpr double lbs_per_kg   { 2.20462 };
constexpr double feet_per_m   { 3.281 };

double get_height(){
	std::cout << "Enter your height in feet (e.g. 5 7 = 5'7\": ";
	int feet{};
	int inches{};
	std::cin >> feet >> inches;

	double feet_to_inches { static_cast<double>(feet) * 12 };
	return (feet_to_inches + inches) / 12; // This returns the decimal value of someones height
}

double get_weight(){
	std::cout << "Enter your weight in lbs: ";
	double weight;
	std::cin >> weight;

	return weight;
}

int get_age(){
	std::cout << "Enter your age: ";
	int age{};
	std::cin >> age;

	return age;
}

std::string get_sex(){
	std::cout << "Enter your sex: ";
	std::string sex;
	std::cin >> sex;

	return sex;
}

// Convert user input of lbs ot kg
double convert_lbs_kg(double lbs){
	return lbs / lbs_per_kg;
}

// Convert user input of feet to cm
double convert_feet_cm(double height_in_feet){
	return height_in_feet * cm_per_foot;
}

double convert_feet_m(double height_in_feet){
	return height_in_feet / feet_per_m;
}

double calc_bmi(double kg, double height_in_m){
	double meters_squared { height_in_m * height_in_m };
	double bmi { kg / meters_squared };
	return bmi;
}

double calc_bmr(double cm, double kg, std::string_view sex, int age){
	double bmr{};

	// Mifflin-St Jeor Equation
	if (sex == "Male")
		bmr  = { (10 * kg) + (6.25 * cm) - (5 * age) + 5 };
	else if (sex == "Female")
		bmr  = { (10 * kg) + (6.25 * cm) - (5 * age) - 161 };
	else
		std::cout << "Unknown sex" << '\n';

	return bmr;
}

std::string_view calc_bmi_class(double bmi){
	if (bmi < 18.5)
		return "Underweight";
	if (bmi < 25.9) 
		return "Normal Weight";
	if (bmi < 29.9)
		return "Overweight";
	return "High risk of heart problems";
}

int main(){
	const int age		    { get_age() };
	const std::string sex       { get_sex() };
	const double height_ft	    { get_height() };
	const double weight_lbs	    { get_weight() };
	const double weight_kg      { convert_lbs_kg(weight_lbs) };
	const double height_cm	    { convert_feet_cm(height_ft) };
	const double height_m	    { convert_feet_m(height_ft) };
	const double bmr	    { calc_bmr(height_cm, weight_kg, sex, age) };
	const double bmi	    { calc_bmi(weight_kg, height_m) };

	const std::string_view bmi_class { calc_bmi_class(bmi) };

	std::cout << '\n';
	std::cout << "Age: " << age << '\n';
	std::cout << "Sex: " << sex  << '\n';
	std::cout << "Height: " << height_ft << "ft" << '\n';
	std::cout << "Weight: " << weight_lbs << "lbs" << '\n';

	std::cout << '\n';
	std::cout << "BMR: " << bmr << '\n';
	std::cout << std::left << std::setw(15) << "Resting requirement: " << bmr * 1.2 << '\n';
	std::cout << std::left << std::setw(15) << "Light activity requirement: " << bmr * 1.375 << '\n';
	std::cout << std::left << std::setw(15) << "Moderate activity requirement: " << bmr * 1.55 << '\n';
	std::cout << std::left << std::setw(15) << "Very active requirement: " << bmr * 1.725 << '\n';

	std::cout << '\n';
	std::cout << "BMI: " << bmi << '\n';
	std::cout << "BMI Class: " << bmi_class << '\n';

	return 0;
} 
