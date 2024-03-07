#include <iostream>

using namespace std;

// Ǯ��.
// char �迭�� ��������ν� bool �迭�� ��ü�Ҽ� �־��� �׿� ���� �ϳ��� for���� ���ϼ��� �־���.
// cin >> ���� ���ڿ��� �Է¹޴� ���� ���� string�̾��� ������ char �迭�� cin >> ���� �ѹ��� �Է¹�����
// �ִٴ°��� ��� ó�� �˾Ҵ�. �λ��� ����� �����̸���.

char board[20002];
int N, K;

void MakeAnswer()
{
    int answer = 0;
    for (int i = 0; i < N; ++i)
    {
        if (board[i] != 'P')
            continue;
        for (int j = i - K; j <= i + K; ++j)
        {
            if (j < 0 || j >= N || board[j] != 'H')
                continue;
            ++answer;
            board[j] = 'F';
            break;
        }
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K >> board;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}