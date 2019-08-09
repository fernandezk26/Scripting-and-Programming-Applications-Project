#include <iostream>
#include <sstream>
#include <string>
#include "student.h"
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
	for (int i = 0; i <= addIndex; i++)
	{
		if (classRosterArray[i] != nullptr)
		{
			(classRosterArray)[i]->print();
		}
	}
}

void Roster::printByDegreeProgram(int degreeProgram)
{
	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++)
	{

		if (degreeProgram == classRosterArray[i]->getDegreeProgram())
		{
			classRosterArray[i]->print();
		}
	}
};

void Roster::printDaysInCourse(string studentID) 
{
	bool found = false;
	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++)
	{
		if (studentID == classRosterArray[i]->getStudentID())
		{
			found = true;
			int * days = classRosterArray[i]->getDaysInCourse();
			//outputting that the values are iterated through and assigned properly
			/*cout << days[0] << endl;
			cout << days[1] << endl;
			cout << days[2] << endl;*/
			cout << "Average days in course for the ID " << studentID << " is " << (days[0] + days[1] + days[2]) / 3 << endl;
		}
	}
}

void Roster::printInvalidEmails() 

{
	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++)
	{
		string mail = classRosterArray[i]->getEmailAddress();
		//testing getEmailAddress function access
		//cout << mail;

		if ((mail.find(' ') != std::string::npos) || (mail.find('@') == std::string::npos) || (mail.find('.') == std::string::npos))
		{
			cout << mail << endl;
		}
		else
		{
			break;
		}
	}
}


void Roster::remove(string studentID) 
{	


	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++)
	{
		//testing to see how to access studentID
		/*string test = classRosterArray[i]->getStudentID();
		cout << test;*/

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

	//testing how to access studentData[]
	//string r1 = studentData[0];
	//cout << r1 << endl;

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
				//testing to see if the data is being parsed and assigned properly
				//cout << id << ' ' << fname << ' ' << lname << ' ' << mail << ' ' << age << ' ' << d1 << ' ' << d2 << ' ' << d3 << ' ' << degree << endl;
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


	cout << "Printing Invalid emails" << endl;
	cout << "__________________________________________________________________________________________" << endl << endl;
	classRoster.printInvalidEmails();
	cout << "__________________________________________________________________________________________" << endl << endl << endl << endl;


	cout << "Printing average days in Course per student ID:" << endl;
	cout << "__________________________________________________________________________________________" << endl << endl;
	for (int i = 0; i < sizeof(classRoster.classRosterArray) / sizeof(classRoster.classRosterArray[i]); i++)
	{
		classRoster.printDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
	}
	cout << "__________________________________________________________________________________________" << endl << endl << endl << endl;


	cout << "Printing Students with the SOFTWARE degree type:" << endl << endl;
	cout << left << setw(5) << "ID" << left << setw(20) << "Full Name" << left << setw(25) << "Email" << left << setw(10) << "Age" << left << setw(18) << "Days in course" << left << setw(10) << "Degree Type" << endl;
	cout << "__________________________________________________________________________________________" << endl << endl;
	classRoster.printByDegreeProgram(SOFTWARE);
	cout << "__________________________________________________________________________________________" << endl << endl << endl << endl;


	cout << "Removing student with the ID matching A3:" << endl;
	cout << "__________________________________________________________________________________________" << endl << endl;
	classRoster.remove("A3");
	cout << "Student Removed" << endl;
	cout << "__________________________________________________________________________________________" << endl << endl << endl << endl;
	cout << "Removing student with the ID matching A3:" << endl;
	cout << "__________________________________________________________________________________________" << endl << endl;
	classRoster.remove("A3");
	cout << endl << "__________________________________________________________________________________________" << endl << endl;
	cout << endl << endl << endl << endl;

}

Roster::~Roster()
{
}
