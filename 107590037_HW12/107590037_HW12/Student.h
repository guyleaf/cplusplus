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
    //初始化學生資料
    Student(string name, string id, string gender, string university);
protected:
    //名字
    string _name;
    //學號
    string _id;
    //性別
    string _gender;
    //就讀大學
    string _university;
};
#endif