#include <iostream>

using namespace std;

//Ǯ��
//�׸���� �����ϱ� �ָ��� ����Ž���� �Ͽ���. �� �״�� �־��� �Է°����� string �迭�� 2�������� �����Ͽ�
//���������� �ѹ�, ���������� �ѹ��� ��ȸ�ϸ� �ѹ��� ������ �ִ� ������ ���� ������ ������, �������� ����Ѵ�.

string board[50];
int answer = 1;
int N;

void CalMax()
{
    int check;
    for (int i = 0; i < N; ++i)
    {
        check = 1;
        for (int j = 0; j < N - 1; ++j)
        {
            if (board[i][j] == board[i][j + 1])
            {
                ++check;
            }
            else
            {
                answer = max(answer, check);
                check = 1;
            }
        }
        answer = max(answer, check);
    }

    for (int j = 0; j < N; ++j)
    {
        check = 1;
        for (int i = 0; i < N - 1; ++i)
        {
            if (board[i][j] == board[i + 1][j])
            {
                ++check;
            }
            else
            {
                answer = max(answer, check);
                check = 1;
            }
        }
        answer = max(answer, check);
    }
}

void MakeAnswer()
{
    CalMax();

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N - 1; ++j)
            if (board[i][j] != board[i][j + 1])
            {
                swap(board[i][j], board[i][j + 1]);
                CalMax();
                swap(board[i][j], board[i][j + 1]);
            }

    for (int j = 0; j < N; ++j)
        for (int i = 0; i < N - 1; ++i)
            if (board[i][j] != board[i + 1][j])
            {
                swap(board[i][j], board[i + 1][j]);
                CalMax();
                swap(board[i][j], board[i + 1][j]);
            }

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

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