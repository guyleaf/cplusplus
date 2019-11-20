#ifndef COMPLEX_UI_H
#define COMPLEX_UI_H

#include "Complex.h"
class ComplexUI
{
public:
    //UI起始畫面
    void Start();
private:
    //輸出計算結果
    void ShowResult(const Complex& result);
};
#endif
