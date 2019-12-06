#include <string>
#include <iostream>
using namespace std;
class Test
{
public:
    Test(): s("")
    {
        cout << "default constructor" << endl;
    }
    /*Test(string& s) : s(s)
    {
        cout << "copy constructor" << endl;
    }*/
    Test(string s) : s(s)
    {
        cout << "default constructor s" << endl;
    }
    Test do1(int t)
    {
        Test t2 = Test("");
        return t2;
    }
private:
    string s;
};

int main()
{
    Test t;
    t = t.do1(5);
    Test t1(t);
    system("PAUSE");
    return 0;
}