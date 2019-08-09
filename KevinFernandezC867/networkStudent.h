#pragma once
#include <string>
#include "degree.h"
#include "student.h"


class NetworkStudent : public Student {
public:
	NetworkStudent();

	NetworkStudent(string, string, string, string, int, int*, Degree);

	Degree getDegreeProgram();

	void setDegreeProgram(Degree networking);

	void print();


private:
	Degree program;

	~NetworkStudent();
};


