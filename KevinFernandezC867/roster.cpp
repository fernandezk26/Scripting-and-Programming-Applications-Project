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
	for (int i = 0; i <= this->lastIndex; i++) (this->students)[i]->print();
}

void Roster::printByDegreeProgram(int degreeProgram)
{
	cout << "Printing Students of type " << degreeStrings[degreeProgram] << endl;
	for (int i = 0; i <= lastIndex; i++) {
		if (this->students[i]->getDegreeProgram() == degreeProgram) this->students[i]->print();
	}
}

void Roster::printDaysInCourse(string studentID) 
{
	for (int i = 0; i < 5; i++) {
		if ((*classRosterArray[i]).getStudentID() == studentID) {
			int averageDays = 0;
			averageDays = ((*classRosterArray[i]).getDaysInCourse()[0] + (*classRosterArray[i]).getDaysInCourse()[1]
				+ (*classRosterArray[i]).getDaysInCourse()[2]) / 3;
			cout << "The average days it took the student with studentID: " << studentID << " to finish 3 courses: " << averageDays << '\n';
		}
	}
	cout << '\n';
}

void Roster::printInvalidEmails() 
{

}


void Roster::remove(string studentID) 
{
	bool studentFound = false;
	for (int i = 0; i <= lastIndex; i++)
	{
		if (this->students[i]->getStudentID() == studentID)
		{
			studentFound = true;
			delete this->students[i];
			this->students[i] = this->students[lastIndex];
			lastIndex--;
		}
	}
	return studentFound; //FIXME
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
