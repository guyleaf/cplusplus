#ifndef ORDER_H
#define ORDER_H
#include "Cloth.h"
#include "Shop.h"

class Order
{
public:
    //��l�ƭq����
    Order(Shop* shop);
    //���o��w���ө����
    const Shop* GetShop() const;
    //�[�J��A
    void AddCloth(Cloth* clothToAdd);
    //���o�q���`���B
    double GetTotalPrice() const;
private:
    //�w��w����A�M��
    vector<Cloth*> _orderedClothes;
    //��w���ө�
    Shop* _shop;
};
#endif

