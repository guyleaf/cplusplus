#ifndef UI_H
#define UI_H

#include "Shop.h"


class UI //UI����
{
public:
    //��ܿ��
    void ShowMenu();
    ~UI();
private:
    //�Ыذө�
    void CreateShop(string name);
    //���o��J���O�N��
    int GetCommand();
    //�s�W��A
    void AddNewClothes();
    //��ܩ��a�Ҧ���A���
    void DisplayAllClothes() const;
    //�P�_�O�_���Ʀr
    bool IsNumber(string input);
    //�P�_�O�_������
    bool IsPositive(string input);
    //�ө�����
    Shop* _shop;
};
#endif