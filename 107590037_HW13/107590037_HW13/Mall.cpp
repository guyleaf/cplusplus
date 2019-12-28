#include "Mall.h"

#include <regex>
#include <iostream>
using namespace std;

/*
	�禡�\��: ��l�ưӳ�

	�Ѽ�: �L

	�^�ǭ�: �L
*/
Mall::Mall()
{
    LoadShopsData("Cloth.txt");
    _customers.push_back(new Customer("Amber"));
    _customers.push_back(new Customer("Tim"));
    _customers.push_back(new Customer("Marry"));
}


/*
	�禡�\��: �إߦ�A���

	�Ѽ�: name: �ӫ~�W�r, description: �ӫ~�y�z, price: �ӫ~����

	�^�ǭ�: �L
*/
void Mall::CreateNewCloth(string name, string description, double price)
{
    Shop* shop = _shops[_shopIndex];
    shop->CreateNewCloth(name, description, price);
}

/*
	�禡�\��: �إ߷s�q��

	�Ѽ�: �L

	�^�ǭ�: �L
*/
void Mall::MakeNewOrder()
{
    Shop* shop = _shops[_shopIndex];
    _customers[_customerIndex]->MakeNewOrder(shop);
}

/*
	�禡�\��: �[�J��A�ܭq�椤

	�Ѽ�: ��AID

	�^�ǭ�: �L
*/
void Mall::AddClothToOrder(int id)
{
    Shop* shop = _shops[_shopIndex];
    Cloth* cloth = shop->FindCloth(id);
    Customer* customer = _customers[_customerIndex];
    customer->AddClothToOrder(cloth);
}


/*
	�禡�\��: ��ܫȤH�P�ө�

	�Ѽ�: �ȤH�s��, �ө��s��

	�^�ǭ�: �L
*/
void Mall::SelectCustomerAndShop(size_t customerIndex, size_t shopIndex)
{
    _shopIndex = shopIndex;
    _customerIndex = customerIndex;
}

/*
	�禡�\��: �ˬd�I�ƬO�_����

	�Ѽ�: �L

	�^�ǭ�: True/False
*/
bool Mall::IsPointEnough() const
{
    Customer* customer = _customers[_customerIndex];
    return customer->IsPointEnough();
}

/*
	�禡�\��: ���o�I��

	�Ѽ�: �L

	�^�ǭ�: �I��
*/
double Mall::GetCash() const
{
    Customer* customer = _customers[_customerIndex];
    return customer->GetCash();
}

/*
	�禡�\��: �q�榩���I��

	�Ѽ�: �L

	�^�ǭ�: �L
*/
void Mall::ReducePointFromOrder()
{
    Customer* customer = _customers[_customerIndex];
    customer->ReducePointFromOrder();
}

/*
	�禡�\��: �����q��

	�Ѽ�: �L

	�^�ǭ�: �L
*/
void Mall::CancelOrder()
{
    Customer* customer = _customers[_customerIndex];
    customer->CancelOrder();
}

/*
	�禡�\��: ���o�ثe�ȤH�q��

	�Ѽ�: �L

	�^�ǭ�: �ثe�ȤH�q��
*/
const Order* Mall::GetCurrentOrder() const
{
    Customer* customer = _customers[_customerIndex];
    return customer->GetCurrentOrder();
}

const vector<Order*>* Mall::GetPurchasedHistoryFrom() const
{
    return _customers[_customerIndex]->GetPurchasedHistoryFrom(_shops[_shopIndex]);
}

/*
	�禡�\��: ���o�Ҧ��ө����

	�Ѽ�: �L

	�^�ǭ�: �Ҧ��ө����
*/
const vector<Shop*>* Mall::GetShops() const
{
    return &_shops;
}

/*
	�禡�\��: ���o�Ӱө��Ҧ���A���

	�Ѽ�: �L

	�^�ǭ�: �Ҧ���A���
*/
const vector<Cloth*>* Mall::GetClothes() const
{
    Shop* shop = _shops[_shopIndex];
    return shop->GetClothes();
}

/*
	�禡�\��: ���o�Ҧ��ȤH���

	�Ѽ�: �L

	�^�ǭ�: �Ҧ��ȤH���
*/
const vector<Customer*>* Mall::GetCustomers() const
{
    return &_customers;
}

