#ifndef GASPUMP_H
#define GASPUMP_H

#include <string>
#include <vector>
using std::string;
using std::vector;

class GasPump
{
public:
    //﹍て砞竚猳基
    GasPump(double gallonPrice);
    //眔–そど猳基
    double GetLiterPrice() const;
    //眔–ㄚ猳基
    double GetGallonPrice() const;
    //眔Ω猳羆基
    double GetAmountDispensed() const;
    //眔Ω猳秖
    double GetAmountCharged() const;
    //秨﹍猳
    vector<string> Start(int amountLiter);
private:
    //–ㄚ猳基
    double _gallonPrice;
    //Ω猳秖
    double _amountCharged;
};
#endif