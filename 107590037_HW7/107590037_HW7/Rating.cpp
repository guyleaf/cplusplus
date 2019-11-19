#include "Rating.h"


//��ƪ�l��
Rating::Rating()
{
    _reviews = 0;
    _ratings = 0;
}

//��l�ƹq�v�������
Rating::Rating(int reviews, double ratings)
{
    _reviews = reviews;
    _ratings = ratings;
}

//+=�w�q�A���Ƭۥ[
const Rating& Rating::operator+=(const Rating& movie)
{
    _ratings += movie._ratings;
    _reviews++;
    return *this;
}

//+�w�q�A���Ƭۥ[
const Rating Rating::operator+(const Rating& movie) const
{
    int sumOfReviews = _reviews + movie._reviews;
    double sumOfRatings = _ratings + movie._ratings;
    return Rating(sumOfReviews, sumOfRatings);
}

//���o���׼�
int Rating::GetReviews() const
{
    return _reviews;
}

//���o�`��
double Rating::GetRatings() const
{
    return _ratings;
}

