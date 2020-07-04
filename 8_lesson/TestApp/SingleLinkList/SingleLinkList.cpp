// SingleLinkList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

struct Worker {
	std::string name;
	std::string position;
	int salary{ 0 };
	//Worker* next = nullptr;
};

struct Node {
	Worker worker;
	Node* next = nullptr;
	//int i;
};

int main() {
	//int arr[10]{ 10 };
	const char* positions[] = { "SEO", "Man", "Dev", "QA" }; //"SEO", "Manager", "Developer", "QA"
	const char* names[] = { "Dennis", "Anna", "Anton", "Artem" };
	const int personsCount = sizeof(names) / sizeof(names[0]);

	Node* firstNode = nullptr;
	Node* curNode = nullptr;

	for (size_t i = 0; i < personsCount; ++i) {
		Node* node = new Node({
			{ names[i], positions[i], rand() % 10000 + 500 }, nullptr });

		//node->worker.name = "Mike";
		//node->worker.position = "Game";
		//node->worker.salary = 12000;

		if (!firstNode) { // OR (firstNode == nullptr) OR (i == 0) 
			firstNode = node;
			curNode = node;
		}
		else {
			curNode->next = node;
			curNode = node;
		}
	}
	double avarageSalary{ 0.0 };

	// null == false | not null = true
	//for (Node* curNode = firstNode; curNode != nullptr; curNode = curNode->next) {
	for (Node* curNode = firstNode; curNode; curNode = curNode->next) {
		//int i = curNode->i; // value 
		//int* pi = &curNode->i; // pointer to i (address)

		const Worker* worker = &curNode->worker; // OR &(curNode->worker) OR(*curNode).worker;
		std::cout << "Name = " << worker->name << "\tposition = " <<
			worker->position << "\tsalary = " << worker->salary << std::endl;
		//std::cout << "Name = " << curNode->worker.name << "\tposition = " <<
		//	curNode->worker.position << "\tsalary = " << curNode->worker.salary << std::endl;
		//avarageSalary += curNode->worker.salary;
		avarageSalary += worker->salary;
	}
	std::cout << "avarageSalary = " << avarageSalary / personsCount;

	return 0;
}
