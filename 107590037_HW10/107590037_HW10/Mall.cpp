#include "Mall.h"

#include <regex>
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
    shop->createNewCloth(name, description, price);
}

void Mall::MakeNewOrder()
{
    Shop* shop = _shops[_shopIndex];
    _customers[_customerIndex]->MakeNewOrder(shop);
}

void Mall::AddOrderToCloth(int id)
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

bool Mall::IsPointEnough() const
{
    Customer* customer = _customers[_customerIndex];
    return customer->IsPointEnough();
}

double Mall::GetCash() const
{
    Customer* customer = _customers[_customerIndex];
    return customer->GetCash();
}

void Mall::ReducePointFromOrder()
{
    Customer* customer = _customers[_customerIndex];
    customer->ReducePointFromOrder();
}

void Mall::CancelOrder()
{
    Customer* customer = _customers[_customerIndex];
    customer->CancelOrder();
}

const Order* Mall::GetCurrentOrder() const
{
    Customer* customer = _customers[_customerIndex];
    return customer->GetCurrentOrder();
}

const vector<Shop*>* Mall::GetShops() const
{
    return &_shops;
}

const vector<Cloth*>* Mall::GetClothes() const
{
    Shop* shop = _shops[_shopIndex];
    return shop->GetClothes();
}

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
    //檔案資料流
    fstream file;
    //商店檔頭規則
    regex rule("^Shop .+:$");
    //打開檔案
    file.open(fileName, ios::in);

    //找不到檔案則退出
    if (!file)
        return;

    //商店檔頭 商店名稱
    string shopHead, shopName;
    //商店資料
    Shop* shop;

    while (!file.eof())
    {
        //讀取商店檔頭
        shopHead = ReadShopHead(file);

        //檢查是否符合規則
        if (!regex_match(shopHead, rule))
            break;

        //取得檔頭中的商店名稱
        shopName = GetShopName(shopHead);
        //建立商店
        shop = new Shop(shopName);
        //加入至商店清單
        _shops.push_back(shop);
        //載入商店衣服資料
        LoadClothesData(file, shop);
    }

    //關閉檔案
    file.close();
}

/*
	函式功能: 載入商店衣服資料

	參數: file => 檔案資料流, shop => 商店物件

	回傳值: 無
*/
void Mall::LoadClothesData(fstream& file, Shop* shop)
{
    //紀錄最後讀檔位置
    streampos lastReadPosition = file.tellg();
    //衣服名稱, 衣服描述, 衣服價格
    string name, description;
    double price;

    while (IsClothData(file, lastReadPosition))
    {
        //讀取衣服名稱
        name = ReadClothName(file);
        //讀取衣服描述
        description = ReadClothDescription(file);
        //讀取衣服價格
        price = ReadClothPrice(file);
        //紀錄最後讀檔位置
        lastReadPosition = file.tellg();
        //建立衣服資料
        shop->createNewCloth(name, description, price);
    }
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

Mall::~Mall()
{
    for (size_t i = 0; i < _customers.size(); i++)
        delete _customers[i];

    for (size_t i = 0; i < _shops.size(); i++)
        delete _shops[i];
}