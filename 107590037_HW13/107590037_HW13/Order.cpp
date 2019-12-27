#include "Order.h"


/*
	�禡�\��: ��l�ƭq����

	�Ѽ�: �L

	�^�ǭ�: �L
*/
Order::Order(Shop* shop)
{
    _shop = shop;
}

/*
	�禡�\��: ���o��w���ө����

	�Ѽ�: �L

	�^�ǭ�: ��w���ө�
*/
const Shop* Order::GetShop() const
{
    return _shop;
}

/*
	�禡�\��: �[�J��A

	�Ѽ�: ��A����

	�^�ǭ�: �L
*/
void Order::AddCloth(Cloth* clothToAdd)
{
    _orderedClothes.push_back(clothToAdd);
}

/*
	�禡�\��: ���o�q���`���B

	�Ѽ�: �L

	�^�ǭ�: �q���`���B
*/
double Order::GetTotalPrice() const
{
    double totalPrice = 0;

    for (size_t i = 0; i < _orderedClothes.size(); i++)
        totalPrice += _orderedClothes[i]->GetPrice();

    return totalPrice;
}

const vector<Cloth*>* Order::GetClothes() const
{
    return &_orderedClothes;
}