#include <iostream>
#include <cstring>

using namespace std;

//Ǯ��
//�������� DFS�����̴�. 2���� �迭�� ��ȸ�ϸ鼭 ������ �ִ� ��ǥ�� ������ ��� DFS�Լ��� ��ȸ�ϸ� ������ ũ�⸦ 1�� �����س�����.
//�ٸ� �¿���Ϸ� �̵��Ҷ� �Դ����� �ٽ� �ͼ��� �ȵǹǷ�, DFS ���ۺκп� �� ��ǥ�� false�� �����ϴ� ���� ������ �ȵȴ�.
//����, ���� ������ ũ��� 0�� �ƴ� 1�ӿ� �����Ұ�.

bool board[100][100];
int tran[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };
int N, M, K;

int DFS(int y, int x)
{
    int check = 1;
    board[y][x] = false;

    for (int i = 0; i < 4; ++i)
    {
        int dy = y + tran[i][0];
        int dx = x + tran[i][1];

        if (dy < 0 || dy >= N || dx < 0 || dx >= M || !board[dy][dx])
            continue;

        check += DFS(dy, dx);
    }

    return check;
}

void MakeAnswer()
{
    int answer = 0;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (board[i][j])
                answer = max(answer, DFS(i, j));

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(board, false, sizeof(board));

    cin >> N >> M >> K;
    int y, x;
    for (int i = 0; i < K; ++i)
    {
        cin >> y >> x;
        board[y - 1][x - 1] = true;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}