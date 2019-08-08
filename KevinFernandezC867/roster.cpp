#include <iostream>
#include <sstream>
#include <string>
#include "student.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include "roster.h"
#include<iomanip>
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
			if (degreeProgram == classRosterArray[i]->getDegreeProgram())
			{
				classRosterArray[i]->print();
			}
		}
	}
};

//printing the average days it took to complete 3 courses
void Roster::printDaysInCourse(string studentID) 
{

}

void Roster::printInvalidEmails() 
{
	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++)
	{
		bool valid = true;
		
	}
}


void Roster::remove(string studentID) 
{
	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++)
	{
		if (classRosterArray[i] == nullptr)
		{
			cout << "ERROR: this student ID is not found";
		}
		else if (classRosterArray[i]->getStudentID() == studentID)
		{
			classRosterArray[i] = nullptr;
		}
	}
}

int main() {
	cout << "Scripting and Programming - Applications - C867" << endl << endl;
	cout << "C++" << endl;
	cout << "000987606" << endl;
	cout << "Kevin Fernandez" << endl;
	cout << "__________________________________________________________________________________________" << endl << endl << endl;

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
	
	cout << "Printing Class Roster:" << endl << endl;
	cout << left << setw(5) << "ID" << left << setw(20) << "Full Name" << left << setw(25) << "Email" << left << setw(10) << "Age" << left << setw(18) << "Days in course" << left << setw(10) << "Degree Type" << endl;
	cout << "__________________________________________________________________________________________" << endl << endl;

	classRoster.printAll();
	cout << "__________________________________________________________________________________________" << endl << endl;
	cout << endl << endl;
	cout << "Printing Students with the SOFTWARE degree type:" << endl << endl;
	cout << left << setw(5) << "ID" << left << setw(20) << "Full Name" << left << setw(25) << "Email" << left << setw(10) << "Age" << left << setw(18) << "Days in course" << left << setw(10) << "Degree Type" << endl;
	cout << "__________________________________________________________________________________________" << endl << endl;
	classRoster.printByDegreeProgram(SOFTWARE);
	cout << "__________________________________________________________________________________________" << endl << endl;
	cout << "Removing student with the ID matching A3" << endl;
	classRoster.remove("A3");
	cout << "Student Removed" << endl << endl;
	cout << "Removing student with the ID matching A3" << endl;
	classRoster.remove("A3");
	cout << endl << "__________________________________________________________________________________________" << endl << endl;

}

Roster::~Roster()
{
}
