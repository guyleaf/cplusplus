/*
	Author: ��u�G 107590037 ��ģ�w

	Destination: �p��ꤧ�P���B���n�Ϊ��|

	Date: 2019/09/16

	HomeworkNumber: HW3
*/
#include <iostream>
#include <string>
#include <regex>
using namespace std;
#include "circle.h"

/*
	�{���\��: ���o��J�b�|���

	�Ѽ�: �L

	�^�ǭ�: double���A���b�|���
*/
double GetInputRadius()
{
    //�b�|���
    string radius;
    //���W��F�� ��ƻP�p�ƨ�ر��p
    regex rule1("^[0-9]+");
    regex rule2("^[0-9]+\\.[0-9]+$");

    while (true)
    {
        cout << "�п�J��Υb�|: ";
        getline(cin, radius);

        //�ˬd��J��Ʀ��L�X�k
        if (regex_match(radius, rule1) || regex_match(radius, rule2))
        {
            //string��double���A�æ^��
            return stod(radius);
        }

        cout << "��J���~, �Э��s��J" << endl;
    }
}

int main()
{
    //�ŧi�@�Ӷ�
    Circle circle;
    //�]�w�b�|
    circle.SetRadius(GetInputRadius());
    cout << "��Ϊ��|: " << circle.CalculateDiameter() << endl;
    cout << "��ΩP��: " << circle.CalculateCircumference() << endl;
    cout << "��έ��n: " << circle.CalculateArea() << endl;
    system("PAUSE");
    return 0;
}