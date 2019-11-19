#ifndef UI_H
#define UI_H

#include "Shop.h"


class UI //UI介面
{
public:
    //顯示選單
    void ShowMenu();
    ~UI();
private:
    //創建商店
    void CreateShop(string name);
    //取得輸入指令代號
    int GetCommand();
    //新增衣服
    void AddNewClothes();
    //顯示店家所有衣服資料
    void DisplayAllClothes() const;
    //判斷是否為數字
    bool IsNumber(string input);
    //判斷是否為正數
    bool IsPositive(string input);
    //商店物件
    Shop* _shop;
};
#endif