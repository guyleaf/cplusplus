#include "Suite.h"
#include <iostream>

/*
	函式功能: 建構套裝資料

	參數: name => 套裝名稱, description => 套裝描述, id => 套裝商品編號

	回傳值: 無
*/
Suite::Suite(string name, string description, int id) : Cloth(name, description, 0, id)
{
}

/*
	函式功能: 套裝初始化加入選定的衣服

	參數: 一件衣服

	回傳值: 無
*/
void Suite::Add(Cloth* cloth)
{
    _clothes.push_back(cloth);
    _price += cloth->GetPrice();
}

/*
	函式功能: 取得套裝價格

	參數: 無

	回傳值: 套裝價格
*/
double Suite::GetPrice() const
{
    return _price * 0.9;
}

Suite::~Suite()
{
}
