#include <iostream>
#include <string>
#include <string_view>

#define PASS

namespace player {
	int health { 100 };
	int attack { 1 };
	std::string name{};
}

void increaseAttack (int &playerAttack){
	playerAttack += 1;
}

void fightSequence(int &playerAttack, int &enemyAttack, std::string_view enemyName){
	PASS;
}

int main(){
	using namespace player;
	std::cout << "Enter your name: ";
	std::getline(std::cin >> std::ws, name);
	std::cout << "Welcome " << name << "!\n";

	std::cout << "You currently have " << health << " HP.\n";
	std::cout << "You current do " << attack << " DMG.\n";

	increaseAttack(attack);
	std::cout << "After increasing your attack, you now do " << attack << " DMG.\n";

	return 0;;
}
