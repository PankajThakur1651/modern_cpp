//
// Created by ubuntu on 20.06.24.
//

#ifndef MODERN_CPP_STUDENT_H
#define MODERN_CPP_STUDENT_H
#include <iostream>
#include <string>

// SRP: This principe means a software component should have one and only one
// reason to change
//  Cohesion: cohesion is a degree to which the various parts of the software
//  are related
// coupling: Coupling is defined as the level of interdependency between various
// software components
class Student {

private:
  int roll_number_;
  std::string name_;
  int marks_;

public:
  Student(int rollNumber, const std::string &name, int marks);

  const std::string &getName() const;

  void setName(const std::string &name);

  int getMarks() const;

  void setMarks(int marks);

  int getRollNumber() const;

  void setRollNumber(int rollNumber);
};

#endif // MODERN_CPP_STUDENT_H
