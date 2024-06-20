//
// Created by ubuntu on 20.06.24.
//

#include "student_db.h"
#include <algorithm>

void Student_db::add_student(std::shared_ptr<Student> &student) {
  students_.push_back(student);
}

const std::vector<std::shared_ptr<Student>> &Student_db::getStudents() const {
  return students_;
}

void Student_db::setStudents(
    const std::vector<std::shared_ptr<Student>> &students) {
  students_ = students;
}

void Student_db::update_students_roll_number() {
  for (auto const &student : students_) {
    student->setRollNumber(student->getRollNumber() + 100);
  }
}

void Student_db::print_students_record() {
  for (auto const &student : students_) {
    std::cout << "Roll number: " << student->getRollNumber()
              << ", Name: " << student->getName()
              << ", Marks: " << student->getMarks() << std::endl;
  }
}