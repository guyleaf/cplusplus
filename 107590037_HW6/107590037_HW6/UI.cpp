#include "UI.h"

#include <iostream>
#include <string>
#include <regex>
#include <iomanip>

using namespace std;

//釋放Shop記憶體
UI::~UI()
{
    delete _shop;
}
/*
	函式功能: 顯示選單

	參數: 無

	回傳值: 無
*/
void UI::ShowMenu()
{
    //創建商店
    CreateShop("H&M");
    //儲存輸入指令代號
    int command;

    while (true)
    {
        cout << "(" + _shop->GetName() + ")1.新增衣服" << endl;
        cout << "(" + _shop->GetName() + ")2.查看所有衣服" << endl;
        cout << "(" + _shop->GetName() + ")3.結束程式" << endl;
        cout << "請輸入選擇: ";
        //取得輸入指令代號
        command = GetCommand();

        if (command == 1) //功能一 新增衣服
            AddNewClothes();
        else if (command == 2) //功能二 顯示所有衣服庫存
            DisplayAllClothes();
        else if (command == 3) //離開
            break;
    }
}

/*
	函式功能: 取得輸入指令代號

	參數: 無

	回傳值: 指令代號
*/
int UI::GetCommand()
{
    //輸入規則
    regex rule("^[1-3]$");
    //暫存輸入值
    string input;

    while (getline(cin, input))
    {
        if (regex_match(input, rule))
            break;
        else
            cout << "請輸入正確的選項: ";
    }

    return stoi(input); //字串轉整數
}

/*
	函式功能: 新增衣服

	參數: 無

	回傳值: 無
*/
void UI::AddNewClothes()
{
    //暫存輸入資料
    string input;
    //暫存衣服商品資料
    string name, description;
    double price;
    cout << "請輸入衣服名稱: ";
    getline(cin, name);
    cout << "請輸入衣服描述: ";
    getline(cin, description);
    cout << "請輸入價格: ";

    while (getline(cin, input))
    {
        //符合規則且價格不為零
        if (IsNumber(input) && IsPositive(input) && stod(input) != 0)
        {
            //字串轉doeble
            price = stod(input);
            break;
        }

        //判斷輸入是哪種錯誤
        //先前已判斷是否為正數與不等於0，所以只需要判斷是否為數字即可
        if (IsNumber(input))
            cout << "價格不能小於等於零，請重新輸入" << endl;
        else
            cout << "價格不允許非數字格式，請重新輸入" << endl;

        cout << "請輸入價格: ";
    }

    //建立衣服資料
    _shop->CreateNewCloth(name, description, price);
}

/*
	函式功能: 顯示店家所有衣服資料

	參數: 無

	回傳值: 無
*/
void UI::DisplayAllClothes() const
{
    //取得店家所有衣服資料
    vector<Cloth*>* clothesData = _shop->GetClothes();
    cout << left << setw(8) << "No." << left << setw(48) << "衣服名稱" << left << setw(8) << "價格" << "描述" << endl;

    //輸出衣服資料
    //此處的i本身是指向vector位址，所以需要*解參考取得Cloth物件位址，反之**代表是Cloth物件的內容
    for (vector<Cloth*>::iterator i = clothesData->begin(); i != clothesData->end(); i++)
    {
        cout << left << setw(8) << (*i)->GetId()
             << left << setw(48) << (*i)->GetName()
             << left << setw(8) << setprecision(1) << fixed << (*i)->GetPrice()
             << (*i)->GetDescription() << endl;
    }

    //釋放記憶體
    delete clothesData;
}

/*
	函式功能: 創建商店

	參數: 店家名字: string

	回傳值: 無
*/
void UI::CreateShop(string name)
{
    _shop = new Shop(name);
}

/*
	函式功能: 判斷是否為數字

	參數: 輸入資料 string

	回傳值: true/false
*/
bool UI::IsNumber(string input)
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
bool UI::IsPositive(string input)
{
    if (stod(input) >= 0)
        return true;

    return false;
}