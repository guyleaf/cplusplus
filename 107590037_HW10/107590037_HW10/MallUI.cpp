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
}

/*
	函式功能: 顯示UI畫面

	參數: 無

	回傳值: 無
*/
void MallUI::Start()
{
    //選定的商店名稱
    string shopName;

    while (!_exit)
    {
        //商場選單
        MallsMenu(shopName);

        //離開
        if (_exit)
            break;

        //商店選單
        ShopMenu(shopName);
    }
}

/*
	函式功能: 顯示Malls's Menu

	參數: 無

	回傳值: 無
*/
void MallUI::ShowMallsMenu()
{
    //列出店家清單
    for (size_t i = 0; i < _numberOfShops; i++)
        cout << i + 1 << "." << _shopsOrder[i] << endl;

    cout << _numberOfShops + 1 << "." << "結束程式" << endl;
}

/*
	函式功能: 選擇商店

	參數: command => 輸入指令, shopName => 選定的商店名稱

	回傳值: 無
*/
void MallUI::SelectShop(int command, string& shopName)
{
    shopName = _shopsOrder[command - 1];
    int shopIndex = GetShopIndex(shopName);
    _mall->SelectShop(shopIndex);
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
    const string LIMIT_COMMAND_SIZE = to_string(_numberOfShops);
    const string EXIT_COMMAND = to_string(_numberOfShops + 1);
    //選擇商店規則
    regex rule("^[1-" + LIMIT_COMMAND_SIZE + "]$");
    ShowMallsMenu();

    while (true)
    {
        cout << "Select Shop: ";
        command = GetCommand();

        //檢查是否符合選擇商店規則
        if (regex_match(command, rule))
        {
            SelectShop(stoi(command), shopName);
            break;
        }
        else if (command == EXIT_COMMAND)
        {
            _exit = true;
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
void MallUI::ShowShopMenu(const string shopName)
{
    cout << "(" + shopName + ")1.新增衣服" << endl;
    cout << "(" + shopName + ")2.查看所有衣服" << endl;
    cout << "(" + shopName + ")3.返回商場" << endl;
    cout << "請輸入選擇: ";
}

/*
	函式功能: 商店選單

	參數: 選定的商店名稱

	回傳值: 無
*/
void MallUI::ShopMenu(string& shopName)
{
    regex rule("^[1-3]$");
    //儲存輸入指令代號
    string command;
    ShowShopMenu(shopName);

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
            else if (command == "3") //返回商場
                break;

            ShowShopMenu(shopName);
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

/*
	函式功能: 取得商店編號

	參數: 商店名稱

	回傳值: 商店編號
*/
int MallUI::GetShopIndex(const string shopName) const
{
    const vector<Shop*>* shops = _mall->GetShops();

    for (size_t i = 0; i < shops->size(); i++)
    {
        if ((*shops)[i]->GetName() == shopName)
            return (int)i;
    }

    return -1;
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