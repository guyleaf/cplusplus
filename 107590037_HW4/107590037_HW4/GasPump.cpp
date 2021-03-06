#include "GasPump.h"

using namespace std;

//初始化設置油價
GasPump::GasPump(double gallonPrice)
{
    _gallonPrice = gallonPrice;
    _amountCharged = 0.0;
}

//取得每公升油價
double GasPump::GetLiterPrice() const
{
    const double LITERPERGALLON = 3.785411784;
    return _gallonPrice / LITERPERGALLON;
}

//取得每加侖油價
double GasPump::GetGallonPrice() const
{
    return _gallonPrice;
}

//取得上一次加油的總價格
double GasPump::GetAmountDispensed() const
{
    return _amountCharged * GetLiterPrice();
}

//取得上一次加油量
double GasPump::GetAmountCharged() const
{
    return _amountCharged;
}

//開始加油
vector<string> GasPump::Start(int amountLiter)
{
    //儲存加油進度訊息
    vector<string> gasInfo;

    for (int i = 1; i <= amountLiter; i++)
    {
        gasInfo.push_back("目前加了 " + to_string(i) + " 公升");
    }

    //儲存加油總量
    _amountCharged = amountLiter;
    gasInfo.push_back("共 " + to_string(static_cast<int>(_amountCharged)) + " 公升, " + to_string(GetAmountDispensed()) + " 元\n");
    return gasInfo;
}