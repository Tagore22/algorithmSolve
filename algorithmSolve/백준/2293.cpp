#include <iostream>

using namespace std;

int n, k;
int board[100];
int cashe[10001];

void calcul()
{
    cashe[0] = 1;
    for (int i = 0; i < n; ++i)
        for (int j = board[i]; j <= k; ++j)
            cashe[j] += cashe[j - board[i]];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> board[i];
    calcul();
    cout << cashe[k] << '\n';
    return 0;
}