#include <iostream>
#include "networkStudent.h"
using std::cout;

NetworkStudent::NetworkStudent()
{
	//This is the only work this constructor needs to do; the Book class will do the rest; NEAT, HUH?
	setDegreeProgram(NETWORK);
}

NetworkStudent::NetworkStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int* daysInCourse, Degree  degreeProgram) : Student(studentID, firstName, lastName, emailAddress, age, daysInCourse)

{
	setDegreeProgram(NETWORK);
}

Degree NetworkStudent::getDegreeProgram()
{
	return NETWORK;//Now we can do this - it's not virtual anymore
}

void NetworkStudent::setDegreeProgram(Degree NETWORK)
{
	this->program = NETWORK;//Now we can do this - we know what kind of book it is
}

void NetworkStudent::print()
{
	this->Student::print();//Call the print method from the Book class
	cout << "NETWORK" << "\n";//This is the only thing left to display
}

NetworkStudent::~NetworkStudent()
{
	~Degree();//Call the super destructor from Book in case it needs to release something
	delete this;
}
