#include <iostream>
#include <string>
#include "roster.h"

using namespace std;

// We'll define the functions and the methods of the Roster class here

// Parse method to capture each piece of data in a particular student record and add to Roster
void Roster::parse(string studentData)
{
	int rightHS = studentData.find(",");
	string studentID = studentData.substr(0, rightHS);

	int leftHS = rightHS + 1;
	rightHS = studentData.find(",", leftHS);
	string firstName = studentData.substr(leftHS, rightHS - leftHS);

	leftHS = rightHS + 1;
	rightHS = studentData.find(",", leftHS);
	string lastName = studentData.substr(leftHS, rightHS - leftHS);

	leftHS = rightHS + 1;
	rightHS = studentData.find(",", leftHS);
	string email = studentData.substr(leftHS, rightHS - leftHS);

	leftHS = rightHS + 1;
	rightHS = studentData.find(",", leftHS);
	int age = stoi(studentData.substr(leftHS, rightHS - leftHS));

	leftHS = rightHS + 1;
	rightHS = studentData.find(",", leftHS);
	int daysInCourse1 = stoi(studentData.substr(leftHS, rightHS - leftHS));

	leftHS = rightHS + 1;
	rightHS = studentData.find(",", leftHS);
	int daysInCourse2 = stoi(studentData.substr(leftHS, rightHS - leftHS));

	leftHS = rightHS + 1;
	rightHS = studentData.find(",", leftHS);
	int daysInCourse3 = stoi(studentData.substr(leftHS, rightHS - leftHS));

	leftHS = rightHS + 1;
	DegreeProgram degreeprogram = SECURITY;
	if (studentData.substr(leftHS) == "SECURITY") {
		degreeprogram = SECURITY;
	}
	else if (studentData.substr(leftHS) == "NETWORK") {
		degreeprogram = NETWORK;
	}
	else {
		degreeprogram = SOFTWARE;
	}

	add(studentID, firstName, lastName, email, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeprogram);

}


// Add method to populate Roster with each individual student record
void Roster::add(string ID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {
	int daysToCompleteCourseArr[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	classRosterArray[++lastIndex] = new Student(ID, firstName, lastName, emailAddress, age, daysToCompleteCourseArr, degreeprogram);
}


// Method to accept a degreeProgram and parse through studentData to show only those that match
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	cout << "Displaying students by: " << degreeProgramStrings[degreeProgram] << endl;
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			classRosterArray[i]->print();
		}
	}
	cout << endl;
}


// Print invalid emails
void Roster::printInvalidEmails() {
	cout << "Displaying invalid emails:" << '\n' << endl;
	bool invalidEmail = false;
	for (int i = 0; i <= Roster::lastIndex; i++) {
		string isValidEmail = (classRosterArray[i]->getEmail());
		if ((isValidEmail.find('.') == string::npos || isValidEmail.find('@') == string::npos) || isValidEmail.find(' ') != string::npos) { //If email has '@' and "." then valid 
			{
				invalidEmail = true;
				cout << isValidEmail << endl;
			}
		}
	}
	if (invalidEmail == false) std::cout << "No invalid student email addresses were found" << std::endl;
	cout << endl;

}


// Print average days in course
void Roster::printAverageDaysInCourse(string studentId) {
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (classRosterArray[i]->getStudentId() == studentId) {
			cout << "Student ID: " << classRosterArray[i]->getStudentId() << ", has an average of ";
			cout << (classRosterArray[i]->getDaysToCompleteCourseArr()[0] +
				classRosterArray[i]->getDaysToCompleteCourseArr()[1] +
				classRosterArray[i]->getDaysToCompleteCourseArr()[2]) / 3;

			cout << " days spent in a course." << endl;
		}
	}
	cout << endl;
}


// Print method to print all
void Roster::printAll() {
	cout << "Displaying all students:" << endl;
	for (int i = 0; i <= Roster::lastIndex; i++) {
		Roster::classRosterArray[i]->print();
	}
	cout << "\n";
}


// Remove a student 
void Roster::remove(string studentId) {
	cout << "Attempting to remove Student: " << studentId << ":" << endl;

	bool removed = false;

	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (classRosterArray[i]->getStudentId() == studentId) {
			removed = true;
			if (i < numStudents - 1) {
				Student* temp = classRosterArray[i];
				classRosterArray[i] = classRosterArray[numStudents - 1];
				classRosterArray[numStudents - 1] = temp;
			}
			Roster::lastIndex--;
		}
	}
	if (removed) {
		cout << "Student " << studentId << " was removed from Roster." << endl;
	}
	else {
		cout << "Student " << studentId << " was not found in Roster." << endl;
	}

	cout << endl;
}


// Deconstructor to release allocated memory
Roster::~Roster() {
	for (int i = 0; i < numStudents; i++) {
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}

