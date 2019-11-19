#include "Shop.h"

#include <fstream>
using namespace std;

/*
	函式功能: 初始化店家

	參數: 店家名字

	回傳值: 無
*/
Shop::Shop(string name)
{
    //店家名字
    _name = name;
    //衣服種數
    _numberOfClothes = 0;
    //載入衣服資料
    LoadClothesData("Cloth.txt");
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
void Shop::CreateNewCloth(string name, string description, double price)
{
    //加到衣服資料清單
    _clothes.push_back(new Cloth(name, description, price, ++_numberOfClothes));
}

/*
	函式功能: 取得所有衣服資料

	參數: 無

	回傳值: 所有衣服資料的vector位址
*/
vector<Cloth*>* Shop::GetClothes() const
{
    //衣服資料副本，如果直接回傳_clothes位址，可能會造成外部直接修改內部資料
    vector<Cloth*>* clothes = new vector<Cloth*>;
    //複製衣服資料
    (*clothes) = _clothes;
    return clothes;
}

/*
	函式功能: 載入衣服資料

	參數: 檔案名稱

	回傳值: 無
*/
void Shop::LoadClothesData(string fileName)
{
    fstream clothesList;
    //打開資料文件
    clothesList.open(fileName, fstream::in);
    string head;
    //取第一行標頭資料
    getline(clothesList, head, '\n');

    //檢查標頭是否為name, description, price，否則不予載入
    if (head != "name, description, price")
        return;

    string name, description, price;

    //每loop一次代表完成讀取一行
    while (!clothesList.eof())
    {
        //讀取商品名字
        getline(clothesList, name, ',');
        //忽略空格
        clothesList.ignore(1);
        //讀取商品描述
        getline(clothesList, description, ',');
        //忽略空格
        clothesList.ignore(1);
        //讀取商品價格
        getline(clothesList, price, '\n');
        //建立衣服資料
        CreateNewCloth(name, description, stod(price));
    }

    //關閉檔案
    clothesList.close();
}

