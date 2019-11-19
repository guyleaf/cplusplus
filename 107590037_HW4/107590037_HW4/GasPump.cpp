#include "GasPump.h"

using namespace std;

//﹍て砞竚猳基
GasPump::GasPump(double gallonPrice)
{
    _gallonPrice = gallonPrice;
    _amountCharged = 0.0;
}

//眔–そど猳基
double GasPump::GetLiterPrice() const
{
    const double LITERPERGALLON = 3.785411784;
    return _gallonPrice / LITERPERGALLON;
}

//眔–ㄚ猳基
double GasPump::GetGallonPrice() const
{
    return _gallonPrice;
}

//眔Ω猳羆基
double GasPump::GetAmountDispensed() const
{
    return _amountCharged * GetLiterPrice();
}

//眔Ω猳秖
double GasPump::GetAmountCharged() const
{
    return _amountCharged;
}

//秨﹍猳
vector<string> GasPump::Start(int amountLiter)
{
    //纗猳秈癟
    vector<string> gasInfo;

    for (int i = 1; i <= amountLiter; i++)
    {
        gasInfo.push_back("ヘ玡 " + to_string(i) + " そど");
    }

    //纗猳羆秖
    _amountCharged = amountLiter;
    gasInfo.push_back(" " + to_string(static_cast<int>(_amountCharged)) + " そど, " + to_string(GetAmountDispensed()) + " じ\n");
    return gasInfo;
}