#ifndef CLOTH_H
#define CLOTH_H

#include <string>
using std::string;

class Cloth //��A
{
public:
    //��l�Ʀ�A���
    Cloth(string name, string description, double price, int id);
    //���o��A�W��
    string GetName() const;
    //���o��A�y�z
    string GetDescription() const;
    //���o��A����
    double GetPrice() const;
    //���o��A�s��
    int GetId() const;
private:
    //��A�W��
    string _name;
    //��A�y�z
    string _description;
    //��A����
    double _price;
    //��A�s��
    int _id;
};
#endif