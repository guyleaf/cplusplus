#include "Customer.h"



Customer::Customer(string name)
{
    _name = name;
    _point = 2000;
    _order = NULL;
}

string Customer::GetName() const
{
    return _name;
}

double Customer::GetCash() const
{
    return _point;
}

void Customer::MakeNewOrder(Shop* shop)
{
    delete _order;
    _order = new Order(shop);
}

void Customer::AddClothToOrder(Cloth* cloth)
{
    _order->AddCloth(cloth);
}

double Customer::GetOrderTotalPrice() const
{
    return _order->GetTotalPrice();
}

bool Customer::IsPointEnough() const
{
    return (_point - _order->GetTotalPrice() >= 0) ? true : false;
}

void Customer::ReducePointFromOrder()
{
    _point -= _order->GetTotalPrice();
    delete _order;
    _order = NULL;
}

void Customer::CancelOrder()
{
    delete _order;
    _order = NULL;
}

const Order* Customer::GetCurrentOrder() const
{
    return _order;
}


Customer::~Customer()
{
    delete _order;
}
