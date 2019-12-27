#include "Customer.h"


/*
	函式功能: 初始化客人資料

	參數: 客人名字

	回傳值: 無
*/
Customer::Customer(string name)
{
    _name = name;
    _point = 2000;
    _currentOrder = NULL;
}

/*
	函式功能: 取得名字

	參數: 無

	回傳值: 客人名字
*/
string Customer::GetName() const
{
    return _name;
}

/*
	函式功能: 取得點數

	參數: 無

	回傳值: 客人點數
*/
double Customer::GetCash() const
{
    return _point;
}

/*
	函式功能: 建立新訂單

	參數: 選定的商店

	回傳值: 無
*/
void Customer::MakeNewOrder(Shop* shop)
{
    delete _currentOrder;
    _currentOrder = new Order(shop);
}

/*
	函式功能: 加入衣服至訂單中

	參數: 選定的衣服

	回傳值: 無
*/
void Customer::AddClothToOrder(Cloth* cloth)
{
    _currentOrder->AddCloth(cloth);
}

/*
	函式功能: 取得訂單總金額

	參數: 無

	回傳值: 訂單總金額
*/
double Customer::GetOrderTotalPrice() const
{
    return _currentOrder->GetTotalPrice();
}

/*
	函式功能: 檢查點數是否足夠

	參數: 無

	回傳值: True/False
*/
bool Customer::IsPointEnough() const
{
    return (_point - _currentOrder->GetTotalPrice() >= 0) ? true : false;
}

/*
	函式功能: 訂單扣除點數

	參數: 無

	回傳值: 無
*/
void Customer::ReducePointFromOrder()
{
    _point -= _currentOrder->GetTotalPrice();
    _pastOrder.push_back(_currentOrder);
    _currentOrder = NULL;
}

/*
	函式功能: 取消訂單

	參數: 無

	回傳值: 無
*/
void Customer::CancelOrder()
{
    delete _currentOrder;
    _currentOrder = NULL;
}

/*
	函式功能: 取得目前訂單

	參數: 無

	回傳值: 訂單資料
*/
const Order* Customer::GetCurrentOrder() const
{
    return _currentOrder;
}

/*
	函式功能: 取得歷史訂單記錄

	參數: 訂單所屬的Shop

	回傳值: 歷史訂單資料
*/
vector<Order*>* Customer::GetPurchasedHistoryFrom(Shop* shop) const
{
    vector<Order*>* order = new vector<Order*>;

    for (size_t i = 0; i < _pastOrder.size(); i++)
    {
        if (_pastOrder[i]->GetShop()->GetName() == shop->GetName())
            order->push_back(_pastOrder[i]);
    }

    return order;
}

Customer::~Customer()
{
    delete _currentOrder;

    for (size_t i = 0; i < _pastOrder.size(); i++)
        delete _pastOrder[i];
}
