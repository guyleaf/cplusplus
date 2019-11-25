#include "Customer.h"


/*
	ㄧΑ: ﹍て戈

	把计: 

	肚: 礚
*/
Customer::Customer(string name)
{
    _name = name;
    _point = 2000;
    _order = NULL;
}

/*
	ㄧΑ: 眔

	把计: 礚

	肚: 
*/
string Customer::GetName() const
{
    return _name;
}

/*
	ㄧΑ: 眔翴计

	把计: 礚

	肚: 翴计
*/
double Customer::GetCash() const
{
    return _point;
}

/*
	ㄧΑ: ミ穝璹虫

	把计: 匡﹚坝┍

	肚: 礚
*/
void Customer::MakeNewOrder(Shop* shop)
{
    delete _order;
    _order = new Order(shop);
}

/*
	ㄧΑ: ︾狝璹虫い

	把计: 匡﹚︾狝

	肚: 礚
*/
void Customer::AddClothToOrder(Cloth* cloth)
{
    _order->AddCloth(cloth);
}

/*
	ㄧΑ: 眔璹虫羆肂

	把计: 礚

	肚: 璹虫羆肂
*/
double Customer::GetOrderTotalPrice() const
{
    return _order->GetTotalPrice();
}

/*
	ㄧΑ: 浪琩翴计琌ì镑

	把计: 礚

	肚: True/False
*/
bool Customer::IsPointEnough() const
{
    return (_point - _order->GetTotalPrice() >= 0) ? true : false;
}

/*
	ㄧΑ: 璹虫Ι埃翴计

	把计: 礚

	肚: 礚
*/
void Customer::ReducePointFromOrder()
{
    _point -= _order->GetTotalPrice();
    delete _order;
    _order = NULL;
}

/*
	ㄧΑ: 璹虫

	把计: 礚

	肚: 礚
*/
void Customer::CancelOrder()
{
    delete _order;
    _order = NULL;
}

/*
	ㄧΑ: 眔ヘ玡璹虫

	把计: 礚

	肚: 璹虫戈
*/
const Order* Customer::GetCurrentOrder() const
{
    return _order;
}


Customer::~Customer()
{
    delete _order;
}
