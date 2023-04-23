#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

// Ǯ��.
// 1926���� DFS Ǯ�̴�.
// �ܼ��� DFS�� ȣ�� Ƚ���� �ѹ� ȣ�������� ������� ��͵Ǿ� �ٽ� ȣ���ϴ����� ����ϸ� �ȴ�.
// �������� DFS�� ���� ������ BFS���� ��ƸԴ� �޸𸮰� ������ �˾Ҵµ�
// �̹����� DFS�� �ξ��� �޸𸮸� ���� �����ߴ�. �Ƹ� ������ Ŀ���鼭
// ��� ȣ���� �������� �ݽ����� ��� �׿��� �׷�������.
// �������ڸ� BFS�� DFS�� ȣ��Ƚ���� ���������� DFS�� �ξ� �� �����쳪
// ȣ��Ƚ���� �����ϸ� �����Ҽ��� BFS�� �� ����������.

bool board[500][500];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // �� �� �� ��.
bool visit[500][500];
int N, M;

int DFS(int y, int x)
{
    visit[y][x] = true;

    int ans = 1;

    for (int i = 0; i < 4; ++i)
    {
        int dy = y + rot[i][0];
        int dx = x + rot[i][1];

        if (dy < 0 || dy >= N || dx < 0 || dx >= M || !board[dy][dx] || visit[dy][dx])
            continue;

        ans += DFS(dy, dx);
    }
    return ans;
}

void MakeAnswer()
{
    memset(visit, false, sizeof(visit));
    int num = 0, answer = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (board[i][j] == 1 && !visit[i][j])
            {
                ++num;
                answer = max(answer, DFS(i, j));
            }
    cout << num << '\n';
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    int cur;
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