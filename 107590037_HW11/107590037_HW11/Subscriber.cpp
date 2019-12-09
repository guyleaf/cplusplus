#include "Subscriber.h"
#include <iostream>
/*
	�禡�\��: Initialize

	�Ѽ�: �q�\�̦W��

	�^�ǭ�: �L
*/
Subscriber::Subscriber(string name)
{
    _name = name;
    _numChannels = 0;
    _channelList = nullptr;
}

/*
	�禡�\��: Reset the channel list

	�Ѽ�: �L

	�^�ǭ�: �L
*/
void Subscriber::Reset()
{
    _numChannels = 0;
    delete [] _channelList;
    _channelList = nullptr;
}

/*
	�禡�\��: Get subscriber's name

	�Ѽ�: �L

	�^�ǭ�: �q�\�̦W��
*/
string Subscriber::GetName() const
{
    return _name;
}

/*
	�禡�\��: Get subscriber's number of channel list

	�Ѽ�: �L

	�^�ǭ�: �W�D�ƶq
*/
int Subscriber::GetNumberChannels() const
{
    return _numChannels;
}

/*
	�禡�\��: Get subscriber's number of channels in subscriber's channel list

	�Ѽ�: �L

	�^�ǭ�: �W�D�M��
*/
const string* Subscriber::GetChannelList() const
{
    return _channelList;
}

/*
	�禡�\��: operator = :copy the channel list to subscriber's channel list

	�Ѽ�: �W�D�M��

	�^�ǭ�: �L
*/
void Subscriber::operator=(const string* channelList)
{
    //count the number of channelList
    size_t i = 0;

    while (!channelList[i].empty())
        i++;

    _numChannels = (int)i;
    //make another channel list
    _channelList = new string[_numChannels];

    for (int i = 0; i < _numChannels; i++)
        _channelList[i] = channelList[i];
}

Subscriber::~Subscriber()
{
    delete [] _channelList;
}
