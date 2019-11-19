#include <vector>
#include <algorithm>
using namespace std;
#include "NumberArray.h"

//﹍て计-耴箂
NumberArray::NumberArray()
{
    _length = 0;
}

//篶ン戈
NumberArray::NumberArray(const vector<float>& numbers)
{
    _numbers = numbers;
    _length = numbers.size();
    //逼计
    sort(_numbers.begin(), _numbers.end());
}

//眔い丁
float NumberArray::GetMedian() const
{
    //い丁
    float median;
    //眔い丁ま
    size_t index = _length / 2;

    if (_length % 2 == 0) //案计indexのindex-1キА
        median = (_numbers[index] + _numbers[index - 1]) / 2;
    else //计index
        median = _numbers[index];

    return median;
}