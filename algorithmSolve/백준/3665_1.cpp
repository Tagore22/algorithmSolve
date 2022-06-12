#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<bool>> board;
vector<bool> check;
vector<int> team, answer;
int n, m;

void MakeGraph()
{
    board.assign(n, vector<bool>(n, false));
    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
            board[team[i] - 1][team[j] - 1] = true;
}

void DFS(int here)
{
    check[here] = true;
    for (int there = 0; there < n; ++there)
        if (!check[there] && board[here][there])
            DFS(there);

    answer.push_back(here + 1);
}

void MakeAnswer()
{
    check.assign(n, false);
    answer.clear();
    for (int i = 0; i < n; ++i)
        if (!check[i])
            DFS(i);
    reverse(answer.begin(), answer.end());
    for (int i = answer.size() - 1; i > 0; --i)
        for (int j = i - 1; j >= 0; --j)
            if (board[answer[i] - 1][answer[j] - 1])
            {
                answer.clear();
                return;
            }
}

void ShowAnswer()
{
    MakeAnswer();
    if (answer.empty() || answer.size() != n)
        cout << "IMPOSSIBLE";
    else
        for (int i = 0; i < n; ++i)
            cout << answer[i] << ' ';
    cout << '\n';
}

int main() //���� �׷���, ������ ��ȣ�� 1������ n-1, ���������� ����� ���� ���� ��쵵 ����
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int c;
    cin >> c;
    for (int i = 0; i < c; ++i)
    {
        cin >> n;
        team.assign(n, 0);
        for (int j = 0; j < n; ++j) // ���⼭ �̸� �׷����� ����� ���´�.
            cin >> team[j];
        MakeGraph();
        cin >> m;
        for (int j = 0; j < m; ++j) // ���⼭ �׷����� �����Ѵ�.
        {
            int a, b;
            cin >> a >> b;
            if (board[a - 1][b - 1]) // a�� �����϶�
            {
                board[a - 1][b - 1] = false;
                board[b - 1][a - 1] = true;
            }
            else
            {
                board[b - 1][a - 1] = false;
                board[a - 1][b - 1] = true;
            }
        }
        ShowAnswer();
    }
    return 0;
}