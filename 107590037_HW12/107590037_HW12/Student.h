#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>

using std::ostream;
using std::string;

class Student
{
    friend ostream& operator<<(ostream& out, const Student& student);
public:
    Student(string name, string id, string gender, string university);
protected:
    string _name;
    string _id;
    string _gender;
    string _university;
};
#endif