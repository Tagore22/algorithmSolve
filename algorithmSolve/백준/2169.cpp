#include <iostream>
#include <cstring>

using namespace std;

bool check[1000][1000];
int cashe[1000][1000][3];
int board[1000][1000];
int N, M;
int dy[3] = { 0,1,0 };
int dx[3] = { -1,0,1 };
const int MINNUM = -987654321;

//ó������ �������� �κп��� �湮���θ� �������ָ� ���� ĳ���� [][][]���� ���ص� �ɰŶ�� ����������,
//�ٽ� �����غ��� DP�� ���� ��� ��ǥ y,x������ ĳ�ð��� ��� ���� ���� ���Ѵ�.
//�װ��� ����, ������, ���ʿ��� ���������� ���̴�. �㳪 �� ���� ��� �޶���ϴµ� 
//�ֳ��ϸ� ���� ��� �����ʿ��� �������������� �������� �ƴ� �Ʒ���, �������� �̵��� ���� �־���ϴµ�
//���ʿ��� �����ص� ����, �Ʒ����� ū���� ���ϱ⿡ �������� ���� �ȵǱ� �����̴�.

int DP(int y, int x, int dir)
{
    if (y == N - 1 && x == M - 1)
        return board[y][x];
    int& ans = cashe[y][x][dir];
    if (ans != MINNUM)
        return ans;
    for (int i = 0; i < 3; ++i)
    {
        int cy = y + dy[i];
        int cx = x + dx[i];

        if (cy >= N || cx >= M || cy < 0 || cx < 0 || check[cy][cx])
            continue;

        check[cy][cx] = true; //������������������������
        ans = max(ans, DP(cy, cx, i) + board[y][x]);
        check[cy][cx] = false;
    }
    return ans;
}

void MakeAnswer()
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
        {
            cashe[i][j][0] = MINNUM;
            cashe[i][j][1] = MINNUM;
            cashe[i][j][2] = MINNUM;
        }
    check[0][0] = true;
    cout << DP(0, 0, 0) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(check, 0, sizeof(check));

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}