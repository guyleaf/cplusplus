/*
	Author: 資工二 107590037 應耀德

	程式功能: 結算電影評分分數

	作業編號: HW7
*/
#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include "Rating.h"

using namespace std;


/*
	函式功能: 載入電影評分資料

	參數: ratingsFile => 檔案資料 movies => 電影清單, order => 清單順序

	回傳值: 無
*/
void LoadRatingsFile(fstream& ratingsFile, map<string, Rating>& movies, vector<string>& order)
{
    //電影數量
    int numberOfMovies;
    //電影名稱
    string movieName;
    //電影分數
    double ratings;
    //讀取電影評論數量
    ratingsFile >> numberOfMovies;
    //忽略換行
    ratingsFile.ignore(1);

    //每一loop代表一部電影資料
    for (int i = 0; i < numberOfMovies; i++)
    {
        //讀取電影名稱
        getline(ratingsFile, movieName);
        //讀取電影分數
        ratingsFile >> ratings;
        //忽略換行
        ratingsFile.ignore(1);

        //如果尚未建立至電影清單，則插入一個
        if (movies.find(movieName) == movies.end())
        {
            //插入電影清單並建立電影分數資料
            movies.insert(pair<string, Rating>(movieName, Rating(1, ratings)));
            //加入至電影順序清單
            order.push_back(movieName);
        }
        else
            //加入分數至電影資料
            movies[movieName] += Rating(1, ratings);
    }
}

/*
	函式功能: 開啟電影資料檔案

	參數: movies => 電影清單, order => 清單順序

	回傳值: 無
*/
void OpenRatingsFile(map<string, Rating>& movies, vector<string>& order)
{
    //檔案名稱
    string fileName = "Data.txt";
    //檔案串流
    fstream ratingsFile;
    //讀取檔案
    ratingsFile.open(fileName, ios::in);

    //檢查是否找到檔案
    if (!ratingsFile)
    {
        cout << "找不到此檔案，請檢查檔案路徑" << endl;
        return;
    }

    //載入電影評分資料
    LoadRatingsFile(ratingsFile, movies, order);
}
/*
	函式功能: 輸出電影分數

	參數: movies => 電影清單, order => 清單順序

	回傳值: 無
*/
void OutputMovieRating(map<string, Rating>& movies, vector<string>& order)
{
    int reviews;
    double ratings;

    //依電影順序輸出
    for (vector<string>::iterator movieName = order.begin(); movieName != order.end(); movieName++)
    {
        reviews = movies[*movieName].GetReviews();
        ratings = movies[*movieName].GetRatings();
        cout << *movieName << ": " << reviews << " ";

        if (reviews > 1)
            cout << "reviews";
        else
            cout << "review";

        cout << ", average of "
             << setprecision(2) << ratings / reviews << " / 5" << endl;
    }
}

int main()
{
    //電影清單
    map<string, Rating> movies;
    //電影順序清單
    vector<string> order;
    //開啟並載入電影評分資料
    OpenRatingsFile(movies, order);
    //輸出電影分數
    OutputMovieRating(movies, order);
    system("PAUSE");
    return 0;
}