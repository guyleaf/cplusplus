#ifndef SUITE_H
#define SUITE_H

#include "Cloth.h"
#include <vector>
using std::vector;

class Suite : public Cloth
{
public:
    Suite(string name, string description, int id);
    void Add(Cloth*);
    double GetPrice() const;
    ~Suite();
private:
    vector<Cloth*> _clothes;
};
#endif