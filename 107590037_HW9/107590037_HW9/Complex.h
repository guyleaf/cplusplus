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
    //operator overload * => double * Complex �¶q���k
    friend const Complex operator*(double scalar, const Complex complexNum);
    //operator overload +
    friend const Complex operator+(const Complex& firstNum, const Complex& secondNum);
public:
    //��l�ƽƼƪ���
    Complex();
    //�غc�ƼƸ��
    Complex(double real);
    //�غc�ƼƸ��
    Complex(double real, double imaginary);
    //���o���
    double GetReal() const;
    //���o���
    double GetImaginary() const;
    //operator overload * => Complex * Complex �Ƽƭ��k
    const Complex operator*(const Complex& secondNum) const;
private:
    //���
    double _real;
    //���
    double _imaginary;
};
#endif

