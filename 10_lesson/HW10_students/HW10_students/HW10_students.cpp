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

	// =======================================================
	Student* stud = new Student("Mike", 20, "dev");
	University univ1("KhNURE", 1904);
	univ1.AddStudent2(stud);
	univ1.ShowInformation2();
	univ1.ShowStudents2();

	return 0;
}
