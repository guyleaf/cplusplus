#ifndef NUMBER_ARRAY_H
#define NUMBER_ARRAY_H

class NumberArray
{
public:
    //��l�ƼƦC-�����k�s
    NumberArray();
    //�غc������
    NumberArray(vector<float> numbers);
    //���o�����
    float GetMedian() const;
private:
    //�ƦC
    vector<float> _numbers;
    //�ƦC����
    size_t _length;
};
#endif
