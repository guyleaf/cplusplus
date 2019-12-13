#include "ScienceStudent.h"

ostream& operator<<(ostream& out, const ScienceStudent& scienceStudent)
{
    out << std::endl << (Student)scienceStudent;

    if (scienceStudent._gender == "Male")
        out << "He ";
    else if (scienceStudent._gender == "Female")
        out << "She ";

    out << "is majoring in " << scienceStudent._department << ".";
    return out;
}

ScienceStudent::ScienceStudent(string name, string id, string gender, string university, string department) : Student(name, id, gender, university)
{
    _department = department;
}