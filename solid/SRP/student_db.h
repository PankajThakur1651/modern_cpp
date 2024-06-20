//
// Created by ubuntu on 20.06.24.
//

#ifndef MODERN_CPP_STUDENT_DB_H
#define MODERN_CPP_STUDENT_DB_H

#include "student.h"
#include <memory>
#include <vector>
class Student_db {
public:
  void add_student(std::shared_ptr<Student> &student);
  void update_students_roll_number();

  const std::vector<std::shared_ptr<Student>> &getStudents() const;

  void setStudents(const std::vector<std::shared_ptr<Student>> &students);

  void print_students_record();

private:
  std::vector<std::shared_ptr<Student>> students_;
};

#endif // MODERN_CPP_STUDENT_DB_H
