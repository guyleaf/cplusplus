#include "Mall.h"

#include <regex>
#include <iostream>
using namespace std;

/*
	函式功能: 初始化商場

	參數: 無

	回傳值: 無
*/
Mall::Mall()
{
    LoadShopsData("Cloth.txt");
    _customers.push_back(new Customer("Amber"));
    _customers.push_back(new Customer("Tim"));
    _customers.push_back(new Customer("Marry"));
}


/*
	函式功能: 建立衣服資料

	參數: name: 商品名字, description: 商品描述, price: 商品價格

	回傳值: 無
*/
void Mall::CreateNewCloth(string name, string description, double price)
{
    Shop* shop = _shops[_shopIndex];
    shop->CreateNewCloth(name, description, price);
}

/*
	函式功能: 建立新訂單

	參數: 無

	回傳值: 無
*/
void Mall::MakeNewOrder()
{
    Shop* shop = _shops[_shopIndex];
    _customers[_customerIndex]->MakeNewOrder(shop);
}

/*
	函式功能: 加入衣服至訂單中

	參數: 衣服ID

	回傳值: 無
*/
void Mall::AddClothToOrder(int id)
{
    Shop* shop = _shops[_shopIndex];
    Cloth* cloth = shop->FindCloth(id);
    Customer* customer = _customers[_customerIndex];
    customer->AddClothToOrder(cloth);
}


/*
	函式功能: 選擇客人與商店

	參數: 客人編號, 商店編號

	回傳值: 無
*/
void Mall::SelectCustomerAndShop(size_t customerIndex, size_t shopIndex)
{
    _shopIndex = shopIndex;
    _customerIndex = customerIndex;
}

/*
	函式功能: 檢查點數是否足夠

	參數: 無

	回傳值: True/False
*/
bool Mall::IsPointEnough() const
{
    Customer* customer = _customers[_customerIndex];
    return customer->IsPointEnough();
}

/*
	函式功能: 取得點數

	參數: 無

	回傳值: 點數
*/
double Mall::GetCash() const
{
    Customer* customer = _customers[_customerIndex];
    return customer->GetCash();
}

/*
	函式功能: 訂單扣除點數

	參數: 無

	回傳值: 無
*/
void Mall::ReducePointFromOrder()
{
    Customer* customer = _customers[_customerIndex];
    customer->ReducePointFromOrder();
}

/*
	函式功能: 取消訂單

	參數: 無

	回傳值: 無
*/
void Mall::CancelOrder()
{
    Customer* customer = _customers[_customerIndex];
    customer->CancelOrder();
}

/*
	函式功能: 取得目前客人訂單

	參數: 無

	回傳值: 目前客人訂單
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
	函式功能: 取得所有商店資料

	參數: 無

	回傳值: 所有商店資料
*/
const vector<Shop*>* Mall::GetShops() const
{
    return &_shops;
}

/*
	函式功能: 取得該商店所有衣服資料

	參數: 無

	回傳值: 所有衣服資料
*/
const vector<Cloth*>* Mall::GetClothes() const
{
    Shop* shop = _shops[_shopIndex];
    return shop->GetClothes();
}

/*
	函式功能: 取得所有客人資料

	參數: 無

	回傳值: 所有客人資料
*/
const vector<Customer*>* Mall::GetCustomers() const
{
    return &_customers;
}

/*
	函式功能: 載入外部店家資料

	參數: 檔案名稱

	回傳值: 無
*/
void Mall::LoadShopsData(string fileName)
{
    fstream file;
    //商店檔頭規則
    regex rule("^Shop .+:$");
    file.open(fileName, ios::in);

    if (!file)
        return;

    //商店檔頭 商店名稱
    string shopHead, shopName;
    //商店資料
    Shop* shop;

    while (!file.eof())
    {
        shopHead = ReadShopHead(file);

        //檢查是否符合規則
        if (!regex_match(shopHead, rule))
            break;

        shopName = GetShopName(shopHead);
        //建立商店
        shop = new Shop(shopName);
        //加入至商店清單
        _shops.push_back(shop);
        LoadClothesData(file, shop);
    }

    file.close();
}

