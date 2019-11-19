#include "Complex.h"
#include <string>
using namespace std;

/*
	�禡�\��: ��l�ƽƼƪ���

	�Ѽ�: �L

	�^�ǭ�: �L
*/
Complex::Complex()
{
    _real = 0;
    _imaginary = 0;
}

/*
	�禡�\��: �غc�ƼƸ��

	�Ѽ�: real => ��Ƴ���

	�^�ǭ�: �L
*/
Complex::Complex(double real)
{
    _real = real;
    _imaginary = 0;
}

/*
	�禡�\��: �غc�ƼƸ��

	�Ѽ�: real => ��Ƴ���, imaginary => ��Ƴ���

	�^�ǭ�: �L
*/
Complex::Complex(double real, double imaginary)
{
    _real = real;
    _imaginary = imaginary;
}

/*
	�禡�\��: operator overload ���k double * Complex

	�Ѽ�: scalar => double���A, complexNum => �Ƽ�

	�^�ǭ�: �Ƽƪ���
*/
const Complex operator*(double scalar, const Complex complexNum)
{
    return Complex(scalar * complexNum._real, scalar * complexNum._imaginary);
}

/*
	�禡�\��: operator overload �[�k

	�Ѽ�: ��ӽƼ�

	�^�ǭ�: �Ƽƪ���
*/
const Complex operator+(const Complex& firstNum, const Complex& secondNum)
{
    double real = firstNum._real + secondNum._real;
    double imaginary = firstNum._imaginary + secondNum._imaginary;
    return Complex(real, imaginary);
}

/*
	�禡�\��: operator overload ��X

	�Ѽ�: out => ��X��Ƭy, result => �p�⵲�G

	�^�ǭ�: ��X��Ƭy
*/
ostream& operator<<(ostream& out, const Complex& result)
{
    out << result._real;

    //��ƥ��t���P�_
    if (result._imaginary < 0)
        out << " - " << -result._imaginary << "i";
    else
        out << " + " << result._imaginary << "i";

    return out;
}

/*
	�禡�\��: operator overload ��J

	�Ѽ�: in => ��J��Ƭy, number => �n�s�J��Complex����

	�^�ǭ�: ��J��Ƭy
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
	�禡�\��: ���o���

	�Ѽ�: �L

	�^�ǭ�: double���A�����
*/
double Complex::GetReal() const
{
    return _real;
}

/*
	�禡�\��: ���o���

	�Ѽ�: �L

	�^�ǭ�: double���A�����
*/
double Complex::GetImaginary() const
{
    return _imaginary;
}