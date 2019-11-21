#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include "Order.h"
#include "Shop.h"
#include "Cloth.h"
using std::string;

class Customer
{
public:
    Customer(string name);
    string GetName() const;
    double GetCash() const;
    void MakeNewOrder(Shop* shop);
    void AddClothToOrder(Cloth* cloth);
    double GetOrderTotalPrice() const;
    bool IsPointEnough() const;
    void ReducePointFromOrder();
    void CancelOrder();
    const Order* GetCurrentOrder() const;
    ~Customer();
private:
    string _name;
    double _point;
    Order* _order;
};
#endif
