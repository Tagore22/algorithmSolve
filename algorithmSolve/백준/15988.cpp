#include <iostream>
#include <vector>

using namespace std;

vector<int> cashe(1000001, -1);
const int DIVNUM = 1000000009;

int Calcul(int now, bool IsFirst) //처음 호출시 IsFirst는 1
{
    if (now == 0 && !IsFirst)
        return 1;

    int& ans = cashe[now];
    if (ans != -1)
        return ans;
    ans = 0;
    for (int i = 1; i <= 3; ++i)
        if (now > i || (now == i && !IsFirst))
        {
            ans += Calcul(now - i, false) % DIVNUM;
            ans %= DIVNUM;
        }
    return ans % DIVNUM;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        int n;
        cin >> n;
        cout << Calcul(n, false) << '\n';
    }
    return 0;
}