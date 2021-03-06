#ifndef NUMBER_ARRAY_H
#define NUMBER_ARRAY_H

class NumberArray
{
public:
    //初始化數列-長度歸零
    NumberArray();
    //建構物件資料
    NumberArray(vector<float> numbers);
    //取得中位數
    float GetMedian() const;
private:
    //數列
    vector<float> _numbers;
    //數列長度
    size_t _length;
};
#endif
