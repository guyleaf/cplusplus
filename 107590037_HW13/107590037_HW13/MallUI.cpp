#include "MallUI.h"
#include <iostream>
#include <regex>
#include <iomanip>
#include <utility>
using namespace std;

/*
	�禡�\��: ��l�ưӳ�UI

	�Ѽ�: �ӳ�Model

	�^�ǭ�: �L
*/
MallUI::MallUI(Mall* mall)
{
    _mall = mall;
    _exit = false;
    _shopsOrder.push_back("UNIQLO");
    _shopsOrder.push_back("H&M");
    _shopsOrder.push_back("ZARA");
    _numberOfShops = _shopsOrder.size();
    _customersOrder.push_back("Amber");
    _customersOrder.push_back("Tim");
    _customersOrder.push_back("Marry");
    _numberOfCustomers = _customersOrder.size();
}

/*
	�禡�\��: ���UI�e��

	�Ѽ�: �L

	�^�ǭ�: �L
*/
void MallUI::Start()
{
    //��w���ө��W��
    string shopName, customerName;

    while (!_exit)
    {
        CustomersMenu(customerName);

        //���}
        if (_exit)
            break;

        MallsMenu(shopName);
        SelectCustomerAndShop(customerName, shopName);
        ShopMenu(shopName, customerName);
    }
}

/*
	�禡�\��: ���o�ȤH�W��

	�Ѽ�: index

	�^�ǭ�: �ȤH�W��
*/
string MallUI::GetCustomerName(int index) const
{
    return _customersOrder[index - 1];
}

/*
	�禡�\��: ���o�ө��W��

	�Ѽ�: index

	�^�ǭ�: �ө��W��
*/
string MallUI::GetShopName(int index) const
{
    return _shopsOrder[index - 1];
}

/*
	�禡�\��: ��ܫȤH���UI

	�Ѽ�: �L

	�^�ǭ�: �L
*/
void MallUI::ShowCustomersMenu() const
{
    //�C�X�ȤH���
    for (size_t i = 0; i < _numberOfCustomers; i++)
        cout << i + 1 << "." << _customersOrder[i] << endl;

    cout << _numberOfCustomers + 1 << "." << "���}" << endl;
}

/*
	�禡�\��: �ȤH���

	�Ѽ�: ��w���ȤH�W��

	�^�ǭ�: �L
*/
void MallUI::CustomersMenu(string& customerName)
{
    //�Ȧs��J���
    string command;
    const size_t MAX_COMMAND_SIZE = _numberOfCustomers;
    const string EXIT_COMMAND = to_string(_numberOfCustomers + 1);
    //��ܫȤH�W�h
    regex rule("^[1-" + to_string(MAX_COMMAND_SIZE) + "]$");
    ShowCustomersMenu();

    while (true)
    {
        cout << "select customer: ";
        //���o����J���O
        command = GetCommand();

        //�ˬd�O�_�ŦX��ܫȤH�W�h
        if (regex_match(command, rule))
        {
            customerName = GetCustomerName(stoi(command));
            break;
        }
        else if (command == EXIT_COMMAND)
        {
            _exit = true;
            break;
        }

        cout << "�п�ܵe���W���ȤH" << endl;
    }
}

/*
	�禡�\��: ��ܰӳ����UI

	�Ѽ�: �L

	�^�ǭ�: �L
*/
void MallUI::ShowMallsMenu() const
{
    //�C�X���a�M��
    for (size_t i = 0; i < _numberOfShops; i++)
        cout << i + 1 << "." << _shopsOrder[i] << endl;
}

/*
	�禡�\��: �ӳ����

	�Ѽ�: ��w���ө��W��

	�^�ǭ�: �L
*/
void MallUI::MallsMenu(string& shopName)
{
    //�Ȧs��J���
    string command;
    const size_t MAX_COMMAND_SIZE = _numberOfShops;
    const string EXIT_COMMAND = to_string(_numberOfShops + 1);
    //��ܰө��W�h
    regex rule("^[1-" + to_string(MAX_COMMAND_SIZE) + "]$");
    ShowMallsMenu();

    while (true)
    {
        cout << "Select Shop: ";
        //���o����J���O
        command = GetCommand();

        //�ˬd�O�_�ŦX��ܰӳ��W�h
        if (regex_match(command, rule))
        {
            shopName = GetShopName(stoi(command));
            break;
        }

        cout << "�п�ܵe���W�����a" << endl;
    }
}

