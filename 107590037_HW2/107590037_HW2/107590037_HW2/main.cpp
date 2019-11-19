/*
	Author: 資工二 107590037 應耀德

	程式功能: 試算2-50個人，每組兩人以上同一天的生日機率 (每組比較5000次)

	作業編號: HW2

	完成日期: 2019/09/21
*/
#include <iostream>
#include <cstdlib>

using namespace std;

//產生一個人的生日日期 0-364
int GenerateBirthday()
{
    return static_cast<int>((static_cast<double>(rand()) / (RAND_MAX + 1)) * 365);
}

//計算生日日期相同的機率
double CaculateProbability(int peopleCount)
{
    //一年有365天 day用來記錄每天有幾個人生日
    int day[365];
    //每組總共比較TRIALS次
    const int TRIALS = 5000;
    //用來記錄每組比較TRIALS次中，有幾次生日相同
    int totalCount = 0;

    //一組比較TRIALS次
    for (int i = 1; i <= TRIALS; i++)
    {
        //day每天的生日人數全部歸零初始化
        for (int j = 0; j <= 364; day[j++] = 0);

        //產生peopleCount個人的生日日期
        for (int j = 1; j <= peopleCount; j++)
        {
            //產生一個人的生日日期並判斷是否與其他人的生日相同
            if (++day[GenerateBirthday()] > 1)
            {
                totalCount++;
                break;
            }
        }
    }

    return static_cast<double>(totalCount) / TRIALS;
}

void OutputProbability()
{
    //最大人數
    const int MAX_PEOPLE = 50;

    //2~50個人
    for (int peopleCount = 2; peopleCount <= MAX_PEOPLE; peopleCount++)
    {
        //計算生日日期相同的機率並輸出
        cout.precision(4);
        cout << "For " << peopleCount << " people, the probability of two birthdays is about "
             << CaculateProbability(peopleCount) << endl;
    }
}

int main()
{
    OutputProbability();
    system("PAUSE");
    return 0;
}