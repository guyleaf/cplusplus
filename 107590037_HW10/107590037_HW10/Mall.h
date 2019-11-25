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

    void MakeNewOrder();

    void AddOrderToCloth(int id);

    void SelectCustomerAndShop(size_t customerIndex, size_t shopIndex);

    bool IsPointEnough() const;

    double GetCash() const;

    void ReducePointFromOrder();

    void CancelOrder();

    const vector<Shop*>* GetShops() const;
    const vector<Cloth*>* GetClothes() const;
    const vector<Customer*>* GetCustomers() const;
    const Order* GetCurrentOrder() const;
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
    size_t _shopIndex;
    size_t _customerIndex;
    //商店清單
    vector<Shop*> _shops;
    vector<Customer*> _customers;
};
#endif
