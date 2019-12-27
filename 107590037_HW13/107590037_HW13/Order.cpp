#include "Order.h"


/*
	函式功能: 初始化訂單資料

	參數: 無

	回傳值: 無
*/
Order::Order(Shop* shop)
{
    _shop = shop;
}

/*
	函式功能: 取得選定的商店資料

	參數: 無

	回傳值: 選定的商店
*/
const Shop* Order::GetShop() const
{
    return _shop;
}

/*
	函式功能: 加入衣服

	參數: 衣服物件

	回傳值: 無
*/
void Order::AddCloth(Cloth* clothToAdd)
{
    _orderedClothes.push_back(clothToAdd);
}

/*
	函式功能: 取得訂單總金額

	參數: 無

	回傳值: 訂單總金額
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