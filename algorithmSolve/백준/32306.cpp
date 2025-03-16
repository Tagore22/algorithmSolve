#include <iostream>

using namespace std;

int main()
{
    int team1 = 0;
    for (int i = 1; i <= 3; ++i)
    {
        int num;
        cin >> num;
        team1 += i * num;
    }
    int team2 = 0;
    for (int i = 1; i <= 3; ++i)
    {
        int num;
        cin >> num;
        team2 += i * num;
    }
    if (team1 > team2)
        cout << 1 << '\n';
    else if (team1 < team2)
        cout << 2 << '\n';
    else
        cout << 0 << '\n';
    return 0;
}