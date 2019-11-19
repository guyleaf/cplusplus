#ifndef COMPLEX_UI_H
#define COMPLEX_UI_H

#include "Complex.h"
class ComplexUI
{
public:
    //UI�_�ϵe��
    void Start();
private:
    //��X�p�⵲�G
    void ShowResult(const Complex& result);
    //�Ƽƭ��k�B��
    const Complex Multiply(const Complex& firstNum, const Complex& secondNum);
    //���i
    const Complex _I = Complex(0, 1);
};
#endif
