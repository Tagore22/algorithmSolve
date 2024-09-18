#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    int first = 0;
    for (int i = 0; i < str.size() / 2; ++i)
        first += stoi(str.substr(i, 1));
    int second = 0;
    for (int i = str.size() / 2; i < str.size(); ++i)
        second += stoi(str.substr(i, 1));
    if (first == second)
        cout << "LUCKY" << '\n';
    else
        cout << "READY" << '\n';
    return 0;
}