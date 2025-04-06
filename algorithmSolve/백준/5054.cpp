#include <iostream>
#include <algorithm>

using namespace std;

// 풀이.
// 복잡해보이지만 조금만 생각하면 간단한 문제다. 차에서 가까운 A와 좀 더 먼 B가 있을때 
// A로의 이동은 결국 B로의 이동에 포함된다. 따라서 이 문제에서도 가장 작은 수와 가장 큰
// 수로의 이동에 나머지 이동들은 포함되어 무시되기에 정렬하여 가장 작은 수와 가장 큰 수의
// 중간에 차를 두고 그 이동거리를 계산하면 된다.

int board[100];
int T, N;

void MakeAnswer()
{
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> N;
        for (int i = 0; i < N; ++i)
            cin >> board[i];
        sort(board, board + N);
        int mid = (board[0] + board[N - 1]) / 2;
        int answer = (mid - board[0]) * 2 + (board[N - 1] - mid) * 2;
        cout << answer << '\n';
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