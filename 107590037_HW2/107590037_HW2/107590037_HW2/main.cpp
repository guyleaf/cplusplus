/*
	Author: ��u�G 107590037 ��ģ�w

	�{���\��: �պ�2-50�ӤH�A�C�ը�H�H�W�P�@�Ѫ��ͤ���v (�C�դ��5000��)

	�@�~�s��: HW2

	�������: 2019/09/21
*/
#include <iostream>
#include <cstdlib>

using namespace std;

//���ͤ@�ӤH���ͤ��� 0-364
int GenerateBirthday()
{
    return static_cast<int>((static_cast<double>(rand()) / (RAND_MAX + 1)) * 365);
}

//�p��ͤ����ۦP�����v
double CaculateProbability(int peopleCount)
{
    //�@�~��365�� day�ΨӰO���C�Ѧ��X�ӤH�ͤ�
    int day[365];
    //�C���`�@���TRIALS��
    const int TRIALS = 5000;
    //�ΨӰO���C�դ��TRIALS�����A���X���ͤ�ۦP
    int totalCount = 0;

    //�@�դ��TRIALS��
    for (int i = 1; i <= TRIALS; i++)
    {
        //day�C�Ѫ��ͤ�H�ƥ����k�s��l��
        for (int j = 0; j <= 364; day[j++] = 0);

        //����peopleCount�ӤH���ͤ���
        for (int j = 1; j <= peopleCount; j++)
        {
            //���ͤ@�ӤH���ͤ����çP�_�O�_�P��L�H���ͤ�ۦP
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
    //�̤j�H��
    const int MAX_PEOPLE = 50;

    //2~50�ӤH
    for (int peopleCount = 2; peopleCount <= MAX_PEOPLE; peopleCount++)
    {
        //�p��ͤ����ۦP�����v�ÿ�X
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