#ifndef MALL_H
#define MALL_H
#include "Shop.h"
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Mall
{
public:
    //初始化商場
    Mall();
    //建立衣服資料
    void CreateNewCloth(string name, string description, double price);
    //選擇商店
    void SelectShop(int shopIndex);
    //取得該商店所有衣服資料
    const vector<Cloth*>* GetClothes() const;
    //取得所有商店資料
    const vector<Shop*>* GetShops() const;

    ~Mall();
private:
    //載入外部商店資料
    void LoadShopsData(string fileName);
    //載入商店的衣服資料
    void LoadClothesData(fstream& file, Shop* shop);
    //讀取商店標頭
    string ReadShopHead(fstream& file) const;
    //取得商店名稱
    string GetShopName(const string& shopHead) const;
    //讀取衣服名稱
    string ReadClothName(fstream& file) const;
    //讀取衣服描述
    string ReadClothDescription(fstream& file) const;
    //讀取衣服價格
    double ReadClothPrice(fstream& file) const;
    //檢查是否為衣服資料
    bool IsClothData(fstream& file, streampos& lastReadPosition) const;
    //選定的商店編號
    int _shopIndex;
    //商店清單
    vector<Shop*> _shops;
};
#endif
