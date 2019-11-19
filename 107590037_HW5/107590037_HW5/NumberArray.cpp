#include <vector>
using std::vector;
#include "NumberArray.h"

//��l�ƼƦC-�����k�s
NumberArray::NumberArray()
{
    _length = 0;
}

//�غc������
NumberArray::NumberArray(vector<float> numbers)
{
    _numbers = numbers;
    _length = numbers.size();
}

//���o������
float NumberArray::GetMedian() const
{
    //������
    float median;
    //���o�������ޭ�
    size_t index = _length / 2;

    //���ƨ�index�H��index-1��������
    if (_length % 2 == 0)
        median = (_numbers[index] + _numbers[index - 1]) / 2;
    else //�_�ƨ�index��
        median = _numbers[index];

    return median;
}