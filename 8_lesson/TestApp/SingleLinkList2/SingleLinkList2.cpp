// SingleLinkList2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

struct Worker {
	std::string name;
	std::string position;
	int salary;
	Worker* next = nullptr;
};

int main()
{
	const char* positions[] = { "SEO", "Manager", "Developer", "QA" };
	const char* names[] = { "Dennis", "Anna", "Anton", "Artem" };
	const int personsCount = sizeof(names) / sizeof(names[0]);

	Worker* firstWorker = nullptr;
	Worker* curWorker = nullptr;

	for (size_t i = 0; i < personsCount; ++i) {
		Worker* worker = new Worker({ names[i], positions[i], rand() % 10000 + 500 });
		if (i == 0) {
			firstWorker = worker;
			curWorker = worker;
		}
		else {
			curWorker->next = worker;
			curWorker = worker;
		}
	}
	double avarageSalary{ 0.0 };
	for (Worker* curWorker = firstWorker; curWorker; curWorker = curWorker->next) {
		std::cout << "Name = " << curWorker->name << "\tposition = " <<
			curWorker->position << "\tsalary = " << curWorker->salary << std::endl;
		avarageSalary += curWorker->salary;
	}
	std::cout << "avarageSalary = " << avarageSalary / personsCount;

	delete firstWorker, curWorker;

	return 0;
}

