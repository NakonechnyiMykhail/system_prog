#include "University.h"
#include <iostream>
#include <iomanip>

University::University() 
	: m_name(""), m_year(0), m_students()
{}
University::University(const std::string& name) 
	: m_name(name), m_year(0), m_students()
{}
University::University(std::vector<Student> students) 
	: m_name(""), m_year(0), m_students(students)
{}
University::University(const std::string& name, std::vector<Student> students) 
	: m_name(name), m_year(0), m_students(students)
{}
University::University(const std::string& name, int year)
	: m_name(name), m_year(year), m_students()
{}
University::University(const std::string& name, int year, std::vector<Student> students)
	: m_name(name), m_year(year), m_students(students)
{}
University::~University(){}
void University::AddStudent(Student* student) 
{
	m_students.push_back(*student);
}
void University::SetName(const std::string& name) 
{
	this->m_name = name;
}
std::string University::GetName()
{
	return m_name;
}
void University::SetYear(int year)
{
	this->m_year = year;
}
int University::GetYear()
{
	return m_year;
}
void University::ShowInformation()
{
	std::cout << "========================================================================================" << std::endl;
	std::cout << "University Information: " << std::endl;
	std::cout << std::setw(5) <<
		"Name:\t\t" << m_name << '\t' <<
		"Year:\t\t" << m_year << '\t' <<
		"Students:\t\t" << m_students.size() << '\t' <<
		std::endl;
	std::cout << "========================================================================================" << std::endl;
}
void University::ShowStudents()
{
	size_t count{ 0 };
	std::cout << "========================================================================================" << std::endl;
	std::cout << "Students Information: " << std::endl;
	for (auto& student : m_students)
	{
		std::cout << std::setw(5) <<
			"\u2116: "					<< count						<< '\t' <<
			"\tName:\t\t"			<< student.GetName()			<< '\t' <<
			"\tAge:\t\t"			<< student.GetAge()				<< '\t' <<
			"\tSpecialization:\t\t" << student.GetSpecialization()	<< '\t' <<
			std::endl;
		count++;
	}

	
	std::cout << "========================================================================================" << std::endl;
}