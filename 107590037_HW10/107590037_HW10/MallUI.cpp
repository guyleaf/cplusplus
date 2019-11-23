#include "MallUI.h"
#include <iostream>
#include <regex>
#include <iomanip>
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

        //商場選單
        MallsMenu(shopName);
        SelectCustomerAndShop(customerName, shopName);
        //商店選單
        ShopMenu(shopName, customerName);
    }
}

/*
	函式功能: 顯示Malls's Menu

	參數: 無

	回傳值: 無
*/
void MallUI::ShowMallsMenu() const
{
    //列出店家清單
    for (size_t i = 0; i < _numberOfShops; i++)
        cout << i + 1 << "." << _shopsOrder[i] << endl;
}

string MallUI::GetCustomerName(int command) const
{
    return _customersOrder[command - 1];
}

string MallUI::GetShopName(int command) const
{
    return _shopsOrder[command - 1];
}

void MallUI::ShowCustomersMenu() const
{
    for (size_t i = 0; i < _numberOfCustomers; i++)
        cout << i + 1 << "." << _customersOrder[i] << endl;

    cout << _numberOfCustomers + 1 << "." << "離開" << endl;
}

void MallUI::CustomersMenu(string& customerName)
{
    //暫存輸入資料
    string command;
    const string MAX_COMMAND_SIZE = to_string(_numberOfCustomers);
    const string EXIT_COMMAND = to_string(_numberOfCustomers + 1);
    //選擇客人規則
    regex rule("^[1-" + MAX_COMMAND_SIZE + "]$");
    ShowCustomersMenu();

    while (true)
    {
        cout << "select customer: ";
        command = GetCommand();

        //檢查是否符合選擇商店規則
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
	函式功能: 商場選單

	參數: 選定的商店名稱

	回傳值: 無
*/
void MallUI::MallsMenu(string& shopName)
{
    //暫存輸入資料
    string command;
    const string MAX_COMMAND_SIZE = to_string(_numberOfShops);
    const string EXIT_COMMAND = to_string(_numberOfShops + 1);
    //選擇商店規則
    regex rule("^[1-" + MAX_COMMAND_SIZE + "]$");
    ShowMallsMenu();

    while (true)
    {
        cout << "Select Shop: ";
        command = GetCommand();

        //檢查是否符合選擇商店規則
        if (regex_match(command, rule))
        {
            shopName = GetShopName(stoi(command));
            break;
        }

        cout << "請選擇畫面上的店家" << endl;
    }
}

/*
	函式功能: 顯示商店選單

	參數: 選定的商店名稱

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

	參數: 選定的商店名稱

	回傳值: 無
*/
void MallUI::ShopMenu(string& shopName, string& customerName)
{
    regex rule("^[1-8]$");
    //儲存輸入指令代號
    string command;
    ShowShopMenu(shopName, customerName);

    while (true)
    {
        //取得商店選單輸入指令
        command = GetCommand();

        if (regex_match(command, rule))
        {
            if (command == "1") //功能一 新增衣服
                AddNewClothes();
            else if (command == "2") //功能二 顯示所有衣服庫存
                DisplayAllClothes();
            else if (command == "3") //功能三 建立新訂單
                MakeNewOrder();
            else if (command == "4") //功能四 購買衣服
                AddClothesToOrder();
            else if (command == "5") //功能五 結束訂單
                CheckOutOrder();
            else if (command == "6") //功能六 查看剩餘點數
                CheckLeftPoint();
            else if (command == "7") //功能七 查看歷史收據
                CheckPastOrders();
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
            //字串轉doeble
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
    //暫存商品價格
    string name = GetClothName();
    string description = GetClothDescription();
    double price = GetClothPrice();
    //建立衣服資料
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

void MallUI::MakeNewOrder()
{
    _mall->MakeNewOrder();
    cout << "成功建立新訂單!!!" << endl << endl;
}

void MallUI::AddClothesToOrder()
{
    if (_mall->GetCurrentOrder() == NULL)
    {
        cout << "請建立訂單，才能購買衣服!" << endl << endl;
        return;
    }

    DisplayAllClothes();

    while (true)
    {
        int clothIndex = GetClothIndex();

        if (clothIndex == -1)
            break;

        int clothCount = GetClothCount();

        for (int i = 0; i < clothCount; i++)
            _mall->AddOrderToCloth(clothIndex);
    }
}

void MallUI::CheckOutOrder()
{
    if (_mall->GetCurrentOrder() == NULL)
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

void MallUI::CheckLeftPoint()
{
    cout << "您剩餘的點數剩下: " << _mall->GetCash() << endl << endl;
}

void MallUI::CheckPastOrders()
{
    return;
}

int MallUI::GetClothIndex()
{
    string input;
    cout << "請輸入衣服ID, 離開請輸入-1: ";
    getline(cin, input);
    return stoi(input);
}

int MallUI::GetClothCount()
{
    string input;
    cout << "請輸入衣服數量: ";
    getline(cin, input);
    return stoi(input);
}
/*
	函式功能: 選擇客人與商店

	參數: customerName => 客人名稱, shopName => 商店名稱

	回傳值: 無
*/
void MallUI::SelectCustomerAndShop(const string customerName, const string shopName) const
{
    const vector<Customer*>* customers = _mall->GetCustomers();
    const vector<Shop*>* shops = _mall->GetShops();
    int customerIndex, shopIndex;

    for (size_t i = 0; i < customers->size(); i++)
    {
        if ((*customers)[i]->GetName() == customerName)
        {
            customerIndex = i;
            break;
        }
    }

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

	參數: 輸入資料 string

	回傳值: true/false
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

	參數: 輸入資料 string

	回傳值: true/false
*/
bool MallUI::IsPositive(string input)
{
    if (stod(input) >= 0)
        return true;

    return false;
}