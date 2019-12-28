#ifndef SUITE_H
#define SUITE_H

#include "Cloth.h"
#include <vector>
using std::vector;

class Suite : public Cloth
{
public:
    //�غc�M�˸��
    Suite(string name, string description, int id);
    //�M�˪�l�ƥ[�J��w����A
    void Add(Cloth*);
    //���o�M�˻���
    double GetPrice() const;
    ~Suite();
private:
    //�w��w����A�M��
    vector<Cloth*> _clothes;
};
#endif