//
// Created by ubuntu on 20.06.24.
//

#include "student.h"

int Student::getRollNumber() const { return roll_number_; }

void Student::setRollNumber(int rollNumber) { roll_number_ = rollNumber; }

const std::string &Student::getName() const { return name_; }

void Student::setName(const std::string &name) { name_ = name; }

int Student::getMarks() const { return marks_; }

void Student::setMarks(int marks) { marks_ = marks; }

Student::Student(int rollNumber, const std::string &name, int marks)
    : roll_number_(rollNumber), name_(name), marks_(marks) {}
