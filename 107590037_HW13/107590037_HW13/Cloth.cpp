#include "Cloth.h"

/*
	�禡�\��: ��l�Ʀ�A���

	�Ѽ�: name: ��A�W�r, description: ��A�y�z, price: ��A����

	�^�ǭ�: �L
*/
Cloth::Cloth(string name, string description, double price, int id)
{
    _name = name;
    _description = description;
    _price = price;
    _id = id;
}

/*
	�禡�\��: ���o��A�W��

	�Ѽ�: �L

	�^�ǭ�: ��A�W��
*/
string Cloth::GetName() const
{
    return _name;
}

/*
	�禡�\��: ���o��A�y�z

	�Ѽ�: �L

	�^�ǭ�: ��A�y�z
*/
string Cloth::GetDescription() const
{
    return _description;
}

/*
	�禡�\��: ���o��A����

	�Ѽ�: �L

	�^�ǭ�: ��A����
*/
double Cloth::GetPrice() const
{
    return _price;
}

/*
	�禡�\��: ���o��A�s��

	�Ѽ�: �L

	�^�ǭ�: ��A�s��
*/
int Cloth::GetId() const
{
    return _id;
}

Cloth::~Cloth()
{
}