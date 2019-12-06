#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include <string>
using std::string;

class Subscriber
{
public:
    Subscriber(string name);
    void Reset();
    string GetName() const;
    int GetNumberChannels() const;
    const string* GetChannelList() const;
    ~Subscriber();
    void operator=(const string* channelList);
private:
    string _name;
    int _numChannels;
    string* _channelList;
};
#endif
