#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include <string>
using std::string;

class Subscriber
{
public:
    //Initialize
    Subscriber(string name);
    //Reset the channel ist
    void Reset();
    //Get subscriber's name
    string GetName() const;
    //Get subscriber's number of channels in subscriber's channel list
    int GetNumberChannels() const;
    //Get subscriber's channel list with constant
    const string* GetChannelList() const;
    ~Subscriber();
    //operator = :copy the channel list to subscriber's channel list
    void operator=(const string* channelList);
private:
    //subscriber's name
    string _name;
    //the number of channels in subscriber's channel list
    int _numChannels;
    //subscriber's channel list
    string* _channelList;
};
#endif
