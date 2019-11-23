#include "Order.h"



Order::Order(Shop* shop)
{
    _shop = shop;
}

const Shop* Order::GetShop() const
{
    return _shop;
}

void Order::AddCloth(Cloth* clothToAdd)
{
    _orderedClothes.push_back(clothToAdd);
}

double Order::GetTotalPrice() const
{
    double totalPrice = 0;

    for (size_t i = 0; i < _orderedClothes.size(); i++)
        totalPrice += _orderedClothes[i]->GetPrice();

    return totalPrice;
}
