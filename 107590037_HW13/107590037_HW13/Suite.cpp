#include "Suite.h"
#include <iostream>

Suite::Suite(string name, string description, int id) : Cloth(name, description, 0, id)
{
}

void Suite::Add(Cloth* cloth)
{
    _clothes.push_back(cloth);
    _price += cloth->GetPrice();
}

double Suite::GetPrice() const
{
    return _price * 0.9;
}

Suite::~Suite()
{
    std::cout << "destructor" << std::endl;
}
