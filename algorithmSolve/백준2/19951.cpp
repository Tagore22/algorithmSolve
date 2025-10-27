#include <iostream>

using namespace std;

// 풀이.
// 차등 배열 트릭이라는 알고리즘을 사용해야하는 문제였다. 처음 보는 알고리즘인데
// 설명하자면 세그먼트 트리와 비슷하다. 차이점이 있다면 세그먼트 트리는 업데이트와
// 출력이 빈번하지만 차등 배열 트릭은 출력이 맨 마지막에 단 한번뿐이라는 점이다.
// 로직이나 구현 자체는 전혀 어렵지 않으나 낯설다.

// 자세한 설명은 주석으로 남긴다.

int N, M;
int board[100001], diff[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
        cin >> board[i];
    for (int i = 0; i < M; ++i)
    {
        int from, to, k;
        cin >> from >> to >> k;
        diff[from] += k;
        diff[to + 1] -= k;
    }
    for (int i = 1; i <= N; ++i)
    {
        diff[i] += diff[i - 1];
        board[i] += diff[i];
        cout << board[i] << ' ';
    }
    return 0;
}