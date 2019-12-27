#include "Cloth.h"

/*
	ㄧΑ: ﹍て︾狝戈

	把计: name: ︾狝, description: ︾狝磞瓃, price: ︾狝基

	肚: 礚
*/
Cloth::Cloth(string name, string description, double price, int id)
{
    _name = name;
    _description = description;
    _price = price;
    _id = id;
}

/*
	ㄧΑ: 眔︾狝嘿

	把计: 礚

	肚: ︾狝嘿
*/
string Cloth::GetName() const
{
    return _name;
}

/*
	ㄧΑ: 眔︾狝磞瓃

	把计: 礚

	肚: ︾狝磞瓃
*/
string Cloth::GetDescription() const
{
    return _description;
}

/*
	ㄧΑ: 眔︾狝基

	把计: 礚

	肚: ︾狝基
*/
double Cloth::GetPrice() const
{
    return _price;
}

/*
	ㄧΑ: 眔︾狝絪腹

	把计: 礚

	肚: ︾狝絪腹
*/
int Cloth::GetId() const
{
    return _id;
}

Cloth::~Cloth()
{
}