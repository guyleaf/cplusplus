#include "Mall.h"

#include <regex>
using namespace std;

/*
	�禡�\��: ��l�ưӳ�

	�Ѽ�: �L

	�^�ǭ�: �L
*/
Mall::Mall()
{
    LoadShopsData("Cloth.txt");
}


/*
	�禡�\��: �إߦ�A���

	�Ѽ�: name: �ӫ~�W�r, description: �ӫ~�y�z, price: �ӫ~����

	�^�ǭ�: �L
*/
void Mall::CreateNewCloth(string name, string description, double price)
{
    Shop* shop = _shops[_shopIndex];
    shop->createNewCloth(name, description, price);
}

/*
	�禡�\��: ��ܰө�

	�Ѽ�: �ө��s��

	�^�ǭ�: �L
*/
void Mall::SelectShop(int shopIndex)
{
    _shopIndex = shopIndex;
}

/*
	�禡�\��: ���o�Ҧ���A���

	�Ѽ�: �L

	�^�ǭ�: �Ҧ���A��ƪ�vector��}
*/
const vector<Cloth*>* Mall::GetClothes() const
{
    return _shops[_shopIndex]->GetClothes();
}

/*
	�禡�\��: ���o�Ҧ��ө�

	�Ѽ�: �L

	�^�ǭ�: �Ҧ��ө���ƪ�vector��}
*/
const vector<Shop*>* Mall::GetShops() const
{
    return &_shops;
}

/*
	�禡�\��: ���J�~�����a���

	�Ѽ�: �ɮצW��

	�^�ǭ�: �L
*/
void Mall::LoadShopsData(string fileName)
{
    //�ɮ׸�Ƭy
    fstream file;
    //�ө����Y�W�h
    regex rule("^Shop .+:$");
    //���}�ɮ�
    file.open(fileName, ios::in);

    //�䤣���ɮ׫h�h�X
    if (!file)
        return;

    //�ө����Y �ө��W��
    string shopHead, shopName;
    //�ө����
    Shop* shop;

    while (!file.eof())
    {
        //Ū���ө����Y
        shopHead = ReadShopHead(file);

        //�ˬd�O�_�ŦX�W�h
        if (!regex_match(shopHead, rule))
            break;

        //���o���Y�����ө��W��
        shopName = GetShopName(shopHead);
        //�إ߰ө�
        shop = new Shop(shopName);
        //�[�J�ܰө��M��
        _shops.push_back(shop);
        //���J�ө���A���
        LoadClothesData(file, shop);
    }

    //�����ɮ�
    file.close();
}

/*
	�禡�\��: ���J�ө���A���

	�Ѽ�: file => �ɮ׸�Ƭy, shop => �ө�����

	�^�ǭ�: �L
*/
void Mall::LoadClothesData(fstream& file, Shop* shop)
{
    //�����̫�Ū�ɦ�m
    streampos lastReadPosition = file.tellg();
    //��A�W��, ��A�y�z, ��A����
    string name, description;
    double price;

    while (IsClothData(file, lastReadPosition))
    {
        //Ū����A�W��
        name = ReadClothName(file);
        //Ū����A�y�z
        description = ReadClothDescription(file);
        //Ū����A����
        price = ReadClothPrice(file);
        //�����̫�Ū�ɦ�m
        lastReadPosition = file.tellg();
        //�إߦ�A���
        shop->createNewCloth(name, description, price);
    }
}

/*
	�禡�\��: Ū���ө����Y

	�Ѽ�: �ɮ׸�Ƭy

	�^�ǭ�: �ө����Y
*/
string Mall::ReadShopHead(fstream& file) const
{
    string shopHead;
    getline(file, shopHead, '\n');
    return shopHead;
}

/*
	�禡�\��: ���o�ө��W��

	�Ѽ�: �ө����Y

	�^�ǭ�: �ө��W��
*/
string Mall::GetShopName(const string& shopHead) const
{
    string shopName;
    shopName = shopHead.substr(5, shopHead.size() - 6);
    return shopName;
}

/*
	�禡�\��: Ū����A�W��

	�Ѽ�: �ɮ׸�Ƭy

	�^�ǭ�: ��A�W��
*/
string Mall::ReadClothName(fstream& file) const
{
    string name;
    getline(file, name, ',');
    //�����Ů�
    file.ignore(1);
    return name;
}

/*
	�禡�\��: Ū����A�y�z

	�Ѽ�: �ɮ׸�Ƭy

	�^�ǭ�: ��A�y�z
*/
string Mall::ReadClothDescription(fstream& file) const
{
    string description;
    getline(file, description, ',');
    //�����Ů�
    file.ignore(1);
    return description;
}

/*
	�禡�\��: Ū����A����

	�Ѽ�: �ɮ׸�Ƭy

	�^�ǭ�: ��A����
*/
double Mall::ReadClothPrice(fstream& file) const
{
    string price;
    getline(file, price, '\n');
    return stod(price);
}

/*
	�禡�\��: �ˬd�O�_����A���

	�Ѽ�: file => �ɮ׸�Ƭy, lastReadPosition => �̫�Ū���ɮת���m

	�^�ǭ�: �ө��W��
*/
bool Mall::IsClothData(fstream& file, streampos& lastReadPosition) const
{
    string data;
    //��A��ƳW�h
    regex rule("^.+, .+, .+$");
    getline(file, data, '\n');
    //rollback
    file.seekg(lastReadPosition);

    //�ˬd�O�_����A���
    if (regex_match(data, rule))
        return true;

    return false;
}

Mall::~Mall()
{
    for (size_t i = 0; i < _shops.size(); i++)
        delete _shops[i];
}