/*
	�禡�\��: ��ܰө����UI

	�Ѽ�: shopName => ��w���ө��W��, customerName => ��w���ȤH�W��

	�^�ǭ�: �L
*/
void MallUI::ShowShopMenu(const string shopName, const string customerName) const
{
    cout << "�˷R�����U��: " << customerName << "�A�z�n!" << endl;
    cout << "(" + shopName + ")1.�s�W��A" << endl;
    cout << "(" + shopName + ")2.�d�ݩҦ���A" << endl;
    cout << "(" + shopName + ")3.�إ߷s�q��" << endl;
    cout << "(" + shopName + ")4.�ʶR��A" << endl;
    cout << "(" + shopName + ")5.�����q��" << endl;
    cout << "(" + shopName + ")6.�d�ݳѾl�I��" << endl;
    cout << "(" + shopName + ")7.�d�ݾ��v����" << endl;
    cout << "(" + shopName + ")8.���}" << endl;
    cout << "�п�J���: ";
}

/*
	�禡�\��: �ө����

	�Ѽ�: shopName => ��w���ө��W��, customerName => ��w���ȤH�W��

	�^�ǭ�: �L
*/
void MallUI::ShopMenu(string& shopName, string& customerName)
{
    //�x�s��J���O�N��
    string command;
    //��ܰө��W�h
    regex rule("^[1-8]$");
    ShowShopMenu(shopName, customerName);

    while (true)
    {
        //���o����J���O
        command = GetCommand();

        //�ˬd�O�_�ŦX��ܰө��W�h
        if (regex_match(command, rule))
        {
            if (command == "1") //�\��@ �s�W��A
                AddNewClothes();
            else if (command == "2") //�\��G ��ܩҦ���A�w�s
                DisplayAllClothes();
            else if (command == "3") //�\��T �إ߷s�q��
                MakeNewOrder();
            else if (command == "4") //�\��| �ʶR��A
                AddClothesToOrder(shopName);
            else if (command == "5") //�\�भ �����q��
                CheckOutOrder(shopName);
            else if (command == "6") //�\�ऻ �d�ݳѾl�I��
                CheckLeftPoint();
            else if (command == "7") //�\��C �d�ݾ��v����
                CheckPastOrders(customerName);
            else if (command == "8") //��^�ӳ�
                break;

            ShowShopMenu(shopName, customerName);
        }
        else
            cout << "�п�J���T���ﶵ: ";
    }
}

/*
	�禡�\��: ���o����J���O

	�Ѽ�: �L

	�^�ǭ�: ���O�N��
*/
string MallUI::GetCommand()
{
    //�Ȧs��J��
    string input;
    getline(cin, input);
    return input;
}

/*
	�禡�\��: ���o��A�W��

	�Ѽ�: �L

	�^�ǭ�: ��A�W��
*/
string MallUI::GetClothName()
{
    //�Ȧs��J��
    string input;
    cout << "�п�J��A�W��: ";
    getline(cin, input);
    return input;
}

/*
	�禡�\��: ���o��A�y�z

	�Ѽ�: �L

	�^�ǭ�: ��A�y�z
*/
string MallUI::GetClothDescription()
{
    //�Ȧs��J��
    string input;
    cout << "�п�J��A�y�z: ";
    getline(cin, input);
    return input;
}

/*
	�禡�\��: ���o��A����

	�Ѽ�: �L

	�^�ǭ�: ��A����
*/
double MallUI::GetClothPrice()
{
    //�Ȧs��J���
    string data;
    double price;
    cout << "�п�J����: ";

    while (getline(cin, data))
    {
        //�ŦX�W�h�B���椣���s
        if (IsNumber(data) && IsPositive(data) && stod(data) != 0)
        {
            price = stod(data);
            break;
        }

        //�P�_��J�O���ؿ��~
        //���e�w�P�_�O�_�����ƻP������0�A�ҥH�u�ݭn�P�_�O�_���Ʀr�Y�i
        if (IsNumber(data))
            cout << "���椣��p�󵥩�s�A�Э��s��J" << endl;
        else
            cout << "���椣���\�D�Ʀr�榡�A�Э��s��J" << endl;

        cout << "�п�J����: ";
    }

    return price;
}

