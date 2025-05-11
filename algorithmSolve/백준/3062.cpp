#include <iostream>
#include <string>

using namespace std;

int T;

bool IsSymmetry(int num)
{
    int before = num, after = 0;
    while (num > 0)
    {
        after = (after * 10) + (num % 10);
        num /= 10;
    }
    string test = to_string(before + after);
    int tsize = test.size();
    for (int i = 0; i < tsize / 2; ++i)
        if (test[i] != test[tsize - i - 1])
            return false;
    return true;
}

void Solve()
{
    for (int iter = 0; iter < T; ++iter)
    {
        int num;
        cin >> num;
        if (IsSymmetry(num))
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

int main()
{
    Input();
    Solve();
    return 0;
}