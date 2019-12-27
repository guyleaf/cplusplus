#ifndef MALL_H
#define MALL_H

#include "Shop.h"
#include "Customer.h"

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
    //建立新訂單
    void MakeNewOrder();
    //加入衣服至訂單中
    void AddClothToOrder(int id);
    //選擇客人與商店
    void SelectCustomerAndShop(size_t customerIndex, size_t shopIndex);
    //檢查點數是否足夠
    bool IsPointEnough() const;
    //取得點數
    double GetCash() const;
    //訂單扣除點數
    void ReducePointFromOrder();
    //取消訂單
    void CancelOrder();
    //取得所有商店資料
    const vector<Shop*>* GetShops() const;
    //取得該商店所有衣服資料
    const vector<Cloth*>* GetClothes() const;
    //取得所有客人資料
    const vector<Customer*>* GetCustomers() const;
    //取得目前客人訂單
    const Order* GetCurrentOrder() const;
    //取得客人歷史訂單記錄
    const vector<Order*>* GetPurchasedHistoryFrom() const;
    ~Mall();
private:
    //載入外部商店資料
    void LoadShopsData(string fileName);
    //載入商店的衣服資料
    void LoadClothesData(fstream& file, Shop* shop);
    void LoadSuiteData(fstream& file, Shop* shop, int idOffset);
    //讀取商店標頭
    string ReadShopHead(fstream& file) const;
    //取得商店名稱
    string GetShopName(const string& shopHead) const;
    //讀取衣服index
    int ReadClothIndex(fstream& file) const;
    //讀取衣服名稱
    string ReadClothName(fstream& file) const;
    //讀取衣服描述
    string ReadClothDescription(fstream& file) const;
    //讀取衣服價格
    double ReadClothPrice(fstream& file) const;

    //檢查是否為衣服資料
    bool IsClothData(fstream& file, streampos& lastReadPosition) const;
    //是否為套裝
    bool IsSuiteData(fstream& file, streampos& lastReadPosition) const;
    //選定的商店編號
    size_t _shopIndex;
    //選定的客人編號
    size_t _customerIndex;
    //商店清單
    vector<Shop*> _shops;
    //客人清單
    vector<Customer*> _customers;
};
#endif
