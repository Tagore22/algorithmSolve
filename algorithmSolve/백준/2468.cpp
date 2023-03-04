#include <iostream>
#include <cstring>

using namespace std;

// Ǯ��
// �������� DFS�����̴�. �ٸ� DFS��ȸ�� ������ �ϳ��� �迭������ ��ȸ�ϸ� DFS�� ��ȸ�ؾ��Ѵ�.
// 100 * 100������ �ִ� 10000���� ��ȸ�ϴ� ���� ũ���� ������, ��������� ����ȭ�� ����
// �ִ� ���̰��� ���Ͽ� �� ���������� ��ȸ�� �����Ͽ���.

int board[100][100];
bool check[100][100];
int rot[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
int N, H, max_H = 0;

// �������� DFS �����Լ�.
void DFS(int y, int x)
{
    check[y][x] = true;

    for (int i = 0; i < 4; ++i)
    {
        int dy = y + rot[i][0];
        int dx = x + rot[i][1];

        if (dy < 0 || dy >= N || dx < 0 || dx >= N || check[dy][dx] || board[dy][dx] <= H)
            continue;

        DFS(dy, dx);
    }
}

void MakeAnswer()
{
    int answer = 0, cur;
    
    // �ϼ��Ͽ��� ������ �ִ� ���̺����� ��ȸ�� �ǹ̰� ����. �ִ� ���̺��ʹ� ������ ��� ���ð� ���� ��� �������밡 ���� ����.
    for (int i = 0; i < max_H; ++i)
    {
        // �̹� ��ȸ�� ���������� ���� ���̰�, �湮 ���θ� ����ϴ� �迭�� �ʱ�ȭ.
        cur = 0;
        H = i;
        memset(check, false, sizeof(check));

        for (int j = 0; j < N; ++j)
            for (int k = 0; k < N; ++k)
                if (board[j][k] > H && !check[j][k])
                {
                    ++cur;
                    DFS(j, k);
                }

        answer = max(answer, cur);
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
        for (int j = 0; j < N; ++j)
        {
            cin >> board[i][j];
            // ���� DFS ��ȸ�� �־����� ���̰��� �ּ�ȭ�ϱ� ���� �迭�� �ִ밪�� ���Ѵ�. ���ð� ��� ���� ���ٸ� ���������
            // ������ 0�̱� ������ �ִ밪������ ��ȸ�� �ǹ̰� ����.
            max_H = max(max_H, board[i][j]);
        }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}