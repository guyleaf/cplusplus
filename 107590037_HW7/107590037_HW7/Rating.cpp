#include "Rating.h"


//資料初始化
Rating::Rating()
{
    _reviews = 0;
    _ratings = 0;
}

//初始化電影評分資料
Rating::Rating(int reviews, double ratings)
{
    _reviews = reviews;
    _ratings = ratings;
}

//+=定義，分數相加
const Rating& Rating::operator+=(const Rating& movie)
{
    _ratings += movie._ratings;
    _reviews++;
    return *this;
}

//+定義，分數相加
const Rating Rating::operator+(const Rating& movie) const
{
    int sumOfReviews = _reviews + movie._reviews;
    double sumOfRatings = _ratings + movie._ratings;
    return Rating(sumOfReviews, sumOfRatings);
}

//取得評論數
int Rating::GetReviews() const
{
    return _reviews;
}

//取得總分
double Rating::GetRatings() const
{
    return _ratings;
}

