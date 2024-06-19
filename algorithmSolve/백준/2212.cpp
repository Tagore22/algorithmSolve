#include <iostream>
#include <algorithm>

using namespace std;

// 풀이.
// 처음에는 백트래킹을 이용해서 모든 경우를 다 해보려고 했다. 그런데 K의 수가 많아서 그런지 시간초과가 났다.
// 따라서 그리디같은 좀더 짧은 연산을 필요로 하는 알고리즘을 사용해야만 했다. 도무지 알수가 없었는데
// 한끗 차이로 빗나간것 같다. 모든 센서들의 위치를 내림차순으로 정렬하였을때 제대로 된 위치를 알수 있는데
// 이때 K개의 집중국을 세운다고 치자. K개의 집중국 사이에는 K - 1개의 공간이 생기는데 이 공간의 위치를
// 최고로 하는게 영역을 최소로 하는 방법이다. 이것이 아주 중요했다. 따라서 각 센서의 위치를 모두 구해서
// 내림차순으로 정렬하면 가장 큰 센서들의 거리가 구해진다. 이 거리들중 큰 것부터 K - 1개를 집중국 사이의
// 공간으로 하면 된다. 즉 모든 거리들을 더해서 가장 큰 K - 1개를 빼주면 그것이 답이 된다.

int N, K;
int board[10000], bet[10000];

void MakeAnswer()
{
    sort(board, board + N);
    int sum = 0;
    for (int i = 0; i < N - 1; ++i)
    {
        bet[i] = board[i + 1] - board[i];
        sum += bet[i];
    }
    sort(bet, bet + N - 1, greater<>());
    for (int i = 0; i < K - 1; ++i)
        sum -= bet[i];
    cout << sum << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}