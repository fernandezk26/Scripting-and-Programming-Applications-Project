#pragma once
#include <string>
#include "degree.h"
#include "student.h"


class SecurityStudent : public Student {
public:
	SecurityStudent();

	SecurityStudent(string, string, string, string, int, int*, Degree);

	Degree getDegreeProgram();

	void setDegreeProgram(Degree Networking);

	void print();


private:
	Degree degreeProgram;

	//Destructor
	~SecurityStudent();
};


