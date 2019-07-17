#pragma once
#include "Student.h"
#include <array>
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"

class Roster {
public:
	Roster();
	Roster(int maxSize);
	void printAll();
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram);
	void remove(string studentID);
	void printByDegreeProgram(int degreeProgram);
	void printDaysInCourse(string studentID);
	void printInvalidEmails();
	int addIndex = -1;

	~Roster();

private:

	int lastIndex;
	int maxSize;
	Student** students;

	// Declaring array of pointers
	Student* classRosterArray[5];
};