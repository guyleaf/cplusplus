#include <iostream>
#include "Student.h"
#include "ScienceStudent.h"

using std::cout;
using std::endl;

int main()
{
    Student student1("Michael", "107598042", "Male", "NTU");
    cout << student1 << endl;
    ScienceStudent scienceStudent("Mary", "107598041", "Female", "NTUT", "CS");
    cout << scienceStudent << endl;
    system("PAUSE");
    return 0;
}