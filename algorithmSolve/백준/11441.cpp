#include <iostream>

using namespace std;

// 풀이.
// from번째 원소부터 to번째 원소까지의 합을 출력하는 누적합 문제다.
// to까지의 누적합 - from - 1까지의 누적합이 그 점화식이다.
// 누적합의 원리를 이해하고 있다면 어렵지 않은 문제였다.

// 자세한 설명은 주석으로 남긴다.

// 누적합을 저장해두는 int 배열.
int board[100001];
int N, M;

void MakeAnswer()
{
    int from, to;
    for (int iter = 0; iter < M; ++iter)
    {
        cin >> from >> to;

        // to까지의 누적합 - from - 1까지의 누적합을 빼고 출력한다.
        cout << board[to] - board[from - 1] << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    int num, cur = 0;
    // 1번부터 N번 원소까지의 누적합을 미리 구해놓는다.
    for (int i = 1; i <= N; ++i)
    {
        cin >> num;
        cur += num;
        board[i] = cur;
    }
    cin >> M;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}