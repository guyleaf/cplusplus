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
    //��l�ưӳ�
    Mall();
    //�إߦ�A���
    void CreateNewCloth(string name, string description, double price);
    //�إ߷s�q��
    void MakeNewOrder();
    //�[�J��A�ܭq�椤
    void AddClothToOrder(int id);
    //��ܫȤH�P�ө�
    void SelectCustomerAndShop(size_t customerIndex, size_t shopIndex);
    //�ˬd�I�ƬO�_����
    bool IsPointEnough() const;
    //���o�I��
    double GetCash() const;
    //�q�榩���I��
    void ReducePointFromOrder();
    //�����q��
    void CancelOrder();
    //���o�Ҧ��ө����
    const vector<Shop*>* GetShops() const;
    //���o�Ӱө��Ҧ���A���
    const vector<Cloth*>* GetClothes() const;
    //���o�Ҧ��ȤH���
    const vector<Customer*>* GetCustomers() const;
    //���o�ثe�ȤH�q��
    const Order* GetCurrentOrder() const;
    //���o�ȤH���v�q��O��
    const vector<Order*>* GetPurchasedHistoryFrom() const;
    ~Mall();
private:
    //���J�~���ө����
    void LoadShopsData(string fileName);
    //���J�ө�����A���
    void LoadClothesData(fstream& file, Shop* shop);
    void LoadSuiteData(fstream& file, Shop* shop, int idOffset);
    //Ū���ө����Y
    string ReadShopHead(fstream& file) const;
    //���o�ө��W��
    string GetShopName(const string& shopHead) const;
    //Ū����Aindex
    int ReadClothIndex(fstream& file) const;
    //Ū����A�W��
    string ReadClothName(fstream& file) const;
    //Ū����A�y�z
    string ReadClothDescription(fstream& file) const;
    //Ū����A����
    double ReadClothPrice(fstream& file) const;

    //�ˬd�O�_����A���
    bool IsClothData(fstream& file, streampos& lastReadPosition) const;
    //�O�_���M��
    bool IsSuiteData(fstream& file, streampos& lastReadPosition) const;
    //��w���ө��s��
    size_t _shopIndex;
    //��w���ȤH�s��
    size_t _customerIndex;
    //�ө��M��
    vector<Shop*> _shops;
    //�ȤH�M��
    vector<Customer*> _customers;
};
#endif
