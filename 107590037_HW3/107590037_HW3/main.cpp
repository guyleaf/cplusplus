/*
	Author: 資工二 107590037 應耀德

	Destination: 計算圓之周長、面積及直徑

	Date: 2019/09/16

	HomeworkNumber: HW3
*/
#include <iostream>
#include <string>
#include <regex>
using namespace std;
#include "circle.h"

/*
	程式功能: 取得輸入半徑資料

	參數: 無

	回傳值: double型態的半徑資料
*/
double GetInputRadius()
{
    //半徑資料
    string radius;
    //正規表達式 整數與小數兩種情況
    regex rule1("^[0-9]+");
    regex rule2("^[0-9]+\\.[0-9]+$");

    while (true)
    {
        cout << "請輸入圓形半徑: ";
        getline(cin, radius);

        //檢查輸入資料有無合法
        if (regex_match(radius, rule1) || regex_match(radius, rule2))
        {
            //string轉double型態並回傳
            return stod(radius);
        }

        cout << "輸入錯誤, 請重新輸入" << endl;
    }
}

int main()
{
    //宣告一個圓
    Circle circle;
    //設定半徑
    circle.SetRadius(GetInputRadius());
    cout << "圓形直徑: " << circle.CalculateDiameter() << endl;
    cout << "圓形周長: " << circle.CalculateCircumference() << endl;
    cout << "圓形面積: " << circle.CalculateArea() << endl;
    system("PAUSE");
    return 0;
}