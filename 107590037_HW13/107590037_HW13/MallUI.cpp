#include "MallUI.h"
#include <iostream>
#include <regex>
#include <iomanip>
#include <utility>
using namespace std;

/*
	函式功能: 初始化商場UI

	參數: 商場Model

	回傳值: 無
*/
MallUI::MallUI(Mall* mall)
{
    _mall = mall;
    _exit = false;
    _shopsOrder.push_back("UNIQLO");
    _shopsOrder.push_back("H&M");
    _shopsOrder.push_back("ZARA");
    _numberOfShops = _shopsOrder.size();
    _customersOrder.push_back("Amber");
    _customersOrder.push_back("Tim");
    _customersOrder.push_back("Marry");
    _numberOfCustomers = _customersOrder.size();
}

/*
	函式功能: 顯示UI畫面

	參數: 無

	回傳值: 無
*/
void MallUI::Start()
{
    //選定的商店名稱
    string shopName, customerName;

    while (!_exit)
    {
        CustomersMenu(customerName);

        //離開
        if (_exit)
            break;

        MallsMenu(shopName);
        SelectCustomerAndShop(customerName, shopName);
        ShopMenu(shopName, customerName);
    }
}

/*
	函式功能: 取得客人名稱

	參數: index

	回傳值: 客人名稱
*/
string MallUI::GetCustomerName(int index) const
{
    return _customersOrder[index - 1];
}

/*
	函式功能: 取得商店名稱

	參數: index

	回傳值: 商店名稱
*/
string MallUI::GetShopName(int index) const
{
    return _shopsOrder[index - 1];
}

/*
	函式功能: 顯示客人選單UI

	參數: 無

	回傳值: 無
*/
void MallUI::ShowCustomersMenu() const
{
    //列出客人選單
    for (size_t i = 0; i < _numberOfCustomers; i++)
        cout << i + 1 << "." << _customersOrder[i] << endl;

    cout << _numberOfCustomers + 1 << "." << "離開" << endl;
}

/*
	函式功能: 客人選單

	參數: 選定的客人名稱

	回傳值: 無
*/
void MallUI::CustomersMenu(string& customerName)
{
    //暫存輸入資料
    string command;
    const size_t MAX_COMMAND_SIZE = _numberOfCustomers;
    const string EXIT_COMMAND = to_string(_numberOfCustomers + 1);
    //選擇客人規則
    regex rule("^[1-" + to_string(MAX_COMMAND_SIZE) + "]$");
    ShowCustomersMenu();

    while (true)
    {
        cout << "select customer: ";
        //取得選單輸入指令
        command = GetCommand();

        //檢查是否符合選擇客人規則
        if (regex_match(command, rule))
        {
            customerName = GetCustomerName(stoi(command));
            break;
        }
        else if (command == EXIT_COMMAND)
        {
            _exit = true;
            break;
        }

        cout << "請選擇畫面上的客人" << endl;
    }
}

/*
	函式功能: 顯示商場選單UI

	參數: 無

	回傳值: 無
*/
void MallUI::ShowMallsMenu() const
{
    //列出店家清單
    for (size_t i = 0; i < _numberOfShops; i++)
        cout << i + 1 << "." << _shopsOrder[i] << endl;
}

/*
	函式功能: 商場選單

	參數: 選定的商店名稱

	回傳值: 無
*/
void MallUI::MallsMenu(string& shopName)
{
    //暫存輸入資料
    string command;
    const size_t MAX_COMMAND_SIZE = _numberOfShops;
    const string EXIT_COMMAND = to_string(_numberOfShops + 1);
    //選擇商店規則
    regex rule("^[1-" + to_string(MAX_COMMAND_SIZE) + "]$");
    ShowMallsMenu();

    while (true)
    {
        cout << "Select Shop: ";
        //取得選單輸入指令
        command = GetCommand();

        //檢查是否符合選擇商場規則
        if (regex_match(command, rule))
        {
            shopName = GetShopName(stoi(command));
            break;
        }

        cout << "請選擇畫面上的店家" << endl;
    }
}

/*
	函式功能: 顯示商店選單UI

	參數: shopName => 選定的商店名稱, customerName => 選定的客人名稱

	回傳值: 無
*/
void MallUI::ShowShopMenu(const string shopName, const string customerName) const
{
    cout << "親愛的的顧客: " << customerName << "，您好!" << endl;
    cout << "(" + shopName + ")1.新增衣服" << endl;
    cout << "(" + shopName + ")2.查看所有衣服" << endl;
    cout << "(" + shopName + ")3.建立新訂單" << endl;
    cout << "(" + shopName + ")4.購買衣服" << endl;
    cout << "(" + shopName + ")5.結束訂單" << endl;
    cout << "(" + shopName + ")6.查看剩餘點數" << endl;
    cout << "(" + shopName + ")7.查看歷史收據" << endl;
    cout << "(" + shopName + ")8.離開" << endl;
    cout << "請輸入選擇: ";
}

