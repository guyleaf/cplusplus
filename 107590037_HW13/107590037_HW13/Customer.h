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
    //初始化客人資料
    Customer(string name);
    //取得名字
    string GetName() const;
    //取得點數
    double GetCash() const;
    //建立新訂單
    void MakeNewOrder(Shop* shop);
    //加入衣服至訂單中
    void AddClothToOrder(Cloth* cloth);
    //取得訂單總金額
    double GetOrderTotalPrice() const;
    //檢查點數是否足夠
    bool IsPointEnough() const;
    //訂單扣除點數
    void ReducePointFromOrder();
    //取消訂單
    void CancelOrder();
    //取得目前訂單
    const Order* GetCurrentOrder() const;
    //取得歷史訂單紀錄
    vector<Order*>* GetPurchasedHistoryFrom(Shop* shop) const;
    ~Customer();
private:
    //客人名字
    string _name;
    //擁有的點數
    double _point;
    //目前訂單
    Order* _currentOrder;
    //歷史訂單紀錄
    vector<Order*> _pastOrder;
};
#endif
