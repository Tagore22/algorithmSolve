#include <iostream>

using namespace std;

// Ǯ��.
// �� �л��� ������ �г��� �־����� �׸�ŭ�� �����Ҽ� �ִ� 2���� �迭�� �����س��´�.
// ������ ��� ���� ���� �ٽ� ��� �迭���� ��ȸ�ϸ� �� �л����� �ʿ��� ���� ���ϴµ�
// �� �迭���� ���Ұ��� K�� ������ ���� �������� �����Ѵٸ� 1���� ���� �� �߰��Ѵ�.

int board[2][7];
int N, K;

void MakeAnswer()
{
    int answer = 0;
    for (int i = 0; i < 2; ++i)
        for (int j = 1; j <= 6; ++j)
        {
            answer += board[i][j] / K;
            answer = board[i][j] % K == 0 ? answer : answer + 1;
        }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    int s, g;
    for (int i = 0; i < N; ++i)
    {
        cin >> s >> g;
        ++board[s][g];
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}