/*
	函式功能: 商店選單

	參數: shopName => 選定的商店名稱, customerName => 選定的客人名稱

	回傳值: 無
*/
void MallUI::ShopMenu(string& shopName, string& customerName)
{
    //儲存輸入指令代號
    string command;
    //選擇商店規則
    regex rule("^[1-8]$");
    ShowShopMenu(shopName, customerName);

    while (true)
    {
        //取得選單輸入指令
        command = GetCommand();

        //檢查是否符合選擇商店規則
        if (regex_match(command, rule))
        {
            if (command == "1") //功能一 新增衣服
                AddNewClothes();
            else if (command == "2") //功能二 顯示所有衣服庫存
                DisplayAllClothes();
            else if (command == "3") //功能三 建立新訂單
                MakeNewOrder();
            else if (command == "4") //功能四 購買衣服
                AddClothesToOrder(shopName);
            else if (command == "5") //功能五 結束訂單
                CheckOutOrder(shopName);
            else if (command == "6") //功能六 查看剩餘點數
                CheckLeftPoint();
            else if (command == "7") //功能七 查看歷史收據
                CheckPastOrders(customerName);
            else if (command == "8") //返回商場
                break;

            ShowShopMenu(shopName, customerName);
        }
        else
            cout << "請輸入正確的選項: ";
    }
}

/*
	函式功能: 取得選單輸入指令

	參數: 無

	回傳值: 指令代號
*/
string MallUI::GetCommand()
{
    //暫存輸入值
    string input;
    getline(cin, input);
    return input;
}

/*
	函式功能: 取得衣服名稱

	參數: 無

	回傳值: 衣服名稱
*/
string MallUI::GetClothName()
{
    //暫存輸入值
    string input;
    cout << "請輸入衣服名稱: ";
    getline(cin, input);
    return input;
}

/*
	函式功能: 取得衣服描述

	參數: 無

	回傳值: 衣服描述
*/
string MallUI::GetClothDescription()
{
    //暫存輸入值
    string input;
    cout << "請輸入衣服描述: ";
    getline(cin, input);
    return input;
}

/*
	函式功能: 取得衣服價格

	參數: 無

	回傳值: 衣服價格
*/
double MallUI::GetClothPrice()
{
    //暫存輸入資料
    string data;
    double price;
    cout << "請輸入價格: ";

    while (getline(cin, data))
    {
        //符合規則且價格不為零
        if (IsNumber(data) && IsPositive(data) && stod(data) != 0)
        {
            price = stod(data);
            break;
        }

        //判斷輸入是哪種錯誤
        //先前已判斷是否為正數與不等於0，所以只需要判斷是否為數字即可
        if (IsNumber(data))
            cout << "價格不能小於等於零，請重新輸入" << endl;
        else
            cout << "價格不允許非數字格式，請重新輸入" << endl;

        cout << "請輸入價格: ";
    }

    return price;
}

/*
	函式功能: 新增衣服

	參數: 無

	回傳值: 無
*/
void MallUI::AddNewClothes()
{
    string name = GetClothName();
    string description = GetClothDescription();
    double price = GetClothPrice();
    _mall->CreateNewCloth(name, description, price);
}

