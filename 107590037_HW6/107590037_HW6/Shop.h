#ifndef SHOP_H
#define SHOP_H

#include "Cloth.h"

#include <string>
#include <vector>

using std::string;
using std::vector;

class Shop //���a
{
public:
    //��l�Ʃ��a
    Shop(string name);
    //���o���a�W�r
    string GetName() const;
    //�إߦ�A���
    void CreateNewCloth(string name, string description, double price);
    //���o���a�Ҧ���A���
    vector<Cloth*>* GetClothes() const;
private:
    //���J��A���
    void LoadClothesData(string fileName);
    //��A��ƲM��
    vector<Cloth*> _clothes;
    //���a�W�r
    string _name;
    //��A�ƶq
    int _numberOfClothes;
};
#endif