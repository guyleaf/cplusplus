#ifndef NUMBER_ARRAY_H
#define NUMBER_ARRAY_H

class NumberArray
{
public:
    //﹍て计-耴箂
    NumberArray();
    //篶ン戈
    NumberArray(vector<float> numbers);
    //眔い计
    float GetMedian() const;
private:
    //计
    vector<float> _numbers;
    //计
    size_t _length;
};
#endif
