#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

// Ǯ��.
// ��� ���� �����̷� ���� ������ �׷��� Ž�� ������. ��� ���Ӹ��� �÷��̾ �����ϹǷ�
// �� ���� ��忡�� ��Ʈ �������� �̵��Ÿ��� Ȧ����� �̱�� ¦����� ���� �ȴ�.
// ���� �� ��Ʈ ��忡�� ���� �������� �� �̵��Ÿ��� ���ϸ� �ȴ�.
// �׷��� ���⼭ �⺻���� �׷��� Ž�� �����ʹ� �ٸ� �κ��� �����Ѵ�.
// ���� 2���� ���� 1���� ��Ʈ ����̸� �� �ڽ��� 2�� ����̰� �� �ڽĵ��� �� 3���� 4���̴�.
// ���� �� �̵��Ÿ��� 4���� �⺻���� DFS, BFS�� �̿��ϸ� �̵��Ÿ��� 3�� ���´�.
// 1������ 2������ �̵��ϴ� ������ 2�� �������� �ϱ� �����̴�. �� �κп��� ���� �򰥷ȴ�.
// ������ ���� �̵��Ÿ��� �� ��͸��� ������ �ִ� ���̾���. �� ���� ���� ��尡 ���� �����
// �̵��Ÿ��� �� �̵��Ÿ� answer�� �����ְ� Ż���ϸ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

vector<vector<int>> board;
bool visit[500001];
int N, answer = 0;

void DFS(int here, int dist)
{
    // ���� �湮�� ����� �湮 ���θ� �����ϰ� �̵� ���ɿ��θ� false�� �ʱ�ȭ�Ѵ�.
    visit[here] = true;
    bool isMove = false;

    for (int i = 0; i < board[here].size(); ++i)
    {
        int there = board[here][i];
        if (!visit[there])
        {
            // �̵��� �������� �����ϰ�, ���ȣ���� �Ѵ�.
            isMove = true;
            DFS(there, dist + 1);
        }
    }
    // ���� �̵��� �Ұ����ߴٸ� ���� ����̹Ƿ� �̵��Ÿ��� �� �̵��Ÿ� answer�� ���Ѵ�.
    if (!isMove)
        answer += dist;
}

void MakeAnswer()
{
    memset(visit, false, sizeof(visit));
    DFS(1, 0);
    // �� �̵��Ÿ��� Ȧ����� �¸��ϰ� ¦����� �й��Ѵ�.
    if (answer % 2 == 1)
        cout << "Yes" << '\n';
    else
        cout << "No" << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    board.resize(N + 1, vector<int>());
    int a, b;
    for (int i = 0; i < N - 1; ++i)
    {
        cin >> a >> b;
        board[a].push_back(b);
        board[b].push_back(a);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}