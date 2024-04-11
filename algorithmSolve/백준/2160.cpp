#include <iostream>

using namespace std;

// Ǯ��. 
// �ܼ� �ִ� 50���� 2���� �迭�� ���ϴ� ����. �ٸ� for���� ������ ���� ������.
// �׷��� ����� �ʴ�.

char board[51][5][7];
int N;

void MakeAnswer()
{
    int min_diff = 36;
    pair<int, int> answer = make_pair(-1, -1);
    for (int i = 1; i < N; ++i)
    {
        for (int j = i + 1; j <= N; ++j)
        {
            int diff = 0;
            for (int k = 0; k < 5; ++k)
            {
                for (int z = 0; z < 7; ++z)
                {
                    if (board[i][k][z] != board[j][k][z])
                        ++diff;
                }
            }
            if (diff < min_diff)
            {
                min_diff = diff;
                answer = make_pair(i, j);
            }
        }
    }
    cout << answer.first << ' ' << answer.second << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i)
        for (int j = 0; j < 5; ++j)
            for (int k = 0; k < 7; ++k)
                cin >> board[i][j][k];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}