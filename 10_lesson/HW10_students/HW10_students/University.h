#pragma once
#include <string>
#include <vector>
#include "Student.h"

class University
{
public:
	University();
	University(const std::string& name);
	University(std::vector<Student> students);
	University(const std::string& name, std::vector<Student> students);
	University(const std::string& name, int year);
	University(const std::string& name, int year, std::vector<Student> students);
	~University();

	void					AddStudent(Student* student);

	void					SetName(const std::string& name);
	std::string				GetName();
	void					SetYear(int year);
	int						GetYear();
	void					ShowInformation();
	void					ShowStudents();

private:
	std::string				m_name;
	int						m_year;
	std::vector<Student>	m_students;
};

