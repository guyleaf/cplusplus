/*
	Author: 資工二 107590037 應耀德

	程式功能: 商場管理以及顧客購買系統

	作業編號: HW13
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