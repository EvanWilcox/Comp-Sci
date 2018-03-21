//Name: Evan Wilcox         Date: 10/8/2017
//Class CS1580              Dection: E
//Filename: students.cpp
//Desc:

#include <iostream>
#include <string>
using namespace std;

struct Student
{
  string m_name;
  int m_age;
  string m_major;
  float m_gpa;
};

//Desc: Prints greetin gto screen
//Pre:  None
//Post: Greeting is printed to screen
void greeting();

//Desc: Gets infromation of a student
//Pre:  None
//Post: returns student with user inputed info
Student getInformation();

//Desc: Prints student to screen
//Pre:  None
//Post: Student info is printed to screen
void printStudent(const Student student);


int main()
{
  const int MAX_STUDENTS = 10;
  int numStudents;

  greeting();
  
  do
  {
    cout << "How many students?: ";
    cin >> numStudents;
  } while(numStudents > 10 || numStudents < 1);

  Student students[MAX_STUDENTS];

  for(int i = 0;i < numStudents;i++)
  {
    students[i] = getInformation();
    cout << endl;
  }

  for(int i = 0;i < numStudents;i++)
  {
    printStudent(students[i]);
    cout << endl;
  }
  
  return 0;
}

void greeting()
{
  cout << "Hello!" << endl;
}

Student getInformation()
{
  //creates new student
  Student student;
  //sets new students info
  cout << "Enter name: ";
  cin >> student.m_name;
  cout << "Enter age: ";
  cin >> student.m_age;
  cout << "Enter major: ";
  cin >> student.m_major;
  cout << "Enter GPA: ";
  cin >> student.m_gpa;
  //returns new student
  return student;
}

void printStudent(const Student student)
{
  //prints students info
  cout << "Student Info: " << endl;
  cout << "\tName: " << student.m_name << endl;
  cout << "\tAge: " << student.m_age << endl;
  cout << "\tMajor: " << student.m_major << endl;
  cout << "\tGPA: " << student.m_gpa << endl;
}
