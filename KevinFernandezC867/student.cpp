#include<iostream>
#include<iomanip>
#include "student.h"

Student::Student()
{
	this->StudentID = "";
	this->FirstName = "";
	this->LastName = "";
	this->EmailAddress = "";
	for (int i = 0; i < daysArraySize; i++) { this->DaysInCourse[i] = 0; }
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[])
{
	this->StudentID = studentID;
	this->FirstName = firstName;
	this->LastName = lastName;
	this->EmailAddress = emailAddress;
	this->Age = age;
	for (int i = 0; i < daysArraySize; i++) { this->DaysInCourse[i] = daysInCourse[i]; }
	setAge(age);
}

//getters
string Student::getStudentID()
{
	return StudentID;
}

string Student::getFirstName()
{
	return FirstName;
}

string Student::getLastName()
{
	return LastName;
}

string Student::getEmailAddress()
{
	return EmailAddress;
}

int Student::getAge()
{
	return Age;
}

int* Student::getDaysInCourse()
{
	return DaysInCourse;
}

Degree Student::getDegreeProgram()
{
	return Degree();
}

//setters 
void Student::setStudentId(string studentID)
{
	this->StudentID = studentID;
}

void Student::setFirstName(string firstName)
{
	this->FirstName = firstName;
}

void Student::setLastName(string lastName)
{
	this->LastName = lastName;
}

void Student::setEmailAddress(string emailAddress)
{
	this->EmailAddress = emailAddress;
}

void Student::setAge(int age)
{
	this->Age = age;
}

void Student::setDaysInCourse(int daysInCourse[])
{
	for (int i = 0; i < 3; i++) {
		daysInCourse[i] = daysInCourse[i];
	}
}

void Student::setDegreeProgram(Degree  degreeProgram)
{
	this->DegreeProgram = degreeProgram;
}


void Student::print()
{
	cout << left << setw(5) << StudentID;
	cout << left << setw(7) << FirstName;
	cout << left << setw(13) << LastName;
	cout << left << setw(25) << EmailAddress;
	cout << left << setw(10) << Age;
	cout << left << setw(6) << DaysInCourse[0];
	cout << left << setw(6) << DaysInCourse[1];
	cout << left << setw(6) << DaysInCourse[2];
}

Student::~Student()
{
}


