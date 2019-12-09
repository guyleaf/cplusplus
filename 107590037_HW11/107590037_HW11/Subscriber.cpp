#include "Subscriber.h"
#include <iostream>
/*
	ㄧΑ: Initialize

	把计: 璹綷嘿

	肚: 礚
*/
Subscriber::Subscriber(string name)
{
    _name = name;
    _numChannels = 0;
    _channelList = nullptr;
}

/*
	ㄧΑ: Reset the channel list

	把计: 礚

	肚: 礚
*/
void Subscriber::Reset()
{
    _numChannels = 0;
    delete [] _channelList;
    _channelList = nullptr;
}

/*
	ㄧΑ: Get subscriber's name

	把计: 礚

	肚: 璹綷嘿
*/
string Subscriber::GetName() const
{
    return _name;
}

/*
	ㄧΑ: Get subscriber's number of channel list

	把计: 礚

	肚: 繵笵计秖
*/
int Subscriber::GetNumberChannels() const
{
    return _numChannels;
}

/*
	ㄧΑ: Get subscriber's number of channels in subscriber's channel list

	把计: 礚

	肚: 繵笵睲虫
*/
const string* Subscriber::GetChannelList() const
{
    return _channelList;
}

/*
	ㄧΑ: operator = :copy the channel list to subscriber's channel list

	把计: 繵笵睲虫

	肚: 礚
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
