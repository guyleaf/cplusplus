/*
	Author: 資工二 107590037 應耀德

	程式功能: 協助計算數列之中位數

	完成日期: 2019/10/11
*/
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <regex>
using namespace std;
#include "NumberArray.h"

/*
	函式功能: 分割字串輸入資料

	參數: 字串輸入資料

	回傳值: float型態的數列，分割錯誤則回傳空數列
*/
vector<float> SplitString(const string& input)
{
    //儲存數列之變數
    vector<float> numbers;
    //把字串輸入資料丟入inputstream資料流
    istringstream inputStream(input);
    //暫存已分割字串
    string stringTemp;
    //輸入資料規則
    regex rule1("^-?[0-9]+$");
    regex rule2("^-?[0-9]+\\.[0-9]+$");

    //分割資料
    while (getline(inputStream, stringTemp, ' '))
    {
        //檢查分割資料，不合法則清空數列並跳出
        if (regex_match(stringTemp, rule1) || regex_match(stringTemp, rule2))
            //存入數列並轉換成浮點數
            numbers.push_back(stof(stringTemp));
        else
        {
            //清空數列並跳出
            numbers.clear();
            break;
        }
    }

    return numbers;
}

/*
	函式功能: 取得輸入數列

	參數: NumberArray數列物件

	回傳值: 無
*/
void GetInput(NumberArray& numberArray)
{
    //儲存數列之變數
    vector<float> numbers;
    //輸入資料
    string input;

    while (true)
    {
        cout << "請輸入一串多組數字: ";
        getline(cin, input);
        //分割字串輸入資料
        numbers = SplitString(input);

        //如果不為空數列，代表分割輸入資料符合規則，則跳出迴圈
        if (!empty(numbers))
            break;

        cout << "輸入資料有誤" << endl;
    }

    //建構物件資料
    numberArray = NumberArray(numbers);
}

int main()
{
    //初始化數列物件-長度歸零
    NumberArray numberArray;
    //取得輸入數列
    GetInput(numberArray);
    //輸出中位數
    cout << "中位數: " << numberArray.GetMedian() << endl;
    system("PAUSE");
    return 0;
}