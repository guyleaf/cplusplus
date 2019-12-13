#ifndef SCIENCE_STUDENT_H
#define SCIENCE_STUDENT_H

#include "Student.h"
#include <string>
#include <iostream>

using std::ostream;
using std::string;

class ScienceStudent : public Student
{
    friend ostream& operator<<(ostream& out, const ScienceStudent& scienceStudent);
public:
    //初始化學生資料
    ScienceStudent(string name, string id, string gender, string university, string department);
private:
    //科系
    string _department;
};
#endif
