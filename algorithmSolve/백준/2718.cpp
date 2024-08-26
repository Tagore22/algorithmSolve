#include <iostream>

using namespace std;

// Ǯ��.
// ��ƴ�. �� �𸣰ڴ�. ������ 2 x N Ÿ���� �ſ� �������̾���. 1�̳� 2ĭ�� �����ϰ� ���� ������ �����ʺκ���
// �������̱� ������ �ſ� �Ҹ��ߴµ� 4���� ���� �װ� �ƴϱ� ������ ���� �ʴ�. �Ƹ��� N - 1 ������ ��� 
// ä���� �����ϰ� �� ���� ������ ����� ���� ��� ���ϴ°� ����. ���߿� �ٽ� Ǯ���.

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