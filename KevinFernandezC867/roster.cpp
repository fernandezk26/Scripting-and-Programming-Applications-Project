#include <iostream>
#include <sstream>
#include "roster.h"

using std::cout;
using namespace std;

Roster::Roster()
{
	this->maxSize = 0;
	this->lastIndex = -1;
	this->students = nullptr;
}

Roster::Roster(int maxSize)
{
	this->maxSize = maxSize;
	this->lastIndex = -1;
	this->students = new Student * [maxSize];
}

Student* Roster::getStudentAt(int index)
{
	return students[index];
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram) 
{
	int courseDays[3];
	courseDays[0] = daysInCourse1;
	courseDays[1] = daysInCourse2;
	courseDays[2] = daysInCourse3;
	addIndex++;

	if (degreeProgram == NETWORK) {
		classRosterArray[addIndex] = new NetworkStudent(studentID, firstName, lastName, emailAddress, age, courseDays, degreeProgram);
	}
	else if (degreeProgram == SOFTWARE)
	{
		classRosterArray[addIndex] = new SoftwareStudent(studentID, firstName, lastName, emailAddress, age, courseDays, degreeProgram);
	}
	else 
	{
		classRosterArray[addIndex] = new SecurityStudent(studentID, firstName, lastName, emailAddress, age, courseDays, degreeProgram);
	}
}

void Roster::printAll()
{
	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
		classRosterArray[i]->print();
	}
}

void Roster::printByDegreeProgram(int degreeProgram)
{

}

void Roster::printDaysInCourse(string studentID) 
{

}

void Roster::printInvalidEmails() 
{

}


void Roster::remove(string studentID) 
{

}





int main() {
	cout << "Scripting and Programming - Applications - C867 \n";
	cout << "C++ \n";
	cout << "000987606 \n";
	cout << "Kevin Fernandez \n\n";

	Roster classRoster;

	const string studentData[] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Kevin,Fernandez,kfern20@wgu.edu,15,20,90,30,SOFTWARE"
	};

	}

Roster::~Roster()
{
}
