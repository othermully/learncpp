/* This program calculates your daily calorie intake requirements based on sex, weight, age and height */
#include <iomanip>
#include <iostream>
#include <string>
#include <string_view>

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
	double kg { lbs / 2.205 };
	std::cout << lbs << "lbs => " << kg << "kg" << '\n';
	return kg;
};

// Convert user input of feet to cm
double convert_feet_cm(double height_in_feet){
	double cm { height_in_feet * 30.8 }; // 30.8 cm in 1ft
	std::cout << height_in_feet << "ft => " << cm << "cm" << '\n';
	return cm;
};

double convert_feet_m(double height_in_feet){
	double meters { height_in_feet / 3.281 };
	std::cout << height_in_feet << "ft => " << meters << "m" << '\n';
	return meters;
};

double calc_bmi(double kg, double height_in_m){
	double meters_squared { height_in_m * height_in_m };
	std::cout << "Height meters squared: " << meters_squared << '\n';
	double bmi { kg / meters_squared };
	std::cout << kg << " / " << meters_squared << " = " << bmi << '\n';
	return bmi;
}

double calc_bmr(double cm, double kg, std::string_view sex, int age){
	double bmr{};

	// Mifflin-St Jeor Equation
	if (sex == "Male")
		bmr  = { (10 * kg) + (6.25 * cm) - (5 * age) + 5 };
	if (sex == "Female")
		bmr  = { (10 * kg) + (6.25 * cm) - (5 * age) - 161 };
	else
		std::cout << "Unknown sex" << '\n';

	return bmr;
}

std::string_view calc_bmi_class(double bmi){
	if (bmi < 18.5)
		return "Underweight";
	if ((bmi <= 25.9) && (bmi >= 18.5))
		return "Normal Weight";
	if ((bmi <= 29.9) && (bmi >= 25.0))
		return "Overweight";
	else
		return "High risk of heart problems.";
}

int main(){
	const int age		    { get_age() };
	const std::string sex       { get_sex() };
	const double height	    { get_height() };
	const double weight	    { get_weight() };
	const double bmr	    { calc_bmr(convert_feet_cm(height), convert_lbs_kg(weight),
				               sex, age) };
	const double bmi	    { calc_bmi(convert_lbs_kg(weight), convert_feet_m(height)) };

	const std::string_view bmi_class { calc_bmi_class(bmi) };

	std::cout << '\n';
	std::cout << "Age: " << age << '\n';
	std::cout << "Sex: " << sex  << '\n';
	std::cout << "Height: " << height << "ft" << '\n';
	std::cout << "Weight: " << weight << "lbs" << '\n';

	std::cout << '\n';
	std::cout << "BMR: " << bmr << '\n';
	std::cout << std::right << std::setw(15) << "Resting requirement: " << bmr * 1.2 << '\n';
	std::cout << std::right << std::setw(15) << "Light activity requirement: " << bmr * 1.375 << '\n';
	std::cout << std::right << std::setw(15) << "Moderate activity requirement: " << bmr * 1.55 << '\n';
	std::cout << std::right << std::setw(15) << "Very active requirement: " << bmr * 1.725 << '\n';

	std::cout << '\n';
	std::cout << "BMI: " << bmi << '\n';
	std::cout << "BMI Class: " << bmi_class << '\n';

	return 0;
} 
