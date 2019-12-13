#include "ScienceStudent.h"

/*
	函式功能: ScienceStudent's operator <<

	參數: out => 輸出資料流, scienceStudent => 電腦科學系的學生

	回傳值: 輸出資料流
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
	函式功能: 初始化學生資料

	參數: name => 名字, id => 學號, gender => 性別, university => 就讀大學, department => 科系

	回傳值: 無
*/
ScienceStudent::ScienceStudent(string name, string id, string gender, string university, string department) : Student(name, id, gender, university)
{
    _department = department;
}