#include <vector>
using std::vector;
#include "NumberArray.h"

//初始化數列-長度歸零
NumberArray::NumberArray()
{
    _length = 0;
}

//建構物件資料
NumberArray::NumberArray(vector<float> numbers)
{
    _numbers = numbers;
    _length = numbers.size();
}

//取得中間值
float NumberArray::GetMedian() const
{
    //中間值
    float median;
    //取得中間索引值
    size_t index = _length / 2;

    //偶數取index以及index-1的平均值
    if (_length % 2 == 0)
        median = (_numbers[index] + _numbers[index - 1]) / 2;
    else //奇數取index值
        median = _numbers[index];

    return median;
}