#include <iostream>
#include <vector>

using namespace std;//������ ��ȣ�� 1������ n����, ����� �׷���, ��� ������ ����Ǿ�����

vector<vector<int>> board;
int n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cin >> n >> m;
        board.assign(n + 1, vector<int>());
        for (int j = 0; j < m; ++j)
        {
            int a, b;
            cin >> a >> b;
            board[a].push_back(b);
            board[b].push_back(a);
        }
        cout << n - 1 << '\n';
    }
    return 0;
}