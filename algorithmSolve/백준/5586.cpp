#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str;
    cin >> str;

    int first = 0, second = 0;
    for (int i = 0; i < str.size() - 2; ++i)
    {
        string cur = str.substr(i, 3);
        if (cur == "JOI")
            ++first;
        else if (cur == "IOI")
            ++second;
    }
    cout << first << '\n';
    cout << second << '\n';
    return 0;
}