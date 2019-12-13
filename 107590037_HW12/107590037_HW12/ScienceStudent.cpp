#include "ScienceStudent.h"

/*
	�禡�\��: ScienceStudent's operator <<

	�Ѽ�: out => ��X��Ƭy, scienceStudent => �q����Ǩt���ǥ�

	�^�ǭ�: ��X��Ƭy
*/
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

/*
	�禡�\��: ��l�ƾǥ͸��

	�Ѽ�: name => �W�r, id => �Ǹ�, gender => �ʧO, university => �NŪ�j��, department => ��t

	�^�ǭ�: �L
*/
ScienceStudent::ScienceStudent(string name, string id, string gender, string university, string department) : Student(name, id, gender, university)
{
    _department = department;
}