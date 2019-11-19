#include "Shop.h"

#include <fstream>
using namespace std;

/*
	�禡�\��: ��l�Ʃ��a

	�Ѽ�: ���a�W�r

	�^�ǭ�: �L
*/
Shop::Shop(string name)
{
    //���a�W�r
    _name = name;
    //��A�ؼ�
    _numberOfClothes = 0;
    //���J��A���
    LoadClothesData("Cloth.txt");
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
void Shop::CreateNewCloth(string name, string description, double price)
{
    //�[���A��ƲM��
    _clothes.push_back(new Cloth(name, description, price, ++_numberOfClothes));
}

/*
	�禡�\��: ���o�Ҧ���A���

	�Ѽ�: �L

	�^�ǭ�: �Ҧ���A��ƪ�vector��}
*/
vector<Cloth*>* Shop::GetClothes() const
{
    //��A��ưƥ��A�p�G�����^��_clothes��}�A�i��|�y���~�������ק鷺�����
    vector<Cloth*>* clothes = new vector<Cloth*>;
    //�ƻs��A���
    (*clothes) = _clothes;
    return clothes;
}

/*
	�禡�\��: ���J��A���

	�Ѽ�: �ɮצW��

	�^�ǭ�: �L
*/
void Shop::LoadClothesData(string fileName)
{
    fstream clothesList;
    //���}��Ƥ��
    clothesList.open(fileName, fstream::in);
    string head;
    //���Ĥ@����Y���
    getline(clothesList, head, '\n');

    //�ˬd���Y�O�_��name, description, price�A�_�h�������J
    if (head != "name, description, price")
        return;

    string name, description, price;

    //�Cloop�@���N����Ū���@��
    while (!clothesList.eof())
    {
        //Ū���ӫ~�W�r
        getline(clothesList, name, ',');
        //�����Ů�
        clothesList.ignore(1);
        //Ū���ӫ~�y�z
        getline(clothesList, description, ',');
        //�����Ů�
        clothesList.ignore(1);
        //Ū���ӫ~����
        getline(clothesList, price, '\n');
        //�إߦ�A���
        CreateNewCloth(name, description, stod(price));
    }

    //�����ɮ�
    clothesList.close();
}

