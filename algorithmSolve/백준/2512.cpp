#include <iostream>

using namespace std;

// Ǯ��.
// ���� ��ü�� ����� �ʴ�. 2�� �ݺ������� ���� ū ������ 1�� �����ذ���
// ������ �� M�ȿ��� ��ο��� �ټ� �ִ� ���� ū ���ذ��� ����س��� �ȴ�.
// �ٸ� �� Ǯ�̴� �ִ� 10���� ���귮�� ���ϱ� ������ �ſ� ������.

// �ڼ��� ������ �ּ����� �����.

int board[10000];
int N, M, cur;

void MakeAnswer()
{
    int answer;
    // ���ذ� cur�� �ִ� ���Ұ����� �����ؼ� 1�� �����ذ��� �ټ� �ִ� �ִ밪�� ���Ѵ�.
    while (cur > 0)
    {
        answer = 0;
        for (int i = 0; i < N; ++i)
        {
            answer += board[i] > cur ? cur : board[i];
            if (answer > M)
            {
                answer = 0;
                --cur;
                break;
            }
        }
        if (answer != 0)
        {
            cout << cur << '\n';
            return;
        }
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> board[i];
        cur = max(cur, board[i]);
    }
    cin >> M;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}