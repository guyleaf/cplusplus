#include "Student.h"

ostream& operator<<(ostream& out, const Student& student)
{
    out << student._name << " is a student at " << student._university << ". ";

    if (student._gender == "Male")
        out << "His ";
    else if (student._gender == "Female")
        out << "Her ";

    out << "studentId is " << student._id << ". ";
    return out;
}

Student::Student(string name, string id, string gender, string university)
{
    _name = name;
    _id = id;
    _gender = gender;
    _university = university;
}