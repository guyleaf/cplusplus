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
    Complex result = firstNumber * secondNumber;
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