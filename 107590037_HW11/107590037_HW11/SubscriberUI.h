#ifndef SUBSCRIBER_UI_H
#define SUBSCRIBER_UI_H

#include "Subscriber.h"
#include <string>

using std::string;

class SubscriberUI
{
public:
    void Start();
private:
    void Menu();
    string GetInputUserName() const;
    string* GetInputChannelList() const;
    void PrintInformation(Subscriber& user) const;
    void ResetSubscriber(Subscriber& user) const;
};
#endif
