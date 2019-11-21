#include "Shop.h"

/*
	函式功能: 初始化店家

	參數: 店家名字

	回傳值: 無
*/
Shop::Shop(string name)
{
    _name = name;
    _numberOfClothes = 0;
}

/*
	函式功能: 取得店家名字

	參數: 無

	回傳值: 無
*/
string Shop::GetName() const
{
    return _name;
}

/*
	函式功能: 建立衣服資料

	參數: name: 商品名字, description: 商品描述, price: 商品價格

	回傳值: 無
*/
void Shop::createNewCloth(string name, string description, double price)
{
    //加到衣服資料清單
    _clothes.push_back(new Cloth(name, description, price, ++_numberOfClothes));
}

/*
	函式功能: 取得所有衣服資料

	參數: 無

	回傳值: 所有衣服資料的vector位址
*/
const vector<Cloth*>* Shop::GetClothes() const
{
    /*//衣服資料副本，如果直接回傳_clothes位址，可能會造成外部直接修改內部資料
    vector<Cloth*>* clothes = new vector<Cloth*>;
    //複製衣服資料
    (*clothes) = _clothes;*/
    return &_clothes;
}

/*
	函式功能: 尋找衣服

	參數: 衣服id

	回傳值: 衣服物件
*/
Cloth* Shop::FindCloth(int id) const
{
    for (size_t i = 0; i < _clothes.size(); i++)
    {
        if (_clothes[i]->GetId() == id)
            return _clothes[i];
    }

    return NULL;
}

Shop::~Shop()
{
    for (int i = 0; i < _numberOfClothes; i++)
        delete _clothes[i];
}

