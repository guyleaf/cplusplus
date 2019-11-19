#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <regex>
using namespace std;
#include "NumberArray.h"

/*
	�禡�\��: �P�_�O�_���Ʀr

	�Ѽ�: �r���J���

	�^�ǭ�: true/false
*/
bool IsNumber(const string& input)
{
    //��J��ƳW�h
    regex rule1("^-?[0-9]+$");
    regex rule2("^-?[0-9]+\\.[0-9]+$");

    if (regex_match(input, rule1) || regex_match(input, rule2))
        return true;

    return false;
}

/*
	�禡�\��: ���o��J�ƦC

	�Ѽ�: NumberArray�ƦC����

	�^�ǭ�: �L
*/
void GetInput(NumberArray& numberArray)
{
    //�x�s�ƦC���ܼ�
    vector<float> numbers;
    //��J���
    string input;

    while (true)
    {
        cout << "�п�J�@��h�ռƦr: ";

        while (cin >> input)
        {
            if (IsNumber(input))
                numbers.push_back(stof(input));
            else
            {
                numbers.clear();
                break;
            }
        }

        if (!empty(numbers))
            break;

        cout << "��J��Ʀ��~" << endl;
    }

    //�ƧǼƦC
    sort(numbers.begin(), numbers.end());
    //�غc������
    numberArray = NumberArray(numbers);
}

int main()
{
    //�ƦC����
    NumberArray numberArray;
    //���o��J�ƦC
    GetInput(numberArray);
    cout << "�����: " << numberArray.GetMedian() << endl;
    system("PAUSE");
    return 0;
}