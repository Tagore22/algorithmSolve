#include <iostream>

using namespace std;


// 풀이
// 처음에는 그리디로 풀수 있을줄 알았다. N개의 카드팩이 있을때 1개를 살때 드는 비용이 높은 순으로 정렬하여 앞에서부터 살수 있는 개수를
// 사가며 for문을 순회하면 될줄 알았는데 다음과 같은 반례에 막혔다.

// N = 5, 1 6 8 12 10

// 이 반례를 보고 깨달은건 무조건 1개를 살때 드는 비용이 높은 카드팩이 우선순위가 아닌것이었다. 이러면 내가 생각했던 로직이 다 뭉개지는데 크흠;
// 그래서 DP를 이용하여 다시 풀었는데 1개일때 최고 비용은 무조건 1개를 살때뿐이고 그 이후로는 합쳐서 K개를 사는 카드팩들의 DP값을 모두 확인해보면
// 되었다.

int board[10001], DP[10001];
int N;

void MakeAnswer()
{
    // 1개를 사는 경우는 한가지이기에 DP[1]은 무조건 board[1]이다.
    DP[1] = board[1];

    // 그 이후부턴 합쳐서 현재값 K가 되는 모든 경우를 확인해본다.
    for (int i = 2; i <= N; ++i)
    {
        DP[i] = board[i];
        for (int j = 1; j <= i / 2; ++j)
            DP[i] = max(DP[i], DP[j] + DP[i - j]);
    }

    cout << DP[N] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    int cost;
    for (int i = 1; i <= N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}