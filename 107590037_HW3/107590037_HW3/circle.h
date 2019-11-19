#ifndef CIRCLE_H
#define CIRCLE_H

class Circle
{
public:
    //設定半徑
    void SetRadius(double radius);
    //取得半徑
    double GetRadius();
    //計算面積
    double CalculateArea();
    //計算直徑
    double CalculateDiameter();
    //計算周長
    double CalculateCircumference();
private:
    const double _PI = 3.14; //常數PI
    double _radius; //半徑
};
#endif