#include <iostream>
#include <cstring>

using namespace std;

const int MAXNUM = 500;
int cashe[5][MAXNUM][MAXNUM];
int board[MAXNUM][MAXNUM];
int N;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,-1,0,1 };
int answer = 0;

//���������� �˼� ���⿡ ��� �������� DFS�� �����ؾ��ϴµ� �̷��� 500�� 4�����ؾ� �ϱ⿡ ���� �ð����� Ǯ������.
//�����غ��� ��� ������ ��,��,��,�� 4�����ιۿ� �������̴µ� � ���� A�� ���ʿ��� �����ϴ� ����� �������� ����
//��� �Ȱ��� ���ʿ��� �ѹ� �����̹Ƿ� ĳ���Ҽ� �ִ�. �����̴� ����� 4�����̹Ƿ� 4���� �迭�� �ʿ��ϸ�
//�������� ��Ⱑ �ָ��߱⿡ �ƹ��͵� ���� 0�� �߰��� �� 5���� �迭�� ĳ���ϸ� �ȴ�.
//ex) 1,1���� 1,2�� �̵��ϴ°� ��ĭ �̵��ϴ� ���̸� �� �������� 2,0�̵� 3,0�̵� ������ �� �ѹ��� �̵��̴�.

int DFS(int prev, int y, int x)
{
    int& ans = cashe[prev][y][x];
    if (ans != -1)
        return ans;
    ans = 1;
    for (int i = 0; i < 4; ++i)
    {
        int cy = y + dy[i];
        int cx = x + dx[i];

        if (cy >= N || cx >= N || cy < 0 || cx < 0 || board[cy][cx] <= board[y][x])
            continue;

        ans = max(ans, DFS(i + 1, cy, cx) + 1);
    }
    return ans;
}

void MakeAnswer()
{
    int answer = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            answer = max(answer, DFS(0, i, j));
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(cashe, -1, sizeof(cashe));

    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}