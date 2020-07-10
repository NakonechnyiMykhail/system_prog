#pragma once
#include <string>

class Student
{
public:
	Student();
	Student(const std::string& name);
	Student(const std::string& name, int age);
	Student(const std::string& name, int age, const std::string& specialization);
	~Student();
	void					SetName(const std::string& name);
	std::string				GetName();
	void					SetAge(int age);
	int						GetAge();
	void					SetSpecialization(const std::string& specialization);
	std::string				GetSpecialization();
	void					ShowInformation();

private:
	std::string				m_name;
	int						m_age;
	std::string				m_specialization;
};