/*
	�禡�\��: �s�W��A

	�Ѽ�: �L

	�^�ǭ�: �L
*/
void MallUI::AddNewClothes()
{
    string name = GetClothName();
    string description = GetClothDescription();
    double price = GetClothPrice();
    _mall->CreateNewCloth(name, description, price);
}

/*
	�禡�\��: ��ܩ��a�Ҧ���A���

	�Ѽ�: �L

	�^�ǭ�: �L
*/
void MallUI::DisplayAllClothes() const
{
    //���o���a�Ҧ���A���
    const vector<Cloth*>* clothesData = _mall->GetClothes();
    cout << left << setw(8) << "No." << left << setw(48) << "��A�W��" << left << setw(8) << "����" << "�y�z" << endl;

    //��X��A���
    for (size_t i = 0; i < clothesData->size(); i++)
    {
        cout << left << setw(8) << (*clothesData)[i]->GetId()
             << left << setw(48) << (*clothesData)[i]->GetName()
             << left << setw(8) << setprecision(1) << fixed << (*clothesData)[i]->GetPrice()
             << (*clothesData)[i]->GetDescription() << endl;
    }

    cout << endl;
}

/*
	�禡�\��: �إ߷s�q��

	�Ѽ�: �L

	�^�ǭ�: �L
*/
void MallUI::MakeNewOrder()
{
    _mall->MakeNewOrder();
    cout << "���\�إ߷s�q��!!!" << endl << endl;
}

/*
	�禡�\��: �ʶR��A

	�Ѽ�: �L

	�^�ǭ�: �L
*/
void MallUI::AddClothesToOrder(string shopName)
{
    //�q�椣�s�b�A�h�����ø��X
    if (_mall->GetCurrentOrder() == NULL || _mall->GetCurrentOrder()->GetShop()->GetName() != shopName)
    {
        cout << "�Ыإ߭q��A�~���ʶR��A!" << endl << endl;
        return;
    }

    DisplayAllClothes();

    while (true)
    {
        int clothIndex = GetClothId();

        //��J-1�ɸ��X
        if (clothIndex == -1)
            break;

        int clothCount = GetClothCount();

        //�̦�A��Ʀөw
        for (int i = 0; i < clothCount; i++)
            _mall->AddClothToOrder(clothIndex);
    }
}

/*
	�禡�\��: �q�浲�b

	�Ѽ�: �L

	�^�ǭ�: �L
*/
void MallUI::CheckOutOrder(string shopName)
{
    //�q�椣�s�b�A�h�����ø��X
    if (_mall->GetCurrentOrder() == NULL or _mall->GetCurrentOrder()->GetShop()->GetName() != shopName)
    {
        cout << "�Х��إ߷s�q��A�~��������q�� !" << endl << endl;
        return;
    }

    if (_mall->IsPointEnough())
    {
        _mall->ReducePointFromOrder();
        cout << "�q�浲�����\!" << endl << endl;
        return;
    }

    cout << "�Ѿl�I�Ƥ����A�L�k�i���ʶR!" << endl << endl;
    _mall->CancelOrder();
}

/*
	�禡�\��: �d�߳Ѿl�I��

	�Ѽ�: �L

	�^�ǭ�: �L
*/
void MallUI::CheckLeftPoint()
{
    cout << "�z�Ѿl���I�ƳѤU: " << _mall->GetCash() << endl << endl;
}

