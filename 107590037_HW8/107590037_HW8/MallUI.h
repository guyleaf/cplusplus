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
    //商場選單
    void MallsMenu(string& shopName);
    void ShowMallsMenu();

    //商店選單
    void ShopMenu(string& shopName);
    void ShowShopMenu(const string shopName);

    //取得商店編號
    int GetShopIndex(const string shopName) const;
    //選擇商店
    void SelectShop(int command, string& shopName);
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
    //商店順序
    vector<string> _shopsOrder;
    //商店數量
    size_t _numberOfShops;
    //商場Model
    Mall* _mall;
};
#endif
