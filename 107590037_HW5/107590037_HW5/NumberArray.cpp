#include <vector>
using std::vector;
#include "NumberArray.h"

//﹍て计-耴箂
NumberArray::NumberArray()
{
    _length = 0;
}

//篶ン戈
NumberArray::NumberArray(vector<float> numbers)
{
    _numbers = numbers;
    _length = numbers.size();
}

//眔い丁
float NumberArray::GetMedian() const
{
    //い丁
    float median;
    //眔い丁ま
    size_t index = _length / 2;

    //案计indexのindex-1キА
    if (_length % 2 == 0)
        median = (_numbers[index] + _numbers[index - 1]) / 2;
    else //计index
        median = _numbers[index];

    return median;
}