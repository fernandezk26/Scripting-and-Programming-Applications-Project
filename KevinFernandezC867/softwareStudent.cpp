#include <iostream>
#include "softwareStudent.h"
using std::cout;

SoftwareStudent::SoftwareStudent()
{
	setDegreeProgram(SOFTWARE);
}

SoftwareStudent::SoftwareStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int* daysInCourse, Degree  degreeProgram) : Student(studentID, firstName, lastName, emailAddress, age, daysInCourse)
{
	setDegreeProgram(SOFTWARE);
}

Degree SoftwareStudent::getDegreeProgram()
{
	return SOFTWARE;
}

void SoftwareStudent::setDegreeProgram(Degree SOFTWARE)
{
	this->program = SOFTWARE;
}

void SoftwareStudent::print()
{
	this->Student::print();
	cout << "SOFTWARE" << "\n";
}

SoftwareStudent::~SoftwareStudent()
{
	~Degree();
	delete this;
}
