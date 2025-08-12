#include <iostream>

using namespace std;

// Ǯ��.
// ó������ ���� for���� ����ϴ� �����ۿ� ������ �ȳ����� �ƹ��� ���� �ִ� 50����
// �Ѿ�� ���귮�� �ʿ�� �ϱ⿡ �Ұ����ߴ�. �� �����غ��� ������ board[1] * board[2]
// ~ board[1] * board[N - 1]�ε� �̰��� ������ ������ ���� board[2] + ... board[N - 1]
// * board[1]�� �ٲ� �� �ִ�. �̰��� ���� �հ� ��ġ�ϱ⿡ ������ �ϸ� �ȴ�.

int N;
int board[100000];
long long sum = 0;

void Solve()
{
    long long answer = 0;
    for (int i = 0; i < N - 1; ++i)
    {
        sum -= board[i];
        answer += sum * board[i];
    }

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> board[i];
        sum += board[i];
    }
}

int main()
{
    Input();
    Solve();
    return 0;
}