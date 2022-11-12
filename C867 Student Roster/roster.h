#pragma once
#ifndef roster_h
#define roster_h
#include "student.h"


class Roster {

public:

	// Initialize a classRosterArray of pointers numStudents
	int lastIndex = -1;
	const static int numStudents = 5;
	Student* classRosterArray[numStudents];

	// Methods of Roster
	void parse(string row);
	void add(string ID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
	void printAll();
	void printByDegreeProgram(DegreeProgram sProgram);
	void printInvalidEmails();
	void printAverageDaysInCourse(string studentId);
	void remove(string studentId);

	// Deconstructor
	~Roster();
};

#endif

