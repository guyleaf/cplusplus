#include "MallUI.h"
#include <iostream>
#include <regex>
#include <iomanip>
using namespace std;

/*
	�禡�\��: ��l�ưӳ�UI

	�Ѽ�: �ӳ�Model

	�^�ǭ�: �L
*/
MallUI::MallUI(Mall* mall)
{
    _mall = mall;
    _exit = false;
    _shopsOrder.push_back("UNIQLO");
    _shopsOrder.push_back("H&M");
    _shopsOrder.push_back("ZARA");
    _numberOfShops = _shopsOrder.size();
}

/*
	�禡�\��: ���UI�e��

	�Ѽ�: �L

	�^�ǭ�: �L
*/
void MallUI::Start()
{
    //��w���ө��W��
    string shopName;

    while (!_exit)
    {
        //�ӳ����
        MallsMenu(shopName);

        //���}
        if (_exit)
            break;

        //�ө����
        ShopMenu(shopName);
    }
}

/*
	�禡�\��: ���Malls's Menu

	�Ѽ�: �L

	�^�ǭ�: �L
*/
void MallUI::ShowMallsMenu()
{
    //�C�X���a�M��
    for (size_t i = 0; i < _numberOfShops; i++)
        cout << i + 1 << "." << _shopsOrder[i] << endl;

    cout << _numberOfShops + 1 << "." << "�����{��" << endl;
}

/*
	�禡�\��: ��ܰө�

	�Ѽ�: command => ��J���O, shopName => ��w���ө��W��

	�^�ǭ�: �L
*/
void MallUI::SelectShop(int command, string& shopName)
{
    shopName = _shopsOrder[command - 1];
    int shopIndex = GetShopIndex(shopName);
    _mall->SelectShop(shopIndex);
}

/*
	�禡�\��: �ӳ����

	�Ѽ�: ��w���ө��W��

	�^�ǭ�: �L
*/
void MallUI::MallsMenu(string& shopName)
{
    //�Ȧs��J���
    string command;
    const string LIMIT_COMMAND_SIZE = to_string(_numberOfShops);
    const string EXIT_COMMAND = to_string(_numberOfShops + 1);
    //��ܰө��W�h
    regex rule("^[1-" + LIMIT_COMMAND_SIZE + "]$");
    ShowMallsMenu();

    while (true)
    {
        cout << "Select Shop: ";
        command = GetCommand();

        //�ˬd�O�_�ŦX��ܰө��W�h
        if (regex_match(command, rule))
        {
            SelectShop(stoi(command), shopName);
            break;
        }
        else if (command == EXIT_COMMAND)
        {
            _exit = true;
            break;
        }

        cout << "�п�ܵe���W�����a" << endl;
    }
}

/*
	�禡�\��: ��ܰө����

	�Ѽ�: ��w���ө��W��

	�^�ǭ�: �L
*/
void MallUI::ShowShopMenu(const string shopName)
{
    cout << "(" + shopName + ")1.�s�W��A" << endl;
    cout << "(" + shopName + ")2.�d�ݩҦ���A" << endl;
    cout << "(" + shopName + ")3.��^�ӳ�" << endl;
    cout << "�п�J���: ";
}

/*
	�禡�\��: �ө����

	�Ѽ�: ��w���ө��W��

	�^�ǭ�: �L
*/
void MallUI::ShopMenu(string& shopName)
{
    regex rule("^[1-3]$");
    //�x�s��J���O�N��
    string command;
    ShowShopMenu(shopName);

    while (true)
    {
        //���o�ө�����J���O
        command = GetCommand();

        if (regex_match(command, rule))
        {
            if (command == "1") //�\��@ �s�W��A
                AddNewClothes();
            else if (command == "2") //�\��G ��ܩҦ���A�w�s
                DisplayAllClothes();
            else if (command == "3") //��^�ӳ�
                break;

            ShowShopMenu(shopName);
        }
        else
            cout << "�п�J���T���ﶵ: ";
    }
}

