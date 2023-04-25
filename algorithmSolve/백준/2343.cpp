#include <iostream>

using namespace std;

// Ǯ��.
// �̺� Ž������ �ִ밪�� 0 ~ 10��1������ ���� Ž���ϸ�
// ������ ��緹���� ������ �ּҰ��� ����ϸ� �ȴ�.

int board[100000];
int N, M;

bool CheckMin(int sum)
{
    int num = 1, cur = 0;

    for (int i = 0; i < N; ++i)
    {
        if (board[i] > sum)
            return false;

        if (cur + board[i] > sum)
        {
            ++num;
            cur = board[i];
        }
        else
        {
            cur += board[i];
        }
    }

    return num <= M;
}

void Binary()
{
    int from = 0, to = 1000000001, mid;

    for (int i = 0; i < 100; ++i)
    {
        mid = (from + to) / 2;

        if (CheckMin(mid))
            to = mid;
        else
            from = mid;
    }

    cout << to << '\n';
}

void MakeAnswer()
{
    Binary();
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