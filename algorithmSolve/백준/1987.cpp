#include <iostream>
#include <cstring>

using namespace std;

//Ǯ��
//��Ʈ��ŷ �����̴�. �ٸ�, �ѹ��� ���ư��� �̹� �湮�ߴ� ���� �������� bool������ üũ������ �̹� ������ �ѹ� �湮�� ���ĺ���
//�Ǵٽ� �湮�Ҽ� ���ٴ� ������ �پ ���� bool���� �� �ʿ䰡 �����⿡ �湮�� ���ĺ��� ����ϴ� int�� �迭�� ����Ͽ���.
//�ѹ��� ���ư��� �湮�ߴ� ���ĺ��� ����ϰ� ���ư����� ĭ�� �̹� �湮�� ���ĺ��̶�� ���ư��� �ʴ´�.
//�� �̵��� �ִ밪�� ��ȯ�Ͽ� �ʱ�ĭ�� ���� 1�� ���� ����Ѵ�.

char board[20][20];
int alpha[26];
int tran[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
int R, C;

int DFS(int y, int x)
{
    int move = 0;
    alpha[board[y][x] - 'A'] = 1;

    for (int i = 0; i < 4; ++i)
    {
        int dy = y + tran[i][0];
        int dx = x + tran[i][1];

        if (dy < 0 || dy >= R || dx < 0 || dx >= C || alpha[board[dy][dx] - 'A'] != 0)
            continue;

        move = max(move, DFS(dy, dx) + 1);
    }
    alpha[board[y][x] - 'A'] = 0;
    return move;
}

void MakeAnswer()
{
    cout << DFS(0, 0) + 1 << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(alpha, 0, sizeof(alpha));

    cin >> R >> C;
    string str;
    for (int i = 0; i < R; ++i)
    {
        cin >> str;
        for (int j = 0; j < C; ++j)
            board[i][j] = str[j];
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}