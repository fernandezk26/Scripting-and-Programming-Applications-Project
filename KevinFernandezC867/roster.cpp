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

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree program) 
{
	int courseDays[3];
	courseDays[0] = daysInCourse1;
	courseDays[1] = daysInCourse2;
	courseDays[2] = daysInCourse3;
	addIndex++;

	if (program == NETWORK) {
		classRosterArray[addIndex] = new NetworkStudent(studentID, firstName, lastName, emailAddress, age, courseDays, program);
	}
	else if (program == SOFTWARE)
	{
		classRosterArray[addIndex] = new SoftwareStudent(studentID, firstName, lastName, emailAddress, age, courseDays, program);
	}
	else 
	{
		classRosterArray[addIndex] = new SecurityStudent(studentID, firstName, lastName, emailAddress, age, courseDays, program);
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
	int age, d1, d2, d3;

	
	istringstream ss(r1);
	string token;
	Degree degree;

	for (int i = 0; i < 10; i++)
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
			age = stoi(token);
		}
		if (i == 5)
		{
			d1 = stoi(token);
			
		}
		if (i == 6)
		{
			d2 = stoi(token);
		}
		if (i == 7)
		{
			d3 = stoi(token);
		}
		if (i == 8)
		{
			if (token == "SECURITY")
			{
				degree = SECURITY;
			}
			else if (token == "NETWORK")
			{
				degree = NETWORK;
			}
			else if (token == "SOFTWARE")
			{
				degree = SOFTWARE;
			}
		}

	}
	//ut << id << ' ' << fname << ' ' << lname << ' ' << mail << ' ' << age << ' ' << d1 << ' ' << d2 << ' ' << d3 << ' ' << degree << endl << endl;
	classRoster.add(id, fname, lname, mail, age, d1, d2, d3, degree);

	classRoster.printAll();
}

Roster::~Roster()
{
}
