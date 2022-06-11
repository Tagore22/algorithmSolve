#include <iostream>
#include <vector>

using namespace std; // ���� �׷���, � �� ���� ���̿� ���� �ϳ��� �ƴҼ��� �ִ�. ������ ��ȣ�� 1������ n����

vector<vector<int>> board;// � �������� �����ϴ� ���� ���� ��� 0�� ����Ѵ�. ����, ���� ����ġ�� �־����� �ʴ´�.
int n, m;
const int MAXNUM = 987654321;

void Floyd()
{
    for (int i = 0; i < n; ++i)
        board[i][i] = 0;

    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                board[i][j] = min(board[i][j], board[i][k] + board[k][j]);
}

void ShowAnswer()
{
    Floyd();
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            cout << (board[i][j] != MAXNUM ? board[i][j] : 0) << ' ';
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    board.assign(n, vector<int>(n, MAXNUM));
    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        board[a - 1][b - 1] = min(board[a - 1][b - 1], c);
    }
    ShowAnswer();
    return 0;
}