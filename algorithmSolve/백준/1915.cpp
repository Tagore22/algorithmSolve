#include <iostream>

using namespace std;

int board[1001][1001];
int N, M;

//�������� �־����� N�� M�� ������ 1���� 1000�ε� �迭�� ũ�⸦ N�� M�� ������ ������
//N�� M�� 1�϶����� ����� �Ҽ��� ���⿡ ���� ������ ũ�⸦ ������ 1�� �÷����Ѵ�.
//�� �κ��� ������ ���� ���� �ɷȴ�. �Ф�...
//������ �� �� ����.

void MakeAnswer()
{
    int answer = 0;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            if (board[i][j] != 0)
            {
                board[i][j] = min(board[i - 1][j - 1], min(board[i - 1][j], board[i][j - 1])) + 1;
                answer = max(answer, board[i][j]);
            }
    cout << answer * answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
    {
        string str;
        cin >> str;
        for (int j = 0; j < M; ++j)
            board[i][j + 1] = str[j] - '0';
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}