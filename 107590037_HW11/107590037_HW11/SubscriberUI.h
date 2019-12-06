#ifndef SUBSCRIBER_UI_H
#define SUBSCRIBER_UI_H

#include "Subscriber.h"
#include <string>

using std::string;

class SubscriberUI
{
public:
    //UI畫面
    void Menu();
private:
    //取得使用者輸入的使用者名稱
    string GetInputUserName() const;
    //取得使用者輸入的頻道清單
    string* GetInputChannelList() const;
    //輸出訂閱者的資料
    void PrintInformation(Subscriber& user) const;
    //重設使用者的頻道清單
    void ResetChannelList(Subscriber& user) const;
};
#endif
