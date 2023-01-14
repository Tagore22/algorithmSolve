#include <iostream>

using namespace std;

//Ǯ��
//�����¿� 4������ ���� �ִ� ��� ������ ����, ���ܿ� ���������� �Ÿ��� K�϶��� ������ answer�� ���� 1 ���Ѵ�.
//����, �ѹ��� �̵��� ���� ���� �Ǵٽ� ���� ���⿡ bool������ 2���� �迭�� �̹� �湮�� ���� �������־�� �Ѵ�.

string board[5];
bool check[5][5];
int tran[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };
int R, C, K, answer = 0;

void BackTrack(int y, int x, int num)
{
    if (y == 0 && x == C - 1 && num == K)
        ++answer;

    check[y][x] = true;

    for (int i = 0; i < 4; ++i)
    {
        int dy = y + tran[i][0];
        int dx = x + tran[i][1];

        if (dy < 0 || dy >= R || dx < 0 || dx >= C || check[dy][dx] || board[dy][dx] == 'T')
            continue;
        BackTrack(dy, dx, num + 1);
    }

    check[y][x] = false;
}

void MakeAnswer()
{
    BackTrack(R - 1, 0, 1);

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C >> K;
    for (int i = 0; i < R; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}