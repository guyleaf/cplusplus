#include "Student.h"

/*
	函式功能: Student's operator <<

	參數: out => 輸出資料流, student => 學生

	回傳值: 輸出資料流
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
	函式功能: 初始化學生資料

	參數: name => 名字, id => 學號, gender => 性別, university => 就讀大學

	回傳值: 吳
*/
Student::Student(string name, string id, string gender, string university)
{
    _name = name;
    _id = id;
    _gender = gender;
    _university = university;
}