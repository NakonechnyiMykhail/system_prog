#include "Student.h"
#include <iostream>
#include <iomanip>

Student::Student() 
	: m_name(""), m_age(0), m_specialization("")
{}
Student::Student(const std::string& name) 
	: m_name(name), m_age(0), m_specialization("")
{}
Student::Student(const std::string& name, int age) 
	: m_name(name), m_age(age), m_specialization("")
{}
Student::Student(const std::string& name, int age, const std::string& specialization) 
	: m_name(name), m_age(age), m_specialization(specialization)
{}
Student::~Student()
{}
void Student::SetName(const std::string& name) 
{
	this->m_name = name;
}
std::string Student::GetName()
{
	return m_name;
}
void Student::SetAge(int age) 
{
	this->m_age = age;
}
int Student::GetAge()
{
	return m_age;
}
void Student::SetSpecialization(const std::string& specialization) 
{
	this->m_specialization = specialization;
}
std::string Student::GetSpecialization()
{
	return m_specialization;
}
void Student::ShowInformation()
{
	std::cout << "========================================================================================" << std::endl;
	std::cout << "Student Information: " << std::endl;
	std::cout << std::setw(5) << 
		"Name:\t"			<< m_name				<< '\t' <<
		"Age:\t"				<< m_age				<< '\t' <<
		"Specialization:\t"	<< m_specialization		<< '\t' <<
		std::endl;
	std::cout << "========================================================================================" << std::endl;
}