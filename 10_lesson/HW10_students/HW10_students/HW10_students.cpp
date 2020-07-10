// HW9_students.cpp :   University and Students.
// author:              Nakonechnyi Mikhail
// date:                10.07.20
// version:             1.0
// description of homework task:
// Реализовать классы University и Student.У студента поля Name, age, specialization и 
// конструктор, который инициализирует класс студента.У университета метод AddStudent(Student* student)
// Студентов в университете можете сохранять любым удобным способом )

#include <iostream>
#include "Student.h"
#include "University.h"

int main()
{

	Student stud1("Mike", 26, "engineer");
	stud1.ShowInformation();

	University univ("Karazin KhNU", 1804);
	for (size_t i = 0; i < 10; i++)
	{
		univ.AddStudent(&stud1);
	}
	univ.ShowInformation();
	univ.ShowStudents();

	return 0;
}
