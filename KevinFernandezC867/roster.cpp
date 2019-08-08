#include <iostream>
#include <sstream>
#include <string>
#include "student.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include "roster.h"

using std::cout;
using namespace std;

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree  degreeProgram)
{
	int courseDays[3];
	courseDays[0] = daysInCourse1;
	courseDays[1] = daysInCourse2;
	courseDays[2] = daysInCourse3;
	addIndex++;

	if (degreeProgram == NETWORK) {
		classRosterArray[addIndex] = new NetworkStudent(studentID, firstName, lastName, emailAddress, age, courseDays, degreeProgram);
		/*cout << "created Network Student : " << endl;*/
	}
	else if (degreeProgram == SOFTWARE)
	{
		classRosterArray[addIndex] = new SoftwareStudent(studentID, firstName, lastName, emailAddress, age, courseDays, degreeProgram);
		/*cout << "created Software Student :" << endl;*/
	}
	else 
	{
		classRosterArray[addIndex] = new SecurityStudent(studentID, firstName, lastName, emailAddress, age, courseDays, degreeProgram);
		
		/*cout << "created Security Student :" << endl;*/
	}
	//Outputs to test if add method works
	/*cout << studentID << ' ' << firstName << ' ' << lastName << ' ' << emailAddress << ' ' << age << ' ' << daysInCourse1 << ' ' << daysInCourse2 << ' ' << daysInCourse3 << ' ' << degreeProgram << endl;
*/
}



void Roster::printAll()
{
	for (int i = 0; i <= this->addIndex; i++) (this->classRosterArray)[i]->print();
}

void Roster::printByDegreeProgram(int degreeProgram)
{
	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++)
	{
		if (classRosterArray[i] != nullptr)
		{
			if (classRosterArray[i]->getDegreeProgram() == degreeProgram)
			{
				classRosterArray[i]->print();
			}
		}
	}
};

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
	Degree degree;
	string id, fname, lname, mail, temp;
	int age, d1, d2, d3;

	for (int i = 0; i < sizeof(studentData) / sizeof(studentData[i]); i++)
	{
		string input = studentData[i];
		istringstream ss(input);
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
		classRoster.add(id, fname, lname, mail, age, d1, d2, d3, degree);
	}
	
	classRoster.printAll();
	cout << endl; 
	classRoster.printByDegreeProgram(SOFTWARE);
}

Roster::~Roster()
{
}
