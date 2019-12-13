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
    //��l�ƾǥ͸��
    ScienceStudent(string name, string id, string gender, string university, string department);
private:
    //��t
    string _department;
};
#endif