/*
	函式功能: 顯示店家所有衣服資料

	參數: 無

	回傳值: 無
*/
void MallUI::DisplayAllClothes() const
{
    //取得店家所有衣服資料
    const vector<Cloth*>* clothesData = _mall->GetClothes();
    cout << left << setw(8) << "No." << left << setw(48) << "衣服名稱" << left << setw(8) << "價格" << "描述" << endl;

    //輸出衣服資料
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
	函式功能: 建立新訂單

	參數: 無

	回傳值: 無
*/
void MallUI::MakeNewOrder()
{
    _mall->MakeNewOrder();
    cout << "成功建立新訂單!!!" << endl << endl;
}

/*
	函式功能: 購買衣服

	參數: 無

	回傳值: 無
*/
void MallUI::AddClothesToOrder(string shopName)
{
    //訂單不存在，則提醒並跳出
    if (_mall->GetCurrentOrder() == NULL || _mall->GetCurrentOrder()->GetShop()->GetName() != shopName)
    {
        cout << "請建立訂單，才能購買衣服!" << endl << endl;
        return;
    }

    DisplayAllClothes();

    while (true)
    {
        int clothIndex = GetClothId();

        //輸入-1時跳出
        if (clothIndex == -1)
            break;

        int clothCount = GetClothCount();

        //依衣服件數而定
        for (int i = 0; i < clothCount; i++)
            _mall->AddClothToOrder(clothIndex);
    }
}

/*
	函式功能: 訂單結帳

	參數: 無

	回傳值: 無
*/
void MallUI::CheckOutOrder(string shopName)
{
    //訂單不存在，則提醒並跳出
    if (_mall->GetCurrentOrder() == NULL or _mall->GetCurrentOrder()->GetShop()->GetName() != shopName)
    {
        cout << "請先建立新訂單，才能夠結束訂單 !" << endl << endl;
        return;
    }

    if (_mall->IsPointEnough())
    {
        _mall->ReducePointFromOrder();
        cout << "訂單結束成功!" << endl << endl;
        return;
    }

    cout << "剩餘點數不足，無法進行購買!" << endl << endl;
    _mall->CancelOrder();
}

/*
	函式功能: 查詢剩餘點數

	參數: 無

	回傳值: 無
*/
void MallUI::CheckLeftPoint()
{
    cout << "您剩餘的點數剩下: " << _mall->GetCash() << endl << endl;
}

/*
	函式功能: 查詢歷史收據

	參數: 無

	回傳值: 無
*/
void MallUI::CheckPastOrders(string customerName)
{
    const vector<Order*>* orders = _mall->GetPurchasedHistoryFrom();
    vector<pair<Cloth*, int>> countedClothes;

    if (orders->size() != 0)
        countedClothes = CountClothesOfOrders(orders);

    delete orders;
    cout << customerName << "的歷史購買紀錄:" << endl;
    cout << left << setw(8) << "名稱" << left << setw(8) << "數量" << left << setw(8) << "單價" << left << setw(8) << "總價" << endl;

    for (size_t i = 0; i < countedClothes.size(); i++)
    {
        if (countedClothes[i].second != 0)
        {
            cout << left << setw(8) << countedClothes[i].first->GetName();
            cout << left << setw(8) << countedClothes[i].second;
            cout << left << setw(8) << countedClothes[i].first->GetPrice();
            cout << left << setw(8) << countedClothes[i].first->GetPrice() * countedClothes[i].second << endl;
        }
    }
}

/*
	函式功能: 統計訂單衣服資料

	參數: 多筆訂單

	回傳值: 已統計的衣服種類
*/
vector<pair<Cloth*, int>> MallUI::CountClothesOfOrders(const vector<Order*>* orders)
{
    //衣服種類
    const vector<Cloth*>* clothesData = _mall->GetClothes();
    //已統計的衣服種類
    vector<pair<Cloth*, int>> countedClothes;

    //初始化輸入衣服種類
    for (size_t i = 0; i < clothesData->size(); i++)
        countedClothes.push_back(make_pair((*clothesData)[i], 0));

    //統計每一筆訂單的衣服資料
    for (size_t i = 0; i < orders->size(); i++)
    {
        //該筆訂單的衣服資料
        const vector<Cloth*>* clothes = (*orders)[i]->GetClothes();

        //統計
        for (size_t j = 0; j < clothes->size(); j++)
        {
            for (size_t k = 0; k < countedClothes.size(); k++)
            {
                if (countedClothes[k].first->GetName() == (*clothes)[j]->GetName())
                    countedClothes[k].second++;
            }
        }
    }

    return countedClothes;
}

/*
	函式功能: 取得衣服ID

	參數: 無

	回傳值: 衣服ID
*/
int MallUI::GetClothId()
{
    string input;
    cout << "請輸入衣服ID, 離開請輸入-1: ";
    getline(cin, input);
    return stoi(input);
}

/*
	函式功能: 取得衣服件數

	參數: 無

	回傳值: 衣服件數
*/
int MallUI::GetClothCount()
{
    string input;
    cout << "請輸入衣服數量: ";
    getline(cin, input);
    return stoi(input);
}

/*
	函式功能: 選擇客人與商店

	參數: customerName => 選定的客人名稱, shopName => 選定的商店名稱

	回傳值: 無
*/
void MallUI::SelectCustomerAndShop(const string customerName, const string shopName) const
{
    //取得所有客人資料
    const vector<Customer*>* customers = _mall->GetCustomers();
    //取得所有商店資料
    const vector<Shop*>* shops = _mall->GetShops();
    size_t customerIndex, shopIndex;

    //查詢customerIndex
    for (size_t i = 0; i < customers->size(); i++)
    {
        if ((*customers)[i]->GetName() == customerName)
        {
            customerIndex = i;
            break;
        }
    }

    //查詢shopIndex
    for (size_t i = 0; i < shops->size(); i++)
    {
        if ((*shops)[i]->GetName() == shopName)
        {
            shopIndex = i;
            break;
        }
    }

    _mall->SelectCustomerAndShop(customerIndex, shopIndex);
}

/*
	函式功能: 判斷是否為數字

	參數: 輸入資料

	回傳值: True/False
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
	函式功能: 判斷是否為正數

	參數: 輸入資料

	回傳值: True/False
*/
bool MallUI::IsPositive(string input)
{
    if (stod(input) >= 0)
        return true;

    return false;
}