/*
	函式功能: 載入商店衣服資料

	參數: file => 檔案資料流, shop => 商店物件

	回傳值: 無
*/
void Mall::LoadClothesData(fstream& file, Shop* shop)
{
    //記錄最後讀檔位置
    streampos lastReadPosition = file.tellg();
    //衣服Index
    int index;
    //衣服名稱, 衣服描述
    string name, description;
    //衣服價格
    double price;
    //檔案index的offset值
    int idOffset = -1;

    while (IsClothData(file, lastReadPosition))
    {
        index = ReadClothIndex(file);

        //紀錄第一筆衣服資料的index為id的offset
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

        //記錄最後讀檔位置
        lastReadPosition = file.tellg();
    }
}

/*
	函式功能: 載入套裝資料

	參數: file => 檔案資料流, shop => 商店物件, idOffset => index的Offset值

	回傳值: 無
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
	函式功能: 讀取商店標頭

	參數: 檔案資料流

	回傳值: 商店標頭
*/
string Mall::ReadShopHead(fstream& file) const
{
    string shopHead;
    getline(file, shopHead, '\n');
    return shopHead;
}

/*
	函式功能: 取得商店名稱

	參數: 商店標頭

	回傳值: 商店名稱
*/
string Mall::GetShopName(const string& shopHead) const
{
    string shopName;
    shopName = shopHead.substr(5, shopHead.size() - 6);
    return shopName;
}

/*
	函式功能: 讀取衣服index

	參數: 檔案資料流

	回傳值: 索引值
*/
int Mall::ReadClothIndex(fstream& file) const
{
    string index;
    getline(file, index, ',');
    //忽略空格
    file.ignore(1);
    return stoi(index);
}

/*
	函式功能: 讀取衣服名稱

	參數: 檔案資料流

	回傳值: 衣服名稱
*/
string Mall::ReadClothName(fstream& file) const
{
    string name;
    getline(file, name, ',');
    //忽略空格
    file.ignore(1);
    return name;
}

/*
	函式功能: 讀取衣服描述

	參數: 檔案資料流

	回傳值: 衣服描述
*/
string Mall::ReadClothDescription(fstream& file) const
{
    string description;
    getline(file, description, ',');
    //忽略空格
    file.ignore(1);
    return description;
}

/*
	函式功能: 讀取衣服價格

	參數: 檔案資料流

	回傳值: 衣服價格
*/
double Mall::ReadClothPrice(fstream& file) const
{
    string price;
    getline(file, price, '\n');
    return stod(price);
}

/*
	函式功能: 檢查是否為衣服資料

	參數: file => 檔案資料流, lastReadPosition => 最後讀取檔案的位置

	回傳值: 商店名稱
*/
bool Mall::IsClothData(fstream& file, streampos& lastReadPosition) const
{
    string data;
    //衣服資料規則
    regex rule("^.+, .+, .+$");
    getline(file, data, '\n');
    //rollback
    file.seekg(lastReadPosition);

    //檢查是否為衣服資料
    if (regex_match(data, rule))
        return true;

    return false;
}

/*
	函式功能: 檢查是否為套裝資料

	參數: file => 檔案資料流, lastReadPosition => 最後讀取檔案的位置

	回傳值: 商店名稱
*/
bool Mall::IsSuiteData(fstream& file, streampos& lastReadPosition) const
{
    string type;
    //Suite資料規則
    regex rule("^Suite.+$");
    //記錄最後讀檔位置
    lastReadPosition = file.tellg();
    getline(file, type, '\n');
    //rollback
    file.seekg(lastReadPosition);

    if (regex_match(type, rule))
    {
        //移動至Suite的資料位置
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