#ifndef CLOTH_H
#define CLOTH_H

#include <string>
using std::string;

class Cloth //衣服
{
public:
    //初始化衣服資料
    Cloth(string name, string description, double price, int id);
    //取得衣服名稱
    string GetName() const;
    //取得衣服描述
    string GetDescription() const;
    //取得衣服資訊
    string GetInformation() const;
    //取得衣服價格
    virtual double GetPrice() const;
    //取得衣服編號
    int GetId() const;
    virtual ~Cloth();
protected:
    //衣服名稱
    string _name;
    //衣服描述
    string _description;
    //衣服價格
    double _price;
    //衣服編號
    int _id;
};
#endif
