#ifndef SUBSCRIBER_UI_H
#define SUBSCRIBER_UI_H

#include "Subscriber.h"
#include <string>

using std::string;

class SubscriberUI
{
public:
    //UI�e��
    void Menu();
private:
    //���o�ϥΪ̿�J���ϥΪ̦W��
    string GetInputUserName() const;
    //���o�ϥΪ̿�J���W�D�M��
    string* GetInputChannelList() const;
    //��X�q�\�̪����
    void PrintInformation(Subscriber& user) const;
    //���]�ϥΪ̪��W�D�M��
    void ResetChannelList(Subscriber& user) const;
};
#endif
