#include "Subscriber.h"

Subscriber::Subscriber(string name)
{
    _name = name;
}

void Subscriber::Reset()
{
    _numChannels = 0;
    delete [] _channelList;
    _channelList = nullptr;
}

string Subscriber::GetName() const
{
    return _name;
}

int Subscriber::GetNumberChannels() const
{
    return _numChannels;
}

const string* Subscriber::GetChannelList() const
{
    return _channelList;
}

void Subscriber::operator=(const string* channelList)
{
    _numChannels = (int)channelList->size();
    _channelList = new string[_numChannels];

    for (int i = 0; i < _numChannels; i++)
        _channelList[i] = channelList[i];
}

Subscriber::~Subscriber()
{
    delete [] _channelList;
}
