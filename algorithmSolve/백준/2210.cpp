#include <iostream>
#include <set>
#include <string>

using namespace std;

//Ǯ��
//��� ĭ�� ��ȸ�ϸ� ����� �ִ� ��� 6�ڸ� ���� ���Ѵ�. �ٸ� �ߺ��� ���ؾ��ϱ⿡ set�� ���� �Է��Ͽ� ���� ���� 6�ڸ����� �̹� �����ϴ��� Ȯ��
//�ϸ� �����Ѵ�. ���� ��ȸ�� ������ set�ȿ� �����ϴ� ���� �ٸ� ���� ��, size�� ����Ѵ�. 

set<string> check;
int board[5][5];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { -1, 0, 1, 0 };

void DFS(int y, int x, string str)
{
    if (str.size() == 6) //����� ���� 6�ڸ�
    {
        if (check.find(str) == check.end())
            check.insert(str);
        return;
    }

    for (int i = 0; i < 4; ++i)
    {
        int cy = y + dy[i];
        int cx = x + dx[i];

        if (cy < 0 || cy >= 5 || cx < 0 || cx >= 5)
            continue;

        DFS(cy, cx, str + to_string(board[cy][cx]));
    }
}

void MakeAnswer()
{
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            DFS(i, j, to_string(board[i][j]));

    cout << check.size() << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}