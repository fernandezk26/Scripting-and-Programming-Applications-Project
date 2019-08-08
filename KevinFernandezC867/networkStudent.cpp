#include <iostream>
#include "networkStudent.h"
using std::cout;

NetworkStudent::NetworkStudent()
{
	setDegreeProgram(NETWORK);
}

NetworkStudent::NetworkStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int* daysInCourse, Degree  degreeProgram) : Student(studentID, firstName, lastName, emailAddress, age, daysInCourse)

{
	setDegreeProgram(NETWORK);
}

Degree NetworkStudent::getDegreeProgram()
{
	return NETWORK;
}

void NetworkStudent::setDegreeProgram(Degree NETWORK)
{
	this->program = NETWORK;
}

void NetworkStudent::print()
{
	this->Student::print();
	cout << "NETWORK" << "\n";
}

NetworkStudent::~NetworkStudent()
{
	~Degree();
	delete this;
}
