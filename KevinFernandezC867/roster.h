#pragma once
#include "Student.h"
#include <array>
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"

const string studentData[] =
{
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Kevin,Fernandez,kfern20@wgu.edu,15,20,90,30,SOFTWARE"
};

class Roster {
public:



	void printAll();
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree  degreeProgram);
	void remove(string studentID);
	void printByDegreeProgram(int degreeProgram);
	void printDaysInCourse(string studentID);
	void printInvalidEmails();
	int addIndex = -1;

	~Roster();

private:

	int lastIndex;
	int maxSize;
	Student* students;

	// Declaring array of pointers
	Student* classRosterArray[5] = { nullptr, nullptr, nullptr, nullptr, nullptr };
};