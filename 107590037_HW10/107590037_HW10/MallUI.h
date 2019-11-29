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
    //�ȤH���
    void CustomersMenu(string& customerName);
    void ShowCustomersMenu() const;

    //�ӳ����
    void MallsMenu(string& shopName);
    void ShowMallsMenu() const;

    //�ө����
    void ShopMenu(string& shopName, string& customerName);
    void ShowShopMenu(const string shopName, const string customerName) const;

    //��ܫȤH�P�ө�
    void SelectCustomerAndShop(const string customerName, const string shopName) const;
    //��ܰө�
    string GetCustomerName(int index) const;
    //��ܰө�
    string GetShopName(int index) const;
    //�إ߷s�q��
    void MakeNewOrder();
    //�ʶR��A
    void AddClothesToOrder(string shopName);
    //���o��AId
    int GetClothId();
    //���o��A���
    int GetClothCount();
    //�q�浲�b
    void CheckOutOrder(string shopName);
    //�d�ݳѾl�I��
    void CheckLeftPoint();
    //�d�ݾ��v����
    void CheckPastOrders();
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

    //�ȤH����
    vector<string> _customersOrder;
    //�ө�����
    vector<string> _shopsOrder;
    //�ȤH�ƶq
    size_t _numberOfCustomers;
    //�ө��ƶq
    size_t _numberOfShops;

    //�ӳ�Model
    Mall* _mall;
};
#endif
