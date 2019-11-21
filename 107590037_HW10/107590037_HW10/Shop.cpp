#include "Shop.h"

/*
	�禡�\��: ��l�Ʃ��a

	�Ѽ�: ���a�W�r

	�^�ǭ�: �L
*/
Shop::Shop(string name)
{
    _name = name;
    _numberOfClothes = 0;
}

/*
	�禡�\��: ���o���a�W�r

	�Ѽ�: �L

	�^�ǭ�: �L
*/
string Shop::GetName() const
{
    return _name;
}

/*
	�禡�\��: �إߦ�A���

	�Ѽ�: name: �ӫ~�W�r, description: �ӫ~�y�z, price: �ӫ~����

	�^�ǭ�: �L
*/
void Shop::createNewCloth(string name, string description, double price)
{
    //�[���A��ƲM��
    _clothes.push_back(new Cloth(name, description, price, ++_numberOfClothes));
}

/*
	�禡�\��: ���o�Ҧ���A���

	�Ѽ�: �L

	�^�ǭ�: �Ҧ���A��ƪ�vector��}
*/
const vector<Cloth*>* Shop::GetClothes() const
{
    /*//��A��ưƥ��A�p�G�����^��_clothes��}�A�i��|�y���~�������ק鷺�����
    vector<Cloth*>* clothes = new vector<Cloth*>;
    //�ƻs��A���
    (*clothes) = _clothes;*/
    return &_clothes;
}

/*
	�禡�\��: �M���A

	�Ѽ�: ��Aid

	�^�ǭ�: ��A����
*/
Cloth* Shop::FindCloth(int id) const
{
    for (size_t i = 0; i < _clothes.size(); i++)
    {
        if (_clothes[i]->GetId() == id)
            return _clothes[i];
    }

    return NULL;
}

Shop::~Shop()
{
    for (int i = 0; i < _numberOfClothes; i++)
        delete _clothes[i];
}

