#include "UI.h"

#include <iostream>
#include <string>
#include <regex>
#include <iomanip>

using namespace std;

//����Shop�O����
UI::~UI()
{
    delete _shop;
}
/*
	�禡�\��: ��ܿ��

	�Ѽ�: �L

	�^�ǭ�: �L
*/
void UI::ShowMenu()
{
    //�Ыذө�
    CreateShop("H&M");
    //�x�s��J���O�N��
    int command;

    while (true)
    {
        cout << "(" + _shop->GetName() + ")1.�s�W��A" << endl;
        cout << "(" + _shop->GetName() + ")2.�d�ݩҦ���A" << endl;
        cout << "(" + _shop->GetName() + ")3.�����{��" << endl;
        cout << "�п�J���: ";
        //���o��J���O�N��
        command = GetCommand();

        if (command == 1) //�\��@ �s�W��A
            AddNewClothes();
        else if (command == 2) //�\��G ��ܩҦ���A�w�s
            DisplayAllClothes();
        else if (command == 3) //���}
            break;
    }
}

/*
	�禡�\��: ���o��J���O�N��

	�Ѽ�: �L

	�^�ǭ�: ���O�N��
*/
int UI::GetCommand()
{
    //��J�W�h
    regex rule("^[1-3]$");
    //�Ȧs��J��
    string input;

    while (getline(cin, input))
    {
        if (regex_match(input, rule))
            break;
        else
            cout << "�п�J���T���ﶵ: ";
    }

    return stoi(input); //�r������
}

/*
	�禡�\��: �s�W��A

	�Ѽ�: �L

	�^�ǭ�: �L
*/
void UI::AddNewClothes()
{
    //�Ȧs��J���
    string input;
    //�Ȧs��A�ӫ~���
    string name, description;
    double price;
    cout << "�п�J��A�W��: ";
    getline(cin, name);
    cout << "�п�J��A�y�z: ";
    getline(cin, description);
    cout << "�п�J����: ";

    while (getline(cin, input))
    {
        //�ŦX�W�h�B���椣���s
        if (IsNumber(input) && IsPositive(input) && stod(input) != 0)
        {
            //�r����doeble
            price = stod(input);
            break;
        }

        //�P�_��J�O���ؿ��~
        //���e�w�P�_�O�_�����ƻP������0�A�ҥH�u�ݭn�P�_�O�_���Ʀr�Y�i
        if (IsNumber(input))
            cout << "���椣��p�󵥩�s�A�Э��s��J" << endl;
        else
            cout << "���椣���\�D�Ʀr�榡�A�Э��s��J" << endl;

        cout << "�п�J����: ";
    }

    //�إߦ�A���
    _shop->CreateNewCloth(name, description, price);
}

/*
	�禡�\��: ��ܩ��a�Ҧ���A���

	�Ѽ�: �L

	�^�ǭ�: �L
*/
void UI::DisplayAllClothes() const
{
    //���o���a�Ҧ���A���
    vector<Cloth*>* clothesData = _shop->GetClothes();
    cout << left << setw(8) << "No." << left << setw(48) << "��A�W��" << left << setw(8) << "����" << "�y�z" << endl;

    //��X��A���
    //���B��i�����O���Vvector��}�A�ҥH�ݭn*�ѰѦҨ��oCloth�����}�A�Ϥ�**�N��OCloth���󪺤��e
    for (vector<Cloth*>::iterator i = clothesData->begin(); i != clothesData->end(); i++)
    {
        cout << left << setw(8) << (*i)->GetId()
             << left << setw(48) << (*i)->GetName()
             << left << setw(8) << setprecision(1) << fixed << (*i)->GetPrice()
             << (*i)->GetDescription() << endl;
    }

    //����O����
    delete clothesData;
}

/*
	�禡�\��: �Ыذө�

	�Ѽ�: ���a�W�r: string

	�^�ǭ�: �L
*/
void UI::CreateShop(string name)
{
    _shop = new Shop(name);
}

/*
	�禡�\��: �P�_�O�_���Ʀr

	�Ѽ�: ��J��� string

	�^�ǭ�: true/false
*/
bool UI::IsNumber(string input)
{
    regex rule1("^-?[0-9]+$");
    regex rule2("^-?[0-9]+\\.[0-9]+$");

    if (regex_match(input, rule1) || regex_match(input, rule2))
        return true;

    return false;
}


/*
	�禡�\��: �P�_�O�_������

	�Ѽ�: ��J��� string

	�^�ǭ�: true/false
*/
bool UI::IsPositive(string input)
{
    if (stod(input) >= 0)
        return true;

    return false;
}