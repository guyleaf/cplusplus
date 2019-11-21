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
    //��l�ưӳ�
    Mall();
    //�إߦ�A���
    void CreateNewCloth(string name, string description, double price);
    //��ܰө�
    void SelectShop(int shopIndex);
    //���o�Ӱө��Ҧ���A���
    const vector<Cloth*>* GetClothes() const;
    //���o�Ҧ��ө����
    const vector<Shop*>* GetShops() const;

    ~Mall();
private:
    //���J�~���ө����
    void LoadShopsData(string fileName);
    //���J�ө�����A���
    void LoadClothesData(fstream& file, Shop* shop);
    //Ū���ө����Y
    string ReadShopHead(fstream& file) const;
    //���o�ө��W��
    string GetShopName(const string& shopHead) const;
    //Ū����A�W��
    string ReadClothName(fstream& file) const;
    //Ū����A�y�z
    string ReadClothDescription(fstream& file) const;
    //Ū����A����
    double ReadClothPrice(fstream& file) const;
    //�ˬd�O�_����A���
    bool IsClothData(fstream& file, streampos& lastReadPosition) const;
    //��w���ө��s��
    int _shopIndex;
    //�ө��M��
    vector<Shop*> _shops;
};
#endif
