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
	Degree degreeProgram;

	const string studentData[] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Kevin,Fernandez,kfern20@wgu.edu,15,20,90,30,SOFTWARE"
	};


	string r1, r2, r3, r4, r5;
	r1 = studentData[0];
	r2 = studentData[1];
	r3 = studentData[2];
	r4 = studentData[3];
	r5 = studentData[4];

	string id, fname, lname, mail, temp;
	enum Degree degree;
	int age = 0, d1 = 0, d2 = 0, d3 = 0;
	
	istringstream ss(r1);
	string token;

	for (int i = 0; i < 9; i++)
	{
		getline(ss, token, ',');
		if (i == 0)
		{
			id = token;
		}
		if (i == 1)
		{
			fname = token;
		}
		if (i == 2)
		{
			lname = token;
		}
		if (i == 3)
		{
			mail = token;
		}
		if (i == 4)
		{
			temp = token;
			stringstream AGE(temp);
			int age = 0;
			AGE >> age;
		}
		if (i == 5)
		{
			temp = token;
			stringstream D1(temp);
			int d1 = 0;
			D1 >> d1;

		}
		if (i == 6)
		{
			temp = token;
			stringstream D2(temp);
			int d2 = 0;
			D2 >> d2;
		}
		if (i == 7)
		{
			temp = token;
			stringstream D3(temp);
			int d3 = 0;
			D3 >> d3;
		}
		if (i == 8)
		{
			temp = token;
			if (temp == "SECURITY")
			{
				degreeProgram = SECURITY;
			}
			cout << temp << endl;
	
		}
		classRoster.add(id, fname, lname, mail, age, d1, d2, d3, degree);
	}
	classRoster.printAll();


}

Roster::~Roster()
{
}
