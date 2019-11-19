/*
	Author: ��u�G 107590037 ��ģ�w
	�{���ت�: �p��ǥͦ��ZGPA�������ơA��U�ǥͤ�K�p��
	�s�@���: 2019/09/11
*/
#include <iostream>
#include <string>
#include <regex>
using namespace std;

//�ˬd��J����جO�_����
bool IsExistedSubject(string subjectName, string subjects[], int subjectsLength)
{
    for (int i = 0; i < subjectsLength; i++)
    {
        //�p�G��J����ػP�w�x�s��زM��ۦP�A�h��^true
        if (subjects[i].compare(subjectName) == 0)
            return true;
    }

    return false;
}

/*
		�ഫ����to�������
		����S = 10��
		����A = 9��
		����B = 8��
		����C = 7��
		����D = 6��
		����E = 5��
		����F = 0��
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

//�B�z��J��ؤΦ��Z
void InputSubjectAndGrade(string subjects[], int grades[], int& subjectsLength)
{
    //��J����ئW��
    string subjectName;
    //��J����ئ��Z
    string subjectGrade;

    while (1)
    {
        //�B�z��J���
        cout << "Enter Subject name:";
        getline(cin, subjectName);

        //���b �קK��ئW�٬���
        if (subjectName.empty())
        {
            cout << "Subject name cannot be empty!" << endl;
            continue;
        }
        //�ˬd��ئW�٬O�_����
        else if (IsExistedSubject(subjectName, subjects, subjectsLength))
        {
            cout << "Can not enter duplicate subject!" << endl;
            continue;
        }

        //�x�s�ܬ�زM�椤
        subjects[subjectsLength] = subjectName;

        //�B�z��J��ئ��Z
        while (1)
        {
            cout << "Enter grade of subject:";
            getline(cin, subjectGrade);
            regex pattern("^[SABCDEF]{1}$");

            //���b �ˬd��J���Z�O�_�X�k
            if (regex_match(subjectGrade, pattern))
                break;

            cout << "Invalid Grade!" << endl;
        }

        //�ഫ����to�������
        grades[subjectsLength++] = ConvertGradeToScore(subjectGrade);
        break;
    }

    return;
}

//�p��GPA�������ƨæL�X
void CalculateAndPrintGPA(int grades[], int subjectsLength)
{
    float gpa = 0.0, totalPoints = 0.0;

    for (int i = 0; i < subjectsLength; i++)
        totalPoints += grades[i];

    //���b�קK�L��ظ��
    if (subjectsLength != 0)
        gpa = totalPoints / subjectsLength;

    //�P�_gpa�ȬO�_����ơA�_�h�H�p���I�����
    if (static_cast<int>(gpa) * 10 == static_cast<int>(gpa * 10))
        cout << "GPA is: " << static_cast<int>(gpa) << endl;
    else
    {
        cout.precision(3);
        cout << "GPA is: " << gpa << endl;
    }

    return;
}

//�D�nCommand�\�౱���
int main()
{
    //��JCommand�Ʀr
    string commandNumber;
    //�w�x�s��زM��
    string subjects[50];
    //�w�x�s��ئ��Z
    int grades[50];
    //�w�x�s��حӼ�
    int subjectsLength = 0;

    while (1)
    {
        cout << "1. Enter subject followed by grade" << endl;
        cout << "2. Calculate GPA" << endl;
        cout << "3. exit" << endl;
        cout << "Command: ";
        getline(cin, commandNumber);
        //�ˬdCommand�O�_�X�k
        regex pattern("^[123]{1}$");

        if (!regex_match(commandNumber, pattern))
        {
            cout << "Invalid Input!" << endl;
            continue;
        }

        if (commandNumber == "1")
            //�B�z��J��ؤΦ��Z
            InputSubjectAndGrade(subjects, grades, subjectsLength);
        else if (commandNumber == "2")
            //�p��GPA�������ƨæL�X
            CalculateAndPrintGPA(grades, subjectsLength);
        else
            break;
    }

    return 0;
}