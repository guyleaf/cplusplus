#include "GasPump.h"

using namespace std;

//��l�Ƴ]�m�o��
GasPump::GasPump(double gallonPrice)
{
    _gallonPrice = gallonPrice;
    _amountCharged = 0.0;
}

//���o�C���ɪo��
double GasPump::GetLiterPrice() const
{
    const double LITERPERGALLON = 3.785411784;
    return _gallonPrice / LITERPERGALLON;
}

//���o�C�[�ڪo��
double GasPump::GetGallonPrice() const
{
    return _gallonPrice;
}

//���o�W�@���[�o���`����
double GasPump::GetAmountDispensed() const
{
    return _amountCharged * GetLiterPrice();
}

//���o�W�@���[�o�q
double GasPump::GetAmountCharged() const
{
    return _amountCharged;
}

//�}�l�[�o
vector<string> GasPump::Start(int amountLiter)
{
    //�x�s�[�o�i�װT��
    vector<string> gasInfo;

    for (int i = 1; i <= amountLiter; i++)
    {
        gasInfo.push_back("�ثe�[�F " + to_string(i) + " ����");
    }

    //�x�s�[�o�`�q
    _amountCharged = amountLiter;
    gasInfo.push_back("�@ " + to_string(static_cast<int>(_amountCharged)) + " ����, " + to_string(GetAmountDispensed()) + " ��\n");
    return gasInfo;
}