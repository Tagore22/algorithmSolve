#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

// 풀이.
// 제일 귀찮은 것들중 하나인 float 연산을 사용해야 한다.
// 반올림은 floor(N)에서 N에 0.5를 더해주면 쉽게 구할수 있다.
// 어렵지 않은 문제이지만 N이 0일때를 주의해야 한다. 이를 놓쳐서 조금 헤맸다.

int board[300000];
int N;

void MakeAnswer()
{
    if (N == 0)
    {
        cout << 0 << '\n';
        return;
    }
    int idx = floor(N * 0.15f + 0.5f);
    sort(board, board + N);
    int sum = 0;
    for (int i = idx; i < N - idx; ++i)
        sum += board[i];
    cout << floor(static_cast<float>(sum) / (N - idx * 2) + 0.5f) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}