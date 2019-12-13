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
    //��l�ƾǥ͸��
    Student(string name, string id, string gender, string university);
protected:
    //�W�r
    string _name;
    //�Ǹ�
    string _id;
    //�ʧO
    string _gender;
    //�NŪ�j��
    string _university;
};
#endif