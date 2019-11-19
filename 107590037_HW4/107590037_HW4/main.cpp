/*
	Author: 資工二 107590037 應耀德

	程式功能: 模擬加油站系統，實作人機介面

	完成日期: 2019/10/03
*/
#include <iostream>
#include <regex>
using namespace std;
#include "GasPump.h"

/*
	函式功能: 創建GasPump物件並初始化設定油價，使用者輸入1加侖的油價

	參數: GasPump物件指標 (call by reference)

	回傳值: true/false(是否設置成功)
*/
bool SetGasPump(GasPump*& gasPump)
{
    //暫存輸入資料
    string input;
    //正則表達式 防止指令輸入格式不正確
    regex rule1("^[0-9]+\\.[0-9]+$");
    regex rule2("^[0-9]+$");
    cout << "請輸入1加侖的價格: ";
    getline(cin, input);
    //釋放先前已設置過的物件
    delete gasPump;

    //檢查輸入是否合法，不合法則輸出無效並返回選單
    if (regex_match(input, rule1) || regex_match(input, rule2))
    {
        //string轉double型態，設置油價
        gasPump = new GasPump(stod(input));
        return true;
    }

    //避免重新設置時，無效輸入，遺留先前物件的記憶體位址(導致delete位址不存在)
    gasPump = NULL;
    cout << "無效輸入\n" << endl;
    return false;
}

/*
	函式功能: 顯示目前油價

	參數: const GasPump物件 (call by reference)

	回傳值: 無
*/
void DisplayCurrentPrice(const GasPump* gasPump)
{
    cout << "目前油價為 每加侖 "
         << gasPump->GetGallonPrice()
         << " 元， 每公升 "
         << gasPump->GetLiterPrice()
         << " 元\n" << endl;
}

/*
	函式功能: 顯示上一次加油的資訊

	參數: const GasPump物件 (call by reference)

	回傳值: 無
*/
void DisplayLastInfo(const GasPump* gasPump)
{
    cout << gasPump->GetAmountCharged()
         << " 公升, "
         << gasPump->GetAmountDispensed()
         << " 元\n" << endl;
}

/*
	函式功能: 加油程序，使用者輸入要加多少公升數的油，顯示加油進度

	參數: GasPump物件 (call by reference)

	回傳值: 無
*/
void StartFilling(GasPump* gasPump)
{
    //暫存輸入資料
    string input;
    //正則表達式 防止指令輸入格式不正確
    regex rule("^[0-9]+$");
    cout << "請輸入要加幾公升的油: ";
    getline(cin, input);

    //檢查輸入是否合法，不合法則跳過加油程序並返回選單
    if (regex_match(input, rule))
    {
        //開始加油
        vector<string> gasInfo = gasPump->Start(stoi(input));

        //輸出加油進度
        for (vector<string>::iterator sentence = gasInfo.begin(); sentence != gasInfo.end(); sentence++)
        {
            cout << *sentence << endl;
        }

        return;
    }

    cout << "無效輸入\n" << endl;
    return;
}

//模式選擇器
void ModeController()
{
    //是否已設置油價
    bool priceIsSet = false;
    //宣告gaspump物件指標為NULL
    GasPump* gasPump = NULL;
    //暫存輸入指令
    string command;
    //正則表達式 防止指令輸入格式不正確
    regex rule("^[1-5]$");

    while (true)
    {
        cout << "1. 設定油價" << endl;
        cout << "2. 顯示目前的油價" << endl;
        cout << "3. 顯示上一次加油的資訊" << endl;
        cout << "4. 開始加油" << endl;
        cout << "5. 結束" << endl;
        cout << "請輸入指令: ";
        getline(cin, command);

        //檢查指令是否合法
        if (regex_match(command, rule))
        {
            if (command == "1")  //mode 1 設定油價
                priceIsSet = SetGasPump(gasPump);
            else if (command == "5") //mode 5 離開
                break;
            else if (priceIsSet) //檢查是否油價已設置
            {
                if (command == "2") //mode 2 顯示目前的油價
                    DisplayCurrentPrice(gasPump);
                else if (command == "3") //mode 3 顯示上一次加油的資訊
                    DisplayLastInfo(gasPump);
                else if (command == "4") //mode 4 進入加油程序
                    StartFilling(gasPump);
            }
            else
                cout << "請先設定油價\n" << endl;
        }
    }

    //釋放記憶體
    delete gasPump;
}

int main()
{
    //模式選擇器
    ModeController();
    system("PAUSE");
    return 0;
}