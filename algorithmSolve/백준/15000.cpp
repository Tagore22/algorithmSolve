#include <iostream>

using namespace std;

int main()
{
    string str;
    cin >> str;
    for (auto& c : str)
    {
        char cur = c - 32;
        cout << cur;
    }
    cout << '\n';
    return 0;
}