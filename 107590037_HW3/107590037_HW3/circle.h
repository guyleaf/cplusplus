#ifndef CIRCLE_H
#define CIRCLE_H

class Circle
{
public:
    //�]�w�b�|
    void SetRadius(double radius);
    //���o�b�|
    double GetRadius();
    //�p�⭱�n
    double CalculateArea();
    //�p�⪽�|
    double CalculateDiameter();
    //�p��P��
    double CalculateCircumference();
private:
    const double _PI = 3.14; //�`��PI
    double _radius; //�b�|
};
#endif