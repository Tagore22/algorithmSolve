#include <iostream>

using namespace std;

//Ǯ��
//������ board�� �ٲ�°� check�� ���ذ��� ��ȸ�� �ϵ�, �� �񱳴� ���纸�� 1ĭ �»�ܰ� [i-1][j-1]�� ���Ͽ� �ٸ� ���
//�����´�. �»���� ������ ������ ������ ���Ŀ� �ٲ� ���ɼ��� �ֱ⿡ ���� �ٲپ���� �ҿ��̾��� �����̴�.
//�� ��, �ٽ� board�� check�� ���Ͽ� ��ȭ�� ��ģ ���ݵ� �ٸ� �κ��� �ִٸ� -1�� ����Ѵ�.

int board[50][50], check[50][50];
int N, M;

void MakeAnswer()
{
    int answer = 0;
    for (int i = 1; i < N - 1; ++i)
        for (int j = 1; j < M - 1; ++j)
            if (board[i - 1][j - 1] != check[i - 1][j - 1])
            {
                for (int a = i - 1; a <= i + 1; ++a)
                    for (int b = j - 1; b <= j + 1; ++b)
                        board[a][b] ^= 1;
                ++answer;
            }

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (board[i][j] != check[i][j])
            {
                cout << -1 << '\n';
                return;
            }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    string str;
    for (int i = 0; i < N; ++i)
    {
        cin >> str;
        for (int j = 0; j < M; ++j)
            board[i][j] = str[j] - '0';
    }

    for (int i = 0; i < N; ++i)
    {
        cin >> str;
        for (int j = 0; j < M; ++j)
            check[i][j] = str[j] - '0';
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}