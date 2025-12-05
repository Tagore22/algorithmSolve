#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int num;
    string str;
    cin >> num >> str;

    int sum = 0, bonus = 0;
    for (int i = 0; i < num; ++i)
    {
        if (str[i] == 'O')
        {
            sum += i + 1 + bonus;
            ++bonus;
        }
        else
        {
            bonus = 0;
        }
    }
    cout << sum << '\n';
    return 0;
}