#include <iostream>

using namespace std;

// 풀이.
// 오랜만에 플로이드 워셜 알고리즘을 이용한 문제였다. 정리해야할 부분은 다음과 같다.

// 1. 어떤 지점에서 다른 지점으로의 최소거리(가중치)를 알아야 하는데 이것이 여러번 반복되므로
// 플로이드 워셜 알고리즘을 사용해야한다.
// 2. 플로이드 워셜 알고리즘에서 직접적으로 연결되지 않은 경로는 엄청 큰 수로, A -> A 등
// 나 자신으로의 이동은 0으로 초기화를 해야하는데 문제의 난이도가 낮아서인지 입력에서
// 전부 처리해주기 때문에 신경쓸 필요가 없다.

// 따라서, 각 거리들을 입력받아 최소거리를 찾은 후에 다시 입력을 받아 주어진 시간보다
// 짧거나 같은지만 확인하면 된다.

// 자세한 설명은 주석으로 남긴다.

int board[501][501];
int N, M;

// 플로이드 워셜 알고리즘을 구현하는 함수.
void Floyd()
{
    // 상술한대로 A -> A = 0 등의 처리는 신경쓰지 않아도 된다.
    for (int k = 1; k <= N; ++k)
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j)
                board[i][j] = min(board[i][j], board[i][k] + board[k][j]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            cin >> board[i][j];

    Floyd();

    int from, to, cost;
    for (int i = 0; i < M; ++i)
    {
        cin >> from >> to >> cost;
        if (cost >= board[from][to])
            cout << "Enjoy other party" << '\n';
        else
            cout << "Stay here" << '\n';
    }
    return 0;
}