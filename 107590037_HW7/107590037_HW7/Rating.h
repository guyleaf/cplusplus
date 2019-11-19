#ifndef RATING_H
#define RATING_H
class Rating
{
public:
    //資料初始化
    Rating();
    //初始化電影評分資料
    Rating(int reviews, double ratings);
    //取得評論數
    int GetReviews() const;
    //取得總分
    double GetRatings() const;
    //+定義，分數相加
    const Rating operator+(const Rating& movie) const;
    //+=定義，分數相加
    const Rating& operator+=(const Rating& movie);
private:
    //評論數
    int _reviews;
    //總分
    double _ratings;
};
#endif
