#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

// Ǯ��.
// 12849���� ù��° Ǯ���̴�. ����ϰ� DFSǮ�̷� Ǯ����.
// �׷��� �ٸ� Ǯ�̵麸�� �ӵ��� ���Ȱ� �̰����� ã�ƺ��Ҵ�.

// �ڼ��� ������ �ּ����� �����.

vector<vector<int>> board;
int dp[8][100000];
const int DIV_NUM = 1000000007;

int D;

void MakeBoard()
{
    // �������� �־����� �׸��� ���ܺ��� 0������. ������ �Ʒ���, �����ʺ��� ��������.
    board.resize(8, vector<int>());
    board[0].push_back(1);
    board[0].push_back(2);
    board[1].push_back(0);
    board[1].push_back(2);
    board[1].push_back(3);
    board[2].push_back(0);
    board[2].push_back(1);
    board[2].push_back(3);
    board[2].push_back(4);
    board[3].push_back(1);
    board[3].push_back(2);
    board[3].push_back(4);
    board[3].push_back(5);
    board[4].push_back(2);
    board[4].push_back(3);
    board[4].push_back(5);
    board[4].push_back(6);
    board[5].push_back(3);
    board[5].push_back(4);
    board[5].push_back(7);
    board[6].push_back(4);
    board[6].push_back(7);
    board[7].push_back(5);
    board[7].push_back(6);
}

int DFS(int here, int time)
{
    if (time == D)
        return here == 0 ? 1 : 0;

    int& ans = dp[here][time];
    if (ans != -1)
        return ans;

    ans = 0;
    for (int i = 0; i < board[here].size(); ++i)
    {
        int there = board[here][i];
        ans += DFS(there, time + 1);
        ans %= DIV_NUM;
    }
    return ans;
}

void MakeAnswer()
{
    MakeBoard();
    memset(dp, -1, sizeof(dp));
    // ���⼭ DFS
    int answer = DFS(0, 0);
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> D;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}