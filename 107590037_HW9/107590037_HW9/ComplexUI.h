#ifndef COMPLEX_UI_H
#define COMPLEX_UI_H

#include "Complex.h"
class ComplexUI
{
public:
    //UI起使畫面
    void Start();
private:
    //輸出計算結果
    void ShowResult(const Complex& result);
    //複數乘法運算
    const Complex Multiply(const Complex& firstNum, const Complex& secondNum);
    //虛數i
    const Complex _I = Complex(0, 1);
};
#endif
