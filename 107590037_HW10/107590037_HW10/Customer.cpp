#include "Customer.h"


/*
	�禡�\��: ��l�ƫȤH���

	�Ѽ�: �ȤH�W�r

	�^�ǭ�: �L
*/
Customer::Customer(string name)
{
    _name = name;
    _point = 2000;
    _order = NULL;
}

/*
	�禡�\��: ���o�W�r

	�Ѽ�: �L

	�^�ǭ�: �ȤH�W�r
*/
string Customer::GetName() const
{
    return _name;
}

/*
	�禡�\��: ���o�I��

	�Ѽ�: �L

	�^�ǭ�: �ȤH�I��
*/
double Customer::GetCash() const
{
    return _point;
}

/*
	�禡�\��: �إ߷s�q��

	�Ѽ�: ��w���ө�

	�^�ǭ�: �L
*/
void Customer::MakeNewOrder(Shop* shop)
{
    delete _order;
    _order = new Order(shop);
}

/*
	�禡�\��: �[�J��A�ܭq�椤

	�Ѽ�: ��w����A

	�^�ǭ�: �L
*/
void Customer::AddClothToOrder(Cloth* cloth)
{
    _order->AddCloth(cloth);
}

/*
	�禡�\��: ���o�q���`���B

	�Ѽ�: �L

	�^�ǭ�: �q���`���B
*/
double Customer::GetOrderTotalPrice() const
{
    return _order->GetTotalPrice();
}

/*
	�禡�\��: �ˬd�I�ƬO�_����

	�Ѽ�: �L

	�^�ǭ�: True/False
*/
bool Customer::IsPointEnough() const
{
    return (_point - _order->GetTotalPrice() >= 0) ? true : false;
}

/*
	�禡�\��: �q�榩���I��

	�Ѽ�: �L

	�^�ǭ�: �L
*/
void Customer::ReducePointFromOrder()
{
    _point -= _order->GetTotalPrice();
    delete _order;
    _order = NULL;
}

/*
	�禡�\��: �����q��

	�Ѽ�: �L

	�^�ǭ�: �L
*/
void Customer::CancelOrder()
{
    delete _order;
    _order = NULL;
}

/*
	�禡�\��: ���o�ثe�q��

	�Ѽ�: �L

	�^�ǭ�: �q����
*/
const Order* Customer::GetCurrentOrder() const
{
    return _order;
}


Customer::~Customer()
{
    delete _order;
}
