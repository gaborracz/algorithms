#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student
{
private:
  int m_id;
  std::string m_name;

public:
  Student(int id, std::string name);
  Student(const Student& other);
  ~Student();

  int getID() const;
  std::string getName() const;
};

std::ostream& operator<<(std::ostream& os, const Student& student);

#endif