/*
	�禡�\��: ���o����J���O

	�Ѽ�: �L

	�^�ǭ�: ���O�N��
*/
string MallUI::GetCommand()
{
    //�Ȧs��J��
    string input;
    getline(cin, input);
    return input;
}

/*
	�禡�\��: ���o��A�W��

	�Ѽ�: �L

	�^�ǭ�: ��A�W��
*/
string MallUI::GetClothName()
{
    //�Ȧs��J��
    string input;
    cout << "�п�J��A�W��: ";
    getline(cin, input);
    return input;
}

/*
	�禡�\��: ���o��A�y�z

	�Ѽ�: �L

	�^�ǭ�: ��A�y�z
*/
string MallUI::GetClothDescription()
{
    //�Ȧs��J��
    string input;
    cout << "�п�J��A�y�z: ";
    getline(cin, input);
    return input;
}

/*
	�禡�\��: ���o��A����

	�Ѽ�: �L

	�^�ǭ�: ��A����
*/
double MallUI::GetClothPrice()
{
    //�Ȧs��J���
    string data;
    double price;
    cout << "�п�J����: ";

    while (getline(cin, data))
    {
        //�ŦX�W�h�B���椣���s
        if (IsNumber(data) && IsPositive(data) && stod(data) != 0)
        {
            //�r����doeble
            price = stod(data);
            break;
        }

        //�P�_��J�O���ؿ��~
        //���e�w�P�_�O�_�����ƻP������0�A�ҥH�u�ݭn�P�_�O�_���Ʀr�Y�i
        if (IsNumber(data))
            cout << "���椣��p�󵥩�s�A�Э��s��J" << endl;
        else
            cout << "���椣���\�D�Ʀr�榡�A�Э��s��J" << endl;

        cout << "�п�J����: ";
    }

    return price;
}
/*
	�禡�\��: �s�W��A

	�Ѽ�: �L

	�^�ǭ�: �L
*/
void MallUI::AddNewClothes()
{
    //�Ȧs�ӫ~����
    string name = GetClothName();
    string description = GetClothDescription();
    double price = GetClothPrice();
    //�إߦ�A���
    _mall->CreateNewCloth(name, description, price);
}

/*
	�禡�\��: ��ܩ��a�Ҧ���A���

	�Ѽ�: �L

	�^�ǭ�: �L
*/
void MallUI::DisplayAllClothes() const
{
    //���o���a�Ҧ���A���
    const vector<Cloth*>* clothesData = _mall->GetClothes();
    cout << left << setw(8) << "No." << left << setw(48) << "��A�W��" << left << setw(8) << "����" << "�y�z" << endl;

    //��X��A���
    for (size_t i = 0; i < clothesData->size(); i++)
    {
        cout << left << setw(8) << (*clothesData)[i]->GetId()
             << left << setw(48) << (*clothesData)[i]->GetName()
             << left << setw(8) << setprecision(1) << fixed << (*clothesData)[i]->GetPrice()
             << (*clothesData)[i]->GetDescription() << endl;
    }

    cout << endl;
}

/*
	�禡�\��: ���o�ө��s��

	�Ѽ�: �ө��W��

	�^�ǭ�: �ө��s��
*/
int MallUI::GetShopIndex(const string shopName) const
{
    const vector<Shop*>* shops = _mall->GetShops();

    for (size_t i = 0; i < shops->size(); i++)
    {
        if ((*shops)[i]->GetName() == shopName)
            return (int)i;
    }

    return -1;
}

/*
	�禡�\��: �P�_�O�_���Ʀr

	�Ѽ�: ��J��� string

	�^�ǭ�: true/false
*/
bool MallUI::IsNumber(string input)
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
bool MallUI::IsPositive(string input)
{
    if (stod(input) >= 0)
        return true;

    return false;
}