#include "ComplexUI.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
/*
	�禡�\��: UI�_�l�e��

	�Ѽ�: �L

	�^�ǭ�: �L
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
	�禡�\��: ��X���G

	�Ѽ�: �Ƽƭp�⵲�G

	�^�ǭ�: �L
*/
void ComplexUI::ShowResult(const Complex& result)
{
    cout << "Multi:"
         << " (" << result << ")"
         << endl;
}

/*
	�禡�\��: ���k�Ƽƭp��

	�Ѽ�: ��ӽƼ�

	�^�ǭ�: �Ƽƭp�⵲�G
*/
const Complex ComplexUI::Multiply(const Complex& firstNum, const Complex& secondNum)
{
    double real = firstNum.GetReal() * secondNum.GetReal() - firstNum.GetImaginary() * secondNum.GetImaginary();
    double imaginary = firstNum.GetReal() * secondNum.GetImaginary() + firstNum.GetImaginary() * secondNum.GetReal();
    return real + imaginary * _I;
}