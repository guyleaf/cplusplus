#include <vector>
#include <algorithm>
using namespace std;
#include "NumberArray.h"

//��l�ƼƦC-�����k�s
NumberArray::NumberArray()
{
    _length = 0;
}

//�غc������
NumberArray::NumberArray(const vector<float>& numbers)
{
    _numbers = numbers;
    _length = numbers.size();
    //�ƧǼƦC
    sort(_numbers.begin(), _numbers.end());
}

//���o������
float NumberArray::GetMedian() const
{
    //������
    float median;
    //���o��������
    size_t index = _length / 2;

    if (_length % 2 == 0) //���ƨ�index�H��index-1��������
        median = (_numbers[index] + _numbers[index - 1]) / 2;
    else //�_�ƨ�index��
        median = _numbers[index];

    return median;
}