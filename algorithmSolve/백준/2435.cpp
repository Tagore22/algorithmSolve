#include <iostream>

using namespace std;

// Ǯ��.
// K���� ���ӵ� �յ��� ���س����� �Ź� �ִ밪�� �����ϸ� �ȴ�.

int board[100];
int N, K;

void MakeAnswer()
{
    int sum = 0;
    for (int i = 0; i < K; ++i)
        sum += board[i];
    int answer = sum;
    for (int i = K; i < N; ++i)
    {
        sum -= board[i - K];
        sum += board[i];
        answer = max(answer, sum);
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

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