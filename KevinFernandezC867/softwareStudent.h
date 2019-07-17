#pragma once
#include <string>
#include "degree.h"
#include "student.h"


class SoftwareStudent : public Student {
public:
	SoftwareStudent();

	SoftwareStudent(string, string, string, string, int, int*, Degree);

	Degree getDegreeProgram();

	void setDegreeProgram(Degree Software);

	void print();


private:
	Degree program;

	//Destructor
	~SoftwareStudent();
};


