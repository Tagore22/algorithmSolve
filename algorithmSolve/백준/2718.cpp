#include <iostream>

using namespace std;

// 풀이.
// 어렵다. 잘 모르겠다. 기존의 2 x N 타일은 매우 직관적이었다. 1이나 2칸을 제외하고 나면 나머지 오른쪽부분은
// 독립적이기 때문에 매우 할만했는데 4같은 경우는 그게 아니기 때문에 쉽지 않다. 아마도 N - 1 까지는 모두 
// 채웠다 생각하고 그 이후 나머지 경우의 수를 모두 구하는것 같다. 나중에 다시 풀어보자.

int dp[501][13];
int T;

int CalTile(int n, char bit)
{
    if (n < 0) return 0;
    if (n < 1) return bit == 0;
    int& r = dp[n][bit];
    if (r != -1) return r;

    r = 0;
    if (bit == 0) {
        r += CalTile(n - 1, 0);
        r += CalTile(n - 1, 3);
        r += CalTile(n - 1, 9);
        r += CalTile(n - 1, 12);
        r += CalTile(n - 2, 0);
    }
    if (bit == 3) {
        r += CalTile(n - 1, 0);
        r += CalTile(n - 1, 12);
    }
    if (bit == 6) {
        r += CalTile(n - 1, 9);
    }
    if (bit == 9) {
        r += CalTile(n - 1, 0);
        r += CalTile(n - 1, 6);
    }
    if (bit == 12) {
        r += CalTile(n - 1, 0);
        r += CalTile(n - 1, 3);
    }
    return r;
}

void MakeAnswer()
{
    for (int i = 0; i < 501; ++i)
        for (int j = 0; j < 13; ++j)
            dp[i][j] = -1;
    int num;
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> num;
        cout << CalTile(num, 0) << '\n';
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
    MakeAnswer();
    return 0;
}