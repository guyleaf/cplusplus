#ifndef ORDER_H
#define ORDER_H
#include "Cloth.h"
#include "Shop.h"

class Order
{
public:
    Order(Shop* shop);
    const Shop* GetShop() const;
    void AddCloth(Cloth* clothToAdd);
    double GetTotalPrice() const;
private:
    vector<Cloth*> _orderedClothes;
    Shop* _shop;
};
#endif

