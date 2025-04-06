#include <iostream>
#include <algorithm>

using namespace std;

// Ǯ��.
// �����غ������� ���ݸ� �����ϸ� ������ ������. ������ ����� A�� �� �� �� B�� ������ 
// A���� �̵��� �ᱹ B���� �̵��� ���Եȴ�. ���� �� ���������� ���� ���� ���� ���� ū
// ������ �̵��� ������ �̵����� ���ԵǾ� ���õǱ⿡ �����Ͽ� ���� ���� ���� ���� ū ����
// �߰��� ���� �ΰ� �� �̵��Ÿ��� ����ϸ� �ȴ�.

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