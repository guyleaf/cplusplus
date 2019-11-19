#include "circle.h"

//設定半徑
void Circle::SetRadius(double radius)
{
    _radius = radius;
}

//取得半徑
double Circle::GetRadius()
{
    return _radius;
}

//計算面積
double Circle::CalculateArea()
{
    return _radius * _radius * _PI;
}

//計算周長
double Circle::CalculateCircumference()
{
    //倍數
    const int multiple = 2;
    return (_radius * multiple) * _PI;
}

//計算直徑
double Circle::CalculateDiameter()
{
    //倍數
    const int multiple = 2;
    return _radius * multiple;
}
