#pragma once
#include <iostream>
#include <string>
#include "student.h"

using namespace std;

// Define default constructor
Student::Student() {
	this->studentId = "";
	this->firstName = "";
	this->lastName = "";
	this->email = "";
	this->age = 0;
	for (int i = 0; i < courses; i++) {
		this->daysToCompleteCourseArr[i] = 0;
	}
	this->degreeProgram = DegreeProgram::SOFTWARE;
}

// Define constructor to use parameters passed in
Student::Student(string studentId, string firstName, string lastName, string email, int age, int daysToCompleteCourseArr[], DegreeProgram degreeProgram) {
	this->studentId = studentId;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	for (int i = 0; i < courses; i++) {
		this->daysToCompleteCourseArr[i] = daysToCompleteCourseArr[i];
	}
	this->degreeProgram = degreeProgram;
}

// Defining deconstructor
Student::~Student() {
	return;
}

// Defining getter methods 
string Student::getStudentId() {
	return this->studentId;
}

string Student::getFirstName() {
	return this->firstName;
}

string Student::getLastName() {
	return this->lastName;
}

string Student::getEmail() {
	return this->email;
}

int Student::getAge() {
	return this->age;
}

const int* Student::getDaysToCompleteCourseArr() {
	return this->daysToCompleteCourseArr;
}

DegreeProgram Student::getDegreeProgram() {
	return this->degreeProgram;
}


// Defining setter methods
void Student::setStudentId(string studentId) {
	this->studentId = studentId;
}

void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}

void Student::setLastName(string lastName) {
	this->lastName = lastName;
}

void Student::setEmail(string email) {
	this->email = email;
}

void Student::setAge(int age) {
	this->age = age;
}

void Student::setDaysToCompleteCourseArr(const int daysToComplete[]) {
	for (int i = 0; i < courses; i++) this->daysToCompleteCourseArr[i] = daysToComplete[i];
}

void Student::setDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
}

// Defining print method for each respective Student
void Student::print() {
	cout << "Student ID: " << this->studentId << '\t';
	cout << "First Name: " << this->firstName << '\t';
	cout << "Last Name: " << this->lastName << '\t';
	cout << "Email: " << this->email << '\t';
	cout << "Age: " << this->age << '\t';
	cout << "Days To Complete Course 1: " << this->daysToCompleteCourseArr[0] << '\t';
	cout << "Days To Complete Course 2: " << this->daysToCompleteCourseArr[1] << '\t';
	cout << "Days To Complete Course 3: " << this->daysToCompleteCourseArr[2] << '\t';
	cout << "Degree Program: " << degreeProgramStrings[this->getDegreeProgram()];
	cout << endl;
}

