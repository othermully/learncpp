#include <iostream>

double get_initial_height(){
	std::cout << "Enter the height of the tower in meters: ";
	double height{};
	std::cin >> height;
	return height;
}

double calc_height(double towerHeight, int seconds){
	float gravity { 9.8 };

	double fallen { (gravity * (seconds * seconds)) / 2.0 };
	double ballHeight { towerHeight - fallen };

	if (ballHeight < 0)
		return 0.0;

	return ballHeight;
}

void print_ball_height(double ballHeight, int seconds){

	if (ballHeight> 0)
		std::cout << "At " << seconds 
			  << ", the ball is at height: "
			  << ballHeight << " meters" << '\n';
	else
		std::cout << "At " << seconds << ", the ball is on the ground." << '\n';
}

void calc_and_print_ball_height(double towerHeight, int seconds){
	double ballHeight { calc_height(towerHeight, seconds) };
	print_ball_height(ballHeight, seconds);
}


int main(){
	double towerHeight{ get_initial_height() };

	calc_and_print_ball_height(towerHeight, 0);
	calc_and_print_ball_height(towerHeight, 1);
	calc_and_print_ball_height(towerHeight, 2);
	calc_and_print_ball_height(towerHeight, 3);
	calc_and_print_ball_height(towerHeight, 4);
	calc_and_print_ball_height(towerHeight, 5);

	return 0;

}
