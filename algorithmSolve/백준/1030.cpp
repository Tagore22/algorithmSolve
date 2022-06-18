#include <iostream>
#include <cmath>

using namespace std; // 정점의 번호는 0번부터 n-1번까지

int s, N, K, R1, R2, C1, C2; //R,C 모두 시작점은 0이다.

bool IsBlack(int time, int y, int x)
{
    if (time == 0)
        return false;

    int NowN = pow(N, time);
    int NowK = NowN / N * K;
    int start = (NowN - NowK) / 2;
    int end = start + NowK - 1;
    if ((start <= y && y <= end) && (start <= x && x <= end))
        return true;
    int PrevN = NowN / N;
    y %= PrevN;
    x %= PrevN;
    return IsBlack(time - 1, y, x);
}

void ShowAnswer()
{
    for (int i = R1; i <= R2; ++i)
    {
        for (int j = C1; j <= C2; ++j)
        {
            if (IsBlack(s, i, j))
                cout << 1;
            else
                cout << 0;
        }
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s >> N >> K >> R1 >> R2 >> C1 >> C2;
    if (s == 0)
        cout << 0 << '\n';
    else
        ShowAnswer();
    return 0;
}