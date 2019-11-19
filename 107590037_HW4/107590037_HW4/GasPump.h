#ifndef GASPUMP_H
#define GASPUMP_H

#include <string>
#include <vector>
using std::string;
using std::vector;

class GasPump
{
public:
    //��l�Ƴ]�m�o��
    GasPump(double gallonPrice);
    //���o�C���ɪo��
    double GetLiterPrice() const;
    //���o�C�[�ڪo��
    double GetGallonPrice() const;
    //���o�W�@���[�o���`����
    double GetAmountDispensed() const;
    //���o�W�@���[�o�q
    double GetAmountCharged() const;
    //�}�l�[�o
    vector<string> Start(int amountLiter);
private:
    //�C�[�ڪo��
    double _gallonPrice;
    //�W�@���[�o�q
    double _amountCharged;
};
#endif