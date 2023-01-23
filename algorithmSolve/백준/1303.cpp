#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

//Ǯ��
//2���� �迭�� ��ȸ�ϸ� DFS�� ȣ���ϵ�, ���� ���ڳ����� �̵� �����ϴٴ� ���� �����Ұ�. ����, �Ʊ��� ���� ��� ���ؼ� �����ϴ°� �ƴ�
//���Ҷ����� �����ؼ� ���ؾ� �Ѵٴ� �͵� ������ �ȵȴ�.

char board[100][100];
int tran[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
bool check[100][100];
int N, M;

int DFS(int y, int x, char c)
{
    int num = 1;
    check[y][x] = true;
    for (int i = 0; i < 4; ++i)
    {
        int dy = y + tran[i][0];
        int dx = x + tran[i][1];

        if (dy < 0 || dy >= M || dx < 0 || dx >= N || check[dy][dx] || board[dy][dx] != c)
            continue;

        num += DFS(dy, dx, c);
    }

    return num;
}

void MakeAnswer()
{
    int our = 0, enemy = 0;
    for (int i = 0; i < M; ++i)
        for (int j = 0; j < N; ++j)
            if (!check[i][j])
            {
                int cur = DFS(i, j, board[i][j]);
                if (board[i][j] == 'W')
                    our += pow(cur, 2);
                else
                    enemy += pow(cur, 2);
            }
    cout << our << ' ' << enemy << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(check, false, sizeof(check));

    cin >> N >> M;
    string str;
    for (int i = 0; i < M; ++i)
    {
        cin >> str;
        for (int j = 0; j < N; ++j)
            board[i][j] = str[j];
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}