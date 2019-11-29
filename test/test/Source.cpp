#include <string>
#include <iostream>
using namespace std;
class Exam
{
public:
    Exam() : s("") {};
    Exam(int s) : s(to_string(s)) {};
    Exam(string s) : s(s) {};
    const Exam operator++(int flag)
    {
        string t = s;
        s += "+";
        return t;
    }
private:
    string s;
};

int main()
{
    Exam t(11);
    
    return 0;
}