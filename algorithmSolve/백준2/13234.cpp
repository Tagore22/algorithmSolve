#include <iostream>

using namespace std;

int main()
{
    string str1, str2, oper;
    cin >> str1 >> oper >> str2;

    if (str1 == str2)
    {
        cout << str1 << '\n';
    }
    else
    {
        if (oper == "AND")
            cout << "false" << '\n';
        else
            cout << "true" << '\n';
    }
    return 0;
}