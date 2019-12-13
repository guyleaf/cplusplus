#include "SubscriberUI.h"

#include <string>
#include <regex>
#include <iostream>

using namespace std;

/*
	函式功能: Subscriber's operator <<

	參數: out => 輸出資料流, user => 訂閱者

	回傳值: 輸出資料流
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
	函式功能: UI畫面

	參數: 無

	回傳值: 無
*/
void SubscriberUI::Menu()
{
    string username = GetInputUserName();
    string* channelList = GetInputChannelList();
    //Initialize
    Subscriber user(username);
    //copy channelList to user
    user = channelList;
    delete[] channelList;
    channelList = nullptr;
    PrintInformation(user);
    ResetChannelList(user);
    PrintInformation(user);
}

/*
	函式功能: 輸出訂閱者的資料

	參數: 訂閱者

	回傳值: 無
*/
void SubscriberUI::PrintInformation(Subscriber& user) const
{
    cout << "Print subscriber" << endl;
    cout << user;
}

/*
	函式功能: 重設訂閱者的頻道清單

	參數: 訂閱者

	回傳值: 無
*/
void SubscriberUI::ResetChannelList(Subscriber& user) const
{
    cout << "Reset subscriber" << endl;
    user.Reset();
}

/*
	函式功能: 取得使用者輸入的使用者名稱

	參數: 無

	回傳值: 字串
*/
string SubscriberUI::GetInputUserName() const
{
    cout << "Enter the name of subscriber: ";
    string username;
    getline(cin, username);
    return username;
}

/*
	函式功能: 取得使用者輸入的頻道清單

	參數: 無

	回傳值: 頻道清單
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

    //convert input into integer
    int numberOfChannels = stoi(input);
    //preserve one array space, the pointer's length function cannot calculate correctly.
    string* channelList = new string[numberOfChannels + 1];

    for (int i = 0; i < numberOfChannels; i++)
    {
        cout << "Name of channel " << i + 1 << ": ";
        getline(cin, channelList[i]);
    }

    return channelList;
}
