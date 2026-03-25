#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <cstdlib>
#include <ctime>

using namespace std;

static std::unique_ptr<std::string> ptrName() {

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



int main() {

	std::unique_ptr<std::string> name = ptrName();

	if (!name) {

		std::cout << "Not in Memory" << std::endl;
	}

	else {
		
		std::cout << *name << std::endl;
	}

	system("pause > 0");
	return 0;
}