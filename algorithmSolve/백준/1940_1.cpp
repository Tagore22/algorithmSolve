#include <iostream>
#include <algorithm>

using namespace std;

// 기존의 1940번 풀이가 너무 오래 걸려서 다시 찾아보니
// 투포인터 문제였다. 정렬하여 두 원소의 합에 따라 시작점이나 끝점을 이동시켜
// 합이 M인 쌍의 수를 더 빠르게 알수 있다.

// 자세한 설명은 주석으로 남긴다.

int board[15000];
int N, M;

void MakeAnswer()
{
    // 투포인터 알고리즘을 위한 정렬.
    sort(board, board + N);
    // 각각 시작점과 끝점을 초기화한다.
    int answer = 0, from = 0, to = N - 1;
    // 모든 원소값은 고유하기에 같은 두 값을 더해서 M을 만들수 없다.
    // 따라서 from과 to는 같은 곳에 존재할수 없다.
    while (from < to)
    {
        // 두점의 합이 M보다 작다면 크기를 올려야하기에 from을 오른쪽으로 이동한다.
        if (board[from] + board[to] < M)
        {
            ++from;
        }
        // 두점의 합이 M보다 크다면 크기를 줄여야하기에 to을 왼쪽으로 이동한다.
        else if (board[from] + board[to] > M)
        {
            --to;
        }
        // 두점의 합이 M이라면 두점은 모두 더이상 사용할수 없기에 from과 to를 각각 오른쪽, 왼쪽으로 이동시키고
        // 최종답 answer를 1 증가시킨다.
        else
        {
            ++from;
            --to;
            ++answer;
        }
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}