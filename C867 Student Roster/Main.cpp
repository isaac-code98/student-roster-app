#include <iostream>
#include <string>

#include "student.h"
#include "roster.h"
#include "degree.h"

using namespace std;

int main()
{
	cout << "Course: C867" << endl;
	cout << "Language: C++" << endl;
	cout << "Student ID: 001230140" << endl;
	cout << "Name: Isaac Kwong" << '\n' << endl;

	// Create an instance of the Roster class 
	Roster classRoster;

	// Create a constant variable int of numStudents that will be used as the for-loop constrainer to loop through the studentData
	const int numStudents = 5;

	// Create studentData table array with personal information as the last item
	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Isaac,Kwong,ikwong@wgu.edu,24,10,15,24,SOFTWARE"
	};

	// Calling parse method to parse and add each student to classRoster
	cout << "Parsing and populating classRoster... " << endl;
	for (int i = 0; i < numStudents; i++) {
		classRoster.parse(studentData[i]);
	}

	// Calling printAll method
	classRoster.printAll();

	// Calling printInvalidEmails method
	classRoster.printInvalidEmails();

	// Calling printAverageDaysInCourse method
	cout << "Displaying average days per course for each Student: " << endl;
	for (int i = 0; i < numStudents; i++) {
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentId());
	}

	// Calling printbyDegreeProgram method that will print only students in SOFTWARE degree program
	classRoster.printByDegreeProgram(SOFTWARE);

	// Calling remove method on student ID of A3 from classRoster
	classRoster.remove("A3");

	// Calling printAll method again
	classRoster.printAll();

	// Calling remove method on same student ID, won't work, instead prints student not found 
	classRoster.remove("A3");

	// When we exit, deconstructors called automatically 
	return 0;
}
