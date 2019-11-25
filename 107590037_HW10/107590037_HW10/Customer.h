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
    //��l�ƫȤH���
    Customer(string name);
    //���o�W�r
    string GetName() const;
    //���o�I��
    double GetCash() const;
    //�إ߷s�q��
    void MakeNewOrder(Shop* shop);
    //�[�J��A�ܭq�椤
    void AddClothToOrder(Cloth* cloth);
    //���o�q���`���B
    double GetOrderTotalPrice() const;
    //�ˬd�I�ƬO�_����
    bool IsPointEnough() const;
    //�q�榩���I��
    void ReducePointFromOrder();
    //�����q��
    void CancelOrder();
    //���o�ثe�q��
    const Order* GetCurrentOrder() const;
    ~Customer();
private:
    //�ȤH�W�r
    string _name;
    //�֦����I��
    double _point;
    //�q��
    Order* _order;
};
#endif
