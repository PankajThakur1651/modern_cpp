#include "student.h"
#include "student_db.h"
using namespace std;

int main() {
  auto first_student = std::make_shared<Student>(1, "first_student", 1000);
  auto second_student = std::make_shared<Student>(2, "second_student", 1001);

  Student_db db;

  db.add_student(first_student);
  db.add_student(second_student);
  db.update_students_roll_number();

  db.print_students_record();
}