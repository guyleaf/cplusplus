#include "ComplexUI.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
/*
	函式功能: UI起始畫面

	參數: 無

	回傳值: 無
*/
void ComplexUI::Start()
{
    Complex firstNumber;
    Complex secondNumber;
    cout << "Input complex number 1: ";
    cin >> firstNumber;
    cout << "Input complex number 2: ";
    cin >> secondNumber;
    Complex result = Multiply(firstNumber, secondNumber);
    ShowResult(result);
}

/*
	函式功能: 輸出結果

	參數: 複數計算結果

	回傳值: 無
*/
void ComplexUI::ShowResult(const Complex& result)
{
    cout << "Multi:"
         << " (" << result << ")"
         << endl;
}

/*
	函式功能: 乘法複數計算

	參數: 兩個複數

	回傳值: 複數計算結果
*/
const Complex ComplexUI::Multiply(const Complex& firstNum, const Complex& secondNum)
{
    double real = firstNum.GetReal() * secondNum.GetReal() - firstNum.GetImaginary() * secondNum.GetImaginary();
    double imaginary = firstNum.GetReal() * secondNum.GetImaginary() + firstNum.GetImaginary() * secondNum.GetReal();
    return real + imaginary * _I;
}