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

    //選擇客人與商店
    void SelectCustomerAndShop(const string customerName, const string shopName) const;
    //選擇商店
    string GetCustomerName(int index) const;
    //選擇商店
    string GetShopName(int index) const;
    //建立新訂單
    void MakeNewOrder();
    //購買衣服
    void AddClothesToOrder(string shopName);
    //取得衣服Id
    int GetClothId();
    //取得衣服件數
    int GetClothCount();
    //訂單結帳
    void CheckOutOrder(string shopName);
    //查看剩餘點數
    void CheckLeftPoint();
    //查看歷史收據
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
