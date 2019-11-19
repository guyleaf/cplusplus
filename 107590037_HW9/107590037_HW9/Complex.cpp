#include "Complex.h"
#include <string>
using namespace std;

/*
	ㄧΑ: ﹍て狡计ン

	把计: 礚

	肚: 礚
*/
Complex::Complex()
{
    _real = 0;
    _imaginary = 0;
}

/*
	ㄧΑ: 篶狡计戈

	把计: real => 龟计场だ

	肚: 礚
*/
Complex::Complex(double real)
{
    _real = real;
    _imaginary = 0;
}

/*
	ㄧΑ: 篶狡计戈

	把计: real => 龟计场だ, imaginary => 店计场だ

	肚: 礚
*/
Complex::Complex(double real, double imaginary)
{
    _real = real;
    _imaginary = imaginary;
}

/*
	ㄧΑ: operator overload 猭 double * Complex

	把计: scalar => double篈, complexNum => 狡计

	肚: 狡计ン
*/
const Complex operator*(double scalar, const Complex complexNum)
{
    return Complex(scalar * complexNum._real, scalar * complexNum._imaginary);
}

/*
	ㄧΑ: operator overload 猭

	把计: ㄢ狡计

	肚: 狡计ン
*/
const Complex operator+(const Complex& firstNum, const Complex& secondNum)
{
    double real = firstNum._real + secondNum._real;
    double imaginary = firstNum._imaginary + secondNum._imaginary;
    return Complex(real, imaginary);
}

/*
	ㄧΑ: operator overload 块

	把计: out => 块戈瑈, result => 璸衡挡狦

	肚: 块戈瑈
*/
ostream& operator<<(ostream& out, const Complex& result)
{
    out << result._real;

    //店计タ璽腹耞
    if (result._imaginary < 0)
        out << " - " << -result._imaginary << "i";
    else
        out << " + " << result._imaginary << "i";

    return out;
}

/*
	ㄧΑ: operator overload 块

	把计: in => 块戈瑈, number => 璶Complexン

	肚: 块戈瑈
*/
istream& operator>>(istream& in, Complex& number)
{
    in >> number._real;
    in.ignore(1);
    in >> number._imaginary;
    in.ignore(1);
    return in;
}

/*
	ㄧΑ: 眔龟计

	把计: 礚

	肚: double篈龟计
*/
double Complex::GetReal() const
{
    return _real;
}

/*
	ㄧΑ: 眔店计

	把计: 礚

	肚: double篈店计
*/
double Complex::GetImaginary() const
{
    return _imaginary;
}