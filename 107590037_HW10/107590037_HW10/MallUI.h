#ifndef MALL_UI_H
#define MALL_UI_H
#include "Mall.h"
#include <vector>
#include <string>

using std::vector;
using std::string;

class MallUI
{
public:
    //初始化商場UI
    MallUI(Mall* mall);
    //顯示UI畫面
    void Start();
private:
    //客人選單
    void CustomersMenu(string& customerName);
    void ShowCustomersMenu() const;

    //商場選單
    void MallsMenu(string& shopName);
    void ShowMallsMenu() const;

    //商店選單
    void ShopMenu(string& shopName, string& customerName);
    void ShowShopMenu(const string shopName, const string customerName) const;

    void SelectCustomerAndShop(const string customerName, const string shopName) const;
    //選擇商店
    string GetCustomerName(int command) const;
    //選擇商店
    string GetShopName(int command) const;

    void MakeNewOrder();

    void AddClothesToOrder();

    int GetClothIndex();

    int GetClothCount();

    void CheckOutOrder();

    void CheckLeftPoint();

    void CheckPastOrders();
    //新增衣服
    void AddNewClothes();
    //取得衣服名稱
    string GetClothName();
    //取得衣服描述
    string GetClothDescription();
    //取得衣服價格
    double GetClothPrice();
    //取得選單輸入指令
    string GetCommand();
    //判斷是否為正數
    bool IsPositive(string input);
    //判斷是否為數字
    bool IsNumber(string input);

    //顯示店家所有衣服資料
    void DisplayAllClothes() const;
    //離開trigger
    bool _exit;

    //客人順序
    vector<string> _customersOrder;
    //商店順序
    vector<string> _shopsOrder;
    //客人數量
    size_t _numberOfCustomers;
    //商店數量
    size_t _numberOfShops;

    //商場Model
    Mall* _mall;
};
#endif
