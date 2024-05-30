#include <iostream>

using namespace std;

// Ǯ��.
// DFS �����̴�. �迭�� ��� ����ĭ���� �����ؼ� ��� �Ѱ��̵� �� �Ʒ��� �̵��Ҽ� �ִٸ� YES��, �׷��� �ʴٸ�
// NO�� ����ϸ� �ȴ�. 

// �ڼ��� ������ �ּ����� �����.

bool check[1000][1000] = { false, }, board[1000][1000];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // ����, ����, ������, �Ʒ���
int M, N;

// DFS ��ȸ�Լ�.
void DFS(int y, int x)
{
    // ���� �� �Ʒ��ʿ� �����Ͽ��ٸ� YES�� ����ϰ� ���α׷��� �����Ѵ�.
    if (y == M - 1)
    {
        cout << "YES" << '\n';
        exit(0);
    }

    // 4�������� �̵��غ���.
    for (int i = 0; i < 4; ++i)
    {
        int ny = y + rot[i][0];
        int nx = x + rot[i][1];

        // �迭�� ����ų�, �̹� �湮�� ���̰ų�, ������ ������ �ʴ� ���̶�� �����Ѵ�.
        if (ny < 0 || ny >= M || nx < 0 || nx >= N || check[ny][nx] || board[ny][nx])
            continue;
        // �湮 ���θ� �����ϰ� ���ȣ���Ѵ�.
        check[ny][nx] = true;
        DFS(ny, nx);
    }
}

void MakeAnswer()
{
    // ��� �� ��ĭ�� ��ȸ�Ѵ�.
    for (int i = 0; i < N; ++i)
    {
        // ���� �湮���� �ʾ�����, ������ �帣�� ���̶�� DFS��ȸ�� �غ���.
        if (!check[0][i] && !board[0][i])
        {
            check[0][i] = true;
            DFS(0, i);
        }
    }
    // ��� ��ȸ���� �� �Ʒ����� ���޸��ߴٸ� NO�� ����Ѵ�.
    cout << "NO" << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> M >> N;
    string str;
    for (int i = 0; i < M; ++i)
    {
        cin >> str;
        for (int j = 0; j < N; ++j)
            board[i][j] = str[j] == '0' ? false : true;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}