#ifndef ORDER_H
#define ORDER_H
#include "Cloth.h"
#include "Shop.h"

class Order
{
public:
    //初始化訂單資料
    Order(Shop* shop);
    //取得選定的商店資料
    const Shop* GetShop() const;
    //加入衣服
    void AddCloth(Cloth* clothToAdd);
    //取得訂單總金額
    double GetTotalPrice() const;
private:
    //已選定的衣服清單
    vector<Cloth*> _orderedClothes;
    //選定的商店
    Shop* _shop;
};
#endif

