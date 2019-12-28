#ifndef SUITE_H
#define SUITE_H

#include "Cloth.h"
#include <vector>
using std::vector;

class Suite : public Cloth
{
public:
    //建構套裝資料
    Suite(string name, string description, int id);
    //套裝初始化加入選定的衣服
    void Add(Cloth*);
    //取得套裝價格
    double GetPrice() const;
    ~Suite();
private:
    //已選定的衣服清單
    vector<Cloth*> _clothes;
};
#endif