#include <iostream>
#include "securityStudent.h"
using std::cout;

SecurityStudent::SecurityStudent()
{
	setDegreeProgram(SECURITY);
}

SecurityStudent::SecurityStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int* daysInCourse, Degree  degreeProgram) : Student(studentID, firstName, lastName, emailAddress, age, daysInCourse)
{
	setDegreeProgram(SECURITY);
}

Degree SecurityStudent::getDegreeProgram()
{
	return SECURITY;
}

void SecurityStudent::setDegreeProgram(Degree NETWORKING)
{
	this->degreeProgram = SECURITY;
}

void SecurityStudent::print()
{
	this->Student::print();
	cout << "SECURITY" << "\n";
}

SecurityStudent::~SecurityStudent()
{
	~Degree();
	delete this;
}
