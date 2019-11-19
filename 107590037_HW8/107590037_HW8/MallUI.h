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
    //��l�ưӳ�UI
    MallUI(Mall* mall);
    //���UI�e��
    void Start();
private:
    //�ӳ����
    void MallsMenu(string& shopName);
    void ShowMallsMenu();

    //�ө����
    void ShopMenu(string& shopName);
    void ShowShopMenu(const string shopName);

    //���o�ө��s��
    int GetShopIndex(const string shopName) const;
    //��ܰө�
    void SelectShop(int command, string& shopName);
    //�s�W��A
    void AddNewClothes();
    //���o��A�W��
    string GetClothName();
    //���o��A�y�z
    string GetClothDescription();
    //���o��A����
    double GetClothPrice();
    //���o����J���O
    string GetCommand();
    //�P�_�O�_������
    bool IsPositive(string input);
    //�P�_�O�_���Ʀr
    bool IsNumber(string input);

    //��ܩ��a�Ҧ���A���
    void DisplayAllClothes() const;
    //���}trigger
    bool _exit;
    //�ө�����
    vector<string> _shopsOrder;
    //�ө��ƶq
    size_t _numberOfShops;
    //�ӳ�Model
    Mall* _mall;
};
#endif