/*
	�禡�\��: ���J�~�����a���

	�Ѽ�: �ɮצW��

	�^�ǭ�: �L
*/
void Mall::LoadShopsData(string fileName)
{
    fstream file;
    //�ө����Y�W�h
    regex rule("^Shop .+:$");
    file.open(fileName, ios::in);

    if (!file)
        return;

    //�ө����Y �ө��W��
    string shopHead, shopName;
    //�ө����
    Shop* shop;

    while (!file.eof())
    {
        shopHead = ReadShopHead(file);

        //�ˬd�O�_�ŦX�W�h
        if (!regex_match(shopHead, rule))
            break;

        shopName = GetShopName(shopHead);
        //�إ߰ө�
        shop = new Shop(shopName);
        //�[�J�ܰө��M��
        _shops.push_back(shop);
        LoadClothesData(file, shop);
    }

    file.close();
}

/*
	�禡�\��: ���J�ө���A���

	�Ѽ�: file => �ɮ׸�Ƭy, shop => �ө�����

	�^�ǭ�: �L
*/
void Mall::LoadClothesData(fstream& file, Shop* shop)
{
    //�O���̫�Ū�ɦ�m
    streampos lastReadPosition = file.tellg();
    //��AIndex
    int index;
    //��A�W��, ��A�y�z
    string name, description;
    //��A����
    double price;
    //�ɮ�index��offset��
    int idOffset = -1;

    while (IsClothData(file, lastReadPosition))
    {
        index = ReadClothIndex(file);

        //�����Ĥ@����A��ƪ�index��id��offset
        if (idOffset == -1)
            idOffset = index;

        name = ReadClothName(file);
        description = ReadClothDescription(file);

        if (IsSuiteData(file, lastReadPosition))
        {
            shop->AddCloth(new Suite(name, description, index - idOffset + 1));
            LoadSuiteData(file, shop, idOffset);
        }
        else
        {
            price = ReadClothPrice(file);
            shop->AddCloth(new Cloth(name, description, price, index - idOffset + 1));
        }

        //�O���̫�Ū�ɦ�m
        lastReadPosition = file.tellg();
    }
}

/*
	�禡�\��: ���J�M�˸��

	�Ѽ�: file => �ɮ׸�Ƭy, shop => �ө�����, idOffset => index��Offset��

	�^�ǭ�: �L
*/
void Mall::LoadSuiteData(fstream& file, Shop* shop, int idOffset)
{
    Suite* suite = (Suite*)(*(*shop->GetClothes()).rbegin());

    do
    {
        int clothIndex;
        file >> clothIndex;
        Cloth* cloth = shop->FindCloth(clothIndex - idOffset + 1);
        suite->Add(cloth);
    }
    while (!file.eof() && file.get() != '\n');
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
	�禡�\��: Ū����Aindex

	�Ѽ�: �ɮ׸�Ƭy

	�^�ǭ�: ���ޭ�
*/
int Mall::ReadClothIndex(fstream& file) const
{
    string index;
    getline(file, index, ',');
    //�����Ů�
    file.ignore(1);
    return stoi(index);
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

/*
	�禡�\��: �ˬd�O�_���M�˸��

	�Ѽ�: file => �ɮ׸�Ƭy, lastReadPosition => �̫�Ū���ɮת���m

	�^�ǭ�: �ө��W��
*/
bool Mall::IsSuiteData(fstream& file, streampos& lastReadPosition) const
{
    string type;
    //Suite��ƳW�h
    regex rule("^Suite.+$");
    //�O���̫�Ū�ɦ�m
    lastReadPosition = file.tellg();
    getline(file, type, '\n');
    //rollback
    file.seekg(lastReadPosition);

    if (regex_match(type, rule))
    {
        //���ʦ�Suite����Ʀ�m
        file.seekg(7, ios::cur);
        return true;
    }

    return false;
}

Mall::~Mall()
{
    for (size_t i = 0; i < _customers.size(); i++)
        delete _customers[i];

    for (size_t i = 0; i < _shops.size(); i++)
        delete _shops[i];
}