#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    if (str.substr(0, 3) == "555")
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';

    return 0;
}