#pragma once
#include <string>
#include "degree.h"
using std::string;

class Student
{
public:
	const static int daysArraySize = 3;
	Student();//empty constructor
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], Degree program);//full constructor

private:
	string StudentID, FirstName, LastName, EmailAddress;
	int DaysInCourse[daysArraySize];//DaysInCourse will be an array of size 3
	int Age;
	Degree DegreeProgram;//The enumerated value: Security, networking or software.


public:
	//getters
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int* getDaysInCourse();
	int getAge();
	virtual Degree getDegreeProgram();//VIRTUAL; cannot instantiate a Book object

	//setters
	void setStudentId(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setDaysInCourse(int daysInCourse[]);
	void setDegreeProgram(Degree);

	virtual void print() = 0;

	//The destructor
	~Student();
};
