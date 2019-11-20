#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
using std::ostream;
using std::istream;

class Complex
{
    //operator overload <<
    friend ostream& operator<<(ostream& out, const Complex& result);
    //operator overload >>
    friend istream& operator>>(istream& in, Complex& number);
    //operator overload * => double * Complex 純量乘法
    friend const Complex operator*(double scalar, const Complex complexNum);
    //operator overload +
    friend const Complex operator+(const Complex& firstNum, const Complex& secondNum);
public:
    //初始化複數物件
    Complex();
    //建構複數資料
    Complex(double real);
    //建構複數資料
    Complex(double real, double imaginary);
    //取得實數
    double GetReal() const;
    //取得虛數
    double GetImaginary() const;
    //operator overload * => Complex * Complex 複數乘法
    const Complex operator*(const Complex& secondNum) const;
private:
    //實數
    double _real;
    //虛數
    double _imaginary;
};
#endif

