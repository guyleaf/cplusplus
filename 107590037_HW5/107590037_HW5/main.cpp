#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <regex>
using namespace std;
#include "NumberArray.h"

/*
	函式功能: 判斷是否為數字

	參數: 字串輸入資料

	回傳值: true/false
*/
bool IsNumber(const string& input)
{
    //輸入資料規則
    regex rule1("^-?[0-9]+$");
    regex rule2("^-?[0-9]+\\.[0-9]+$");

    if (regex_match(input, rule1) || regex_match(input, rule2))
        return true;

    return false;
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

        while (cin >> input)
        {
            if (IsNumber(input))
                numbers.push_back(stof(input));
            else
            {
                numbers.clear();
                break;
            }
        }

        if (!empty(numbers))
            break;

        cout << "輸入資料有誤" << endl;
    }

    //排序數列
    sort(numbers.begin(), numbers.end());
    //建構物件資料
    numberArray = NumberArray(numbers);
}

int main()
{
    //數列物件
    NumberArray numberArray;
    //取得輸入數列
    GetInput(numberArray);
    cout << "中位數: " << numberArray.GetMedian() << endl;
    system("PAUSE");
    return 0;
}