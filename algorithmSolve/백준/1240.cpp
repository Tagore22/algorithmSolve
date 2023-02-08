#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

// Ǯ��
// Ʈ���̱⿡ A���� B�� �����ϴ� ���� 2���� �̻��ϸ��� ������. �켱 �� ��忡�� ���� �̾����������� �˼� ���⿡ 2���� �迭�� ���۰���
// -1�� �ΰ�(�����Ҽ� ����) �Է¿��� �־����� ���̸� ���� ��ο� �����Ѵ�. (A, B, 2�Ͻ� board[A][B] = 2�� board[B][A] = 2)
// �� �� �־����� �� ��带 �� �������� �������� �ξ� ���������� BFS()�� ��ȸ�Ѵ�. ���� ��带 here�� �ξ� ���� �������� �ʾҰ�, ����
// �����Ҽ� �ִ� ��� ��忡 �����Ͽ� ������ ���ö����� ���̸� �÷�����.

int board[1001][1001];
bool check[1001];
int N, M, from, to;

void BFS()
{
    queue<pair<int, int>> que;
    que.push(make_pair(from, 0));
    check[from] = true;
    while (!que.empty())
    {
        int here = que.front().first;
        int len = que.front().second;
        que.pop();

        if (here == to)
        {
            cout << len << '\n';
            return;
        }

        for (int there = 1; there <= N; ++there)
            if (board[here][there] != -1 && !check[there])
            {
                que.push(make_pair(there, len + board[here][there]));
                check[there] = true;
            }
    }
}

void MakeAnswer()
{
    for (int i = 0; i < M; ++i)
    {
        cin >> from >> to;
        memset(check, false, sizeof(check));
        BFS();
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(board, -1, sizeof(board));

    cin >> N >> M;
    for (int i = 0; i < N - 1; ++i)
    {
        int from, to, len;
        cin >> from >> to >> len;
        board[from][to] = len;
        board[to][from] = len;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}