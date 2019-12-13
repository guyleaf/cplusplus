#include "Student.h"

/*
	�禡�\��: Student's operator <<

	�Ѽ�: out => ��X��Ƭy, student => �ǥ�

	�^�ǭ�: ��X��Ƭy
*/
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

/*
	�禡�\��: ��l�ƾǥ͸��

	�Ѽ�: name => �W�r, id => �Ǹ�, gender => �ʧO, university => �NŪ�j��

	�^�ǭ�: �d
*/
Student::Student(string name, string id, string gender, string university)
{
    _name = name;
    _id = id;
    _gender = gender;
    _university = university;
}