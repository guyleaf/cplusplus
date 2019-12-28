#ifndef SHOP_H
#define SHOP_H

#include "Cloth.h"
#include "Suite.h"

#include <string>
#include <vector>

using std::string;
using std::vector;

class Shop //店家
{
public:
    //初始化店家
    Shop(string name);
    //取得店家名字
    string GetName() const;
    //建立衣服資料
    void CreateNewCloth(string name, string description, double price);
    //加入衣服至資料清單
    void AddCloth(Cloth* cloth);
    //取得店家所有衣服資料
    const vector<Cloth*>* GetClothes() const;
    //尋找衣服
    Cloth* FindCloth(int id) const;
    ~Shop();
private:
    //衣服資料清單
    vector<Cloth*> _clothes;
    //店家名字
    string _name;
    //衣服數量
    int _numberOfClothes;
};
#endif