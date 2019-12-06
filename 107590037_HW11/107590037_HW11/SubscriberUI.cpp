#include "SubscriberUI.h"

#include <string>
#include <regex>
#include <iostream>

using namespace std;

/*
	�禡�\��: Subscriber's operator <<

	�Ѽ�: out => ��X��Ƭy, user => �q�\��

	�^�ǭ�: ��X��Ƭy
*/
ostream& operator<<(ostream& out, const Subscriber& user)
{
    out << "----Name of subscriber: " << user.GetName() << endl;
    out << "----Number of channels: " << user.GetNumberChannels() << endl;
    const string* channelList = user.GetChannelList();

    for (int i = 0; i < user.GetNumberChannels(); i++)
    {
        out << "----Name of channel" << i + 1 << ": " << channelList[i] << endl;
    }

    return out;
}

/*
	�禡�\��: UI�e��

	�Ѽ�: �L

	�^�ǭ�: �L
*/
void SubscriberUI::Menu()
{
    string username = GetInputUserName();
    string* channelList = GetInputChannelList();
    //Initialize
    Subscriber user(username);
    //copy channelList to user
    user = channelList;
    PrintInformation(user);
    ResetChannelList(user);
    PrintInformation(user);
    delete[] channelList;
    channelList = nullptr;
}

/*
	�禡�\��: ��X�q�\�̪����

	�Ѽ�: �q�\��

	�^�ǭ�: �L
*/
void SubscriberUI::PrintInformation(Subscriber& user) const
{
    cout << "Print subscriber" << endl;
    cout << user;
}

/*
	�禡�\��: ���]�q�\�̪��W�D�M��

	�Ѽ�: �q�\��

	�^�ǭ�: �L
*/
void SubscriberUI::ResetChannelList(Subscriber& user) const
{
    cout << "Reset subscriber" << endl;
    user.Reset();
}

/*
	�禡�\��: ���o�ϥΪ̿�J���ϥΪ̦W��

	�Ѽ�: �L

	�^�ǭ�: �r��
*/
string SubscriberUI::GetInputUserName() const
{
    cout << "Enter the name of subscriber: ";
    string username;
    getline(cin, username);
    return username;
}

/*
	�禡�\��: ���o�ϥΪ̿�J���W�D�M��

	�Ѽ�: �L

	�^�ǭ�: �W�D�M��
*/
string* SubscriberUI::GetInputChannelList() const
{
    string input;
    //The rule of input
    regex pattern("^[0-9]+$");

    while (true)
    {
        cout << "Enter an arbitrary number of channels: ";
        getline(cin, input);

        //Avoid enter wrong type
        if (regex_match(input, pattern))
            break;

        cout << "Invalid Input" << endl;
    }

    //convert input into number
    int numberOfChannels = stoi(input);
    string* channelList = new string[numberOfChannels];

    for (int i = 0; i < numberOfChannels; i++)
    {
        cout << "Name of channel " << i + 1 << ": ";
        getline(cin, channelList[i]);
    }

    return channelList;
}