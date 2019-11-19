/*
	Author: ��u�G 107590037 ��ģ�w

	�{���\��: �����[�o���t�ΡA��@�H������

	�������: 2019/10/03
*/
#include <iostream>
#include <regex>
using namespace std;
#include "GasPump.h"

/*
	�禡�\��: �Ы�GasPump����ê�l�Ƴ]�w�o���A�ϥΪ̿�J1�[�ڪ��o��

	�Ѽ�: GasPump������� (call by reference)

	�^�ǭ�: true/false(�O�_�]�m���\)
*/
bool SetGasPump(GasPump*& gasPump)
{
    //�Ȧs��J���
    string input;
    //���h��F�� ������O��J�榡�����T
    regex rule1("^[0-9]+\\.[0-9]+$");
    regex rule2("^[0-9]+$");
    cout << "�п�J1�[�ڪ�����: ";
    getline(cin, input);
    //������e�w�]�m�L������
    delete gasPump;

    //�ˬd��J�O�_�X�k�A���X�k�h��X�L�Ĩê�^���
    if (regex_match(input, rule1) || regex_match(input, rule2))
    {
        //string��double���A�A�]�m�o��
        gasPump = new GasPump(stod(input));
        return true;
    }

    //�קK���s�]�m�ɡA�L�Ŀ�J�A��d���e���󪺰O�����}(�ɭPdelete��}���s�b)
    gasPump = NULL;
    cout << "�L�Ŀ�J\n" << endl;
    return false;
}

/*
	�禡�\��: ��ܥثe�o��

	�Ѽ�: const GasPump���� (call by reference)

	�^�ǭ�: �L
*/
void DisplayCurrentPrice(const GasPump* gasPump)
{
    cout << "�ثe�o���� �C�[�� "
         << gasPump->GetGallonPrice()
         << " ���A �C���� "
         << gasPump->GetLiterPrice()
         << " ��\n" << endl;
}

/*
	�禡�\��: ��ܤW�@���[�o����T

	�Ѽ�: const GasPump���� (call by reference)

	�^�ǭ�: �L
*/
void DisplayLastInfo(const GasPump* gasPump)
{
    cout << gasPump->GetAmountCharged()
         << " ����, "
         << gasPump->GetAmountDispensed()
         << " ��\n" << endl;
}

/*
	�禡�\��: �[�o�{�ǡA�ϥΪ̿�J�n�[�h�֤��ɼƪ��o�A��ܥ[�o�i��

	�Ѽ�: GasPump���� (call by reference)

	�^�ǭ�: �L
*/
void StartFilling(GasPump* gasPump)
{
    //�Ȧs��J���
    string input;
    //���h��F�� ������O��J�榡�����T
    regex rule("^[0-9]+$");
    cout << "�п�J�n�[�X���ɪ��o: ";
    getline(cin, input);

    //�ˬd��J�O�_�X�k�A���X�k�h���L�[�o�{�Ǩê�^���
    if (regex_match(input, rule))
    {
        //�}�l�[�o
        vector<string> gasInfo = gasPump->Start(stoi(input));

        //��X�[�o�i��
        for (vector<string>::iterator sentence = gasInfo.begin(); sentence != gasInfo.end(); sentence++)
        {
            cout << *sentence << endl;
        }

        return;
    }

    cout << "�L�Ŀ�J\n" << endl;
    return;
}

//�Ҧ���ܾ�
void ModeController()
{
    //�O�_�w�]�m�o��
    bool priceIsSet = false;
    //�ŧigaspump������Ь�NULL
    GasPump* gasPump = NULL;
    //�Ȧs��J���O
    string command;
    //���h��F�� ������O��J�榡�����T
    regex rule("^[1-5]$");

    while (true)
    {
        cout << "1. �]�w�o��" << endl;
        cout << "2. ��ܥثe���o��" << endl;
        cout << "3. ��ܤW�@���[�o����T" << endl;
        cout << "4. �}�l�[�o" << endl;
        cout << "5. ����" << endl;
        cout << "�п�J���O: ";
        getline(cin, command);

        //�ˬd���O�O�_�X�k
        if (regex_match(command, rule))
        {
            if (command == "1")  //mode 1 �]�w�o��
                priceIsSet = SetGasPump(gasPump);
            else if (command == "5") //mode 5 ���}
                break;
            else if (priceIsSet) //�ˬd�O�_�o���w�]�m
            {
                if (command == "2") //mode 2 ��ܥثe���o��
                    DisplayCurrentPrice(gasPump);
                else if (command == "3") //mode 3 ��ܤW�@���[�o����T
                    DisplayLastInfo(gasPump);
                else if (command == "4") //mode 4 �i�J�[�o�{��
                    StartFilling(gasPump);
            }
            else
                cout << "�Х��]�w�o��\n" << endl;
        }
    }

    //����O����
    delete gasPump;
}

int main()
{
    //�Ҧ���ܾ�
    ModeController();
    system("PAUSE");
    return 0;
}