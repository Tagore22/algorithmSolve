#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

// Ǯ��.
// ���� ������ �͵��� �ϳ��� float ������ ����ؾ� �Ѵ�.
// �ݿø��� floor(N)���� N�� 0.5�� �����ָ� ���� ���Ҽ� �ִ�.
// ����� ���� ���������� N�� 0�϶��� �����ؾ� �Ѵ�. �̸� ���ļ� ���� ��̴�.

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