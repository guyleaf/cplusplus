/*
	Author: 資工二 107590037 應耀德

	程式功能: 商場管理系統

	作業編號: HW8
*/
#include "Mall.h"
#include "MallUI.h"
int main()
{
    Mall mall;
    MallUI ui(&mall);
    ui.Start();
    system("PAUSE");
    return 0;
}