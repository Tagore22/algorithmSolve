#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Ǯ��.
// ������ Ǯ���� BFS ����� ������ DFS �����̴�.
// ū ������ �����ϴ�. �־��� ������� �� ������ �������� �������� ������ DFS��ȸ�� �ϸ�
// ������ ���غ���.

// �ڼ��� ������ �ּ����� �����.

vector<vector<int>> board;
vector<bool> visit;
int compare[100001];
int N, idx = 1;
bool isEnd = false;

// �� ������ �켱������ ���ϴ� �Լ�.
bool CompareFunc(int lhs, int rhs)
{
    return compare[lhs] < compare[rhs];
}

// DFS ��ȸ �Լ�.
void DFS(int here)
{
    if (isEnd)
        return;
    if (visit[here])
        return;
    visit[here] = true;

    for (auto there : board[here])
    {
        if (!visit[there])
        {
            // ���� �湮�Ϸ��� ������ ���� �־��� ������ ���غ���.
            // ���� �ٸ��ٸ� isEnd�� true�� �Ǿ� ��� DFS�� Ż���Ѵ�. 
            if (compare[there] != idx)
            {
                isEnd = true;
                return;
            }
            ++idx;
            DFS(there);
        }
    }
}

void MakeAnswer()
{
    if (compare[1] != 0)
    {
        cout << 0 << '\n';
        return;
    }
    // ��� �������� �־��� ������ ���� �����Ѵ�.
    for (int i = 1; i <= N; ++i)
        sort(board[i].begin(), board[i].end(), CompareFunc);
    DFS(1);
    // isEnd�� ���� ������ ���а� ������.
    cout << (!isEnd ? 1 : 0) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    board.resize(N + 1, vector<int>());
    visit.resize(N + 1, false);
    int from, to;
    for (int i = 0; i < N - 1; ++i)
    {
        cin >> from >> to;
        board[from].push_back(to);
        board[to].push_back(from);
    }
    int num;
    for (int i = 0; i < N; ++i)
    {
        cin >> num;
        compare[num] = i;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}