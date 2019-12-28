#include "Suite.h"
#include <iostream>

/*
	�禡�\��: �غc�M�˸��

	�Ѽ�: name => �M�˦W��, description => �M�˴y�z, id => �M�˰ӫ~�s��

	�^�ǭ�: �L
*/
Suite::Suite(string name, string description, int id) : Cloth(name, description, 0, id)
{
}

/*
	�禡�\��: �M�˪�l�ƥ[�J��w����A

	�Ѽ�: �@���A

	�^�ǭ�: �L
*/
void Suite::Add(Cloth* cloth)
{
    _clothes.push_back(cloth);
    _price += cloth->GetPrice();
}

/*
	�禡�\��: ���o�M�˻���

	�Ѽ�: �L

	�^�ǭ�: �M�˻���
*/
double Suite::GetPrice() const
{
    return _price * 0.9;
}

Suite::~Suite()
{
}
