#include <iostream>

using namespace std;

// 풀이.
// 처음에는 누적합을 이용한 로직을 구현하려고 했으나 불가능했다. 
// 조금만 더 생각해보면 되는데 왼쪽, 오른쪽부터 각각 최대공약수를
// 구하는 방식으로 대체하면 된다. 그 이후 최대 N번을 순회하며 
// i를 제외한 즉, LToR[i - 1]과 RToL[i + 1]의 최대공약수를 구한후
// board[i]를 나눌 수 있는지 확인해가며 최대값을 찾는다.

// 자세한 설명은 주석으로 남긴다.

int N;
int board[1000000], LToR[1000000], RToL[1000000];

int GCD(int a, int b)
{
    if (b == 0)
        return a;
    return GCD(b, a % b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
    // 왼쪽부터 최대공약수 계산.
    LToR[0] = board[0];
    for (int i = 1; i < N; ++i)
        LToR[i] = GCD(LToR[i - 1], board[i]);
    // 오른쪽부터 최대공약수 계산.
    RToL[N - 1] = board[N - 1];
    for (int i = N - 2; i >= 0; --i)
        RToL[i] = GCD(RToL[i + 1], board[i]);
    // 맨 왼쪽 계산.
    int ans = board[0] % RToL[1] == 0 ? -1 : RToL[1];
    pair<int, int> answer = make_pair(ans, board[0]);
    // 맨 오른쪽 계산.
    ans = board[N - 1] % LToR[N - 2] == 0 ? -1 : LToR[N - 2];
    if (ans > answer.first)
        answer = make_pair(ans, N - 1);
    for (int i = 1; i < N - 2; ++i)
    {
        int g = GCD(LToR[i - 1], RToL[i + 1]);
        ans = board[i] % g == 0 ? -1 : g;
        if (ans > answer.first)
            answer = make_pair(ans, board[i]);
    }
    if (answer.first == -1)
        cout << answer.first << '\n';
    else
        cout << answer.first << ' ' << answer.second << '\n';
    return 0;
}