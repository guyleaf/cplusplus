#include "SubscriberUI.h"

#include <string>
#include <regex>
#include <iostream>

using namespace std;

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

void SubscriberUI::Start()
{
    Menu();
}

void SubscriberUI::Menu()
{
    string username = GetInputUserName();
    string* channelList = GetInputChannelList();
    Subscriber user(username);
    user = channelList;
    delete [] channelList;
    channelList = nullptr;
    PrintInformation(user);
    ResetSubscriber(user);
    PrintInformation(user);
}

void SubscriberUI::PrintInformation(Subscriber& user) const
{
    cout << "Print subscriber" << endl;
    cout << user;
}

void SubscriberUI::ResetSubscriber(Subscriber& user) const
{
    cout << "Reset subscriber" << endl;
    user.Reset();
}

string SubscriberUI::GetInputUserName() const
{
    cout << "Enter the name of subscriber: ";
    string username;
    getline(cin, username);
    return username;
}

string* SubscriberUI::GetInputChannelList() const
{
    string input;
    regex pattern("^[0-9]+$");

    while (true)
    {
        cout << "Enter an arbitrary number of channels: ";
        getline(cin, input);

        if (regex_match(input, pattern))
            break;

        cout << "Invalid Input" << endl;
    }

    int numberOfChannels = stoi(input);
    string* channelList = new string[numberOfChannels];

    for (int i = 0; i < numberOfChannels; i++)
    {
        cout << "Name of channel " << i + 1 << ": ";
        getline(cin, channelList[i]);
    }

    return channelList;
}
