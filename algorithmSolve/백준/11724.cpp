#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board; // ������ ��ȣ�� 1������ n������. �� ������ ������ �ʿ�� ����.
vector<bool> Check;
int n, m;

void DFS(int here)
{
    Check[here] = true;
    for (int i = 0; i < board[here].size(); ++i)
    {
        int there = board[here][i];
        if (!Check[there])
            DFS(there);
    }
}

void ShowAnswer()
{
    Check.assign(n, false);
    int answer = 0;
    for (int i = 0; i < n; ++i)
        if (!Check[i])
        {
            ++answer;
            DFS(i);
        }
    cout << answer << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    board.assign(n, vector<int>());
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        board[a - 1].push_back(b - 1);
        board[b - 1].push_back(a - 1);
    }
    ShowAnswer();
    return 0;
}