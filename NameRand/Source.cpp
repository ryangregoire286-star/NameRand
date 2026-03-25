#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <ctime>

using namespace std;

class WindowTitle {

public:

	auto setTitle(std::string title) {

		return title;

	}

	auto setSpaceBetween() {

		return "\n";
	}

	void getTitle() {
		
		this->setSpaceBetween();
		std::cout << this->setTitle("Rand | Name Picker") << std::endl;
	}

};

struct Player {
	
	std::string playerX;
	std::string playerY;

};

static std::unique_ptr<std::string> player1() {

	std::vector<std::string> Names;
	Names.push_back("Ryan James");
	Names.push_back("Peter Johnson");
	Names.push_back("Joe Peterson");
	Names.push_back("Matthew Kyleton");

	srand(time_t(NULL));
	auto lengthName = rand() % 4;
	std::string n = Names[lengthName];

	std::unique_ptr<std::string> namePtr(new string(n));


	return namePtr;
}


static std::unique_ptr<std::string> player2() {

	std::vector<std::string> Names;
	Names.push_back("Ryan James");
	Names.push_back("Peter Johnson");
	Names.push_back("Joe Peterson");
	Names.push_back("Matthew Kyleton");

	srand(time(NULL));
	auto lengthName = rand() % 4;
	std::string n = Names[lengthName];

	std::unique_ptr<std::string> namePtr(new string(n));


	return namePtr;
}

static void PrintValue(std::string name, int index) {

	std::cout << "Player " << index << " " << name << std::endl;
}

class Timer {

public:
	
	auto getSeconds(long sec) {

		return sec;
	}

	void getTimerCurrent(long sec) {
		std::this_thread::sleep_for(std::chrono::milliseconds(this->getSeconds(sec)));
	}

};

static void NameLevel(std::string* name1, std::string* name2) {

	for (int i = 0; i < 1; i++) {

		WindowTitle window{};
		Timer timer;
		Player player;
		
		player.playerX = *name1;
		player.playerY = *name2;

		window.setSpaceBetween();
		timer.getTimerCurrent(300 * 10);
		PrintValue(player.playerX, i);

		window.setSpaceBetween();
		timer.getTimerCurrent(500 * 10);
		PrintValue(player.playerY, i + 1);

	}
}

int main() {

	WindowTitle window{};
	std::unique_ptr<std::string> pl1 = player1();
	std::unique_ptr<std::string> pl2 = player2();


	if (!pl1 || !pl2) {

		std::cout << "Not in Memory" << std::endl;
	}

	if (new string(*pl1) == new string(*pl2)) {

		std::cout << "Same Name..." << std::endl;
	}

	else {


		window.getTitle();
		std::cout << window.setSpaceBetween();

		NameLevel(new string(*pl1), new string(*pl2));
	}
	
	system("pause > 0");
	return 0;
}