#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <cstdlib>
#include <ctime>
#include <corecrt.h>

using namespace std;

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

static void NameLevel(std::string* name1, std::string* name2) {

	for (int i = 0; i < 1; i++) {


		PrintValue(*name1, i);
		PrintValue(*name2, i + 1);

	}
}

int main() {



	std::unique_ptr<std::string> pl1 = player1();
	std::unique_ptr<std::string> pl2 = player2();

	if (!pl1 || !pl2) {

		std::cout << "Not in Memory" << std::endl;
	}

	NameLevel(new string(*pl1), new string(*pl2));
	
	system("pause > 0");
	return 0;
}