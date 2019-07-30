#include<iostream>
#include<iomanip>
#include "student.h"




Student::Student()//Empty constructor will set all to default values
{
	this->StudentID = "";
	this->FirstName = "";
	this->LastName = "";
	this->EmailAddress = "";
	for (int i = 0; i < daysArraySize; i++) this->DaysInCourse[i] = 0;

	//NOTE that neither Book constructor sets the BookType - the type of Book is not known
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], Degree program)
{
	this->StudentID = studentID;
	this->FirstName = firstName;
	this->LastName = lastName;
	this->EmailAddress = emailAddress;
	this->Age = age;
	for (int i = 0; i < daysArraySize; i++) this->DaysInCourse[i] = 0;
	this->DegreeProgram = program;
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

void Student::setDegreeProgram(Degree program)
{
	this->DegreeProgram = program;
}



//The print method displays all fields EXCEPT the book type! 
void Student::print()
{
	string degree;
	if (getDegreeProgram() == 0)
	{
		degree = "Security";
	}
	else if (getDegreeProgram() == 1)
	{
		degree = "Network";
	}
	if (getDegreeProgram() == 2)
	{
		degree = "Software";
	}

	cout << left << setw(5) << StudentID;
	cout << left << setw(20) << FirstName;
	cout << left << setw(20) << LastName;
	cout << left << setw(20) << EmailAddress;
	cout << left << setw(5) << Age;
	cout << left << setw(10) << DaysInCourse[0];
	cout << left << setw(10) << DaysInCourse[1];
	cout << left << setw(10) << DaysInCourse[2];
	cout << left << setw(10) << degree; 
}

Student::~Student()
{
}

//NOTE THIS 'ABSTRACT' CLASS SEEMS TO BE DOING A LOT OF WORK!  
//IT WON'T GO TO WASTE; THE DERIVED CLASSES WILL USE IT!
