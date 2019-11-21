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
    string name = clothToAdd->GetName();
    string description = clothToAdd->GetDescription();
    double price = clothToAdd->GetPrice();
    _shop->createNewCloth(name, description, price);
}

double Order::GetTotalPrice() const
{
    double totalPrice = 0;

    for (size_t i = 0; i < _orderedClothes.size(); i++)
        totalPrice += _orderedClothes[i]->GetPrice();

    return totalPrice;
}
