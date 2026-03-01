#include "student.h"
#include <iostream>

Student::Student(int id, std::string name)
  : m_id{id}, m_name{name}
{
  std::cout << "Student with ID: " << m_id << " constructed." << std::endl;
}

Student::Student(const Student& other)
  : m_id{other.m_id}
  , m_name{other.m_name}
{
  std::cout << "Student with ID: " << m_id << " copied." << std::endl;
}

Student::~Student()
{
  std::cout << "Student with ID: " << m_id << " destroyed." << std::endl;
}

int Student::getID() const { return m_id; }

std::string Student::getName() const { return m_name; }

std::ostream& operator<<(std::ostream& os, const Student& student)
{
  os << "Name: " << student.getName() << ", ID: " << student.getID();
  return os;
}
