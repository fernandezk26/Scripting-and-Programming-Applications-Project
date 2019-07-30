#include <iostream>
#include "securityStudent.h"
using std::cout;

SecurityStudent::SecurityStudent()
{
	//This is the only work this constructor needs to do; the Book class will do the rest; NEAT, HUH?
	setDegreeProgram(SECURITY);
}

SecurityStudent::SecurityStudent(string studentID, string firstName, string lastName, string email, int age, int* daysInCourse, Degree program)
{
	setDegreeProgram(SECURITY);
}

Degree SecurityStudent::getDegreeProgram()
{
	return SECURITY;//Now we can do this - it's not virtual anymore
}

void SecurityStudent::setDegreeProgram(Degree NETWORKING)
{
	this->degreeProgram = SECURITY;//Now we can do this - we know what kind of book it is
}

void SecurityStudent::print()
{
	this->Student::print();//Call the print method from the Book class
	cout << "SECURITY" << "\n";//This is the only thing left to display
}

SecurityStudent::~SecurityStudent()
{
	~Degree();//Call the super destructor from Book in case it needs to release something
	delete this;
}
