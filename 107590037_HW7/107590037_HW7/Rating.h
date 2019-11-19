#ifndef RATING_H
#define RATING_H
class Rating
{
public:
    //��ƪ�l��
    Rating();
    //��l�ƹq�v�������
    Rating(int reviews, double ratings);
    //���o���׼�
    int GetReviews() const;
    //���o�`��
    double GetRatings() const;
    //+�w�q�A���Ƭۥ[
    const Rating operator+(const Rating& movie) const;
    //+=�w�q�A���Ƭۥ[
    const Rating& operator+=(const Rating& movie);
private:
    //���׼�
    int _reviews;
    //�`��
    double _ratings;
};
#endif
