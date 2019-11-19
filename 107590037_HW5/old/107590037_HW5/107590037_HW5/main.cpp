/*
	Author: ��u�G 107590037 ��ģ�w

	�{���\��: ��U�p��ƦC�������

	�������: 2019/10/11
*/
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <regex>
using namespace std;
#include "NumberArray.h"

/*
	�禡�\��: ���Φr���J���

	�Ѽ�: �r���J���

	�^�ǭ�: float���A���ƦC�A���ο��~�h�^�ǪżƦC
*/
vector<float> SplitString(const string& input)
{
    //�x�s�ƦC���ܼ�
    vector<float> numbers;
    //��r���J��ƥ�Jinputstream��Ƭy
    istringstream inputStream(input);
    //�Ȧs�w���Φr��
    string stringTemp;
    //��J��ƳW�h
    regex rule1("^-?[0-9]+$");
    regex rule2("^-?[0-9]+\\.[0-9]+$");

    //���θ��
    while (getline(inputStream, stringTemp, ' '))
    {
        //�ˬd���θ�ơA���X�k�h�M�żƦC�ø��X
        if (regex_match(stringTemp, rule1) || regex_match(stringTemp, rule2))
            //�s�J�ƦC���ഫ���B�I��
            numbers.push_back(stof(stringTemp));
        else
        {
            //�M�żƦC�ø��X
            numbers.clear();
            break;
        }
    }

    return numbers;
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
        getline(cin, input);
        //���Φr���J���
        numbers = SplitString(input);

        //�p�G�����żƦC�A�N����ο�J��ƲŦX�W�h�A�h���X�j��
        if (!empty(numbers))
            break;

        cout << "��J��Ʀ��~" << endl;
    }

    //�غc������
    numberArray = NumberArray(numbers);
}

int main()
{
    //��l�ƼƦC����-�����k�s
    NumberArray numberArray;
    //���o��J�ƦC
    GetInput(numberArray);
    //��X�����
    cout << "�����: " << numberArray.GetMedian() << endl;
    system("PAUSE");
    return 0;
}