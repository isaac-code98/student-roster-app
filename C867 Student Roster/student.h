#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"

using namespace std;
using std::cout;
using std::endl;


class Student {

	// Declaring private variables with respective data types 
private:
	string studentId;
	string firstName;
	string lastName;
	string email;
	int age;
	const static int courses = 3;
	int daysToCompleteCourseArr[courses];
	DegreeProgram degreeProgram;


public:
	// Constructor and deconstructor methods
	Student();
	Student(string studentId, string firstName, string lastName, string email, int age, int daysToCompleteCourseArr[], DegreeProgram degreeProgram);
	~Student();

	// Accessor (getter) methods 
	string getStudentId();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	const int* getDaysToCompleteCourseArr();
	DegreeProgram getDegreeProgram();

	// Mutator (setter) methods
	void setStudentId(string studentId);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string email);
	void setAge(int age);
	void setDaysToCompleteCourseArr(const int daysToCompleteCourseArr[]);
	void setDegreeProgram(DegreeProgram degreeProgram);

	// Print method 
	void print();

};

