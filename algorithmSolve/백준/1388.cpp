#include <iostream>

using namespace std;

//Ǯ��
//��� �迭�� ��ȸ�ϸ� �� ���Ұ� '-'�϶����� �������� '-'�̶�� �ϳ��� ���ڷ� �����ϱ⿡ ���ڰ� 1�� ������,
//�� ���Ұ� '|'�϶����� �Ʒ����� '|'�̶�� ���������� �ϳ��� ���ڷ� �����ϱ⿡ 1���� ������.
//�̷� ������� answer�� �ʱⰪ�� N * M���� ���� �迭�� ��ȸ�Ͽ� ���� answer���� ����ϸ� �ȴ�.

//P.S �˰��� �з��� ���� DFS, BFS�ε� �װɷε� �ǳ�����.

string board[50];
int N, M;

void MakeAnswer()
{
    int answer = N * M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
        {
            if (board[i][j] == '-' && j != M - 1)
            {
                if (board[i][j + 1] == '-')
                    --answer;
            }
            else if (board[i][j] == '|' && i != N - 1)
            {
                if (board[i + 1][j] == '|')
                    --answer;
            }
        }
    cout << answer << '\n';
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