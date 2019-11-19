#include "circle.h"

//�]�w�b�|
void Circle::SetRadius(double radius)
{
    _radius = radius;
}

//���o�b�|
double Circle::GetRadius()
{
    return _radius;
}

//�p�⭱�n
double Circle::CalculateArea()
{
    return _radius * _radius * _PI;
}

//�p��P��
double Circle::CalculateCircumference()
{
    //����
    const int multiple = 2;
    return (_radius * multiple) * _PI;
}

//�p�⪽�|
double Circle::CalculateDiameter()
{
    //����
    const int multiple = 2;
    return _radius * multiple;
}
