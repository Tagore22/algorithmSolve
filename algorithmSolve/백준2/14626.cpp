#include <iostream>

using namespace std;

int main()
{
    string str;
    cin >> str;
    int sum = 0, idx = 0;
    for (int i = 0; i < 13; ++i)
    {
        if (str[i] == '*')
        {
            idx = i;
            continue;
        }
        int cur = str[i] - '0';
        sum += i % 2 != 0 ? cur * 3 : cur;
    }
    for (int i = 0; i < 10; ++i)
    {
        int cur = idx % 2 != 0 ? i * 3 : i;
        if ((sum + cur) % 10 == 0)
        {
            cout << i << '\n';
            break;
        }
    }
    return 0;
}