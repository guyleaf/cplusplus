/*
	Author: 資工二 107590037 應耀德
	程式目的: 計算學生成績GPA平均分數，協助學生方便計算
	製作日期: 2019/09/11
*/
#include <iostream>
#include <string>
#include <regex>
using namespace std;

//檢查輸入之科目是否重複
bool IsExistedSubject(string subjectName, string subjects[], int subjectsLength)
{
    for (int i = 0; i < subjectsLength; i++)
    {
        //如果樹入之科目與已儲存科目清單相同，則返回true
        if (subjects[i].compare(subjectName) == 0)
            return true;
    }

    return false;
}

/*
		轉換分數to對應整數
		分數S = 10分
		分數A = 9分
		分數B = 8分
		分數C = 7分
		分數D = 6分
		分數E = 5分
		分數F = 0分
*/
int ConvertGradeToScore(string subjectGrade)
{
    if (subjectGrade.compare("S") == 0)
        return 10;
    else if (subjectGrade.compare("A") == 0)
        return 9;
    else if (subjectGrade.compare("B") == 0)
        return 8;
    else if (subjectGrade.compare("C") == 0)
        return 7;
    else if (subjectGrade.compare("D") == 0)
        return 6;
    else if (subjectGrade.compare("E") == 0)
        return 5;
    else
        return 0;
}

//處理輸入科目及成績
void InputSubjectAndGrade(string subjects[], int grades[], int& subjectsLength)
{
    //輸入之科目名稱
    string subjectName;
    //輸入之科目成績
    string subjectGrade;

    while (1)
    {
        //處理輸入科目
        cout << "Enter Subject name:";
        getline(cin, subjectName);

        //防呆 避免科目名稱為空
        if (subjectName.empty())
        {
            cout << "Subject name cannot be empty!" << endl;
            continue;
        }
        //檢查科目名稱是否重複
        else if (IsExistedSubject(subjectName, subjects, subjectsLength))
        {
            cout << "Can not enter duplicate subject!" << endl;
            continue;
        }

        //儲存至科目清單中
        subjects[subjectsLength] = subjectName;

        //處理輸入科目成績
        while (1)
        {
            cout << "Enter grade of subject:";
            getline(cin, subjectGrade);
            regex pattern("^[SABCDEF]{1}$");

            //防呆 檢查輸入成績是否合法
            if (regex_match(subjectGrade, pattern))
                break;

            cout << "Invalid Grade!" << endl;
        }

        //轉換分數to對應整數
        grades[subjectsLength++] = ConvertGradeToScore(subjectGrade);
        break;
    }

    return;
}

//計算GPA平均分數並印出
void CalculateAndPrintGPA(int grades[], int subjectsLength)
{
    float gpa = 0.0, totalPoints = 0.0;

    for (int i = 0; i < subjectsLength; i++)
        totalPoints += grades[i];

    //防呆避免無科目資料
    if (subjectsLength != 0)
        gpa = totalPoints / subjectsLength;

    //判斷gpa值是否為整數，否則以小數點兩位表示
    if (static_cast<int>(gpa) * 10 == static_cast<int>(gpa * 10))
        cout << "GPA is: " << static_cast<int>(gpa) << endl;
    else
    {
        cout.precision(3);
        cout << "GPA is: " << gpa << endl;
    }

    return;
}

//主要Command功能控制端
int main()
{
    //輸入Command數字
    string commandNumber;
    //已儲存科目清單
    string subjects[50];
    //已儲存科目成績
    int grades[50];
    //已儲存科目個數
    int subjectsLength = 0;

    while (1)
    {
        cout << "1. Enter subject followed by grade" << endl;
        cout << "2. Calculate GPA" << endl;
        cout << "3. exit" << endl;
        cout << "Command: ";
        getline(cin, commandNumber);
        //檢查Command是否合法
        regex pattern("^[123]{1}$");

        if (!regex_match(commandNumber, pattern))
        {
            cout << "Invalid Input!" << endl;
            continue;
        }

        if (commandNumber == "1")
            //處理輸入科目及成績
            InputSubjectAndGrade(subjects, grades, subjectsLength);
        else if (commandNumber == "2")
            //計算GPA平均分數並印出
            CalculateAndPrintGPA(grades, subjectsLength);
        else
            break;
    }

    return 0;
}