/*
	�禡�\��: �d�߾��v����

	�Ѽ�: �L

	�^�ǭ�: �L
*/
void MallUI::CheckPastOrders(string customerName)
{
    const vector<Order*>* orders = _mall->GetPurchasedHistoryFrom();
    vector<pair<Cloth*, int>> countedClothes;

    if (orders->size() != 0)
        countedClothes = CountClothesOfOrders(orders);

    delete orders;
    cout << customerName << "�����v�ʶR����:" << endl;
    cout << left << setw(8) << "�W��" << left << setw(8) << "�ƶq" << left << setw(8) << "���" << left << setw(8) << "�`��" << endl;

    for (size_t i = 0; i < countedClothes.size(); i++)
    {
        if (countedClothes[i].second != 0)
        {
            cout << left << setw(8) << countedClothes[i].first->GetName();
            cout << left << setw(8) << countedClothes[i].second;
            cout << left << setw(8) << countedClothes[i].first->GetPrice();
            cout << left << setw(8) << countedClothes[i].first->GetPrice() * countedClothes[i].second << endl;
        }
    }
}

/*
	�禡�\��: �έp�q���A���

	�Ѽ�: �h���q��

	�^�ǭ�: �w�έp����A����
*/
vector<pair<Cloth*, int>> MallUI::CountClothesOfOrders(const vector<Order*>* orders)
{
    //��A����
    const vector<Cloth*>* clothesData = _mall->GetClothes();
    //�w�έp����A����
    vector<pair<Cloth*, int>> countedClothes;

    //��l�ƿ�J��A����
    for (size_t i = 0; i < clothesData->size(); i++)
        countedClothes.push_back(make_pair((*clothesData)[i], 0));

    //�έp�C�@���q�檺��A���
    for (size_t i = 0; i < orders->size(); i++)
    {
        //�ӵ��q�檺��A���
        const vector<Cloth*>* clothes = (*orders)[i]->GetClothes();

        //�έp
        for (size_t j = 0; j < clothes->size(); j++)
        {
            for (size_t k = 0; k < countedClothes.size(); k++)
            {
                if (countedClothes[k].first->GetName() == (*clothes)[j]->GetName())
                    countedClothes[k].second++;
            }
        }
    }

    return countedClothes;
}

/*
	�禡�\��: ���o��AID

	�Ѽ�: �L

	�^�ǭ�: ��AID
*/
int MallUI::GetClothId()
{
    string input;
    cout << "�п�J��AID, ���}�п�J-1: ";
    getline(cin, input);
    return stoi(input);
}

/*
	�禡�\��: ���o��A���

	�Ѽ�: �L

	�^�ǭ�: ��A���
*/
int MallUI::GetClothCount()
{
    string input;
    cout << "�п�J��A�ƶq: ";
    getline(cin, input);
    return stoi(input);
}

/*
	�禡�\��: ��ܫȤH�P�ө�

	�Ѽ�: customerName => ��w���ȤH�W��, shopName => ��w���ө��W��

	�^�ǭ�: �L
*/
void MallUI::SelectCustomerAndShop(const string customerName, const string shopName) const
{
    //���o�Ҧ��ȤH���
    const vector<Customer*>* customers = _mall->GetCustomers();
    //���o�Ҧ��ө����
    const vector<Shop*>* shops = _mall->GetShops();
    size_t customerIndex, shopIndex;

    //�d��customerIndex
    for (size_t i = 0; i < customers->size(); i++)
    {
        if ((*customers)[i]->GetName() == customerName)
        {
            customerIndex = i;
            break;
        }
    }

    //�d��shopIndex
    for (size_t i = 0; i < shops->size(); i++)
    {
        if ((*shops)[i]->GetName() == shopName)
        {
            shopIndex = i;
            break;
        }
    }

    _mall->SelectCustomerAndShop(customerIndex, shopIndex);
}

/*
	�禡�\��: �P�_�O�_���Ʀr

	�Ѽ�: ��J���

	�^�ǭ�: True/False
*/
bool MallUI::IsNumber(string input)
{
    regex rule1("^-?[0-9]+$");
    regex rule2("^-?[0-9]+\\.[0-9]+$");

    if (regex_match(input, rule1) || regex_match(input, rule2))
        return true;

    return false;
}


/*
	�禡�\��: �P�_�O�_������

	�Ѽ�: ��J���

	�^�ǭ�: True/False
*/
bool MallUI::IsPositive(string input)
{
    if (stod(input) >= 0)
        return true;

    return false;
}