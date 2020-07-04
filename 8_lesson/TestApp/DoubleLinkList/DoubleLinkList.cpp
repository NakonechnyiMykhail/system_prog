// DoubleLinkList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

struct Worker {
	std::string name;
	std::string position;
	int salary{ 0 };

};

struct Node {
	Worker worker;
	Node* next = nullptr;
	Node* prev = nullptr;
};

int main() {

	const char* positions[] = { "SEO", "Man", "Dev", "QA" };
	const char* names[] = { "Dennis", "Anna", "Anton", "Artem" };
	const int personsCount = sizeof(names) / sizeof(names[0]);

	Node* firstNode = nullptr;
	Node* curNode = nullptr;

	for (size_t i = 0; i < personsCount; ++i) {
		Node* node = new Node({
			{ names[i], positions[i], rand() % 10000 + 500 }, nullptr, nullptr });

		if (!firstNode) { // OR (firstNode == nullptr) OR (i == 0) 
			firstNode = node;
			firstNode->prev = nullptr;
			firstNode->next = node;
			curNode = node;
		}
		else {
			curNode->prev = firstNode;
			curNode->next = node;
			curNode = node;
		}
	}
	double avarageSalary{ 0.0 };

	// print list
	for (Node* curNode = firstNode; curNode; curNode = curNode->next) {
		const Worker* worker = &curNode->worker; // OR &(curNode->worker) OR(*curNode).worker;
		std::cout << "Name = " << worker->name << "\tposition = " <<
			worker->position << "\tsalary = " << worker->salary << std::endl;
		avarageSalary += worker->salary;
	}
	std::cout << "avarageSalary = " << avarageSalary / personsCount;
	avarageSalary = 0.0;
	//delete
	int id{ 4 }, i{ 1 }; // id of Person = 1, 2, 3, 4 for this names ARRAY
	for (Node* curNode = firstNode; curNode; curNode = curNode->next) {
		const Worker* worker = &curNode->worker;

		if ((firstNode->prev == nullptr) && (id == i)) { // for first person
			std::cout << "\n1del Name = " << worker->name << std::endl;
			firstNode = curNode->next;
			firstNode->next->prev = nullptr;
			
		}
		else if ((id == i) && ((curNode->next != nullptr) || (curNode->prev != nullptr))) { // for middle person - if not first or not last
			std::cout << "\n2del Name = " << worker->name << std::endl;
			
			curNode->prev->next = curNode->next;
			curNode->next->prev = curNode->prev;
		}
		else if ((curNode->next->next == nullptr) && (id == (i + 1))) { // for last person
			std::cout << "\n3del Name = " << curNode->next->worker.name << std::endl;

			curNode->next = nullptr;
			break;
		}

		i++;
	}
	// print list
	for (Node* curNode = firstNode; curNode; curNode = curNode->next) {
		const Worker* worker = &curNode->worker; // OR &(curNode->worker) OR(*curNode).worker;
		std::cout << "Name = " << worker->name << "\tposition = " <<
			worker->position << "\tsalary = " << worker->salary << std::endl;
		avarageSalary += worker->salary;
	}

	std::cout << "avarageSalary = " << avarageSalary / personsCount;

	delete firstNode, curNode;

	return 0;
}
