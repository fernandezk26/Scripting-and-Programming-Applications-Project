#include <iostream>
#include "softwareStudent.h"
using std::cout;

SoftwareStudent::SoftwareStudent()
{
	//This is the only work this constructor needs to do; the Book class will do the rest; NEAT, HUH?
	setDegreeProgram(SOFTWARE);
}

SoftwareStudent::SoftwareStudent(string studentID, string firstName, string lastName, string email, int age, int* daysInCourse, Degree degreeProgram)
{
	setDegreeProgram(SOFTWARE);
}

Degree SoftwareStudent::getDegreeProgram()
{
	return SOFTWARE;//Now we can do this - it's not virtual anymore
}

void SoftwareStudent::setDegreeProgram(Degree SOFTWARE)
{
	this->program = SOFTWARE;//Now we can do this - we know what kind of book it is
}

void SoftwareStudent::print()
{
	this->Student::print();//Call the print method from the Book class
	cout << "SOFTWARE" << "\n";//This is the only thing left to display
}

SoftwareStudent::~SoftwareStudent()
{
	~Degree();//Call the super destructor from Book in case it needs to release something
	delete this;
}
